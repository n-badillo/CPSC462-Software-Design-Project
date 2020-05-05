#pragma once

#include <memory>
#include <any>
#include <stdexcept>   // domain_error
#include <string>
#include <vector>

#include "TechnicalServices/Persistence/PersistenceHandler.hpp"

namespace Domain::Station
{
  // Import the User Credentials type from the lower layer
  using TechnicalServices::Persistence::UserCredentials;

  struct TrainTicket
  { // Function arguement type definitions
    std::vector<std::string>      ticketType;
    int     startStation;
    int     endStation;
    int     ticketQuantity;
  };

  struct PaymentMethod
  { // Function arguement type definitions
    std::string cardHolderName;
    std::string cardCompany;
    std::string cardNumber;
    std::string expDate;
  };

  // MaintainTrainHandler Package within the Domain Layer Abstract class
  class MaintainTrainHandler
  {
    public:
      // ================== Exceptions
      struct TransactionFailed : std::domain_error {using domain_error::domain_error;};  // If transaction failed, throw this error

      static std::unique_ptr<MaintainTrainHandler> createSession( const UserCredentials & credentials );

      // ================== Constructors
      MaintainTrainHandler()                                          = default;        // default ctor
      MaintainTrainHandler( const MaintainTrainHandler &  original )  = default;        // copy ctor
      MaintainTrainHandler(       MaintainTrainHandler && original )  = default;        // move ctor
      
      // ================== Operations
      virtual std::vector<std::string> findRoles()                                       = 0;   // Returns list of all legal roles
      virtual UserCredentials          findCredentialsByName( const std::string & name )   = 0;   // Returns credentials for specified user, throws NoSuchUser if user not found
          // UserCredentials is defined in the PersistenceHandler.hpp, and takes in the userName, passPhase and roles.
          // Corresponds with "createSession("username", "password", "role")" in the SSD 
      virtual std::vector<std::string> getCommands()                                       = 0; // Display commands based on roles
      virtual TrainTicket              enterPurchaseInformation( int startStation, int endStation, std::string ticketType, int ticketQuantity )  = 0; 
          // Corresponds with "getCommand("enterPurchaseInformation", 3, 9, "Express", 2)" in the SSD
      virtual PaymentMethod            enterPaymentMethod( std::string cardHolderName, std::string cardCompany, std::string cardNumber, std::string expDate )   = 0;  // Returns transaction completed successfully, throws TransactionFailed if failure occurred

      // =================== Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
      virtual ~MaintainTrainHandler() noexcept = 0;

    protected:
      // Copy assignment operators, protected to prevent mix derived-type assignments
      MaintainTrainHandler & operator=( const MaintainTrainHandler &  rhs ) = default;  // copy assignment
      MaintainTrainHandler & operator=(       MaintainTrainHandler && rhs ) = default;  // move assignment

  };    // class MaintainTrainHandler


  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline MaintainTrainHandler::~MaintainTrainHandler() noexcept
  {}


} // namespace Domain::Station
