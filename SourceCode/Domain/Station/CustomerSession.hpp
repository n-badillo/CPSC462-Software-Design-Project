#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Domain/Station/Session.hpp"


namespace Domain::Station
{
  class CustomerSession : public Domain::Station::SessionHandler
  {
    public:
      using SessionHandler::SessionHandler;  // inherit constructors

      // Operations
      std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands)


      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
     ~CustomerSession() noexcept override;
  }; // class CustomerSession





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline CustomerSession::~CustomerSession() noexcept
  {}


  inline std::vector<std::string> CustomerSession::getCommands()
  {
    return { "View Train Schedule", "Make Purchase", "Redeem Pass", "Help" };
  }

} // namespace Domain::Station
