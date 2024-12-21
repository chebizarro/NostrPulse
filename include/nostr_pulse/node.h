#pragma once

#include <optional>
#include <string>

namespace nostr_pulse {

  struct Node {
    std::string pubkey;

    // Internal integer ID, used for adjacency structures.
    int nodeId = -1;

    // Basic user metadata from kind 0 events
    std::optional<std::string> name;
    std::optional<std::string> about;
    std::optional<std::string> pictureUrl;

    Node() = default;

    Node(std::string pubkey_, int nodeId_) : pubkey(std::move(pubkey_)), nodeId(nodeId_) {}
  };
}  // namespace nostr_pulse