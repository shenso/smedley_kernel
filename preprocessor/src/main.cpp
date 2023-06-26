#include <cstring>
#include <filesystem>
#include <iostream>
#include <stdexcept>

constexpr int RET_INVALID_USAGE = 1;
constexpr int RET_FAILURE = 2;

void PreprocessFile(const std::string &in_filename, const std::string &out_filename);
void PreprocessDirectory(const std::string &dir);

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cerr << "invalid arguments! usage:" << std::endl;
        std::cerr << "\tpreprocessor <input file> <output file>" << std::endl;
        std::cerr << "\tpreprocessor -R <dir>" << std::endl;
        return RET_INVALID_USAGE;
    }

    try {
        if (std::strcmp(argv[1], "-R") == 0) {
            PreprocessDirectory(argv[2]);
        } else {
            PreprocessFile(argv[1], argv[2]);
        }
    } catch (std::runtime_error &e) {
        std::cerr << "preprocessor failure: " << e.what() << std::endl;
        return RET_FAILURE;
    }

    return 0;
}

void PreprocessFile(const std::string &in_filename, const std::string &out_filename)
{
    auto in_fs = std::filesystem::status(in_filename);
    auto out_fs = std::filesystem::status(out_filename);

    if (!std::filesystem::is_regular_file(in_fs))
        throw std::runtime_error("input file '" + in_filename + "' does not exist!");
    if (!std::filesystem::is_regular_file(out_fs))
        throw std::runtime_error("output file '" + out_filename + "' does not exist!");
}

void PreprocessDirectory(const std::string &dir)
{
    auto dir_fs = std::filesystem::status(dir);

    if (!std::filesystem::is_directory(dir_fs))
        throw std::runtime_error("directory '" + dir + "' is not a directory!");
}