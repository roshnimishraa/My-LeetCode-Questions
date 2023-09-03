Given Rearrange Array of Even Length
Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.

  Appraoch : Array with Extra Space 
TC : O(2N) 
SC : O(N) 

Algo 
1. Take 3 vector arrays ans,positive,negative 
if arr[i] > 0 push in positive array 
if arr[i] < 0 push in negative array 
2. Traverse in negative array 
 and push into ans positive and negative elements 


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        vector<int> neg;
        vector<int> pos;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > 0){
                pos.push_back(nums[i]);
            }
            if(nums[i] < 0) {
                neg.push_back(nums[i]);
            }
        }
        for(int i=0;i<neg.size();i++)
          
        {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);

        }
        return ans;
    }
};

Efficient Approach :  TWO POINTER 
 TC : O(N )
SC : O(N) 

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int pos =0;
        int neg =1;
        for(int i=0;i<nums.size();i++)
        {
 if(nums[i] > 0)
        {
            ans[pos] = nums[i];
            pos+=2;
        }
        if(nums[i] < 0)
        {
            ans[neg] = nums[i];
            neg+=2;
        }
        }
        return ans;
    }
};
--------------------------------------------------------------------------------------------------------------------------------------------------------

Follow Up Question : If positive and negative number is not fixed 
Given : If any of positive and negative number are left add them at the end without altering the order 

TC : O(N + N/2) ~ O(N) 
SC : O(N) 

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> neg;
        vector<int> pos;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] > 0){
                pos.push_back(nums[i]);
            }
            if(nums[i] < 0) {
                neg.push_back(nums[i]);
            }
        }
   
    if(pos.size()>neg.size())
    {
        for(int i=0;i<neg.size();i++)
        {
    // put pos at even place 
    nums[2*i] = pos[i];
    // put neg at odd place 
    nums[2*i+1]= neg[i];
        }
        // if positive and negative are not equal then 
// and them at end 
int index = neg.size()*2;
for(int i= neg.size();i<pos.size();i++)
{
nums[index] = pos[i];
index++;
}
       
}

else{
    for(int i=0;i<pos.size();i++)
        {
    // put pos at even place 
    nums[2*i] = pos[i];
    // put neg at odd place 
    nums[2*i+1]= neg[i];
        }   
        // if positive and negative are not equal then 
// and them at end 
int index = pos.size()*2;
for(int i= pos.size();i<neg.size();i++)
{
nums[index] = neg[i];
index++;
}
    
}
return nums;
    }
};



















  
