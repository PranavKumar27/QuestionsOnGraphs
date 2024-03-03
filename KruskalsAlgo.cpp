#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int Num0 = 0;
const int Num1 = 1;
const int Num2 = 2;

// DSU = DisjointSetUnion
class DSU
{
    vector<int> rank;
    vector<int> parent;

    public:
    DSU(int V)
    {
        rank.resize(V,Num0);
        // Initialize Parents
        for(int i=0;i<V;i++)
        {
            parent.push_back(i);
        }
    }

    int findParent(int child)
    {
        if(child == parent[child])
        {
            return child;
        }
        else
        {
            parent[child] = findParent(parent[child]);
        }      
    }

    void unionOfNode(int u,int v)
    {
        int ultimate_parent_u = findParent(u);
        int ultimate_parent_v = findParent(v);

        int rank_u = rank[ultimate_parent_u];
        int rank_v = rank[ultimate_parent_v];

        if(ultimate_parent_u!=ultimate_parent_v)
        {
            if(rank_u > rank_v)
            {
                parent[v] = ultimate_parent_u;
            }
            else if(rank_v > rank_u)
            {
                parent[u] = ultimate_parent_v;
            }
            else
            {
                parent[v] = ultimate_parent_u; // Attaching v to u
                rank[u]+=1;
            }
        }
        
    }
};

class Graph
{
    int V;
    vector<vector<int>> EdgeList;

    public:
    Graph(int v)
    {
        V=v;
        //EdgeList.resize(V);
    }
    void addEdge(int u,int v,int wt)
    {
        EdgeList.push_back({wt,u,v});
    }
    int kruskalsAlgo()
    {
        DSU S(V);
        vector<pair<int,int>> MstList;
        sort(EdgeList.begin(),EdgeList.end());
        int ans = 0;
        int wt,u,v;
        for(auto edges:EdgeList)
        {
            int wt = edges[0];
            int u = edges[1];
            int v = edges[2]; 
            
            cout << "wt=" << wt << " u=" << u << " v=" << v << endl;

            int parent_u = S.findParent(u);
            int parent_v = S.findParent(v);

            cout << "parent of u =" << parent_u << " parent of v=" << parent_v << endl;
            if(parent_u != parent_v) // No cycle Found
            {
                cout << "No Cyle Found for  u=" << u << " v=" << v << endl;
                S.unionOfNode(u,v);
                MstList.push_back({u,v});
                ans = ans+wt;
            }
            else
            {
                cout << "Cycle Found" << endl;
            }
        }
        // print MST
        cout << "Cost of Minimum Spanning Tree : " << ans << endl;
        cout << "Edges in Minimum Spanning Tree: " << endl;
        for(auto edge:MstList)
        {
            // pair<int,int> p = edge;
            cout << "\t" << edge.first << "------\t" << edge.second << endl; 
        }
        return ans;
    }
};

int main()
{
    Graph G(4);
    G.addEdge(0,1,10);
    G.addEdge(1,3,15);
    G.addEdge(2,3,4);
    G.addEdge(2,0,6);
    G.addEdge(0,3,5);

    int res = G.kruskalsAlgo();

    cout << "Cost of Minimum Spanning Tree =" << res << endl;
    return 0;
}
