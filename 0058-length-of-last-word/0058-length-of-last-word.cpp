class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream st(s);
        int ans=0;
        string word;
        while(st>>word) ans=word.size();
        return ans;
    }
};