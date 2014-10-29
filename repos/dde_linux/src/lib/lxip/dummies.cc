/**
 * \brief  Dummy functions
 * \author Sebastian Sumpf
 * \date   2013-08-26
 */

/*
 * Copyright (C) 2013 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

#include <base/printf.h>

extern "C" {
	typedef long DUMMY;

enum {
	SHOW_DUMMY = 0,
	SHOW_SKIP  = 0,
	SHOW_RET   = 0,
};

#define DUMMY(retval, name) \
	DUMMY name(void) { \
	if (SHOW_DUMMY) \
		PDBG( #name " called (from %p) not implemented", __builtin_return_address(0)); \
	return retval; \
}

#define DUMMY_SKIP(retval, name) \
	DUMMY name(void) { \
		if (SHOW_SKIP) \
			PLOG( #name " called (from %p) skipped", __builtin_return_address(0)); \
	return retval; \
}

#define DUMMY_RET(retval, name) \
	DUMMY name(void) { \
		if (SHOW_RET) \
			PWRN( #name " called (from %p) return %d", __builtin_return_address(0), retval); \
	return retval; \
}


/*
 * Changed return values
 */
DUMMY_RET(0, in_irq)
DUMMY_RET(0, inet_twsk_alloc)
DUMMY_RET(0, ipv6_only_sock)
DUMMY_RET(0, netpoll_receive_skb)
DUMMY_RET(0, netpoll_rx_disable)
DUMMY_RET(1, nf_hook)
DUMMY_RET(0, notifier_to_errno)
DUMMY_RET(0, net_hash_mix)
DUMMY_RET(0, netdev_kobject_init)
DUMMY_RET(0, netdev_register_kobject)
DUMMY_RET(0, netpoll_rx)
DUMMY_RET(0, nla_put)
DUMMY_RET(1, num_possible_cpus)
DUMMY_RET(0, read_seqretry)
DUMMY_RET(0, poll_does_not_wait)
DUMMY_RET(0, secpath_exists)
DUMMY_RET(0, security_inet_conn_request)
DUMMY_RET(0, security_sk_alloc)
DUMMY_RET(0, signal_pending)
DUMMY_RET(0, sk_filter)
DUMMY_RET(0, sock_tx_timestamp)
DUMMY_RET(0, sscanf)
DUMMY_RET(0, static_key_false)
DUMMY_RET(0, vlan_tx_nonzero_tag_present)
DUMMY_RET(0, vlan_tx_tag_present)
DUMMY_RET(1, xfrm4_policy_check)
DUMMY_RET(0, xfrm_sk_clone_policy)
DUMMY_RET(0, xfrm_decode_session_reverse)


/*
 * Unnecessary to trace
 */
