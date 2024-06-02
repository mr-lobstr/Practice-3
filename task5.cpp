#include <algorithm>
#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>
using namespace std;

bool is_not_even (int a)
{
    return a % 2 != 0;
}

bool is_sqr (int a)
{
    int _sqrt = sqrt(a);
    return a == pow(_sqrt, 2);
}

int main()
{
    size_t n = 100;
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 0);

    auto it = partition(nums.begin(), nums.end(), is_not_even);

    cout << "Количество полных нечётных квадратов = "
         << count_if (nums.begin(), it, is_sqr) << endl;
}