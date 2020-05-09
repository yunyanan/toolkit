#include <stdio.h>

#include <toolkit.h>
#include <toolkit_common.h>
#include <toolkit_section.h>

int main(void)
{
	printf("%s start\n", __func__);

	toolkit_common();
	toolkit_section();

	printf("%s end\n", __func__);

	return 0;
}
