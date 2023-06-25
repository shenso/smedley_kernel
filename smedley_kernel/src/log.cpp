#include "log.hpp"
#include <ctime>
#include <sstream>

namespace smedley
{

	Logger::Logger(const std::string &prefix, bool use_stderr) : _prefix(prefix), _use_stderr(use_stderr)
	{
	}

	void Logger::Log(Level level, const std::string &msg)
	{
		std::time_t now;
		char time_buf[64];
		std::string level_prefix;
		std::stringstream ss;

		now = std::time(nullptr);
		std::strftime(time_buf, sizeof(time_buf), "[%Y-%m-%d %H:%M:%S]", std::localtime(&now));

		switch (level) {
		case Level::DEBUG:
			level_prefix = "[DEBUG]";
			break;
		case Level::INFO:
			level_prefix = "[INFO]";
			break;
		case Level::WARN:
			level_prefix = "[WARN]";
			break;
		case Level::FAILURE:
			level_prefix = "[FAILURE]";
			break;
		case Level::CRITICAL:
			level_prefix = "[CRITICAL]";
			break;
		}

		ss << time_buf;
		if (!level_prefix.empty())
			ss << " " << level_prefix;
		if (!_prefix.empty())
			ss << " [" << _prefix << "]";

		ss << " " << msg;
		Write(ss.str());
	}

	FileLogger::FileLogger(const std::string &filename, const std::string &prefix, bool use_stderr) :
		Logger(prefix, use_stderr),
		_filename(filename),
		_ostream(filename, std::ios_base::app)
	{
	}

}