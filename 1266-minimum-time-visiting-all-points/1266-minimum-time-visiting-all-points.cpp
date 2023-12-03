class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int ans=0;
        for(int i=1; i<p.size(); i++)
        {
            ans+=max(abs(p[i][1]-p[i-1][1]), abs(p[i][0]-p[i-1][0]));
        }
        return ans;
    }
};