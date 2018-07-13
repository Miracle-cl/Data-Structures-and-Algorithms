# python3
# from collections import defaultdict

## Good job! (Max time used: 0.18/45.00, max memory used: 9236480/536870912.)

class Graph:
    """this class represents a directed graph using adjacency matrix representation"""
    def __init__(self, graph):
        self.graph = graph # residual Graph
        self.row = len(graph)

    def bfs(self, s, t, parent):
        """
        return 1 if there's a path from source s to sink t in residual Graphself.
        Also fill parent[] to store the path
        """
        # mark all the vertices as not visited
        visited = [0] * self.row

        # create a queue for bfs
        queue = []

        # mark the source node as visited and enqueue it
        queue.append(s) # FIFO
        visited[s] = 1

        # standard bfs loop
        while queue:
            # dequeue a vertex from queue and print it
            u = queue.pop(0) # first out

            # Get all adjacent vertices of the dequeued vertex u
            # If a adjacent has not been visited, then mark it
            # visited and enqueue it
            for ind, val in enumerate(self.graph[u]):
                if visited[ind] == 0 and val > 0 :
                    queue.append(ind)
                    visited[ind] = 1
                    parent[ind] = u

        # If we reached sink in BFS starting from source, then return
        # true, else false
        return 1 if visited[t] else 0


    def ford_fulkerson(self, source, sink):
        """
        Returns tne maximum flow from s to t in the given graph
        """
        # This array is filled by BFS and to store path
        parent = [-1] * self.row

        max_flow = 0 # There is no flow initially

        # Augment the flow while there is path from source to sink
        while self.bfs(source, sink, parent):

            # Find minimum residual capacity of the edges along the path filled by BFS.
            # Or we can say find the maximum flow through the path found.
            path_flow = float("Inf")
            s = sink
            while s != source:
                path_flow = min(path_flow, self.graph[parent[s]][s])
                s = parent[s]

            # Add path flow to overall flow
            max_flow +=  path_flow

            # update residual capacities of the edges and reverse edges along the path
            v = sink
            while v !=  source:
                u = parent[v]
                self.graph[u][v] -= path_flow
                self.graph[v][u] += path_flow
                v = parent[v]

            ### ===== show process =====
            # print("parent: ", parent)
            # print("graph: ", self.graph)
            # print("path_flow: ", max_flow)
            # print()

        return max_flow

if __name__ == '__main__':
    vertex_count, edge_count = map(int, input().split())

    adj_matrix = [[0] * vertex_count for _ in range(vertex_count)] # graph
    for _ in range(edge_count):
        u, v, capacity = map(int, input().split())
        adj_matrix[u-1][v-1] += capacity
    g = Graph(adj_matrix)
    print(g.ford_fulkerson(0, vertex_count-1))


# Create a graph given in the above diagram
# graph = [[0, 16, 13, 0, 0, 0],
#         [0, 0, 10, 12, 0, 0],
#         [0, 4, 0, 0, 14, 0],
#         [0, 0, 9, 0, 0, 20],
#         [0, 0, 0, 7, 0, 4],
#         [0, 0, 0, 0, 0, 0]]
# g = Graph(graph)
# source = 0; sink = 5
# print ("The maximum possible flow is %d " % g.FordFulkerson(source, sink))
