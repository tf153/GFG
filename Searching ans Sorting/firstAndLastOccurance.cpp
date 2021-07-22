// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n, int x);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        ans = find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends

vector<int> find(int arr[], int n, int x)
{
    vector<int> ans(2);
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            ans[0] = i;
            break;
        }
    }
    if (i == n)
    {
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == x)
        {
            ans[1] = i;
            break;
        }
    }
    return ans;
}