#include<iostream>
#include<vector>

using namespace std;

void print_2D_vector(vector<vector<int>> Gph);
void finalFloodFilled(vector<vector<int>>& Gph,vector<vector<int>>& Gph1,vector<vector<int>>& visited,int sr_row,int sr_col,
    int initialColor,int newColor,int delrow[],int delcol[]);

int main()
{
    vector<vector<int>> Gph;
    vector<vector<int>> visited;

    Gph= {{1,1,1},{2,2,0},{2,2,2}};
    visited ={{0,0,0},{0,0,0},{0,0,0}};

    vector<vector<int>> Gph1(Gph);
    int sr_row = 1;
    int sr_col = 1;

    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};

    // Flood Fill from starting node {sr_row,sr_col}
    // Flood Fill color 2 with color 3
    int to_be_coloured = 3;
    int initial_color = 2;

    cout << "Before Flood Fill" << endl;
    print_2D_vector(Gph);

    finalFloodFilled(Gph,Gph1,visited,sr_row,sr_col,initial_color,to_be_coloured,delrow,delcol);

    cout << "After Flood Fill" << endl;
    print_2D_vector(Gph1);
    return 0;
}

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
void finalFloodFilled(vector<vector<int>>& Gph,vector<vector<int>>& Gph1,vector<vector<int>>& visited,int sr_row,int sr_col,
    int initialColor,int newColor,int delrow[],int delcol[])
{
    int m = Gph.size();
    int n= Gph[0].size();
    visited[sr_row][sr_col]=1;

    if(Gph1[sr_row][sr_col] == initialColor)
        Gph1[sr_row][sr_col] = newColor;

    for(int i=0;i<4;i++)
    {
        int updated_row = sr_row+delrow[i];
        int updated_col = sr_col+delcol[i];

        if(updated_row>=0 && updated_row<m &&
            updated_col>=0 && updated_col<n &&
            Gph1[updated_row][updated_col]==initialColor &&
            visited[updated_row][updated_col]==0)
            {
                cout << "New Call updated_row=" << updated_row << " updated_col=" << updated_col << endl;
                //Gph1[updated_row][updated_col] = newColor;
                finalFloodFilled(Gph,Gph1,visited,updated_row,updated_col,initialColor,newColor,delrow,delcol);
            }
    }
}
