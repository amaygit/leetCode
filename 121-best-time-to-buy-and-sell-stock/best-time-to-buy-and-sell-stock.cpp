class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPrice=0,bestPrice=prices[0];
        for(int i=1;i<prices.size();i++){
            if(bestPrice<prices[i]){
                maxPrice=max(maxPrice,prices[i]-bestPrice);
            }
            bestPrice=min(bestPrice,prices[i]);
        }
        return maxPrice;
    }
    
};