class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)       {
        int n = nums1.size(), m = nums2.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
        minh.push({nums1[0]+nums2[0], 0, 0});
        vector<vector<int>> ans;
        set<pair<int, int>> vis;
        vis.insert({0, 0});
        while(k-- && !minh.empty()) {
            auto it = minh.top();
            minh.pop();
            ans.push_back({nums1[it[1]], nums2[it[2]]});
            if( ((it[1]+1) < n) && (vis.find({it[1]+1, it[2]}) == vis.end()) ) {
                minh.push({nums1[it[1]+1] +nums2[it[2]], it[1]+1, it[2]});
                vis.insert({it[1]+1, it[2]});
            }
            if( (it[2]+1 < m) && (vis.find({it[1], it[2]+1}) == vis.end()) ) {
                minh.push({nums1[it[1]] +nums2[it[2]+1], it[1], it[2]+1});
                vis.insert({it[1], it[2]+1});
            }
        }
        return ans;
    }
};