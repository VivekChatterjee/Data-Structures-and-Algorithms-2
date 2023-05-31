class UndergroundSystem {
public:
    map<int, pair<string, int>>mp;
    map<string, map<string, vector<int>>>m;
    UndergroundSystem() {
    }
    void checkIn(int id, string st, int t) {
        mp[id]={st, t};
    }
    void checkOut(int id, string st, int t) {
        int diff=abs(t-mp[id].second);
        if(m.count(mp[id].first) && m[mp[id].first].count(st))
        {
            m[mp[id].first][st].push_back(diff+m[mp[id].first][st].back());
        }
        else
        {
            m[mp[id].first][st].push_back(diff);
        }
    }
    double getAverageTime(string st, string en) {
        return m[st][en].back()/(m[st][en].size()*1.0);
    }
};