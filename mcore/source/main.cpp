#include "shell/shell.h"

int main(void)
{
	shell::init(std::cout);
	shell::post(shell::post_type::Trace, "XD");

	return MC_SHELL_SUCCESS;
}