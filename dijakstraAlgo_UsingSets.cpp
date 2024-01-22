#include <iostream>
#include <vector>
#include <set>
#include <limits.h>
#define INF INT_MAX

using namespace std;

typedef pair<int,int> par;
class Graph
{
    int V;
    vector<vector<pair<int,int>>> Adj;
    public:
    Graph(int v)
    {
        V=v;
        Adj.resize(V);
    }
    void addEdge(int u,int v,int wt)
    {
        Adj[u].push_back({v,wt});
    }
    // Shortest Path
    void dijakstraAlgo(vector<int>& dist,int s)
    {
        set<par> St; // pair = wt,node  / Min Heap Priority Queue
        St.insert({0,s});
        dist[s]=0;

        while(!St.empty())
        {
            auto it=*(St.begin());
            int weight = it.first;
            int node = it.second;
            cout << "\tweight=" << weight << " node=" << node << endl;
            St.erase(it);

            for(auto adjacent:Adj[node])
            {
                int adjNode = adjacent.first;
                int adjWeight = adjacent.second;
                if(dist[adjNode]>weight+adjWeight)
                {
                    if(dist[adjNode]!=INF)
                    {
                        St.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode] = weight+adjWeight;
                    St.insert({dist[adjNode],adjNode});
                }
            }


        }
    }
};

void print_v(vector<int> dist)
{
    for(auto x:dist)
        cout << x << "\t";

    cout << endl;
}
int main()
{
    int n = 6;
    Graph g(n);
    g.addEdge(0,1,4);
    g.addEdge(0,2,4);

    g.addEdge(2,0,4);
    g.addEdge(1,2,2);

    g.addEdge(2,0,4);
    g.addEdge(2,1,2);
    g.addEdge(2,3,3);
    g.addEdge(2,4,1);
    g.addEdge(2,5,6);

    g.addEdge(3,2,3);
    g.addEdge(3,5,2);

    g.addEdge(4,2,1);
    g.addEdge(4,5,3);

    g.addEdge(5,3,2);
    g.addEdge(5,2,6);
    g.addEdge(5,4,3);

    vector<int> dist;
    dist.resize(n,INF);

    g.dijakstraAlgo(dist,0);

    cout << "Shortest Path Traversal:\t";
    print_v(dist);


    return 0;
}
