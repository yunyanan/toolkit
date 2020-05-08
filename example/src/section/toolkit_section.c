#include <stdio.h>

struct toolkit_section_order {
	char name[16];
	init_callback init;
	exit_callback exit;
	dispose_callback dispose;
};

#define TOOLKIT_SECTION_ORDER(_name, _init, _exit, _dispose) \
	const struct toolkit_section_order toolkit_section_order_##_name __attribute__((weak, used, section("toolkit_section_order"))) = { \
		.name = #_name,													\
		.rxcache_size = _rx_size,										\
		.txcache_size = _tx_size,										\
		.init = _init,													\
		.exit = _exit,													\
		.dispose = _dispose,											\
	};

int main(void)
{
	return 0;
}
