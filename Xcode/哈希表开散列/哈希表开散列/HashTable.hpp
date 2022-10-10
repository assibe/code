//
//  HashTable.hpp
//  哈希表开散列
//
//  Created by 周仁玺 on 2022/10/10.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
#include <vector>
#include <utility>
#include <string>

#endif /* HashTable_hpp */

using std::pair;
using namespace std;

enum State{
    
    EMPTY,
    EXITS,
    DELETE
};

template <class K, class V>

class HashDate{
    
    pair<K, V> _kv;
    State _state;
    
};

template <class K,class V>
class HashTable{
    
    bool Insert(const pair<K, V>& kv){
        
        if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7) {//判断容器类型范围位0.7
            size_t newSize = _tables.size() == 0 ? 10 :_tables.size() * 2;
            
            HashTable<K, V> newHT;
            newHT._tables.resize(newSize);
            
            for (auto& e :_tables) {
                
                if (e._state == EXITS) {
                    newHT.Insert(e._kv);
                }
                
            }
            newHT._tables.swap(_tables);
            }
        size_t starti = kv.first;
        starti %= _tables.size();
        
        size_t hashi = starti;
        size_t i = 1;
        
        while (_tables[hashi]._sate == EXITS) {//探测空位置，不同的动手方式
            hashi = starti + i;
            i++;
            hashi %= _tables.size();
        }
        
        _tables[hashi]._kv = kv;
        _tables[hashi]._state = EXITS;
        _n++;
    }
    
private:
    vector<HashTable> _tables;
    size_t _n = 0;//容量
};
