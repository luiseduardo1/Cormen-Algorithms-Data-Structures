# Simple implementation of BFS algorithm

# Graph implemented with an adjacency list which stores each element in a dictionary with their value being a list with
# their adjacent nodes

graph = { 'A': ['B', 'C'],
          'B': ['A', 'D', 'E'],
          'C': ['A', 'F'],
          'D': ['B'],
          'E': ['B', 'F'],
          'F': ['C', 'E'] }

def BFS(graph, start, end):
    parent = {}
    queue = []
    queue.append(start)
    while queue:
        node = queue.pop(0)
        if node == end:
            return backtrace(parent, start, end)
        for adjacent in graph.get(node, []):
            parent[adjacent] = node 
            queue.append(adjacent)

def backtrace(parent, start, end):
    path = [end]
    while path[-1] != start:
        path.append(parent[path[-1]])
    path.reverse()
    return path

print (BFS(graph, 'A', 'E'))
