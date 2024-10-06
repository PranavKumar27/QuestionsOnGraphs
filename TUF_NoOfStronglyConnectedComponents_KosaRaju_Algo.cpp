#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
Kosaraju's Algo: 
If every pair of nodes can be reached from each other, it is called a SSC
SSC Strongly Connected components
The internal SSC is not impacted if all the edges are reversed
But if we have two SSC Connected and Edges are reversed, SSC will still remain connected internally
and SSC can't be reached from each other via DFS
Before
SSC1 ----> SSC2
After Reversal of Edges

SSC1 <---- SSC2

After Reversal of edges One Cannot reach SSC2 starting from SSC1

Hence there are two Strongly Connected  Components in the Graph

Steps in ALgo:
Sort the edges according to the finishing time when dfs is performed
Reverse the Graph
Do a dfs on each Sorted elements list

TC = O(E+v) for dfs and same for Algo
*/
class Graph
{
    public:
    int n;
    vector<vector<int>> Adj;

    Graph(){}
    Graph(int v)
    {
        n=v;
        Adj.resize(n);
    }
    void addEdge(int u,int v)
    {
        Adj[u].push_back(v);
    }
    void dfs(int src, stack<int>&S, vector<int>& visited)
    {
        if(!visited[src])
        {
            visited[src]=1;
        }

        for(auto adj:Adj[src])
        {
            //cout << "Calling DFS(" << adj << ")" << endl;
            dfs(adj,S,visited);
        }
        S.push(src);
        //cout << "Pushing Adj =" << src << endl;
    }
};

void reverseAllEdges(Graph& G,Graph& G1)
{
    int u =0 ;
    for(auto EdgeListVector:G.Adj)
    {
        for(auto data:EdgeListVector)
        {
            G1.addEdge(data,u);
        }
        u++;
    }
}
int main()
{
    int n = 8;
    Graph G(n);

    G.addEdge(0,1);
    G.addEdge(1,2);
    G.addEdge(2,0);

    G.addEdge(2,3);
    G.addEdge(3,4);
    G.addEdge(4,5);
    G.addEdge(5,6);
    G.addEdge(6,4);

    G.addEdge(4,7);
    G.addEdge(6,7);

    vector<int>visited(n,0);
    stack<int> S;

    int src =0;
    G.dfs(src,S,visited);
    Graph G1(n);
    reverseAllEdges(G,G1);

    vector<int>visited1(n,0);
    stack<int> S1;
    cout << "All Stack Data:: " << endl;
    int countOfNoOfSSC = 0;
    while(S.size()>0)
    {
        int data = S.top();
        if(!visited1[data]) // If Already visited Don't Call DFS Again
            G1.dfs(data,S1,visited1);
        if(S1.size()>0)
        {
            cout << "Size of SSC List =" << S1.size()  << endl;
            ++countOfNoOfSSC;
            cout << "Strongly Connect Component List=";
            while(S1.size()>0)
            {
                cout << S1.top() << ",";
                S1.pop(); // SSC list Stack POP
            }
            cout << endl;
        }
        S.pop();  // Main Stack POP
    }

    cout << "Total Number of Strongly Connected Component =" << countOfNoOfSSC << endl;
    return 0;
}
