#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;
#define INF INT_MAX

class Graph
{
    int node;
    vector<vector<pair<int,int>>> Adj;
public:
    Graph(){}
    Graph(int n)
    {
        node = n;
        Adj.resize(node);
    }
    void addEdge(int u,int v,int wt)
    {
        Adj[u].push_back({v,wt});
    }
    int bfs(int src,int dest)
    {
        vector<int> dist(node,INF);
        dist[src] = 0;
        vector<int> paths(node,0);
        paths[src] = 1;
        set<pair<int,int>> S;
        S.insert({dist[src],src});
        while(!S.empty())
        {
            auto itr = *(S.begin());
            S.erase(itr);
            int wt = itr.first;
            int u = itr.second;
            int p = paths[u];

            cout << "Popped from Set:\t{" << wt << "," << u << "," << p << "}"<< endl;

            for(auto adj:Adj[u])
            {
                int v = adj.first;
                int weight = adj.second;

                if(dist[v]>=weight+wt)
                {
                    if(dist[v]!=INF)
                    {
                        S.erase({dist[v],v});
                    }
                    dist[v]=weight+wt;
                    paths[v]=paths[v]+p;
                    S.insert({dist[v],v});
                }
            }
        }

        cout << "Dist::\t" ;
        for(auto d:dist)
        {
            cout << d << "\t";
        }
        cout << endl;

        cout << "Paths::\t" ;
        for(auto d:paths)
        {
            cout << d << "\t";
        }
        cout << endl;
        return paths[dest];
    }
};

int main()
{
    int n = 9;
    Graph G(n);
    G.addEdge(0,1,1);
    G.addEdge(0,2,2);
    G.addEdge(0,3,1);
    G.addEdge(0,4,2);

    G.addEdge(1,0,1);
    G.addEdge(1,5,2);

    G.addEdge(2,0,2);
    G.addEdge(2,5,1);

    G.addEdge(3,5,2);
    G.addEdge(3,7,3);
    G.addEdge(3,6,2);

    G.addEdge(4,0,2);
    G.addEdge(4,6,1);

    G.addEdge(5,1,2);
    G.addEdge(5,2,1);
    G.addEdge(5,3,2);
    G.addEdge(5,8,1);

    G.addEdge(6,4,1);
    G.addEdge(6,3,2);
    G.addEdge(6,8,1);

    G.addEdge(7,3,3);
    G.addEdge(7,8,1);

    G.addEdge(8,5,1);
    G.addEdge(8,7,1);
    G.addEdge(8,6,1);

    int src = 0;
    int dest = 8;
    int NoOfpaths = G.bfs(src,dest);

    cout << "Number of Shortest Paths possible from src = " << src << " to dest = " << dest << " Total Possible Paths =" << NoOfpaths << endl;
    return 0;
}
