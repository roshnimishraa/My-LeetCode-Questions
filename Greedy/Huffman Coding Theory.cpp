Huffman Coding 
1. Variable Length Coding 
2. Used for Lossless Compression

>>> Variable Length Huffman Coding 
1. GREEDY IDEA  
  The MOST FREQUENT character has SMALLEST code 
2. PREFIX REQUIREMENT FOR COMPRESSION 
  No code should be prefix of any other 

>>>>>>> For Huffman Coding 
1. Build a Binary Tree/ Huffman Tree such that 
i) Every input character is a leaf 
ii) Every left child edge is labelled as 0 and 
    Every right child edge is labelled as 1
iii) Every root to leaf path represents Huffman Code of the leaf 

?? Min-Heap Priority Queue for Binary Tree Implementation 
TC : Time complexity: O(nlogn) where n is the number of unique characters
 extractMin() takes O(logn) time as it calls minHeapify()

Algorithm 
1. Create Leaf Node and Build a Min-Heap h of all the leaves initially
2. While h.size() > 1
a) left = h.extractMin()
b) right = h.extractMin() 
c) Create a new tree node with 
i) character $ represents Internal Nodes
ii) Frequency as left.freq + right.freq 
iii) left and right children as left and right respectively
iv) Insert the new node into h.
3. The only node left in h is our required binary tree


>>>>>> PsuedoCode FOR PRINTING HUFFMAN CODES FROM THE BUILD BINARY TREE 

void PrintCodes(root,str="") 
{
  if(root == nullptr) return;
if(root.ch != '$')
  print(root.ch + " " +str) 
    return;
printCodes(root.left,str+"O")
printCodes(root.right,str+"1")
  
