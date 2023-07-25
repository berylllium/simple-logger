#include <simple-logger.hpp>

int main()
{
	sl::set_log_to_file(true);
	sl::log_info("Hello");
}
