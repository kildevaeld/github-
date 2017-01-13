
#include "github++/repositories.h"
#include "github++/client.h"
#include "github++/error.h"
#include "github++/api_urls.h"

#include "cpr/cpr.h"
#include "github++/json.h"

#include <iostream>
namespace github {

Repositories::Repositories(const Client &client) : Requestable(client) {}
Repositories::~Repositories() {}

std::vector<Repository> Repositories::list_public(const std::string &user) {

  auto result = this->request(Get, urls::repositories(user));

  if (!result.is_array()) {
    throw Exception("not an array");
  }

  std::vector<Repository> out;

  for (int i = 0; i < result.size(); i++) {
    nlohmann::json j = result[i];
    out.push_back(Repository(j));
  }

  return out;
}
}