/*
Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int editDistance(string s, string t)
    {
        int n = s.length(), m = t.length();
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else
                {
                    if (s[i - 1] == t[j - 1])
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
            }
        }
        return dp[n][m];
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends