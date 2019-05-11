#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

#include "../Common/Interfaces.h"
#include "../Common/User.h"
#include "../Common/Movie.h"
#include "../Common/Ticket.h"
#include "C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h"

using namespace std;

#ifdef _EXPORTING
#define CLASS_DECLSPEC    _declspec(dllexport)
#else
#define CLASS_DECLSPEC    _declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

class CLASS_DECLSPEC PerformDatabaseActions
{
private:
	static bool finish_with_error_bool(MYSQL *con);
	static IUser* finish_with_error_IUser(MYSQL *con);
	static vector<IMovieDetails*> finish_with_error_MovieDetails(MYSQL *con);
	static vector<ITicketDetails*> finish_with_error_TicketDetails(MYSQL *con);

public:	
	static IUser* ValidateUserDetails(long mobileNo, string password);
	static bool RegisterNewUser(long mobileNo,string password,string name, string emailId,string gender,string city);
	static vector<IMovieDetails*> GetMovieDetails(string city);
	static vector<IMovieDetails*> GetTheaterDetails(string city);
	static bool BookTicket(long userId, int showId, int noOfSeatsBooked, int amountPaid);
	static vector<ITicketDetails*> GetTicketDetails(long userId);
};

#ifdef __cplusplus
}
#endif