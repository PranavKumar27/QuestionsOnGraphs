#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define INF INT_MAX
const int One = 1;
const int Zero = 0;

//This code is wriiten on Aug 19 2024 at 8 AM

using namespace std;

class Graph
{
    int V;
    vector<vector<int>> Adj;
public:
    Graph(){}
    Graph(int n)
    {
        V=n;
        Adj.resize(V);
    }
    void addEdge(int u,int v)
    {
        Adj[u].push_back(v);
    }
    void bfs(vector<int>& dist,int src)
    {
        queue<int> q;
        q.push(src);
        dist[src]=Zero;

        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            for(auto adjacent:Adj[u])
            {
                if(dist[u]!=INF && dist[adjacent]>dist[u]+One)
                {
                    dist[adjacent] = dist[u]+One;
                    q.push(adjacent);
                }
            }
        }
    }
};

void print_v(vector<int> v)
{
    for(auto d:v)
    {
        cout << d << "\t";
    }
    cout << endl;
}
int main()
{
    int n=9;
    Graph G(n);
    G.addEdge(0,1);
    G.addEdge(0,3);

    G.addEdge(1,0);
    G.addEdge(1,2);

    G.addEdge(2,1);
    G.addEdge(2,6);

    G.addEdge(3,0);
    G.addEdge(3,4);

    G.addEdge(4,3);
    G.addEdge(4,5);

    G.addEdge(5,4);
    G.addEdge(5,6);

    G.addEdge(6,2);
    G.addEdge(6,5);
    G.addEdge(6,7);
    G.addEdge(6,8);

    G.addEdge(7,6);
    G.addEdge(7,8);

    G.addEdge(8,6);
    G.addEdge(8,7);

    for(int src = 0;src < n;src++)
    {
        vector<int> dist;
        dist.resize(n,INF);
        G.bfs(dist,src);
        cout << "Distance Array with src = " << src << endl;
        print_v(dist);
        cout << endl;
    }
    
    return 0;
}
