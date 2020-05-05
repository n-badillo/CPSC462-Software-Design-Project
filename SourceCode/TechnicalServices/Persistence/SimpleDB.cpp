#include <string>
#include <vector>
#include <memory>     // make_unique()

#include "TechnicalServices/Persistence/SimpleDB.hpp"
#include "TechnicalServices/Logging/SimpleLogger.hpp"
#include "TechnicalServices/Persistence/PersistenceHandler.hpp"


namespace TechnicalServices::Persistence
{
  SimpleDB::SimpleDB()
  : _loggerPtr( std::make_unique<TechnicalServices::Logging::SimpleLogger>() )     // will replace these factory calls with abstract factory calls next increment
  {
    _logger << "Simple DB being used and has been successfully initialized";
  }



  SimpleDB::~SimpleDB() noexcept
  {
    _logger << "Simple DB shutdown successfully";
  }



  std::vector<std::string> SimpleDB::findRoles()
  {
    return { "Customer", "Employee", "System Administrator", "Maintainance", "Management" };
  }

  UserCredentials SimpleDB::findCredentialsByName( const std::string & name )
  {
    static std::vector<UserCredentials> storedUsers =
    {
    // Username    Pass Phrase         Authorized roles
      {"Sam",     "myPassword!",  {"System Administrator",     "Management"}},
      {"LoyalCustomer56", "iLikeHorses!",   {"Custoemr"                  }},
      {"Amanda",  "",                 {"System Administrator"             }}
    };

    for( const auto & user : storedUsers ) if( user.userName == name ) return { user.userName, user.passPhrase, user.roles };

    // Name not found, throw something
    std::string message = __func__;
    message += " attempt to find user \"" + name + "\" failed";

    _logger << message;

    throw PersistenceHandler::NoSuchUser( message );
  }

} // namespace TechnicalServices::Persistence
