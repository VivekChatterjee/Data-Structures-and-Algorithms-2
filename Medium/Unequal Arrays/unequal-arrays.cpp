//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
#define ll long long
class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
       long long sumA=0,sumB=0;
        vector<int>Aeven;
        vector<int>Aodd;
        vector<int>Beven;
        vector<int>Bodd;
        for(int i=0;i<N;i++){
            if(A[i]%2==0)
            Aeven.push_back(A[i]);
            else
            Aodd.push_back(A[i]);
            if(B[i]%2==0)
            Beven.push_back(B[i]);
            else
            Bodd.push_back(B[i]);
            sumA+=A[i];
            sumB+=B[i];
            
        }
        long long res=0;
        if(sumA!=sumB||Aeven.size()!=Beven.size()) return -1;
        sort(Aeven.begin(),Aeven.end());
        sort(Beven.begin(),Beven.end());
        for(int i=0;i<Aeven.size();i++){
            res +=abs(Aeven[i]-Beven[i])/2;
        }
        sort(Aodd.begin(),Aodd.end());
        sort(Bodd.begin(),Bodd.end());
        for(int i=0;i<Aodd.size();i++){
            res +=abs(Aodd[i]-Bodd[i])/2;
        }
        return res/2;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends