#include "shell/shell.h"
#include "server/protocol/datatype.h"

int main(void) {
	shell::post(shell::post_type::trace, "trace");

	protocol::datatype::varint_t v = protocol::datatype::varint_t::encode(25565);

	shell::post(shell::post_type::debug, std::to_string(v.decode()));
	for (auto el : v.get_bytes()) {
		shell::post(shell::post_type::debug, std::to_string(el));
	}

	return MC_SHELL_SUCCESS;
}