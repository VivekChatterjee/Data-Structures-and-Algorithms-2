class Solution {
public:
    vector<vector<string>>ans;
    unordered_map<string, int>m, wd;
    string beg="";
    void dfs(string word, vector<string>&seq)
    {
        if(word == beg)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int len = wd[word];
        for(int i=0; i<word.size();i++)
        {
            string st = word;
            for(char c='a'; c <='z'; c++)
            {
                st[i] = c;
                if(wd.count(st) && wd[st] + 1 == len)
                {
                    seq.push_back(st);
                    dfs(st, seq);
                    seq.pop_back();
                }
            }
        }
    }        
    vector<vector<string>> findLadders(string start, string target, 
    vector<string>& words) 
    {
        beg = start;
        for(auto i: words)
        {
            if(i != start)
            m[i] = 1;
        }
        wd[start] = 1;
        if(!m.count(target)) return {};
        queue<string>q;
        q.push(start);
        while(!q.empty())
        {
            string s = q.front();
            q.pop();
            int len = wd[s];
            if(s == target) break;
            for(int i=0; i<s.size();i++)
            {
                string st = s;
                for(char c='a'; c <='z'; c++)
                {
                    st[i] = c;
                    if(m.count(st))
                    {
                        m.erase(st);
                        q.push(st);
                        wd[st] = len + 1;
                    }
                }
            }
        }
        vector<string>seq;
        seq.push_back(target);
        dfs(target, seq);
        return ans;
    }
};