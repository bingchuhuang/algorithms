//normal way
int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    int i=0,j=n-1;
    int counts = 0;
    while (i<=j){
        while (nums[j]==val&&j>i){
            counts++;
            j--;
        }
        if (nums[i]==val){
            int tmp = nums[j];
            nums[j] = nums[i];
            nums[i] = tmp;
            counts++;
            j--;
        }
        i++;
    }
    if(counts>0) nums.erase(nums.end()-counts,nums.end()); 
    return n-counts;
}

//elegant way
int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    int pos = 0;
    for(int i=0;i<n;i++){
        if(nums[i]!=val)
            nums[pos++] = nums[i];
    }
    return pos;
}
void q27(){
}
