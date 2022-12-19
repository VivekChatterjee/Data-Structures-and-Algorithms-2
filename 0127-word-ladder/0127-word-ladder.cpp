class Solution {
public:
    int ladderLength(string start, string target, vector<string>& words) {
        queue<pair<string,int>>q;
        q.push({start, 1});
        unordered_map<string, int>m;
        for(auto i: words)
        {
            if(i != start)
            m[i] = 1;
        }
        int ans = 0;
        if(!m.count(target)) return ans;
        while(!q.empty())
        {
            string s = q.front().first;
            int len = q.front().second;
            q.pop();
            if(s == target) 
            {
                ans = len;
                break;
            }
            for(int i=0; i<s.size();i++)
            {
                string st = s;
                for(char c='a'; c <='z'; c++)
                {
                    st[i] = c;
                    if(m.count(st))
                    {
                        m.erase(st);
                        q.push({st, len+1});
                    }
                }
            }
        }
        return ans;
    }
};