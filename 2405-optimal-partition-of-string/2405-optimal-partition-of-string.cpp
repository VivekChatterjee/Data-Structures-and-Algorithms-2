class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        unordered_map<char, int>m;
        int i=0, j=0, ans=1;
        while(j<n)
        {
            m[s[j]]++;
            if(m.size()!=j-i+1)
            {
                ans++;
                m.clear();
                m[s[j]]++;
                i=j;
            }
            j++;
        }
        return ans;
    }
};