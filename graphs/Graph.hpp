#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_


#include <ostream>
#include <cstdio>

#include "List.hpp"
#include "WeightedEdge.hpp"

using namespace std;

class FullGraph {};
class VertexNotFound {};

template<class VertexType>
class Graph {
public:
    Graph(int maxVertices);
    ~Graph();
    void prettyPrint(ostream& out);
    void addEdge(VertexType a, VertexType b);
    void addEdge(VertexType a, VertexType b, int weight);
    void addVertex(VertexType v);
    bool isFull();
    int indexOf(VertexType v);
    void getNeighbors(VertexType v, List<VertexType> &list);
    void mark(VertexType v);
    void mark(VertexType v, int weight);
    void clearMarks();
    bool isMarked(VertexType v);
    void getWeightedEdges(VertexType v, List< WeightedEdge<VertexType> > &list);
    int getNumVertices() { return numVertices; }
private:
    int maxVertices;
    int numVertices;
    VertexType * vertices;
    //bool * marks;
    int * marks;
    int ** edgeMatrix;
};


template<class VertexType>
Graph<VertexType>::Graph(int maxVertices) : maxVertices(maxVertices) {
    vertices = new VertexType[maxVertices];
    //marks = new bool[maxVertices];
    marks = new int[maxVertices];
    edgeMatrix = new int*[maxVertices];
    for (int i = 0; i < maxVertices; i++) {
        edgeMatrix[i] = new int[maxVertices];
        for (int j = 0; j < maxVertices; j++) {
            edgeMatrix[i][j] = -1;
        }
    }
    clearMarks();
    numVertices = 0;
}

template<class VertexType>
Graph<VertexType>::~Graph() {
    cout << "Inside destructor for Graph..." << endl;
    for (int i = 0; i < maxVertices; i++) {
        delete[] edgeMatrix[i];
    }
    delete[] edgeMatrix;
    delete[] vertices;
    delete[] marks;
}

template<class VertexType>
void Graph<VertexType>::prettyPrint(ostream& out) {
    out << "Vertices:" << endl;
    for (int i = 0; i < numVertices; i++) {
        out << i << " -> " << vertices[i];
        if (i < numVertices - 1) {
            out << ", ";
        }
    }
    out << endl << "Edges:" << endl;
    char buf[5];

    // Print header
    for (int i = -1; i < numVertices; i++) {
        if (i < 0) {
            snprintf(buf, sizeof(buf), "%-5s", "");
        } else {
            snprintf(buf, sizeof(buf), "%-5d", i);
        }
        out << buf;
    }
    out << endl;

    // Print rows
    for (int i = 0; i < numVertices; i++) {
        for (int j = -1; j < numVertices; j++) {
            if (j < 0) {
                snprintf(buf, sizeof(buf), "%-5d", i);
            } else {
                if (edgeMatrix[i][j] > 0) {
                    snprintf(buf, sizeof(buf), "%-5d", edgeMatrix[i][j]);
                } else {
                    snprintf(buf, sizeof(buf), "%-5s", "");
                }
            }
            out << buf;
        }
        out << endl;
    }
}

template<class VertexType>
int Graph<VertexType>::indexOf(VertexType v) {
    for (int i = 0; i < numVertices; i++) {
        if (vertices[i] == v) {
            return i;
        }
    }
    return -1;
}

template<class VertexType>
void Graph<VertexType>::addEdge(VertexType a, VertexType b) {
    addEdge(a, b, 1);
    //int i = indexOf(a);
    //int j = indexOf(b);
    //if (i < 0 || j < 0) {
    //   throw VertexNotFound();
    //}
    //edgeMatrix[i][j] = 1;
}

template<class VertexType>
void Graph<VertexType>::addEdge(VertexType a, VertexType b, int weight) {
    int i = indexOf(a);
    int j = indexOf(b);
    if (i < 0 || j < 0) {
        throw VertexNotFound();
    }
    edgeMatrix[i][j] = weight;
}

template<class VertexType>
void Graph<VertexType>::addVertex(VertexType v) {
    if (isFull()) {
        throw FullGraph();
    }
    if (indexOf(v) > -1) {
        return;
    }
    vertices[numVertices] = v;
    for (int i = 0; i <= numVertices; i++) {
        edgeMatrix[i][numVertices] = -1;
        edgeMatrix[numVertices][i] = -1;
    }
    numVertices += 1;
}

template<class VertexType>
bool Graph<VertexType>::isFull() {
    return numVertices >= maxVertices;
}

template<class VertexType>
void Graph<VertexType>::getNeighbors(VertexType v, List<VertexType>& list) {
    int i = indexOf(v);
    if (i < 0) {
        throw VertexNotFound();
    }
    for (int j = 0; j < numVertices; j++) {
        if (edgeMatrix[i][j] > -1) {
            list.push(vertices[j]);
        }
    }
}

template<class VertexType>
void Graph<VertexType>::getWeightedEdges(VertexType v, List< WeightedEdge<VertexType> > &list) {
    int i = indexOf(v);
    if (i < 0) {
        throw VertexNotFound();
    }
    for (int j = 0; j < numVertices; j++) {
        if (edgeMatrix[i][j] > -1) {
            list.push(WeightedEdge<VertexType>(v, vertices[j], edgeMatrix[i][j]));
        }
    }
}


template<class VertexType>
void Graph<VertexType>::mark(VertexType v) {
    //int i = indexOf(v);
    //if (i < 0) {
    //    throw VertexNotFound();
    //}
    //marks[i] = true;
    mark(v, 1);
}

template<class VertexType>
void Graph<VertexType>::mark(VertexType v, int weight) {
    int i = indexOf(v);
    if (i < 0) {
        throw VertexNotFound();
    }
    marks[i] = weight;
}

template<class VertexType>
void Graph<VertexType>::clearMarks() {
    for (int i = 0; i < maxVertices; i++) {
        //marks[i] = false;
        marks[i] = -1;
    }
}

template<class VertexType>
bool Graph<VertexType>::isMarked(VertexType v) {
    int i = indexOf(v);
    if (i < 0) {
        throw VertexNotFound();
    }
    return marks[i] > -1;
}


#endif
