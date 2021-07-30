// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        int n = nums.size();
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            temp ^= nums[i];
        }
        int setBit = 1;
        while (temp)
        {
            if (temp & 1)
                break;
            setBit <<= 1;
            temp >>= 1;
        }
        int num1 = 0, num2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] & setBit)
            {
                num1 ^= nums[i];
            }
            else
            {
                num2 ^= nums[i];
            }
        }
        vector<int> vec;
        if (num1 < num2)
        {
            vec.push_back(num1);
            vec.push_back(num2);
        }
        else
        {
            vec.push_back(num2);
            vec.push_back(num1);
        }
        return vec;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(2 * n + 2);
        for (int i = 0; i < 2 * n + 2; i++)
            cin >> v[i];
        Solution ob;
        vector<int> ans = ob.singleNumber(v);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends