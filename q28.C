int strStr(string haystack, string needle) {
    int i=0,j=0;
    if(needle.length()==0) return 0;
    if(needle.length()>haystack.length()) return -1;
    while(i<=haystack.length()-needle.length()){
        if(haystack[i+j]==needle[j]){
            j++;
        }else{
            i++;
            j=0;
        }
        if(j==needle.length()) return i;
    }
    return -1;
}


//KMP algorithm
int strStr(string haystack, string needle) {
    int m = haystack.length(), n = needle.length();
    if (!n) return 0;
    vector<int> lps = kmpProcess(needle);
    for (int i = 0, j = 0; i < m; ) {
        if (haystack[i] == needle[j]) { 
            i++;
            j++;
        }
        if (j == n) return i - j;
        if (i < m && haystack[i] != needle[j]) {
            if (j) j = lps[j - 1];
            else i++;
        }
    }
    return -1;
}
vector<int> kmpProcess(string& needle) {
    int n = needle.length();
    vector<int> lps(n, 0);
    for (int i = 1, len = 0; i < n; ) {
        if (needle[i] == needle[len])
            lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}
