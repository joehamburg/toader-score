#ifndef RETAILWOWPLAYER_H
#define RETAILWOWPLAYER_H

#include "players/PlayerInterface.h"

class RetailWoWPlayer : public Player {
  public:
    RetailWoWPlayer(std::string name, std::string realm, std::string region);
    ~RetailWoWPlayer();
    bool loadPlayerWarcraftLogs(json characterLogs);
    bool loadPlayerRaiderIO(json characterRaiderIO);
    void print(std::ostream& oss) const;
};

#endif