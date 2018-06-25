string multiply(string num1, string num2) {
    string res(num1.size()+num2.size(),'0');

    int dig = res.size()-1;
    for(int i=num1.size()-1;i>=0;--i){
        int carry = 0;
        for(int j=num2.size()-1;j>=0;--j){
            int cur = (res[i+j+1]-'0') + (num1[i]-'0')*(num2[j]-'0') + carry;
            res[i+j+1] = '0' + cur%10;
            carry = cur/10;
        }
        res[i] += carry;
    }
    size_t first = res.find_first_not_of('0');
    if(first!=string::npos)
        return res.substr(first);
    return "0";
}
