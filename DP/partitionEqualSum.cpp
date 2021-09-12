// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    bool solve(int arr[], int sum, int i)
    {
        if (sum == 0)
            return true;
        if (i < 0)
            return false;
        if (sum >= arr[i])
            return (solve(arr, sum - arr[i], i - 1) || solve(arr, sum, i - 1));
        else
            return solve(arr, sum, i - 1);
    }

public:
    int equalPartition(int N, int arr[])
    {
        int sum = accumulate(arr, arr + N, 0);
        if (sum & 1)
            return 0;
        sum >>= 1;
        return (solve(arr, sum, N - 1) ? 1 : 0);
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
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
} // } Driver Code Ends