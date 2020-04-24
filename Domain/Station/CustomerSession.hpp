#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Session.hpp"


namespace Station
{
  class CustomerSession : public Station::SessionHandler
  {
    public:
      using SessionHandler::SessionHandler;  // inherit constructors

      // Operations
      std::vector<std::string> getCommands();  // retrieves the list of actions (commands)
      std::vector<std::string> viewTrainSchedule(int stationID);
      std::vector<std::string> buyTicket(int enterStart, int enterEnd, std::string ticketType, int ticketQuantity);
      std::vector<std::string> payTicket(std::string CreditCardName, std::string CreditCardCompany, std::string CreditCardNumber, std::string CreditCardExpDate);
      std::vector<std::string> getHelp();
      std::vector<std::string> endSession();

      // Destructor
      // Pure virtual destructor helps force the class to be abstract, but must still be implemented
     ~CustomerSession() noexcept;
  }; // class CustomerSession

  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline CustomerSession::~CustomerSession() noexcept
  {}

  inline std::vector<std::string> CustomerSession::getCommands()
  {
    return { "View Train Schedule", "Buy Ticket", "Help", "End Session" };
  }

  inline std::vector<std::string> CustomerSession::viewTrainSchedule(int stationID){
    // should return all available train / route schedules leaving that station
    return { "Enter your station ID: "};
  }

  inline std::vector<std::string> CustomerSession::buyTicket(int enterStart, int enterEnd, std::string ticketType, int ticketQuantity){
    // should return totalPrice of the transaction
    return {"Total Price: ", "Choose Payment Method"};
  }

  inline std::vector<std::string> CustomerSession::payTicket(std::string CreditCardName, std::string CreditCardCompany, std::string CreditCardNumber, std::string CreditCardExpDate){
    bool isValidTransaction;

    // if the transaction information is valid
    if(isValidTransaction){
      return {"Transaction Complete"};
    } else {
      return { "Transaction could not be complete, please check input details." };
    }
  }

  inline std::vector<std::string> CustomerSession::getHelp(){
    return {"For help, please call extension 911."};
  } 

  inline std::vector<std::string> CustomerSession::endSession(){
    return {"Session ended."};
  }

} // namespace Domain::Library
