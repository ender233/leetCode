#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

class MapSum {
    public:
        /** Initialize your data structure here. */
        MapSum() {
        }
        void insert(string key, int val) {
            if(key.empty()) return ;
            mp[key] = val;
        }
        int sum(string prefix) {
            int sum(0);
            for(auto &p : mp) {
                // get the prefix string from another string
                auto iter = std::mismatch(prefix.begin(), prefix.end(), p.first.begin());
                if(iter.first == prefix.end()) sum += p.second;
            }
            return sum;
        }
        map<string, int> mp;
};

int main() {

    return 1;
}
