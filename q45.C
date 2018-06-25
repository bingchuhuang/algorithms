int jump(vector<int>& nums) {
    if(nums.size()<2) return 0;
    int lev = 0, i=0, curMax = 0, nextMax = 0;
    while(curMax-i+1>0){
        lev++;
        for(;i<=curMax;i++){
            nextMax = max(nextMax,nums[i]+i);
            if(nextMax>=nums.size()-1) return lev;
        }
        curMax = nextMax;
    }
    return 0;
}
