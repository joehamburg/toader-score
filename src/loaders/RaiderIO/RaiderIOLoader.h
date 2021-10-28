#ifndef RAIDERIOLOADER_H
#define RAIDERIOLOADER_H


#include <cpr/cpr.h>
#include <sstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "players/PlayerInterface.h"

using json = nlohmann::json;

class RaiderIOLoader {
  private:
    std::string apiKey_;
    std::string baseURL_;
    Player* player_;
  public:
    RaiderIOLoader(Player* player);
    ~RaiderIOLoader();
    bool loadPlayerStats();
    bool getQuantileScore(double quantile, double& quantileScore);
};

#endif