#pragma once

#include <string>
#include <iostream>

#define MC_SHELL_SUCCESS 0
#define MC_SHELL_FAILURE 1

namespace shell {
	enum class post_type {
		Trace,
		Info,
		Debug,
		Warning,
		Error,
		Critical,
	};

	void init(const std::ostream& stream);
	void post(const post_type& type, const std::string& message);
}