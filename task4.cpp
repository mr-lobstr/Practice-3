#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    vector<double> points = {5.5, 6.0, 5.0, 5.2, 6.0, 5.1, 5.4, 5.8};
    
    auto [minIt, maxIt] = minmax_element(points.begin(), points.end());
    double minP = *minIt, maxP = *maxIt;

    
    auto newEnd = remove(points.begin(), points.end(), minP);
    newEnd = remove(points.begin(), newEnd, maxP);
    points.erase(newEnd, points.end());

    double sumPoints = accumulate(points.begin(), points.end(), 0.0);

    cout << "Баллы без учета максимальных и минимальных: " << endl;
    for (auto el : points)
    {
        cout << el << " ";
    }
    cout << endl << "Средний балл: " << (sumPoints / points.size()) << endl;
}