#include "stdafx.h"
#include "Movie.h"
#include "../Backend/PerformDatabaseActions.h"

vector<IMovieDetails*> MovieDetails::GetMovieDetails(string city)
{
	vector<IMovieDetails*> movDetails = PerformDatabaseActions::GetMovieDetails(city);
	return movDetails;
}

int MovieDetails::GetId()
{
	return id;
}

void MovieDetails::SetId(int input)
{
	this->id = input;
}

string MovieDetails::GetMovieName()
{
	return movieName;
}

void MovieDetails::SetMovieName(string input)
{
	this->movieName = input;
}

string MovieDetails::GetLanguage()
{
	return language;
}

void MovieDetails::SetLanguage(string input)
{
	language = input;
}

string MovieDetails::GetMovieType()
{
	return movieType;
}

void MovieDetails::SetMovieType(string input)
{
	movieType = input;
}

string MovieDetails::GetReleaseDate()
{
	return releaseDate;
}

void MovieDetails::SetReleaseDate(string input)
{
	releaseDate = input;
}

float MovieDetails::GetRating()
{
	return rating;
}

void MovieDetails::SetRating(float input)
{
	rating = input;
}

string MovieDetails::GetStarCasts()
{
	return startCasts;
}

void MovieDetails::SetStarCasts(string input)
{
	startCasts = input;
}

string MovieDetails::GetShowTime()
{
	return showTime;
}

void MovieDetails::SetShowTime(string input)
{
	showTime = input;
}

string MovieDetails::GetTheaterName()
{
	return theaterName;
}

void MovieDetails::SetTheaterName(string input)
{
	theaterName = input;
}

int MovieDetails::GetAvailableSeats()
{
	return availableSeats;
}

void MovieDetails::SetAvailableSeats(int input)
{
	availableSeats = input;
}

int MovieDetails::GetBookingPrice()
{
	return bookingPrice;
}

void MovieDetails::SetBookingPrice(int input)
{
	bookingPrice = input;
}
