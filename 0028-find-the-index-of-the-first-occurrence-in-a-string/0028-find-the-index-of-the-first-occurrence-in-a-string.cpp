class Solution {
public:
    int strStr(string s, string t) {
        if(s.size()<t.size()) return -1;
        int ind=s.find(t);
        if(ind==s.size()) return -1;
        else return ind;
    }
};