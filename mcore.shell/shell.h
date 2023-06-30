#pragma once

#include "shell_post_type.h"

#define MC_SHELL_SUCCESS 0
#define MC_SHELL_FAILURE 1

class Shell {
private:


public:
	Shell();
	Shell(Shell& shell) = delete;
	
	void post(const ShellPostType& type, const std::string& message);

	~Shell();
};