#pragma once

#include "user.h"
#include <string>
#include <ctime>
#include "github++/json.h"

namespace github {

class RepositoryData;

class Repository {

public:
  Repository();
  Repository(const Repository &other);
  Repository &operator=(const Repository &other);
  Repository(const nlohmann::json &json);
  ~Repository();

  long id() const;
  User user() const;
  std::string name() const;
  std::string full_name() const;
  std::string description() const;
  std::string homepage() const;
  std::string default_branch() const;
  std::string master_branch() const;
  std::time_t created_at() const;
  std::time_t pushed_at() const;
  std::time_t updated_at() const;
  std::string html_url() const;
  std::string clone_url() const;
  std::string git_url() const;
  std::string mirror_url() const;
  std::string ssh_url() const;
  std::string svn_url() const;
  std::string language() const;
  bool fork() const;
  int fork_count() const;
  int network_count() const;
  int open_issues_count() const;
  int stargazers_count() const;
  int subscribers_count() const;
  int watchers_count() const;
  int size() const;
  bool auto_init() const;
  Repository parent() const;
  Repository source() const;
  bool allow_rebase_merge() const;
  bool allow_squash_merge() const;
  bool allow_merge_commit() const;

private:
  friend std::ostream &operator<<(std::ostream &os, const Repository &repo);
  std::shared_ptr<RepositoryData> d_ptr;
};

std::ostream &operator<<(std::ostream &os, const Repository &repo);
}