//121. Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1) return 0;

        int tempDif = 0;
        int tempNum = prices[prices.size()-1];

        for(int i = prices.size()-2; i >= 0; i--) {
              if(tempNum > prices[i]){
                    if(tempDif < (tempNum - prices[i])){
                        tempDif = tempNum - prices[i];
                    }
              }else{
                    tempNum = prices[i];
              }
        }
        return tempDif;
    }
};