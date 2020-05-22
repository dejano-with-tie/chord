//
// Created by dejan-osmanovic on 22.5.20..
//

#ifndef CHORD_SRC_UTILS_NETWORKUTILS_H_
#define CHORD_SRC_UTILS_NETWORKUTILS_H_

static const char *const IP_API_URL = "https://api.ipify.org/";

class NetworkUtils {

 public:
  static std::string ip();
};

#endif //CHORD_SRC_UTILS_NETWORKUTILS_H_
