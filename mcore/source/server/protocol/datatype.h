#pragma once

namespace protocol {
	namespace datatype {
		typedef struct {
			unsigned char value;
		} u8_t;
		typedef struct {
			signed char value;
		} s8_t;
		typedef struct {
			unsigned char value : 3;
			unsigned char fractional : 5;
		} f8_t;

		typedef struct {
			signed short value;
		} s16_t;
		typedef struct {
			unsigned short value : 11;
			unsigned short fractional : 5;
		} f16_t;

		typedef struct {
			char value[1024];
		} array_t;
		typedef struct {
			char value[64];
		} string_t;
	}
}