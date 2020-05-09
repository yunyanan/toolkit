#include <toolkit.h>

TOOLKIT_RESULT_USED
static int toolkit_common_result_used(int i)
{
	return i+1;
}

void toolkit_common(void)
{
	int a;

	a = 0;
	/* The return value of this function is not used here,
	 * there will be a warning when compiling. */
	toolkit_common_result_used(a);
}
