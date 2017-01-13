#pragma once
#include <string>

namespace github {

struct Credential {};

class Client {

public:
  Client(const Credential &creds = Credential(),
         const std::string &apiBase = "https://api.github.com");
  ~Client();

private:
  friend class Requestable;
  Credential m_auth;
  std::string m_api;
};
}