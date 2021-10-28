#include "RaiderIOLoader.h"


RaiderIOLoader::RaiderIOLoader(Player* player):
  player_(player),
  baseURL_("https://raider.io/api/v1")
  { }


RaiderIOLoader::~RaiderIOLoader() {}


bool RaiderIOLoader::loadPlayerStats() {
  bool retVal = true;
  std::string urlString = baseURL_ + "/characters/profile";
  // ?seems to maybe be too slow? may want to try libcurl
  cpr::Response r = cpr::Get(cpr::Url{urlString},
                    cpr::Parameters{{"name", player_->getName()},
                                    {"realm", player_->getRealm()},
                                    {"region", player_->getRegion()},
                                    {"fields", "mythic_plus_scores_by_season:current"}});
  // Parse repsonse into json object
  json responseJson = json::parse(r.text);

  if ( !player_->loadPlayerRaiderIO(responseJson) ) {
    retVal = false;
  }
  return retVal;
}


bool RaiderIOLoader::getQuantileScore(double quantile, double& quantileScore) {
  bool retVal = true;
  //https://raider.io/api/v1/mythic-plus/season-cutoffs?season=season-sl-2&region=us
  // hardcoded season and faction cause OMEGALUL
  std::string urlString = baseURL_ + "/mythic-plus/season-cutoffs?season=season-sl-2&region=us";
  // ?seems to maybe be too slow? may want to try libcurl
  cpr::Response r = cpr::Get(cpr::Url{urlString});
  // Parse repsonse into json object
  json responseJson = json::parse(r.text);
  //! hardcoded p999
  quantileScore = static_cast<double>(responseJson["cutoffs"]["p999"]["horde"]["quantileMinValue"]);

  return retVal;

}