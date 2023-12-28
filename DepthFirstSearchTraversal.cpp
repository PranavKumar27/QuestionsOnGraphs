#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
    int v;
    vector<vector<int>> Adj;
public:
    Graph(int v)
    {
        this->v = v;
        Adj.resize(v);
    }

    void addEdge(int x,int y)
    {
        Adj[x].push_back(y);
    }

    vector<int> DFS(int s)
    {
       vector<int> res;
       vector<bool> visited;
       visited.resize(v,false);

       stack<int> Stk;
       Stk.push(s);
       visited[s] = true;

       while(!Stk.empty())
       {
           s =  Stk.top();
           cout << s << "\t";
           res.push_back(s);
           Stk.pop();
           for(auto adjacent:Adj[s])
           {
               if(!visited[adjacent])
               {
                   visited[adjacent] = true;
                   Stk.push(adjacent);
               }
           }
       }

    }

    void ViaRecursionDFS(vector<bool>& visited,int s)
    {
       visited[s] = true;
       cout << "" << s << "\t";

       vector<int>::iterator itr;
       for(itr = Adj[s].begin();itr!=Adj[s].end();itr++)
       {
           if(!visited[*itr])
           {
               //cout << "\tCalling DFS for Node=" << *itr << endl;
               ViaRecursionDFS(visited,*itr);
           }
       }
    }

    void CallDFS(int s)
    {
        vector<bool> visited;
        visited.resize(5,false);
        ViaRecursionDFS(visited,s);
    }

    void printAdjList()
    {
        int sz = Adj.size();
        for(int i=0;i<sz;i++)
        {
            cout << i << "-->\t";
            for(auto adjacent:Adj[i])
            {
                cout << adjacent << "\t";
            }
            cout << endl;
        }
    }

};
using namespace std;

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

    G.DFS(2);
    cout << endl;

    G.CallDFS(2);

    return 0;
}
