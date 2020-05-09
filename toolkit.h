/**
 * toolkit
 *
 * Author: YunYanan <yunyanan1@gmail.com>
 * License: unlicense
 */
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

/**
 * This macro allows a function to be called before the main function.
 */
#define TOOLKIT_PREPARE					__attribute__((constructor))

/**
 * This macro allows a function to be called after the main function exits
 */
#define TOOLKIT_WINDUP					__attribute__((destructor))

/**
 * Compare two numbers.
 */
#define TOOLKIT_MAX(_a, _b)						\
	((_a) > (_b) ? (_a) : (_b))
#define TOOLKIT_MIN(_a, _b)						\
	((_a) < (_b) ? (_a) : (_b))

/**
 * Swap the high and low 4 bits of a byte.
 */
#define TOOLKIT_SWAP4(__d)			((((__d)>>4)&0x0f) | (((__d)<<4)&0xf0))

/**
 * Take the high/low 4/8 bits of a number.
 */
#define TOOLKIT_H4(__d)				(((__d)>>4) & 0x0f)
#define TOOLKIT_L4(__d)				(((__d)>>0) & 0x0f)
#define TOOLKIT_H8(__d)				(((__d)>>8) & 0xff)
#define TOOLKIT_L8(__d)				(((__d)>>0) & 0xff)
#define TOOLKIT_HH8(__d)			(((__d)>>24) & 0xff)
#define TOOLKIT_HL8(__d)			(((__d)>>16) & 0xff)
#define TOOLKIT_LH8(__d)			(((__d)>> 8) & 0xff)
#define TOOLKIT_LL8(__d)			(((__d)>> 0) & 0xff)

/**
 * Merge a few bytes together.
 */
#define TOOLKIT_MERGE_1(_b0)					\
	((((uint32_t)((_b0)&0xff))<<0))
#define TOOLKIT_MERGE_2(_b0, _b1)										\
	((((uint32_t)((_b0)&0xff))<<8)|(((iot_uint32_t)((_b1)&0xff))<<0))
#define TOOLKIT_MERGE_3(_b0, _b1, _b2)									\
	((((uint32_t)((_b0)&0xff))<<16)|								\
	 (((uint32_t)((_b1)&0xff))<<8)|(((iot_uint32_t)((_b2)&0xff))<<0))
#define TOOLKIT_MERGE_4(_b0, _b1, _b2, _b3)								\
	((((uint32_t)((_b0)&0xff))<<24) | (((iot_uint32_t)((_b1)&0xff))<<16) | \
	 (((uint32_t)((_b2)&0xff))<<8) | (((iot_uint32_t)((_b3)&0xff))<<0))
#define TOOLKIT_MERGE_8(_b0, _b1, _b2, _b3, _b4, _b5, _b6, _b7)			\
	((((uint64_t)((_b0)&0xff))<<56) | (((iot_uint64_t)((_b1)&0xff))<<48) | \
	 (((uint64_t)((_b2)&0xff))<<40) | (((iot_uint64_t)((_b3)&0xff))<<32) | \
	 (((uint64_t)((_b4)&0xff))<<24) | (((iot_uint64_t)((_b5)&0xff))<<16) | \
	 (((uint64_t)((_b6)&0xff))<<8) | (((iot_uint64_t)((_b7)&0xff))<<0))

/* background color */
#define TOOLKIT_B_NULL					"\033["
#define TOOLKIT_B_BLACK					"\033[40;"
#define TOOLKIT_B_RED					"\033[41;"
#define TOOLKIT_B_GREEN					"\033[42;"
#define TOOLKIT_B_YELLOW				"\033[43;"
#define TOOLKIT_B_BLUE					"\033[44;"
#define TOOLKIT_B_MAGENTA				"\033[45;"
#define TOOLKIT_B_CYAN					"\033[46;"
#define TOOLKIT_B_WHITE					"\033[47;"
/* font color */
#define TOOLKIT_F_BLACK					"30;"
#define TOOLKIT_F_RED					"31;"
#define TOOLKIT_F_GREEN					"32;"
#define TOOLKIT_F_YELLOW				"33;"
#define TOOLKIT_F_BLUE					"34;"
#define TOOLKIT_F_MAGENTA				"35;"
#define TOOLKIT_F_CYAN					"36;"
#define TOOLKIT_F_WHITE					"37;"
/* color end */
#define TOOLKIT_C_END					"\033[0m"

#endif	/* #ifndef __TOOLKIT_H__ */
