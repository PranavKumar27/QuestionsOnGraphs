#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <algorithm>

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
    void kahnsAlgo(vector<int>& res)
    {
        //Find Frequency of each node
        map<int,int> outdegree;
        for(int i=0;i<V;i++)
        {
            cout << "i=" << i << endl;
            bool NotFound = false;
            for(int j=0;j<V;j++)
            {
                cout << "j=" << j << endl;
               if(find(Adj[j].begin(),Adj[j].end(),i) == Adj[j].end())
                {
                    NotFound = true;
                }
                else
                {
                    cout << "Found i=" << i << " on index j=" << j << endl;
                    NotFound = false;
                    outdegree[i] = 1;
                    break;
                }
            }

            cout << "NotFound= " << NotFound << endl;
            //outdegree[i]=0;
            if(NotFound == true)
            {
                outdegree[i]=0;
            }
            else
            {
                for(auto adjacent:Adj[i])
                {
                    cout << "adjacent=" << adjacent << endl;
                    if(outdegree.find(adjacent)!=outdegree.end())
                    {
                        outdegree[adjacent]=outdegree[adjacent]+1;
                    }
                    cout << "outdegree of adjacenet=" << outdegree[adjacent] << " adjacent=" << adjacent << endl;
                }
            }
        }

        cout << "Outdegree Calculated" << endl;
        for(auto o:outdegree)
        {
            cout << o.first << "\t" << o.second << endl;
        }

        cout << endl;

        sortByValue(outdegree,res);



    }
/*
    bool cmp(pair<int,int>& a, pair<int,int>& b)
    {
        if(a.second < b.second)
            return true;
        //else
            //return false;
    }*/

    bool cmp(pair<string, int>& a,
        pair<string, int>& b)
{
    return a.second < b.second;
}
    void sortByValue(map<int,int>& outdegree,vector<int>& res)
    {
        vector<pair<int,int>> A;

        for(auto& m:outdegree)
        {
            A.push_back(m);
        }

        sort(A.begin(),A.end());

        cout << "Sorted Outdegree" << endl;
        for(auto& x:A)
        {
            cout << x.first << "\t" << x.second << endl;
            res.push_back(x.first);
        }

        reverse(res.begin(),res.end());
        cout << endl;
    }
};

int main()
{
    graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(3,0);

    vector<int> res;
    g.kahnsAlgo(res);


    for(auto x:res)
        cout << x << "\t";
    cout << endl;

    return 0;
}
