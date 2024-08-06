#include <iostream>
#include <vector>
#include <queue>
#define Four 4
#define N 3
#define M 3

// Problem: Find the dist to the nearest one from a node
// Dist of 1 to nearest 1 is 0
// Distance of Nearest 1 from 0 is number of hops to the nearest 1 present

using namespace std;

void print2DVector(vector<vector<int>> v)
{
    int m = v.size();
    int n = v[0].size();

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << v[i][j] << "\t";
        }
        cout << endl;
    }

}

void bfs(vector<vector<int>>& Gph, vector<vector<int>>& visited, vector<vector<int>>& Dist)
{
    queue<pair<pair<int,int>,int>> q;

    // Find 1 in Gph
    int m = Gph.size();
    int n = Gph[0].size();

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(Gph[i][j]==1)
            {
                q.push({{i,j},0});
                visited[i][j]=1;
            }
        }
    }

    vector<int> delrow = {-1,0,1,0};
    vector<int> delcol = {0,1,0,-1};
    while(!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int d = q.front().second;
        Dist[row][col] = d;

        q.pop();

        for(int i=0;i<Four;i++)
        {
            int updated_row = row+delrow[i];
            int updated_col = col+delcol[i];

            if(updated_row>=0 && updated_row<m &&
               updated_col>=0 && updated_col<n &&
               visited[updated_row][updated_col]==0 &&
               Gph[updated_row][updated_col] == 0)
            {
                q.push({{updated_row,updated_col},d+1});
                visited[updated_row][updated_col] = 1;
            }
        }
    }

}
int main()
{
    vector<vector<int>> Gph = {{0,0,0},{0,1,0},{1,0,0}};
    vector<vector<int>> visited(N,vector<int>(M,0));
    vector<vector<int>> Dist = {{0,0,0},{0,0,0},{0,0,0}};

    cout << "Before Gph =" << endl;
    print2DVector(Gph);
    cout << "Before visited =" << endl;
    print2DVector(visited);
    cout << "Before Dist =" << endl;
    print2DVector(Dist);

    bfs(Gph,visited,Dist);

    cout << "After Gph =" << endl;
    print2DVector(Gph);
    cout << "After visited =" << endl;
    print2DVector(visited);
    cout << "After Dist =" << endl;
    print2DVector(Dist);


    return 0;
}
