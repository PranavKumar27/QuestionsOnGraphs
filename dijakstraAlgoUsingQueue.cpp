#include <iostream>
#include <vector>
#include <queue>
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
        priority_queue<par,vector<par>,greater<par> > q; // pair = wt,node  / Min Heap Priority Queue
        q.push({0,s});
        dist[s]=0;

        while(!q.empty())
        {
            pair<int,int> p = q.top();
            q.pop();
            int weight = p.first;
            int node = p.second;
            cout << "\tweight=" << weight << " node=" << node << endl;

            for(auto it:Adj[node])
            {
                int v = it.first;
                int wt = it.second;
                if(dist[v]>weight+wt)
                {
                    dist[v] = weight+wt;
                    q.push({dist[v],v});
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
