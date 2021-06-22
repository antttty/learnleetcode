#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); //
        int     closestSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() ; i++){
            int     l = i + 1, r = nums.size()-1;
            while(l < r){
                int     threeSum = nums[i] + nums[l] + nums[r];
                if (abs(threeSum - target) <= abs(closestSum - target)){
                    closestSum = threeSum;
                }
                if (threeSum > target ){
                    r--;
                }else if (threeSum < target){
                    l++;
                }else{
                    return threeSum;
                }
            }
        }
        return closestSum;
}

int main(){
    vector<int> nums = {-1, 2, 1, -4};
    cout << threeSumClosest(nums, 1) << '\n';
    return 0;
}