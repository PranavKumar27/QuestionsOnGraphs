#include <iostream>
#include <vector>

using namespace std;

class Union_Find
{
    int n;
    vector<int> parent;
    vector<int> ranks;
    vector<int> sizes;

public:
    Union_Find(){}
    Union_Find(int V)
    {
        n=V;
        parent.resize(n);
        initParent();
        ranks.resize(n,0);
        sizes.resize(n,1);
    }
    void initParent()
    {
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }
    }
    void print_v(vector<int> ranks)
    {
        cout << "\n Sizes::" ;
        for(auto r:ranks)
            cout << r << ",";
        cout << endl;
    }
    void union_by_rank(int u,int v)
    {
        cout << __FUNCTION__ << endl;

        cout << "Before u=" << u << " v=" << v << endl;

        print_v(ranks);
        int ultimate_p_u = findParent(u);
        int ultimate_p_v = findParent(v);

        cout << "Before ultimate_p_u=" << ultimate_p_u << " ultimate_p_v=" << ultimate_p_v << endl;

        int rank_u = ranks[ultimate_p_u];
        int rank_v = ranks[ultimate_p_v];



        cout << "Before rank_u=" << rank_u << " rank_v=" << rank_v << endl;

        if(ultimate_p_u == ultimate_p_v)
        {
            cout << "Same Edge Or Cycle" << endl;
            return;
        }
        if(rank_u==rank_v)
        {
            rank_u = rank_u+1;
            ranks[ultimate_p_u] = rank_u;
            parent[ultimate_p_v] = ultimate_p_u;
        }
        else if(rank_u>rank_v)
        {
            parent[ultimate_p_v] = ultimate_p_u;
        }
        else if(rank_u<rank_v)
        {
            parent[ultimate_p_u] = ultimate_p_v;
        }

        cout << "After rank_u=" << rank_u << " rank_v=" << rank_v << endl;

        cout << "After ultimate_p_u=" << ultimate_p_u << " ultimate_p_v=" << ultimate_p_v << endl;
    }

    void union_by_size(int u,int v)
    {
        cout << __FUNCTION__ << endl;

        cout << "Before u=" << u << " v=" << v << endl;

        int ultimate_p_u = findParent(u);
        int ultimate_p_v = findParent(v);

        cout << "Before ultimate_p_u=" << ultimate_p_u << " ultimate_p_v=" << ultimate_p_v << endl;

        print_v(sizes);
        int size_u = sizes[ultimate_p_u];
        int size_v = sizes[ultimate_p_v];

        cout << "Before size_u=" << size_u << " size_v=" << size_v << endl;

        if(ultimate_p_u == ultimate_p_v)
        {
            cout << "Same Edge Or Cycle" << endl;
            return;
        }

        if(size_u>=size_v)
        {
            size_u = size_u+size_v;
            sizes[ultimate_p_u] = size_u;
            parent[ultimate_p_v] = ultimate_p_u;
        }
        else if(size_u<size_v)
        {
            size_v = size_v+size_u;
            sizes[ultimate_p_v] = size_v;
            parent[ultimate_p_u] = ultimate_p_v;
        }

        cout << "After size_u=" << size_u << " size_v=" << size_v << endl;

        cout << "After ultimate_p_u=" << ultimate_p_u << " ultimate_p_v=" << ultimate_p_v << endl;
    }

    int findParent(int node)
    {
        //cout << __FUNCTION__ << endl;

        if(node == parent[node])
            return node;
        return parent[node]=findParent(parent[node]);

    }
    bool Belongs_to_Same_Set(int u,int v)
    {
        int ultimate_p_u = findParent(u);
        int ultimate_p_v = findParent(v);

        if(ultimate_p_u == ultimate_p_v)
            return true;
        else
            return false;

    }
};
int main()
{
    /*
    Union_Find G(8);

    G.union_by_rank(1,2);
    G.union_by_rank(2,3);
    G.union_by_rank(4,5);
    G.union_by_rank(6,7);

    cout << "Using Union by Rank Does 1 and 7 belongs to same set =" << G.Belongs_to_Same_Set(1,7) << endl;
    G.union_by_rank(5,6);
    G.union_by_rank(3,7);

    cout << "Using Union By Rank Does 1 and 7 belongs to same set =" << G.Belongs_to_Same_Set(1,7) << endl;
    */

    Union_Find G(8);

    G.union_by_size(1,2);
    G.union_by_size(2,3);
    G.union_by_size(4,5);
    G.union_by_size(6,7);

    cout << "Using Union by Size Does 1 and 7 belongs to same set =" << G.Belongs_to_Same_Set(1,7) << endl;
    G.union_by_size(5,6);
    G.union_by_size(3,7);

    cout << "Using Union by SizeDoes 1 and 7 belongs to same set =" << G.Belongs_to_Same_Set(1,7) << endl;


    return 0;
}
