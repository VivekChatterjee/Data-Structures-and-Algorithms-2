class Solution {
public:
    int countCharacters(vector<string>& w, string c) {
        unordered_map<char,int>m;
        for(char cc: c) m[cc]++;
        int ans=0;
        for(int i=0; i<w.size(); i++)
        {
            sort(w[i].begin(), w[i].end());
            int ct=1;
            bool good=1;
            for(int j=1; j<w[i].size(); j++)
            {
                if(w[i][j] != w[i][j-1])
                {
                    if(m[w[i][j-1]]<ct) {
                        good=0;
                        break;
                    }
                    ct=1;
                }
                else ct++;
                if(j==w[i].size()-1)
                {
                    if(m[w[i][j]]<ct) {
                        good=0;
                        break;
                    }
                }
            }
            if(w[i].size() == 1)
            {
                if(m[w[i][0]] >= 1) ans+=1;
            }
            else if(good) ans+=w[i].size();
        }
        return ans;
    }
};