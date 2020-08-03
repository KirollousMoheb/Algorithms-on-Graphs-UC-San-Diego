#include <iostream>
#include <vector>
using namespace std;

void Explore(int x,vector<vector<int> >& adj, vector<int>& visited )
{
	visited[x] = 1;
	for (int w: adj[x])
	{
		if (visited[w] == 0) 
			Explore(w,adj, visited);
	}

}

int reach(vector<vector<int> >& adj, int x, int y) {

	vector<int> visited(adj.size());
	Explore(x,adj, visited);
	return visited[y];


}

int main() {
	size_t n, m;
	cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	int x, y;
	cin >> x >> y;
	cout << reach(adj, x - 1, y - 1) << std::endl;
}
//4 2
//1 2
//3 2