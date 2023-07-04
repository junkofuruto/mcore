#pragma once

#include "datatype/numeric.h"
#include "datatype/varlen.h"

namespace protocol::datatype {
	typedef __mc_prot_numeric<bool>					bool_t;
	typedef __mc_prot_numeric<float>				float_t;
	typedef __mc_prot_numeric<double>				double_t;
	typedef __mc_prot_numeric<signed char>			byte_t;
	typedef __mc_prot_numeric<signed short>			short_t;
	typedef __mc_prot_numeric<signed int>			int_t;
	typedef __mc_prot_numeric<signed long long>		long_t;
	typedef __mc_prot_numeric<unsigned char>		ubyte_t;
	typedef __mc_prot_numeric<unsigned short>		ushort_t;
	typedef __mc_prot_varlen<signed int>			varint_t;
	typedef __mc_prot_varlen<signed long long>		varlong_t;
}