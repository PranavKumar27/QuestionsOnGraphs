#include <iostream>
#include <vector>
#include <set>

using namespace std;

void print_vector(vector<pair<int,int>> V)
{
    for(auto data:V)
    {
        cout << "\t{ " << data.first << "\t" << data.second  << " }"<< endl;
    }
}

void dfs(vector<vector<int>>& Gph,int row, int col, vector<vector<int>> & visited ,vector<pair<int,int>> & V,int rowBase,int colBase)
{
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    visited[row][col]=1;
    int m = Gph.size();
    int n = Gph[0].size();

    //pair<int,int> src({row,col});

    for(int i=0;i<4;i++)
    {
        int updated_row = row+delrow[i];
        int updated_col = col+delcol[i];

        if(updated_row>=0 && updated_row<m &&
           updated_col>=0 && updated_col<n &&
           visited[updated_row][updated_col]==0 &&
           Gph[updated_row][updated_col]==1)
        {
            V.push_back({abs(row-rowBase),abs(col-colBase)});
            visited[updated_row][updated_col] = 1;
            dfs(Gph,updated_row,updated_col,visited,V,rowBase,colBase);
            //int rowdiff = abs(updated_row - src.first);
            //int coldiff = abs(updated_col - src.second);
            //V.push_back({rowdiff,coldiff});
        }
    }

}
int main()
{
    vector<vector<int>> Gph = {
                                {1,1,0,1,1},
                                {1,0,0,0,0},
                                {0,0,0,1,1},
                                {1,1,0,1,0}
                                };
    int m = Gph.size();
    int n = Gph[0].size();
    vector<vector<int>> visited(m,vector<int>(n,0));
    set<vector<pair<int,int>>> S;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            vector<pair<int,int>> V;
            if(Gph[i][j]==1 && visited[i][j]==0)
            {
                //V.push_back({i-i,j-j});
                int rowBase = i;
                int colBase = j;
                dfs(Gph,i,j,visited,V,rowBase,colBase); // rowBase and colBase are base node or starting node for dfs
                cout << "Vector Returned From Dfs" << endl;
                print_vector(V);
                S.insert(V);
                //V.clear();
            }
        }
    }

    cout << "Count of Number of Unique Lands =" << S.size() << endl;
    return 0;
}


