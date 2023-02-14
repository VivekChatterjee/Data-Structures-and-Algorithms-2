class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size(), nn=b.size(), i=n-1, j=nn-1, carry=0;
        string ans="";
        while(i>=0 || j>=0 || carry)
        {
            int sum=carry;
            if(i>=0) sum += a[i--]-'0';
            if(j>=0) sum += b[j--]-'0';
            carry=(sum>1)?1:0;
            ans=to_string(sum%2)+ans;
        }
        return ans;
    }
};