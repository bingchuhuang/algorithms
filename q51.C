bool checkRow(int r, int c, vector<int> &res){
    for(int i=0;i<r;i++){
        if(c==res[i] || abs(r-i)==abs(c-res[i])){
            return false;
        }
    }
    return true;
}
void solve(int r, int n, vector<int> &res, vector<vector<string>> &out){

    if(r==n){
        vector<string> s(n,string(n,'.'));
        for(int i=0;i<n;i++){
            s[i][res[i]] = 'Q';
        }
        out.push_back(s);
        return;
    }

    for(int i=0;i<n;i++){
        res[r]=i;
        if(checkRow(r,i,res)){
            solve(r+1,n,res,out);
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> out;
    vector<int> cor(8,-1);
    solve(0,n,cor,out);
    return out;
}
