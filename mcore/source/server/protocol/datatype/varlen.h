#pragma once

#include <vector>
#include <memory>
#include <stdexcept>

#include "getbytes.h"

namespace protocol::datatype {
    template<typename T> class __mc_prot_varlen : public __mc_prot_asbytes_i {
    private:
        std::unique_ptr<unsigned char[]> value;
        unsigned char length;

    public:
        __mc_prot_varlen() : value(nullptr), length(0) {}

        static __mc_prot_varlen encode(T value) {
            using unsigned_T = typename std::make_unsigned<T>::type;
            std::vector<unsigned char> buffer;
            unsigned_T uvalue = static_cast<unsigned_T>(value);
            while (uvalue >= 0x80) {
                buffer.push_back(static_cast<unsigned char>((uvalue & 0x7F) | 0x80));
                uvalue >>= 7;
            }
            buffer.push_back(static_cast<unsigned char>(uvalue));
            __mc_prot_varlen result;
            result.length = static_cast<unsigned char>(buffer.size());
            result.value = std::make_unique<unsigned char[]>(result.length);
            std::memcpy(result.value.get(), buffer.data(), result.length);
            return result;
        }
        static __mc_prot_varlen create(const std::vector<unsigned char>& array) {
            if (array.size() > (sizeof(T) + 1 * sizeof(T) / 4)) {
                throw std::runtime_error("INNER-DT-VARLEN-MISMATCH (varlen.h): Input array of bytes is bigger than possible result");
            }
            __mc_prot_varlen result;
            result.length = static_cast<unsigned char>(array.size());
            result.value = std::make_unique<unsigned char[]>(result.length);
            std::memcpy(result.value.get(), array.data(), result.length);
            return result;
        }
        std::vector<unsigned char> get_bytes() const override {
            std::vector<unsigned char> result(value.get(), value.get() + length);
            return result;
        }
        T decode() const {
            T result = 0;
            int position = 0;
            unsigned char current_byte, i = 0;
            while (true) {
                current_byte = value[i++];
                result |= static_cast<T>(current_byte & 0x7F) << position;
                if ((current_byte & 0x80) == 0) {
                    break;
                }
                position += 7;
            }
            return result;
        }
    };
}