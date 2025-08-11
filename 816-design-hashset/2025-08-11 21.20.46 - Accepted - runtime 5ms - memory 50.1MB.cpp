class MyHashSet {
public:
    int size=1000001;
    vector<bool> hash;
    MyHashSet() {
        hash.resize(size);
        hash.assign(size, false);
    }
    
    void add(int key) {
        hash[key]=true;
    }
    
    void remove(int key) {
        if(hash[key]>0){
            hash[key]=false;
        }
    }
    
    bool contains(int key) {
        return hash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */