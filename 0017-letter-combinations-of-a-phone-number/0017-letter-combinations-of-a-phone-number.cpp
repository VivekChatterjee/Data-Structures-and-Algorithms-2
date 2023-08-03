class Solution {
public:
    
    void solve(string d, int index,string ans, vector<string> &v, unordered_map<int,string>m)
    {
        //bc
        if(index>=d.length())
        {
            v.push_back(ans);
            return;
        }
        
        string val=m[d[index]-'0'];
        
        for(int i=0;i<val.size();i++)
        {
            ans.push_back(val[i]);
            solve(d,index+1,ans,v,m);
            ans.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string>v;
        if(digits.size()==0)
            return v;
        
        unordered_map<int,string>m;
        
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        
        
        
        int in=0;
        string ans="";
        solve(digits,in,ans,v,m);
        return v;
    }
};