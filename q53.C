int maxSubArray(vector<int>& nums) {
    if(nums.size()<1) return 0;
    int sum = 0, res = nums[0];
    for(int i=0;i<nums.size();i++){
        sum += nums[i];
        res = max(res,sum);
        sum = max(sum,0);
    }
    return res;
}
