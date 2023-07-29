Naive Approach : Stack 
Time Complexity: O(N), Traversing the entire string
Space Complexity: O(N), Stack and ans variable


Approach
•	Use a stack to push all the words in a stack
•	Now, all the words of the string are present in the stack, but in reverse order
•	Pop elements of the stack one by one and add them to our answer variable. Remember to add a space between the words as well. 
•	Here’s a quick demonstration of the same


class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0)  return s;
        stack<string> st;
        string result;
        int n = s.size();
        for(int i=0;i<n;i++){
            string word
            if(s[i] == ' ')  continue;
            while(i < n && s[i] != ' '){
                word += s[i];
                i++;
            }
            st.push(word);           
        }
        while(!st.empty())
        {
 result += st.top();
            st.pop();
            if(!st.empty()) {
                result += " ";            
            }
        }    
        return result;
     }
};
----------------------------------------------------------------------------------------------------------------------------------------

Efficient Approach : 
Time Complexity: O(N), N->length of string
Space Complexity: O(1), Constant Space

Approach : 
 •	We start traversing the string from the end until we hit a space. It indicates that we have gone past a word and now we need to store it.
•	We check if our answer variable is empty or not
•	If it’s empty, it indicates that this is the last word we need to print, and hence, there shouldn’t be any space after this word.
•	If it’s empty we add it to our result with a space after it.

Implementation 

class Solution {
public:
    string reverseWords(string s) {
        int n =s.length();
        int left = 0 , right=0;
    int i=0;
        
//  1. Reverse the entire array
        reverse(s.begin(),s.end());
        while(i < n){    
    while(i < n && s[i] == ' '){
        i++;
    } 
      
while(i< n && s[i] != ' '){
    s[right++] = s[i++];
    
}

//2. Reverse word 
        if(left < right){
            reverse(s.begin()+left,s.begin()+right);
            
             // Add a space after the reversed word
        s[right++]=' ';
   
//update the left index for the next word
            left = right;
        }
    i++;
        }
         // Add a space after the reversed word
      s = s.substr(0,right-1);
        return s;
    }
};
