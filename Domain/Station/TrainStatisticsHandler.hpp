#pragma once

namespace Domain::Station
{
  // RailSystem Package within the Domain Layer Abstract class
  class TrainStatisticsHandler
  {
    public:
      // Constructors
      TrainStatisticsHandler()                                          = default;        // default ctor
      TrainStatisticsHandler( const TrainStatisticsHandler &  original )  = default;        // copy ctor
      TrainStatisticsHandler(       TrainStatisticsHandler && original )  = default;        // move ctor

      // Operations

      // Destructor
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


} // namespace Domain::RailSystem
