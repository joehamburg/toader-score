#include "ConfigParser.h"

ConfigParser::ConfigParser(WarcraftRunnerData* runnerData) {
    runnerData_ = runnerData;
    std::ifstream cFile(runnerData_->configPath_.c_str());
    if (cFile.is_open())
    {
        std::string line;
        while(getline(cFile, line)) {
            line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
            if(line[0] == '#' || line.empty())
                continue;
            auto delimiterPos = line.find("=");
            std::string key = line.substr(0, delimiterPos);
            std::string value = line.substr(delimiterPos + 1);
            if (! parseLine(key, value) ) {
                std::cerr << "Found key in cfg file that is not NAME, TYPE, or REALM" << std::endl;
            } 
        }
        
    }
    else {
        std::cerr << "Couldn't open the path specified in WarcraftRunnnerData." << std::endl;
    }
}


bool ConfigParser::parseLine(std::string key, std::string value)
{
    if ( key == "REALM" )
        runnerData_->realm_ = value;
    else if ( key == "TYPE" )
        runnerData_->type_ = value;
    else if ( key == "NAME" )
        runnerData_->name_ = value;
    else if ( key == "REGION" )
        runnerData_->region_ = value;
    else if ( key == "WARCRAFT_LOGS_CONFIG" )
        parseWarcraftLogs(value);
    else
        return false;

    return true;
}


bool ConfigParser::parseWarcraftLogs(std::string path) 
{
    bool rc = false;
    std::ifstream cFile(path.c_str());
    if (cFile.is_open())
    {
        std::string line;
        while( getline(cFile, line) ) {
            line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
            if(line[0] == '#' || line.empty())
                continue;
            auto delimiterPos = line.find("=");
            std::string key = line.substr(0, delimiterPos);
            std::string value = line.substr(delimiterPos + 1);
            if (! parseWarcraftLogsLine(key, value) ) {
                std::cerr << "Found key in cfg file that is not API_KEY" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Can't open Warcraft logs config" << std::endl;
    }
    rc = true;
    return rc;
}


bool ConfigParser::parseWarcraftLogsLine(std::string key, std::string value) {
    if ( key == "API_KEY" )
    {
        runnerData_->apiKey_ = value;
    }
    else
        return false;

    return true;
}
