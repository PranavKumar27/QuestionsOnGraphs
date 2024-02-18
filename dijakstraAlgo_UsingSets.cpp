#include <iostream>
#include <set>
#include <vector>
#include <limits.h>

using namespace std;

typedef pair<int,int> pairOfInt;

class Graph
{
    int V;
    vector<vector<pairOfInt>> Adj;
    public:
        Graph(int v)
        {
            V=v;
            Adj.resize(V);
        }
        void addEdge(int u,int v,int wt)
        {
            cout << __FUNCTION__ << endl;
            Adj[u].push_back({v,wt});
        }
        void dijasktra(vector<int>& dist,int s)
        {
            set<pairOfInt> St;
            St.insert({0,s});
            dist[s] = 0;
            while(!St.empty())
            {
                // top Value
                print_Set(St);
                pairOfInt p = *(St.begin());
                St.erase(p);
                int weight = p.first;
                int node = p.second;
                cout << "Popped Node =" << node << "\t Popped Node Wt=" << weight << endl;

                for( auto adjacent:Adj[node])
                {
                    int adjacentNode = adjacent.first;
                    int adjacentWt = adjacent.second;

                    cout << "adjacentNode =" << adjacentNode << "\t adjacentWt=" << adjacentWt << endl;

                    if(dist[adjacentNode]>adjacentWt+weight)
                    {
                        if(dist[adjacentNode]!=INT_MAX)
                        {
                            St.erase({dist[adjacentNode],adjacentNode}); // Update old Entry of same distance,Node
                        }
                        dist[adjacentNode] = adjacentWt+weight;
                        St.insert({dist[adjacentNode],adjacentNode});
                    }
                }
            }
        }
        void print_Set(set<pairOfInt> St)
        {
            cout << "----------" << endl;
            for(auto s:St)
            {
                cout << "{ " << s.first << " , " << s.second << " }" << endl;
            }
            cout << "----------" << endl;
        }
};

int main()
{
    int V=6;
    Graph G(V);

    G.addEdge(0,1,2);
    G.addEdge(0,2,3);
    G.addEdge(0,5,10);

    G.addEdge(1,0,2);
    G.addEdge(1,3,3);
    G.addEdge(1,2,4);

    G.addEdge(2,0,3);
    G.addEdge(2,1,4);
    G.addEdge(2,4,8);

    G.addEdge(3,1,3);
    G.addEdge(3,4,2);
    G.addEdge(3,5,5);

    G.addEdge(4,2,8);
    G.addEdge(4,3,2);
    G.addEdge(4,5,1);

    G.addEdge(5,0,10);
    G.addEdge(5,3,5);
    G.addEdge(5,4,1);

    vector<int> dist;
    dist.resize(V,INT_MAX);

    G.dijasktra(dist,0);

    for(auto d:dist)
    {
        cout << d << "\t";
    }
    cout << endl;
    return 0;

}
