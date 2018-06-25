vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if(n<1) return vector<int>();
    int m = matrix[0].size();
    if(m<1) return vector<int>();
    vector<int> res(n*m,0);
    int i=0;
    int row = 0, col = 0, u=0,d=n,l=0,r=m;
    int direction = 0;
    while(i<m*n){
        if(direction==0){
            if(col==r-1){ direction = 1; u++; }
            else res[i++] = matrix[row][col++];
        }
        if(direction==1){
            if(row==d-1){ direction = 2;r--;}
            else res[i++] = matrix[row++][col];
        }
        if(direction==2){
            if(col==l){ direction = 3; d--;}
            else res[i++] = matrix[row][col--];
        }
        if(direction==3){
            if(row==u){ direction = 0; l++;}
            else res[i++] = matrix[row--][col];
        }
    }
    return res;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};
    int m = matrix.size(), n = matrix[0].size();
    vector<int> spiral(m * n);
    int u = 0, d = m - 1, l = 0, r = n - 1, k = 0;
    while (true) {
        // up
        for (int col = l; col <= r; col++) spiral[k++] = matrix[u][col];
        if (++u > d) break;
        // right
        for (int row = u; row <= d; row++) spiral[k++] = matrix[row][r];
        if (--r < l) break;
        // down
        for (int col = r; col >= l; col--) spiral[k++] = matrix[d][col];
        if (--d < u) break;
        // left
        for (int row = d; row >= u; row--) spiral[k++] = matrix[row][l];
        if (++l > r) break;
    }
    return spiral;
}
