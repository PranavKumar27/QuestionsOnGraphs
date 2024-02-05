#include <iostream>
#include <climits>
#include <vector>

#define INF INT_MAX
#define N 8

using namespace std;

int shortestPathDistance(int graph[N][N],vector<int>& path)
{
    int dist[N];
    dist[N-1]=0;
    int cheapestCostNode[N];

    cheapestCostNode[N-1]=N-1;
    for(int i=N-2;i>=0;i--)
    {
        dist[i]=INF;
        cheapestCostNode[i] = i;

        int min_j=i;
        for(int j=i;j<N;j++)
        {
            if(graph[i][j]!=INF && dist[i]>graph[i][j]+dist[j])
            {
                dist[i] = graph[i][j]+dist[j];
                min_j=j;
            }
        }
        cheapestCostNode[i] = min_j;
    }
    cout << "cheapestCostNode Generated:\t";
    for(int i=0;i<N;i++)
    {
        cout << cheapestCostNode[i] << "\t";
    }

    cout << endl;
    int node = cheapestCostNode[0];
    path.push_back(0); // Start Node is 0
    path.push_back(node); // Immediate Node is from cheapestCostNode[0]
    do
    {
        node = cheapestCostNode[node];
        path.push_back(node);

    }while(node!=N-1);


    return dist[0];
}

int main()
{
    int graph[N][N] =
        {{INF, 1, 2, 5, INF, INF, INF, INF},
       {INF, INF, INF, INF, 4, 11, INF, INF},
       {INF, INF, INF, INF, 9, 5, 16, INF},
       {INF, INF, INF, INF, INF, INF, 2, INF},
       {INF, INF, INF, INF, INF, INF, INF, 18},
       {INF, INF, INF, INF, INF, INF, INF, 13},
       {INF, INF, INF, INF, INF, INF, INF, 2},
      {INF, INF, INF, INF, INF, INF, INF, INF}};


    vector<int> path;
    int res = shortestPathDistance(graph,path);
    cout << "Shortest Distance  =     " << res << endl;

    cout << "Shortest Path :\t";
    for(auto ss:path)
        cout << ss << "\t";

    cout << endl;
    return 0;
}
