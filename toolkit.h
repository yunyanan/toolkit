#ifndef __TOOLKIT_H__
#define __TOOLKIT_H__

/*
 * section define for function. With these macros, the functions will be put together.
 */
#define TOOLKIT_INIT					__attribute__((used, section("toolkit_init")))
#define TOOLKIT_EXIT					__attribute__((used, section("toolkit_exit")))
#define TOOLKIT_COMMON					__attribute__((used, section("toolkit_common")))

/*
 * Collecting section information.
 *
 */
#define TOOLKIT_SECTION_LAYOUT(_name, _body, _table, _count)	\
	do {														\
		extern _body __start_##_name __attribute__ ((weak));	\
		extern _body __stop_##_name __attribute__ ((weak));		\
		unsigned long base, limit;								\
		base = (unsigned long)&__start_##_name;					\
		limit = (unsigned long)&__stop_##_name;					\
		_table = (const _body *)base;							\
		_count = ((limit-base)/sizeof(_body));					\
	} while (0)


/**
 * This macro allows gcc to check whether the function return value is used.
 *
 */
#define TOOLKIT_RESULT_USED				__attribute__((warn_unused_result))

#endif	/* #ifndef __TOOLKIT_H__ */
