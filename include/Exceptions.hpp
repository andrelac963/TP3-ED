//---------------------------------------------------------------------
// Arquivo      : Exceptions.hpp
// Conteudo     : programa
// Autor        : André Luiz Alves Costa (andrelac963@gmail.com)
// Historico    : 2023-00-00 - arquivo criado
//---------------------------------------------------------------------

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

using namespace std;

class InvalidArguments : public exception
{
private:
  const char *message;

public:
  InvalidArguments(int argc)
  {
    message = "Invalid number of arguments";
  }

  InvalidArguments(const char *option)
  {
    message = "Invalid option";
  }

  const char *what() const throw()
  {
    return message;
  }
};

class FailedToOpenFile : public exception
{
private:
  const char *message;

public:
  FailedToOpenFile(const char *file)
  {
    message = "Failed to open file";
  }

  const char *what() const throw()
  {
    return message;
  }
};

#endif