#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class graph
{
    int V;
    vector<vector<int>>Adj;
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
    bool cycleUsingBFS(vector<bool>& visited,int s)
    {
        queue<pair<int,int>> q;
        q.push({s,-1});

        while(!q.empty())
        {
            pair<int,int> p;
            p=q.front();
            q.pop();
            int node = p.first;
            int parent = p.second;
            cout << "pop from queue=" << node << "and parent=" << parent<< endl;

            if(visited[node] == false)
                visited[node] = true;

            for(auto adjacent:Adj[node])
            {
                cout << "Adjacent to node " << adjacent << endl;
                if(visited[adjacent]==false)
                {
                    q.push({adjacent,node});
                }
                else if(adjacent!=parent)
                {
                    cout << "A Cycle Found adjacent=" << adjacent << " Parent" <<  visited[adjacent] << endl;
                    return true;
                }
                else
                {
                    cout << "Adjacent " << adjacent << " paremt=" << node << endl;
                }
            }
        }

        return false;

    }
};

int main()
{
    int v=5;
    graph G(v);

    G.addEdge(0,1);
    G.addEdge(1,0);

    G.addEdge(1,2);
    G.addEdge(2,1);

    G.addEdge(2,3);
    G.addEdge(3,2);

    G.addEdge(3,1);
    G.addEdge(1,3);

    G.addEdge(2,4);
    G.addEdge(4,2);

    vector<bool> visited;
    visited.resize(v,false);

    bool ans = false;
    for(int i=0;i<v;i++)
    {
        if(visited[i]== false)
        {
            ans = G.cycleUsingBFS(visited,i);
            if(ans)
                break;
        }
    }

    cout << "Is Cycle Detetced =" << ans << endl;
    return 0;
}
