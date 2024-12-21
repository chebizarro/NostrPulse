#pragma once

#include <cstdint>

namespace nostr_pulse {

  struct Edge {
    int srcId;
    int dstId;

    Edge(int s, int d) : srcId(s), dstId(d) {}
  };

}  // namespace nostr_pulse