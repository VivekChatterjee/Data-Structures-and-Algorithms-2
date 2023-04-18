class Solution {
public:
    string mergeAlternately(string s, string t) {
        int n=s.size(), nn=t.size();
        int i=0, j=0;
        string ans="";
        bool first=1;
        while(i<n && j<nn)
        {
            ans += ((first) ? (s[i++]) : (t[j++])); 
            first=!first;
        }
        if(i<n) ans += s.substr(i, n);
        if(j<nn) ans += t.substr(j, nn);
        return ans;
    }
};