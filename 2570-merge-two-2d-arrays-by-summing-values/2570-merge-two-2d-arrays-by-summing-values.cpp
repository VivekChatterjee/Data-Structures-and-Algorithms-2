#define vvi vector<vector<int>>
#define pb push_back
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> m;
        set<int> ids;
        for (auto i : nums1)
        {
            m[i[0]] += i[1];
        }
        for (auto i : nums2)
        {
            m[i[0]] += i[1];
        }
        vvi ans;
        for (auto it : m)
        {
            ans.pb({it.first, it.second});
        }
        return ans;
    }
};