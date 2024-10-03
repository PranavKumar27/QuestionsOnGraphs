#include <iostream>
#include <vector>

using namespace std;

class Union_Set
{
    int n;
    vector<int> parent;
    vector<int> ranking;

public:
    Union_Set(){}
    Union_Set(int n)
    {
        n = this->n;
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        ranking.resize(n,0);
    }
    int findParent(int node)
    {
        if(node==parent[node])
            return node;
        else
            return parent[node] = findParent(parent[node]);
    }
    void union_by_rank(int u,int v)
    {
        int ult_p_u = findParent(u);
        int ult_p_v = findParent(v);

        if(ult_p_u!=ult_p_v)
        {
            if(ranking[ult_p_u]==ranking[ult_p_v])
            {
                ranking[ult_p_u] += 1;
                parent[ult_p_v] = ult_p_u;
            }
            else if(ranking[ult_p_u]>ranking[ult_p_v])
            {
                parent[ult_p_v] = parent[ult_p_u];
            }
            else
            {
                parent[ult_p_u] = parent[ult_p_v];
            }
        }
    }
};

vector<int> findNoOfIslands(vector<pair<int,int>> OnlineQueries,vector<vector<int>> IslandsAndSea, vector<vector<int>> visited)
{
    vector<int> res;
    int m = IslandsAndSea.size(); /// row
    int n = IslandsAndSea[0].size(); /// col

    int totalNodes = m*n;

    cout << "totalNodes = " << totalNodes << endl;
    Union_Set S(totalNodes);

    int currentIslandsCount = 0;

    for(auto query:OnlineQueries)
    {
        int u = query.first;
        int v = query.second;

        int currentNode = u*n + v;
        cout << "u= " << u << " v= " << v << " currentNode= " << currentNode << endl;

        if(!visited[u][v]) /// If not visited
        {
           visited[u][v] = 1;
           currentIslandsCount = currentIslandsCount+1;
           IslandsAndSea[u][v]=1;

           cout << "Node unvisited currentIslandsCount = " << currentIslandsCount << endl;

           // check for adjacent Nodes now

           vector<int> delrow = {-1,0,1,0};
           vector<int> delcol = {0,1,0,-1};

           for(int i=0;i<4;i++)
           {
               int n_row = u+delrow[i];
               int n_col = v+delcol[i];

               if(n_row>=0 && n_row<m && n_col>=0 && n_col<n)
               {
                   if(IslandsAndSea[n_row][n_col]==1)
                   {
                       int New_node = n_row*n + n_col;
                       int New_node_Parent = S.findParent(New_node);
                       int Current_Node_Parent = S.findParent(currentNode);

                       if(New_node_Parent!=Current_Node_Parent)
                       {
                           S.union_by_rank(currentNode,New_node);
                           currentIslandsCount = currentIslandsCount-1;
                           cout << "Updated currentIslandsCount = " << currentIslandsCount << endl;
                       }
                       else
                       {
                           cout << "Same Parent" << endl;
                       }

                   }
                   else
                   {

                   }
               }
           }

         cout << "Before Pushing in res currentIslandsCount = " << currentIslandsCount << endl;
         res.push_back(currentIslandsCount);
        }


    }

    return res;
}
int main()
{
    vector<pair<int,int>> OnlineQueries { {0,0},{0,0},{1,1},{1,0},{0,1},{0,3},{1,3},{0,4},{3,2},{2,2},{1,2},{0,2} };

    int row = 4;
    int col = 5;

    vector<vector<int>> IslandsAndSea(row,vector<int>(col,0));
    vector<vector<int>> visited(row,vector<int>(col,0));

    vector<int> res = findNoOfIslands(OnlineQueries,IslandsAndSea,visited);

    cout << "All Islands" << endl;
    for(auto d:res)
    {
        cout << "No Of Islands = " << d <<  endl;
    }

    return 0;
}
