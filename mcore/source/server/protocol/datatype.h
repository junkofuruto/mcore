#pragma once

#include <stdint.h>

#include "datatype/numeric.h"

namespace protocol::datatype {
	typedef __mc_prot_numeric<bool>			bool_t;
	typedef __mc_prot_numeric<int8_t>		s8_t;
	typedef __mc_prot_numeric<uint8_t>		u8_t;
	typedef __mc_prot_numeric<int16_t>		s16_t;
	typedef __mc_prot_numeric<uint16_t>		u16_t;
	typedef __mc_prot_numeric<int32_t>		s32_t;
	typedef __mc_prot_numeric<int64_t>		s64_t;
	typedef float							f32_t;
	typedef double							f64_t;
}