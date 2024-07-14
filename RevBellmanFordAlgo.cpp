#include <iostream>
#include <vector>
#include <limits.h>
#define INF INT_MAX
using namespace std;

/*
    Make N-1 Pass first if N vertices are there
    If The dist array changes in the Nth Pass as well
    Then A Negative Cycle is Present
*/

class Graph
{
    int Totalvertex;
    vector<vector<pair<int,int>>> Adj; // {u,v,wt}
public:
    Graph(){}
    Graph(int n)
    {
        Totalvertex = n;
        Adj.resize(Totalvertex);
    }
    void addEdge(int u,int v,int wt)
    {
        pair<int,int> p(v,wt);
        Adj[u].push_back(p);
    }
    bool IsNegativeCyleBFA(vector<int>& dist,int s)
    {
        dist.resize(Totalvertex,INF);
        dist[s]=0;
        //Run Loop and Relax the edge for N-1 Pass
        //since N vertex can have make N-1 Edges if no Cycle.
        int pass = Totalvertex;
        for(int i=0;i<pass-1;i++)
        {
            for(int u=0;u<Totalvertex;u++)
            {
               for(auto &adjacent : Adj[u])
               {
                   int v = adjacent.first;
                   int wt = adjacent.second;
                   if(dist[u]!=INF && dist[u]+wt<dist[v])
                   {
                       dist[v] = dist[u]+wt;
                   }
               }
            }
        }

        // Now Try to Relax the edges for Nth time
        // If Neg-Cycle Detected, dist array will change
        // If no change in dist array, No Neg Cycle

        cout << "Completed N-1 Pass " << endl;

        for(int u=0;u<Totalvertex;u++)
        {
            for(auto &adjacent:Adj[u])
            {
                int v = adjacent.first;
                int wt = adjacent.second;
                if(dist[u]!=INF && dist[u]+wt<dist[v])
                {
                    cout << "Cycle Found" << endl;
                    return true;
                }
            }
        }
        cout << "No Cycle Found" << endl;
        return false;
    }
};


int main()
{
    int v = 7;
    Graph G(v);
    G.addEdge(1,2,2);
    G.addEdge(1,5,1);
    G.addEdge(2,3,2);
    G.addEdge(3,4,-3);
    G.addEdge(4,2,-1);
    G.addEdge(5,4,1);
    G.addEdge(6,0,3);

    vector<int> dist;
    vector<bool> visited;
    visited.resize(v,false);

    //
    int ans;
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            cout << "Calling IsNegativeCyleBFA From Index i=" << i << endl;
            ans = G.IsNegativeCyleBFA(dist,i);
            if(ans)
                break;
        }
        for(int j=0;j<v;j++)
        {
            if(dist[j]!=INT_MAX)
            {
                cout << "Setting visited True for j=" << j << endl;
                visited[j]=true;
            }
        }
    }
    //bool res=G.IsNegativeCyleBFA(dist,0);
    cout << "Is Negative cycle Detected=" << ans << endl;
    return 0;
}
