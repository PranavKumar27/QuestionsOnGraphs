#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> & Gph, int row,int col,vector<vector<int>> & visited);
int main()
{
    vector<vector<int>> Gph ={
                            {0,0,0,1},
                            {0,1,1,0},
                            {0,1,1,0},
                            {0,0,0,1},
                            {0,1,1,0}
                            };
    int m = Gph.size();
    int n = Gph[0].size();
    vector<vector<int>> visited(m,vector<int>(n,0));

    for(int j=0;j<n;j++)   // First and Last Row
    {
        if(Gph[0][j] == 1 && visited[0][j] == 0)
        {
            bfs(Gph,0,j,visited);
        }
        else if(Gph[m-1][j] == 1 && visited[m-1][j] == 0)
        {
            bfs(Gph,m-1,j,visited);
        }
    }

    for(int i=0;i<m;i++) // First and Last Col
    {
        if(Gph[i][0] == 1 && visited[i][0] == 0)
        {
            bfs(Gph,i,0,visited);
        }
        else if(Gph[i][n-1] == 1 && visited[i][n-1] == 0)
        {
            bfs(Gph,i,n-1,visited);
        }
    }

    // count of Number of 1's which are not visited

    int cnt = 0;
    for(int i =0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j]==0 && Gph[i][j]==1)
            {
                cnt++;
                visited[i][j]=1;
            }
        }
    }

    cout << "Number of Lands Enclosed =" << cnt << endl;
    return 0;
}

void bfs(vector<vector<int>> & Gph, int row,int col,vector<vector<int>> & visited)
{
    int m = Gph.size();
    int n = Gph[0].size();
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    queue<pair<int,int>> q;

    q.push({row,col});
    visited[row][col]=1;

    while(!q.empty())
    {
        int nrow = q.front().first;
        int ncol = q.front().second;

        q.pop();

        for(int i=0;i<4;i++) // Movement in 4 directions
        {
            int updated_row = nrow+delrow[i];
            int updated_col = ncol+delcol[i];

            if(updated_row>=0 && updated_row<m &&
               updated_col>=0 && updated_col<n &&
               visited[updated_row][updated_col]==0 &&
               Gph[updated_row][updated_col]==1)
            {
                visited[updated_row][updated_col] = 1;
                q.push({updated_row,updated_col});
            }
        }
    }
}
