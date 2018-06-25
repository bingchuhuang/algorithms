bool isPalindrome(int x) {
    if(x<0||(x!=0 && x%10==0)) return false;
    int rev=0;  
    while(x>rev){
        rev = rev*10 + x%10;
        x /= 10;
    }
    return (rev == x) || (rev/10 == x);
}

void q9(){
   int a = 1001;
   cout<<isPalindrome(a)<<endl;
}
