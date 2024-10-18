////////////////////////////////////////// NEW CODE /////////////////////////////////////////

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
    int n;
    vector<vector<int>> Adj;

public:
    Graph(){}
    Graph(int n)
    {
        this->n=n;
        Adj.resize(n);
    }
    void addEdge(int u,int v)
    {
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    void DFS(vector<int>& visited,vector<int>& tin, vector<int>& low,int src, int parent,int& timer)
    {
        if(!visited[src])
        {
            timer = timer+1;
            visited[src]=1;
            tin[src]=timer;
            low[src]=timer;

            for(auto adj:Adj[src])
            {
                if(adj==parent) continue;
                if(!visited[adj])
                {
                    DFS(visited,tin,low,adj,src,timer);

                    low[src] = min(low[src],low[adj]);

                    if(low[adj]>tin[src]) // time of insertion is less than low of adj
                    {
                        // A bridge is detected
                        cout << "A bridge Between " << src << " and " << adj << endl;
                    }
                }
                else
                {
                    low[src] = min(low[src],low[adj]);
                }

            }
        }
    }
};

int main()
{
    int n=13;
    Graph G(n);

    G.addEdge(1,2);
    G.addEdge(1,4);
    G.addEdge(2,3);
    G.addEdge(3,4);

    G.addEdge(4,5);
    G.addEdge(5,6);

    G.addEdge(6,7);
    G.addEdge(9,6);
    G.addEdge(7,8);
    G.addEdge(8,9);

    G.addEdge(8,10);
    G.addEdge(10,11);
    G.addEdge(11,12);
    G.addEdge(12,10);

    vector<int> visited(n,0);
    vector<int> tin(n,0);
    vector<int> low(n,0);
    int timer=0;

    G.DFS(visited,tin,low,1,-1,timer);

    return 0;
}


////////////////////////////////////////// OLD CODE ////////////////////////////////////////
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
    int n;
    vector<vector<int>> Adj;

public:
    Graph(){}
    Graph(int n)
    {
        this->n=n;
        Adj.resize(n);
    }
    void addEdge(int u,int v)
    {
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    void DFS(vector<int>& visited,vector<int>& tin, vector<int>& low,int src, int parent,int& timer)
    {
        if(!visited[src])
        {
            cout << "timer value =" << timer << endl;
            timer = timer+1;
            visited[src]=1;
            tin[src]=timer;
            low[src]=timer;

            cout << "tin[src]=" << tin[src] << " low[src]=" << low[src] << endl;

            for(auto adj:Adj[src])
            {
                if(adj==parent) continue;
                if(!visited[adj])
                {
                    cout << "Calling DFS on " << adj << endl;
                    DFS(visited,tin,low,adj,src,timer);


                    if(low[src]>low[adj]) // low of adj is less than src
                    {
                        cout << "Found a lower src low[src]=" << low[src] << " low[adj]=" << low[adj] << endl;
                        low[src] = low[adj];

                        // Can src and parent be a bridge

                    }

                    if(tin[src]<low[adj]) // time of insertion is less than low of adj
                    {
                        // A bridge is detected
                        cout << "A bridge Between " << src << " and " << adj << endl;
                    }
                }
                else
                {
                    if(low[src]>low[adj]) // low of adj is less than src
                    {
                        cout << "Before Found a lower adj  low[src]=" << low[src] << " low[adj]=" << low[adj] << endl;
                        low[src] = low[adj];
                        cout << "After Found a lower adj  low[src]=" << low[src] << " low[adj]=" << low[adj] << endl;
                        // Can src and parent be a bridge

                    }
                }

            }
        }
        else
        {
            cout << "-----------DFS on node " << src << " already done"  << " parent=" << parent << endl;
            //cout << "tin[src]=" << tin[src] << " low[src]=" << low[src] << endl;
            //cout << "tin[parent]=" << tin[parent] << " low[parent]=" << low[parent] << endl;





        }

    }
};

int main()
{
    int n=13;
    Graph G(n);

    G.addEdge(1,2);
    G.addEdge(1,4);
    G.addEdge(2,3);
    G.addEdge(3,4);

    G.addEdge(4,5);
    G.addEdge(5,6);

    G.addEdge(6,7);
    G.addEdge(9,6);
    G.addEdge(7,8);
    G.addEdge(8,9);

    G.addEdge(8,10);
    G.addEdge(10,11);
    G.addEdge(11,12);
    G.addEdge(12,10);

    vector<int> visited(n,0);
    vector<int> tin(n,0);
    vector<int> low(n,0);
    int timer=0;

    G.DFS(visited,tin,low,1,-1,timer);

    return 0;
}
