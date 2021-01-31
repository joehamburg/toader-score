#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include "players/Retail/RetailWoWPlayer.h"
#include "runners/WarcraftRunnerData.h"

class PlayerFactory {
  private: 
    Player *player_;
  public:
    PlayerFactory(WarcraftRunnerData* runnerData);
    ~PlayerFactory();
    Player* getPlayer();
};

#endif
