#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[5][5] = {
                        {1,1,0,0,0},
                        {0,1,0,0,1},
                        {1,0,0,1,1},
                        {0,0,0,0,0},
                        {1,0,1,1,0}
                    };

void bfs(vector<vector<int>>& visited,int i,int j)
{
    visited[i][j]=1;
    int sz = visited.size();
    pair<int,int> p={i,j};
    queue<pair<int,int>> q;
    q.push(p);

    while(!q.empty())
    {
        pair<int,int> edge = q.front();
        int row = edge.first;
        int col = edge.second;
        q.pop();

        // Insert All Adjacent Nodes from 8 directions in the queue
        for(int row_delta=row-1;row_delta<=row+1;row_delta++)
        {
            for(int col_delta=col-1;col_delta<=col+1;col_delta++)
            {
                if(row_delta>=0 && row_delta<sz && col_delta>=0 && col_delta<sz &&
                    visited[row_delta][col_delta]==0 && arr[row_delta][col_delta]==1)
                {
                    pair<int,int>s = {row_delta,col_delta};
                    visited[row_delta][col_delta]=1;
                    q.push(s);
                }
            }
        }
    }
}

int main()
{
    int n=5;
    int m=5;

    vector<vector<int>> visited;
    vector<int>v{0,0,0,0,0};
    visited.resize(m,v);

    int cnt = 1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j]==0 && arr[i][j]==1)
            {
                bfs(visited,i,j);
                cnt++;
            }
        }
    }

    cout << "Number of Islands =" << cnt << endl;
    return 0;
}
