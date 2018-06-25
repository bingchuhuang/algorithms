bool isValidSudoku(vector<vector<char>>& board) {
    int usedInCol[9][9]={0},usedInRow[9][9]={0},usedInBox[9][9]={0};
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]!='.'){
                int num = board[i][j]-'0'-1;
                int row = i, col = j, box = (i/3)*3 + j/3;
                if(usedInCol[col][num]||usedInRow[row][num]||usedInBox[box][num])
                    return false;
                usedInCol[col][num]=usedInRow[row][num]=usedInBox[box][num]=1;
            }
        }
    }
    return true;
}
