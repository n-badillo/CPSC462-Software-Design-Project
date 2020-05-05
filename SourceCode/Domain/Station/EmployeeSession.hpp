#ifndef Domain_Employee_EmployeeSession_hpp
#define Domain_Employee_EmployeeSession_hpp

#include <memory>
#include <string>
#include <vector>


#include "Domain/Station/Session.hpp"


namespace Domain::Station
{
  class EmployeeSession : public Domain::Station::SessionHandler
  {
    public:
      using SessionHandler::SessionHandler;  // inherit constructors

      // Operations
      std::vector<std::string> getCommands() override;  // retrieves the list of actions (commands)


      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
     ~EmployeeSession() noexcept override;
  }; // class EmployeeSession





  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline EmployeeSession::~EmployeeSession() noexcept
  {}


  inline std::vector<std::string> EmployeeSession::getCommands()
  {
    return { "Open Account", "Checkout Purchase", "Collect Fines", "Help" };
  }

} // namespace Domain::Station

#endif // Domain_Employee_EmployeeSession_hpp
