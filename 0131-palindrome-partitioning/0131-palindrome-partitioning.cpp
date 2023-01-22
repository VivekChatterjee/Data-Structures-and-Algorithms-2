#define vc vector
class Solution {
public:
    vc<vc<string>> ans;
    bool isPalin(string s, int i, int j)
    {
        while(i<j)
        {
            if(s[i] != s[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
    void solve(string s, int ind, vc<string>&v)
    {
        if(ind==s.size())
        {
            ans.push_back(v);
            return;
        }
        for(int i=ind;i<s.size();i++)
        {
            if(isPalin(s, ind, i))
            {
                v.push_back(s.substr(ind, i-ind+1));
                solve(s,i+1,v);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vc<string>v;
        solve(s,0,v);
        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<string>> partition(string s) {
//         vector<vector<string> > res;
//         vector<string> path;
//         func(0, s, path, res);
//         return res;
//     }
    
//     void func(int index, string s, vector<string> &path, 
//               vector<vector<string> > &res) {
//         if(index == s.size()) {
//             res.push_back(path);
//             return;
//         }
//         for(int i = index; i < s.size(); ++i) {
//             if(isPalindrome(s, index, i)) {
//                 path.push_back(s.substr(index, i - index + 1));
//                 func(i+1, s, path, res);
//                 path.pop_back();
//             }
//         }
//     }
    
//     bool isPalindrome(string s, int start, int end) {
//         while(start <= end) {
//             if(s[start++] != s[end--])
//                 return false;
//         }
//         return true;
//     }
// };