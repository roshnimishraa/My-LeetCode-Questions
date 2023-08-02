Approach 1: 
1. first find nextGreater and then do comparison between 2 subarray

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int>nxtgrt(n,0);
        nxtgrt[n-1]=-1;
        
        //calculating postfix next greator
        for(int i=n-2;i>=0;i--)
        {
            if(nums2[i+1]>nums2[i])
            {
                nxtgrt[i]=nums2[i+1];
            }
            else
            {
                for(int j=i+1;j<=nums2.size()-1;j++)
                {
                    nxtgrt[i]=-1;
                    if(nxtgrt[j]>nums2[i])
                    {
                        nxtgrt[i]=nxtgrt[j];
                        break;
                    }
                }
            }
        }
        
        //matching and putting value in output vector
        vector<int>out;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    out.push_back(nxtgrt[j]);
                    break;
                }
            }
        }
        return out;
        
    }
};
--------------------------------------------------------------------------------------------------------------------------------

  Approach 2 : Using unordered map and stack 
1. unordered map stores distict values so after finding next greater from nums2 store next greater into map 
2. store nums1 in map 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> umap;
        stack<int> st;
        int n=nums2.size();
        for(int i=n-1; i>=0;i--){
            
        while(!st.empty() && st.top() <= nums2[i]){
            st.pop();
        }
            
            if(st.empty() == true){
                umap[nums2[i]] = -1;
            }
            else{
                umap[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int>output;
        for(int i=0;i<nums1.size();i++){
            output.push_back(umap[nums1[i]]);
        }
        return output;
    }
};

TC : O(N) 
SC : O(N) 
