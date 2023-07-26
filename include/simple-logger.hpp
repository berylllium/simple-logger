#pragma once

#include <type_traits>
#include <concepts>
#include <string>
#include <format>

namespace sl
{

enum class LogLevel
{
	FATAL = 0,
	ERROR = 1,
	WARN = 2,
	INFO = 3,
	DEBUG = 4,
	TRACE = 5
};

// --- Internal Log Function ---

void _log(LogLevel log_level, std::string parsed_message);

// --- Configuration Setters ---

void set_log_to_file(bool save_to_file);

void set_flush_on_log(bool flush);

void set_log_time(bool time);

void set_log_file_path(std::string path);

void set_log_prefix(std::string prefix);

// --- Log Functions ---

template<typename... P>
void log(LogLevel log_level, std::string message, P... args)
{
	_log(log_level, std::vformat(message, std::make_format_args(args...)));
}

template<typename... P>
void log_fatal(std::string message, P... args)
{
	log(LogLevel::FATAL, message, args...);
}

template<typename... P>
void log_error(std::string message, P... args)
{
	log(LogLevel::ERROR, message, args...);
}

template<typename... P>
void log_warn(std::string message, P... args)
{
	log(LogLevel::WARN, message, args...);
}

template<typename... P>
void log_info(std::string message, P... args)
{
	log(LogLevel::INFO, message, args...);
}

template<typename... P>
void log_debug(std::string message, P... args)
{
	log(LogLevel::DEBUG, message, args...);
}

template<typename... P>
void log_trace(std::string message, P... args)
{
	log(LogLevel::TRACE, message, args...);
}

}
