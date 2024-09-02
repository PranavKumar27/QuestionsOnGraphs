#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

#define INF INT_MAX

using namespace std;

void print_v(vector<int> V)
{
    for(auto d:V)
    {
        cout << d << "\t";
    }
    cout << endl;
}

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
    void bfs(int src,vector<int>& dist, vector<int>& path, int dest)
    {
        set<pair<int,int>> S;
        vector<int> parent;
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        S.insert({0,src});
        parent[src]=src;
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
                    parent[v]=u;
                }
            }
        }

        int dest_node = dest;
        while(parent[dest_node]!=dest_node)
        {
            path.push_back(dest_node);
            dest_node = parent[dest_node];
        }
        path.push_back(src);

        print_v(parent);

        reverse(path.begin(),path.end());
    }
};
int main()
{
    int n = 6;
    Graph G(n);

    G.addEdge(0,1,2);
    G.addEdge(1,0,2);

    G.addEdge(1,2,2);
    G.addEdge(1,4,1);

    G.addEdge(2,3,2);
    G.addEdge(2,1,2);

    G.addEdge(3,2,2);
    G.addEdge(3,4,4);
    G.addEdge(3,5,1);

    G.addEdge(4,1,1);
    G.addEdge(4,3,4);
    G.addEdge(4,5,1);

    G.addEdge(5,3,1);
    G.addEdge(5,4,1);

    vector<int> dist;
    dist.resize(n,INF);

    int src = 1;
    int dest = 3;
    vector<int> path;
    G.bfs(src,dist,path,dest);

    cout << "Shortest Path using Dijakstra Algo From src Using Set =" << src << endl;
    print_v(dist);

    cout << "Shortest Path using Dijakstra Algo From src Using Set =" << src  << "  to destination dest =" << dest << endl;

    print_v(path);

    cout << "Cost of the Path from src = " << src << " to dest=" << dest << "::" << dist[dest] << endl;

    return 0;
}

