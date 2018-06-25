#include <algorithm>
string intToRoman(int num) {
    string out;
    if(num<1||num>3999) return out;
    char marker[7] = {'I','V','X','L','C','D','M'}; //1, 5, 10, 50, 100, 500, 1000; 
    int dig = 0;

    while(num){
        int res = num % 10;
        int half = res/5;
        int it = res%5;
        if(it<=3&&it>0){
            for(int i=0;i<it;i++)
                out += marker[2*dig];
            if(half) out += marker[2*dig+1];
        }else if(it==4){
            if(half) out += marker[2*dig+2];
            else out += marker[2*dig+1];
            out += marker[2*dig];
        }else{
            if(half) out += marker[2*dig+1];
        }
        cout<<"out = "<<out<<endl;
        dig++;
        num /= 10;
    }
    for(int i=0,j=out.size()-1;i<j;i++,j--){
        int c = out[i];
        out[i] = out[j];
        out[j] = c;
    }
    return out;
}

string intToRomanFast(int num) {
    static char* ones[10] =     { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
    static char* tens[10] =     { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
    static char* hundreds[10] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
    static string thousands[4] = { "", "M", "MM", "MMM" };

    int th = num/1000;
    num -= th*1000;
    int h = num/100;
    num -= h*100;
    int t = num/10;
    int o = num - t*10;

    return thousands[th]+hundreds[h]+tens[t]+ones[o];
}

void q12(){
    int n = 1;
    cout<<"n = "<<n<<" roman = "<<intToRoman(n)<<endl;
    n = 6;
    cout<<"n = "<<n<<" roman = "<<intToRoman(n)<<endl;

}
