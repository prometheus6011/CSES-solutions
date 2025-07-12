### 11.1 - Graph Terminology
- a graph consists of nodes and edges
	- $n$ denotes the number of nodes in a graph
	- $m$ denotes the number of edges
- a path leads from node $a$ to node $b$ through edges of the graph
- the length of a path is the number of edges in it
- a path if a cycle if the first and last node is the same
- a path is simple if each node appears at most once in the path
- Connectivity
	- a graph is connected if there is a path between any two nodes
	- the connected parts of graphs are called its components
	- a tree if a connected graph that consists of $n$ nodes and $n-1$ edges
- Edge Directions
	- a graph is directed if the edges can be traversed in one direction only
- Edge Weights
	- in a weighted graph, each edge is assigned a weight, often interpreted as edge lengths
- Neighbors and Degrees
	- two nodes are neighbors or adjacent if there is an edge between them
	- the degree of a node is the number of its neighbors
	- a graph is regular if the degree of every node is a constant $d$
	- a graph is complete if the degree of every node is $n-1$
	- in a directed graph, the in-degree of a node is the number of edges that end at the node, and the out-degree of a node is the number of edges that start at the node
- Colorings
	- each node is assigned a color so that no adjacent nodes have the same color
	- a graph is bipartite if it is possible to color it using two colors
- Simplicity
	- a graph is simple if no edge starts and ends at the same node, and there are no multiple edges between two nodes
### 11.2 - Graph Representations
- the choice of a data structure depends on the size of the graph and the way the algorithm processes it
- Adjacency List Representation
	- each node $x$ in the graph is assigned an adjacency list that consists of nodes to which there is an edge from $x$
	- if the graph is undirected, it can be stored in a similar way, but each edge is added in both directions
	- for a weighted graph, the structure needs to be extended
![[Screenshot 2025-07-12 at 3.25.32 PM.png]]
```cpp
vector<int> adj[N];   // unweighted graph representation

adj[1].push_back(2);
adj[2].push_back(3);
adj[2].push_back(4);
adj[3].push_back(4);
adj[4].push_back(1);

vector<pair<int, int> > adj[N];  // weighted graph representation

adj[1].push_back({2,5}); 
adj[2].push_back({3,7}); 
adj[2].push_back({4,6}); 
adj[3].push_back({4,5}); 
adj[4].push_back({1,2});

// efficiently find nodes to which we can move from a given node through an edge
for (auto u : adj[s]) {
	// process node u
}
```
- Adjacency Matrix Representations
	- two dimensional array that indicates which edges the graph contains, where each value indicates whether the graph contains an edge from node $a$ to node $b$
	- representations of this type contains $n^2$ elements, and usually most of them are zero, cannot be used if the graph is large
```cpp
int adj[N][N];
```
- Edge List Representations
	- an edge list contains all edges of a graph in some order
	- if the algorithm processes all edges of the graph and it is not needed to find edges that start at a given node
```cpp
vector<pair<int, int> > edges;

edges.push_back({1,2}); 
edges.push_back({2,3}); 
edges.push_back({2,4}); 
edges.push_back({3,4}); 
edges.push_back({4,1});
```

