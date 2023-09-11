#pragma once

#include <functional>
#include <string>

// Reads the dictionary.txt file into memory and invokes the processWord callback for
// each word it encounters.
void loadDictionary(int limit, std::function<void(const std::string& line)> processWord);
