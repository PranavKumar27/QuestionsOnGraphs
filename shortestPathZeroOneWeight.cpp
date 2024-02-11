#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#define INF INT_MAX

using namespace std;

typedef pair<int,int> _pair;

class Graph
{
    int V;
    vector<vector<pair<int,int>>> Adj;

public:
    Graph(int v)
    {
        V=v;
        Adj.resize(v);
    }
    void addEdge(int u,int v,int wt)
    {
        Adj[u].push_back({v,wt});
    }
    void findShortestPath(vector<int>& dist,int s)
    {
        priority_queue<_pair,vector<_pair>,greater<_pair>> dq;
        dist.resize(V,INF);
        dist[s]=0;
        dq.push({s,0});

        while(!dq.empty())
        {
            _pair p = dq.top();
            dq.pop();
            int wt_u = p.first;
            int u = p.second;
            for(auto adjacent:Adj[u])
            {
               int v = adjacent.first;
               int wt_v = adjacent.second;

               if(dist[v]>wt_u+wt_v)
               {
                    dist[v] = wt_u+wt_v;
                    dq.push({dist[v],v});
                }
            }
        }
    }
};

int main()
{
    Graph g(9);
    g.addEdge(0,1,0);
    g.addEdge(0,7,1);

    g.addEdge(1,0,0);
    g.addEdge(1,2,1);
    g.addEdge(1,7,1);

    g.addEdge(2,1,1);
    g.addEdge(2,3,0);
    g.addEdge(2,5,0);
    g.addEdge(2,8,1);


    g.addEdge(3,2,0);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);

    g.addEdge(4,3,1);
    g.addEdge(4,5,1);

    g.addEdge(5,2,0);
    g.addEdge(5,3,1);
    g.addEdge(5,4,1);

    g.addEdge(6,5,1);
    g.addEdge(6,7,1);

    g.addEdge(7,0,1);
    g.addEdge(7,6,1);
    g.addEdge(7,8,1);

    g.addEdge(8,2,1);
    g.addEdge(8,7,1);

    vector<int> dist;
    g.findShortestPath(dist,0);

    cout << "Shortest Path=\t";
    for(auto x:dist)
    {
        cout << x << "\t";
    }

    cout << endl;
    return 0;
}
