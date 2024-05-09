#include "header.h"
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> minCoinsUsed(vector<int>& coins, int S) {
    int n = coins.size();
    vector<int> dp(S + 1, INT_MAX); // dp[i] will store the minimum number of coins needed to make sum i
    vector<int> usedCoins(S + 1, -1); // usedCoins[i] will store the last used coin for sum i
    dp[0] = 0; // base case

    for (int i = 1; i <= S; ++i) {
        for (int j = 0; j < n; ++j) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX && dp[i - coins[j]] + 1 < dp[i]) {
                dp[i] = dp[i - coins[j]] + 1;
                usedCoins[i] = j; // Store the index of the last used coin
            }
        }
    }

    vector<int> coinsUsed;
    int remaining = S;
    while (remaining > 0) {
        int coinIndex = usedCoins[remaining];
        coinsUsed.push_back(coins[coinIndex]);
        remaining -= coins[coinIndex];
    }

    return coinsUsed;
}
