// Same as Kahn's Algo for topological Sort
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class graph
{
    int V;
    vector<vector<int>> Adj;
public:
    graph(int vertex)
    {
        V=vertex;
        Adj.resize(V);
    }
    void addEdge(int u,int v)
    {
        Adj[u].push_back(v);
    }

    void generateInDegree(vector<int>& in)
    {
        in.resize(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto adjacent:Adj[i])
            {
                in[adjacent]++;
            }
        }
    }

    void print_v(vector<int> v)
    {
        cout << endl;

        for(int i=0;i<v.size();i++)
            cout << i << "\t" << v[i] << endl;
        cout << endl;
    }
    void cycleUsingBFS(vector<int>& res,vector<int> in)
    {
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }

        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);

            // find Adjacent and reduce the in degree
            for(auto adjacent:Adj[node])
            {
                in[adjacent]--;
                if(in[adjacent]==0)
                {
                    q.push(adjacent);
                }
            }

        }

        //print_v(res);
    }
};

int main()
{
    int v = 4;
    graph g(v);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,1);

    vector<int> in;
    g.generateInDegree(in);

    vector<int> res;
    g.cycleUsingBFS(res,in);

    if(res.size()!=v)
        cout << "A Cycle has been detected" << endl;
    for(auto x:res)
        cout << x << "\t";
    cout << endl;

    return 0;
}
