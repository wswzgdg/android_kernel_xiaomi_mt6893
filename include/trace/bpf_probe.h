/* SPDX-License-Identifier: GPL-2.0 */

#undef TRACE_SYSTEM_VAR

#ifdef CONFIG_BPF_EVENTS

#define ___bpf_concat(a, b) a##b
#define __bpf_concat(a, b) ___bpf_concat(a, b)
#define CONCATENATE(a, b) __bpf_concat(a, b)
#define __bpf_narg(...) __bpf_narg_(__VA_ARGS__,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)
#define __bpf_narg_(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,N,...) N
#define COUNT_ARGS(...) __bpf_narg(__VA_ARGS__)

#undef __entry
#define __entry entry

#undef __get_dynamic_array
#define __get_dynamic_array(field)	\
		((void *)__entry + (__entry->__data_loc_##field & 0xffff))

#undef __get_dynamic_array_len
#define __get_dynamic_array_len(field)	\
		((__entry->__data_loc_##field >> 16) & 0xffff)

#undef __get_str
#define __get_str(field) ((char *)__get_dynamic_array(field))

#undef __get_bitmask
#define __get_bitmask(field) (char *)__get_dynamic_array(field)

#undef __perf_count
#define __perf_count(c)	(c)

#undef __perf_task
#define __perf_task(t)	(t)

/* cast any integer, pointer, or small struct to u64 */
#define UINTTYPE(size) \
	__typeof__(__builtin_choose_expr(size == 1,  (u8)1, \
		   __builtin_choose_expr(size == 2, (u16)2, \
		   __builtin_choose_expr(size == 4, (u32)3, \
		   __builtin_choose_expr(size == 8, (u64)4, \
					 (void)5)))))
#define __CAST_TO_U64(x) ({ \
	__typeof__(x) __src = (x); \
	u64 __dst = 0; \
	memcpy(&__dst, &__src, sizeof(__src)); \
	__dst; })

#define __CAST1(a,...) __CAST_TO_U64(a)
#define __CAST2(a,...) __CAST_TO_U64(a), __CAST1(__VA_ARGS__)
#define __CAST3(a,...) __CAST_TO_U64(a), __CAST2(__VA_ARGS__)
#define __CAST4(a,...) __CAST_TO_U64(a), __CAST3(__VA_ARGS__)
#define __CAST5(a,...) __CAST_TO_U64(a), __CAST4(__VA_ARGS__)
#define __CAST6(a,...) __CAST_TO_U64(a), __CAST5(__VA_ARGS__)
#define __CAST7(a,...) __CAST_TO_U64(a), __CAST6(__VA_ARGS__)
#define __CAST8(a,...) __CAST_TO_U64(a), __CAST7(__VA_ARGS__)
#define __CAST9(a,...) __CAST_TO_U64(a), __CAST8(__VA_ARGS__)
#define __CAST10(a,...) __CAST_TO_U64(a), __CAST9(__VA_ARGS__)
#define __CAST11(a,...) __CAST_TO_U64(a), __CAST10(__VA_ARGS__)
#define __CAST12(a,...) __CAST_TO_U64(a), __CAST11(__VA_ARGS__)
#define __CAST13(a,...) __CAST_TO_U64(a), __CAST12(__VA_ARGS__)
#define __CAST14(a,...) __CAST_TO_U64(a), __CAST13(__VA_ARGS__)
#define __CAST15(a,...) __CAST_TO_U64(a), __CAST14(__VA_ARGS__)
#define __CAST16(a,...) __CAST_TO_U64(a), __CAST15(__VA_ARGS__)
/* tracepoints with more than 16 arguments will hit build error */
#define CAST_TO_U64(...) CONCATENATE(__CAST, COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__)

void bpf_trace_run1(struct bpf_prog *prog, u64 arg0);
void bpf_trace_run2(struct bpf_prog *prog, u64 arg0, u64 arg1);
void bpf_trace_run3(struct bpf_prog *prog, u64 arg0, u64 arg1, u64 arg2);
void bpf_trace_run4(struct bpf_prog *prog, u64 arg0, u64 arg1, u64 arg2, u64 arg3);
void bpf_trace_run5(struct bpf_prog *prog, u64 arg0, u64 arg1, u64 arg2, u64 arg3, u64 arg4);
void bpf_trace_run6(struct bpf_prog *prog, u64 arg0, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5);
void bpf_trace_run7(struct bpf_prog *prog, u64 arg0, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6);
void bpf_trace_run8(struct bpf_prog *prog, u64 arg0, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7);
void bpf_trace_run9(struct bpf_prog *prog, u64 arg0, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8);
void bpf_trace_run10(struct bpf_prog *prog, u64 arg0, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8, u64 arg9);
void bpf_trace_run11(struct bpf_prog *prog, u64 arg0, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8, u64 arg9, u64 arg10);
void bpf_trace_run12(struct bpf_prog *prog, u64 arg0, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8, u64 arg9, u64 arg10, u64 arg11);
void bpf_trace_run13(struct bpf_prog *prog, u64 arg0, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8, u64 arg9, u64 arg10, u64 arg11, u64 arg12);
void bpf_trace_run14(struct bpf_prog *prog, u64 arg0, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8, u64 arg9, u64 arg10, u64 arg11, u64 arg12, u64 arg13);
void bpf_trace_run15(struct bpf_prog *prog, u64 arg0, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8, u64 arg9, u64 arg10, u64 arg11, u64 arg12, u64 arg13, u64 arg14);
void bpf_trace_run16(struct bpf_prog *prog, u64 arg0, u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5, u64 arg6, u64 arg7, u64 arg8, u64 arg9, u64 arg10, u64 arg11, u64 arg12, u64 arg13, u64 arg14, u64 arg15);

#undef DECLARE_EVENT_CLASS
#define DECLARE_EVENT_CLASS(call, proto, args, tstruct, assign, print)	\
static notrace void							\
__bpf_trace_##call(void *__data, proto)					\
{									\
	struct bpf_prog *prog = __data;					\
	CONCATENATE(bpf_trace_run, COUNT_ARGS(args))(prog, CAST_TO_U64(args));	\
}

/*
 * This part is compiled out, it is only here as a build time check
 * to make sure that if the tracepoint handling changes, the
 * bpf probe will fail to compile unless it too is updated.
 */
#undef DEFINE_EVENT
#define DEFINE_EVENT(template, call, proto, args)			\
static inline void bpf_test_probe_##call(void)				\
{									\
	check_trace_callback_type_##call(__bpf_trace_##template);	\
}									\
static struct bpf_raw_event_map	__used					\
	__attribute__((section("__bpf_raw_tp_map")))			\
__bpf_trace_tp_map_##call = {						\
	.tp		= &__tracepoint_##call,				\
	.bpf_func	= (void *)__bpf_trace_##template,		\
	.num_args	= COUNT_ARGS(args),				\
};


#undef DEFINE_EVENT_PRINT
#define DEFINE_EVENT_PRINT(template, name, proto, args, print)	\
	DEFINE_EVENT(template, name, PARAMS(proto), PARAMS(args))

#include TRACE_INCLUDE(TRACE_INCLUDE_FILE)
#endif /* CONFIG_BPF_EVENTS */
