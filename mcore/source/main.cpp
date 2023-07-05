#include "shell/shell.h"
#include "server/protocol/datatype.h"

int main(void) {
	try {
		protocol::datatype::varlong_t value1 = protocol::datatype::varlong_t::encode(-2147483648);
		shell::post(shell::post_type::debug, std::to_string(value1.decode()));
		for (auto el : value1.get_bytes()) {
			shell::post(shell::post_type::debug, std::to_string(el));
		}

	} catch (const std::runtime_error& e) {
		shell::post(shell::post_type::error, e.what());
	}
	return MC_SHELL_SUCCESS;
}