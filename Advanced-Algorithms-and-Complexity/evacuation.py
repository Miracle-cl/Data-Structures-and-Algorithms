# python3

class Edge:

    def __init__(self, u, v, capacity):
        self.u = u
        self.v = v
        self.capacity = capacity
        self.flow = 0

# This class implements a bit unusual scheme for storing edges of the graph,
# in order to retrieve the backward edge for a given edge quickly.
class FlowGraph:

    def __init__(self, n, m):
        # List of all - forward and backward - edges
        self.n = n # vertex_count
        self.m = m # edge_count
        self.edges = []
        # These adjacency lists store only indices of edges in the edges list
        self.graph = [[] for _ in range(n)]
        ## sample 1 - graph : [[0, 4], [1, 2, 11, 12], [5, 6, 10], [7, 8, 13], [3, 9]]
        ## graph[from_] : the path go from 'from_'
        ## graph[0] : [0, 4] - edges[0] and edges[4] is the edges go from '0'
        ## edges[0] : Edge(0,1,2,0); edges[4] : Edge(0,2,6,0)

    def read_data(self):
        for _ in range(self.m):
            u, v, capacity = map(int, input().split())
            self.add_edge(u - 1, v - 1, capacity)

    def add_edge(self, from_, to, capacity):
        # Note that we first append a forward edge and then a backward edge,
        # so all forward edges are stored at even indices (starting from 0),
        # whereas backward edges are stored at odd indices.
        forward_edge = Edge(from_, to, capacity)
        backward_edge = Edge(to, from_, 0)
        self.graph[from_].append(len(self.edges))
        self.edges.append(forward_edge)
        self.graph[to].append(len(self.edges))
        self.edges.append(backward_edge)

    def size(self):
        return len(self.graph)

    def get_ids(self, from_):
        return self.graph[from_]

    def get_edge(self, id):
        return self.edges[id]

    def add_flow(self, id, flow):
        # To get a backward edge for a true forward edge (i.e id is even), we should get id + 1
        # due to the described above scheme. On the other hand, when we have to get a "backward"
        # edge for a backward edge (i.e. get a forward edge for backward - id is odd), id - 1
        # should be taken.
        #
        # It turns out that id ^ 1 works for both cases. Think this through!
        self.edges[id].flow += flow
        self.edges[id ^ 1].flow -= flow # 异或

    # def bfs(self, s, t, parent):
    #     visited = [0] * self.n
    #     queue = []







def max_flow(graph, from_, to):
    flow = 0
    # your code goes here
    return flow


if __name__ == '__main__':
    vertex_count, edge_count = map(int, input().split())
    g = FlowGraph(vertex_count, edge_count)
    g.read_data()
    print(g.graph)
    # graph = read_data()
    # print(max_flow(graph, 0, graph.size() - 1))

    # print(graph.graph)
    # for i in range(len(graph.edges)):
    #     print(graph.edges[i].u, graph.edges[i].v, graph.edges[i].capacity, graph.edges[i].flow)

# graph : [[0, 4], [1, 2, 11, 12], [5, 6, 10], [7, 8, 13], [3, 9]]
# edges :
# 0 1 2 0
# 1 0 0 0
# 1 4 5 0
# 4 1 0 0
# 0 2 6 0
# 2 0 0 0
# 2 3 2 0
# 3 2 0 0
# 3 4 1 0
# 4 3 0 0
# 2 1 3 0
# 1 2 0 0
# 1 3 1 0
# 3 1 0 0
