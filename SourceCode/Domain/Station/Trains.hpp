#pragma once

#include "Domain/Station/MaintainTrainHandler.hpp"

namespace Domain::Station
{
  class Trains : public Domain::Station::MaintainTrainHandler
  {
    public:
      // Constructors
      using MaintainTrainHandler::MaintainTrainHandler;  // inherit constructors

      // Operations

     ~Trains() noexcept override;
  }; // class Trains


  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline Trains::~Trains() noexcept
  {}


}  // namespace Domain::Station
