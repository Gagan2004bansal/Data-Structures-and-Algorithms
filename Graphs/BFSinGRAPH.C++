// Breadth First Traversal In Graph
#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <vector>
using namespace std;
class graph
{
public:
    unordered_map<int, list<int> > adjList;

    void createGraph(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void Display()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    void bfsTraversal(vector<int> &ans, unordered_map<int, bool> &visited, int node)
    {
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for (auto i : adjList[frontNode])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = 1;
                }
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

        g.createGraph(u, v);
    }

    // g.Display();

    vector<int> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.bfsTraversal(ans, visited, i);
        }
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

// If we want to print the answer in sorted Order use set in change of list
