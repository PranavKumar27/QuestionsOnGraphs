#include <iostream>
#include <vector>
#include <queue>

enum Colors{Blank =-1,Yellow=0,Green=1};

using namespace std;

class Graph
{
    int n;
    vector<vector<int>> Adj;
public:
    Graph(){}
    Graph(int nodes)
    {
        n = nodes;
        Adj.resize(n);
    }
    void addEdge(int u,int v)
    {
        Adj[u].push_back(v);
    }
    void print_Adj()
    {
        for(auto row:Adj)
        {
            for(auto col:row)
            {
                cout << col << "\t,";
            }
            cout << endl;
        }
    }
    bool dfs(vector<int>& C,int src)
    {
        int alternateColor = (C[src] == Yellow)?Green:Yellow;

        for(auto adjacent:Adj[src])
        {
            if(C[adjacent]==Blank)
            {
                C[adjacent] = alternateColor;
                dfs(C,adjacent);
            }
            else if(C[adjacent]==C[src])
            {
                return true;
            }
        }
        return false;
    }

};
int main()
{
    int n = 7;
    Graph G(n);
    G.addEdge(0,1);
    G.addEdge(1,0);
    G.addEdge(1,2);
    G.addEdge(1,5);
    G.addEdge(2,1);
    G.addEdge(2,3);
    G.addEdge(3,2);
    G.addEdge(3,4);
    G.addEdge(3,6);
    G.addEdge(4,3);
    G.addEdge(4,5);
    G.addEdge(5,1);
    G.addEdge(5,4);

    bool ans = false;
    vector<int> C(n,Blank);
    // starting node for dfs
    for(int i=0;i<n;i++)
    {
        vector<int> C(n,Blank);
        C[i]=Yellow;
        ans = G.dfs(C,i);
        if(ans)
            break;
    }


    cout << "Is Graph Bipartite = " << ans << endl;
    return 0;
}
