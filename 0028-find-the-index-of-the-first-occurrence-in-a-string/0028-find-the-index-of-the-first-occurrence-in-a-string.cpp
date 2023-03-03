class Solution {
public:
    int strStr(string s, string t) {
        if(s.size()<t.size()) return -1;
        return (s.find(t)==s.size())? -1 : s.find(t);
    }
};