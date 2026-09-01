#include <bits/stdc++.h>
using namespace std;

class LFUCache {
    int capacity, minFreq;

    // key -> {value, frequency}
    unordered_map<int, pair<int,int>> mp;

    // frequency -> keys
    unordered_map<int, list<int>> freq;

    // key -> position
    unordered_map<int, list<int>::iterator> pos;

    void update(int key) {
        int f = mp[key].second;

        freq[f].erase(pos[key]);

        if (freq[f].empty() && minFreq == f)
            minFreq++;

        mp[key].second++;

        freq[f + 1].push_front(key);
        pos[key] = freq[f + 1].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;

        update(key);
        return mp[key].first;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        // Key already exists
        if (mp.count(key)) {
            mp[key].first = value;
            update(key);
            return;
        }

        // Cache full
        if (mp.size() == capacity) {
            int oldKey = freq[minFreq].back();

            freq[minFreq].pop_back();
            mp.erase(oldKey);
            pos.erase(oldKey);
        }

        // Add new key
        mp[key] = {value, 1};
        freq[1].push_front(key);
        pos[key] = freq[1].begin();

        minFreq = 1;
    }
};