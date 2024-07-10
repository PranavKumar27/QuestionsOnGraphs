#include <iostream>
#include <vector>

using namespace std;

class Graph
{
    int n;
    vector<vector<int>> Adj;
    public:
    Graph(int v)
    {
        n = v;
        Adj.resize(n);
    }
    void addEdge(int u,int v)
    {
        Adj[u].push_back(v);
    }
    bool IscycleUsingDFS(vector<bool>& visited,int s,int parent)
    {
        cout << "parent=" << parent << " s=" << s << endl;
        if(!visited[s])
        {
            visited[s]=true;
        }
        for(auto adjacent:Adj[s])
        {
            if(!visited[adjacent])
            {
                bool ans = IscycleUsingDFS(visited,adjacent,s);
                if(ans)
                    return ans;
            }
            else if(visited[adjacent]==true && parent!=adjacent)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    int n=6;
    Graph G(n);
    G.addEdge(1,2);
    G.addEdge(1,5);
    G.addEdge(2,1);
    G.addEdge(2,3);
    G.addEdge(2,5);
    G.addEdge(3,2);
    G.addEdge(3,4);
    G.addEdge(5,1);
    G.addEdge(4,3);
    G.addEdge(5,2);

    vector<bool> visited;
    visited.resize(n,false);
    bool res = false;
    for(int i=1;i<n;i++)
    {
        if(visited[i]==false)
        {
            res = G.IscycleUsingDFS(visited,i,-1);
            if(res)
                break;
        }
    }

    cout << "Is Cycle Found =" << res << endl;
    return 0;
}
