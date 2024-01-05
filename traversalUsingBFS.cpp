// Breadth First Search 
#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph
{
    int vertex;
    vector<vector<int>> Adj;

public:
    Graph(int v)
    {
        vertex = v;
        Adj.resize(vertex);
    }
    void addEdge(int v,int w)
    {
        Adj[v].push_back(w);
    }
    void BFS(int s)
    {
        queue<int> q;
        q.push(s);
        vector<bool> visisted;
        visisted.resize(vertex,false);
        visisted[s] = true;

        while(!q.empty())
        {
            s = q.front();
            cout << s << "\t";
            q.pop();

            //int sz = Adj[s].size();
            //cout << "\t sz =" << sz << endl;
            for(auto adjacent:Adj[s])
            {
                if(!visisted[adjacent])
                {
                    visisted[adjacent] = true;
                    //cout << "\t Pushed =" << Adj[s][i] << "\n";
                    q.push(adjacent);
                }
            }

            /*

            OR -->
            for(int i=0;i<sz;i++)
            {
                //cout << "s=" << s << " visited[s]=" << visisted[s] << "\t To be Pushed =" << Adj[s][i]<< endl;
                if(!visisted[Adj[s][i]])
                {
                    visisted[Adj[s][i]] = true;
                    //cout << "\t Pushed =" << Adj[s][i] << "\n";
                    q.push(Adj[s][i]);
                }
            }
            */
        }
    }
    void printAdjList()
    {
        int sz = Adj.size();
        for(int i=0;i<sz;i++)
        {
            cout << i << "-->\t";
            int rowSz = Adj[i].size();
            for(int j=0;j<rowSz;j++)
            {
                cout << Adj[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph G(5);

    G.addEdge(1,0);
    G.addEdge(2,0);

    G.addEdge(0,1);
    G.addEdge(3,1);

    G.addEdge(0,2);
    G.addEdge(3,2);
    G.addEdge(4,2);

    G.addEdge(1,3);
    G.addEdge(2,3);
    G.addEdge(4,3);

    G.addEdge(2,4);
    G.addEdge(3,4);

    G.printAdjList();
    cout << endl;

    G.BFS(2);

    return 0;
}
