#ifndef WARCRAFTRUNNERDATA_H
#define WARCRAFTRUNNERDATA_H


struct WarcraftRunnerData {
  std::string type_,
              name_,
              realm_,
              configPath_,
              warcraftLogsConfig_,
              apiKey_,
              region_;
  WarcraftRunnerData() :
    type_(""),
    name_(""),
    realm_(""),
    region_(""),
    configPath_(""),
    apiKey_("")
  {}
};

#endif
