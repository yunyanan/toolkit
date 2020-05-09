#include <stdio.h>
#include <stdint.h>
#include <toolkit.h>

typedef int (*init_t)(void);
typedef void (*exit_t)(void);
struct toolkit_section_order {
	char name[16];
	init_t init;
	exit_t exit;
};

#define TOOLKIT_SECTION_ORDER(_name, _init, _exit)						\
	const struct toolkit_section_order toolkit_section_order_##_name __attribute__((weak, used, section("toolkit_section_order"))) = { \
		.name = #_name,													\
		.init = _init,													\
		.exit = _exit,													\
};

TOOLKIT_INIT
static int toolkit_section_init1(void)
{
	printf("%s addr %p\n", __func__, toolkit_section_init1);

	return 0;
}

TOOLKIT_EXIT
static void toolkit_section_exit1(void)
{
	printf("%s addr %p\n", __func__, toolkit_section_exit1);
}
TOOLKIT_SECTION_ORDER(toolkit_section1,
					  toolkit_section_init1,
					  toolkit_section_exit1);

TOOLKIT_INIT
static int toolkit_section_init2(void)
{
	printf("%s addr %p\n", __func__, toolkit_section_init2);

	return 0;
}

TOOLKIT_EXIT
static void toolkit_section_exit2(void)
{
	printf("%s addr %p\n", __func__, toolkit_section_exit2);
}
TOOLKIT_SECTION_ORDER(toolkit_section2,
					  toolkit_section_init2,
					  toolkit_section_exit2);

static int toolkit_section_init3(void)
{
	printf("%s addr %p\n", __func__, toolkit_section_init3);

	return 0;
}

static void toolkit_section_exit3(void)
{
	printf("%s addr %p\n", __func__, toolkit_section_exit3);
}
TOOLKIT_SECTION_ORDER(toolkit_section3,
					  toolkit_section_init3,
					  toolkit_section_exit3);

void toolkit_section(void)
{
	const struct toolkit_section_order *order_table;
	uint32_t order_count;
	const init_t *init_p;
	const exit_t *exit_p;
	int i;

	/* The toolkit_section_order section is collected using the
	 * TOOLKIT_SECTION_LAYOUT macro. You can access this information using
	 * order_table pointer.
	 *
	 * Because the functions toolkit_section_init1 and toolkit_section_init2 use
	 * the TOOLKIT_INIT macro, so their addresses are adjacent. The
	 * toolkit_section_init3 function does not use the TOOLKIT_INIT macro, so
	 * its address is not adjacent with the toolkit_section_init1 or
	 * toolkit_section_init2 function.
	 */
	TOOLKIT_SECTION_LAYOUT(toolkit_section_order,
						   struct toolkit_section_order,
						   order_table,
						   order_count);

	for (i=0; i<order_count; i++) {
		init_p = &order_table[i].init;
		exit_p = &order_table[i].exit;
		printf("%s\n", order_table[i].name);
		(*init_p)();
		(*exit_p)();
	}
}
