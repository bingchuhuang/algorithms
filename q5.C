
string longestPalindrome(string s) {
    if (s.size() < 2)
        return s;
    int len = s.size(), max_left = 0, max_len = 1, left, right;
    for (int start = 0; start < len && len - start > max_len / 2;) {
        left = right = start;
        while (right < len - 1 && s[right + 1] == s[right])
            ++right;
        start = right + 1;
        while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
            ++right;
            --left;
        }
        if (max_len < right - left + 1) {
            max_left = left;
            max_len = right - left + 1;
        }
    }
    return s.substr(max_left, max_len);
}

string longestPalindrome(string s) {
    int n = s.size();
    if(n<2) return s;

    int max_len = 0, max_l=0,l,r;
    for(int start=0;start<n&&n-start>max_len/2;){
        l=r=start;
        while(r<n-1&&s[r+1]==s[r])
            ++r;
        start = r+1;
        while(l>0&&r+1<n&&s[r+1]==s[l-1]){
            ++r;
            --l;
        }
        if(max_len<r-l+1){ 
            max_len = r-l+1;
            max_l = l;
        }
    }
    return s.substr(max_l,max_len);
}

//slower version
/*
string longestPalindrome(string s) {
    string pal;
    int n = s.size();
    if(n>0) pal = s[0];
    for(int i=1;i<2*n;i++){
        string sub; 
        int lo = (i-1)/2;
        int hi = (i+1)/2+(i+1)%2;
        if(hi-lo==2){
            sub.append(s,i/2,1);
        }
        cout<<"sub = "<<sub<<endl;
        while(lo>=0&&hi<=n-1){
            if(s[hi]==s[lo]){ 
                sub.append(s,hi,1);
                sub.insert(0 ,s,lo,1);
                lo--;
                hi++;
                if(sub.size()>pal.size()) pal = sub;
            }else{
                break;
            }
        }
    }
    return pal;
}
*/

void q5(){
    string a = "abcda";
    cout<<"a = "<<a<<endl;
    cout<<"polindrome = "<<longestPalindrome(a)<<endl;
}
