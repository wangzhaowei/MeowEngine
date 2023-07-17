//
//  LRUCache.hpp
//  SampleCPP
//
//  Created by Felis Meow on 2023/7/14.
//

#ifndef LRUCache_hpp
#define LRUCache_hpp

#include <stdio.h>
#include <list>
#include <unordered_map>

namespace MeowEngine{

template<class Key, class Value, size_t Capacity, class DeallocationFuncTy = std::function<void(Value&)>>
class LRUCache{

private:
//    DeallocationFuncTy _deconstruction;
    
public:
    static_assert(Capacity > 0, "Capacity must be larger than 0");
    
//    LRUCache(DeallocationFuncTy&& deconstruction);
//
//    virtual ~LRUCache(){
//
//    }
        
    std::unordered_map<Key, typename std::list<std::pair<Key, Value>>::iterator> bufferMap;
    std::list<std::pair<Key, Value>> bufferList;
    
    bool put(const Key& key, const Value& value);
    std::optional<Value> get(const Key& key);
    void erase(const Key& key);
};

//template<class Key, class Value, size_t Capacity, class DeallocationFuncTy>
//LRUCache<Key, Value, Capacity, DeallocationFuncTy>::LRUCache(DeallocationFuncTy&& deconstruction): _deconstruction(deconstruction){
//
//}

template<class Key, class Value, size_t Capacity, class DeallocationFuncTy>
bool LRUCache<Key, Value, Capacity, DeallocationFuncTy>::put(const Key& key, const Value& value){
    if(bufferMap.count(key)){
        return false;
    }

    if(bufferMap.size() >= Capacity){
        DeallocationFuncTy deallocator;
        deallocator(bufferList.back().second);
        bufferMap.erase(bufferList.back().first);
        bufferList.pop_back();
    }

    bufferList.emplace_front(key, value);
    bufferMap.emplace(key, bufferList.begin());
    
    return true;
}

template<class Key, class Value, size_t Capacity, class DeallocationFuncTy>
std::optional<Value> LRUCache<Key, Value, Capacity, DeallocationFuncTy>::get(const Key &key){
    auto it = bufferMap.find(key);
    if(it == bufferMap.end()){
        return {};
    }

    bufferList.splice(bufferList.begin(), bufferList, it->second);
    return it->second->second;
}

template<class Key, class Value, size_t Capacity, class DeallocationFuncTy>
void LRUCache<Key, Value, Capacity, DeallocationFuncTy>::erase(const Key &key){
    auto it = bufferMap.find(key);
    if (it != bufferMap.end()) {
        
        bufferList.erase(it->second);
        bufferMap.erase(it);
    }
}

};

#endif /* LRUCache_hpp */
