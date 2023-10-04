class MyHashMap {
public:
    
    int arr[1000001] = {0};
    
    MyHashMap() {
    }
    
    void put(int key, int value) {
        arr[key] = value+1;
    }
    
    int get(int key) {
        return arr[key] - 1;
    }
    
    void remove(int key) {
        arr[key] = 0;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */