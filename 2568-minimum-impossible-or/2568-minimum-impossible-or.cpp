#define ll long long
class Solution {
public:
    int minImpossibleOR(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i : nums)
            m[i]++;
        int i = 0;
        while (1)
        {
            ll num = 1 << i;
            if (!m.count(num))
                return num;
            i++;
        }
        return -1;
    }
};