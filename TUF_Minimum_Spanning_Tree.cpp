#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PairOfInt;
typedef pair<int,PairOfInt> POPairOfInt;

class Graph
{
    int n;
    vector<vector<PairOfInt>> Adj;

public:
    Graph(){}
    Graph(int v)
    {
        cout << __FUNCTION__ << endl;
        n=v;
        Adj.resize(n);
    }
    void addEdge(int u,int v, int wt)
    {
        cout << __FUNCTION__ << endl;
        Adj[u].push_back({v,wt});
    }
    int findMST(vector<PairOfInt>& MstList,int src,int parent)
    {
        cout << __FUNCTION__ << endl;
        int sum = 0;
        priority_queue<POPairOfInt,vector<POPairOfInt>,greater<POPairOfInt>> pQ;

        vector<int> visited(n,0);

        pQ.push({0,{src,parent}});

        while(!pQ.empty())
        {
            int wt = pQ.top().first;
            int u = pQ.top().second.first;
            int p = pQ.top().second.second; // Parent

            pQ.pop();

            if(!visited[u])
            {
                sum = sum + wt;
                visited[u]=1;
                if(p!=-1)
                {
                    MstList.push_back({p,u});
                }
            }

            for(auto adjacent:Adj[u])
            {
                int v = adjacent.first;
                int weight = adjacent.second;

                if(!visited[v])
                {
                    cout << "Pushed in Q" << endl;
                    pQ.push({weight,{v,u}});
                }
            }
        }
        return sum;
    }
};
int main()
{
    Graph G(5);
    G.addEdge(0,1,2);
    G.addEdge(0,2,1);

    G.addEdge(1,0,2);
    G.addEdge(1,2,1);

    G.addEdge(2,0,1);
    G.addEdge(2,1,1);
    G.addEdge(2,4,2);
    G.addEdge(2,3,2);

    G.addEdge(3,2,2);
    G.addEdge(3,4,1);

    G.addEdge(4,2,2);
    G.addEdge(4,3,1);

    int src = 0;
    vector<PairOfInt> MstList;
    int s = G.findMST(MstList,src,-1);

    cout << "ans =" << s << endl;

    cout << "[ " ;
    for(auto listdata:MstList)
    {
        cout << " ( " << listdata.first << "," << listdata.second << " ) ";
    }
    cout << " ] " ;
    return 0;
}
