/* The idea is to use a Vector(To store Element) + Map(To get element index) */
// Average Time O(1) & Auxiliary Space O(N)
class RandomizedSet {
public:
vector<int> vec;
unordered_map<int,int> ump;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
    //if val is already present 
        if(ump.find(val) != ump.end()){
            return false;
        }
        vec.push_back(val); 
       ump[val] = vec.size()-1;
return true;
    }
    
    bool remove(int val) {
    //if val is not present 
if(ump.find(val) == ump.end()){
    return false;
}
//access the element which is going to delete from ///map
 int index = ump[val]; 
 //store last ele of vec
 int lastEle = vec.back();
 //shift element to be deleted at last of vec to 
 // delete in O(1) 
 vec.back() = val;
 //Now,val index = vec last ele index
vec[index] = lastEle;
//update lastEle index from map as well
ump[lastEle] = index;


//remove from vec and map
vec.pop_back();
ump.erase(val);
return true;
 }
    
    int getRandom() {
          int idx = rand()%vec.size();
        return vec[idx];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
