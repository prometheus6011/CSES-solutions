### 13.1 - Bellman-Ford algorithm
- can process all kinds of graphs, provided that the graph does not contain a cycle with negative length
- the algorithm keeps track of distances from the starting node to all nodes of the graph
- initially the distance to the starting node is 0 and the distance to all other nodes is infinite
- Implementation
	- determines the shortest distances from a node $x$ to all nodes of the graph
	- consists of $n - 1$ rounds, and on each round the algorithm goes through all edges of the graph and tries to reduce the distances
	- constructs an array distance  that will contain the distances from $x$ to all nodes of the graph
	- time complexity is $O(nm)$
```cpp
for (int i = 1; i <= n; ++i) distance[i] = INF;
distance[x] = 0;
for (int i = 1; i <= n - 1; ++i) {
	for (auto e : edges) {
		int a, b, w;
		tie(a, b, w) = e;
		distance[b] = min(distance[b], distance[a] + w);
	}
}
```
- Negative Cycles
	- if the graph contains a negative cycle, we can shorten infinitely many times any path that contains the cycle by repeating the cycle again and again
- SPFA algorithm
	- shortest path faster algorithm is a variant of Bellman-Ford
	- algorithm maintains a queue of nodes that might be used for reducing the distances
### 13.2 - Dijkstra's algorithm
- finds shortest paths from the starting node to all nodes of the graph
- requires there to be no negative weight edges in the graph
- Implementation
	- distance stores the distance to each node
	- q is a priority queue data structure that contains pairs of the form $(-d, x)$, meaning that the current distance to node $x$ is $d$
	- the time complexity is $O(n + mlog(m))$
```cpp
for (int i = 1; i <= n; ++i) distance[i] = INF;
distance[x] = 0;
q.push({0, x});
while (!q.empty()) {
	int a = q.top().second;
	q.pop();
	if (processed[a]) continue;
	processed[a] = true;
	for (auto u : adj[a]) {
		int b = u.first, w = u.second;
		if (distance[a] + w < distance[b]) {
			distance[b] = distance[a] + w;
			q.push({-distance[b], b});
		}
	}
}
```
### 13.3 - Floyd-Warshall algorithm
- provides an alternative way to approach the problem of finding shortest poaths
- 