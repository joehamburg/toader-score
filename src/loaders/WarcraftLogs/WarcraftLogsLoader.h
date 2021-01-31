#ifndef WARCRAFTLOGSLOADER_H
#define WARCRAFTLOGSLOADER_H


#include <cpr/cpr.h>
#include <sstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "players/PlayerInterface.h"

using json = nlohmann::json;

class WarcraftLogsLoader {
  private:
    std::string apiKey_;
    std::string baseURL_;
    Player* player_;
  public:
    WarcraftLogsLoader(std::string apiKey, Player* player);
    ~WarcraftLogsLoader();
    bool loadPlayerStats();
};

#endif
