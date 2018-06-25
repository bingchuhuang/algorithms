vector<int> kmpProcess(string& needle) {
    int n = needle.length();
    vector<int> lps(n, 0);
    for (int i = 1, len = 0; i < n; ) {
        //cout<<"in  i = "<<i<<" len = "<<len<<" t[i] = "<<lps[i]<<endl;
        if (needle[i] == needle[len])
            lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
        //cout<<"out i = "<<i<<" len = "<<len<<" t[i] = "<<lps[i-1]<<endl;
    }
    return lps;
}

vector<int> getNext(string &needle){
    
    int n = needle.length();
    vector<int> lps(n+1, 0);
    lps[0]=-1;
    int j=0,k=-1;
    while(j<n){
        if(k==-1||needle[j]==needle[k]){
            lps[++j] = ++k;
        }else{
            k = lps[k];
        }
    }
    return lps;
}

void testKMP(){
    string s = "aaaabaaabca";
    vector<int> lps = kmpProcess(s);
    vector<int> lps1 = getNext(s);
    cout<<"s = "<<s<<endl;
    for(int i=0;i<lps.size();i++){
        cout<<lps[i]<<" "<<lps1[i+1]<<endl;
    }
}
