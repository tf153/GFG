/*
Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move

to the cell diagonally up towards the right 
to the right
to the cell diagonally down towards the right
Find out maximum amount of gold which he can collect.
*/
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int r = M.size();
        int c = M[0].size();
        int dp[r + 2][c];
        for (int i = 0; i < c; i++)
            dp[0][i] = dp[r + 1][i] = 0;
        for (int i = 1; i <= r; i++)
            dp[i][c - 1] = M[i - 1][c - 1];
        for (int j = c - 2; j >= 0; j--)
        {
            for (int i = 1; i <= r; i++)
            {
                dp[i][j] = max(dp[i][j + 1], max(dp[i - 1][j + 1], dp[i + 1][j + 1])) + M[i - 1][j];
            }
        }
        int ans = dp[1][0];
        for (int i = 2; i <= r; i++)
        {
            ans = max(ans, dp[i][0]);
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
        }

        Solution ob;
        cout << ob.maxGold(n, m, M) << "\n";
    }
    return 0;
} // } Driver Code Ends