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
			unsigned char value : 4;
			unsigned char fractional : 4;
		} f8_t;

		typedef struct {

		} ;
	}
}