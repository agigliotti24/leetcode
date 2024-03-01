int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 1)
        return 0;

    int maxProfit = 0;
    int left = 0;
    int right = 1;

    while(right < pricesSize) {
        if (prices[left] < prices[right]){
            int tmp = prices[right] - prices[left];
            if(tmp > maxProfit)
                maxProfit = tmp;
        } else {
            left = right;
        }

        ++right;
    }

    return maxProfit;
}