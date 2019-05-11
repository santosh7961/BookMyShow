#pragma once

#ifdef _EXPORTING
#define CLASS_DECLSPEC    _declspec(dllexport)
#else
#define CLASS_DECLSPEC    _declspec(dllimport)
#endif

class CLASS_DECLSPEC Booking
{
public:
	Booking(){}
	~Booking(){}

	static bool BookTicket(long userId,int showId,int noOfSeatsBooked, int amountPaid);
};

