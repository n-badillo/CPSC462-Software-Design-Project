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
      std::vector<std::string> getTrainStatistics();
      std::vector<std::string> filterStatistics();


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

    inline std::vector<std::string> SystemAdministratorSession::getTrainStatistics()
  {
    return { "Filter Statistics", "Train 1 from Los Angeles to Moorpark at 13:30", "Train 2 from Camarillo to Griffith Park at 15:00", "Train 3 from Union Station to Orange Metro Station at 07:00" };
  }

      inline std::vector<std::string> SystemAdministratorSession::filterStatistics()
  {
    return { "Train 5 from Fullerton to Los Angeles at 14:30"  }
  }


} // namespace Domain::Station
