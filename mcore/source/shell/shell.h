#pragma once

#include <string>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>

#define MC_SHELL_SUCCESS 0
#define MC_SHELL_FAILURE 1

namespace shell {
	enum class post_type {
		Trace		= '7',
		Info		= '2',
		Debug		= '4',
		Warning		= '3',
		Error		= '1',
	};

	void post(const post_type& type, const std::string& message);
}