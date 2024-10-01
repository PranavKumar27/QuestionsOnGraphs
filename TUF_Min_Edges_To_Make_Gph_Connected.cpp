#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VofInt;
typedef vector<pair<int,int>> VofPairOfInt;

class Union_Set
{
  int n;
  VofInt parent;
  VofInt sizes;

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
          sizes.resize(n,1);
      }
      int findParent(int node)
      {
          if(node == parent[node])
            return node;
          else
            return parent[node]=findParent(parent[node]);
      }
      void union_by_size(int u,int v)
      {
          int ult_p_u = findParent(u);
          int ult_p_v = findParent(v);

          if(ult_p_u == ult_p_v)
          {
              cout << "Edge Repeating/ Loop Present" << endl;
              return;
          }
          if(sizes[ult_p_u]>=sizes[ult_p_v])
          {
              sizes[ult_p_u] += sizes[ult_p_v];
              parent[ult_p_v] = parent[ult_p_u];
          }
          else
          {
              sizes[ult_p_v] += sizes[ult_p_u];
              parent[ult_p_u] = parent[ult_p_v];
          }
      }
      bool IsBelongingToSameSet(int u,int v)
      {
          if(findParent(u)==findParent(v))
            return true;
          else
            return false;
      }
      int NoOfComponentsInGph()
      {
          int noOfComponents = 0;
          for(int i=0;i<n;i++)
          {
            if(parent[i]==i)
            {
                noOfComponents++;
            }
          }
            return noOfComponents;
      }
};

int MinEdgesToMakeGphConnected(int n,VofPairOfInt EdgeList)
{
    Union_Set S(n);
    int extraEdges = 0;
    for(auto edgePair:EdgeList)
    {
        int u = edgePair.first;
        int v = edgePair.second;

        if(S.IsBelongingToSameSet(u,v))
        {
            // It means u and v are connected
            extraEdges++;
        }
        else
        {
            S.union_by_size(u,v);
        }
    }

    // count Number of sub Graph/ Components of Gph
    int noOfComponents = S.NoOfComponentsInGph();
    cout << "noOfComponents=" << noOfComponents << endl;

    cout << "extraEdges=" << extraEdges << endl;

    if(extraEdges>=(noOfComponents-1))
        return (noOfComponents-1);
    else
        return -1;
}
int main()
{
    int n = 10;

    VofPairOfInt EdgeList;
    EdgeList.push_back({0,1});
    EdgeList.push_back({0,2});
    EdgeList.push_back({1,2});
    EdgeList.push_back({1,3});
    EdgeList.push_back({2,3});

    EdgeList.push_back({4,5});
    EdgeList.push_back({4,6});
    EdgeList.push_back({5,6});

    EdgeList.push_back({7,8});
    EdgeList.push_back({9,8});
    EdgeList.push_back({9,7});

    int res = MinEdgesToMakeGphConnected(n,EdgeList);

    cout << "Min Edges To Make Gph Connected : " << res << endl;
    return 0;
}
