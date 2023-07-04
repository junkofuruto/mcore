#pragma once

namespace protocol::datatype {
	template<typename T> class __mc_prot_numeric {
	private:
		T m_value;

	public:
		__mc_prot_numeric() : m_value(0) {}
		__mc_prot_numeric(T value) : m_value(value) {}

		T value() {
			return m_value;
		}

		template<typename U> __mc_prot_numeric& operator=(const U& val) {
			m_value = val;
			return *this;
		}
	};
}