# simple-logger

A simple C++20 logging library.

## About

simple-logger is a simple logging library that uses C++20 features.

## Performance

This repository includes a testing directory which times and compares the library's logging functionality with simply printing to the standard output.

Below you'll find the results of the tests that I've ran on my own hardware. Feel free to run the tests on your own. The units are in milliseconds (ms).

```
Test #1: sl::log execution time. (No writing to file)
        Mean: 0.0116723
        Median: 0.009498
        Mode: 0.009498 Count: 5474
        Range: min: 0.006565 (Count: 2) max: 4.28482 (Count: 1)

Test #2: sl::log execution time. (Writing to file)
        Mean: 0.0113812
        Median: 0.010476
        Mode: 0.010127 Count: 5828
        Mode: 0.009498 Count: 5474
        Range: min: 0.006565 (Count: 2) max: 4.28482 (Count: 1)

Test #2: sl::log execution time. (Writing to file)
        Mean: 0.0113812
        Median: 0.010476
        Mode: 0.010127 Count: 5828
        Range: min: 0.00845 (Count: 1) max: 3.53549 (Count: 1)

Test #3: sl::log execution time. (No writing to file, logging time.)
        Mean: 0.0135992
        Median: 0.013339
        Mode: 0.01327 Count: 6945
        Range: min: 0.011105 (Count: 1) max: 0.086812 (Count: 1)

Test #4: std::cout execution time.
        Mean: 0.00997613
        Median: 0.003422
        Mode: 0.003352 Count: 11216
        Range: min: 0.000908 (Count: 9) max: 7.30048 (Count: 1)
```
