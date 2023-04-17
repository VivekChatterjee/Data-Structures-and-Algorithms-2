class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int e) {
        int max=*max_element(c.begin(), c.end());
        vector<bool>ans;
        for(int i: c) ans.push_back(i+e>=max);
        return ans;
    }
};