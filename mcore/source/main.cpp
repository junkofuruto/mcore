#include "shell/shell.h"
#include "server/protocol/datatype.h"

int main(void) {
	shell::post(shell::post_type::info, std::to_string(sizeof(protocol::datatype::boolean)));
	shell::post(shell::post_type::info, std::to_string(sizeof(protocol::datatype::s_byte)));
	shell::post(shell::post_type::info, std::to_string(sizeof(protocol::datatype::s_short)));
	shell::post(shell::post_type::info, std::to_string(sizeof(protocol::datatype::s_int)));
	shell::post(shell::post_type::info, std::to_string(sizeof(protocol::datatype::s_long)));

	return MC_SHELL_SUCCESS;
}