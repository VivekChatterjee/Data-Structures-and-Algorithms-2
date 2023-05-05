class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        int i=0, j=0;
        int ans=0, cur=0;
        while(j<n)
        {
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
            {
                cur++;
            }
            if(j-i+1==k)
            {
                ans=max(ans, cur);
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                    cur--;
                i++;
            }
            j++;
        }
        return ans;
    }
};