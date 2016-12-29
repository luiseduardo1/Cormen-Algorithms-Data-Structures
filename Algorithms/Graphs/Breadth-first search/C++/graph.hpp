#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

class Graph {
public:
    Graph(int numberOfNodes): adjacencyVector(numberOfNodes) {}
    void addEdges(std::vector<std::pair<int, int> > const& edgeList);
    void BFS(int startNode);
    void BFSMinPath(int startNode, int endNode);
    
private:
    std::vector<std::vector<int> > adjacencyVector;
};

#endif
