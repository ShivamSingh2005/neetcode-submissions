class MyHashSet {
public:
    vector<int> hset;
    MyHashSet() {
        hset={};
    }
    
    void add(int key) {
        for(int i = 0 ; i<hset.size() ; i++){
            if(hset[i]==key) return;
        }
        hset.push_back(key);
    }
    
    void remove(int key) {
        for(int i = 0 ; i<hset.size() ; i++){
            if(hset[i]==key) hset.erase(hset.begin()+i);
        }
    }
    
    bool contains(int key) {
        for(int i = 0 ; i<hset.size() ; i++){
            if(hset[i]==key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */