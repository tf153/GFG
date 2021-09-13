/*
Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long countFriendsPairings(int n)
    {
        long dp[n + 1];
        int mod = 1000000007;
        for (int i = 0; i <= n; i++)
        {
            if (i < 3)
            {
                dp[i] = i;
                continue;
            }
            dp[i] = (dp[i - 1] % mod + ((i - 1) % mod) * (dp[i - 2] % mod)) % mod;
        }
        return dp[n] % mod;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}
// } Driver Code Ends