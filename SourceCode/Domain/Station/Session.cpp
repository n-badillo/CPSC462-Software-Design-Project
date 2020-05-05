#include <memory>              // unique_ptr, make_unique<>()
#include <stdexcept>           // logic_error
#include <string>

#include "Domain/Station/SystemAdministratorSession.hpp"
#include "Domain/Station/CustomerSession.hpp"
#include "Domain/Station/EmployeeSession.hpp"
// #include "Domain/Station/ManagementSession.hpp"  // Not implemented yet

#include "Domain/Station/Session.hpp"




namespace Domain::Station
{
  // returns a specialized object specific to the specified role
  std::unique_ptr<SessionHandler>  SessionHandler::createSession( const std::string & role )
  {
    // Just as a smart defensive strategy, one should verify this role is one of the roles in the DB's legal value list.  I'll come
    // back to that

    // This is a good example of a Factory - the function takes the "order" (role) and builds the "product" (session) to fulfill the
    // order. This, however, still leaks knowledge of the kinds of sessions to the client, after all the client needs to specify
    // with role.

    // ToDo: Make this an Abstract Factory by:
    //  1) removing the parameter from the function's signature :  std::unique_ptr<SessionHandler>  SessionHandler::createSession();
    //  2) read the role from a proprieties files or (preferred) look up the role in the persistent data


    if     ( role == "System Administrator"      )    return std::make_unique<Domain::Station::SystemAdministratorSession>();
    else if( role == "Customer"     )    return std::make_unique<Domain::Station::CustomerSession>();
    else if( role == "Employee" )    return std::make_unique<Domain::Station::EmployeeSession>();
    //else if( role == "Management"    )    return std::make_unique<Domain::Station::ManagementSession>(); // Not implemented yet
    else
    {
      throw std::logic_error( "Invalid role requested in function " + std::string(__func__) ); // Oops, should never get here but ...  Throw something
    }
  }

} // namespace Domain::Station
