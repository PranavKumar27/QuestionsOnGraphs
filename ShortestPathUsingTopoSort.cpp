#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>

using namespace std;

class Graph
{
    int V;
    vector<vector<pair<int,int>>> Adj;
public:
    Graph(int v)
    {
        V=v;
        Adj.resize(V);
    }
    void addEdge(int u,int v,int wt)
    {
        Adj[u].push_back({v,wt});
    }
    void topologicalSort(stack<int>& st,int s,vector<bool>& visited)
    {
        if(visited[s]==false)
            visited[s] = true;

        for(auto adjacent:Adj[s])
        {
            int node = adjacent.first;
            if(visited[node]==false)
            {
                topologicalSort(st,node,visited);
            }
        }
        st.push(s);
    }
    vector<int> driverTopoSort()
    {
        vector<bool> visisted;
        visisted.resize(V,false);
        stack<int> st;

        for(int s=0;s<V;s++)
        {
            if(visisted[s]==false)
            {
                topologicalSort(st,s,visisted);
            }
        }
        vector<int> toposortRes;
        // Here the topo Sort is obtained
        while(!st.empty())
        {
            toposortRes.push_back(st.top());
            st.pop();
        }


        return toposortRes;
    }
    void findShortestDistance(vector<int> topoSort)
    {
        vector<int> dist;
        dist.resize(V,INT_MAX);
        int s = 0;
        dist[topoSort[0]] = 0;
        for(int i=0;i<V;i++)
        {
            int node = topoSort[i];
            cout << "node=" << node << " dist[node]=" << dist[node] << endl;
            for(auto adjacent:Adj[node])
            {
                int v = adjacent.first;
                int wt = adjacent.second;
                cout << " v=" << v << " wt=" << wt << endl;
                if(dist[node]+wt<dist[v])
                {
                    dist[v] = dist[node]+wt;
                    cout << "Updated dist[v]=" << dist[v] << endl;
                }
            }
        }


        cout << "Shortest Distances" << endl;
        for(int i=0;i<V;i++)
        {
            cout << "\t dist["<<i<<"]\t" << dist[i] << "\t";
        }
        cout << endl;
    }
};

int main()
{
    int v=7;
    Graph g(v);

    g.addEdge(0,1,2);
    g.addEdge(1,3,1);
    g.addEdge(2,3,3);
    g.addEdge(4,0,3);
    g.addEdge(4,2,1);
    g.addEdge(5,4,1);
    g.addEdge(6,4,2);
    g.addEdge(6,5,3);




    cout << "Topo Sort Result:" << endl;
    vector<int> topoSort = g.driverTopoSort();
    for(auto val:topoSort)
    cout << "\t" << val << "\t";
    cout << endl;

    g.findShortestDistance(topoSort);




    return 0;
}
