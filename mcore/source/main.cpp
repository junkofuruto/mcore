#include "shell/shell.h"
#include "server/protocol/datatype.h"
#include "server/protocol/packet.h"

int main(void) {
	protocol::datatype::f8_t point = protocol::datatype::f8_t::from_float(3.96875f);

	shell::post(shell::post_type::Info, std::to_string(point.to_float()));
	shell::post(shell::post_type::Info, std::to_string(sizeof(point)));
	shell::post(shell::post_type::Trace, "Exiting...");

	return MC_SHELL_SUCCESS;
}