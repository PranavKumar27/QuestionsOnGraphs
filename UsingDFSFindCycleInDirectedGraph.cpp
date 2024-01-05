#include <iostream>
#include <vector>

using namespace std;

class graph
{
    int V;
    vector<vector<int>>Adj;
public:
    graph(int e)
    {
        V = e;
        Adj.resize(V);
    }
    void addEdge(int u, int v)
    {
        Adj[u].push_back(v);
    }
    bool dfsInDirectedGraph(vector<bool>& visited,vector<bool>& dfsVisited,int s)
    {
        cout << __FUNCTION__ << "\t s=" << s << endl;
        visited[s] = true;
        dfsVisited[s] = true;

        for(auto adjacent:Adj[s])
        {
            cout << "Node adjacent =" << adjacent << endl;
            if(visited[adjacent] == false)
            {
                int ans = dfsInDirectedGraph(visited,dfsVisited,adjacent);
                cout << "ans 1=" << ans << endl;
                if(ans)
                    return ans;
                else
                    break;
            }
            else if(visited[adjacent] == true &&
                    dfsVisited[adjacent] == true)
            {
                cout << "Node adjacent =" << adjacent << endl;
                cout << "ans 2=" << true << endl;
                return true;
            }
        }
        dfsVisited[s] = false;
        cout  << "Resetting dfsVisited[s] s=" << s << " dfsVisited[s]=" << dfsVisited[s] << endl;
        return false;
    }
};

int main()
{
    int v = 8;
    graph g(v);

    g.addEdge(0,1);

    g.addEdge(2,1);
    g.addEdge(2,3);

    g.addEdge(4,1);
    g.addEdge(4,3);

    g.addEdge(5,0);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(7,5);

    vector<bool> visisted;
    visisted.resize(v,false);

    vector<bool> dfsVisited;
    dfsVisited.resize(v,false);

    bool res = false;
    for(int x=0;x<v;x++)
    {
        cout << "x=" << x << endl;
        if(!visisted[x])
        {
            cout  << " dfsVisited = " << dfsVisited[x] << endl;
            cout  << " dfsVisited 0 = " << dfsVisited[0] << endl;
            res = g.dfsInDirectedGraph(visisted,dfsVisited,x);
            cout <<  "res=" << res << endl;
        }
        if(res)
            break;
    }

    for(auto y: dfsVisited)
        cout  << " dfsVisited = " << y << endl;
    cout << "Is Cycle Present = " << res << endl;

    return 0;
}
