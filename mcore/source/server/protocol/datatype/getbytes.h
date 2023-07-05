#pragma once

#include <vector>

namespace protocol::datatype {
	class __mc_prot_asbytes_i {
	public:
		virtual std::vector<unsigned char> get_bytes() const = 0;
	};
}