class Solution {
public:
    bool check(vector<int>& nums) {
        int count =0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1] > nums[i])
            {
              count++;
                
            }
            }
            if(nums[n-1] > nums[0])
               count++;
            return count<=1;
            
    }
};

Approach 
2conditions
1. compare all the elements if there is only 1 pair exists
nums[i-1] > nums[i] then true do count++

2. compare last element with first element if last is greater 
then return count++ and do count <=1 (for 0 or 1) it is true