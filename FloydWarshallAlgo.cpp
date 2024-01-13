#include <iostream>
#include <limits.h>

// Find the Shortest Path from each pair

using namespace std;
#define n 4

void print_arr(int arr[n][n])
{
    cout << "---------------------------" <<  endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "---------------------------" <<  endl;
}

void floydWarshallAlgo(int arr[n][n])
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][k]==INT_MAX)
                {
                    // No changes
                }
                else if(arr[k][j]==INT_MAX)
                {
                    // No changes
                }
                else if(arr[i][k]+arr[k][j] < arr[i][j])
                {
                    arr[i][j] = arr[i][k]+arr[k][j];
                }
            }
        }
    }
}

int main()
{
    int arr[n][n] = { {0,3,INT_MAX,7},
                      {8,0,2,INT_MAX},
                      {5,INT_MAX,0,1},
                      {2,INT_MAX,INT_MAX,0}
                    };

    floydWarshallAlgo(arr);

    cout << "Floyd Warshall Result Array/ Shortest Pair Matrix" << endl;
    print_arr(arr);

    return 0;
}
