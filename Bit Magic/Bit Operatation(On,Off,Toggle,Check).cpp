    int setKthBit(int N, int K)
    {
      int onMask = (1<<K);   //k==1
      return N|onMask;
      
      int offMask = ~(1<<K);  //k==0
      return N&offMask;
       
      int toggleMask = (1<<K);   //k==1
      return N^toggleMask;
       
      int checkMask = (1<<K); // k==1
      return N&checkMask;
       

    }
