class FoodRatings {
public:
    unordered_map<string, pair<string,int>> food2cuisine;   // food -> {cuisine, rating}
    unordered_map<string,set<pair<int, string>>> cuisine2food;    // cuisines -> { -rating, food}

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            food2cuisine[foods[i]]={cuisines[i],ratings[i]};
            cuisine2food[cuisines[i]].insert({(-1)*ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        cuisine2food[food2cuisine[food].first].erase({(-1)*food2cuisine[food].second,food});
        cuisine2food[food2cuisine[food].first].insert({(-1)*newRating,food});
        food2cuisine[food].second=newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisine2food[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */