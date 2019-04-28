#include "stdafx.h"
#include "PerformDatabaseActions.h"


bool PerformDatabaseActions::finish_with_error_bool(MYSQL *con)
{
	cout << mysql_error(con);
	mysql_close(con);
	return false;
}

IUser* PerformDatabaseActions::finish_with_error_IUser(MYSQL *con)
{
	cout << mysql_error(con);
	mysql_close(con);
	return NULL;
}

vector<IMovieDetails*> PerformDatabaseActions::finish_with_error_MovieDetails(MYSQL *con)
{
	vector<IMovieDetails*> vecMovies;
	cout << mysql_error(con);
	mysql_close(con);
	return vecMovies;
}

vector<ITicketDetails*> PerformDatabaseActions::finish_with_error_TicketDetails(MYSQL *con)
{
	vector<ITicketDetails*> vecTickets;
	cout << mysql_error(con);
	mysql_close(con);
	return vecTickets;
}
 
IUser* PerformDatabaseActions::ValidateUserDetails(long mobileNo, string password)
{
	MYSQL *con = mysql_init(NULL);

	if (mysql_real_connect(con, "localhost", "root", "MySQL",
		"BookMyShow", 0, NULL, 0) == NULL)
	{
		finish_with_error_IUser(con);
	}
	string selectQuery = "SELECT * FROM User where MobileNo=";
	selectQuery += to_string(mobileNo);
	selectQuery += " and UserPassword='";
	selectQuery += password;
	selectQuery += "'";

	if (mysql_query(con, selectQuery.c_str()))
	{
		finish_with_error_IUser(con);
	}

	MYSQL_RES *result = mysql_store_result(con);

	if (result == NULL)
	{
		finish_with_error_IUser(con);
	}
	//Not valid user id or password
	if (result->row_count == 0)
		return NULL;

	int num_fields = mysql_num_fields(result);

	MYSQL_ROW row;
	IUser *pUser = new User();

	//It must have only one row.
	while ((row = mysql_fetch_row(result)))
	{
		pUser->SetMobileNumber(atol(row[0]));
		pUser->SetPassword(row[1]);
		pUser->SetName(row[2]);
		pUser->SetEmailId(row[3]);
		pUser->SetGender(row[4]);
		pUser->SetCity(row[5]);
	}

	mysql_free_result(result);
	mysql_close(con);

	return pUser;
}

bool PerformDatabaseActions::RegisterNewUser(long mobileNo, string password,string name, string emailId, string gender, string city)
{	
	MYSQL *con = mysql_init(NULL);

	if (mysql_real_connect(con, "localhost", "root", "MySQL",
		"BookMyShow", 0, NULL, 0) == NULL)
	{
		finish_with_error_bool(con);
	}
	
	//Add User
	//insert into User values(123456789,'12345','Santosh', 'santosh796@gmail.com','Male','Hyderabad')

	string selectQuery = "insert into User values(";
	selectQuery += to_string(mobileNo);
	selectQuery += ",'";
	selectQuery += password;
	selectQuery += "','";
	selectQuery += name;
	selectQuery += "','";
	selectQuery += emailId;
	selectQuery += "','";
	selectQuery += gender;
	selectQuery += "','";
	selectQuery += city;
	selectQuery += "')";

	//AcquireSRWLockExclusive(&lockBooking);
	if (mysql_query(con, selectQuery.c_str()))
	{
		finish_with_error_bool(con);
	}
	//ReleaseSRWLockExclusive(&lockBooking);//Release the lock

	mysql_close(con);
	return true;
}

vector<IMovieDetails*> PerformDatabaseActions::GetMovieDetails(string city)
{
	MYSQL *con = mysql_init(NULL);

	if (mysql_real_connect(con, "localhost", "root", "MySQL",
		"BookMyShow", 0, NULL, 0) == NULL)
	{
		finish_with_error_MovieDetails(con);
	}

	/*To get the movie details based on city
	select shows.Id,movie.MovieName,movie.Languages,movie.MovieType,movie.ReleaseDate,
	movie.Rating, movie.StarCasts,Showtime.starttime,theater.TheaterName,
	theater.AvailableSeats from Movie
	inner join Shows  on movie.Id = shows.MovieId
	inner join Showtime on showtime.Id = shows.showstime
	inner join Theater on theater.Id = shows.TheaterId
	where theater.City='Delhi' order by shows.id, movie.MovieName;*/

	string selectQuery = "select shows.Id,movie.MovieName,movie.Languages,movie.MovieType,movie.ReleaseDate,\
		movie.Rating, movie.StarCasts, Showtime.starttime, theater.TheaterName,\
		theater.AvailableSeats, theater.Price from Movie\
		inner join Shows  on movie.Id = shows.MovieId\
		inner join Showtime on showtime.Id = shows.showstime\
		inner join Theater on theater.Id = shows.TheaterId\
	    where theater.City = '";
	selectQuery += city;
	selectQuery += "' order by shows.id, movie.MovieName";

	if (mysql_query(con, selectQuery.c_str()))
	{
		finish_with_error_MovieDetails(con);
	}

	MYSQL_RES *result = mysql_store_result(con);

	if (result == NULL)
	{
		finish_with_error_MovieDetails(con);
	}
	vector<IMovieDetails*> vecMovies;
	//Didn't find any movie in the given city
	if (result->row_count == 0)
		return vecMovies;

	int num_fields = mysql_num_fields(result);

	MYSQL_ROW row;

	while ((row = mysql_fetch_row(result)))
	{
		IMovieDetails *pMovieDetails = new MovieDetails();

		pMovieDetails->SetId(atol(row[0]));
		pMovieDetails->SetMovieName(row[1]);
		pMovieDetails->SetLanguage(row[2]);
		pMovieDetails->SetMovieType(row[3]);
		pMovieDetails->SetReleaseDate(row[4]);
		pMovieDetails->SetRating(atof(row[5]));
		pMovieDetails->SetStarCasts(row[6]);
		pMovieDetails->SetShowTime(row[7]);
		pMovieDetails->SetTheaterName(row[8]);
		pMovieDetails->SetAvailableSeats(atoi(row[9]));
		pMovieDetails->SetBookingPrice(atoi(row[10]));
		vecMovies.push_back(pMovieDetails);
	}

	mysql_free_result(result);
	mysql_close(con);

	return vecMovies;
}

