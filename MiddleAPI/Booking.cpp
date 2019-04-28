#include "stdafx.h"
#include "Booking.h"
#include "../Backend/PerformDatabaseActions.h"

bool Booking::BookTicket(long userId, int showId, int noOfSeatsBooked, int amountPaid)
{
	return PerformDatabaseActions::BookTicket(userId,showId, noOfSeatsBooked, amountPaid);
}
