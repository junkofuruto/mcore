#pragma once

#include <stdint.h>

namespace protocol {
	namespace datatype {
		template<typename T> class __mc_prot_numerical {
		private:
			T m_value;

		public:
			__mc_prot_numerical() : m_value(0) {}
			__mc_prot_numerical(T value) : m_value(value) {}

			T value() {
				return m_value;
			}

			__mc_prot_numerical& operator=(bool val) {
				m_value = val;
				return *this;
			}
			__mc_prot_numerical& operator=(signed char val) {
				m_value = val;
				return *this;
			}
			__mc_prot_numerical& operator=(signed short val) {
				m_value = val;
				return *this;
			}
			__mc_prot_numerical& operator=(signed int val) {
				m_value = val;
				return *this;
			}
			__mc_prot_numerical& operator=(signed long val) {
				m_value = val;
				return *this;
			}
			__mc_prot_numerical& operator=(unsigned char val) {
				m_value = val;
				return *this;
			}
			__mc_prot_numerical& operator=(unsigned short val) {
				m_value = val;
				return *this;
			}
			__mc_prot_numerical& operator=(unsigned int val) {
				m_value = val;
				return *this;
			}
			__mc_prot_numerical& operator=(unsigned long val) {
				m_value = val;
				return *this;
			}
		};


		typedef __mc_prot_numerical<bool>			bool_t;
		typedef __mc_prot_numerical<int8_t>			s8_t;
		typedef __mc_prot_numerical<uint8_t>		u8_t;
		typedef __mc_prot_numerical<int16_t>		s16_t;
		typedef __mc_prot_numerical<uint16_t>		u16_t;
		typedef __mc_prot_numerical<int32_t>		s32_t;
		typedef __mc_prot_numerical<int64_t>		s64_t;
		typedef float								f32_t;
		typedef double								f64_t;
	}
}