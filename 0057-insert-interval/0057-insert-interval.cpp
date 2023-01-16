class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newInt) {
        int n=inter.size();
        bool took=0;
        int i=0;
        for(; i<n; i++)
        {
            if(!took && inter[i][0]>newInt[1])
            {
                inter.insert(inter.begin()+i, newInt);
                took=1;
                break;
            }
            else if(!took && ((newInt[0]>=inter[i][0] && newInt[0]<=inter[i][1]) 
                              || (inter[i][1]>=newInt[0] && inter[i][1]<=newInt[1])))
            {
                inter[i][0]=min(inter[i][0], newInt[0]);
                inter[i][1]=max(inter[i][1], newInt[1]);
                took=1;
                break;
            }
        }
        if(!took) inter.push_back(newInt);
        sort(inter.begin(), inter.end());
        vector<vector<int>>ans;
        ans.push_back(inter[0]);
        i=1;
        for(; i<inter.size(); i++)
        {
            if(inter[i][0] <= ans.back()[1] && inter[i][0] >= ans.back()[0])
            {
                ans.back()[0]=min(ans.back()[0], inter[i][0]);
                ans.back()[1]=max(ans.back()[1], inter[i][1]);
            }
            else
            {
                ans.push_back(inter[i]);
            }
        }
        return ans;
    }
};