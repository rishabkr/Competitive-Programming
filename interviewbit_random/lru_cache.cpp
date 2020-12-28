#include<bits/stdc++.h>
unordered_map<int,pair<int,list<int>::iterator>>mp;
list<int>keys;
int max_capacity;

LRUCache::LRUCache(int capacity) {
    mp.clear();
    keys.clear();
    max_capacity=capacity;

}

int LRUCache::get(int key) {

if(mp.find(key)!=mp.end())
{
    keys.erase(mp[key].second);
    keys.push_front(key);
    mp[key].second=keys.begin();
    return mp[key].first;
}
return -1;
}

void LRUCache::set(int key, int value) {

    if(mp.find(key)!=mp.end())
    {
        keys.erase(mp[key].second);
        keys.push_front(key);
        mp[key]={value,keys.begin()};
    }
    else
    {
        if(keys.size() ==  max_capacity)
        {
            mp.erase(keys.back());
            keys.pop_back();
        }
            keys.push_front(key);
        mp[key]={value,keys.begin()};
    }

}
