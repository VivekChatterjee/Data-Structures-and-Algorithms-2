class Solution {
public:
    bool isScramblee(string s1, string s2, unordered_map<string,bool>&mpp) {
    if(s1.compare(s2)==0){
        return true;
    }
    if(s1.length()<=1){
        return false;
    }
   
    string key=s1;
    key.push_back(' ');
    key.append(s2);
    if(mpp.find(key)!=mpp.end()){
        return mpp[key];
    }
    int n=s1.size();
     bool flag=false;
    for(int i=1; i<=n-1; i++){
        bool cond1=isScramblee(s1.substr(0,i), s2.substr(n-i,i), mpp)&& isScramblee(s1.substr(i,n-1), s2.substr(0,n-i), mpp);
        bool cond2=isScramblee(s1.substr(0,i), s2.substr(0,i), mpp)&& isScramblee(s1.substr(i,n-i), s2.substr(i,n-i), mpp);
        if(cond1||cond2){
            flag=true;
            break;
        }
    }
    return mpp[key]=flag;
}
bool isScramble(string s1, string s2){
    unordered_map<string, bool> mpp;
    int n=s1.size();
    return isScramblee(s1,s2,mpp);
}
};