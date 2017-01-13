
#include "github++/requestable.h"
#include "github++/client.h"
#include "cpr/cpr.h"
#include "github++/error.h"
using nlohmann::json;

namespace github {

Requestable::Requestable(const Client &client) : m_client(client) {}

nlohmann::json Requestable::request(Method method, const std::string &path) {
  std::cout << m_client.m_api + path << std::endl;
  std::string url(m_client.m_api + "/" + path);
  cpr::Response r;
  switch (method) {
  case Get:
    r = cpr::Get(url);
    break;
  case Post:
    r = cpr::Post(url);
    break;
  default:
    return json();
  }

  auto out = json::parse(r.text);

  if (r.status_code >= 400) {
    throw Exception(out["message"].get<std::string>().c_str());
  }

  return out;
}
}
