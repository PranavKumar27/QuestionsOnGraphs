#include <iostream>
#include <vector>

using namespace std;

class Disjoint
{
    vector<int>parent;
    vector<int>ranking;
    int N;
public:
    Disjoint(int n)
    {
        N = n;
        ranking.resize(N,0);
        parent.resize(N);
        makeSet();
        print_Obj();
    }
    void makeSet()
    {
        for(int i=0;i<N;i++)
            parent[i] = i;
    }

    int findParent(int node)
    {
        if(parent[node] == node)
            return parent[node];

        else
        {
            int res = findParent(parent[node]);
            parent[node] = res;
        }
        //return parent[node];
    }

    void union_(int u,int v)
    {
        int root_u = findParent(u);
        int root_v = findParent(v);

        if(root_u == root_v)
            return;

        if(ranking[u]<ranking[v])
        {
            parent[root_u] = root_v;
        }
        else if(ranking[u]>ranking[v])
        {
            parent[root_v] = root_u;
        }
        else
        {
            parent[root_u] = root_v;
            ranking[root_v] = ranking[root_v]+1;
        }
    }
    void print_Obj()
    {
        cout << "__Parent Array__" << endl;
        for(int i=0;i<N;i++)
            cout << parent[i] << "\t";
        cout << endl;

        cout << "__Ranking_Array__" << endl;
        for(int i=0;i<N;i++)
            cout << ranking[i] << "\t";
        cout << endl;
    }
};

int main()
{
    Disjoint d(5);
    d.union_(0,1);
    d.print_Obj();
    d.union_(2,3);
    d.print_Obj();
    d.union_(4,3);
    d.print_Obj();

    //d.print_Obj();
    if(d.findParent(4)==d.findParent(4))
    {
        cout << "Belongs to Same Set" << endl;
    }
    else
        cout << "Doesn't belong to Same Set" << endl;
    return 0;
}
