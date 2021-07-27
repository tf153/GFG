#include <bits/stdc++.h>
using namespace std;
bool solve(string &str, int k)
{
    int len = str.length();
    for (int i = k; i < len; i++)
    {
        if (str[i - k] != '?')
        {
            if (str[i] == '?')
            {
                str[i] = str[i - k];
            }
            else
            {
                if (str[i] != str[i - k])
                    return false;
            }
        }
    }
    for (int i = len - k - 1; i >= 0; i--)
    {
        if (str[i + k] == '?')
            return false;
        if (str[i] == '?')
        {
            str[i] = str[i + k];
        }
        else
        {
            if (str[i] != str[i + k])
                return false;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int k;
        cin >> k;
        cout << (solve(str, k) ? str : "-1") << endl;
    }
    return 0;
}