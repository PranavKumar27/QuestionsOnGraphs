#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <iomanip>

using namespace std;

#define INF INT_MAX
typedef pair<int,int> PairOfInt; // {row,col}
typedef pair<int,PairOfInt> PairOfPairOfInt; // wt,{row,col}

int bfs(vector<vector<int>> Gph,pair<int,int> src,pair<int,int> dest)
{
    cout << __FUNCTION__ << endl;
    queue<PairOfPairOfInt> q; //Priority Queue

    int ans = INF;
    int m = Gph.size();
    int n = Gph[1].size();
    vector<vector<int>> distances(m,vector<int>(n,INF));

    cout << "m=" << m <<  "  n=" << n << endl;
    //dist of src = 0;
    q.push({0,{src}});

    distances[src.first][src.second] = 0;



    while(!q.empty())
    {
        int wt = q.front().first;
        pair<int,int> node = q.front().second;
        q.pop();
        int row = node.first;
        int col = node.second;
        int new_wt = wt + 1;

        cout << "row=" << row << " col=" << col << " wt=" << wt << endl;

        if(row==dest.first && col== dest.second && Gph[row][col]==1)
        {
            cout << "Found Shortest Distance" << endl;
            ans = wt;
            break;
        }

        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            if(nrow>=0 && nrow<m &&
               ncol>=0 && ncol<n &&
               distances[nrow][ncol]>wt+1 && ans>new_wt)
            {
                q.push({new_wt,{nrow,ncol}});
                distances[nrow][ncol]=new_wt;
                cout << " -- nrow=" << nrow << " ncol=" << ncol << " wt=" << new_wt << endl;
            }
        }
    }

    for(int i =0 ;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(distances[i][j] == INF)
                cout << setw(10) << "INF" << " , ";
            else
                cout << setw(10) << distances[i][j] << " , ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Shortest Distance ans =" << ans << endl;

    if(ans==INF)
        return -1;
    else
        return ans;
}

int main()
{
    int m = 5;
    int n = 4;
    vector<vector<int>> Gph={
                                {1,1,1,1},
                                {1,1,0,1},
                                {1,1,1,1},
                                {1,1,0,0},
                                {1,0,0,1}
                            };

    pair<int,int> src = {0,1};
    pair<int,int> dest = {2,2};


    int dist = bfs(Gph,src,dest);

    cout << "dist =" << dist << endl;

    return 0;
}
