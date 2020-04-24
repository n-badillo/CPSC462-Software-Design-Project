#pragma once

#include <memory>  // unique_ptr
#include <string>
#include <vector>


namespace Domain::Station
{
  class SessionHandler
  {
    public:
      // Constructors and assignment operations
      SessionHandler()                                           = default;  // default ctor
      SessionHandler( const SessionHandler &  original )         = default;  // copy ctor
      SessionHandler(       SessionHandler && original )         = default;  // move ctor

      // Operations
      virtual std::vector<std::string> getCommands() = 0;

      static std::unique_ptr<SessionHandler> createSession( const std::string & role );

      virtual ~SessionHandler() noexcept = 0;

    protected:
      // Copy assignment operators, protected to prevent mix derived-type assignments
      SessionHandler & operator=( const SessionHandler &  rhs ) = default;  // copy assignment
      SessionHandler & operator=(       SessionHandler && rhs ) = default;  // move assignment

  }; 

  inline SessionHandler::~SessionHandler() noexcept
  {}

}
