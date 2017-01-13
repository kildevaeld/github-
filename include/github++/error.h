#pragma once

#include <exception>
#include <string>
namespace github {

class Exception : public std::exception {

public:
  Exception(const std::string &what) : m_what(what.c_str()) {}
  ~Exception() throw() {}
  const char *what() const throw() { return m_what; }

private:
  const char *m_what;
};
}