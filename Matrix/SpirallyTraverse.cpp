#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int R, int C)
    {
        vector<int> ans;
        int t = 0, l = 0, r = C - 1, b = R - 1;
        bool fwd = true;
        while (t <= b && l <= r)
        {
            if (fwd)
            {
                for (int i = l; i <= r; i++)
                {
                    ans.push_back(matrix[t][i]);
                }
                t++;
            }
            if (fwd)
            {
                for (int i = t; i <= b; i++)
                {
                    ans.push_back(matrix[i][r]);
                }
                r--;
            }
            if (!fwd)
            {
                for (int i = r; i >= l; i--)
                {
                    ans.push_back(matrix[b][i]);
                }
                b--;
            }
            if (!fwd)
            {
                for (int i = b; i >= t; i--)
                {
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }
            fwd = !fwd;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends
l++;
}
fwd = !fwd;
}
return ans;