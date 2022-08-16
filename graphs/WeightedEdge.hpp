#ifndef _WEIGHTED_EDGE_HPP_
#define _WEIGHTED_EDGE_HPP_

#include <ostream>

template <class VertexType>
class WeightedEdge;

template <class VertexType>
ostream& operator<<(ostream& out, const WeightedEdge<VertexType>& weightedEdge);


template <class VertexType>
struct WeightedEdge {
    VertexType source;
    VertexType destination;
    int weight;
    WeightedEdge(): source(VertexType()), destination(VertexType()), weight(-1) {};
    WeightedEdge(VertexType s, VertexType d, int w) : source(s), destination(d), weight(w) {};
    bool operator<(const WeightedEdge<VertexType>& rhs);
    bool operator>(const WeightedEdge<VertexType>& rhs);
};

template <class VertexType>
ostream& operator<<(ostream& out, const WeightedEdge<VertexType>& e) {
    out << "source: " << e.source << " destination: " << e.destination << " weight: " << e.weight;
    return out;
}

template <class VertexType>
bool WeightedEdge<VertexType>::operator<(const WeightedEdge<VertexType>& rhs) {
    return weight > rhs.weight;
}

template <class VertexType>
bool WeightedEdge<VertexType>::operator>(const WeightedEdge<VertexType>& rhs) {
    return weight < rhs.weight;
}

#endif