vector<IMovieDetails*> PerformDatabaseActions::GetTheaterDetails(string city)
{	
	MYSQL *con = mysql_init(NULL);

	if (mysql_real_connect(con, "localhost", "root", "MySQL",
		"BookMyShow", 0, NULL, 0) == NULL)
	{
		finish_with_error_MovieDetails(con);
	}

	/*select shows.Id, theater.TheaterName, movie.MovieName, movie.Languages, movie.MovieType,
	movie.ReleaseDate, movie.Rating, movie.StarCasts, Showtime.starttime, theater.AvailableSeats
	from Movie
	inner join Shows  on movie.Id = shows.MovieId
	inner join Showtime on showtime.Id = shows.showstime
	inner join Theater on theater.Id = shows.TheaterId
	where theater.City='Delhi' order by shows.id , theater.TheaterName   */

	string selectQuery = "select shows.Id, theater.TheaterName, movie.MovieName, movie.Languages,\
		movie.MovieType, movie.ReleaseDate, movie.Rating, movie.StarCasts, Showtime.starttime,\
		theater.AvailableSeats, theater.Price from Movie\
		inner join Shows  on movie.Id = shows.MovieId\
		inner join Showtime on showtime.Id = shows.showstime\
		inner join Theater on theater.Id = shows.TheaterId\
	where theater.City = '";
	selectQuery += city;
	selectQuery += "' order by shows.id , theater.TheaterName";

	if (mysql_query(con, selectQuery.c_str()))
	{
		finish_with_error_MovieDetails(con);
	}

	MYSQL_RES *result = mysql_store_result(con);

	if (result == NULL)
	{
		finish_with_error_MovieDetails(con);
	}

	vector<IMovieDetails*> vecMovies;
	//Didn't find any movie in the given city
	if (result->row_count == 0)
		return vecMovies;

	int num_fields = mysql_num_fields(result);

	MYSQL_ROW row;
	while ((row = mysql_fetch_row(result)))
	{
		IMovieDetails *pMovieDetails = new MovieDetails();

		pMovieDetails->SetId(atol(row[0]));
		pMovieDetails->SetTheaterName(row[1]);
		pMovieDetails->SetMovieName(row[2]);
		pMovieDetails->SetLanguage(row[3]);
		pMovieDetails->SetMovieType(row[4]);
		pMovieDetails->SetReleaseDate(row[5]);
		pMovieDetails->SetRating(atof(row[6]));
		pMovieDetails->SetStarCasts(row[7]);
		pMovieDetails->SetShowTime(row[8]);
		pMovieDetails->SetAvailableSeats(atoi(row[9]));
		pMovieDetails->SetBookingPrice(atoi(row[10]));
		vecMovies.push_back(pMovieDetails);
	}

	mysql_free_result(result);
	mysql_close(con);

	return vecMovies;
}

