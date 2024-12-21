#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "edge.h"
#include "node.h"

namespace nostr_pulse {

  class Graph {
  public:
    // Adds or retrieves the nodeId for a given pubkey
    int getOrCreateNodeId(const std::string& pubkey);

    // Returns reference to a Node by ID
    Node& getNodeById(int nodeId);

    // Create a directed edge from 'srcPubkey' to 'dstPubkey'.
    // This will automatically create nodes if they don't exist yet.
    void addEdge(const std::string& srcPubkey, const std::string& dstPubkey);

    const std::vector<Node>& getAllNodes() const { return nodes; }
    const std::vector<Edge>& getAllEdges() const { return edges; }

  private:
    // We hold a contiguous list of Node structs
    std::vector<Node> nodes;

    // For a quick way to find a Node by pubkey
    // Key = pubkey hex, value = nodeId index
    std::unordered_map<std::string, int> pubkeyToNodeId;

    std::vector<Edge> edges;

    int nextNodeId = 0;
  };
}  // namespace nostr_pulse