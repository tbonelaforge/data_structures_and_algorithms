#include <iostream>
#include <string>

#include "Graph.hpp"
#include "List.hpp"
#include "WeightedEdge.hpp"
#include "PriorityQueue.hpp"

using namespace std;

template<class VertexType>
void dfs(Graph<VertexType>& g, VertexType a, VertexType b) {
    List<VertexType> stack;
    List<VertexType> neighbors;
    stack.push(a);
    g.clearMarks();
    while (!stack.isEmpty()) {
        VertexType v = stack.pop();
        if (v == b) {
            cout << "Found: " << v << endl;
            return;
        }
        if (g.isMarked(v)) {
            continue;
        }
        cout << "Visiting: " << v << endl;
        g.mark(v);
        g.getNeighbors(v, neighbors);
        while (!neighbors.isEmpty()) {
            stack.push(neighbors.dequeue());
        }
    }
    cout << "Did not find: " << b;
}

template<class VertexType>
void bfs(Graph<VertexType>& g, VertexType a, VertexType b) {
    List<VertexType> queue;
    List<VertexType> neighbors;
    queue.push(a);
    g.clearMarks();
    while (!queue.isEmpty()) {
        VertexType v = queue.dequeue();
        if (v == b) {
            cout << "Found: " << v << endl;
            cout << "about to return...the queue is:" << endl << queue;
            cout << "And the neighbors is:" << endl << neighbors;
            return;
        }
        if (g.isMarked(v)) {
            continue;
        }
        cout << "Visiting: " << v << endl;
        g.mark(v);
        g.getNeighbors(v, neighbors);
        while (!neighbors.isEmpty()) {
            VertexType n = neighbors.dequeue();
            cout << "about to push: " << n << endl;
            queue.push(n);
        }
    }
    cout << "Did not find: " << b;
}


template <class VertexType>
void shortestPath(Graph<VertexType>& g, VertexType a, VertexType b) {
    int n = g.getNumVertices();
    PriorityQueue<WeightedEdge <VertexType> > pq(n * n);
    List< WeightedEdge<VertexType> > neighborEdges;
    WeightedEdge<VertexType> edge(a, a, 0);
    VertexType v;
    int shortestPathWeight;

    g.clearMarks();
    pq.enqueue(edge);
    while (!pq.isEmpty()) {
        edge = pq.dequeue();
        v = edge.destination;
        shortestPathWeight = edge.weight;
        cout << "The shortest path that ends in " << edge.source << " - " << v 
             << " has total weight: " << shortestPathWeight << endl;
        g.mark(v, shortestPathWeight);
        if (v == b) {
            cout << "Path Found." << endl;
            return;
        }
        g.getWeightedEdges(v, neighborEdges);
        while (!neighborEdges.isEmpty()) {
            edge = neighborEdges.dequeue();
            if (g.isMarked(edge.destination)) {
                continue;
            }
            edge.weight += shortestPathWeight;
            pq.enqueue(edge);
        }
    }
    cout << "No path found from " << a << " to " << b << endl;
}

void testListCleanup() {
    List<string> l;
    l.push("A");
    l.push("B");
    l.push("C");
    l.dequeue();
}

int main() {
    cout << "About to construct a new graph, with maxVertices of 6" << endl;
    Graph<string> g(5);
    cout << "Made it past the construction of the graphe..." << endl;
    cout << "ABout to prettyPrint the (empty) graph..." << endl;
    g.prettyPrint(cout);
    cout << "About to add a Vertex 'A'" << endl;
    g.addVertex("A");
    cout << "Now the graph looks like:" << endl;
    g.prettyPrint(cout);
    cout << "About to add a link from 'A' to 'A'" << endl;
    g.addEdge("A", "A");
    cout << "Now the graph looks like:" << endl;
    g.prettyPrint(cout);
    cout << "About to add some more vertices..." << endl;
    g.addVertex("B");
    g.addVertex("A");
    g.addVertex("C");
    g.addVertex("D");
    cout << "NOw that we have 4 vertices it looks like: " << endl;
    g.prettyPrint(cout);
    cout << "About to add some more edges..." << endl;
    g.addEdge("A", "B");
    g.addEdge("D", "B");
    g.addEdge("B", "D");
    g.addEdge("D", "A");
    g.addEdge("D", "C");
    cout << "Now the graph looks like:" << endl;
    g.prettyPrint(cout);
    cout << "About to test the getNeighbors function..." << endl;
//    List<string> q;
//    g.getNeighbors("A", q);
//    cout << "Made it past the getNeighbors call, not the list has neighbors.." << endl;
//    cout << q;
//    cout << "About to dfs from B to A" << endl;
//    dfs<string>(g, "B", "A");
//    cout << "Done" << endl;
    cout << "About to bfs from B to A" << endl;
    bfs<string>(g, "B", "A");
    cout << "About to shortest path search from A to D" << endl;
    shortestPath<string>(g, "A", "D");
    cout << "Done" << endl;


}
