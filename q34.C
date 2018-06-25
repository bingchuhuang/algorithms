vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> res(2,-1);
    if(n<1) return res;
    int lo = 0, hi = n-1;

    int found = 0;
    while(lo<hi){  //search for lowest index
        int mid = (lo+hi)/2;
        if(nums[mid]<target){
            lo = mid+1;
        }else{
            hi = mid;
        }
    }
    if(nums[lo]!=target) return res;
    else res[0]=lo;

    hi = n-1;
    while(lo<hi){ //search for highest index
        int mid = (lo+hi)/2+1;
        if(nums[mid]>target){
            hi = mid-1;
        }else{
            lo = mid;
        }
    }
    res[1] = hi;
    return res;
}
