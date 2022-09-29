#include <bits/stdc++.h>
using namespace std;

const int inf = 1e17;
const int ninf = -1e17;
struct custom {
	int from;
	int to;
	int weight;
};
 
int32_t main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<custom> edges;
	for(int i = 0; i < m; i++) {
		custom input;
		cin >> input.from >> input.to >> input.weight;
		input.weight *= -1;
		edges.push_back(input);
	}
	vector<int> dist(n+1, inf);
	dist[1] = 0;
	// bellman ford algo
	for(int i = 0; i < n; i++) {
		for(auto e : edges) {
			int u = e.from, v = e.to, w = e.weight;
			if(dist[u] == inf)
				continue;
			dist[v] = min(dist[v], dist[u]+w);
			dist[v] = max(dist[v], ninf);
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(auto e : edges) {
			int u = e.from, v = e.to, w = e.weight;
			if(dist[u] == inf)
				continue;
			dist[v] = max(dist[v], ninf);
			if(dist[v] > dist[u]+w)
				dist[v] = ninf;
		}
	}
	cout << '\n';
	if(dist[n] == ninf or dist[n] == inf) {
		cout << -1;
	} else {
		cout << -1*dist[n];
	}
	cout << '\n';
	return 0;
}