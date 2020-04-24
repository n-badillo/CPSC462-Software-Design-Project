#include <memory>              // unique_ptr, make_unique<>()
#include <stdexcept>           // logic_error
#include <string>

#include "AdministratorSession.hpp"
#include "CustomerSession.hpp"
#include "Session.hpp"




namespace Station
{
  // returns a specialized object specific to the specified role
  std::unique_ptr<SessionHandler>  SessionHandler::createSession( const std::string & role )
  {
	if(role == "Customer"){  
		return std::make_unique<Station::CustomerSession>();
	}
    	else if( role == "Administrator" ){   
		return std::make_unique<Station::AdministratorSession>();
	}
    	else{
      		throw std::logic_error( "Invalid role requested in function " + std::string(__func__) ); 
    	}
  }

}
