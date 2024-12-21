#pragma once

#include <cstdint>

namespace nostr_pulse {

#pragma pack(push, 1)
  struct CSRHeader {
    uint64_t magicNumber;
    uint64_t nodeCount;
    uint64_t edgeCount;
  };
#pragma pack(pop)
}  // namespace nostr_pulse