#include "PlayerFactory.h"

PlayerFactory::PlayerFactory(WarcraftRunnerData* runnerData) {
  if (runnerData->type_ == "RETAIL") 
    player_ = new RetailWoWPlayer(runnerData->name_, runnerData->realm_, runnerData->region_);
  else
    player_ = NULL; 
}

PlayerFactory::~PlayerFactory() {
  if (player_) { 
    delete player_;
    player_ = NULL;
  } 
} 

Player* PlayerFactory::getPlayer() {
  return player_;
}
