/*
void genParen(string s, int l, int r, int n, vector<string> &res){
    if(l==n&&r==n){
        cout<<"s = "<<s<<endl;
        res.push_back(s); 
        return;
    }
    if(l<n){ 
        genParen(s+'(',l+1,r,n,res);
    }
    if(r<l){
        genParen(s+')',l,r+1,n,res);
    }
}

vector<string> generateParenthesis(int n) {
    string s;
    vector<string> res;
    genParen(s,0,0,n,res);
    return res;
}
*/

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string sol;
    genParen(sol, 0, 0, n, res);
    return res;
}
void genParen(string& sol, int open, int close, int total, vector<string>& res) {
    if (open == total && close == total) {
        res.push_back(sol);
        return;
    }
    if (open < total) {
        sol += '(';
        genParen(sol, open + 1, close, total, res);
        sol.resize(sol.length() - 1);
    }
    if (close < open) {
        sol += ')';
        genParen(sol, open, close + 1, total, res);
        sol.resize(sol.length() - 1);
    }
}

void q22(){
    generateParenthesis(2);
}
