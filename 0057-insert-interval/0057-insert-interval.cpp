class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newInt) {
        inter.push_back(newInt);
        sort(inter.begin(), inter.end());
        vector<vector<int>>ans;
        ans.push_back(inter[0]);
        int i=1;
        for(; i<inter.size(); i++)
        {
            if(inter[i][0]>ans.back()[1]) ans.push_back(inter[i]);
            else ans.back()[1]=max(ans.back()[1], inter[i][1]);
        }
        return ans;
    }
};