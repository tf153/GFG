// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n);

// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    void solve(vector<string> &ans, string str, int o, int c)
    {
        if (o == 0 and c == 0)
        {
            ans.push_back(str);
            return;
        }
        if (o != 0)
        {
            solve(ans, str + '(', o - 1, c);
        }
        if (o < c)
        {
            solve(ans, str + ')', o, c - 1);
        }
    }

public:
    vector<string> AllParenthesis(int n)
    {
        vector<string> ans;
        string str;
        solve(ans, str, n, n);
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
        int n;
        cin >> n;
        Solution ob;
        vector<string> result = ob.AllParenthesis(n);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << "\n";
    }
    return 0;
}
// } Driver Code Ends