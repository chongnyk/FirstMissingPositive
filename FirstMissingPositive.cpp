class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int idx = 0, size = nums.size();
        for(int i = 0; i < size; i++){
            if(nums[i] < 1 || nums[i] > size){
                nums[i] = size + 1;
            }
        }
        for(int i = 0; i < size; i++){
            if(abs(nums[i]) > size){
                continue;
            }
            if(nums[abs(nums[i]) - 1] > 0){
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        for(int num : nums){
            if(num < 0){
                idx++;
            }
            else {
                return ++idx;
            }
        }
        return ++idx;
    }
};

//The idea is that there are two cases
//First case: nums is of size n, contains all elements from 1 to n.
//In this case, smallest missing positive integer is n + 1.
//Second case: nums is of size n, missing at least one integer from 1 to n.
//In this case, this means nums contains at least one element that is either <= 0  or > n
//First pass through, O(n)
//change all elems that are either <= 0 or > n to n + 1
//This allows us to use negative integers in arbitrary cell i, indicating that i which is between 0 to n-1 and thus mappable to 1 to n is present in nums
//Second pass through, O(n), if cell has value, val, between 1 to n, then set nums[val - 1] to negative.
//Must use abs(val) to remain within array boundaries
//Third pass through, O(n), if a positive value is found, that means that cell's index, idx, was not marked negative, so idx + 1 is missing
//If no positive value is found, that means nums aligns with the first case, therefore smallest missing positive integer is n + 1.