//SRWLOCK lockBooking;
bool PerformDatabaseActions::BookTicket(long userId, int showId, int noOfSeatsBooked, int amountPaid)
{	
	/*
	3 steps
	1. Check the available seats. If available seats are less than requested. Return
	2. Book the ticket
	3. Reduce the no. of available seats in the theater where ticket booked
	*/
	//Perform thread safe in concurrency
	//AcquireSRWLockShared(&lockBooking);

	vector<IMovieDetails*> vecMovies;
	MYSQL *con = mysql_init(NULL);

	if (mysql_real_connect(con, "localhost", "root", "MySQL",
		"BookMyShow", 0, NULL, 0) == NULL)
	{
		finish_with_error_bool(con);
	}

	//1. Check the available seats
	/*select theater.AvailableSeats  from theater
		inner join Shows on shows.theaterId = theater.Id
	where shows.id = 1*/
	string availableSeatQuery = "select theater.AvailableSeats,theater.TheaterName  from theater\
		inner join Shows on shows.theaterId = theater.Id\
	    where shows.id =";
	availableSeatQuery += to_string(showId);

	if (mysql_query(con, availableSeatQuery.c_str()))
	{
		finish_with_error_bool(con);
	}

	MYSQL_RES *result = mysql_store_result(con);

	if (result == NULL)
	{
		finish_with_error_bool(con);
	}

	//Didn't find any movie in the given city
	if (result->row_count == 0)
		return false;	

	MYSQL_ROW row;
	int numberOfAvailableSeats = 0;
	string theaterName;
	//It must have only one row and 2 columns.
	while ((row = mysql_fetch_row(result)))
	{
		numberOfAvailableSeats = atoi(row[0]);
		theaterName = row[1];
	}

	if (numberOfAvailableSeats < noOfSeatsBooked)
	{
		cout << "Sorry!!" << theaterName << " theater is full. Try in some other theater.\n";
		return false;
	}
	int remainingSeats = numberOfAvailableSeats - noOfSeatsBooked;

	//2. Perform booking
	//Insert data into Booking table and update available seats in Theater table
	//insert into Booking (UserId,ShowId,NoOfSeatsBooked,AmountPaid)values(123456789,1,2,500);
	
	string selectQuery = "insert into Booking (UserId,ShowId,NoOfSeatsBooked,AmountPaid)values(";
	selectQuery += to_string(userId);
	selectQuery += ",";
	selectQuery += to_string(showId);
	selectQuery += ",";
	selectQuery += to_string(noOfSeatsBooked);
	selectQuery += ",";
	selectQuery += to_string(amountPaid);
	selectQuery += ")";

	//ReleaseSRWLockShared(&lockBooking);

	//AcquireSRWLockExclusive(&lockBooking);
	if (mysql_query(con, selectQuery.c_str()))
	{
		finish_with_error_bool(con);
	}

	//3. Reduce the number of available seats in the theater.
	//update theater inner join shows on shows.theaterId = theater.Id
	//set AvailableSeats = 10 - 3 where shows.Id = 1;
	selectQuery = "update theater inner join shows on shows.theaterId = theater.Id\
			set AvailableSeats = ";
	selectQuery += to_string(remainingSeats);
	selectQuery += " where shows.Id = ";
	selectQuery += to_string(showId);
	if (mysql_query(con, selectQuery.c_str()))
	{
		finish_with_error_bool(con);
	}
	mysql_free_result(result);
	mysql_close(con);

	//ReleaseSRWLockExclusive(&lockBooking);//Release the lock

	return true;
}

vector<ITicketDetails*> PerformDatabaseActions::GetTicketDetails(long userId)
{	
	MYSQL *con = mysql_init(NULL);

	if (mysql_real_connect(con, "localhost", "root", "MySQL",
		"BookMyShow", 0, NULL, 0) == NULL)
	{
		finish_with_error_TicketDetails(con);
	}

	/*select booking.BookingId, movie.MovieName,theater.TheaterName,ShowTime.StartTime,
	booking.NoOfSeatsBooked,booking.AmountPaid from Booking
	join shows on shows.id= booking.ShowId
	join theater on theater.Id = shows.theaterId
	join movie on movie.Id=shows.MovieId
	join ShowTime on Showtime.Id=shows.Showstime
	join user on booking.userId = user.MobileNo
	where user.MobileNo =123456789 order by booking.BookingId*/

	string selectQuery = "select booking.BookingId, movie.MovieName, theater.TheaterName,\
		ShowTime.StartTime, booking.NoOfSeatsBooked, booking.AmountPaid from Booking\
		join shows on shows.id = booking.ShowId\
		join theater on theater.Id = shows.theaterId\
		join movie on movie.Id = shows.MovieId\
		join ShowTime on Showtime.Id = shows.Showstime\
		join user on booking.userId = user.MobileNo\
	    where user.MobileNo =";
	selectQuery += to_string(userId);
	selectQuery += " order by booking.BookingId";

	if (mysql_query(con, selectQuery.c_str()))
	{
		finish_with_error_TicketDetails(con);
	}

	MYSQL_RES *result = mysql_store_result(con);

	if (result == NULL)
	{
		finish_with_error_TicketDetails(con);
	}
	vector<ITicketDetails*> vecTickets;
	//Didn't find any movie in the given city
	if (result->row_count == 0)
		return vecTickets;

	int num_fields = mysql_num_fields(result);

	MYSQL_ROW row;
	while ((row = mysql_fetch_row(result)))
	{
		ITicketDetails *pMovieDetails = new Ticket();
		pMovieDetails->SetBookingId(atol(row[0]));
		pMovieDetails->SetMovieName(row[1]);
		pMovieDetails->SetTheaterName(row[2]);
		pMovieDetails->SetShowTime(row[3]);
		pMovieDetails->SetNoOfSeatsBooked(atoi(row[4]));
		pMovieDetails->SetAmountPaid(atoi(row[5]));

		vecTickets.push_back(pMovieDetails);
	}

	mysql_free_result(result);
	mysql_close(con);

	return vecTickets;
}
