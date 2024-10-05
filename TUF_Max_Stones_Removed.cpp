#include <iostream>
#include <vector>
#include <map>

using namespace std;

class union_Set
{
    public:

    int n;
    vector<int> parent;
    vector<int> sizes;


    union_Set(){}
    union_Set(int n)
    {
        this->n = n;
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        sizes.resize(n,1);
    }
    int findParent(int node)
    {
        if(node == parent[node])
            return node;
        else
        {
            return parent[node]=findParent(parent[node]);
        }
    }
    void unionBySize(int u,int v)
    {
        int ult_p_u = findParent(u);
        int ult_p_v = findParent(v);

        if( ult_p_u != ult_p_v )
        {
            if(sizes[ult_p_u]>=sizes[ult_p_v])
            {
                sizes[ult_p_u] += sizes[ult_p_v];
                parent[ult_p_v] = ult_p_u;
            }
            else
            {
                sizes[ult_p_v] += sizes[ult_p_u];
                parent[ult_p_u] = ult_p_v;
            }
        }
    }

};

int findMaxNoOfStonesToBeRemoved(vector<vector<int>> Stones)
{
    int row = Stones.size();
    int col = Stones.size();

    int totalNodes = row+col;
    union_Set S(totalNodes);

    int totalStones = 0;
    map<int,int> Stones_index;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(Stones[i][j]==1)
            {
                ++totalStones;
                int node = j+row;
                S.unionBySize(i,node);
                Stones_index[node] = 1;
                Stones_index[i] = 1;
            }
        }
    }

    // Find Ultimate Parents with size > 1
    int totalConnectedComponents =0;

    /*
    Technique 1
    for(int i=0;i<totalNodes;i++)
    {
        if(S.parent[i]==i && S.sizes[i]>1)
        {
            ++totalConnectedComponents;
        }
    }
    */

    /// Technique 2
    for(auto d:Stones_index)
    {
        if(S.findParent(d.first)==d.first)
        {
           ++totalConnectedComponents;
        }
    }

    cout << "total Stones=" << totalStones << endl;
    cout << "No of Connected components =" << totalConnectedComponents << endl;

    int diff = totalStones - totalConnectedComponents;
    cout << "diff =" << diff << endl;
    return diff;
}
int main()
{
    vector<vector<int>> Stones = {
                                    {0,1},
                                    {1,0}
                                };

    int ans = findMaxNoOfStonesToBeRemoved(Stones);

    cout << "Maximum Number of Stones that can be removed =" << ans << endl;
    return 0;
}
