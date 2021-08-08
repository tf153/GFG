class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size(), col = matrix[0].size();
        int i, j;
        for (i = 0; i < row; i++)
        {
            if (target <= matrix[i][col - 1])
            {
                for (j = 0; j < col; j++)
                {
                    if (target < matrix[i][j])
                        return false;
                    if (target == matrix[i][j])
                        return true;
                }
            }
        }
        return false;
    }
};