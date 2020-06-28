include $(call select_from_repositories,lib/import/import-qt5_qmake.mk)

QT5_PORT_LIBS += libQt5Core libQt5Gui libQt5Network libQt5Widgets
QT5_PORT_LIBS += libQt5Qml libQt5Quick

LIBS = libc libm mesa stdcxx $(QT5_PORT_LIBS)

built.tag: qmake_prepared.tag

	@#
	@# run qmake
	@#

	$(VERBOSE)source env.sh && $(QMAKE) \
		-qtconf qmake_root/mkspecs/$(QMAKE_PLATFORM)/qt.conf \
		$(QT_DIR)/qtquickcontrols2/qtquickcontrols2.pro \
		$(QT5_OUTPUT_FILTER)

	@#
	@# build
	@#

	$(VERBOSE)source env.sh && $(MAKE) sub-src $(QT5_OUTPUT_FILTER)

	@#
	@# install into local 'install' directory
	@#

	$(VERBOSE)$(MAKE) INSTALL_ROOT=$(CURDIR)/install sub-src-install_subtargets $(QT5_OUTPUT_FILTER)

	$(VERBOSE)ln -sf .$(CURDIR)/qmake_root install/qt

	@#
	@# create stripped versions
	@#

	$(VERBOSE)cd $(CURDIR)/install/qt/lib && \
		$(STRIP) libQt5QuickControls2.lib.so -o libQt5QuickControls2.lib.so.stripped && \
		$(STRIP) libQt5QuickTemplates2.lib.so -o libQt5QuickTemplates2.lib.so.stripped

	$(VERBOSE)cd $(CURDIR)/install/qt/qml/QtQuick/Controls.2 && \
		$(STRIP) libqtquickcontrols2plugin.lib.so -o libqtquickcontrols2plugin.lib.so.stripped

	$(VERBOSE)cd $(CURDIR)/install/qt/qml/QtQuick/Templates.2 && \
		$(STRIP) libqtquicktemplates2plugin.lib.so -o libqtquicktemplates2plugin.lib.so.stripped

	@#
	@# create symlinks in 'bin' directory
	@#

	$(VERBOSE)ln -sf $(CURDIR)/install/qt/lib/libQt5QuickControls2.lib.so.stripped $(PWD)/bin/libQt5QuickControls2.lib.so
	$(VERBOSE)ln -sf $(CURDIR)/install/qt/lib/libQt5QuickTemplates2.lib.so.stripped $(PWD)/bin/libQt5QuickTemplates2.lib.so

	$(VERBOSE)ln -sf $(CURDIR)/install/qt/qml/QtQuick/Controls.2/libqtquickcontrols2plugin.lib.so.stripped $(PWD)/bin/libqtquickcontrols2plugin.lib.so
	$(VERBOSE)ln -sf $(CURDIR)/install/qt/qml/QtQuick/Templates.2/libqtquicktemplates2plugin.lib.so.stripped $(PWD)/bin/libqtquicktemplates2plugin.lib.so

	@#
	@# create symlinks in 'debug' directory
	@#

	$(VERBOSE)ln -sf $(CURDIR)/install/qt/lib/libQt5QuickControls2.lib.so $(PWD)/debug/
	$(VERBOSE)ln -sf $(CURDIR)/install/qt/lib/libQt5QuickTemplates2.lib.so $(PWD)/debug/

	$(VERBOSE)ln -sf $(CURDIR)/install/qt/qml/QtQuick/Controls.2/libqtquickcontrols2plugin.lib.so $(PWD)/debug/
	$(VERBOSE)ln -sf $(CURDIR)/install/qt/qml/QtQuick/Templates.2/libqtquicktemplates2plugin.lib.so $(PWD)/debug/

	@#
	@# create tar archives
	@#

	$(VERBOSE)tar chf $(PWD)/bin/qt5_quickcontrols2_qml.tar --exclude='*.lib.so' --transform='s/\.stripped//' -C install qt/qml

	@#
	@# mark as done
	@#

	$(VERBOSE)touch $@


ifeq ($(called_from_lib_mk),yes)
all: built.tag
endif
