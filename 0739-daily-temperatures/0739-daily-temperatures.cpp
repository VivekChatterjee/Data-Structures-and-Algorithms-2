class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack<pair<int,int>>s;
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--)
        {
            while(!s.empty() && s.top().first <= temp[i]) s.pop();
            if(s.empty()) ans[i] = 0;
            else ans[i] = s.top().second - i;
            s.push({temp[i], i});
        }
        return ans;
    }
};