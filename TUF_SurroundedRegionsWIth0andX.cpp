#include <iostream>
#include <vector>

/* Find the 'O' surrounded by X on all sides
    For All such Groups of O Replace with X
    For All such Groups of O such that one of the O
    belongs on the boundary need not be replaced with 'X'
*/
using namespace std;

template<typename T>
void print2DVector(vector<vector<T>> v)
{
    int m = v.size();
    int n = v[0].size();

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << v[i][j] << "\t";
        }
        cout << endl;
    }

}

void dfs(vector<vector<char>>& Gph,int row,int col,vector<vector<int>> & visited)
{
    int m = Gph.size();
    int n = Gph[0].size();

    int del_row[] = {-1,0,1,0};
    int del_col[] = {0,1,0,-1};

    for(int i=0;i<4;i++)
    {
        int updated_row = row+del_row[i];
        int updated_col = col+del_col[i];

        if(updated_row>=0 && updated_row<m &&
           updated_row>=0 && updated_col<n &&
           visited[updated_row][updated_col]==0 &&
           Gph[updated_row][updated_col]=='0')
        {
            visited[updated_row][updated_col] = 1;
            dfs(Gph,updated_row,updated_col,visited);
        }
    }
}

int main()
{
    vector<vector<char>> Gph = {
                                {'X','X','X','X','X'},
                                {'X','0','0','X','0'},
                                {'X','X','0','X','0'},
                                {'X','0','X','0','X'},
                                {'0','0','X','X','X'}
                                };
    int m = Gph.size();
    int n = Gph[0].size();

    cout << "Before Processing Gph =" << endl;;
    print2DVector(Gph);

    vector<vector<int>> visited(m,vector<int>(n,0));

    for(int i=0;(i==0 || i==m-1) && i<m;i=i+m-1)
    {
        for(int j=0;j<n;j++)
        {
            if(Gph[i][j]=='0')
            {
                dfs(Gph,i,j,visited);
            }
        }
    }

    for(int i=0;(i==0 || i==n-1) && i<n;i=i+n-1)
    {
        for(int j=0;j<m;j++)
        {
            if(Gph[j][i]=='0')
            {
                dfs(Gph,j,i,visited);
            }
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j]==0 && Gph[i][j]=='0')
            {
                Gph[i][j]='X';
            }
        }
    }

    cout << "After Processing visited =" << endl;;
    print2DVector(visited);

    cout << "After Processing Gph =" << endl;;
    print2DVector(Gph);


    cout << "Hello world!" << endl;
    return 0;
}
