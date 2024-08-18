#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#define INF 1e9

// Programmed on 18-08024 at 7.27 PM
using namespace std;

class Graph
{
    int V;
    vector<vector<pair<int,int>>>Adj;
public:
    Graph(){}
    Graph(int n)
    {
        V = n;
        Adj.resize(V);
    }
    void addEdge(int u,int v,int wt)
    {
        Adj[u].push_back({v,wt});
    }
    void dfs(vector<int>& visited,int src,stack<int>& S)
    {
        if(!visited[src])
        {
            visited[src]=1;
        }

        for(auto adjacent:Adj[src])
        {
            int v = adjacent.first;
            int wt = adjacent.second;
            if(!visited[v])
            {
                dfs(visited,v,S);
            }
        }
        S.push(src);
    }
    void findShortestDistance(vector<int>& dist,int src,stack<int>& S)
    {
        dist[src]=0; // Making source node distance as 0.

        while(!S.empty())
        {
            int u = S.top();
            S.pop();
            //cout << "u=" << u << endl;

            for(auto adjacent:Adj[u])
            {
                int v = adjacent.first;
                int wt = adjacent.second;

                //cout << "v=" << v << " wt=" << wt << endl;
                if(dist[u]!=INF && dist[v]>dist[u]+wt)
                {
                    dist[v] = dist[u]+wt;
                    //cout << "Updated Distance of v =" << dist[v] << endl;
                }
            }
        }

    }
};
int main()
{
    int n = 7;
    Graph G(n);
    G.addEdge(0,1,2);
    G.addEdge(1,3,1);
    G.addEdge(2,3,3);
    G.addEdge(4,0,3);
    G.addEdge(4,2,1);
    G.addEdge(5,4,1);
    G.addEdge(6,4,2);
    G.addEdge(6,5,3);

    vector<int>visited;
    visited.resize(n,0);

    stack<int>S;
    int src = 6; // Start Node
    G.dfs(visited,src,S);





    for(int src=0;src<n;src++)
    {
        stack<int> S1(S);
        vector<int>dist;
        dist.resize(n,INF);

        //dist[src]=0;
        G.findShortestDistance(dist,src,S1);

        cout << "Distances Obtained starting with node =" << src << endl;
        for(auto d:dist)
        {
            if(d==INF)
                cout << "INF" << "\t";
            else
                cout << d << "\t";
        }
        cout << endl;
    }






    return 0;
}
