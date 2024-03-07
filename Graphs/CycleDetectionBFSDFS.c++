// #include <iostream>
// #include <unordered_map>
// #include <queue>
// #include <list>
// using namespace std;
// class graph
// {
// public:
//     unordered_map<int, list<int> > Adj;

//     void CreateGraph(int u, int v)
//     {
//         Adj[u].push_back(v);
//         Adj[v].push_back(u);
//     }

//     bool CyclicDetection(int node, unordered_map<int, bool> &visited)
//     {
//         unordered_map<int, int> parent;
//         parent[node] = -1;
//         visited[node] = 1;
//         queue<int> q;
//         q.push(node);

//         while (!q.empty())
//         {
//             int temp = q.front();
//             q.pop();

//             for (auto neighbour : Adj[temp])
//             {
//                 if (visited[neighbour] == true && neighbour != parent[temp])
//                 {
//                     return true;
//                 }
//                 else if (!visited[neighbour])
//                 {
//                     q.push(neighbour);
//                     visited[neighbour] = true;
//                     parent[neighbour] = temp;
//                 }
//             }
//         }

//         return false;
//     }
// };
// int main()
// {
//     int n;
//     cin >> n;
//     int m;
//     cin >> m;

//     graph g;

//     for (int i = 0; i < m; i++)
//     {
//         int u;
//         cin >> u;

//         int v;
//         cin >> v;

//         g.CreateGraph(u, v);
//     }

//     unordered_map<int, bool> visited;
//     bool ans = false;
//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             ans = g.CyclicDetection(i, visited);
//             if (ans == true)
//             {
//                 cout << "CYCLIC" << endl;
//                 exit(0);
//             }
//         }
//     }

//     if (ans == false)
//     {
//         cout << "NON CYCLIC" << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
class graph
{
public:
    unordered_map<int, list<int> > Adj;

    void CreateGraph(int u, int v)
    {
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    bool CyclicDetection(int node, int parent, unordered_map<int, bool> &visited)
    {
        visited[node] = true;

        for (auto neighbour : Adj[node])
        {
            if (!visited[neighbour])
            {
                bool cycledetected = CyclicDetection(neighbour, node, visited);
                if (cycledetected)
                {
                    return true;
                }
            }
            else if (neighbour != parent)
            {
                return true;
            }
        }

        return false;
    }
};
int main()
{
    int n;
    cin >> n;

    int m;
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
    bool ans = false;
    int parent = -1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = g.CyclicDetection(i, parent, visited);
            if (ans == true)
            {
                cout << "CYCLIC" << endl;
                exit(0);
            }
        }
    }

    if (ans == false)
    {
        cout << "NON CYCLIC" << endl;
    }

    return 0;
}