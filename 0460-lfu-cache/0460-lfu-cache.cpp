#include <bits/stdc++.h>
using namespace std;

class LFUCache {
    int capacity;
    int time = 0;

    // key -> {value, frequency, last used time}
    unordered_map<int, tuple<int, int, int>> mp;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;

        auto &[value, freq, last] = mp[key];

        freq++;
        last = ++time;

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (mp.count(key)) {
            auto &[v, freq, last] = mp[key];

            v = value;
            freq++;
            last = ++time;
            return;
        }

        if (mp.size() == capacity) {
            int removeKey = -1;
            int minFreq = INT_MAX;
            int oldTime = INT_MAX;

            for (auto &[k, data] : mp) {
                auto [v, f, t] = data;

                if (f < minFreq || (f == minFreq && t < oldTime)) {
                    minFreq = f;
                    oldTime = t;
                    removeKey = k;
                }
            }

            mp.erase(removeKey);
        }

        mp[key] = {value, 1, ++time};
    }
};
