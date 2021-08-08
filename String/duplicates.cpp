class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        map<int, int> mp;
        for (int a : nums)
        {
            mp[a]++;
        }
        vector<int> ans;
        for (pair<int, int> p : mp)
        {
            if (p.second > 1)
                ans.push_back(p.first);
        }
        return ans;
    }
};