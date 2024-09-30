#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VofInt;

class Union_Set
{
    int n;
    VofInt parent;
    VofInt ranks;

public:
    Union_Set(){}
    Union_Set(int v)
    {
        n=v;
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        ranks.resize(n,0);
    }
    int findParent(int node)
    {
        if(node == parent[node])
            return node;
        else
            return parent[node] = findParent(parent[node]);
    }
    void union_by_rank(int u,int v)
    {
        int ult_p_u = findParent(u);
        int ult_p_v = findParent(v);

        if(ult_p_u != ult_p_v)
        {
            if(ranks[ult_p_u]==ranks[ult_p_v])
            {
                ranks[ult_p_u] += 1;
                parent[ult_p_v] = parent[ult_p_u];
            }
            else if(ranks[ult_p_u]>ranks[ult_p_v])
            {
                parent[ult_p_v] = parent[ult_p_u];
            }
            else
            {
                parent[ult_p_u] = parent[ult_p_v];
            }
        }
        else
        {
            cout << "Cycle Present" << endl;
        }
    }
    int noOfProvinces()
    {
        int cnt = 0;
        for(int i=0;i<n;++i)
        {
            if(parent[i]==i)
            {
                ++cnt;
                cout << "\n Province Found parent =" << parent[i] << endl;
            }
        }
        cout << "\n\n";
        return cnt;
    }

};

int main()
{
    Union_Set S(8);
    S.union_by_rank(1,2);
    S.union_by_rank(2,1);
    S.union_by_rank(2,3);

    S.union_by_rank(4,5);
    S.union_by_rank(5,4);

    S.union_by_rank(6,7);

    int res = S.noOfProvinces();
    cout << "Count the No Of Provinces =" << res << endl;
    return 0;
}
