// Creation and Printing of Graph
// Creating graph using Adjaceny List
// #include <iostream>
// #include <unordered_map>
// #include <list>
// using namespace std;
// template <typename T>
// class graph
// {
// public:
//     unordered_map<T, list<T> > adj;

//     void AddEdge(T u, T v, bool direction)
//     {
//         // 0 -> Unidirected Graph
//         // 1 -> Directed Graph

//         // Creating a edge u with v
//         adj[u].push_back(v);

//         // Creating a edge v with u
//         if (direction == 0)
//         {
//             adj[v].push_back(u);
//         }
//     }

//     void Display()
//     {
//         for (auto i : adj)
//         {
//             cout << i.first << " -> ";
//             for (auto j : i.second)
//             {
//                 cout << j << ", ";
//             }
//             cout << endl;
//         }
//     }
// };
// int main()
// {
//     int n;
//     cout << "Enter number of nodes : ";
//     cin >> n;

//     int m;
//     cout << "Enter number of edges : ";
//     cin >> m;

//     graph<int> g;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;

//         g.AddEdge(u, v, 0);
//     }

//     g.Display();
//     return 0;
// }

// Creating Graph using Adjaceny Matrix
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > CreateGraph(int n, int m, vector<vector<int> > edges)
{
    vector<vector<int> > adj(n);

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
}
int main()
{
    /// n --> no of vertices
    /// m --> no of edges
    int n, m;
    cin >> n >> m;

    vector<vector<int> > edges(m, vector<int>(2)); /// isse hm ptaye ge ke  konsi egde kise se connect h
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> edges[i][j];
        }
    }

    vector<vector<int> > ans = CreateGraph(n, m, edges); // ye pta rha hh ke hm kin kin se connect h

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (auto j : ans[i])
        {
            cout << j << ",";
        }

        cout << endl;
    }

    return 0;
}
