#pragma once
#include <string>

namespace github {

namespace urls {

std::string repositories(const std::string &user) {
  return "users/" + user + "/repos";
}
}
}