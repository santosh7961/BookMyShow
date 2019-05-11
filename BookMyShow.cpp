// BookMyShow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include<Windows.h>
#include "Common/Interfaces.h"
#include "MiddleAPI/User.h"
#include "MiddleAPI/Movie.h"
#include "MiddleAPI/Theater.h"
#include "MiddleAPI/Booking.h"
#include "MiddleAPI/Ticket.h"

using namespace std;


/*validate the cin  long input value.*/
void MyCin(long &input)
{
	cin >> input;
	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(LLONG_MAX, '\n');
			cout << "You have entered wrong input. Try again..." << endl;
			cin >> input;
		}
		//This is for decimal input for long. It ignores next cin without this line
		cin.ignore(LLONG_MAX, '\n');
		if (!cin.fail())
			break;
	}
}

/*validate the cin  long input value.*/
void MyCin(int &input)
{
	cin >> input;
	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(LLONG_MAX, '\n');
			cout << "You have entered wrong input. Try again..." << endl;
			cin >> input;
		}
		//This is for decimal input for long. It ignores next cin without this line
		cin.ignore(LLONG_MAX, '\n');
		if (!cin.fail())
			break;
	}
}

/*Method to show the details about all the booking based on input userid.*/
void ViewBookings(long userId)
{
	cout << "\n\n************************************************************************\n\n";
	cout << "Here is your all the tickets booking details. \n" << endl;

	vector<ITicketDetails*> ticketDetails = TicketMiddle::GetTicketDetails(userId);
	if (ticketDetails.size() == 0)
		cout << "You haven't booked any ticket yet. Please book and enjoy the movie!!!\n";

	cout << left << setw(10) << "BookingId" << setw(25) << "MovieName" << setw(25) << "TheaterName";
	cout << setw(10) << "ShowTime" << setw(20) << "NoOfSeatsBooked" << setw(10) << "AmountPaid\n";
	cout << left << setw(10) << "*********" << setw(25) << "*********" << setw(25) << "***********";
	cout << setw(10) << "*******" << setw(20) << "**************" << setw(10) << "**********\n";

	for (auto md : ticketDetails)
	{
		cout << left << setw(10) << md->GetBookingId();
		cout << setw(25) << md->GetMovieName();
		cout << setw(25) << md->GetTheaterName();
		cout << setw(10) << md->GetShowTime();
		cout << setw(20) << md->GetNoOfSeatsBooked();
		cout << setw(10) << md->GetAmountPaid() << endl;
	}
	cout << endl;
}

/*Method for booking the movie ticket.*/
void BookTicket(long userId, int showId, string movieName, int pricePerSeat)
{
	cout << "\n\n************************************************************************\n";
	cout << "************************************************************************\n\n";
	cout << "Great!!! Here is your favorite movie: " << movieName << endl;

	int numberOfBooking;
	cout << "How many tickets do you wants to book?\n";
	MyCin(numberOfBooking);

	int totalPrice = numberOfBooking * pricePerSeat;
	cout << "\nTotal amount to be paid is: " << totalPrice << " RS.\n";

	while (true)
	{
		int paidAmount = 0;
		cout << "Please pay the amount\n";
		MyCin(paidAmount);

		if (paidAmount != totalPrice)
		{
			cout << "Please pay the requested amount: " << totalPrice << " RS." << endl;
		}
		else
			break;
	}
	cout << "Please wait!!! Your booking is in progress...\n";
	Sleep(5000);

	if (!Booking::BookTicket(userId, showId, numberOfBooking, totalPrice))
		cout << "Sorry!! Some error occured during booking. Please try again\n";
	else
	{
		cout << "Greate!! You have successfully booked the ticket. Here is the details!\n";
		ViewBookings(userId);
	}
}

