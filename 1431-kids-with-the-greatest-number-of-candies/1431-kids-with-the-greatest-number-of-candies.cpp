class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int e) {
        int maxi=*max_element(c.begin(), c.end());
        vector<bool>ans;
        for(int i: c)
        {
            if(i+e>=maxi) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};