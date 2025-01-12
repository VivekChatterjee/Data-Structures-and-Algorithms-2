//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string s, string t, vector<string>& words) {
        unordered_map<string, int>m;
        for(string s: words){
            m[s]=0;
        }
        if(!m.count(t)) return 0;
        int ans=0;
        queue<pair<string, int>>q;
        q.push({s, 1});
        while(!q.empty()){
            string word=q.front().first;
            int len=q.front().second;
            q.pop();
            
            string original=word;
            for(int i=0; i<word.size(); i++){
                word=original;
                for(char c='a'; c<='z'; c++){
                    word[i]=c;
                    if(m.count(word) && m[word]==0){
                        if(word==t) {
                            ans=len+1;
                            return ans;
                        }
                        m[word]++;
                        q.push({word, len+1});
                    }
                }   
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends