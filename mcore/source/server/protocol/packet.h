#pragma once

#include "datatype.h"

namespace protocol {
	namespace packet {
		class cs_player_id {
		public:
			protocol::datatype::u8_t id { 0x00 };
			protocol::datatype::u8_t protocol_version;
			protocol::datatype::string_t username;
			protocol::datatype::string_t verification_key;
			protocol::datatype::u8_t unused;
		};
	}
}