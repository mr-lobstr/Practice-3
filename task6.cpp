#include <algorithm>
#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>
using namespace std;

bool str_search (string const& str, string const& s)
{
    auto itS = search(str.begin(), str.end(), s.begin(), s.end());
    return itS != str.end();
}

int main()
{
    vector<string> mailAddresses = {
        "seleznev@corp.nstu.ru",
        "rakov.2023@stud.nstu.ru",
        "avdeenko@corp.nstu.ru",
        "levich.2021@stud.nstu.ru",
        "ryabova.2022@stud.nstu.ru",
        "cosarev@corp.nstu.ru",
        "ryazanov.2023@stud.nstu.ru",
        "aksenov.2023@stud.nstu.ru"
    };

    vector<string> corpAddresses;
    string filterWord = "corp";

    copy_if(mailAddresses.begin(), mailAddresses.end(), back_inserter(corpAddresses),
        [&filterWord] (string const& str){
            return str_search(str, filterWord);
        });

    for (auto const& s : corpAddresses)
    {
        cout << s << endl;
    }
}