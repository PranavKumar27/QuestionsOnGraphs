#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>> & visited,vector<vector<int>>& Gph,int row,int col) ;
int countNumberOfIslandsUsingDFS(vector<vector<int>>& Gph,vector<vector<int>>& visited);

int main()
{
    int n = 5;
    vector<vector<int>> Gph;
    Gph.resize(n);

    Gph = {{1,1,0,1,1},{0,1,0,0,0},{1,1,0,0,0},{0,0,0,1,0},{0,0,1,1,0}};


    vector<vector<int>> visited;
    visited.resize(n);
    for(auto x=0;x<n;x++)
    {
        visited[x]={0,0,0,0,0};
    }


    int res = countNumberOfIslandsUsingDFS(Gph,visited);

    cout << "Count of Number of Islands =" << res << endl;

    return 0;
}

int countNumberOfIslandsUsingDFS(vector<vector<int>>& Gph,vector<vector<int>>& visited)
{
    int cnt =0 ;
    int m=Gph.size();
    int n=Gph[0].size();
    for(int i=0;i<m;i++ )
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j]==0 && Gph[i][j]==1)
            {
                dfs(visited,Gph,i,j);
                cnt++;
            }
        }
    }
    return cnt;
}

void dfs(vector<vector<int>> & visited,vector<vector<int>>& Gph,int row,int col)
{
    int m=Gph.size();
    int n=Gph[0].size();
    visited[row][col]=1;
    for(int delrow=-1;delrow<=1;delrow++)
    {
        for(int delcol=-1;delcol<=1;delcol++)
        {
            int updatedrow = row+delrow;
            int updatedcol = col+delcol;

            if(updatedrow>=0 && updatedrow<m &&
                updatedcol>=0 && updatedcol<n &&
                visited[updatedrow][updatedcol]==0 &&
                Gph[updatedrow][updatedcol]==1)
                {
                    dfs(visited,Gph,updatedrow,updatedcol);
                }
        }
    }
}
