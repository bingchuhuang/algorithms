#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

void threeSum(vector<int>& nums) {
    if(nums.size()<3) return;
    std::sort(nums.begin(),nums.end());
    int i=0,j,k;
    for(int i=0;i<nums.size()-2;i++){
        j=i+1;
        k=nums.size()-1;
        while(j<k){
            int sum = nums[i] + nums[j] +nums[k]; 
            if(sum==0){
                vector<int> oneset(3,0);
                oneset[0] = nums[i];
                oneset[1] = nums[j];
                oneset[2] = nums[k];
                while(j<k && nums[j]==oneset[1]) j++;
                while(j<k && nums[k]==oneset[2]) k--;
            }else if(sum>0){
                k--;
            }else{
                j++;
            }
        }
        while(i<nums.size()-1&&nums[i+1]==nums[i])
            i++;
    }
    return;
}

//copy from solution
/*
vector<vector<int>> threeSum(vector<int>& num) {
    vector<vector<int> > res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {

        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back) {

            int sum = num[front] + num[back];

            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);

                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) back--;
            }

        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;

    }

    return res;
}
*/

void q15(){
    vector<int> s;
    s.push_back(-1);
    s.push_back(0);
    s.push_back(1);
    s.push_back(2);
    s.push_back(-1);
    s.push_back(-4);
    threeSum(s);
}
