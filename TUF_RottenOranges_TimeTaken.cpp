#include <iostream>
#include <vector>
#include <queue>

enum Oranages{Empty=0,Good,Rotten};

using namespace std;

struct AllData{
    int row;
    int col;
    int time;
};

void bfs(vector<vector<int>>& cart,vector<vector<int>>& visited,int & totalTime);

void print_2D_vector(vector<vector<int>> Gph)
{
    int m = Gph.size();
    int n= Gph[0].size();

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << Gph[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> Cart;
    Cart.resize(n);
    Cart = {{1,0,1,2},{1,0,1,1},{1,0,1,1},{2,0,1,1}};
    vector<vector<int>> visited;
    visited.resize(n);
    visited = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    int totalTime = 0;
    cout << "Before Bfs " << endl;
    print_2D_vector(Cart);
    bfs(Cart,visited,totalTime);
    cout << "After Bfs " << endl;
    print_2D_vector(Cart);

    cout << "Total Time to rot all Oranges =" << totalTime << endl;
    return 0;
}

void bfs(vector<vector<int>>& cart,vector<vector<int>>& visited,int & totalTime)
{
    int m= cart.size();
    int n= cart[0].size();


    queue<AllData> q;

    int AtTime = 0;
    for(int i =0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cart[i][j]==Rotten) // Equals 2
            {
                AllData a({i,j,AtTime});
                q.push(a);
                visited[i][j] = 1;
            }
        }
    }
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};

    while(!q.empty())
    {
        AllData a(q.front());
        q.pop();
        cout << "row =" << a.row << " col=" << a.col << " At Time=" << a.time << endl;
        AtTime = a.time;
        totalTime = AtTime;
        cout << "At Time t = " << totalTime << endl;
        print_2D_vector(cart);
        for(int i =0;i<4;i++)
        {
            int updatedrow = a.row + delrow[i];
            int updatedcol = a.col + delcol[i];

            if(updatedrow >= 0 && updatedrow < m &&
                updatedcol >=0 && updatedcol < n &&
                visited[updatedrow][updatedcol]==0 &&
                cart[updatedrow][updatedcol]==Good ) // 1 means Good Oranges
            {
                cart[updatedrow][updatedcol] = Rotten;
                AllData a({updatedrow,updatedcol,AtTime+1});
                q.push(a);
            }
        }
    }


}
