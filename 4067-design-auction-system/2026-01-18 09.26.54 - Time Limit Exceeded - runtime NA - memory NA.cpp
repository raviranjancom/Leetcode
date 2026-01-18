class AuctionSystem {
public:
    map<int,map<int,int>> mp;
    map<int,set<pair<int,int>>> st;
    AuctionSystem(){
        
    }
    
    void addBid(int userId, int itemId, int bidAmount){
        if(mp[itemId].count(userId)){
            int oldAmount=mp[itemId][userId];
            st[itemId].erase({oldAmount, userId});
        }
        mp[itemId][userId]=bidAmount;
        st[itemId].insert({bidAmount,userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount){
        int prevAmount=mp[itemId][userId];
        mp[itemId][userId]=newAmount;
        st[itemId].erase({prevAmount,userId});
        st[itemId].insert({newAmount,userId});
    }
    
    void removeBid(int userId, int itemId){
        int prevAmount=mp[itemId][userId];
        mp[itemId].erase(userId);
        st[itemId].erase({prevAmount,userId});
    }
    
    int getHighestBidder(int itemId){
        auto it=st[itemId];
        if(it.empty()) return -1;
        return it.rbegin()->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */