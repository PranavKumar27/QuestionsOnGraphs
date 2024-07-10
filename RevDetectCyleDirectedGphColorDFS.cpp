#include <iostream>
#include <vector>

using namespace std;

enum COLOUR{WHITE,GREY,BLACK};
class Graph
{
    int node;
    vector<vector<int>> Adj;
public:
    Graph(int n)
    {
        node = n;
        Adj.resize(n);
    }
    void addEdge(int u,int v)
    {
        Adj[u].push_back(v);
    }
    bool IsCycleUsingDFSGraphColor(vector<COLOUR>& COLR,int s)
    {
        cout << "s=" << s << " COLR[s]=" << COLR[s] << endl;
        if(COLR[s]==WHITE)
            COLR[s] = GREY;
        cout << "s=" << s << " COLR[s]=" << COLR[s] << endl;

        for(auto adjacent:Adj[s])
        {
            cout << "adjacent=" << adjacent << " COLR[adjacent]=" << COLR[adjacent] << endl;
            if(COLR[adjacent]==WHITE)
            {
                cout << "Calling DFS" << endl;
                bool ans = IsCycleUsingDFSGraphColor(COLR,adjacent);
                if(ans)
                    return ans;
            }
            else if(COLR[adjacent]==GREY && COLR[s]== GREY)
            {
                return true;
            }
        }
        COLR[s]=BLACK;
        return false;
    }


};

int main()
{
    int n=6;
    Graph G(n);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(4,3);
    G.addEdge(5,2);

    vector<COLOUR> COLR;
    COLR.resize(n,WHITE);
    bool res = G.IsCycleUsingDFSGraphColor(COLR,1);
    if(res)
    {
        cout << "Cycle Exists =" << res << endl;
    }
    else
    {
        cout << "No Cycle Exists =" << res << endl;
    }

    return 0;
}
