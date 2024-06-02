#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    size_t n = 100;
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 2);

    auto endPrimes = nums.end();

    for (auto it = nums.begin(); it != endPrimes; ++it)
    {
        endPrimes = remove_if(next(it), endPrimes, [it] (int a) {
            return a % *it == 0;
        });
    }

    nums.erase(endPrimes, nums.end());

    for (auto el : nums)
    {
        cout << el << " ";
    }
    cout << endl;
}