#include "graph.hpp"

int main() {
    Graph graphA(11);
    std::vector<std::pair<int, int> > adjacencyList= { {0,1}, {0,2}, {0,3}, {1,6}, {1,2}, {2,6}, {2,5}, {3,9},
        {4,7}, {4,8}, {5,9}, {6,4}, {6,5}, {6,7}, {7,10}, {8,5}, {9,7}, {10,9} };
    graphA.addEdges(adjacencyList);
    Graph graphB = graphA;

    graphA.BFS(0); // Will print : 0 1 2 3 6 5 9 4 7 8 10
    graphB.BFSMinPath(0, 10); // Will print : 0 1 6 7 10

    return 0;
}
