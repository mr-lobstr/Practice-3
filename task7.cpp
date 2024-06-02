#include <algorithm>
#include <iostream>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int main()
{
    std::vector<int> scenesDur {
        5, 10, 7, 12, 9, 22, 4
    };

    int minDurFilm = 52;
    int durationFilm = accumulate(scenesDur.begin(), scenesDur.end(), 0);
    int diffDur = durationFilm - minDurFilm;
    int criticDur = 13;

    sort(scenesDur.begin(), scenesDur.end());

    auto maxDurScene = upper_bound(scenesDur.begin(), scenesDur.end(), diffDur);
    maxDurScene = prev(maxDurScene);

    auto [lIt, rIt] = equal_range(scenesDur.begin(), scenesDur.end(), criticDur);
    lIt = prev(lIt);
    int nearestDur = (*rIt - criticDur < criticDur - *lIt) ? *rIt : *lIt;

    vector<int> durationSum;
    partial_sum(scenesDur.begin(), scenesDur.end(), back_inserter(durationSum));

    auto It = upper_bound(durationSum.begin(), durationSum.end(), diffDur);
    int mxCntScene = distance(durationSum.begin(), It);

    cout << "Наибольшая продолжительность сцены, которую можно вырезаь"
         << " = " << *maxDurScene << endl;

    cout << "Продолжительность сцены, наиболее близкая к названной критиками"
         << " = " << nearestDur << endl;

    cout << "Максимальное количество сцен которые можно вырезать = "
         << mxCntScene << endl;
}