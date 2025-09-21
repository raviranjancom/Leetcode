class MovieRentingSystem {
public:
    unordered_map<int,set<pair<int,int>>> unrented;       // movie ---> set{price,shop}
    set<vector<int>> rented;                              // {price,ship,movie}
    unordered_map<int ,int> movie2price;                  // movie ---> price
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(int i=0;i<entries.size();i++){
            unrented[entries[i][1]].insert({entries[i][2],entries[i][0]});
            movie2price[entries[i][1]]=entries[i][2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        int i=0;
        for(auto it: unrented[movie]){
            if(i==5) break;
            ans.push_back(it.second);
            i++;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price=movie2price[movie];
        auto it=unrented[movie].find({price,shop});
        unrented[movie].erase(it);

        rented.insert({price,shop,movie});
    }
    
    void drop(int shop, int movie) {
        int price=movie2price[movie];
        rented.erase({price,shop,movie});
        unrented[movie].insert({price,shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int i=0;
        for(auto it:rented){
            if(i==5) break;
            ans.push_back({it[1],it[2]});
            i++;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */