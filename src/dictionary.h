#pragma once

#include <unordered_set>
#include <string>
#include <vector>

// Performs a linear search of a dictionary. Returns true if the given
// word is in the dictionary, false otherwise.
bool linearSearch(const std::vector<std::string>& dictionary, const std::string& word);

// Performs a binary search of a dictionary. Returns true if the given
// word is in the dictionary, false otherwise.
bool binarySearch(const std::vector<std::string>& dictionary, const std::string& word);

// Uses the STL unordered_set class to search a dictionary. Returns true
// if the given word is in the dictionary, false otherwise.
bool setSearch(const std::unordered_set<std::string>& dictionary, const std::string& word);
