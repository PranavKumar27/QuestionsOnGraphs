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
    vector<vector<pair<int,int>>> Adj;
    vector<pair<int,int>> EdgeList;
public:
    Graph(int v)
    {
        V=v;
        Adj.resize(V);
    }
    void addEdge(int u,int v,int wt)
    {
        Adj[u].push_back({v,wt});
        Adj[v].push_back({u,wt});
        EdgeList.push_back({u,v});
        EdgeList.push_back({v,u});
    }

    void printAll()
    {
        for(auto adjacent:Adj)
        {
            cout << "-->\n";
            for(auto data:adjacent)
            {
                cout << "node=" << data.first << "\t";
                cout << "weight=" << data.second << "\n";
            }
            cout << endl;
        }
        cout << endl;
    }
    void removeEdge(int u,int v,int wt)
    {
        pair<int,int> p = {v,wt};
        pair<int,int> q = {u,wt};
        auto itr = find(Adj[u].begin(),Adj[u].end(),p);
        if(itr!=Adj[u].end())
        {
            Adj[u].erase(itr);
        }

        auto itr2 = find(Adj[v].begin(),Adj[v].end(),q);
        if(itr2!=Adj[v].end())
        {
            Adj[v].erase(itr2);
        }

        pair<int,int> p1 = {u,v};
        auto itr3 = find(EdgeList.begin(),EdgeList.end(),p1);
        if(itr3!=EdgeList.end())
        {
            EdgeList.erase(itr3);
        }
        pair<int,int> p2 = {v,u};
        auto itr4 = find(EdgeList.begin(),EdgeList.end(),p2);
        if(itr4!=EdgeList.end())
        {
            EdgeList.erase(itr4);
        }
    }

    int ShorestPath(int u,int v)
    {
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
            q.pop();

            for(auto adjacent:Adj[start_u])
            {
                int adj_v = adjacent.first;
                int adj_wt = adjacent.second;

                if(dist[adj_v]>wt_u+adj_wt)
                {
                    dist[adj_v] = wt_u+adj_wt;
                    q.push({dist[adj_v],adj_v});
                }
            }

        }

        return dist[v];
    }
    void ShortestCycle()
    {
        int res=INF;
        for(auto edges:EdgeList)
        {
            int u = edges.first;
            int v = edges.second;

            int wt = -1;
            int node;

            for(auto allNodes:Adj[u])
            {
                node = allNodes.first;
                if(node == v)
                {
                    wt = allNodes.second;
                    break;
                }
            }

            removeEdge(u,v,wt);
            removeEdge(v,u,wt);

            int path = ShorestPath(u,v);
            cout << "path =" << path << endl;
            res = min(res,path+wt);

            addEdge(u,v,wt);

            cout << "Shortest Cycle Distance between u = " << u << " and v = " << v << " equals = " << res << endl;
        }

        cout << "Shortest Cycle Detected = " << res << endl;
    }
};

int main()
{
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    //g.printAll();
    g.ShortestCycle();

    return 0;
}
