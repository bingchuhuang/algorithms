
//find the longest subtring repeating... not for the question, what did i do?!
/*
   int lengthOfLongestSubstring(string s) {
   int n = (int)(s.size());
   int maxlen = 0;
   for(int i=n/2;i>0;i--){
   for(int j=0;j<n-i;j++){
   string sub = s.substr(j,i);
   string pre = s.substr(0,j);
   int end = j+i>n?n:j+i;
   string post = s.substr(end,(size_t)(n-end));
   if(pre.find(sub)!=string::npos||post.find(sub)!=string::npos){ 
   if(lengthOfLongestSubstring(sub)>=1){
   maxlen = 0; 
   }else{
   return i;
   }
   }
   }
   }
   return maxlen;
   }
   */

int lengthOfLongestSubstringSlow(string s) {
    int maxlen = 0;
    int n = s.size();
    for(int i=n;i>0;i--){
        int found = 0;
        for(int j=0;j<=n-i;j++){
            string sub = s.substr(j,i);
            int isSame = 0;
            for(int k=0;k<i;k++){
                for(int l=k+1;l<i;l++){
                    if(sub[k]==sub[l]){
                        isSame = 1;
                        break;
                    }
                }
                if(isSame) break;
            }
            if(!isSame){ 
                maxlen = i;
                return maxlen;
            }
        }
    }
    return maxlen;
}

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int maxlen = 0;
    string si;
    //string max;
    int j=0;
    while(j<=n){
        cout<<"si = "<<si<<endl;
        int pos = si.find_first_of(s[j]);
        if(pos==string::npos){
            si.append(s,j,1);
        }else{
            int len = si.size(); 
            if(len>maxlen){ 
                maxlen = len;
                //max = si;
            }
            si.erase(0,pos+1);
            si.append(s,j,1);
        }
        j++;
    }
    if(si.size()>maxlen) maxlen = si.size();
    return maxlen;
}

int lengthOfLongestSubstringSmart(string s){
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i != s.length(); i++) {
        if (dict[s[i]] > start)
            start = dict[s[i]];
        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}

void q3(){
    string a = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefg";
    //string a = "a";
    //string a = "dvdf";
    //string a = "pwwkew";
    cout<<lengthOfLongestSubstring(a)<<endl;
}
