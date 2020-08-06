#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;
long long int distance(vector <vector<int> >& adj, vector<vector<int> >& cost, int s, int t) {
    vector<long long int> dist(adj.size(), INT_MAX);
    dist[s] = 0;
    auto cmp = [](pair<int, long long int> left, pair<int, long long int> right) { return (((left.second) > (right.second)) || (((left.second) == (right.second)) && ((left.first) > (right.first)))); };
    priority_queue<pair<int, long long int>,vector<pair<int, long long int>>, decltype(cmp)> Q(cmp);
    Q.push(make_pair(s, dist[s]));
    while (!Q.empty())
    {
        int u=Q.top().first;

        Q.pop();
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (dist[adj[u][i]]>dist[u]+cost[u][i])
            {
                dist[adj[u][i]] = dist[u] + cost[u][i];
                Q.push(make_pair(adj[u][i], dist[adj[u][i]]));
            }
        }

    }
    if (dist[t]<INT_MAX)
    {
        return dist[t];
    }
    else
    {
        return -1;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    int s, t;
    cin >> s >> t;
    s--, t--;
    cout << distance(adj, cost, s, t);
}
