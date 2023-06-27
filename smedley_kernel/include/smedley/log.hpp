#pragma once

#include <cstdint>
#include <fstream>
#include <memory>
#include <string>

namespace smedley
{

    /**
     * Basic Logger interface. Allows for logging at different
     * log levels.
     */
    class Logger
    {
        std::string _prefix;
        bool _use_stderr;
    public:
        enum class Level : uint32_t
        {
            DEBUG = 0,
            INFO = 1,
            WARN = 2,
            FAILURE = 3,
            CRITICAL = 4,
        };

        Logger(const std::string &prefix = "", bool use_stderr = true);
        virtual ~Logger() {}

        void Log(Level level, const std::string &msg);

        void Debug(const std::string &msg) { Log(Level::DEBUG, msg); }
        void Info(const std::string &msg) { Log(Level::INFO, msg); }
        void Warn(const std::string &msg) { Log(Level::WARN, msg); }
        void Failure(const std::string &msg) { Log(Level::FAILURE, msg); }
        void Critical(const std::string &msg) { Log(Level::CRITICAL, msg); }
    protected:
        virtual void Write(const std::string &data) = 0;
    };

    /**
     * The FileLogger is a Logger which outputs to a file stream.
     */
    class FileLogger : public Logger
    {
        std::string _filename;
        std::ofstream _ostream;
    public:
        FileLogger(const std::string &filename, const std::string &prefix = "", bool use_stderr = true);
    protected:
        void Write(const std::string &data) override
        {
            _ostream << data << std::endl;
        }
    };

}