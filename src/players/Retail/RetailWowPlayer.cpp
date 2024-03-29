#include "RetailWoWPlayer.h"
#include <iostream>

RetailWoWPlayer::RetailWoWPlayer( std::string name, std::string realm, std::string region ) {
  name_ = name;
  realm_ = realm;
  region_ = region;
}

RetailWoWPlayer::~RetailWoWPlayer() {}

bool RetailWoWPlayer::loadPlayerWarcraftLogs(json characterLogs) {
  warcraftLogsParse_ = characterLogs;
  std::cout << "Loaded Warcraft Logs -> Blizzard is dead what's the point of toaderscore NEW WORLD?" << std::endl;
  // for (const auto& item : characterLogs.items()) 
  // {
  //   std::cout << item.key() << "\n";
  //   for (const auto& val : item.value().items())
  //   {
  //     std::cout << "  " << val.key() << ": " << val.value() << "\n";
  //   }
  // }

  return true;
}

bool RetailWoWPlayer::loadPlayerRaiderIO(json characterRaiderIO) {
  raiderIOscore_ = static_cast<float>(characterRaiderIO["mythic_plus_scores_by_season"][0]["scores"]["all"]);
  return true;
}


void RetailWoWPlayer::print(std::ostream& oss) const
{
  oss << "Name : " << name_ << "\n"
      << "Realm : " << realm_ << "\n"
      << "RaiderIO: " << raiderIOscore_ << std::endl;
}