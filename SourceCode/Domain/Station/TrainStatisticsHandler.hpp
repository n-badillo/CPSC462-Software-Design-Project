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

  struct SingleTrainStatistics
  { // Function arguement type definitions
    int trainID;
  };

  // TrainStatisticsHandler Package within the Domain Layer Abstract class
  class TrainStatisticsHandler
  {
    public:
      // ================== Exceptions
      struct NoSuchTrain : std::domain_error {using domain_error::domain_error;};  // If train does not exist, throw this error

      static std::unique_ptr<TrainStatisticsHandler> createSession( const UserCredentials & credentials );

      // ================== Constructors
      TrainStatisticsHandler()                                          = default;        // default ctor
      TrainStatisticsHandler( const TrainStatisticsHandler &  original )  = default;        // copy ctor
      TrainStatisticsHandler(       TrainStatisticsHandler && original )  = default;        // move ctor
      
      // ================== Operations
      virtual std::vector<std::string> findRoles()                                       = 0;   // Returns list of all legal roles
      virtual UserCredentials          findCredentialsByName( const std::string & name )   = 0;   // Returns credentials for specified user, throws NoSuchUser if user not found
      virtual std::vector<std::string> getCommands()                                       = 0; // Display commands based on roles
      virtual void                     getAllTrainStatistics()  = 0;  // Returns entire data set in database for train stats
      virtual SingleTrainStatistics    getTrainStatistics( int trainID )   = 0;  // Returns transaction completed successfully, throws NoSuchTrain if failure occurred

      // =================== Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
      virtual ~TrainStatisticsHandler() noexcept = 0;

    protected:
      // Copy assignment operators, protected to prevent mix derived-type assignments
      TrainStatisticsHandler & operator=( const TrainStatisticsHandler &  rhs ) = default;  // copy assignment
      TrainStatisticsHandler & operator=(       TrainStatisticsHandler && rhs ) = default;  // move assignment

  };    // class TrainStatisticsHandler


  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline TrainStatisticsHandler::~TrainStatisticsHandler() noexcept
  {}


} // namespace Domain::Station
