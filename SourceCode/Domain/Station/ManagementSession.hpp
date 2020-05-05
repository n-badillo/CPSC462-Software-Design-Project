#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Domain/Station/Session.hpp"


namespace Domain::Station
{
  class ManagementSession : public Domain::Station::SessionHandler
  {
    public:
      using SessionHandler::SessionHandler;  // inherit constructors

      // Operations
      std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands)


      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
     ~ManagementSession() noexcept override;
  }; // class ManagementSession





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline ManagementSession::~ManagementSession() noexcept
  {}


  inline std::vector<std::string> ManagementSession::getCommands()
  {
    return { "Bug People", "Help" };
  }

} // namespace Domain::Station
