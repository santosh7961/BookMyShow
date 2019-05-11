#pragma once
// MiddleAPI.cpp : Defines the exported functions for the DLL application.
//

#include "pch.h"
#include <string>
#include <vector>
using namespace std;

class IUser
{
public:
	virtual long GetMobileNumber() = 0;
	virtual void SetMobileNumber(long mobileNo) = 0;

	virtual string GetPassword() = 0;
	virtual void SetPassword(string password) = 0;

	virtual string GetName() = 0;
	virtual void SetName(string name) = 0;

	virtual string GetEmailId() = 0;
	virtual void SetEmailId(string emailId) = 0;

	virtual string GetGender() = 0;
	virtual void SetGender(string gender) = 0;

	virtual string GetCity() = 0;
	virtual void SetCity(string city) = 0;
};

class IMovieDetails
{
public:
	virtual int GetId() = 0;
	virtual void SetId(int input) = 0;

	virtual string GetMovieName() = 0;
	virtual void SetMovieName(string input) = 0;

	virtual string GetLanguage() = 0;
	virtual void SetLanguage(string input) = 0;

	virtual string GetMovieType() = 0;
	virtual void SetMovieType(string input) = 0;

	virtual string GetReleaseDate() = 0;
	virtual void SetReleaseDate(string input) = 0;

	virtual float GetRating() = 0;
	virtual void SetRating(float input) = 0;

	virtual string GetStarCasts() = 0;
	virtual void SetStarCasts(string input) = 0;

	virtual string GetShowTime() = 0;
	virtual void SetShowTime(string input) = 0;

	virtual string GetTheaterName() = 0;
	virtual void SetTheaterName(string input) = 0;

	virtual int GetAvailableSeats() = 0;
	virtual void SetAvailableSeats(int input) = 0;

	virtual int GetBookingPrice() = 0;
	virtual void SetBookingPrice(int input) = 0;
};

class ITicketDetails
{	
public:
	virtual int GetBookingId() = 0;
	virtual void SetBookingId(int input) = 0;

	virtual string GetMovieName() = 0;
	virtual void SetMovieName(string input) = 0;

	virtual string GetTheaterName() = 0;
	virtual void SetTheaterName(string input) = 0;

	virtual string GetShowTime() = 0;
	virtual void SetShowTime(string input) = 0;

	virtual int GetNoOfSeatsBooked() = 0;
	virtual void SetNoOfSeatsBooked(int input) = 0;

	virtual int GetAmountPaid() = 0;
	virtual void SetAmountPaid(int input) = 0;
};
