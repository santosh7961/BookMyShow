#pragma once
#include "Interfaces.h"

#ifdef _EXPORTING
#define CLASS_DECLSPEC    _declspec(dllexport)
#else
#define CLASS_DECLSPEC    _declspec(dllimport)
#endif
class CLASS_DECLSPEC Ticket : public ITicketDetails 
{
	int bookingId;
	string movieName;
	string theaterName;
	string showTime;
	int noOfSeatsBooked;
	int amountPaid;

public:
	Ticket(){}
	~Ticket(){}

	static vector<ITicketDetails*> GetTicketDetails(long personId);

	// Inherited via ITicketDetails
	virtual int GetBookingId() override;
	virtual void SetBookingId(int input) override;
	virtual string GetMovieName() override;
	virtual void SetMovieName(string input) override;
	virtual string GetTheaterName() override;
	virtual void SetTheaterName(string input) override;
	virtual string GetShowTime() override;
	virtual void SetShowTime(string input) override;
	virtual int GetNoOfSeatsBooked() override;
	virtual void SetNoOfSeatsBooked(int input) override;
	virtual int GetAmountPaid() override;
	virtual void SetAmountPaid(int input) override;
};

