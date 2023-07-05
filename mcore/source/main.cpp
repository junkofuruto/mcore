#include "shell/shell.h"
#include "server/protocol/datatype.h"

int main(void) {
	protocol::datatype::varint_t v = protocol::datatype::varint_t::encode(25565);

	shell::post(shell::post_type::info, std::to_string(v.decode()));
	for (auto el : v.get_bytes()) {
		shell::post(shell::post_type::info, std::to_string(el));
	}

	return MC_SHELL_SUCCESS;
}