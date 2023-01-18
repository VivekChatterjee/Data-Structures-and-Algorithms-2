class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        queue<pair<int, int>>q;
        vector<int>v(26, 0);
        for(int i=0; i<n; i++)
        {
            if(v[s[i]-'a'] == 0) q.push({s[i], i});
            v[s[i]-'a']++;
        }
        int ans=-1;
        while(!q.empty())
        {
            if(v[q.front().first-'a'] == 1) return q.front().second;
            q.pop();
        }
        return ans;
    }
};