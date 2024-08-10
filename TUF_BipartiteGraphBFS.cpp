// A graph which can be coloured using two colors in Alternate Sequence.
// Odd number of nodes in a cycle are Non-bipartite Graph
// Even number of nodes in a cycle create a Bipartite Graph

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
    bool bfs(vector<int>& C,int s)
    {
        cout << "S=" << s << endl;
        queue<int> q;
        q.push(s);
        C[s] = Yellow;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            int currentColor = C[node];
            int alternateColor = ( currentColor == Yellow )?Green:Yellow;

            for(auto adjacent:Adj[node])
            {
                if(C[adjacent] == Blank)
                {
                    q.push(adjacent);
                    C[adjacent] = alternateColor;
                }
                else if(C[adjacent]==currentColor)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    int n = 9;
    Graph G(n);
    G.addEdge(1,2);
    G.addEdge(2,1);
    G.addEdge(2,3);
    G.addEdge(2,7);
    G.addEdge(3,2);
    G.addEdge(3,4);
    G.addEdge(4,3);
    G.addEdge(4,5);
    G.addEdge(4,8);
    G.addEdge(5,4);
    G.addEdge(5,6);
    G.addEdge(6,7);
    G.addEdge(6,5);
    G.addEdge(7,2);
    G.addEdge(7,6);
    G.addEdge(8,4);

    bool ans = false;
    vector<int> C(n,Blank);
    // starting node for bfs
    for(int i=1;i<n;i++)
    {
        vector<int> C(n,Blank);
        ans = G.bfs(C,i);
        if(ans)
            break;
    }


    cout << "Is Graph Bipartite = " << ans << endl;
    return 0;
}
