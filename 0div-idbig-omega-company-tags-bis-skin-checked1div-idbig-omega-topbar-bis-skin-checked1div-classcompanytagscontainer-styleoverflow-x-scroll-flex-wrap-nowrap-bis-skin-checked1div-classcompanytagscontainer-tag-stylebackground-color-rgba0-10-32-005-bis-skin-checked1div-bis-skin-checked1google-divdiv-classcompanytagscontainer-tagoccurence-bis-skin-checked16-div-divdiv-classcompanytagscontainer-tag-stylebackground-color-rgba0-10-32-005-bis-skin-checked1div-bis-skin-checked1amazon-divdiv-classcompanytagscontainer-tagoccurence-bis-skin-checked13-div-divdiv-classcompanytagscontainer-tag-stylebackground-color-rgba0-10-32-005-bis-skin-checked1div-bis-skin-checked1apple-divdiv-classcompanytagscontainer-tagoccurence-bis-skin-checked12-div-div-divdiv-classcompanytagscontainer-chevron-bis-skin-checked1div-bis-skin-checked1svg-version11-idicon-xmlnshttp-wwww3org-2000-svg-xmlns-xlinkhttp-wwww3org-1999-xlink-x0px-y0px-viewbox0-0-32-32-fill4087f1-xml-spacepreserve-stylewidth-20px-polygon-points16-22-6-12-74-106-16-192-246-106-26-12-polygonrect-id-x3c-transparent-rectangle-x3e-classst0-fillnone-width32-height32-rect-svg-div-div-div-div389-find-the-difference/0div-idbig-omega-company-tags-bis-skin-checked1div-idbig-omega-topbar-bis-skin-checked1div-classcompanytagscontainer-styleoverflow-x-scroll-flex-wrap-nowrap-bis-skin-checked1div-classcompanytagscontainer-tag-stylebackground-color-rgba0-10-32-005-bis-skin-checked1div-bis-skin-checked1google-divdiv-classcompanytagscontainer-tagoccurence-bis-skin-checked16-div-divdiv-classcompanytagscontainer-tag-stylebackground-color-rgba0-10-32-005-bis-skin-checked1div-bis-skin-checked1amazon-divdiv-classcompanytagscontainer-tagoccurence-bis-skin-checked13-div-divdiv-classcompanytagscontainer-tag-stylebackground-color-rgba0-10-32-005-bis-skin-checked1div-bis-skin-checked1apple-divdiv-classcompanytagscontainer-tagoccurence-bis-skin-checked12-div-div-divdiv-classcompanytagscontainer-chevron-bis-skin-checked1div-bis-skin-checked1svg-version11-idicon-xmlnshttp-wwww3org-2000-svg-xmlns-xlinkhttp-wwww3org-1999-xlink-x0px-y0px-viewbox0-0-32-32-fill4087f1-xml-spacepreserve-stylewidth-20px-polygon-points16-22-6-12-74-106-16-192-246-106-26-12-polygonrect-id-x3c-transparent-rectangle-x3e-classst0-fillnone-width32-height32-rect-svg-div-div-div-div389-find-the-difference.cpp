class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>v(26), vec(26);
        for(char c: s) v[c-'a']++;
        for(char c: t)
        {
            vec[c-'a']++;
            if(vec[c-'a'] > v[c-'a']) return c;
        }
        return 'a';
    }
};