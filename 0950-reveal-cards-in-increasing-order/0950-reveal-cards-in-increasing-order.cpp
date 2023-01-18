class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        bool flag=0; // can take when 0, can't take when 1
        vector<int>ans(n, -1);
        sort(deck.begin(), deck.end());
        int i=0, j=0;
        // j at ans vector, i at deck vector, j should always be moved
        int total=n;
        while(total>0)
        {
            if(ans[j] == -1)
            {
                if(!flag)
                {
                    ans[j]=deck[i];
                    i++;
                    total--;
                }
                flag=!flag;
            }
            j=(j+1)%n;
        }
        return ans;
    }
};