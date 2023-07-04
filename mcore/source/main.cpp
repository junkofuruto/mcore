#include "shell/shell.h"
#include "server/protocol/datatype.h"

int main(void) {
	protocol::datatype::varlong_t v = protocol::datatype::varlong_t::encode(-1);

	shell::post(shell::post_type::info, std::to_string(v.decode()));
	for (auto el : v.get_bytes()) {
		shell::post(shell::post_type::info, std::to_string(el));
	}

	return MC_SHELL_SUCCESS;
}