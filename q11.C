#include <algorithm>

//slow
int maxArea(vector<int>& height) {
    int n = height.size();
    int max = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int area = (j-i)*min(height[i],height[j]);
            max = area > max ? area : max;
        }
    }
    return max;
}

//fast
int maxAreaFast(vector<int>& height) {
    int n = height.size();
    int s = 0;
    if(n<=1) return 0;
    int i=0,j=n-1;
    while(j>i){
        int small = min(height[i],height[j]);
        int area = small*(j-i);
        if(area>s)
            s = area;
        if(height[i]>height[j]) j--;
        else i++;
    }
    return s;
}


void q11(){
    vector<int> h;
    h.push_back(1);
    h.push_back(5);
    h.push_back(9);
    h.push_back(7);
    h.push_back(3);

    cout<<maxArea(h)<<endl;
}
