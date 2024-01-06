#include <iostream>
#include <vector>

using namespace std;

enum {WHITE,GREY,BLACK};

class graph
{
    int V;
    vector<vector<int>> Adj;

public:
    graph(int e)
    {
        V=e;
        Adj.resize(V);
    }
    void addEdge(int u,int v)
    {
        Adj[u].push_back(v);
    }
    bool dfs(vector<int>& color,int s)
    {
        color[s] = GREY;

        for(auto adjacent:Adj[s])
        {
            if(color[adjacent] == GREY)
            {
                return true;
            }
            else if(color[adjacent]==WHITE)
            {
                int ans = dfs(color,adjacent);
                if(ans)
                    return ans;
            }
        }
        color[s]=BLACK;
        return false;
    }
};
int main()
{
    int v = 5;
    graph g(v);
    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.addEdge(2,1);
    g.addEdge(3,4);

    vector<int> color;
    color.resize(v,WHITE);

    int res=false;
    for(int i=0;i<v;i++)
    {
        if(color[i]==WHITE)
        {
            res = g.dfs(color,i);
            if(res)
                break;
        }
    }


    cout << "Is Cycle Detected =" << res << endl;
    return 0;
}
