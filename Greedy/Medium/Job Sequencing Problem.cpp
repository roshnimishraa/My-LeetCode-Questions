TC : O( N LOG N) + O(N * K) 
SC : O(N) 

Rules : 
1) One unit by every job
2) Only one job can be assigned at a time 
3) Time starts with 0 

ALGORITHM : GREEDY 
1. Sort Job in decreasing order of profit 
2. Initialize the result as first job in the sorted list.Assign the latest possible slot
3. Do following for the remaining (n-1) jobs : 
a) If this job can not added, ignore it 
b) else add it to the latest possible slot

Eg. 
{deadline,profit}
{{2,100},{1,50},{2,10},{1,20},{3,30}} 
Assign as Job -> J0, J1, J2, J3 , J4
Sol
I. Sort in decreasing order with respect to profit 
{{2,100},{1,50},{3,30},{1,20},{2,10}}
{J0,J1,J4,J1,J2}

II. Maximum Slot = Maximum Deadline = 3 
   Job between 0 to 1 -> J1
   Job between 1 to 2 -> J0
   Job between 2 to 3 -> J4 
  

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp(Job a, Job b)
    {
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        
        int maxSlot = INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxSlot = max(maxSlot,arr[i].dead);
            
        }
    // becaz using 1 based indexing 
  vector<int> schedule(maxSlot+1,-1);
   int count=0; // no of jobs done 
   int maxProfit =0;
   for(int i=0;i<n;i++)
   {
       int currProfit = arr[i].profit;
       int currJobID = arr[i].id;
       int currDead = arr[i].dead;
        
        for(int k = currDead; k>0; k--)
        {
            if(schedule[k] == -1)
            {
                count++;
                maxProfit += currProfit;
                schedule[k] = currJobID;
                //no need to process further 
                break;
            }
        }
   }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(maxProfit);
        return ans;
    } 
};
