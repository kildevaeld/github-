#pragma once
#include <string>

namespace github {

struct Author {
  std::string auther;
  int id;
  std::string avatar_url;
  std::string url;
  std::string html_url;
  std::string followers_url;
  bool site_admin;
};

struct Commit {
  std::string url;
  std::string sha;
  std::string html_url;
  std::string comments_url;
};

struct CommitInfo {
  std::string url;
  Author author;
  Author committer;
};
}
