#define ll long long int

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tt) {
        
        set<vector<int>>ss;
        vector<vector<int>>v;
        ll n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        if(n<=3)
            return v;
        
        
        int num=nums[0];
        
        
        for(ll i=0;i<n-3;i++)
        {
            
            //checking if same values
            if(i!=0)
            {
                    if(nums[i]==num)
                        continue;
                    
                    num=nums[i];
            }
            
            for(ll j=i+1;j<n-2;j++)
            {
                ll s=j+1;
                ll e=n-1;
                
                while(s<e)
                {
                    
                    if((nums[i]*1LL +nums[j]*1LL +nums[s]*1LL +nums[e]*1LL ) == tt)
                    {
                        
                    vector<int>t(4);
                    t[0]=nums[i];
                    t[1]=nums[j];
                    t[2]=nums[s];
                    t[3]=nums[e];
                        if(ss.find(t) == ss.end())
                        {
                            v.push_back(t);
                            ss.insert(t);
                        }
                        
                        s++;
                        e--;
                    }
                    
                    else if( nums[i]*1LL +nums[j]*1LL +nums[s]*1LL +nums[e]*1LL > tt)
                        e--;
                    
                    else
                        s++;
                }
            }
        }
        
        return v;
    }
};
