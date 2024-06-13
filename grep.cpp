#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

bool match(const std::string& line, const std::string& pattern, bool ignoreCase, bool invertMatch, bool printOnlyCount, bool printOnlyFileName)
{
    std::regex regex(pattern, ignoreCase ? std::regex_constants::icase : std::regex_constants::ECMAScript);

    bool isMatch = std::regex_search(line, regex);

    if (invertMatch)
        isMatch = !isMatch;

    if (printOnlyCount && isMatch)
        return true;

    if (printOnlyFileName && isMatch)
        return true;

    if (!printOnlyFileName && isMatch)
    {
        std::cout << line << std::endl;
        return true;
    }

    return false;
}

void grep(const std::string& pattern, const std::vector<std::string>& files, bool ignoreCase, bool invertMatch, bool printOnlyCount, bool printOnlyFileName, bool suppressErrors, bool fromFile)
{
    if (files.empty())
    {
        std::string line;
        while (std::getline(std::cin, line))
        {
            match(line, pattern, ignoreCase, invertMatch, printOnlyCount, printOnlyFileName);
        }
    }
    else
    {
        for (const std::string& file : files)
        {
            std::ifstream inputFile(file);

            if (!inputFile)
            {
                if (!suppressErrors)
                    std::cerr << "Cannot open file: " << file << std::endl;
                continue;
            }

            std::string line;
            int lineNum = 0;
            while (std::getline(inputFile, line))
            {
                lineNum++;

                if (fromFile)
                {
                    std::ifstream patternFile(pattern);
                    if (!patternFile)
                    {
                        if (!suppressErrors)
                            std::cerr << "Cannot open pattern file: " << pattern << std::endl;
                        continue;
                    }

                    std::string patternLine;
                    while (std::getline(patternFile, patternLine))
                    {
                        if (match(line, patternLine, ignoreCase, invertMatch, printOnlyCount, printOnlyFileName))
                            break;
                    }

                    patternFile.close();
                }
                else
                {
                    if (match(line, pattern, ignoreCase, invertMatch, printOnlyCount, printOnlyFileName))
                        continue;
                }
            }

            inputFile.close();
        }
    }
}

int main(int argc, char* argv[])
{
    std::string pattern;
    std::vector<std::string> files;
    bool ignoreCase = false;
    bool invertMatch = false;
    bool printOnlyCount = false;
    bool printOnlyFileName = false;
    bool suppressErrors = false;
    bool fromFile = false;

    int i = 1;
    while(i < argc)
    {
        std::string arg(argv[i]);

        if (arg == "-e" && i + 1 < argc)
        {
            pattern = argv[i + 1];
            i += 2;
        }
        else if (arg == "-i")
        {
            ignoreCase = true;
            i++;
        }
        else if (arg == "-v")
        {
            invertMatch = true;
            i++;
        }
        else if (arg == "-c")
        {
            printOnlyCount = true;
            i++;
        }
        else if (arg == "-l")
        {
            printOnlyFileName = true;
            i++;
        }
        else if (arg == "-s")
        {
            suppressErrors = true;
            i++;
        }
        else if (arg == "-f" && i + 1 < argc)
        {
            pattern = argv[i + 1];
            fromFile = true;
            i += 2;
        }
        else
        {
            files.push_back(arg);
            i++;
        }
    }

    grep(pattern, files, ignoreCase, invertMatch, printOnlyCount, printOnlyFileName, suppressErrors, fromFile);

    return 0;
}
