/*can't use reference '&' at first par, change the nums, add extra permutations*/
void calcPermute(vector<int> nums , int begin, vector<vector<int>>& res){
    if(begin==nums.size()-1){
        res.push_back(nums);
        return;
    }
    for(int i=begin;i<nums.size();i++){
        if(i!=begin&&nums[i]==nums[begin]) continue;
        swap(nums[begin],nums[i]);
        calcPermute(nums,begin+1,res);
        // no swap back here! because some of the recursions are duplicates.
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> r;
    calcPermute(nums,0,r);
    return r;
}
