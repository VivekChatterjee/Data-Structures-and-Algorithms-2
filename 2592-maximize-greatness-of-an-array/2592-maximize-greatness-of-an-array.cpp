class Solution {
public:
    int maximizeGreatness(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> m;
        for (int i : nums)
            m[i]++;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            auto it = m.upper_bound(nums[i]);
            if (it != m.end())
            {
                (*it).second--;
                if ((*it).second == 0)
                {
                    m.erase((*it).first);
                }
                ans++;
            }
        }
        return ans;
    }
};