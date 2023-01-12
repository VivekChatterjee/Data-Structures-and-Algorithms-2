class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int n=s.size();
        int n2=t.size();
        int i=0, j=0;
        while(i<=n && j<n2)
        {
            if(i==n || s[i] != t[j]) return t[j];
            i++;
            j++;
        }
        return ' ';
    }
};