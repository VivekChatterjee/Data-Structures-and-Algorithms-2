class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=-1;
        unordered_map<int, int>m;
        for(int i: nums) m[i]++;
        for(auto i: m) if(i.second==1) ans=i.first;
        return ans;
    }
};