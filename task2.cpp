#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

template<typename ForwardIt, typename Predicate>
ForwardIt my_unique (ForwardIt first, ForwardIt last, Predicate pred)
{
    first = adjacent_find(first, last, pred);
    if (first == last)
	    return last;

    ForwardIt dest = first;
    ++first;

    while (++first != last)
    {
        if (not pred(*dest, *first))
        {
            iter_swap(++dest, first);
        }
    }

    return ++dest;
}

struct Subject
{
    string name;
    vector<int> guards;

    bool operator< (const Subject& rhs) const
    {
        return this->name < rhs.name;
    }

    bool operator== (const Subject& rhs) const
    {
        return this->name == rhs.name;
    }
};

int main()
{
    vector<Subject> subjects = {
        {"русский язык", {4, 5, 3, 4, 4}},
        {"алгебра", {5, 4, 3}},
        {"история", {3, 4, 2, 4}},
        {"физика",  {4, 5, 5, 5, 4, 5}},
        {"история", {5}},
        {"химия",   {4, 5, 4, 4, 4, 4, 3}},
        {"алгебра", {5, 4, 5}}
    };

    sort(subjects.begin(), subjects.end());
    auto endU = my_unique(subjects.begin(), subjects.end(), [](const Subject& a, const Subject& b) {
        return a.name == b.name; 
    });

    for (auto itDbl = endU; itDbl != subjects.end(); ++itDbl)
    {
        auto itU = find (subjects.begin(), endU, *itDbl);
        copy(itDbl->guards.begin(), itDbl->guards.end(), back_inserter(itU->guards));
    }

    subjects.erase(endU, subjects.end());

    for (auto const& [name, guards] : subjects)
    {
        cout << name << ": ";
        for (auto el : guards)
        {
            cout << el << " ";
        }
        
        double sumG = accumulate(guards.begin(), guards.end(), 0.0);
        cout << " -> " << (sumG / guards.size()) << endl;
    }
}