#include "simple-logger.hpp"

#include <format>
#include <filesystem>
#include <fstream>
#include <iostream>

// --- Config Static Vars ---

static bool log_to_file = false;
static bool flush_on_log = true;
static std::filesystem::path log_file_path = "./log.txt";
static std::string log_prefix = "$";

namespace sl
{

void set_log_to_file(bool log_file)
{
	log_to_file = log_file;
}

void set_flush_on_log(bool flush)
{
	flush_on_log = flush;
}

void set_log_file_path(std::string path)
{
	log_file_path = path;
}

void set_log_prefix(std::string prefix)
{
	log_prefix = prefix;
}

void _log(LogLevel log_level, std::string parsed_message)
{
	unsigned int int_log_level = static_cast<unsigned int>(log_level);

	bool is_error = log_level <= LogLevel::ERROR;

	std::string level_strings[] = { "[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: " };

	std::string log = log_prefix + level_strings[int_log_level] + parsed_message;

	if (log_to_file)
	{
		static std::ofstream log_file(log_file_path, std::ios::out | std::ios::app);

		log_file << log << '\n';

		if (flush_on_log) log_file.flush();
	}

	std::string color_strings[] = { "0;41", "1;31", "1;33", "1;32", "1;34", "1;30" };
	
	std::string parsed_log = std::format("\033[{}m{}\033[0m", color_strings[int_log_level], log);

	(is_error ? std::cerr : std::cout) << parsed_log << '\n';

	if (flush_on_log) std::cout.flush();
}

}
