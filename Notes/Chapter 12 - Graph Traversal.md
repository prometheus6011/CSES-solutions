### 12.1 - Depth-first search
- begins at a starting node, and proceeds to all other nodes that are reachable from the starting node using the edges of the graph
```cpp
vector<int> adj[N];
bool visitied[N];

void dfs(int s) {
	if (visited[s]) return;
	visited[s] = true;
	// process node s
	for (auto u : adj[s]) {
		dfs(u);
	}
}
```
### 12.2 - Breadth-first search
- visits the nodes in increasing order of their distance from the starting node
```cpp
queue<int> q;
bool visited[N];
int distance[N];
visited[x] = true;
distance[x] = 0;
q.push(x);
while (!q.empty()) {
	int s = q.front(); q.pop();
	// process node s
	for (auto u : adj[s]) {
		if (visited[u]) continue;
		visited[u] = true;
		distance[u] = distance[u] + 1;
		q.push(u);
	}
}
```