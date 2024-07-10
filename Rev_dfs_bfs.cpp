#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Graph
{
    int nodes;
    vector<vector<int>> Adj;
    vector<bool>visited;
    int u,v;
public:
    Graph(){}
    Graph(int v)
    {
        nodes = v;
        Adj.resize(nodes);
    }
    void addEdge(int u,int v)
    {
        Adj[u].push_back(v);
    }
    void printGph()
    {
        for(auto row:Adj)
        {
            //cout << "" << Adj.at(1) << "->";
            for(auto col:row)
            {
                cout << col << ",";
            }
            cout << endl;
        }
    }
    void dfs(vector<int>& res,int s)
    {
        cout << __FUNCTION__ << endl;
        visited.resize(nodes,false);
        stack<int> st;
        st.push(s);
        visited[s] = true;

        while(!st.empty())
        {
            int element = st.top();
            res.push_back(element);
            st.pop();
            for(auto adjacent:Adj[element])
            {
                if(!visited[adjacent])
                {
                   st.push(adjacent);
                   visited[adjacent] = true;
                }
            }
        }
    }

    void bfs(vector<int>& res,int s)
    {
        cout << __FUNCTION__ << endl;
        visited.clear();
        visited.resize(nodes,false);
        queue<int> Q;
        Q.push(s);
        visited[s] = true;

        while(!Q.empty())
        {
            int element = Q.front();
            res.push_back(element);
            Q.pop();
            for(auto adjacent:Adj[element])
            {
                if(!visited[adjacent])
                {
                    Q.push(adjacent);
                    visited[adjacent] = true;
                }
            }

        }

    }

    void dfs(vector<int>& res, int s, vector<int>& visited)
    {
        if(!visited[s])
        {
            visited[s] = true;
            //cout << s << "\t";
            res.push_back(s);
        }

        for(auto adjacent:Adj[s])
        {
            if(!visited[adjacent])
            {
               dfs(res,adjacent,visited);

            }
        }


    }

};

int main()
{
    Graph G(5);
    G.addEdge(1,2);
    G.addEdge(1,4);
    G.addEdge(2,1);
    G.addEdge(2,3);
    G.addEdge(3,2);
    G.addEdge(3,4);
    G.addEdge(4,1);
    G.addEdge(4,3);

    //G.printGph();
    vector<int> res;
    G.dfs(res,1);

    for(auto x:res)
    {
        cout << x << "\t";
    }
    cout << endl;

    vector<int> res2;
    G.bfs(res2,1);

    for(auto x:res2)
    {
        cout << x << "\t";
    }
    cout << endl;

    vector<int> boolValues;
    boolValues.resize(5,false);
    vector<int> result;
    G.dfs(result,1,boolValues);

    cout << "dfs Using Recursion " << endl;
    for(auto x:result)
    {
        cout << x << "\t";
    }
    cout << endl;

    return 0;
}
