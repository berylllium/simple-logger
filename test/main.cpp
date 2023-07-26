#include <simple-logger.hpp>

#include <chrono>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <cfloat>

#define TEST_MSG "This is a test message. 2.718281828459"

#define TIME(to_time, var_name)					\
duration<double, std::milli> var_name;			\
{												\
	auto t1 = high_resolution_clock::now(); 	\
	to_time 									\
	auto t2 = high_resolution_clock::now(); 	\
												\
	var_name = t2 - t1;							\
}												

using namespace std::chrono;

double calculate_mean(std::vector<double>& v)
{
	return std::reduce(v.begin(), v.end()) / static_cast<double>(v.size());
}

double calculate_median(std::vector<double>& v)
{
	size_t n = v.size() / 2;
	nth_element(v.begin(), v.begin()+n, v.end());
	return v[n];
}

bool compare_freq(const std::pair<double,int>& p1, const std::pair<double,int>& p2) 
{ 
    return (p1.second > p2.second); 
}

std::vector<std::pair<double, int>> calculate_mode(std::vector<double>& v)
{
	std::unordered_map<double,int> freq_map;

    for (double elem : v)
	{
        freq_map[elem]++;
    }

	std::vector<std::pair<double,int>> freq_vec(freq_map.begin(), freq_map.end());

    sort(freq_vec.begin(), freq_vec.end(), compare_freq);

	return freq_vec;
}

std::pair<double, double> calculate_range(std::vector<double>& v)
{
	double min = DBL_MAX;
	double max = 0;

	for (double d : v)
	{
		if (d < min)
		{
			min = d;
			continue;
		}

		if (d > max)
		{
			max = d;
		}
	}

	return { min, max };
}

void print_results(std::vector<double>& v, std::string test_desc)
{
	double mean = calculate_mean(v);
	double median = calculate_median(v);
	std::vector<std::pair<double, int>> modes = calculate_mode(v);
	std::pair<double, double> range = calculate_range(v);

	std::unordered_map<double, int> freq_map;

	for (double d : v)
	{
		freq_map[d]++;
	}

	std::cout << test_desc << '\n' <<
		"\tMean: " << mean <<
		"\n\tMedian: "<< median <<
		"\n\tMode: " << modes[0].first << " Count: " << modes[0].second <<
		"\n\tRange: min: " << range.first << " (Count: " << freq_map[range.first] << ") max: " << range.second << " (Count: " << freq_map[range.second] << ')' <<
		std::endl;
}

int main()
{
	sl::set_log_to_file(false);
	sl::set_flush_on_log(true);
	sl::set_log_time(false);
	
	const int iter_count = 100000;
	std::vector<double> t1_durations(iter_count);

	for (int i = 0; i < iter_count; i++)
	{
		TIME(sl::log_info(TEST_MSG);, td)

		t1_durations[i] = td.count();
	}

	sl::set_log_to_file(true);

	std::vector<double> t2_durations(iter_count);

	for (int i = 0; i < iter_count; i++)
	{
		TIME(sl::log_info(TEST_MSG);, td)

		t2_durations[i] = td.count();
	}

	sl::set_log_to_file(false);
	sl::set_log_time(true);

	std::vector<double> t3_durations(iter_count);

	for (int i = 0; i < iter_count; i++)
	{
		TIME(sl::log_info(TEST_MSG);, td)

		t3_durations[i] = td.count();
	}

	std::vector<double> t4_durations(iter_count);

	for (int i = 0; i < iter_count; i++)
	{
		TIME(std::cout << TEST_MSG << '\n';, td)

		t4_durations[i] = td.count();
	}
	
	// Print types.
	sl::log_info("Testing integer {}", 12);

	print_results(t1_durations, "Test #1: sl::log execution time. (No writing to file)");
	print_results(t2_durations, "Test #2: sl::log execution time. (Writing to file)");
	print_results(t3_durations, "Test #3: sl::log execution time. (No writing to file, logging time.)");
	print_results(t4_durations, "Test #4: std::cout execution time.");

	return 0;
}
