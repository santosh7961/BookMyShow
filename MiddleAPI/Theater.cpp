#include "stdafx.h"
#include "Theater.h"
#include "../Backend/PerformDatabaseActions.h"

vector<IMovieDetails*> Theater::GetTheaterDetails(string city)
{
	vector<IMovieDetails*> movDetails = PerformDatabaseActions::GetTheaterDetails(city);
	return movDetails;
}