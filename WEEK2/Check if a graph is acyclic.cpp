#include <iostream>
#include <vector>

using namespace std;
bool Explore(int x, vector<vector<int> >& adj,vector<int>& visited, vector<int>& record)
{
    visited[x] = 1;
    record[x] = 1;
    for (int w : adj[x])
    {
        if (visited[w] != 1 && Explore(w, adj, visited, record) == false) {
            return false;
        }
        else
        {
            if (record[w]==1)
            {
                return false;
            }
        }

    }
    record[x] = 0;
    return true;

}

int acyclic(vector<vector<int> >& adj) {
    vector<int> visited(adj.size());
    vector<int> record(adj.size());
    for (int i = 0; i < adj.size(); i++)
    {
        if (visited[i]==0)
        {
            if (Explore(i,adj,visited,record)==false)
            {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    size_t n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    cout << acyclic(adj);
}
