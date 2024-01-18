#include <iostream>
#include <vector>

using namespace std;

class Disjoint
{
    vector<int>parent;
    vector<int>ranking;
    vector<int>size_;
    int N;
public:
    Disjoint(int n)
    {
        N = n;
        ranking.resize(N,0);
        size_.resize(N,1);
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
    }

    void unionbyRank(int u,int v)
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
            ranking[root_v]++;
        }
    }

    void unionbySize(int u,int v)
    {
        int root_u = findParent(u);
        int root_v = findParent(v);

        if(root_u == root_v)
            return;

        if(size_[u]<size_[v])
        {
            parent[root_u] = root_v;
            size_[root_v] += size_[root_u];
        }
        else
        {
            parent[root_v] = root_u;
            size_[root_u] += size_[root_v];
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

        cout << "__Size_Array__" << endl;
        for(int i=0;i<N;i++)
            cout << size_[i] << "\t";
        cout << endl;
    }
};

int main()
{
    
    Disjoint d(5);
    d.unionbyRank(0,1);
    d.print_Obj();
    d.unionbyRank(2,3);
    d.print_Obj();
    d.unionbyRank(4,3);
    d.print_Obj();

    //d.print_Obj();
    if(d.findParent(4)==d.findParent(4))
    {
        cout << "Belongs to Same Set Using Ranking " << endl;
    }
    else
        cout << "Doesn't belong to Same Set Using Ranking " << endl;

    
    Disjoint d2(7);
    d2.unionbySize(1,2);
    d2.print_Obj();
    d2.unionbySize(2,3);
    d2.print_Obj();
    d2.unionbySize(4,5);
    d2.print_Obj();
    d2.unionbySize(6,7);
    d2.print_Obj();
    d2.unionbySize(5,6);
    d2.print_Obj();
    //d2.unionbySize(3,7);
    d2.print_Obj();

    //d.print_Obj();
    if(d2.findParent(2)==d2.findParent(6))
    {
        cout << "Belongs to Same Set Using Size" << endl;
    }
    else
        cout << "Doesn't belong to Same Set Using Size" << endl;
    return 0;
}
