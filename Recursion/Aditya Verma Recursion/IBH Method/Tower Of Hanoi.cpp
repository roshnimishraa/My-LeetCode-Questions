class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int source, int dest, int helper) {
    //no. of steps 
    long long count = 1;// 1 for the extra step between two calls
    if(N == 1){
    cout<<"move disk "<<N<<" from rod "<<source<<" to rod "<<dest<<endl;
    
    return 1;
    }
count += toh(N-1,source,helper,dest);

cout<<"move disk "<<N<<" from rod "<<source<<" to rod "<<dest<<endl;

count += toh(N-1,helper,dest,source);

return count;
    }

};
