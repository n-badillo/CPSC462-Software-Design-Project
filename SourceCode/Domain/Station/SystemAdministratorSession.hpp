#pragma once

#include <memory>
#include <string>
#include <vector>


#include "Domain/Station/Session.hpp"


namespace Domain::Station
{
  class SystemAdministratorSession : public Domain::Station::SessionHandler
  {
    public:
      using SessionHandler::SessionHandler;  // inherit constructors

      // Operations
      std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands)


      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
     ~SystemAdministratorSession() noexcept override;
  }; // class SystemAdministratorSession





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline SystemAdministratorSession::~SystemAdministratorSession() noexcept
  {}


  inline std::vector<std::string> SystemAdministratorSession::getCommands()
  {
    return { "Get Train Statistics", "View Train Schedules", "Get Current Employees" };
  }

} // namespace Domain::Station
