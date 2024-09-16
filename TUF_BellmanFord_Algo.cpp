#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

#define INF INT_MAX

void print_v(vector<int> dist)
{
    cout << " {\t" ;
    for(auto d:dist)
    {
        if(d==INF)
            cout << setw(5) << "INF" << ",\t";
        else
            cout << setw(5) <<  d << ",\t";
    }
    cout << " }" << endl;
}

class Graph
{
    int node;
    vector<vector<pair<int,int>>> Adj;
    vector<pair<int,pair<int,int>>> EdgeList;

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
        EdgeList.push_back({u,{v,wt}});
    }
    bool bellmanFordAlgoIsNegCycle(vector<int>& dist,int src) // If neg cycle Return true else false
    {
        bool IsNegCycle = false;
        int NoOfPasses = node-1;
        for(int i=0;i<NoOfPasses;i++)
        {
            cout << "Pass = " << i << endl;
            print_v(dist);
            for(auto edge:EdgeList)
            {
                int u = edge.first;
                int v = edge.second.first;
                int wt = edge.second.second;

                if(dist[u]!=INF && dist[u]+wt<dist[v])
                {
                    dist[v]=dist[u]+wt;
                }
            }
        }

        // Nth Pass
        for(auto edge:EdgeList)
        {
            int u = edge.first;
            int v = edge.second.first;
            int wt = edge.second.second;

            if(dist[u]!=INF && dist[u]+wt<dist[v])
            {
                IsNegCycle = true;
                dist[v]=dist[u]+wt;
            }
        }
        cout << "Pass = " << node-1 << endl;
        print_v(dist);
        return IsNegCycle;
    }
};



int main()
{
    int n = 6;
    Graph G(n);

    G.addEdge(3,2,6);
    G.addEdge(5,3,1);
    G.addEdge(0,1,5);
    G.addEdge(1,5,-3);
    G.addEdge(1,2,-2);
    G.addEdge(3,4,-2);
    G.addEdge(2,4,3);

    vector<int> dist(n,INF);
    int src = 0;
    dist[src] = 0;
    bool IsNegCycle = false;
    IsNegCycle = G.bellmanFordAlgoIsNegCycle(dist,src);

    cout << "IsNegative Cycle =" << IsNegCycle << endl;

    print_v(dist);

    return 0;
}
