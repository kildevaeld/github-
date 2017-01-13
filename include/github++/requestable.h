#pragma once

#include "github++/json.h"
#include "github++/client.h"
namespace github {

class Requestable {

public:
  enum Method { Get, Post, Put, Delete };
  Requestable(const Client &client);

protected:
  nlohmann::json request(Method method, const std::string &path);

private:
  Client m_client;
};
}