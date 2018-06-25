#include <vector>
#include <iostream>
using namespace std;
vector <int> twoSum(vector <int> nums, int target){
    vector<int> output;
    for(vector<int>::iterator it1 = nums.begin();it1!=nums.end();++it1){
        int cur1 = *it1;
        for(vector<int>::iterator it2 = it1+1;it2!=nums.end();++it2){
            int cur2 = *it2;
            if(cur1+cur2 == target){
                cout<<"cur1 = "<<cur1<<" cur2 = "<<cur2<<endl;
                int dis1 = it1-nums.begin();
                cout<<"dis1 = "<<dis1<<endl;
                int dis2 = it2-nums.begin();
                cout<<"dis2 = "<<dis2<<endl;
                output.push_back(it1-nums.begin());
                output.push_back(it2-nums.begin());
            }
        }
    }
    return output;
}

vector<int> twoSum2(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
    map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < numbers.size(); i++) {
        int numberToFind = target - numbers[i];

        //if numberToFind is found in map, return them
        if (hash.find(numberToFind) != hash.end()) {
            result.push_back(hash[numberToFind]);
            result.push_back(i);
            return result;
        }

        //number was not found. Put it in the map.
        hash[numbers[i]] = i;
    }
    return result;

}
void q1(){
    vector<int> a;
    a.push_back(5);
    a.push_back(6);
    a.push_back(4);
    a.push_back(4);
    a.push_back(2);

    int target = 8;
    vector<int> b = twoSum2(a,8);
    for(int i=0;i<b.size();++i){
        cout<<b[i]<<endl;
    }
}
