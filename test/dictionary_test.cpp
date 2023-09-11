#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "dictionary.h"
#include "dictionary_file.h"

using namespace std;

const string KNOWN_WORD = "college";
const string UNKNOWN_WORD = "zzzzzzzz";

TEST_CASE("Searching a dictionary word is successful")
{
    vector<string> dictionary;
    unordered_set<string> dictionarySet;
    loadDictionary(0, [&dictionary](const string& word) { dictionary.push_back(word); });
    loadDictionary(0, [&dictionarySet](const string& word) { dictionarySet.insert(word); });
    REQUIRE(linearSearch(dictionary, KNOWN_WORD));
    REQUIRE(binarySearch(dictionary, KNOWN_WORD));
    REQUIRE(setSearch(dictionarySet, KNOWN_WORD));
}

TEST_CASE("Searching a non-dictionary word is unsuccessful")
{
    vector<string> dictionary;
    unordered_set<string> dictionarySet;
    loadDictionary(0, [&dictionary](const string& word) { dictionary.push_back(word); });
    loadDictionary(0, [&dictionarySet](const string& word) { dictionarySet.insert(word); });
    REQUIRE_FALSE(linearSearch(dictionary, UNKNOWN_WORD));
    REQUIRE_FALSE(binarySearch(dictionary, UNKNOWN_WORD));
    REQUIRE_FALSE(setSearch(dictionarySet, UNKNOWN_WORD));
}

/*
TEST_CASE("Linear search benchmark")
{
    BENCHMARK_ADVANCED("50k words")(Catch::Benchmark::Chronometer meter) {
        vector<string> dictionary;
        loadDictionary(50000, [&dictionary](const string& word) { dictionary.push_back(word); });
        meter.measure([&dictionary] {
            return linearSearch(dictionary, UNKNOWN_WORD);
        });
    };

    BENCHMARK_ADVANCED("100k words")(Catch::Benchmark::Chronometer meter) {
        vector<string> dictionary;
        loadDictionary(100000, [&dictionary](const string& word) { dictionary.push_back(word); });
        meter.measure([&dictionary] {
            return linearSearch(dictionary, UNKNOWN_WORD);
        });
    };

    BENCHMARK_ADVANCED("150k words")(Catch::Benchmark::Chronometer meter) {
        vector<string> dictionary;
        loadDictionary(150000, [&dictionary](const string& word) { dictionary.push_back(word); });
        meter.measure([&dictionary] {
            return linearSearch(dictionary, UNKNOWN_WORD);
        });
    };

    BENCHMARK_ADVANCED("200k words")(Catch::Benchmark::Chronometer meter) {
        vector<string> dictionary;
        loadDictionary(200000, [&dictionary](const string& word) { dictionary.push_back(word); });
        meter.measure([&dictionary] {
            return linearSearch(dictionary, UNKNOWN_WORD);
        });
    };

    BENCHMARK_ADVANCED("300k words")(Catch::Benchmark::Chronometer meter) {
        vector<string> dictionary;
        loadDictionary(300000, [&dictionary](const string& word) { dictionary.push_back(word); });
        meter.measure([&dictionary] {
            return linearSearch(dictionary, UNKNOWN_WORD);
        });
    };
}
*/

/*
TEST_CASE("Binary search benchmark")
{
    BENCHMARK_ADVANCED("25k words")(Catch::Benchmark::Chronometer meter) {
        vector<string> dictionary;
        loadDictionary(25000, [&dictionary](const string& word) { dictionary.push_back(word); });
        meter.measure([&dictionary] {
            return binarySearch(dictionary, UNKNOWN_WORD);
        });
    };

    BENCHMARK_ADVANCED("50k words")(Catch::Benchmark::Chronometer meter) {
        vector<string> dictionary;
        loadDictionary(50000, [&dictionary](const string& word) { dictionary.push_back(word); });
        meter.measure([&dictionary] {
            return binarySearch(dictionary, UNKNOWN_WORD);
        });
    };

    BENCHMARK_ADVANCED("100k words")(Catch::Benchmark::Chronometer meter) {
        vector<string> dictionary;
        loadDictionary(100000, [&dictionary](const string& word) { dictionary.push_back(word); });
        meter.measure([&dictionary] {
            return binarySearch(dictionary, UNKNOWN_WORD);
        });
    };

    BENCHMARK_ADVANCED("150k words")(Catch::Benchmark::Chronometer meter) {
        vector<string> dictionary;
        loadDictionary(150000, [&dictionary](const string& word) { dictionary.push_back(word); });
        meter.measure([&dictionary] {
            return binarySearch(dictionary, UNKNOWN_WORD);
        });
    };

    BENCHMARK_ADVANCED("200k words")(Catch::Benchmark::Chronometer meter) {
        vector<string> dictionary;
        loadDictionary(200000, [&dictionary](const string& word) { dictionary.push_back(word); });
        meter.measure([&dictionary] {
            return binarySearch(dictionary, UNKNOWN_WORD);
        });
    };

    BENCHMARK_ADVANCED("250k words")(Catch::Benchmark::Chronometer meter) {
        vector<string> dictionary;
        loadDictionary(250000, [&dictionary](const string& word) { dictionary.push_back(word); });
        meter.measure([&dictionary] {
            return binarySearch(dictionary, UNKNOWN_WORD);
        });
    };

    BENCHMARK_ADVANCED("300k words")(Catch::Benchmark::Chronometer meter) {
        vector<string> dictionary;
        loadDictionary(300000, [&dictionary](const string& word) { dictionary.push_back(word); });
        meter.measure([&dictionary] {
            return binarySearch(dictionary, UNKNOWN_WORD);
        });
    };
}
*/

/*
TEST_CASE("Set search benchmark")
{
    BENCHMARK_ADVANCED("50k words")(Catch::Benchmark::Chronometer meter) {
        unordered_set<string> dictionary;
        loadDictionary(50000, [&dictionary](const string& word) { dictionary.insert(word); });
        meter.measure([&dictionary] {
            return setSearch(dictionary, UNKNOWN_WORD);
        });
    };

    BENCHMARK_ADVANCED("100k words")(Catch::Benchmark::Chronometer meter) {
        unordered_set<string> dictionary;
        loadDictionary(100000, [&dictionary](const string& word) { dictionary.insert(word); });
        meter.measure([&dictionary] {
            return setSearch(dictionary, UNKNOWN_WORD);
        });
    };

    BENCHMARK_ADVANCED("200k words")(Catch::Benchmark::Chronometer meter) {
        unordered_set<string> dictionary;
        loadDictionary(200000, [&dictionary](const string& word) { dictionary.insert(word); });
        meter.measure([&dictionary] {
            return setSearch(dictionary, UNKNOWN_WORD);
        });
    };

    BENCHMARK_ADVANCED("300k words")(Catch::Benchmark::Chronometer meter) {
        unordered_set<string> dictionary;
        loadDictionary(300000, [&dictionary](const string& word) { dictionary.insert(word); });
        meter.measure([&dictionary] {
            return setSearch(dictionary, UNKNOWN_WORD);
        });
    };
}
*/
