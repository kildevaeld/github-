
#include <github++/github++.h>

int main() {

  github::Client client;

  github::Repositories repo(client);

  auto repos = repo.list_public("kildevaeld");

  for (auto i : repos) {
    std::cout << i << std::endl;
  }
}