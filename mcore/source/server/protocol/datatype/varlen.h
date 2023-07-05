#pragma once

namespace protocol::datatype {
    template<typename T> class __mc_prot_varlen {
    private:
        std::unique_ptr<unsigned char[]> value;
        unsigned char length;

    public:
        __mc_prot_varlen() : value(nullptr), length(0) {}

        static __mc_prot_varlen encode(T value) {
            std::vector<unsigned char> buffer;

            while (true) {
                if ((value & ~((T)0x7F)) == 0) {
                    buffer.push_back(value);
                    break;
                }

                buffer.push_back((value & 0x7F) | 0x80);
                value >>= 7;
            }

            __mc_prot_varlen result;
            result.length = static_cast<unsigned char>(buffer.size());
            result.value = std::make_unique<unsigned char[]>(result.length);
            memcpy(result.value.get(), buffer.data(), result.length);

            return result;
        }

        T decode() {
            T result = 0;
            int position = 0;
            unsigned char currentByte, i = 0;

            while (true) {
                currentByte = value.get()[i++];
                result |= static_cast<T>(currentByte & 0x7F) << position;

                if ((currentByte & 0x80) == 0)
                    break;

                position += 7;
            }

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