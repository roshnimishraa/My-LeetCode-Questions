>> Print N-Bit binary numbers having more 1's than 0's for any prefix
>> Find N digit Binary Numbers where number of 1's >= Number of 0's

Eg. N = 5 
  1 1 0 1 0 
Output
Prefix of N -> 1 1 0 1 0  // A given number is prefix of itself 
               1 1 0 1    // discard 0 from last 
               1 1 0      // discard 1 from last 
               1 1        // discard 0 from last 
               1       // discard 1 from last 
