class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(), people.end());
        int s=0, e=n-1,ans=0;
        while(people[e] == limit)
        {
            ans++;
            e--;
        }
        while(s<=e)
        {
            if(people[s]+people[e] <= limit)
            {
                ans++;
                s++;
                e--;
            }
            else if(people[s]+people[e] > limit)
            {
                ans++;
                e--;
            }
        }
        return ans;
    }
};