#include <string>
#include <new>
#include <iostream>
#include <stdexcept>






/*******************************************************************************
**          Tickets
*******************************************************************************/
// Tickets Abstract Product Interface
class Ticket
{
  public:
      Ticket(double cost, int ticketAmount, int routeID, int duration)
    : _cost(cost), _ticketAmount(ticketAmount), _routeID(routeID), _duration(duration)
    {}

    virtual void open() = 0;

    virtual ~Ticket()     = 0; // force the class to be abstract

  protected:
      double _cost;
      double _ticketAmount;
      int _routeID;
      int _duration;
};

inline Ticket::~Ticket()
{}


// Standard Ticket Standard Product
class StandardTicket : public Ticket
{
public:
    StandardTicket(double cost = 7.5, int ticketAmount = 1, int routeID = 1, int duration = 1)
        : Door(height, width, length)
    {
        std::cout << "Created ticket number " << (_ticketID = ++_counter) << '\n';
    }

    void open() override
    {}

    ~StandardTicket() override
    {
        std::cout << "Used (destroyed) ticket number " << _ticketID << '\n';
    }

private:
    static long unsigned _counter; // class attribute to count the number of wooden door made
    long unsigned        _ticketID = 0;
};
long unsigned StandardTicket::_counter = 0; // Allocate storage for class attribute



// Express Ticket Express Product
class ExpressTicket : public Ticket
{
  public:
      ExpressTicket(double cost = 7.5, int ticketAmount = 1, int routeID = 1, int duration = 1)
    : Ticket(cost, ticketAmount, routeID, duration)
  {
    std::cout << "Created ticket number " << (_ticketID = ++_counter) << '\n';
  }

  void open() override
  {}

  ~ExpressTicket() override
  {
    std::cout << "Used (destroyed) ticket number " << _ticketID << '\n';
  }

  private:
  static long unsigned _counter; // class attribute to count the number of wooden door made
  long unsigned        _ticketID = 0;
};
long unsigned ExpressTicket::_counter = 0; // Allocate storage for class attribute



/*******************************************************************************
**          TICKET  FACTORIES
*******************************************************************************/
// Ticket Abstract Factory Interface
struct TicketFactory
{
  // Must be static
  static TicketFactory* createFactory();

  // All Ticket Factories have these functions
  virtual Ticket * createTicket(double cost, int ticketAmount, int routeID, int duration) = 0;
};






// Carpenter Concrete Factory
struct StandardFactory : TicketFactory
{
  // Note:  Responsibility to delete this object passes to the caller
  //        Smart pointers would be a great idea here
  // Note the covariant return type!
  StandardTicket* createTicket(double cost, int ticketAmount, int routeID, int duration) override
  { return new StandardTicket(cost, ticketAmount, routeID, duration); }
};


// Express Concrete Factory
struct ExpressFactory : TicketFactory
{
  // Note:  Responsibility to delete this object passes to the caller
  //        Smart pointers would be a great idea here
  // Note the covariant return type!
    ExpressTicket* createTicket(double cost, int ticketAmount, int routeID, int duration) override
  { return new ExpressTicket(cost, ticketAmount, routeID, duration); }
};

// This normally goes in the .cpp file ...
TicketFactory * TicketFactory::createFactory()
{ 
  // Read from configuration data what type of doors we want to create.  Let's
  // pretend a call to get the desired type of door from the configuration
  // data returned "Plastic".  In particular, note that no data is passed into
  // the creatFactory function;
  std::string factoryPreference = "Standard";

  if      ( factoryPreference == "Standard" ) return new StandardFactory();
  else if ( factoryPreference == "Express" )  return new ExpressFactory();
  else
  {
    // error - Preference not support.
    throw std::domain_error( "Unsupported factory preference encountered: " + factoryPreference );
  }
} // createFactory()






/*******************************************************************************
**          Clients
*******************************************************************************/
int main()
{
  // I'd like a new door, please.  Let's ask for one and let the system's configuration data 
  // pick the material.
  // Note the assignment of a pointer-to-concrete class to a pointer-to-interface class

    TicketFactory* theFactory = TicketFactory::createFactory();
  
  // Surprise!  I got a new door but never said what kind I wanted
  Ticket        * myNewTicket = theFactory->createTicket( 5.00, 1, 1, 1);

  myNewTicket->open();

  // Bookkeeping to be done - could avoid if we used smart pointers!
  delete myNewTicket;
  delete theFactory;
}