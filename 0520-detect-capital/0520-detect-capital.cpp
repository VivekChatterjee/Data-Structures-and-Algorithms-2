class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if(n < 2) return 1;
        bool small = 0, cap = 0, firstCap = 0;
        if(word[0] >= 65 && word[0] <= 90)
        {
            if(word[1] >= 65 && word[1] <= 90) cap = 1;
            else firstCap = 1;
        }
        else small = 1;
        for(int i=1; i<word.size(); i++)
        {
            if(small || firstCap)
            {
                if(word[i] >= 65 && word[i] <= 90) return 0;
            }
            else if(cap)
            {
                if(word[i] >= 97 && word[i] <= 122) return 0;
            }
        }
        return 1;
    }
};