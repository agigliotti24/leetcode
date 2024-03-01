int findMin(int* mins, int size) {
    bool flag = true;
    int res = mins[0];

    for (int i = 0; i < size; ++i) {
        if (mins[i] > -1 && flag) {
            flag = false;
            res = mins[i];
            continue;
        }

        if (res > mins[i] && mins[i] > -1)
            res = mins[i];
    }

    if (flag)
        return -1;

    return res;
}

int coinChange(int* coins, int coinsSize, int amount) {
    if (amount == 0)
        return 0;

    int cache[amount + 1];
    memset(cache, 0, (amount + 1) * sizeof(int));

    // Calcuating for each amount 1 --> amount
    for (int i = 1; i <= amount; ++i) {
        // Calculating for each coin per amount
        int mins[coinsSize];
        for (int j = 0; j < coinsSize; ++j) {
            if (i - coins[j] >= 0) {
                int index = i - coins[j];
                if (cache[index] < 0) {
                    mins[j] = -1;
                } else {
                    int tmp = cache[index] + 1;
                    mins[j] = tmp;
                }
            } else {
                mins[j] = -1;
            }
        }
        cache[i] = findMin(&mins, coinsSize);
    }

    return cache[amount];
}