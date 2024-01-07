#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class graph
{
    int V;
    vector<vector<pair<int,int>>>Adj;
public:
    graph(int e)
    {
        V=e;
        Adj.resize(V);
    }
    void addEdge(int u,int v,int wt)
    {
        Adj[u].push_back({v,wt});
    }
    bool bellmanFord(vector<int>& dist)
    {
        int n=V;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<V;j++)
            {
                for(auto adjacent:Adj[j])
                {
                    int y = adjacent.first;
                    int wt = adjacent.second;
                    cout << "u=" << j << " v=" << y << " wt=" << wt << endl;
                    cout << "dist[u]=" << dist[j] << " wt=" << wt << " dist[v]=" << dist[y] << endl;
                    if(dist[j]+wt<dist[y])
                    {
                        dist[y] = dist[j]+wt;
                        cout << " dist[v]=" << dist[y] << endl;
                    }
                }
            }
        }
        print_v(dist);
        vector<int> new_dist(dist);

        for(int j=0;j<V;j++)
        {
            for(auto adjacent:Adj[j])
            {
                int y = adjacent.first;
                int wt = adjacent.second;
                if(new_dist[j]+wt<new_dist[y])
                {
                    new_dist[y] = new_dist[j]+wt;
                }
            }
        }

        if(dist == new_dist)
        {
            cout << "No-Negative Cycle Detected" << endl;
        }
        else
        {
            cout << "Negative Cycle Detected" << endl;
        }

    }
    void print_v(vector<int> v)
    {
        for(auto val:v)
            cout << val << "\t";
        cout << endl;
    }
};

int main()
{
    int v = 4;
    graph g(v);
    g.addEdge(0,1,2);
    g.addEdge(0,3,-12);
    g.addEdge(1,2,6);
    g.addEdge(3,2,4);

    vector<int> dist;
    dist.resize(v,INT_MAX);

    dist[0] = 0;
    g.bellmanFord(dist);



    return 0;
}
