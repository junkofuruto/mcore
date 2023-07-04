#include "shell/shell.h"
#include "server/protocol/datatype.h"

int main(void) {
	protocol::datatype::bool_t v = true;
	v = false;

	return MC_SHELL_SUCCESS;
}