Brute Force : Use vector of size n + 1 ( Collision Occurs ) 
  
 Eg. add(3), add(5), add(10) n=5
  vector<int> ans => mark 1 at index which is pushed and add into set 

Collision problem : when we need to add 22 or greater than 5 index value then collision occurs 

Efficient Solution : using chaining method to handle collision 
                          using Doubly Linked List


class MyHashSet {
public:
    vector<list<int>> m;
    int size;
    MyHashSet() {
        size=100;
        m.resize(size);
    }
    int hash(int key){
      return key % size;
    }
    
// iterator to iterate through list 
    list<int> :: iterator search(int key) {
        int i=hash(key);
// find-> return an iterator [first,last) if not found return last
    return find(m[i].begin(),m[i].end(),key);
        
    }
    void add(int key) {
  if(contains(key)) return;
        
        int i=hash(key);
  m[i].push_back(key);    
    }
    
    void remove(int key) {
        int i=hash(key);
        if(!contains(key)) return;
    // for doubly linked list erase method is used
        m[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i=hash(key);
        
    if(search(key) !=m[i].end()) return true;
    else 
        return false;
    }
};
