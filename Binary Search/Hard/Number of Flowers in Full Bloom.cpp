Based on Upper Bound or Lower Bound 
TC : O(N LOG M )
SC : O(M) 
  
class Solution {

public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n =people.size();
        
        //upper_bound(just greater than ) = arr[i]>x  -> start
        //lower_bound(greater than or equal to) = arr[i]>=x  -> end
        
    vector<int> startTime(m);
    vector<int> endTime(m);
        
    for(int i=0;i<m;i++)
    {
   startTime[i] = flowers[i][0];
    endTime[i] = flowers[i][1];
 }
    sort(startTime.begin(),startTime.end());
    sort(endTime.begin(),endTime.end());
        
    vector<int> result(n);
    for(int i=0;i<n;i++)
    {
        int time = people[i];
    int bloomed_flower_already = upper_bound(startTime.begin(),startTime.end(),time) - startTime.begin();
        
    int died_flower_already = lower_bound(endTime.begin(),endTime.end(),time) - endTime.begin();
    result[i] = bloomed_flower_already - died_flower_already;
    }
        return result;
    }
};
