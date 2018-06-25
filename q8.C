#include <climits>
int myAtoi(string str) {
    int size = str.size();
    if(size<1) return 0;
    long long out = 0;
    int sign=1,j=0;

    while(str[j]==' ')
        j++;

    if(str[j]=='-') sign = -1;
    if(str[j]=='+'||str[j]=='-') j+=1;

    for(;j<size;j++){
        if(str[j]-'0'>10||str[j]-'0'<0) break;
        out = out*10 + (str[j]-'0');
        if(out*sign>INT_MAX) return INT_MAX;
        if(out*sign<INT_MIN) return INT_MIN;
    }
    return out*sign;
}

void q8(){
    string a = "-2147483649";
    cout<<myAtoi(a)<<endl;
}
