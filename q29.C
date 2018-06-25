#include <climits>

int divide(int dividend, int divisor) {
    long long num1 = abs((long long) dividend);
    long long num2 = abs((long long) divisor);

    if(divisor==0 || dividend==INT_MIN && divisor==-1) return INT_MAX;

    int res = 0;
    while(num1>=num2){
        long long r2 = num2;
        int m = 1;
        while((r2<<1)<num1){
            r2 <<= 1;
            m <<= 1;
        }
        res += m;
        num1 -= r2;
    }

    if(dividend>0&&divisor<0 || dividend<0 && divisor>0) res = -res;
    return res;
}

void q29(){
    cout<<divide(INT_MAX,1)<<endl;
}
