// Depth First Traversal In Graph
#include <iostream>
#include <unordered_map>
#include <list>
#include <set>
#include <vector>
using namespace std;
class graph
{
public:
    unordered_map<int, set<int> > Adj;

    void CreateGraph(int u, int v)
    {
        Adj[u].insert(v);
        Adj[v].insert(u);
    }

    void DFS(int node, unordered_map<int, bool> &visited, vector<int> &ans)
    {
        ans.push_back(node);
        visited[node] = true;

        for (auto i : Adj[node])
        {
            if (!visited[i])
            {
                DFS(i, visited, ans);
            }
        }
    }
};
int main()
{
    int n;
    cout << "Enter number of vertices : ";
    cin >> n;

    int m;
    cout << "Enter number of edges : ";
    cin >> m;

    graph g;
    for (int i = 0; i < m; i++)
    {
        int u;
        cin >> u;

        int v;
        cin >> v;

        g.CreateGraph(u, v);
    }

    unordered_map<int, bool> visited;
    vector<vector<int> > res;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> ans;
            g.DFS(i, visited, ans);
            res.push_back(ans);
        }
    }

    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}