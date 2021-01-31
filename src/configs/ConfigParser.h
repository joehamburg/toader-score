#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "runners/WarcraftRunnerData.h"

class ConfigParser {
    public:
        ConfigParser(WarcraftRunnerData* runnerData);
    private:
        WarcraftRunnerData* runnerData_;
        bool parseLine(std::string key, std::string value);
        bool parseWarcraftLogsLine(std::string key, std::string value);
        bool parseWarcraftLogs(std::string path);
};

#endif
