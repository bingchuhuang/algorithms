int totalNQueens(int n) {
    int out=0;
    vector<int> res(8,-1);
    solve(0,n,res,out);
    return out;
}

bool checkRow(int r, int c, vector<int> &res){
    for(int i=0;i<r;i++){
        if(c==res[i] || abs(r-i)==abs(c-res[i])){
            return false;
        }
    }
    return true;
}
void solve(int r, int n, vector<int> &res, int &out){
    if(r==n){
        out++;
        return;
    }
    for(int i=0;i<n;i++){
        res[r]=i;
        if(checkRow(r,i,res)){
            solve(r+1,n,res,out);
        }
    }
}