/*Method to fetch the movie details of a given userId in the particular city*/
void FetchMovieDetails(long userId, string city)
{
	vector<IMovieDetails*> movieDetails = MovieMiddle::GetMovieDetails(city);
	cout << "\nHere is the list of movies in your city with all the details!!!!\n";
	map<int, string> showIds;
	cout << "\n***********************************************************************************************\n";

	cout << left << setw(4) << "Id" << setw(25) << "MovieName" << setw(12) << "Language";
	cout << setw(12) << "MovieType" << setw(14) << "ReleaseDate" << setw(8) << "Rating";
	cout << setw(30) << "StarCasts" << setw(10) << "ShowTime" << setw(20) << "TheaterName";
	cout << setw(16) << "AvailableSeats" << setw(10) << "BookingPrice\n";
	cout << left << setw(4) << "**" << setw(25) << "*********" << setw(12) << "********";
	cout << setw(12) << "*********" << setw(14) << "***********" << setw(8) << "******";
	cout << setw(30) << "*********" << setw(10) << "*******" << setw(20) << "***********";
	cout << setw(16) << "**************" << setw(10) << "************\n";

	int bookingPrice = 0;
	for (auto md : movieDetails)
	{
		showIds.insert(map<int, string>::value_type(md->GetId(), md->GetMovieName()));
		cout << left << setw(4) << md->GetId();
		cout << setw(25) << md->GetMovieName();
		cout << setw(12) << md->GetLanguage();
		cout << setw(12) << md->GetMovieType();
		cout << setw(14) << md->GetReleaseDate();
		cout << setw(8) << md->GetRating();
		cout << setw(30) << md->GetStarCasts();
		cout << setw(10) << md->GetShowTime();
		cout << setw(20) << md->GetTheaterName();
		cout << setw(16) << md->GetAvailableSeats();
		cout << setw(10) << md->GetBookingPrice() << endl;
		if (!bookingPrice)
			bookingPrice = md->GetBookingPrice();
	}
	cout << endl;

	int showId;
	map<int, string>::iterator it;
	int continueBooking = 1;
	while (true)
	{
		cout << "Please choose valid id to book the ticket:- ";
		MyCin(showId);

		bool isValidId = false;
		it = showIds.find(showId);
		if (it == showIds.end())
		{
			cout << "Please enter valid Id. Or, 0 to cancel the booking:- ";
			MyCin(continueBooking);

			it = showIds.find(continueBooking);

			if (continueBooking == 0 || it != showIds.end())
				break;
			else
				continue;
		}
		else
			break;
	}
	if (continueBooking != 0)
		BookTicket(userId, showId, it->second, bookingPrice);
}

/*Method to fetch the theaters for a given userId in the particular city*/
void FetchTheaterDetails(long userId, string city)
{
	vector<IMovieDetails*> movieDetails = Theater::GetTheaterDetails(city);
	cout << "\nHere is the list of theater in your city with movie details!!!!\n";
	map<int, string> showIds;
	cout << "\n***********************************************************************************************\n";

	cout << left << setw(4) << "Id" << setw(20) << "TheaterName" << setw(25) << "MovieName";
	cout << setw(12) << "Language" << setw(12) << "MovieType" << setw(14) << "ReleaseDate";
	cout << setw(8) << "Rating" << setw(30) << "StarCasts" << setw(10) << "ShowTime";
	cout << setw(16) << "AvailableSeats" << setw(10) << "BookingPrice\n";
	cout << left << setw(4) << "**" << setw(20) << "***********" << setw(25) << "*********";
	cout << setw(12) << "********" << setw(12) << "*********" << setw(14) << "***********";
	cout << setw(8) << "******" << setw(30) << "*********" << setw(10) << "*******";
	cout << setw(16) << "**************" << setw(10) << "************\n";
	int bookingPrice = 0;
	for (auto md : movieDetails)
	{
		showIds.insert(map<int, string>::value_type(md->GetId(), md->GetMovieName()));

		cout << left << setw(4) << md->GetId();
		cout << setw(20) << md->GetTheaterName();
		cout << setw(25) << md->GetMovieName();
		cout << setw(12) << md->GetLanguage();
		cout << setw(12) << md->GetMovieType();
		cout << setw(14) << md->GetReleaseDate();
		cout << setw(8) << md->GetRating();
		cout << setw(30) << md->GetStarCasts();
		cout << setw(10) << md->GetShowTime();
		cout << setw(16) << md->GetAvailableSeats();
		cout << setw(10) << md->GetBookingPrice() << endl;
		if (!bookingPrice)
			bookingPrice = md->GetBookingPrice();
	}
	cout << endl;

	int showId;
	map<int, string>::iterator it;
	int continueBooking = 1;
	while (true)
	{
		cout << "Please choose valid id to book the ticket:- ";
		MyCin(showId);
		it = showIds.find(showId);
		if (it == showIds.end())
		{
			cout << "Please enter valid Id. Or, 0 to cancel the booking:- ";
			MyCin(continueBooking);

			it = showIds.find(continueBooking);
			if (continueBooking == 0 || it != showIds.end())
				break;
			else
				continue;
		}
		else
			break;
	}
	if (continueBooking != 0)
		BookTicket(userId, showId, it->second, bookingPrice);
}

