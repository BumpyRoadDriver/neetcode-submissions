class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> hmap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hmap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto &desired_row = hmap[key];
        auto it = upper_bound(desired_row.begin(), desired_row.end(), pair<int, string>{timestamp, "{"});
        it--; 
        if (distance(desired_row.begin(), it) >= 0 and it->first <= timestamp){
            return it -> second;
        }
        return "";
    }
};
