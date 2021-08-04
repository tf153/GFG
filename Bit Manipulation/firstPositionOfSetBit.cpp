// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findPosition(int N)
    {
        if (N == 0)
            return -1;
        if (__builtin_popcount(N) > 1)
            return -1;
        return __builtin_ctz(N) + 1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
} // } Driver Code Ends