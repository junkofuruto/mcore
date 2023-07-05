#pragma once

#include "getbytes.h"

namespace protocol::datatype {
	template<typename T> class __mc_prot_numeric : public __mc_prot_asbytes_i {
	private:
		T m_value;

	public:
		__mc_prot_numeric() : m_value(0) {}
		__mc_prot_numeric(T value) : m_value(value) {}

		T value() {
			return m_value;
		}

		std::vector<unsigned char> get_bytes() const override {
			const unsigned char* bytes = reinterpret_cast<const unsigned char*>(&m_value);
			size_t size = sizeof(m_value);
			std::vector<unsigned char> result(bytes, bytes + size);
			return result;
		}

		template<typename U> __mc_prot_numeric& operator=(U val) {
			m_value = val;
			return *this;
		}
	};
}