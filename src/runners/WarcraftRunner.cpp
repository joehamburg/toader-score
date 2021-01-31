#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <sys/stat.h>
#include "factories/Player/PlayerFactory.h"
#include "configs/ConfigParser.h"
#include "loaders/WarcraftLogs/WarcraftLogsLoader.h"
#include "loaders/RaiderIO/RaiderIOLoader.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

inline bool fileExists (const std::string& name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0); 
}

int main(int argc, char* argv[]) {

  // Check the number of parameters
  if (argc < 2) {
    // Tell the user how to run the program
    std::cerr << "Usage: " << argv[0] << " /path/to/config" << std::endl;
    return 1;
  }

  // Check to make sure config file exists
  if ( !fileExists(argv[1]) ) {
    std::cerr << "Error: file does not exist" << std::endl;
    return 1;
  }

  WarcraftRunnerData* runnerData = new WarcraftRunnerData;
  runnerData->configPath_ =  argv[1];

  // Parse Config
  ConfigParser* configParser = new ConfigParser(runnerData);

  // Load info into the correct Player type
  PlayerFactory* PF = new PlayerFactory(runnerData);
  Player* player = PF->getPlayer();

  // !TODD: Need a loader factory that loads based on Warcraft Runner Config vals idk call me maybe????
  WarcraftLogsLoader* testLoader = new WarcraftLogsLoader(runnerData->apiKey_, player);
  if ( !testLoader->loadPlayerStats() ) {
    std::cerr << "Error: could not load Warcraft logs" << std::endl;
    return 1;
  }

  RaiderIOLoader* test2Loader = new RaiderIOLoader(player);
  if ( !test2Loader->loadPlayerStats() ) {
    std::cerr << "Error: could not load Warcraft logs" << std::endl;
    return 1;
  }
  std::cout << player->raiderIOscore_ << std::endl;

  // Cleanup
  delete configParser;
  delete runnerData;
  delete PF;
}
