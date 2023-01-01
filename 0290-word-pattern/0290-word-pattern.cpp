class Solution {
public:
    bool wordPattern(string pattern, string s) {
        s+=" ";
        unordered_map<char,string>m;
        unordered_map<string,char>ss;
        
        int k=0,c=0;
        string x="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                c++;
                if(m.find(pattern[k])==m.end() && ss.find(x)==ss.end())
                {
                    m[pattern[k]]=x;
                    ss[x]=pattern[k];
                    k++;
                    x="";
                    
                }
                
                else if(m.find(pattern[k])!=m.end())
                {
                    if(m[pattern[k]]==x)
                    {
                        k++;
                        x="";
                        continue;
                    }
                    
                    else
                        return false;
                }
                
                else if(ss.find(x)!=ss.end())
                {
                    if(ss[x]==pattern[k])
                    {
                        k++;
                        x="";
                        continue;
                    }
                    else
                        return false;
                }
            }
            
            else
            {
                x+=s[i];
            }
        }
        
        if(pattern.size()!=c)
            return false;
        
        else
        {
            return true;
        }
    }
};