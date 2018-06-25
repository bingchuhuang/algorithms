vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> r;
    calcPermute(nums,0,r);
    return r;
}

void calcPermute(vector<int>&nums, int begin, vector<vector<int>>& res){
    if(begin>=nums.size()){
        res.push_back(nums);
        return;
    }
    for(int i=begin;i<nums.size();i++){
        swap(nums[begin],nums[i]);
        calcPermute(nums,begin+1,res);
        swap(nums[i],nums[begin]);
    }
}
