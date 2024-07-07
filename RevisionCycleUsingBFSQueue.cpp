#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int vertices;
    vector<vector<int>> Adj;
    int u,v;
public:
    Graph(int n)
    {
        vertices = n;
        Adj.resize(n);
    }
    void addEdge(int u,int v)
    {
        Adj[u].push_back(v);
    }
    bool IsCycleInGphUsingBFSQueue(vector<int>& in,vector<int>& res)
    {
        queue<int> q;
        int sz= in.size();
        for(int i=0;i<sz;i++)
        {
            if(in[i] == 0)
            {
                cout << "node with indegree =" << in[i] << " node=" << i << endl;
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node= q.front();
            q.pop();
            res.push_back(node);
            for(auto adjacent:Adj[node])
            {
                in[adjacent]--;
                if(in[adjacent] == 0)
                {
                    q.push(adjacent);
                }
            }
        }

        if(res.size()!=in.size())
            return true;
        else
            return false;
    }
    void print_v(vector<int> v)
    {
        for(auto x:v)
        {
            cout << x << ",";
        }
        cout << endl;
    }
    void generateInDegree(vector<int>& in)
    {
        for(int i=0;i<in.size();++i)
        {
            for(auto adj:Adj[i])
            {
                in[adj]++;
            }
        }
        print_v(in);
    }
};
int main()
{
    int n = 6;
    Graph G(n);
    G.addEdge(1,2);
    G.addEdge(2,4);
    G.addEdge(2,5);
    G.addEdge(1,3);
    G.addEdge(4,3);
    G.addEdge(4,5);

    vector<int> in;
    in.resize(n,0);

    G.generateInDegree(in);

    vector<int> res;
    bool result = G.IsCycleInGphUsingBFSQueue(in,res);
    for(auto x:res)
    {
        cout << x << ",";
    }
    cout << endl;

    cout << "Is Cycle Present in the Graph =" << result << endl;
    return 0;
}
