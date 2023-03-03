class Solution {
public:
    int strStr(string s, string t) {
        int n=s.size(), nn=t.size();
        int i=0, j=0, ti=0, ans=-1;
        while(j<=n)
        {
            if(ti==nn)
            {
                ans=i;
                break;
            }
            if(j==n) break;
            if(s[j]==t[ti]) ti++;
            else
            {
                j=i;
                i++;
                ti=0;
            }
            j++;
        }
        return ans;
    }
};