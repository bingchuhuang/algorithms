vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> indices;
    unordered_map<string,int> count;
    for(string word : words){
        count[word]++;
    }
    int n=s.length(),num=words.size(),len=words[0].length();
    for(int i=0;i<n-num*len+1;i++){
        int j=0;
        unordered_map<string, int> seen;
        for(;j<num;j++){
            string sub = s.substr(i+j*len,len);
            if(count.find(sub)!=count.end()){
                seen[sub]++;
                if(seen[sub]>count[sub])
                    break;
            }else{
                break;
            }
        }
        if(j==num) indices.push_back(i);
    }
    return indices;
}
