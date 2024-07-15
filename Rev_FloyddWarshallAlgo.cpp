#include <iostream>
#include <vector>
#include <limits.h>
#include <iomanip>
#define N 4
#define INF INT_MAX%100000

using namespace std;

void print_2DV(int adj[][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << setw(5) << adj[i][j] << ",";
        }
        cout << endl;
    }
}

bool IsNegativeCycle(int adj[][N])
{
    for(int k=0;k<N;k++)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if( (adj[i][k]!=INF) && (adj[k][j]!=INF) &&
                   adj[i][j]>(adj[i][k]+adj[k][j]) )
                {
                    adj[i][j]=adj[i][k]+adj[k][j];
                }
            }
        }
    }

    print_2DV(adj);

    for(int i=0;i<N;i++)
    {
        if(adj[i][i]<0)
            return true;
    }
    return false;
}

int main()
{
    int arr[][N]={
                    {0,INF,2,3},
                    {-1,0,INF,1},
                    {INF,-2,0,INF},
                    {INF,INF,3,0}
                    };
    print_2DV(arr);
    bool res = IsNegativeCycle(arr);
    cout << "Is Negative Cycle Present=" << res  << endl;
    print_2DV(arr);

    return 0;
}
