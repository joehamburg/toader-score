#include "WarcraftLogsLoader.h"

WarcraftLogsLoader::WarcraftLogsLoader(std::string apiKey, Player* player): 
  apiKey_(apiKey),
  player_(player),
  baseURL_("https://www.warcraftlogs.com:443/v1")
  { }


WarcraftLogsLoader::~WarcraftLogsLoader() {}

bool WarcraftLogsLoader::loadPlayerStats() {
  bool retVal = true;
  std::string urlString = baseURL_ + "/parses/character/"
                                   + player_->getName()
                                   + "/"
                                   + player_->getRealm()
                                   + "/"
                                   + player_->getRegion();
  // ?[[seems to maybe be too slow? may want to try libcurl
  cpr::Response r = cpr::Get(cpr::Url{urlString},
                    cpr::Parameters{{"api_key", apiKey_}});
  // Parse repsonse into json object
  json responseJson = json::parse(r.text);

  if ( !player_->loadPlayerWarcraftLogs(responseJson) ) {
    retVal = false;
  }

  return retVal;
}
