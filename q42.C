int trap(vector<int>& height) {
    if(height.size()<1) return 0;
    int l = 0,r = height.size()-1;
    int maxL = 0, maxR = 0;
    int water = 0;
    while(l<=r){
        if(height[l]<height[r]){
            if(height[l]<maxL){
                water += maxL-height[l];
            }else{
                maxL = height[l];
            }
            l++;
        }else{
            if(height[r]<maxR){
                water += maxR-height[r];
            }else{
                maxR = height[r];
            }
            r--;
        }
    }
    return water;
}
