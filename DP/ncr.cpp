// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int nCr(int n, int r)
    {
        if (r > n)
            return 0;
        if (n == r || r == 0)
            return 1;
        if (r == 1 || n - 1 == r)
            return n;
        int dp[n + 1][n + 1];
        int mod = 1000000007;
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = dp[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod) % mod;
            }
        }
        return dp[n][r];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
} // } Driver Code Ends