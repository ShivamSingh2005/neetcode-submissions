class MyHashSet {
private:
    vector<bool> hset;
public:
    MyHashSet() {
        // Allocate space up to 1,000,000 initialized to false
        hset.resize(1000001, false);
    }
    
    void add(int key) {
        hset[key] = true;
    }
    
    void remove(int key) {
        hset[key] = false;
    }
    
    bool contains(int key) {
        return hset[key];
    }
};