class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size(), mini = INT_MAX, count;
        if(m < n) return "";
        int ans = INT_MAX;
        string res="";
        unordered_map<char, int>mm;
        for(char c: t) mm[c]++;
        count = mm.size();
        int i=0, j=0;
        int start = -1,end=-1;
        while(j < m)
        {
            if(mm.count(s[j]))
            {
                mm[s[j]]--;
                if(mm[s[j]] == 0) count--;
            }
            while(count == 0 && i <= j)
            {
                if(j-i+1 < ans)
                {
                    start = i;
                    end = j;
                    ans = j-i+1;
                }                    
                if(mm.count(s[i]))
                {
                    mm[s[i]]++;
                    if(mm[s[i]] > 0) count++;
                }
                i++; 
            }
            j++;
        }
        if(start != -1 && end != -1)
        res = s.substr(start, end-start+1);
        return res;
    }
};