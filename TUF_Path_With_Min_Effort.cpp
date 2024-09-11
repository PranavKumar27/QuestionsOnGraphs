#include <iostream>
#include <climits>
#include <vector>
#include <queue>

#define INF INT_MAX

using namespace std;

typedef pair<int,int> PairOfInt;
typedef pair<int,PairOfInt> PairOfIntOfInt;

int bfs(vector<vector<int>>& Matrix,PairOfInt src, PairOfInt dest);

int main()
{
    vector<vector<int>> Matrix = { {1,2,2},{3,8,2},{5,3,5} };

    PairOfInt src = {0,0};
    PairOfInt dest = {2,2};

    int ans = bfs(Matrix,src,dest);

    cout << "Path with Min Effort difference in weights : " << ans << endl;
    return 0;
}

int bfs(vector<vector<int>>& Matrix,PairOfInt src, PairOfInt dest)
{
    int m= Matrix.size();
    int n = Matrix[0].size();

    priority_queue< PairOfIntOfInt ,
                    vector< PairOfIntOfInt >,
                    greater< PairOfIntOfInt > > q;
    vector<vector<int>> Dist(m,vector<int>(n,INF));
    q.push({0,{src}});
    Dist[src.first][src.second] = 0;
    //int diff = 100;
    while(!q.empty())
    {
        PairOfIntOfInt p = q.top();
        q.pop();

        int dist = p.first;
        PairOfInt node = p.second;
        int row = node.first;
        int col = node.second;

        cout << " row=" << row << " col=" << col << " dist=" << dist << endl;
        if(row==dest.first && col==dest.second)
        {
            return dist;
        }

        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            cout << " nrow=" << nrow << " ncol=" << ncol << endl;
            if(nrow>=0 && nrow<m &&
               ncol>=0 && ncol<n)
               {
                   int diff = abs(Matrix[row][col] - Matrix[nrow][ncol]);
                   cout << "Absolute diff =" << diff << endl;
                   int newDist = (diff>dist)?diff:dist; // Find Max Dist
                   if(Dist[nrow][ncol]>newDist) // Update with Min Effort
                   {
                       cout << "Updated Distance Array dist=" << newDist << endl;
                       Dist[nrow][ncol] = newDist;
                       q.push({newDist,{nrow,ncol}});
                       cout << "Pushed a New Data [ " << newDist << " , { " << nrow << " , " << ncol << " } ]"<< endl;
                   }
               }
        }
    }
    return -1;
}
