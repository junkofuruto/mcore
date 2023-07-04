#pragma once

namespace protocol::datatype {
    template<typename T> class __mc_prot_varlen {
    private:
        std::unique_ptr<unsigned char[]> value;
        char length;

    public:
        __mc_prot_varlen() : value(nullptr), length(0) {}

        static __mc_prot_varlen encode(T value) {
            std::vector<uint8_t> buffer;

            bool isNegative = false;
            if (value < 0) {
                isNegative = true;
                value = -value;
            }

            do {
                uint8_t byte = value & 0x7F;
                value >>= 7;
                if (value != 0) {
                    byte |= 0x80;
                }
                buffer.push_back(byte);
            } while (value != 0);

            if (isNegative) {
                buffer.back() |= 0x40;
            }

            __mc_prot_varlen result;
            result.length = static_cast<unsigned char>(buffer.size());
            result.value = std::make_unique<unsigned char[]>(result.length);
            memcpy(result.value.get(), buffer.data(), result.length);

            return result;
        }

        T decode() {
            T result = 0;
            size_t shift = 0;
            size_t i = 0;

            uint8_t byte;

            do {
                byte = value[i++];
                result |= (T)(byte & 0x7F) << shift;
                shift += 7;
            } while ((byte & 0x80) != 0 && i < length);

            return result;
        }

        std::vector<unsigned char> get_bytes() {
            std::vector<unsigned char> result;
            for (size_t i = 0; i < length; i++) {
                result.push_back(value.get()[i]);
            }
            return result;
        }
    };
}