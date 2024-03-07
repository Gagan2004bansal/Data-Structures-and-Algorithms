#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;
class graph
{
public:
    unordered_map<int, set<int> > Adj; // Using Set can help us to give answer in Sorted Order

    void CreateGraph(int u, int v)
    {
        Adj[u].insert(v);
        Adj[v].insert(u);
    }

    void DFS(int node, vector<int> &ans, unordered_map<int, bool> &visited)
    {

        ans.push_back(node);
        visited[node] = true;

        for (auto i : Adj[node])
        {
            if (!visited[i])
            {
                DFS(i, ans, visited);
            }
        }
    }

    void BFS(int node, vector<int> &ans, unordered_map<int, bool> &visited)
    {

        queue<int> q;
        q.push(node);

        visited[node] = true;

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            ans.push_back(temp);

            for (auto i : Adj[temp])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};
int main()
{

    int n;
    cout << "Enter the number of vertices : ";
    cin >> n;

    int m;
    cout << "Enter the number of edges : ";
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

    vector<vector<int> > res;
    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> ans;
            g.DFS(i, ans, visited);
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

    vector<int> ans;
    unordered_map<int, bool> visited1;

    for (int i = 0; i < n; i++)
    {
        if (!visited1[i])
        {
            g.BFS(i, ans, visited1);
        }
    }

    for (auto j : ans)
    {
        cout << j << " ";
    }
    cout << endl;

    return 0;
}