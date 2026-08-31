#include <bits/stdc++.h>
using namespace std;

class LFUCache {
    int cap, minFreq;

    // key -> {value, frequency}
    unordered_map<int, pair<int, int>> data;

    // frequency -> keys (front = most recent)
    unordered_map<int, list<int>> freqList;

    // key -> position in its list
    unordered_map<int, list<int>::iterator> pos;

    void increaseFreq(int key) {
        int freq = data[key].second;

        freqList[freq].erase(pos[key]);

        if (freqList[freq].empty() && minFreq == freq)
            minFreq++;

        data[key].second++;
        freqList[freq + 1].push_front(key);
        pos[key] = freqList[freq + 1].begin();
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (!data.count(key))
            return -1;

        increaseFreq(key);
        return data[key].first;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;

        if (data.count(key)) {
            data[key].first = value;
            increaseFreq(key);
            return;
        }

        if (data.size() == cap) {
            int oldKey = freqList[minFreq].back();

            freqList[minFreq].pop_back();
            data.erase(oldKey);
            pos.erase(oldKey);
        }

        data[key] = {value, 1};
        freqList[1].push_front(key);
        pos[key] = freqList[1].begin();

        minFreq = 1;
    }
};