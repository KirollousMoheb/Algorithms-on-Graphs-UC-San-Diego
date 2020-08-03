#include <iostream>
#include <vector>

using namespace std;
void Explore(int x, vector<vector<int> >& adj, vector<int>& visited)
{
	visited[x] = 1;
	for (int w : adj[x])
	{
		if (visited[w] == 0) {
			Explore(w, adj, visited);
		}
	}

}

int DFS(vector<vector<int> >& adj) {

	vector<int> visited(adj.size());
	int cc = 0;
	for (int i = 0; i < adj.size(); i++)
	{
		if (visited[i] == 0) {
			Explore(i, adj, visited);
			cc++;
		}

	}
	return cc;

}

int main() {
	size_t n, m;
	cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	for (size_t i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	cout << DFS(adj);
}