DUMMY_SKIP( 0, ASSERT_RTNL)
DUMMY_SKIP(-1, debug_check_no_locks_freed)
DUMMY_SKIP(-1, local_bh_disable)
DUMMY_SKIP(-1, local_bh_enable)
DUMMY_SKIP(-1, local_irq_disable)
DUMMY_SKIP(-1, local_irq_enable)
DUMMY_SKIP(-1, local_irq_restore)
DUMMY_SKIP(-1, local_irq_save)
DUMMY_SKIP(-1, lockdep_init_map)
DUMMY_SKIP(-1, lockdep_set_class_and_name)
DUMMY_SKIP(-1, kmemcheck_annotate_variable)
DUMMY_SKIP(-1, might_sleep)
DUMMY_SKIP(-1, mutex_acquire)
DUMMY_SKIP(-1, mutex_init)
DUMMY_SKIP(-1, mutex_release)
DUMMY_SKIP(-1, mutex_unlock)
DUMMY_SKIP(-1, prefetchw)
DUMMY_SKIP(-1, mutex_lock)
DUMMY_SKIP(-1, rcu_read_lock)
DUMMY_SKIP(-1, rcu_read_unlock)
DUMMY_SKIP(-1, rcu_read_lock_bh)
DUMMY_SKIP(-1, rcu_read_unlock_bh)
DUMMY_SKIP(-1, read_lock)
DUMMY_SKIP(-1, read_seqbegin)
DUMMY_SKIP(-1, read_unlock)
DUMMY_SKIP(-1, read_lock_bh)
DUMMY_SKIP(-1, read_unlock_bh)
DUMMY_SKIP(-1, rwlock_init)
DUMMY_SKIP(-1, seqlock_init)
DUMMY_SKIP(-1, smp_mb)
DUMMY_SKIP(-1, smp_rmb)
DUMMY_SKIP(-1, smp_wmb)
DUMMY_SKIP(-1, spin_lock_irqsave)
DUMMY_SKIP( 1, spin_trylock)
DUMMY_SKIP(-1, spin_unlock_irqrestore)
DUMMY_SKIP(-1, synchronize_rcu)
DUMMY_SKIP(-1, trace_kfree_skb)
DUMMY_SKIP(-1, trace_consume_skb)
DUMMY_SKIP(-1, trace_net_dev_xmit)
DUMMY_SKIP(-1, trace_netif_receive_skb)
DUMMY_SKIP(-1, write_lock)
DUMMY_SKIP(-1, write_lock_bh)
DUMMY_SKIP(-1, write_lock_irq)
DUMMY_SKIP(-1, write_seqlock)
DUMMY_SKIP(-1, write_seqlock_bh)
DUMMY_SKIP(-1, write_sequnlock)
DUMMY_SKIP(-1, write_sequnlock_bh)
DUMMY_SKIP(-1, write_unlock)
DUMMY_SKIP(-1, write_unlock_bh)
DUMMY_SKIP(-1, write_unlock_irq)

/* requires CONFIG_MEMCG_KMEM */
DUMMY_SKIP(-1, sock_release_memcg)

DUMMY_SKIP(-1, waitqueue_active)
DUMMY_SKIP(-1, wake_up)

/*
 * Test
 */
DUMMY_SKIP(-1, rtmsg_ifinfo)
DUMMY_RET(0, rtnl_is_locked)
DUMMY_SKIP(-1, rtnl_lock)
DUMMY(-1, rtnl_notify)
DUMMY(-1, rtnl_set_sk_err)
DUMMY_SKIP(-1, rtnl_unlock)
DUMMY_RET(0, rtnetlink_put_metrics)
DUMMY(-1, rtnl_af_register)
DUMMY(-1, rtnl_put_cacheinfo)
DUMMY_SKIP(-1, rtnl_register)
DUMMY(-1, rtnl_unicast)



/*
 * Dummies
 */
