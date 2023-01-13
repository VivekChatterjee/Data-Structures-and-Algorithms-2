class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s=to_string(num), st="";
        int i=0, j=0, n=s.size();
        int ans=0;
        while(j<n)
        {
            st+=s[j];
            if(j-i+1 == k)
            {
                if(stoi(st) != 0 && num % stoi(st) == 0) ans++;
                st.erase(st.begin());
                i++;
            }
            j++;
        }
        return ans;
    }
};