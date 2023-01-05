class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<pair<int, int>>ans;
        ans.push_back({points[0][0], points[0][1]});
        for(int i=1; i<points.size(); i++)
        {
            if(points[i][0] <= ans.back().second && points[i][0] >= ans.back().first) 
            {
                ans.back().second = min(ans.back().second, points[i][1]);
            }
            else ans.push_back({points[i][0], points[i][1]});
        }
        return ans.size();
    }
};