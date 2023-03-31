class Solution {
public:
    unordered_map<string, bool>m;
    bool scramble(string s, string t)
    {
        int n=s.size(), nn=t.size();
        if(n!=nn) return 0;
        if(s==t) return 1;
        if(n<=1) return 0;
        string key=s+" "+t;
        if(m.count(key))
        return m[key];
        bool pos=0;
        for(int i=1; i<n; i++)
        {
            //dont swap
            bool dont=scramble(s.substr(0, i), t.substr(0, i)) && scramble(s.substr(i), t.substr(i));
            //swap
            bool scr=scramble(s.substr(0, i), t.substr(n-i)) && scramble(s.substr(i), t.substr(0, n-i));
            pos=dont || scr;
            if(pos) break;
        }
        return m[key]=pos;
    }
    bool isScramble(string s, string t) {
        int n=s.size();
        return scramble(s, t);
    }
};