DUMMY(-1, access_ok)
DUMMY(-1, add_device_randomness)
DUMMY(-1, addrconf_finite_timeout)
DUMMY(-1, addrconf_timeout_fixup)
DUMMY(-1, add_wait_queue)
DUMMY(-1, add_wait_queue_exclusive)
DUMMY(-1, atomic_notifier_call_chain)
DUMMY(-1, atomic_notifier_chain_register)
DUMMY(-1, atomic_notifier_chain_unregister)
DUMMY(-1, audit_enabled)
DUMMY(-1, audit_get_loginuid)
DUMMY(-1, audit_get_sessionid)
DUMMY(-1, audit_log)
DUMMY(-1, autoremove_wake_function)
DUMMY(-1, blocking_notifier_chain_unregister)
DUMMY(-1, call_netevent_notifiers)
DUMMY(-1, cancel_delayed_work)
DUMMY(-1, cancel_delayed_work_sync)
DUMMY(-1, capable)
DUMMY(-1, cipso_v4_validate)
DUMMY(-1, __clear_bit)
DUMMY(-1, clamp)
DUMMY(-1, clear_bit)
DUMMY(-1, cond_resched)
DUMMY(-1, cond_resched_softirq)
DUMMY(-1, __copy_from_user_nocache)
DUMMY(-1, csum_block_sub)
DUMMY(-1, csum_replace2)
DUMMY(-1, csum_sub)
DUMMY(-1, csum_unfold)
DUMMY(-1, current)
DUMMY(-1, current_egid)
DUMMY(-1, current_text_addr)
DUMMY(-1, del_timer_sync)
DUMMY(-1, dev_driver_string)
DUMMY(-1, device_rename)
DUMMY(-1, dev_ioctl)
DUMMY(-1, dev_is_pci)
DUMMY(-1, dev_load)
DUMMY(-1, dev_name)
DUMMY(-1, dev_num_vf)
DUMMY(-1, dev_printk_emit)
DUMMY(-1, div64_u64)
DUMMY(-1, div_u64)
DUMMY(-1, do_softirq)
DUMMY(-1, dump_stack)
DUMMY(-1, ether_addr_equal_64bits)
DUMMY(-1, exit_fn)
DUMMY(-1, file_inode)
DUMMY(-1, finish_wait)
DUMMY(-1, __fls)
DUMMY(-1, fls64)
DUMMY(-1, free_pages)
DUMMY(-1, from_kgid)
DUMMY(-1, from_kgid_munged)
DUMMY(-1, from_kuid)
DUMMY(-1, from_kuid_munged)
DUMMY(-1, generic_pipe_buf_confirm)
DUMMY(-1, generic_pipe_buf_map)
DUMMY(-1, generic_pipe_buf_unmap)
DUMMY(-1, gen_kill_estimator)
DUMMY(-1, get_current_groups)
DUMMY(-1, get_ds)
DUMMY(-1, __get_free_pages)
DUMMY(-1, get_fs)
DUMMY(-1, get_net_ns_by_fd)
DUMMY(-1, get_net_ns_by_pid)
DUMMY(-1, getnstimeofday)
DUMMY(-1, get_nulls_value)
DUMMY(-1, get_options)
DUMMY(-1, get_page)
DUMMY(-1, gfp_pfmemalloc_allowed)
DUMMY(-1, gid_lte)
DUMMY(-1, hash32_ptr)
DUMMY(-1, hex_to_bin)
DUMMY(-1, hlist_add_after_rcu)
DUMMY(-1, hlist_add_before_rcu)
DUMMY(-1, hlist_nulls_del)
DUMMY(-1, hlist_nulls_empty)
DUMMY(-1, hotcpu_notifier)
DUMMY(-1, hweight32)
DUMMY(-1, hweight64)
DUMMY(-1, inet_ctl_sock_destroy)
DUMMY(-1, inet_diag_dump_icsk)
DUMMY(-1, inet_diag_dump_one_icsk)
DUMMY(-1, inet_diag_register)
DUMMY(-1, inet_diag_unregister)
DUMMY(-1, INET_ECN_dontxmit)
DUMMY(-1, INET_ECN_is_not_ect)
DUMMY(-1, INET_ECN_xmit)
DUMMY(-1, inet_twdr_hangman)
DUMMY(-1, inet_twdr_twcal_tick)
DUMMY(-1, inet_twdr_twkill_work)
DUMMY(-1, inet_twsk_bind_unhash)
DUMMY(-1, inet_twsk_deschedule)
DUMMY(-1, __inet_twsk_hashdance)
DUMMY(-1, inet_twsk_purge)
DUMMY(-1, inet_twsk_put)
DUMMY(-1, inet_twsk_schedule)
DUMMY(-1, inet_twsk_unhash)
DUMMY(-1, inet_v6_ipv6only)
DUMMY(-1, INIT_DEFERRABLE_WORK)
DUMMY(-1, INIT_HLIST_NULLS_HEAD)
DUMMY(-1, init_user_ns)
DUMMY(-1, init_waitqueue_head)
DUMMY(-1, INIT_WORK)
DUMMY(-1, in_softirq)
DUMMY(-1, ip4_datagram_connect)
DUMMY(-1, ip4_datagram_release_cb)
DUMMY(-1, ip_check_mc_rcu)
DUMMY(-1, ip_mc_destroy_dev)
DUMMY(-1, ip_mc_down)
DUMMY(-1, ip_mc_drop_socket)
DUMMY(-1, ip_mc_init_dev)
DUMMY(-1, ip_mc_join_group)
DUMMY(-1, ip_mc_leave_group)
DUMMY(-1, ip_mc_msfilter)
DUMMY(-1, ip_mc_remap)
DUMMY(-1, ip_mc_sf_allow)
DUMMY(-1, ip_mc_source)
DUMMY(-1, ip_mc_unmap)
DUMMY(-1, ip_mc_up)
DUMMY(-1, ip_mroute_getsockopt)
DUMMY(-1, ip_mroute_opt)
DUMMY(-1, ip_mroute_setsockopt)
DUMMY(-1, ipv4_is_lbcast)
DUMMY(-1, ipv4_is_local_multicast)
DUMMY(-1, ipv4_is_zeronet)
DUMMY(-1, irqs_disabled)
DUMMY(-1, is_a_nulls)
DUMMY(-1, is_multicast_ether_addr)
DUMMY(-1, is_valid_ether_addr)
DUMMY(-1, is_vlan_dev)
DUMMY(-1, jiffies_delta_to_clock_t)
DUMMY(-1, jiffies_to_clock_t)
DUMMY(-1, jiffies_to_msecs)
DUMMY(-1, jiffies_to_usecs)
DUMMY(-1, kernel_sendmsg)
DUMMY(-1, kmem_cache_destroy)
DUMMY(-1, kobject_put)
DUMMY(-1, kobject_uevent)
DUMMY(-1, krealloc)
DUMMY(-1, kref_init)
DUMMY(-1, kref_put)
DUMMY(-1, kstrdup)
DUMMY(-1, kstrtoul)
DUMMY(-1, ktime_equal)
DUMMY(-1, ktime_to_timespec)
DUMMY(-1, ktime_to_timeval)
DUMMY(-1, ktime_us_delta)
DUMMY(-1, kunmap)
DUMMY(-1, kunmap_atomic)
DUMMY(-1, linkwatch_fire_event)
DUMMY(-1, linkwatch_forget_dev)
DUMMY(-1, linkwatch_init_dev)
DUMMY(-1, linkwatch_run_queue)
DUMMY(-1, list_del_rcu)
DUMMY(-1, list_replace_rcu)
DUMMY(-1, local_softirq_pending)
DUMMY(-1, lockdep_rtnl_is_held)
DUMMY(-1, min)
DUMMY(-1, mod_delayed_work)
DUMMY(-1, module_put)
DUMMY(-1, move_addr_to_kernel)
DUMMY(-1, mq_qdisc_ops)
DUMMY(-1, msecs_to_jiffies)
DUMMY(-1, msleep)
DUMMY(-1, mutex_is_locked)
DUMMY(-1, need_resched)
DUMMY(-1, netdev_queue_update_kobjects)
DUMMY(-1, netdev_unregister_kobject)
DUMMY(-1, net_dmaengine_get)
DUMMY(-1, net_dmaengine_put)
DUMMY(-1, net_eq)
DUMMY(-1, net_namespace_list)
DUMMY(-1, netpoll_poll_lock)
DUMMY(-1, netpoll_poll_unlock)
DUMMY(-1, netpoll_rx_enable)
DUMMY(-1, netpoll_rx_on)
DUMMY(-1, next_pseudo_random32)
DUMMY(-1, nf_bridge_pad)
DUMMY(-1, nf_ct_attach)
DUMMY(-1, nla_find)
DUMMY(-1, nla_memcpy)
DUMMY(-1, nla_parse)
DUMMY(-1, nla_reserve)
DUMMY(-1, nla_strcmp)
DUMMY(-1, nla_strlcpy)
DUMMY(-1, nla_validate)
DUMMY(-1, notifier_from_errno)
DUMMY(-1, ns_capable)
DUMMY(-1, num_online_cpus)
DUMMY(-1, on_each_cpu)
DUMMY(-1, open_softirq)
DUMMY(-1, PageHighMem)
DUMMY(-1, percpu_counter_destroy)
DUMMY(-1, percpu_counter_sum_positive)
DUMMY(-1, pid_vnr)
DUMMY(-1, pr_crit)
DUMMY(-1, pr_err_once)
DUMMY(-1, preempt_disable)
DUMMY(-1, preempt_enable)
DUMMY(-1, prefetch)
DUMMY(-1, pr_emerg)
DUMMY(-1, prepare_to_wait)
DUMMY(-1, prepare_to_wait_exclusive)
DUMMY(-1, pr_err)
DUMMY(-1, pr_info)
DUMMY(-1, pr_info_once)
DUMMY(-1, pr_warn)
DUMMY(-1, put_cmsg)
DUMMY(-1, put_cpu)
DUMMY(-1, put_cpu_var)
DUMMY(-1, put_cred)
DUMMY(-1, put_device)
DUMMY(-1, put_pid)
DUMMY(-1, put_unaligned_be32)
DUMMY(-1, __raise_softirq_irqoff)
DUMMY(-1, raise_softirq_irqoff)
DUMMY(-1, random32)
DUMMY(-1, ___ratelimit)
DUMMY(-1, raw_notifier_chain_unregister)
DUMMY(-1, rcu_barrier)
DUMMY(-1, register_gifconf)
DUMMY(-1, release_net)
DUMMY(-1, remove_proc_entry)
DUMMY(-1, remove_wait_queue)
DUMMY(-1, request_module)
DUMMY(-1, round_jiffies)
DUMMY(-1, round_jiffies_relative)
DUMMY(-1, round_jiffies_up)
DUMMY(-1, roundup_pow_of_two)
DUMMY(-1, rt_genid_bump)
DUMMY(-1, rtnetlink_init)
DUMMY(-1, __rtnl_unlock)
DUMMY(-1, schedule)
DUMMY(-1, schedule_delayed_work)
DUMMY(-1, schedule_timeout_interruptible)
DUMMY(-1, schedule_work)
DUMMY(-1, scm_destroy)
DUMMY(-1, scm_recv)
DUMMY(-1, scm_send)
DUMMY(-1, scnprintf)
DUMMY(-1, secpath_reset)
DUMMY(-1, secure_ip_id)
DUMMY(-1, secure_ipv4_port_ephemeral)
DUMMY(-1, secure_ipv6_id)
DUMMY(-1, secure_tcp_sequence_number)
DUMMY(-1, security_inet_conn_established)
DUMMY(-1, security_inet_csk_clone)
DUMMY(-1, security_netlink_send)
DUMMY(-1, security_release_secctx)
DUMMY(-1, security_req_classify_flow)
DUMMY(-1, security_skb_classify_flow)
DUMMY(-1, security_skb_owned_by)
DUMMY(-1, security_sk_classify_flow)
DUMMY(-1, security_sk_free)
DUMMY(-1, security_socket_getpeersec_dgram)
DUMMY(-1, security_socket_getpeersec_stream)
DUMMY(-1, security_sock_graft)
DUMMY(-1, send_sigurg)
DUMMY(-1, send_sig)
DUMMY(-1, __set_bit)
DUMMY(-1, set_bit)
DUMMY(-1, __set_current_state)
DUMMY(-1, set_current_state)
DUMMY(-1, set_fs)
DUMMY(-1, sg_mark_end)
DUMMY(-1, sg_set_buf)
DUMMY(-1, sg_set_page)
DUMMY(-1, sha_transform)
DUMMY(-1, si_meminfo)
DUMMY(-1, S_ISSOCK)
DUMMY(-1, sk_attach_filter)
DUMMY(-1, sk_detach_filter)
DUMMY(-1, sk_filter_len)
DUMMY(-1, sk_filter_release_rcu)
DUMMY(-1, sk_get_filter)
DUMMY(-1, smp_mb__after_clear_bit)
DUMMY(-1, smp_mb__before_atomic_dec)
DUMMY(-1, __sock_recv_timestamp)
DUMMY(-1, __sock_recv_ts_and_drops)
DUMMY(-1, __sock_recv_wifi_status)
DUMMY(-1, sock_release)
DUMMY(-1, sock_update_classid)
DUMMY(-1, sock_update_memcg)
DUMMY(-1, sock_update_netprioidx)
DUMMY(-1, sock_wake_async)
DUMMY(-1, splice_to_pipe)
DUMMY(-1, srandom32)
DUMMY(-1, ssleep)
DUMMY(-1, static_key_enabled)
DUMMY(-1, static_key_slow_dec)
DUMMY(-1, static_key_slow_inc)
DUMMY(-1, strcat)
DUMMY(-1, strncpy_from_user)
DUMMY(-1, synchronize_rcu_expedited)
DUMMY(-1, sysctl_igmp_max_msf)
DUMMY(-1, sysctl_tcp_fastopen)
DUMMY(-1, system_wq)
DUMMY(-1, tasklet_init)
DUMMY(-1, tasklet_schedule)
DUMMY(-1, task_pid_nr)
DUMMY(-1, task_tgid_vnr)
DUMMY(-1, tcp_fastopen_cache_get)
DUMMY(-1, tcp_fastopen_cache_set)
DUMMY(-1, tcp_fastopen_cookie_gen)
DUMMY(-1, tcp_fetch_timewait_stamp)
DUMMY(-1, tcp_hdrlen)
DUMMY(-1, tcp_init_metrics)
DUMMY(-1, tcp_metrics_init)
DUMMY(-1, tcp_peer_is_proven)
DUMMY(-1, tcp_remember_stamp)
DUMMY(-1, tcp_tw_remember_stamp)
DUMMY(-1, tcp_update_metrics)
DUMMY(-1, test_and_clear_bit)
DUMMY(-1, test_and_set_bit)
DUMMY(-1, test_bit)
DUMMY(-1, textsearch_find)
DUMMY(-1, __this_cpu_read)
DUMMY(-1, trace_napi_poll)
DUMMY(-1, trace_net_dev_queue)
DUMMY(-1, trace_netif_rx)
DUMMY(-1, trace_skb_copy_datagram_iovec)
DUMMY(-1, trace_sock_exceed_buf_limit)
DUMMY(-1, trace_sock_rcvqueue_full)
DUMMY(-1, trace_udp_fail_queue_rcv_skb)
DUMMY(-1, try_module_get)
DUMMY(-1, tsk_restore_flags)
DUMMY(-1, u64_stats_fetch_begin_bh)
DUMMY(-1, u64_stats_fetch_retry_bh)
DUMMY(-1, u64_stats_update_begin)
DUMMY(-1, u64_stats_update_end)
DUMMY(-1, udplite4_register)
DUMMY(-1, uid_eq)
DUMMY(-1, vfree)
DUMMY(-1, virt_to_page)
DUMMY(-1, vlan_do_receive)
DUMMY(-1, __vlan_put_tag)
DUMMY(-1, vlan_untag)
DUMMY(-1, vzalloc)
DUMMY(-1, wake_up_interruptible)
DUMMY(-1, wake_up_interruptible_all)
DUMMY(-1, wake_up_interruptible_poll)
DUMMY(-1, wake_up_interruptible_sync_poll)
DUMMY(-1, WARN_ONCE)
DUMMY(-1, write_seqcount_begin)
DUMMY(-1, write_seqcount_end)
DUMMY(-1, xchg)
DUMMY(-1, xfrm4_policy_check_reverse)
DUMMY(-1, xfrm4_route_forward)
DUMMY(-1, xfrm4_udp_encap_rcv)
DUMMY(-1, xfrm_sk_free_policy)
DUMMY(-1, xfrm_user_policy)
DUMMY(-1, yield)
DUMMY(-1, __xchg)
} /* extern "C" */

