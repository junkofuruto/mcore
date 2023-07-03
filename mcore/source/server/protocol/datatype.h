#pragma once

#include "../../shell/shell.h"

namespace protocol {
	namespace datatype {
		typedef class __u8_t {
			unsigned char value;
		} u8_t;
		typedef class __s8_t {
			signed char value;
		} s8_t;
		typedef class __f8_t {
		public:
			signed char value : 3;
			unsigned char fractional : 5;

#if MC_SHELL_DEEP_DEBUG
			~__f8_t();
#endif

			float to_float();
			static __f8_t from_float(float value);
		} f8_t;

		typedef class __s16_t {
		public:
			signed short value;
		} s16_t;
		typedef class __f16_t {
		public:
			signed short value : 11;
			unsigned short fractional : 5;

			float to_float() {
				return static_cast<float>(this->value) + (static_cast<float>(this->fractional) / 32.0f);
			}
		} f16_t;

		typedef class __array_t {
		public:
			char value[1024];
		} array_t;
		typedef class __string_t {
		public:
			char value[64];
		} string_t;
	}
}