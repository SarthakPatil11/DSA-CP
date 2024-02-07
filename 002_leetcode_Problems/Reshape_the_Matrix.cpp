#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m = mat.size(), n = mat[0].size();
    int size_mat = m * n, size_new = r * c;
    if ((m == r && n == c) || (size_mat != size_new))
        return mat;
    
    vector<int> pre_ans;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pre_ans.push_back(mat[i][j]);
        }
    }
    
    vector<vector<int>> ans;
    int k = 0;
    // int nc = (m * n) / r;
    for (int i = 0; i < r; i++)
    {
        vector<int> temp;
        for (int j = 0; j < c; j++, k++)
        {
            temp.push_back(pre_ans[k]);
        }
        ans.push_back(temp);
    }

    return ans;
}

int main(void)
{
    vector<vector<int>> ans, mat = {{1,2},{3,4}};
    ans = matrixReshape(mat, 2, 4);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

/*
Description:
1. Check validity with size of given metrix (m * n) == reshaped matrix given size (r * c) if its not return original matrix.
2. Convert original matrix to single dimentional vector/ array.
3. Convert that single dimentional vector to given reshaped matrix size.
*/