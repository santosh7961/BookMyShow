#include "stdafx.h"
#include "Movie.h"
#include "../Backend/PerformDatabaseActions.h"

vector<IMovieDetails*> MovieMiddle::GetMovieDetails(string city)
{
	vector<IMovieDetails*> movDetails = PerformDatabaseActions::GetMovieDetails(city);
	return movDetails;
}


MovieMiddle::MovieMiddle()
{
}


MovieMiddle::~MovieMiddle()
{
}
