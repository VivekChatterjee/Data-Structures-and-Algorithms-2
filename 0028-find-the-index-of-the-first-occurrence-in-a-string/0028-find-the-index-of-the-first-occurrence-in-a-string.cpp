class Solution {
public:
    int strStr(string s, string t) {
        int si=0, sj=0, ti=0, ans=-1;
        int n=s.size(), nt=t.size();
        while(sj<=n)
        {
            if(ti==nt) 
            {
                ans=si;
                break;
            }
            if(sj==n) break;
            if(s[sj]==t[ti])
            {
                ti++;
            }
            else
            {
                sj=si;
                si++;
                ti=0;
            }
            sj++;
        }
        return ans;
    }
};