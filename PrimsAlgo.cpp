#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
// Find MST( Minimum Spanning Tree ) of a Given Graph

class Graph
{
    int V;
    public:
    vector<vector<pair<int,int>>> Adj;

    Graph(int v)
    {
        V = v;
        Adj.resize(V);
    }
    void addEdge(int u,int v,int wt)
    {
        cout << __FUNCTION__ << endl;
        Adj[u].push_back(make_pair(v,wt));
    }
    void PrimsAlgo(int s,int& sum)
    {
        cout << __FUNCTION__ << endl;
        vector<bool> visited;
        visited.resize(V,false);

        sum = 0;
        vector<pair<int,int>> MST_Edges;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pQ;

        tuple<int,int,int> aStartNode = make_tuple(0,s,-1);
        pQ.push(aStartNode);
        visited[s] = true;

        while(!pQ.empty())
        {
            tuple<int,int,int> aFrontNode = pQ.top();
            pQ.pop();
            int wt = get<0>(aFrontNode);
            int v = get<1>(aFrontNode);
            int parent = get<2>(aFrontNode);

            cout << "Popped from Queue :wt=" << wt << " v=" << v << " parent=" << parent << endl;
            if(visited[v] == false && parent!=-1)
            {
                sum+=wt;
                visited[v] = true;
                MST_Edges.push_back(make_pair(parent,v));
            }
            for(auto adjacent:Adj[v])
            {
                int v_wt = adjacent.second;
                int v_node = adjacent.first;
                if(visited[v_node]==false)
                    pQ.push(make_tuple(v_wt,v_node,v));
            }
        }

        cout << "MST Sum =" << sum << endl;

        int i=0;
        for(auto edges:MST_Edges)
        {
            cout << "Edge:" << i++ << " from " << edges.second << " to " << edges.first << endl;
        }
    }
};
int main()
{
    Graph G(5);

    G.addEdge(0,1,2);
    G.addEdge(0,2,6);
    G.addEdge(1,3,3);
    G.addEdge(1,4,5);
    G.addEdge(2,1,8);
    G.addEdge(3,4,7);

    int sum=0;
    G.PrimsAlgo(0,sum);

    cout << "MST SUM =" << sum << endl;
    return 0;
}
