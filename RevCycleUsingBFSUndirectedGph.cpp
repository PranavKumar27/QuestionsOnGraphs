#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    int node;
    vector<vector<int>> Adj;
public:
    Graph(int n)
    {
        node = n;
        Adj.resize(node);
    }
    void addEdge(int u,int v)
    {
        Adj[u].push_back(v);
    }
    bool IsCyclePresentBFSQueue(vector<bool>& visited,int s)
    {
        queue<pair<int,int>> Q;
        Q.push({s,-1});

        while(!Q.empty())
        {
            pair<int,int> p = Q.front();
            int vertex = p.first;
            int parent = p.second;
            visited[vertex]=true;
            Q.pop();

            for(auto adjacent:Adj[vertex])
            {
                if(!visited[adjacent])
                {
                    Q.push({adjacent,vertex});
                }
                else if(visited[adjacent] && parent!=adjacent)
                {
                    return true;
                }
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
    //G.addEdge(1,5);
    G.addEdge(2,1);
    G.addEdge(2,3);
    G.addEdge(2,5);
    G.addEdge(3,2);
    G.addEdge(3,4);
    //G.addEdge(5,1);
    G.addEdge(4,3);
    G.addEdge(5,2);

    vector<bool> visited;
    visited.resize(n,false);
    bool res = false;

    res = G.IsCyclePresentBFSQueue(visited,1);

    cout << "Is Cycle Found =" << res << endl;
    return 0;
}
