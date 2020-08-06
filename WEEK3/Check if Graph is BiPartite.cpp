#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int bipartite(vector<vector<int> >& adj) {
    vector<int>color(adj.size());
    vector<int>visited(adj.size());

    for (int i = 0; i < adj.size(); i++)
    {
        color[i] = INT_MAX;
        visited[i] = INT_MAX;

    }
    color[0] = 0;
    queue<int> Q;
    Q.push(0);
    visited[u] = 1;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int v : adj[u])
        {
            if (visited[v] == INT_MAX)
            {
                Q.push(v);
                color[v] =1- color[u] ;

            }
            if (color[v]==color[u])
            {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    cout << bipartite(adj);
}
