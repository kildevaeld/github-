#include "github++/repository.h"

namespace github {

class RepositoryData {

public:
  RepositoryData() {}
  long id;
  User user;
  std::string name;
  std::string full_name;
  std::string description;
  bool private_repo;
  std::string homepage;
  std::string default_branch;
  std::string master_branch;
  std::time_t created_at;
  std::time_t pushed_at;
  std::time_t updated_at;
  std::string html_url;
  std::string clone_url;
  std::string git_url;
  std::string mirror_url;
  std::string ssh_url;
  std::string svn_url;
  std::string language;
  bool fork;
  int fork_count;
  int network_count;
  int open_issues_count;
  int stargazers_count;
  int subscribers_count;
  int watchers_count;
  int size;
  bool auto_init;
  Repository parent;
  Repository source;
  bool allow_rebase_merge;
  bool allow_squash_merge;
  bool allow_merge_commit;
};

Repository::Repository() {}
Repository::Repository(const Repository &other) : d_ptr(other.d_ptr) {}
Repository &Repository::operator=(const Repository &other) {
  if (&other == this) {
    return *this;
  }

  d_ptr = other.d_ptr;

  return *this;
}

Repository::Repository(const nlohmann::json &json)
    : d_ptr(new RepositoryData()) {
  d_ptr->id = json["id"];
  d_ptr->name = json["name"];
  d_ptr->full_name = json["full_name"];
  if (!json["description"].is_null()) {
    d_ptr->description = json["description"];
  }
  d_ptr->private_repo = json["private"];
  d_ptr->fork = json["fork"];
  if (!json["homepage"].is_null())
    d_ptr->homepage = json["homepage"];
  d_ptr->size = json["size"];

  if (!json["language"].is_null()) {
    d_ptr->language = json["language"];
  }
}
Repository::~Repository() {}

long Repository::id() const { return d_ptr->id; }
User Repository::user() const { return d_ptr->user; }
std::string Repository::name() const { return d_ptr->name; }
std::string Repository::full_name() const { return d_ptr->full_name; }
std::string Repository::description() const { return d_ptr->description; }
std::string Repository::homepage() const { return d_ptr->homepage; }
std::string Repository::default_branch() const { return d_ptr->default_branch; }
std::string Repository::master_branch() const { return d_ptr->master_branch; }
std::time_t Repository::created_at() const { return d_ptr->created_at; }
std::time_t Repository::pushed_at() const { return d_ptr->pushed_at; }
std::time_t Repository::updated_at() const { return d_ptr->updated_at; }
std::string Repository::html_url() const { return d_ptr->html_url; }
std::string Repository::clone_url() const { return d_ptr->clone_url; }
std::string Repository::git_url() const { return d_ptr->git_url; }
std::string Repository::mirror_url() const { return d_ptr->mirror_url; }
std::string Repository::ssh_url() const { return d_ptr->ssh_url; }
std::string Repository::svn_url() const { return d_ptr->svn_url; }
std::string Repository::language() const { return d_ptr->language; }
bool Repository::fork() const { return d_ptr->fork; }
int Repository::fork_count() const { return d_ptr->fork_count; }
int Repository::network_count() const { return d_ptr->network_count; }
int Repository::open_issues_count() const { return d_ptr->open_issues_count; }
int Repository::stargazers_count() const { return d_ptr->stargazers_count; }
int Repository::subscribers_count() const { return d_ptr->subscribers_count; }
int Repository::watchers_count() const { return d_ptr->watchers_count; }
int Repository::size() const { return d_ptr->size; }
bool Repository::auto_init() const { return d_ptr->auto_init; }
Repository Repository::parent() const { return d_ptr->parent; }
Repository Repository::source() const { return d_ptr->source; }
bool Repository::allow_rebase_merge() const {
  return d_ptr->allow_rebase_merge;
}
bool Repository::allow_squash_merge() const {
  return d_ptr->allow_squash_merge;
}
bool Repository::allow_merge_commit() const {
  return d_ptr->allow_merge_commit;
}

std::ostream &operator<<(std::ostream &os, const Repository &repo) {
  os << "Repository(name=" << repo.name() << ", full_name=" << repo.full_name()
     << ")";
  return os;
}
}
