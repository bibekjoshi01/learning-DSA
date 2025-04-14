class Graph:
    """Representing the graph using adjacency matrix"""

    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.adj_matrix = [[0] * (num_vertices) for _ in range(num_vertices)]

    def add_edge(self, from_vertex, to_vertex, weight=1):
        self.adj_matrix[from_vertex - 1][to_vertex - 1] = weight

    def display_matrix(self):
        for row in self.adj_matrix:
            print(row)


graph = Graph(4)
graph.add_edge(1, 2)
graph.add_edge(1, 3)
graph.add_edge(1, 4)

graph.display_matrix()
