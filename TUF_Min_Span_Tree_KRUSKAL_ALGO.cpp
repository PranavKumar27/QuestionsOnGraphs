#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

/*
In Kruskal's Algo , we need to find the MST list and wt
first sort the edge list with increasing wt's
Once sorted Apply union find and see if belongs to same Set or not.
If same Parent then it belongs to same set
If two edges belongs to same set it means shortest weight path is already included in MST
Discard all weights if ultimate Parent of tow nodes are same.
Finally we get MST list which has weights and edges such that their wt's are minimum
*/

typedef vector<int> VInt;
typedef vector<pair<int,int>> VPairOfInt;
typedef vector<pair<int,pair<int,int>>> VPairOfPairOfInt;

class Union_Find // Also Disjoint Set DS
{
    int n;
    VInt parent;
    VInt sizes;

public:
    Union_Find(){}
    Union_Find(int vertex)
    {
        n = vertex;
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        sizes.resize(n,1);
    }

    int findParent(int child)
    {
        if(child == parent[child])
            return child;
        else
            return parent[child]=findParent(parent[child]);
    }

    void union_By_Size(int u,int v)
    {
        int ult_p_u = findParent(u);
        int ult_p_v = findParent(v);

        if(ult_p_u == ult_p_v)
        {
            cout << "Already Connected or Loop Exists" << endl;
            return;
        }

        if(sizes[ult_p_u]>=sizes[ult_p_v])
        {
            parent[ult_p_v] = ult_p_u;
            sizes[ult_p_u] += sizes[ult_p_v];
        }
        else
        {
            parent[ult_p_u] = ult_p_v;
            sizes[ult_p_v] += sizes[ult_p_u];
        }
    }

};

int findMstUsingUnionFind_KRUSKAL(VPairOfInt& MSTLIST,VPairOfPairOfInt EDGELIST)
{
    Union_Find unionSet(7);

    // Sort EdgeList with Weights
    sort(EDGELIST.begin(),EDGELIST.end());

    int sum = 0;

    for(auto elist:EDGELIST )
    {
        int wt = elist.first;
        int u = elist.second.first;
        int v = elist.second.second;

        cout << "u=" << u << " v=" << v << " wt=" << wt << endl;

        if(unionSet.findParent(u)!=unionSet.findParent(v))
        {
            sum += wt;
            unionSet.union_By_Size(u,v);
            MSTLIST.push_back({u,v});
        }
    }
    return sum;
}

int main()
{
    VPairOfPairOfInt EDGELIST; // wt,u,v
    EDGELIST.push_back({9,{4,5}});
    EDGELIST.push_back({7,{2,6}});
    EDGELIST.push_back({3,{2,3}});
    EDGELIST.push_back({1,{1,4}});
    EDGELIST.push_back({2,{1,2}});
    EDGELIST.push_back({4,{1,5}});
    EDGELIST.push_back({5,{3,4}});
    EDGELIST.push_back({8,{3,6}});

    VPairOfInt MSTLIST;

    int ans = findMstUsingUnionFind_KRUSKAL(MSTLIST,EDGELIST);

    cout << "Minimum Spanning Tree Wt =" << ans << endl;

    cout << "MST LIST :" << " [ " << endl;
    for(auto edge:MSTLIST)
    {
        cout << setw(15) << " { " << edge.first << " , " << edge.second  << " } "<< endl;
    }
    cout << setw(13) << " ] " << endl;
    return 0;
}
