# Lab 14: Dictionary Lookup

In this lab, you will implement three different algorithms to determine whether a given word is in the dictionary:

* Linear search
* Binary search
* STL set container

You will also measure the performance of each one to determine its rate of growth.

The dictionary words are provided for you in the file `dictionary.txt` along with some unit tests and benchmark tests in `dictionary_test.cpp`. There is also a `main.cpp` program for exploratory testing and debugging is needed. The helper function `loadDictionary` is used by the unit tests, and you can invoke it from `main` as well. (See the unit tests for examples of how to use `loadDictionary`.)

## Part 1: Dictionary Lookup Implementation

Begin by studying the function prototypes in `dictionary.h`. You should already be familiar with vectors, linear search, and binary search. The `unordered_set` class may be new to you, but you only need to know that it models a mathematical set: a container of elements with no duplicates.

Next, implement the missing code in `dictionary.cpp` for all three algorithms:

* You should be able to implement a linear search easily.
* For the binary search, you may copy and paste a C++ implementation from a past project, or you can look up the pseudocode for binary search online (such as [Wikipedia](https://en.wikipedia.org/wiki/Binary_search_algorithm)) and implement the C++ version of it.
* For the set, use the `count` method to determine if a word exists. (For more details see [cppreference.com](https://en.cppreference.com/w/cpp/container/unordered_set).)

After implementing all three functions, run the unit tests to make sure they work correctly. Do not move on to the next part until both unit tests pass.

## Part 2: Algorithm Benchmarking

In `dictionary_test.cpp` you will notice that the benchmark tests have been commented out. Uncomment them to enable them.

To collect the benchmarks, do not run the unit tests the usual way because the benchmark output is hidden by default. Instead, use the `CMake: Set Debug Target` command to select the `lab14_tests` target, then run the benchmarks using `CMake: Run Without Debugging` (or press Shift+F5 or click the little triangle in the status bar). The salient output is the "mean" field, which is in the second row, first column of each benchmark.

If you have a fast computer and your benchmarks are on the order of nanoseconds, you can get better results by adding an artificial delay in your code to emulate a slower computer. For example, in the binary search implementation, you can add a 2-millisecond delay inside the loop by calling `sleep_for`:

    #include <chrono>
    #include <thread>
    ...
    bool binarySearch(const vector<string>& dictionary, const string& word) {
        ...
        while (left <= right) {
            std::this_thread::sleep_for(2ms);
            ...
        }
    }

If your benchmark tests are taking a few minutes to run, then the artificial delay is too large and should be reduced.

## Part 3: Algorithm Graphing

Finally, graph the benchmark results using the [Desmos Graphing Calculator](https://www.desmos.com/calculator), pen and paper, or a tool of your choice.

If using Desmos:

1. Click the `+` (plus) button and choose Table.
2. Put the dictionary size in the X column and the time needed to do the lookup in the Y column. Be careful with the units! You may need to adjust the numbers so that they are all on the same scale. One trick that usually works is to convert all of the times to milliseconds.
3. Click the gear icon, then click the colored circle next to the Y column to see the series options. Enable the Lines option.
4. Click the wrench icon (top right of page) and adjust the viewport to fit the data. Set the horizontal range to 0 < x < 400 and the vertical range to something appropriate for your results (0 < y < maximum).

Compare the plot of your results to the growth curves of the 7 functions used in the book. Which ones do they most closely resemble?
