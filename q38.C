string countAndSay(int n) {
    if(n<=0) return "";
    if(n==1) return "1";
    string last = countAndSay(n-1);
    string s;
    int i=0;
    while(i<last.size()){
        char count='1';
        while(i<last.size()-1&&last[i]==last[i+1]){
            count++;
            i++;
        }
        s = s+count+last[i];
        i++;
    }
    return s;
}
