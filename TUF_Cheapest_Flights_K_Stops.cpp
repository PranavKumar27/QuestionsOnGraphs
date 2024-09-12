#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int,int> PairOfInt;
typedef pair<int,PairOfInt> PairOfIntOfInt;
typedef vector<vector<PairOfInt>> V_Of_PairOfInt;

#define INF INT_MAX

class Graph
{
    int node;
    V_Of_PairOfInt Adj;

public:
    Graph(){}
    Graph(int n)
    {
        node = n;
        Adj.resize(node);
    }
    void addEdge(int u,int v,int wt)
    {
        Adj[u].push_back({v,wt});
    }
    int bfs_for_Cheapest_flights(int srcNode,int destNode, vector<int>& dist,int k)
    {
        queue<PairOfIntOfInt> q;
        int stops = 0;

        q.push({stops,{srcNode,0}});
        dist[srcNode]=0;

        while(!q.empty())
        {
            PairOfIntOfInt p = q.front();
            q.pop();

            stops = p.first;
            int u = p.second.first;
            int wt = p.second.second;

            cout << "{" << stops << ",{" << u << "," << wt << "}}" << endl;

            if(stops>k)
                continue;

            /*if(u==destNode && stops>=k+1)
            {
                cout << "Ans Found " << endl;
                return dist[u];
            }*/

            for(auto adj:Adj[u])
            {
                int v = adj.first;
                int weight = adj.second;

                if(v==destNode)
                {
                   cout << "dist =" << dist[v] << endl;
                   cout << "alternate dist =" << wt+weight << endl;
                }

                if(dist[v]>weight+wt && stops<=k)
                {

                    dist[v]=weight+wt;
                    q.push({stops+1,{v,dist[v]}});
                }
            }
        }
        return dist[destNode];
    }
};
int main()
{
    int n= 5;
    Graph G(n);
    G.addEdge(0,1,5);
    G.addEdge(0,3,2);

    G.addEdge(1,2,5);
    G.addEdge(1,4,1);

    G.addEdge(3,1,2);
    G.addEdge(4,2,1);

    int noOfStopsK = 2; // Maximum No of stops allowed to find the cheapest FLights

    vector<int> dist;
    dist.resize(n,INF);
    int startNode = 0; // Start Node
    int endNode = 2; // End Node or destination Node
    int ans = G.bfs_for_Cheapest_flights(startNode,endNode,dist,noOfStopsK);
    cout << "Cheapest Flight Cost " << ans << endl;
    return 0;
}
