#include <bits/stdc++.h>
using namespace std;

class LFUCache {
    int capacity;
    
    // key -> {value, frequency}
    unordered_map<int, pair<int,int>> data;
    
    // frequency -> keys
    unordered_map<int, list<int>> freq;
    
    int minFreq = 0;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (!data.count(key))
            return -1;

        int value = data[key].first;
        int f = data[key].second;

        freq[f].remove(key);
        freq[f + 1].push_front(key);

        data[key].second++;

        if (freq[minFreq].empty())
            minFreq++;

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        // Key already exists
        if (data.count(key)) {
            data[key].first = value;
            get(key);   // increase frequency
            return;
        }

        // Cache is full
        if (data.size() == capacity) {
            int oldKey = freq[minFreq].back();

            freq[minFreq].pop_back();
            data.erase(oldKey);
        }

        // Add new key
        data[key] = {value, 1};
        freq[1].push_front(key);

        minFreq = 1;
    }
};