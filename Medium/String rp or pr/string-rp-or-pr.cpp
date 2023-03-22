//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

#define ll long long
class Solution{   
public:
    long long solve(int x, int y, string s){
        ll ans=0;
        if(x>=y)
        {
            stack<char>st;
            int n=s.size();
            for(int i=0; i<n; i++)
            {
                while(!st.empty() && i<n && st.top()=='p' && s[i]=='r')
                {
                    ans+=x;
                    st.pop();
                    i++;
                }
                if(i<n)
                {
                    st.push(s[i]);
                }
            }
            stack<int>stt;
            while(!st.empty())
            {
                while(!stt.empty() && !st.empty() && st.top()=='r' && stt.top()=='p')
                {
                    stt.pop();
                    st.pop();
                    ans+=y;
                }
                if(!st.empty())
                {
                    stt.push(st.top());
                    st.pop();
                }
            }
        }
        else
        {
            stack<char>st;
            int n=s.size();
            for(int i=0; i<n; i++)
            {
                while(!st.empty() && i<n && st.top()=='r' && s[i]=='p')
                {
                    ans+=y;
                    st.pop();
                    i++;
                }
                if(i<n)
                {
                    st.push(s[i]);
                }
            }
            stack<int>stt;
            while(!st.empty())
            {
                while(!stt.empty() && !st.empty() && st.top()=='p' && stt.top()=='r')
                {
                    stt.pop();
                    st.pop();
                    ans+=x;
                }
                if(!st.empty())
                {
                    stt.push(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends