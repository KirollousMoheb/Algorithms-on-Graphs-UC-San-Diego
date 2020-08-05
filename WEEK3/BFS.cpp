#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int distance(vector<vector<int> >& adj, int s, int t) {
    vector<int>dist(adj.size());
    for (int i = 0; i < adj.size(); i++)
    {
        dist[i] = INT_MAX;
    }
    dist[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int v : adj[u])
        {
            if (dist[v]==INT_MAX)
            {
                Q.push(v);
                dist[v] = dist[u] + 1;

            }
        }
    }
    if (dist[t]==INT_MAX)
    {
        return -1;
    }
    else
    {
        return dist[t];
    }
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
    int s, t;
    cin >> s >> t;
    s--, t--;
    cout << distance(adj, s, t);
}
