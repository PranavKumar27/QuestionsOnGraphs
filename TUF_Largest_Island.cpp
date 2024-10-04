#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

class union_Set
{
    public:

    int n;
    vector<int> parent;
    vector<int> sizes;


    union_Set(){}
    union_Set(int v)
    {
        n = v+1;
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
        {
            return node;
        }
        else
        {
            return parent[node] = findParent(parent[node]);
        }
    }
    void union_by_size(int u,int v)
    {
        int ult_p_u = findParent(u);
        int ult_p_v = findParent(v);

        if(ult_p_u != ult_p_v)
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

void print_v(vector<int> data)
{
    cout << "[ ";
    for(auto d:data)
    {
        cout << d << ",";
    }
    cout << " ]\n";
}

bool IsValid(int r,int c,int row_sz,int col_sz)
{
    if(r>=0 && r<row_sz && c>=0 && c<col_sz)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*
                                        {1,0,1,1,1},
                                        {1,1,0,1,1},
                                        {1,1,0,0,1},
                                        {0,0,1,1,0},
                                        {1,1,1,1,1}

                                        {
                                            {1,1},
                                            {1,1}
                                        }
*/
int main()
{
    vector<vector<int>> IslandsNSea = {
                                        {1,1,0,1,1},
                                        {1,1,0,1,1},
                                        {1,1,0,1,1},
                                        {0,0,1,1,1},
                                        {0,0,1,1,1}
                                       };


    int row = IslandsNSea.size();
    int col = IslandsNSea.size();

    vector<vector<int>> visited(row,vector<int>(col,0));

    union_Set S(row*col);

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            int current_node = i*row + j;
            if(!visited[i][j] && IslandsNSea[i][j]==1)
            {
                visited[i][j]=1;
                vector<int> delrow = {-1,0,1,0};
                vector<int> delcol = {0,1,0,-1};

                for(int c=0;c<4;c++)
                {
                    int n_row = i+delrow[c];
                    int n_col = j+delcol[c];

                    if(IsValid(n_row,n_col,row,col) && !visited[n_row][n_col]&& IslandsNSea[n_row][n_col]==1)
                    {
                        //visited[n_row][n_col]=1;
                        int connected_node = n_row*row+n_col;

                        if(S.findParent(current_node)!=S.findParent(connected_node))
                        {
                            S.union_by_size(current_node,connected_node);
                        }

                    }
                }
            }
        }
    }

    print_v(S.parent);
    print_v(S.sizes);

    int Total_max = INT_MIN;
    int Final_node;
    bool NoWater = false;

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(!visited[i][j] && IslandsNSea[i][j]==0)
            {
                 set<int> Set; // Parent and Node
                 visited[i][j]=1;
                 vector<int> delrow = {-1,0,1,0};
                 vector<int> delcol = {0,1,0,-1};

                 for(int c=0;c<4;c++)
                 {
                     int n_row = i+delrow[c];
                     int n_col = j+delcol[c];
                     if(IsValid(n_row,n_col,row,col) && IslandsNSea[n_row][n_col]==1)
                     {
                        int connected_node = n_row*row+n_col;
                        int p2 = S.findParent(connected_node);
                        NoWater = true;
                        Set.insert(p2);

                        cout << "inserting in Set row =" << n_row << " col=" << n_col << " connected_node=" << connected_node << endl;


                     }
                 }
                 // find Size
                 int node;
                 int max_Island = 1;

                 cout  << "Size of Set =" << Set.size() << endl;
                 cout  << "Total_max =" << Total_max << endl;
                 while(!Set.empty())
                 {
                     auto itr = Set.begin();
                     int  par = *itr;
                    //node = par.second; /// Node
                     int p = par; /// Parent

                     cout << "Parent=" << p << " node =" << node << endl;
                     int ult_p = S.findParent(p);
                     int ult_p_sz = S.sizes[ult_p];

                     cout << "size=" << ult_p_sz << endl;
                     max_Island+=ult_p_sz;
                     Set.erase(itr);

                 }

                 if(Total_max<max_Island)
                 {
                     Total_max = max_Island;
                     Final_node = node;
                 }
            }
            else if(!NoWater)
            {
                Total_max = S.sizes[0];
            }
        }
    }


    cout << "MaxIslands = " << Total_max << endl;
    cout << "Node to be modified = " << Final_node <<  endl;
    cout << "row =" << Final_node/row << " col=" << Final_node%row;
    return 0;
}
