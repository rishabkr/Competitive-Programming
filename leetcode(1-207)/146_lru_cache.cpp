class LRUCache {
      int max_capacity;
        list<int> keys;
        unordered_map<int,pair<int,list<int>::iterator>>mp;
        
public:
    LRUCache(int capacity)
    {
        mp.clear();
        max_capacity=capacity;
    }
    
    int get(int key) {
    
        if(mp.find(key)!=mp.end())
        {
            //remove from list,push to front of the list,update key posn in map,return value
            keys.erase(mp[key].second);
            keys.push_front(key);
            mp[key].second=keys.begin();
            return mp[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            keys.erase(mp[key].second);
            keys.push_front(key);
            mp[key]={value,keys.begin()};
        }
        else
        {
             if(keys.size() == max_capacity)
             {
                mp.erase(keys.back());
                 keys.pop_back();             
             }
        keys.push_front(key);
        mp[key]={value,keys.begin()};
        
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */