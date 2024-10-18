#include <iostream>
#include <vector>

using namespace std;

/*
Articulation point: A Point in the Graph on whose removal the Graph
                    will break into two or more parts is known as Articulation Point


*/

class Graph
{
    int n;
    vector<vector<int>> Adj;
public:
    Graph(){}
    Graph(int v)
    {
        n=v;
        Adj.resize(n);
    }
    void addEdge(int u,int v)
    {
        Adj[u].push_back(v);
    }
    void dfs(int src,int parent,vector<int>& visited,vector<int>& low,vector<int>& tin,int& timer,vector<int>& Art)
    {
        timer=timer+1;
        visited[src]=1;
        low[src]=timer;
        tin[src]=timer;

        int child = 0;
        for(auto adj:Adj[src])
        {
            if(adj==parent)
                continue;
            else if(visited[adj]==0)
            {
                dfs(adj,src,visited,low,tin,timer,Art);
                /// Updated with lowest of the adj

                low[src] = min(low[src],low[adj]);  /// This is done when we back-track from DFS and update low with lowest so far

                if(low[adj]>=tin[src] && parent!=-1)  /// If the adj can reach only upto tin[src], It means it's reach is only upto src
                                                      /// If a component can only reach upto src, It means if src is removed graph will
                                                      /// disconnect, Hence articulation Point
                {
                    /// Articulation Point
                    Art[src]=1;
                }
                child++;                              /// child is counted for parent Else for connected graph as well
                                                      /// low[adj] = tin[src] src is starting point since they are connected
            }
            else if(visited[adj]==1)
            {
                low[src] = min(low[src],tin[adj]);  /// Comparison is done with tin here since we cannot re-trace the path
                                                    /// But we can still reach smallest tin possible Hence we compare with tin
            }
        }
        if(child>1 && parent==-1)                   /// This condition makes sure that only if start node has more than 1 Chd
                                                    /// Then only it can become ART point
        {
            Art[src]=1;
        }
    }
};
int main()
{
    int n=9;
    Graph G(n);
    G.addEdge(1,2);
    G.addEdge(1,3);
    G.addEdge(1,4);

    G.addEdge(2,1);

    G.addEdge(3,1);
    G.addEdge(3,4);
    G.addEdge(3,5);

    G.addEdge(4,1);
    G.addEdge(4,3);

    G.addEdge(5,3);
    G.addEdge(5,6);
    G.addEdge(5,8);

    G.addEdge(6,5);
    G.addEdge(6,7);

    G.addEdge(7,6);
    G.addEdge(7,8);

    G.addEdge(8,5);
    G.addEdge(8,7);

    vector<int> visited;
    visited.resize(n,0);

    vector<int> low,tin;
    low.resize(n,0);
    tin.resize(n,0);
    vector<int> Art;
    Art.resize(n,0);
    int timer = 1;

    G.dfs(1,-1,visited,low,tin,timer,Art);

    cout << "Articulation Points Are::" << endl;

    for(int i=0;i<n;i++)
    {
        if(Art[i]==1)
        {
            cout << i << ",";
        }
    }

    cout << endl;

    return 0;
}
