
#include "github++/client.h"

namespace github {

Client::Client(const Credential &creds, const std::string &apiBase)
    : m_auth(creds), m_api(apiBase) {}

Client::~Client() {}
}