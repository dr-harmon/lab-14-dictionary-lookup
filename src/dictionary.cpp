#include "dictionary.h"

#include <chrono>
#include <thread>

using namespace std;

bool linearSearch(const vector<string>& dictionary, const string& word)
{
    for (auto i = dictionary.begin(); i != dictionary.end(); i++) {
        if (*i == word) {
            return true;
        }
    }

    return false;
}

bool binarySearch(const vector<string>& dictionary, const string& word)
{
    int left = 0;
    int right = dictionary.size() - 1;
    while (left <= right) {
        std::this_thread::sleep_for(2ms);  // Artificial delay for benchmark tests
        int middle = floor((left + right) / 2);
        if (dictionary[middle] < word) {
            left = middle + 1;
        } else if (dictionary[middle] > word) {
            right = middle - 1;
        } else {
            return true;
        }
    }

    return false;
}

bool setSearch(const unordered_set<string>& dictionary, const string& word)
{
   return dictionary.count(word) > 0;
}
