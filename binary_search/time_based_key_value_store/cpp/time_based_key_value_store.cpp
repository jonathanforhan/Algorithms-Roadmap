#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using std::string;
using std::vector;

// Time O(log(n))
// Space O(n)

class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        this->data[key].emplace_back(std::make_pair(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        auto& v = data[key];
        if(v.empty()) return "";
        int l = 0;
        int r = v.size()-1;
        std::pair<string, int> closest = {"", 0};
        while(l <= r) {
            int m = (l + r) >> 1;
            int t = v[m].second;

            if(t < timestamp && t > closest.second)
                closest = v[m];

            if(t < timestamp) {
                l = m+1;
            } else if(t > timestamp) {
                r = m-1;
            } else {
                return v[m].first;
            }
        }

        return closest.first;
    }

private:
    std::unordered_map<string, std::vector<std::pair<string, int>>> data;
};

int main() {
    TimeMap t = TimeMap();

    t.set("foo", "bar", 1);
    t.set("foo", "baz", 2);

    std::cout << t.get("foo", 2) << '\n';

    return 0;
}
