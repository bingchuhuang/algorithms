string convert(string s, int numRows) {
    string out;
    int n = s.size();
    if(n<3||numRows<=1) return s;
    for(int i=0;i<numRows;i++){
        int start=0,step=2*(numRows-1);
        int l=0,r=0;
        while(l<=n||r<=n){
            l = start + i;
            r = start + step - i;
            if(l==r||r-l==step){
                if(l<n) out.append(s,l,1);
            }else{
                if(l<n) out.append(s,l,1);
                if(r<n) out.append(s,r,1);
            }
            start += step;
        }
    }
    return out;
}

void q6(){
    string a = "PAYPALISHIRING";
    cout<<convert(a,3)<<endl;
}
