#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <typeinfo>

// 12.54 PM Start on 18-08-2024

using namespace std;

class Graph
{
    int V;
    vector<vector<char>> Adj;
public:
    Graph(){}
    Graph(int n)
    {
        V=n;
        Adj.resize(V);
        cout << "V = " << V << endl;
    }
    void addEdge(char u,char v)
    {
        cout << __FUNCTION__ << endl;
        Adj[u-'a'].push_back(v);
    }
    void dfs(vector<int>&visited,vector<int>& dfsVisited,int src,stack<char>& S)
    {
        cout << __FUNCTION__ << endl;
        cout << "src=" << src << endl;
        visited[src]=1;
        dfsVisited[src]=1;
        for(auto adjacent:Adj[src])
        {
            cout << "adjacent=" << adjacent << endl;
            if(visited[adjacent-'a']==0)
            {
                cout << "Calling DFS Again for adjacent=" << adjacent << endl;
                dfs(visited,dfsVisited,adjacent-'a',S);
            }
            else if(dfsVisited[adjacent-'a']==1)
            {
                return;
            }
        }
        S.push(src+'a');
        dfsVisited[src]=0;
        cout << "Pushed into stack =" << src << endl;
    }
};
bool findOrderInStr(string str1,string str2,char& u,char& v)
{
    int smaller_sz = min(str1.size(),str2.size());

    for(int i=0;i<smaller_sz;i++)
    {
        u=str1[i];
        v=str2[i];
        if(u!=v)
        {
            return true;
        }
    }
    /// If we reach here it means we have all chars in
    /// str1 and str2 matching upto the length Smaller_sz
    /// We cannot have an order like abcd and then abc
    /// In dictionary ordering abc comes before abcd

    if(str1.size()>str2.size())
    {
       return false;
    }
}
int main()
{
    int k = 4; // Given Input First 4 Alphabets of English Dictionary
    Graph Gph(k);
    vector<string> Str = {"baa","abcd","abca","cab","cad"};

    ///vector<string> Str = {"abcd","abca","baa","cab","cad"}; // Cycle exists

    for(int i =0;i<Str.size()-1;i++)
    {
        string str1 = Str[i];
        string str2 = Str[i+1];
        char u,v;
        if(findOrderInStr(str1,str2,u,v))
        {
            cout << "Edge from u--> v =  " << u << " --> " << v << endl;
            Gph.addEdge(u,v);
        }
        else
        {
            cout << "Incorrect Ordering of strings Dictionary is invalid" << endl;
            return 0;
        }

    }

    stack<char>S;
    vector<int>visited;
    visited.resize(k,0);

    vector<int>dfsVisited;
    dfsVisited.resize(k,0);

    for(int i=0;i<k;i++)
    {
        if(!visited[i])
        {
            Gph.dfs(visited,dfsVisited,i,S);
        }
    }


    if(S.size()!=k)
    {
        cout << "Cycle Detected- Incorrect Alien Dictionary - Not possible" << endl;
    }
    else
    {
        cout << "No Cycle - Alien Dictionary Order" << endl;

    }

    while(!S.empty())
    {
        cout << S.top() << "\t";
        S.pop();
    }
    //cout << "Hello world!" << endl;
    return 0;
}
