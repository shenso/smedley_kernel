#pragma once

#include "../std/string.hpp"
#include "../std/vector.hpp"

namespace smedley::v2
{

    class CConsoleCmd
    {
    public:
        struct SResult;

        /**
         * Data container for console command metadata and its
         * handler callback.
         */
        struct SCommandData
        {
            bool is_allowed; /// command is only accessible in the dev environment when false
            const char *name;
            int num_aliases;
            const char *aliases[3];
            const char *description;
            SResult (*handler)(const sstd::vector<sstd::string> &argv);
            int num_args;
            const char *args[10];
        };

        static_assert(sizeof(SCommandData) == 0x4c);

        /**
         * The result of an executed console command.
         */
        struct SResult
        {
            bool success;
            sstd::string message;

            SResult(const sstd::string &message, bool success = true) : message(message), success(success)
            {
            }
        };
        
        static_assert(sizeof(SResult) == 0x20);
    };

    class CConsoleCmdManager
    {
    private:
        sstd::vector<CConsoleCmd::SCommandData *> _commands;
    public:
        sstd::vector<CConsoleCmd::SCommandData *> &commands() { return _commands; }
        const sstd::vector<CConsoleCmd::SCommandData *> &commands() const { return _commands; }
    };

    static_assert(sizeof(CConsoleCmdManager) == 0x10);

    class CConsole
    {
    };

}