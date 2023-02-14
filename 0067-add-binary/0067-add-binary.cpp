class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size(), nn=b.size(), i=n-1, j=nn-1, carry=0;
        string ans="";
        while(i>=0 || j>=0 || carry)
        {
            int num=0;
            if(i<=0)
            {
                if(i==0 && a[i]=='1') num++;
                i=-1;
            }
            else
            {
                if(a[i]=='1') num++;
                i--;
            }
            if(j<=0)
            {
                if(j==0 && b[j]=='1') num++;
                j=-1;
            }
            else
            {
                if(b[j]=='1') num++;
                j--;
            }
            if(num+carry==3)
            {
                ans='1'+ans;
                carry=1;
            }
            else if(num+carry==2 || num+carry==1)
            {
                if(num+carry==2)
                {
                    ans='0'+ans;
                    carry=1;
                }
                else
                {
                    ans='1'+ans;
                    carry=0;
                }
            }
            else
            {
                ans='0'+ans;
                carry=0;
            }
        }
        
        return ans;
    }
};