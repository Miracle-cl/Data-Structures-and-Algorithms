# python3
import numpy as np

# Good job! (Max time used: 0.21/5.00, max memory used: 17842176/536870912.)
# https://www.geeksforgeeks.org/maximum-bipartite-matching/

class MaxMatching:
    def read_data(self):
        n, m = map(int, input().split())
        adj_matrix = [list(map(int, input().split())) for i in range(n)]
        self.adj_matrix = np.array(adj_matrix).T # residual graph
        self.crew = m
        self.flight = n
        self.rr = [-1] * n

    def dfs(self, u, matching, used):
        """A DFS based recursive function that return 1 if a matching for vertex u is possible"""
        # try every flight one by one
        for v in range(self.flight):
            # if crew u can be in flight v and v is not used
            if self.adj_matrix[u][v] and not used[v]:
                # mark v as used
                used[v] = 1
                if matching[v] == -1 or self.dfs(matching[v], matching, used):
                    matching[v] = u
                    self.rr[v] = u
                    return 1
        return 0


    def find_matching(self):
        matching = [-1] * self.flight
        # result = 0
        for i in range(self.crew):
            used = [0] * self.flight
            self.dfs(i, matching, used)
            # if self.dfs(i, matching, used):
            #     result += 1
        # return result

    def write_response(self):
        line = [str(-1 if x == -1 else x + 1) for x in self.rr]
        print(' '.join(line))

    def solve(self):
        # adj_matrix = self.read_data()
        # matching = self.find_matching(adj_matrix)
        # self.write_response(matching)
        self.read_data()
        self.find_matching()
        self.write_response()


if __name__ == '__main__':
    max_matching = MaxMatching()
    max_matching.solve()
