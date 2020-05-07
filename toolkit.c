#include <stdio.h>
#include "toolkit.h"

TOOLKIT_RESULT_USED
int toolkit_result_used(int i)
{
	return i+1;
}

int main(void)
{
	/* result used macro test */
	/* The return value of this function is not used here, there will be a warning when compiling */
	toolkit_result_used(1);

	return 0;
}
