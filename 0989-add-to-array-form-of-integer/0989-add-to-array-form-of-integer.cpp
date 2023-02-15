class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size(), carry=0;
        for(int i=n-1; i>=0; i--)
        {
            int sum=num[i]+carry+k%10;
            k/=10;
            num[i]=sum%10;
            carry=sum/10;
        }
        while(k || carry)
        {
            int sum=k%10+carry;
            num.insert(num.begin(), sum%10);
            carry=sum/10;
            k/=10;
        }
        return num;
    }
};