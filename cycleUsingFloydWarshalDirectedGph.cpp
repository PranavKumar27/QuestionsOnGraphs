#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define N 4
#define INF INT_MAX

void floydWarshallAlgo(int Graph[N][N])
{
    for(int k=0;k<N;k++)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(Graph[i][k]==INF)
                {
                    // No changes;
                }
                else if(Graph[k][j]==INF)
                {
                    // No changes;
                }
                else if(Graph[i][j]>Graph[i][k]+Graph[k][j])
                {
                    Graph[i][j] = Graph[i][k]+Graph[k][j];
                }
            }
        }
    }
}

void print_Graph(int Graph[N][N])
{
   for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << Graph[i][j] << "\t";
        }
        cout << endl;
    }
}

bool detectNegCycle(int Graph[N][N])
{
    floydWarshallAlgo(Graph);

    for(int i=0;i<N;i++)
    {
        if(Graph[i][i] < 0)
            return true;
    }
    return false;
}
int main()
{
    int Graph[N][N] = {
                        {0,-1,INF,INF},
                        {INF,0,1,INF},
                        {INF,INF,0,-1},
                        {-1,INF,INF,0}
                    };


    floydWarshallAlgo(Graph);
    print_Graph(Graph);
    bool res = detectNegCycle(Graph);
    cout << "Is Negative Cycle Present in Graph=" << res << endl;

    return 0;
}