void ServeExistingUser(long userId, string cityName)
{
	int movieOrTheater = 0;
	while (true)
	{
		cout << "\n1: To view list of movies.\n";
		cout << "2: To view list of theaters.\n";
		cout << "3: To view your bookings.\n";
		MyCin(movieOrTheater);

		if (movieOrTheater != 1 && movieOrTheater != 2 && movieOrTheater != 3)
		{
			cout << "Please enter valid choice 1, 2 or 3\n\n";
			movieOrTheater = 0;
			continue;
		}

		switch (movieOrTheater)
		{
		case 1:
			FetchMovieDetails(userId, cityName);
			break;

		case 2:
			FetchTheaterDetails(userId, cityName);
			break;

		case 3:
			ViewBookings(userId);
			break;
		}
	}
}

/*Method for the existing user to login and perfomr other action for the user.*/
void ExistingUser()
{
	IUser* user = NULL;

	cout << "Existing User!\n";
	cout << "Enter your mobile number:";
	long mobileNo; MyCin(mobileNo);
	cout << "Enter your password: ";
	string password; cin >> password;

	user = UserMiddle::LogIn(mobileNo, password);
	if (user == NULL)
	{
		cout << "Either mobile number or password is incorrect.\n";
		cout << "Please enter valid mobile number and password or register as a new user.\n";
	}
	else
	{
		cout << "Successfully logged-in...\n";
		ServeExistingUser(mobileNo, user->GetCity());
	}
}

/*Method to Register the new user.*/
void NewUserRegistration()
{
	//insert into User values(123456789,'12345','Santosh', 'santosh796@gmail.com','Male','Hyderabad');
	cout << "New User! To register enter the details\n";
	cout << "Enter your mobile number: ";
	long mobileNo; MyCin(mobileNo);
	cout << "Enter your password: ";
	string password; getline(cin, password);
	cout << "Enter your name: ";
	string name; getline(cin, name);
	cout << "Enter your email id: ";
	string emailId; cin >> emailId;
	cout << "Enter your Gender: ";
	string gender; cin >> gender;
	cout << "Enter your City name: ";
	string cityName; cin>>cityName;

	int submitRegistration=0; 
	while (true)
	{
		cout << "Press 1 to submit registration details.\n";
		cout << "Press 2 to cancel the submission.\n";
		MyCin(submitRegistration);

		if (submitRegistration != 1 && submitRegistration != 2)
		{
			cout << "Please enter valid choice 1, or 2\n\n";
			submitRegistration = 0;
			continue;
		}
		else
			break;
	}	
		
	if (submitRegistration == 1)
	{
		bool isRegistered = UserMiddle::RegiseterNewUser(mobileNo, password, name, emailId, gender, cityName);
		if (isRegistered)
		{
			cout << "You have successfully registered.";
			ServeExistingUser(mobileNo, cityName);
		}
		else
			cout << "Some error occurred during registration. Please try again...";
	}
	else if (submitRegistration == 2)
	{
		cout << "Registration submission is cancelled. Please try again.";
	}
}

/*The main entry point*/
int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	cout << "~~~~~~~~~~~~~~~~Welcome to BookMyShow!-By Santosh~~~~~~~~~~~~~~~~~~~\n\n";

	int isExistingUser = 0;
	while (true)
	{
		//system("cls");
		cout << "\n\n--------------------------------------------\n";
		cout << "Existing User? Press 1 to login.\n";
		cout << "New User? Press 2 to register.\n";
				
		MyCin(isExistingUser);
		//validation
		if (isExistingUser != 1 && isExistingUser != 2)
		{
			cout << "Please enter valid choice 1 or 2\n\n";
			isExistingUser = 0;
			continue;
		}

		try
		{
			switch (isExistingUser)
			{
			case 1:
				ExistingUser();
				isExistingUser = 0;
				break;

			case 2:
				cout << "New User!\n";
				NewUserRegistration();
				break;
			}
		}
		catch(...)
		{
			cout << "Error occurred. Trying to recover!!!";
		}
	}
	return 0;
}