#include <iostream>
#include <vector>

using namespace std;

bool vh_vec(vector<char> &vh_v)
{
    int vv_s = (int)vh_v.size();
    for (int k = 0; k < vv_s-1; k++)
    {
        for (int l = k+1; l < vv_s; l++)
        {
            if (vh_v[k] == vh_v[l])
            {
                return false;
            }
        }
    }
    return true;
}

bool clean_mat(vector<vector<char>> &sub, int k, int l, int r, int c)
{
    vector<char> vh_v;
    for (int i = k; i < r; i++)
    {
        for (int j = l; j < c; j++)
        {
            if (sub[i][j] != '.')
            {
                vh_v.push_back(sub[i][j]);
            }
        }
    }
    return vh_vec(vh_v);
}

bool isValidSudoku(vector<vector<char>> &board)
{
    int size = (int)board.size();
    
    for (int i = 0; i < size; i+=3)
    {
        for (int j = 0; j < size; j+=3)
        {
            if (!clean_mat(board, i, j, i+3, j+3))
                return false;
        }
    }
    
    for (int j = 0; j < size; j++)
    {
        if (!clean_mat(board, j, 0, j+1, size))
            return false;

        if (!clean_mat(board, 0, j, size, j+1))
            return false;
    }
    return true;
}

int main(void)
{
    vector<vector<char>> board = {{'.','.','.','.','5','.','.','1','.'}
                                ,{'.','4','.','3','.','.','.','.','.'}
                                ,{'.','.','.','.','.','3','.','.','1'}
                                ,{'8','.','.','.','.','.','.','2','.'}
                                ,{'.','.','2','.','7','.','.','.','.'}
                                ,{'.','1','5','.','.','.','.','.','.'}
                                ,{'.','.','.','.','.','2','.','.','.'}
                                ,{'.','2','.','9','.','.','.','.','.'}
                                ,{'.','.','4','.','.','.','.','.','.'}};
    bool val = isValidSudoku(board);
    cout<<val<<endl;
    return 0;
}