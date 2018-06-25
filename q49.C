vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map <string,multiset<string>> mp;
    for(auto s : strs){
        string t = s;
        sort(s.begin(),s.end());
        mp[s].insert(t);
    }

    vector<vector<string>> ana;
    for(auto m: mp){
        vector<string> tmp(m.second.begin(),m.second.end());
        ana.push_back(tmp);
    }
    return ana;
}
