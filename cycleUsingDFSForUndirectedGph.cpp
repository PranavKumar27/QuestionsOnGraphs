#include <iostream>
#include <vector>

using namespace std;

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

    bool cycleUsingDFS(vector<bool>& visited,int s,int parent)
    {
        if(visited[s]==false)
        {
            visited[s]=true;
        }

        for(auto adjacent:Adj[s])
        {
            if(visited[adjacent]==false)
            {
                int ans = cycleUsingDFS(visited,adjacent,s);
                if(ans)
                    return ans;
            }
            else if(adjacent != parent)
            {
                cout  << "adjacent=" << adjacent << " \t parent=" << parent << endl;
                return true;
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

    G.addEdge(1,3);
    G.addEdge(3,1);

    G.addEdge(2,3);
    G.addEdge(3,2);

    G.addEdge(2,4);
    G.addEdge(4,2);

    vector<bool> visited;
    visited.resize(v,false);

    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            bool IsCycle = G.cycleUsingDFS(visited,i,-1);
            cout << "Is Cycle detected starting at " << i <<  " using DFS=" << IsCycle << endl;
            if(IsCycle)
                return IsCycle;
        }
        //visited.clear();
        //visited.resize(v,false);
    }

    return 0;
}
