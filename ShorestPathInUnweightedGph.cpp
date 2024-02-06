#include <iostream>
#include <queue>
#include <climits>
#include <vector>

#define INF INT_MAX
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> Adj;
public:
    Graph(int v)
    {
        V=v;
        Adj.resize(V);
    }
    void addEdge(int u,int v)
    {
        Adj[u].push_back(v);
    }
    int findShortestDistance(int src,int dest)
    {
        queue<pair<int,int>> q;
        vector<int> dist;
        dist.resize(V,INF);
        dist[src] = 0;
        q.push({src,dist[src]});

        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            int u = p.first;
            int wt = p.second;
            if(u==dest)
                break;
            for(auto v:Adj[u])
            {
                dist[v] = min(dist[v],wt+1);
                q.push({v,dist[v]});

            }

        }
        cout << "Distances Calculated:\t";
        for(auto d:dist)
            cout << d << "\t";
        cout << endl;
        return dist[dest];

    }
};
int main()
{
    Graph g(8);

    g.addEdge(0,1);
    g.addEdge(0,3);

    g.addEdge(1,0);
    g.addEdge(1,2);

    g.addEdge(3,0);
    g.addEdge(3,4);
    g.addEdge(3,7);

    g.addEdge(4,3);
    g.addEdge(4,5);
    g.addEdge(4,6);
    g.addEdge(4,7);

    g.addEdge(5,4);
    g.addEdge(5,6);

    g.addEdge(6,4);
    g.addEdge(6,5);
    g.addEdge(6,7);

    g.addEdge(7,3);
    g.addEdge(7,4);
    g.addEdge(7,6);

    int res = g.findShortestDistance(0,7);
    cout << "Shorest distance =" << res << endl;
    return 0;
}
