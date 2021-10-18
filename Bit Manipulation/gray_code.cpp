// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<string> graycode(int n)
    {
        vector<string> ans;
        if (n >= 1)
        {
            ans.push_back("0");
            ans.push_back("1");
        }
        for (int i = 1; i < n; i++)
        {
            int size = ans.size();
            for (int j = size - 1; j >= 0; j--)
            {
                ans.push_back("1" + ans[j]);
            }
            for (int j = 0; j < size; j++)
            {
                ans[j] = "0" + ans[j];
            }
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
        int n;
        cin >> n;

        Solution ob;
        vector<string> ans = ob.graycode(n);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << "\n";
    }
}

// } Driver Code Ends