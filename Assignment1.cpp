#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
public:
    void printGraph(vector<int> graph[], int n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " -> ";
            for (int j = 0; j < graph[i].size(); j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void bfs(int V, vector<int> graph[], int start, int visited_bfs[])
    {
        visited_bfs[start] = 1;
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int x = q.front();
            cout << x << " ";
            q.pop();
            for (int i = 0; i < graph[x].size(); i++)
            {
                if (!visited_bfs[graph[x][i]])
                {
                    visited_bfs[graph[x][i]] = 1;
                    q.push(graph[x][i]);
                }
            }
        }
    }

    void dfs(vector<int> graph[], int visited_dfs[], int v)
    {
        visited_dfs[v] = 1;
        cout << v << " ";
        for (auto &i : graph[v])
        {
            if (!visited_dfs[i])
            {
                dfs(graph, visited_dfs, i);
            }
        }
    }
};

int main()
{
    int n;
    cout << "Enter the Number of Vertices: ";
    cin >> n;
    int e;
    cout << "Enter the Number of Edges: ";
    cin >> e;
    vector<int> graph[n + 1];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cout << "Enter source for Edge " << i + 1 << ": ";
        cin >> u;
        cout << "Enter destination for Edge " << i + 1 << ": ";
        cin >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    Graph g;
    int ch;
    bool loop = true;
    while (loop)
    {
        int visited_bfs[n + 1] = {0};
        int visited_dfs[n + 1] = {0};
        cout << "\n";
        cout << "1. Display Graph \n";
        cout << "2. Breadth First Search \n";
        cout << "3. Depth First Search \n";
        cout << "0. Exit \n";
        cout << "\nEnter your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Adjacency List Representation of the Graph: \n";
            g.printGraph(graph, n);
            break;

        case 2:
            cout << "BFS Traversal of Graph: ";
            for (int i = 1; i < n + 1; i++)
            {
                if (!visited_bfs[i])
                {
                    g.bfs(n + 1, graph, i, visited_bfs);
                }
            }
            break;

        case 3:
            cout << "\nDFS Traversal of Graph: ";
            for (int i = 1; i < n + 1; i++)
            {
                if (!visited_dfs[i])
                {
                    g.dfs(graph, visited_dfs, i);
                }
            }
            break;

        case 0:
            cout << "Thank You!";
            loop = false;
            break;

        default:
            break;
        }
    }
    return 0;
}