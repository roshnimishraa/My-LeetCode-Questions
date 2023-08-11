To avoid collision use Chaining method and Doubly Linked List 

class MyHashMap {
public:
    vector<list<pair<int,int>>> m;
    int size;
    MyHashMap() {
        size=100;
        m.resize(size);
    }
    int hash(int key){
        return key % size;
    }
//     search function 

list<pair<int,int>> :: iterator search(int key){
int i=hash(key);
//  iterator to iterate through elements 
list<pair<int,int>> :: iterator it = m[i].begin();
  
//     iterate till the end 
    while(it != m[i].end()) {
        if(it->first == key)
            return it;
            it++;
      
    }
    return it;
    }
    void put(int key, int value) {
     int i = hash(key);
        // if already exist 
        remove(key);
    m[i].push_back({key,value});
        
    }
    
    int get(int key) {
        int i=hash(key);
    list<pair<int,int>> :: iterator it = search(key);
        if(it == m[i].end()) return -1;
        else return it->second;
    }
    
    void remove(int key) {
        int i=hash(key);
    list<pair<int,int>> :: iterator it = search(key);
//         element exists
        if(it != m[i].end()){
            m[i].erase(search(key));
        }
    }
};

