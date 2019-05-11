#include "pch.h"
#include "Ticket.h"


int Ticket::GetBookingId()
{
	return bookingId;
}

void Ticket::SetBookingId(int input)
{
	bookingId = input;
}

string Ticket::GetMovieName()
{
	return movieName;
}

void Ticket::SetMovieName(string input)
{
	movieName = input;
}

string Ticket::GetTheaterName()
{
	return theaterName;
}

void Ticket::SetTheaterName(string input)
{
	theaterName = input;
}

string Ticket::GetShowTime()
{
	return showTime;
}

void Ticket::SetShowTime(string input)
{
	showTime = input;
}

int Ticket::GetNoOfSeatsBooked()
{
	return noOfSeatsBooked;
}

void Ticket::SetNoOfSeatsBooked(int input)
{
	noOfSeatsBooked = input;
}


int Ticket::GetAmountPaid()
{
	return amountPaid;
}

void Ticket::SetAmountPaid(int input)
{
	amountPaid = input;
}
