class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        map<int, int>m;
        for(int i: tasks) m[i]++;
        int ans = 0;
        for(auto i: m)
        {
            if(i.second == 1) return -1;
            else
            {
                int num = i.second;
                if(num % 3 == 0) ans += num/3;
                else if(num == 4  || num == 2)
                {
                    ans+=(num / 2);
                }
                else
                {
                    if(num % 3 == 1)
                    {
                        int qu = num/3;
                        ans+=qu-1; // for 3
                        ans+= (num - (qu-1)*3)/2; // for 2
                    }
                    else
                    {
                        ans += num/3;
                        ans += ((num%3)/2);
                    }
                }
            }
        }
        return ans;        
    }
};