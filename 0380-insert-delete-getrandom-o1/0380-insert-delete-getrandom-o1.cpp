class RandomizedSet {
public:
    unordered_map <int, int> mp;
    vector <int> arr;
    
    RandomizedSet() {
       
    }
    
    bool insert(int val) {
        if(mp[val])
        {
            return false;
        }
        else{
            mp[val] ++;
            arr.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(mp[val])
        {
            auto it = find(arr.begin(), arr.end(), val);
            arr.erase(it);
            mp[val] --;
            return true;
        }
        else{
            return false;
        }
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */