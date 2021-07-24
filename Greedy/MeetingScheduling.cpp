// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
private:
    static bool myComp(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        return p1.second < p2.second;
    }

public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
        {
            vp.push_back(make_pair(start[i], end[i]));
        }

        sort(vp.begin(), vp.end(), myComp);

        int e = vp[0].second, ans = 1;
        for (int i = 1; i < n; i++)
        {
            if (e < vp[i].first)
            {
                ans++;
                e = vp[i].second;
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
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
} // } Driver Code Ends