#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

#define INF INT_MAX

/*
    Floyd Warshall Algo finds the shortest distance
    from each node to every other node
    This works for Directed Graph
    Also a Negative Cycle is detected if Gph[i][i]<-1
*/

void print_2DV(vector<vector<int>> V)
{
    int n = V.size();
    for(int i=0;i<n;i++)
    {
        cout << "{  ";
        for(int j=0;j<n;j++)
        {
            if(V[i][j]==INF)
                cout << setw(5) << "INF" << "\t";
            else
                cout << setw(5) << V[i][j] << "\t";
        }

        cout << "  }" << endl;
    }
}

int main()
{

    vector<vector<int>> dist = {
                                {0,3,INF,INF},
                                {3,0,1,4},
                                {INF,1,0,1},
                                {INF,4,1,0}
                                };


    int n = dist.size();

    cout << "n=" << n << endl;

    for(int k=0;k<n;k++)
    {

        cout << "For k=" << k << endl;
        print_2DV(dist);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << "i=" << i << " j=" << j << endl;
                cout << "dist[i][k] =" << dist[i][k] << endl;
                cout << "dist[k][j] =" << dist[k][j] << endl;
                cout << "dist[i][j] =" << dist[i][j] << endl;

                if(dist[i][k]==INF || dist[k][j]==INF)
                {
                    continue;
                }
                else if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    cout << "Before dist[i][j]=" << dist[i][j] << endl;
                    dist[i][j] = dist[i][k]+dist[k][j];
                    cout << "After dist[i][j]=" << dist[i][j] << endl;
                }
            }
        }
        cout << "At end of K" << k << endl;
        print_2DV(dist);
    }

    cout << "Ans:" << endl;
    print_2DV(dist);

    return 0;
}


