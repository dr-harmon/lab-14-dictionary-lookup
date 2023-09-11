#include "dictionary_file.h"
#include <fstream>

using namespace std;

void loadDictionary(int limit, function<void(const string& line)> processWord)
{
    int wordCount = 0;
    ifstream dictionaryFile(DICTIONARY_PATH);
    while (dictionaryFile.good()) {
        string word;
        dictionaryFile >> word;
        if (word.length() > 0) {
            processWord(word);
            wordCount++;
        }
        if (limit > 0 && wordCount == limit) {
            break;
        }
    }
}
