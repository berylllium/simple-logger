# simple-logger

A simple C++20 logging library.

## About

simple-logger is a simple logging library that uses C++20 features.

## Example

```cpp
#include <simple_logger.hpp>

int main()
{
    int x = 3;
    float f = 3.1416;

    // Configure SL.
    sl::set_log_to_file(true);
    
    // Start logging.
    sl::log_info("Welcome to my program!");

    sl::log_info("The number of the day is: {}", f);

    sl::log_warn("x is equal to {}!?", x);

    sl::log_fatal("Something went wrong, closing program.");

    return -1;
}
```

## Configuring

Configuring simple-logger is as simple as calling a few global functions.

| Configuration Name | Example Use                             | Description                                                     | Default Value |
|--------------------|-----------------------------------------|-----------------------------------------------------------------|---------------|
| `log_to_file`      | `sl::set_log_to_file(true);`            | Whether to also log to a file.                                  | `false`       |
| `flush_on_log`     | `sl::set_flush_on_log(true);`           | Whether to flush the file stream on each log.                   | `true`        |
| `log_time`         | `sl::set_log_time(true);`               | Whether to log the time in the prefix.                          | `true`        |
| `log_file_path`    | `sl::set_log_file_path("log/log.txt");` | The file path of the log file.                                  | `"./log.txt"` |
| `log_prefix`       | `sl::set_log_prefix("##");`             | The prefix for each log. Can be a single character or a string. | `"$"`         |

## Usage

Simple-logger 6 different log levels:

```cpp
FATAL = 0,
ERROR = 1,
WARN = 2,
INFO = 3,
DEBUG = 4,
TRACE = 5
```

Logging a certain level is as simple as calling that levels log function:

```cpp
sl::log_info("I'm logging to info!");
```

Simple-logger has full support for `std::format` message formatting:
```cpp
sl::log_info("Welcome, {}, to this test message. You are currently {}.", user.name, user.status);
```

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
