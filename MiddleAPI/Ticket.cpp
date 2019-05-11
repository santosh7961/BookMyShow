#include "stdafx.h"
#include "Ticket.h"
#include "../Backend/PerformDatabaseActions.h"

vector<ITicketDetails*> TicketMiddle::GetTicketDetails(long personId)
{
	vector<ITicketDetails*> movDetails = PerformDatabaseActions::GetTicketDetails(personId);
	return movDetails;
}

TicketMiddle::TicketMiddle()
{
}


TicketMiddle::~TicketMiddle()
{
}
