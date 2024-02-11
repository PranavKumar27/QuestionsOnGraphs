#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>

#define INF INT_MAX

using namespace std;

class Graph
{
    int V;
    vector<vector<int>> Adj;
    vector<pair<int,int>> EdgeList;
public:
    Graph(int v)
    {
        V=v;
        Adj.resize(V);
    }
    void addEdge(int u,int v)
    {
        Adj[u].push_back(v);
        Adj[v].push_back(u);
        EdgeList.push_back({u,v});
        //EdgeList.push_back({v,u});
    }
    void printAll()
    {
        for(auto adjacent:Adj)
        {
            cout << "-->\t";
            for(auto vertex:adjacent)
            {
                cout << vertex << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    void removeEdge(int u,int v)
    {
        auto itr = find(Adj[u].begin(),Adj[u].end(),v);
        if(itr!=Adj[u].end())
        {
            Adj[u].erase(itr);
        }

        auto itr2 = find(Adj[v].begin(),Adj[v].end(),u);
        if(itr2!=Adj[v].end())
        {
            Adj[v].erase(itr2);
        }

        pair<int,int> p = {u,v};
        auto itr3 = find(EdgeList.begin(),EdgeList.end(),p);
        if(itr3!=EdgeList.end())
        {
            EdgeList.erase(itr3);
        }

        /*
        pair<int,int> p_ = {v,u};
        auto itr4 = find(EdgeList.begin(),EdgeList.end(),p_);
        if(itr4!=EdgeList.end())
        {
            EdgeList.erase(itr4);
        }
        */
    }
    int ShorestPath(int u,int v)
    {
        cout << __FUNCTION__ << " u=" << u << " v=" << v << endl;
        vector<int> dist;
        dist.resize(V,INF);
        dist[u] = 0;

        queue<pair<int,int>> q; // wt, node
        q.push({0,u});

        while(!q.empty())
        {
            pair<int,int> p = q.front();
            int wt_u = p.first;
            int start_u = p.second;
            cout << " start_u=" << start_u << " wt_u=" << wt_u << endl;
            q.pop();

            for(auto adjacent:Adj[start_u])
            {
                int adj_v = adjacent;
                int adj_wt = 1; // Unit weight Fixed

                cout << "u=" << u <<" adj_v=" << adj_v << " wt=" << adj_wt << endl;
                if(dist[adj_v]>wt_u+adj_wt)
                {
                    dist[adj_v] = wt_u+adj_wt;
                    q.push({dist[adj_v],adj_v});
                }
            }

        }
        cout << "All Distances Calculated = \t";
        for(auto d:dist)
        {
            if(d==INF)
                cout << "INF\t";
            else
                cout << d << "\t";
        }
        cout << endl;

        cout << "dist[v]=" << dist[v] << endl;
        return dist[v]+1;
    }
    void ShortestCycle()
    {
        int res=INF;
        for(auto edges:EdgeList)
        {
            int u = edges.first;
            int v = edges.second;

            removeEdge(u,v);
            removeEdge(v,u);
            int path = ShorestPath(u,v);
            cout << "path Length of u and v =" << path << endl;
            res = min(res,path);

            addEdge(u,v);

            cout << "Shortest Cycle Distance between u = " << u << " and v = " << v << " equals = " << res << endl;
        }

        cout << "Shortest Cycle Detected = " << res << endl;
    }
};

int main()
{

    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);

    g.printAll();
    g.ShortestCycle();

    return 0;
}
