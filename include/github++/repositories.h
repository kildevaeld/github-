#pragma once
#include <string>
#include "github++/requestable.h"
#include "repository.h"

namespace github {

struct ListCommitsOptions {};

class Repositories : Requestable {

public:
  Repositories(const Client &client);
  ~Repositories();

  std::vector<Repository> list_public(const std::string &user);
};
}