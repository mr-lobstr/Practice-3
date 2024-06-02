#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> prices {7, 1, 5, 3, 6, 4};
    // int cntActions = 3;
    int maxProfit = 0;

    while (cntActions--)
    {
        auto minPrice = min_element(prices.begin(), prices.end());
        auto maxPrice = max_element(prices.begin(), prices.end());
        maxProfit += (*maxPrice - *minPrice);
        prices.erase(minPrice);
        prices.erase(maxPrice);
    }

    // cout << "Максимальная прибыль: " << maxProfit << endl;
}