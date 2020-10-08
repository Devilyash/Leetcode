class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int>v;
    vector<int>::iterator it; 
    MyHashSet() {
       
    }
    
    void add(int key) {
    	// find the element
    	it = find(v.begin(), v.end(), key);
    	// if element is not present in the vector
    	if(it == v.end())
    	{
    		v.push_back(key);
		}
    }
    
    void remove(int key) {
        it = find(v.begin(), v.end(), key);
        if(it != v.end())
    	{
    		v.erase(it);
		}
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        it = find(v.begin(), v.end(), key);
        // present
        if(it != v.end()) return true;
        // not present
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
