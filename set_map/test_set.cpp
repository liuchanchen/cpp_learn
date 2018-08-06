#include "test_set.h"
#include <iostream>
#include <map>
#include <stdint.h>

using namespace std;

int32_t test_map()
{
    multimap<string, int32_t> mulmap;
    string word;

    while (cin >> word)
    {
        if (word == "end")
        {
            break;
        }
        pair<string, int32_t> value;
        value.first = word;
        value.second++;
        mulmap.insert(value);
    }
    for (auto &iter : mulmap)
    {
        cout << iter.first << " occurs " << iter.second << endl;
    }

    return 0;
}