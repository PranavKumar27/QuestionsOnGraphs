#include <iostream>
#include <vector>
#define Num0 0

using namespace std;

void setAdjWithDefaults(vector<int> Adj[],int v)
{
    cout << __FUNCTION__ << endl;
    for(int i=Num0;i<v;i++)
    {
        for(int j=Num0;j<v;j++)
        {
            Adj[i].push_back(0);
        }
    }
}

void updateAdj(vector<int> Adj[],int row,int col)
{
   Adj[row][col] = 1;
}

void print_2D_v(vector<int> Array2D[])
{
    cout << __FUNCTION__ << endl;
    int sz =  Array2D[Num0].size();;
    for(int i=Num0;i<sz;i++)
    {
        for(int j=Num0;j<sz;j++)
        {
            cout  << Array2D[i][j] << "\t";
        }
        cout << endl;
    }
}

void findTranspose(vector<int> Adj[])
{
    int sz = Adj[Num0].size();
    vector<int> Transpose[sz];
    for(int i=Num0;i<sz;i++)
    {
        for(int j=Num0;j<sz;j++)
        {
            Transpose[i].push_back(Adj[j][i]);
        }
    }
    print_2D_v(Transpose);
}


int main()
{
    int v = 5; // No of Vertices
    vector<int> Adj[v];

    setAdjWithDefaults(Adj,v);

    updateAdj(Adj,0,1);
    updateAdj(Adj,0,3);
    updateAdj(Adj,2,0);
    updateAdj(Adj,3,2);
    updateAdj(Adj,4,1);
    updateAdj(Adj,4,3);

    print_2D_v(Adj);

    cout << "Transpose of Adj" << endl;
    findTranspose(Adj);

    return 0;
}
