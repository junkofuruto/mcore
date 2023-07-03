#include "datatype.h"

#if MC_SHELL_DEEP_DEBUG
protocol::datatype::__f8_t::~__f8_t() {
	shell::post(shell::post_type::Debug, "Object deleted");
}
#endif

float protocol::datatype::__f8_t::to_float() {
	return static_cast<float>(this->value) + (static_cast<float>(this->fractional) / 32.0f);
}

protocol::datatype::f8_t protocol::datatype::__f8_t::from_float(float value) {
	__f8_t result;
	const int factor = 1 << 5;
	unsigned long long temp = (unsigned long long)(value * factor);
	result.value = temp / factor;
	result.fractional = temp - result.value * factor;
	return result;
}
