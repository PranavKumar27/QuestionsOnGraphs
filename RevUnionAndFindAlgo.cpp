#include <iostream>
#include <vector>

using namespace std;

/*
    Union and Find Algo is used to obtain the state of the Dynamic Grapj
    This can also be used for Cycle Detection in Constant Time
*/
class Disjoint
{
    int n;
    vector<int>parent;
    vector<int>ranking;
    vector<int>sizing;
public:
    Disjoint(int v)
    {
        n = v;
        parent.resize(n);
        ranking.resize(n,0);
        sizing.resize(n,1);
        populateParent();
    }
    void populateParent()
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    int findParent(int node)
    {
        if(parent[node]==node)
            return parent[node];

        int ultimate_parent = findParent(parent[node]);
        parent[node] = ultimate_parent;
        return ultimate_parent;
    }
    void unionByRank(int u,int v)
    {
        int ultimateParent_u = findParent(u);
        int ultimateParent_v = findParent(v);


        if(ultimateParent_u == ultimateParent_v)
        {
            cout << "Cycle Detected" << endl;
            return;
        }

        if(ranking[ultimateParent_u]>ranking[ultimateParent_v])
        {
            parent[ultimateParent_v] = ultimateParent_u;
        }
        else if(ranking[ultimateParent_u]<ranking[ultimateParent_v])
        {
            parent[ultimateParent_u] = ultimateParent_v;
        }
        else
        {
            parent[ultimateParent_v] = ultimateParent_u;
            ++ranking[ultimateParent_u];
        }
    }
    void unionBySize(int u,int v)
    {
        int ultimateParent_u = findParent(u);
        int ultimateParent_v = findParent(v);

        if(ultimateParent_u == ultimateParent_v)
        {
            cout << "Cycle Detected" << endl;
            return;
        }

        if(sizing[ultimateParent_u]<sizing[ultimateParent_v])
        {
            parent[ultimateParent_u] = ultimateParent_v;
            sizing[ultimateParent_v] += sizing[ultimateParent_u];
        }
        else if(sizing[ultimateParent_u]>=sizing[ultimateParent_v])
        {
            parent[ultimateParent_v] = ultimateParent_u;
            sizing[ultimateParent_u] += sizing[ultimateParent_v];
        }
    }
    bool validateDynamicGraph(int u,int v)
    {
        int ultimateParent_u = findParent(u);
        int ultimateParent_v = findParent(v);

        cout << "Parent of u=" << ultimateParent_u << endl;
        cout << "Parent of v=" << ultimateParent_v << endl;

        if(ultimateParent_u == ultimateParent_v)
            return true;
        else
            return false;
    }
    void printAll()
    {
        cout << "Parent -->" << endl;
        for(auto pp:parent)
            cout << pp << ",";
        cout << endl;

        cout << "Ranking -->" << endl;
        for(auto rr:ranking)
            cout << rr << ",";
        cout << endl;

        cout << "Sizing -->" << endl;
        for(auto ss:sizing)
            cout << ss << ",";
        cout << endl;

    }
};
int main()
{

    Disjoint d(8);
    d.printAll();
    cout << "<<<<<<<<<<<<<<<<<  Test using unionByRank  >>>>>>>>>>>>>>>>>>>" << endl;
    d.unionByRank(1,2);
    d.unionByRank(3,4);
    d.unionByRank(2,3);
    d.unionByRank(5,6);
    d.unionByRank(6,7);
    d.printAll();
    if(d.validateDynamicGraph(2,5))
    {
        cout << "2 and 5 Below to Same Set" << endl;
    }
    else
    {
        cout << "2 and 5 Below to Different Set" << endl;
    }
    d.unionByRank(4,7);

    d.printAll();
    if(d.validateDynamicGraph(2,5))
    {
        cout << "2 and 5 Below to Same Set" << endl;
    }
    else
    {
        cout << "2 and 5 Below to Different Set" << endl;
    }

    cout << "<<<<<<<<<<<<<<<<<<<<<<<<  Test using UnionBySize   >>>>>>>>>>>>>>>>>>>" << endl;

    // Test using UnionBySize

    Disjoint S(8);
    S.printAll();
    S.unionBySize(1,2);
    S.unionBySize(3,4);
    S.unionBySize(2,3);
    S.unionBySize(5,6);
    S.unionBySize(6,7);
    S.printAll();
    if(S.validateDynamicGraph(2,5))
    {
        cout << "2 and 5 Below to Same Set" << endl;
    }
    else
    {
        cout << "2 and 5 Below to Different Set" << endl;
    }
    S.unionBySize(4,7);

    S.printAll();
    if(S.validateDynamicGraph(2,5))
    {
        cout << "2 and 5 Below to Same Set" << endl;
    }
    else
    {
        cout << "2 and 5 Below to Different Set" << endl;
    }

    cout << "<<<<<<<<<<<<<<<<<<   Test for Cycle Detection in Constant Time    >>>>>>>>>>>>>>>>>>>>>>" << endl;

    // Test for Cycle Detection in Constant Time
    Disjoint C(3);
    C.unionBySize(0,1);
    C.unionBySize(1,2);
    C.unionBySize(2,0);
    if(C.validateDynamicGraph(0,2))
    {
        cout << "0 and 2 Below to Same Set" << endl;
    }
    else
    {
        cout << "0 and 2 Below to Different Set" << endl;
    }

    return 0;
}

