#include "graph.h"

using namespace nostr_pulse;

int Graph::getOrCreateNodeId(const std::string& pubkey) {
    auto it = pubkeyToNodeId.find(pubkey);
    if (it != pubkeyToNodeId.end()) {
        return it->second;
    }
    int newId = nextNodeId++;
    nodes.emplace_back(pubkey, newId);
    pubkeyToNodeId[pubkey] = newId;
    return newId;
}

Node& Graph::getNodeById(int nodeId) {
    return nodes[nodeId];
}

void Graph::addEdge(const std::string& srcPubkey, const std::string& dstPubkey) {
    int srcId = getOrCreateNodeId(srcPubkey);
    int dstId = getOrCreateNodeId(dstPubkey);

    edges.emplace_back(srcId, dstId);
}
