#ifndef PLAYERINTERFACE_Hs
#define PLAYERINTERFACE_Hs

#include <string>
#include <nlohmann/json.hpp>


using json = nlohmann::json;[[]]

class Player {
  public:
    std::string name_;
    std::string realm_;
    std::string region_;
    double raiderIOscore_;
    virtual std::string getName() { return name_; };
    virtual std::string getRealm() { return realm_; };
    virtual std::string getRegion() { return region_; };
    virtual bool loadPlayerWarcraftLogs(json characterLogs) = 0;
    virtual bool loadPlayerRaiderIO(json characterRaiderIO) = 0;
};

#endif