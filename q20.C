#include <map>
bool isValid(string s) {
    stack<char> paren;
    for (char& c : s) {
        switch (c) {
            case '(': 
            case '{': 
            case '[': paren.push(c); break;
            case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
            case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
            case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
            default: ; // pass
        }
    }
    return paren.empty() ;
}

bool isValid(string s){
    unordered_map<char,int> val{{'(',1},{'{',2},{'[',3},{')',-1},{'}',-2},{']',-3}};

    stack<int> match;
    for(int i=0;i<s.length();i++){
        char tmp = s[i];
        auto it = val.find(tmp);
        if(it!=val.end()){
            int num = it->second;
            if(num>0) match.push(num);
            else if(!match.empty()&&match.top()+num==0) match.pop();
            else return false;
        }else{
            return false;
        }
    }
    return match.empty();
}

void q20(){
    string a = "{}{}{}{}";
    cout<<isValid(a)<<endl;
}
