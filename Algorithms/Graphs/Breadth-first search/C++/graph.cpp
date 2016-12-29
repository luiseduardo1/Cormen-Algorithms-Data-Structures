#include "graph.hpp"

void Graph::addEdges(std::vector<std::pair<int, int> > const& edgeList) {
    for (auto const& edge : edgeList) {
        adjacencyVector[edge.first].push_back(edge.second);
    }
}

void Graph::BFS(int startNode) {
    std::vector<bool> visited(adjacencyVector.size());

    std::queue<int> queue;
    queue.push(startNode);
    visited[startNode] = true;

    std::cout << "Breadth first traversal : ";

    while (!queue.empty()) {
        startNode = queue.front();
        std::cout<< startNode << " ";
        queue.pop();

        for (auto node : adjacencyVector[startNode]) {
            if (!visited[node]) {
                visited[node] = true;
                queue.push(node);
            }
        }
    }

    std::cout << std::endl;
}

void Graph::BFSMinPath(int startNode, int endNode) {
    int start = startNode;
    std::vector<bool> visited(adjacencyVector.size());
    std::vector<int> previous(adjacencyVector.size());

    std::queue<int> queue;
    queue.push(start);
    visited[start] = true;
    previous[start] = -1;
    bool found = false;

    while (!queue.empty() && !found) {
        start = queue.front();
        queue.pop();

        for (auto node : adjacencyVector[start]) {
            if (!visited[node]) {
                visited[node] = true;
                queue.push(node);
                previous[node] = start;
            }

            if (node == endNode) {
                found = true;
            }
        }
    }

    if (!found) {
        std::cout << "There is no path between " << startNode << " and " << endNode << std::endl;
    } else {
        std::vector<int> shortestPath;

        int node = endNode;
        while (node != -1) {
            shortestPath.push_back(node);
            node = previous[node];
        }

        std::reverse(shortestPath.begin(), shortestPath.end());
        std::cout << "The shortest path between " << startNode << " and " << endNode << " is : ";
        for (auto node : shortestPath) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }
}
