#include "shell/shell.h"
#include "server/protocol/datatype.h"
#include "server/protocol/packet.h"

int main(void) {
	protocol::datatype::f8_t point {0b111, 0b11111};

	shell::post(shell::post_type::Info, std::to_string(static_cast<float>(point.value) + (static_cast<float>(point.fractional) / 32.0)));

	return MC_SHELL_SUCCESS;
}