#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

#define INF INT_MAX

using namespace std;

class Graph
{
    int u,v,wt;
    int n;
    vector<vector<pair<int,int>>> Adj;

public:
    Graph(){}
    Graph(int n)
    {
        this->n = n;
        Adj.resize(n);
    }
    void addEdge(int u,int v,int wt)
    {
        Adj[u].push_back({v,wt});
    }
    void bfs(int src,vector<int>& dist)
    {
        set<pair<int,int>> S;
        S.insert({0,src});
        dist[src]=0;

        while(!S.empty())
        {
            auto itr = S.begin();
            pair<int,int> p = *itr;
            S.erase(p);
            int wt = p.first;
            int u = p.second;

            for(auto adjacent:Adj[u])
            {
                int v = adjacent.first;
                int weight = adjacent.second;

                if( wt!=INF && dist[v]>wt+weight )
                {
                    if(dist[v]!=INF )
                    {
                        /// There is an existing Entry in the 
                        /// Set S and we need to get rid of it
                        S.erase({dist[v],v});
                    }
                    dist[v]=wt+weight;
                    S.insert({dist[v],v});
                }
            }
        }
    }
};
int main()
{
    int n = 6;
    Graph G(n);
    G.addEdge(0,1,4);
    G.addEdge(0,2,4);
    G.addEdge(1,0,4);
    G.addEdge(1,2,2);
    G.addEdge(2,0,4);
    G.addEdge(2,1,2);
    G.addEdge(2,3,3);
    G.addEdge(2,4,1);
    G.addEdge(3,2,3);
    G.addEdge(3,5,2);
    G.addEdge(4,2,1);
    G.addEdge(4,5,3);
    G.addEdge(5,3,2);
    G.addEdge(5,4,3);

    vector<int> dist;
    dist.resize(n,INF);

    int src = 0;
    G.bfs(src,dist);

    cout << "Shortest Path using Dijakstra Algo From src Using Set =" << src << endl;
    for(auto d:dist)
    {
        cout << d << "\t";
    }
    cout << endl;

    return 0;
}
