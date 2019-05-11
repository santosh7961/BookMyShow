#pragma once
#include "Interfaces.h"

#ifdef _EXPORTING
#define CLASS_DECLSPEC    _declspec(dllexport)
#else
#define CLASS_DECLSPEC    _declspec(dllimport)
#endif

class CLASS_DECLSPEC MovieDetails : public IMovieDetails
{
	int id;
	string movieName;
	string language;
	string movieType;
	string releaseDate;
	float rating;
	string startCasts;
	string showTime;
	string theaterName;
	int availableSeats;
	int bookingPrice;
public:

	// Inherited via IMovieDetails
	virtual int GetId() override;
	virtual void SetId(int input) override;
	virtual string GetMovieName() override;
	virtual void SetMovieName(string input) override;
	virtual string GetLanguage() override;
	virtual void SetLanguage(string input) override;
	virtual string GetMovieType() override;
	virtual void SetMovieType(string input) override;
	virtual string GetReleaseDate() override;
	virtual void SetReleaseDate(string input) override;
	virtual float GetRating() override;
	virtual void SetRating(float input) override;
	virtual string GetStarCasts() override;
	virtual void SetStarCasts(string input) override;
	virtual string GetShowTime() override;
	virtual void SetShowTime(string input) override;
	virtual string GetTheaterName() override;
	virtual void SetTheaterName(string input) override;
	virtual int GetAvailableSeats() override;
	virtual void SetAvailableSeats(int input) override;
	virtual int GetBookingPrice() override;
	virtual void SetBookingPrice(int input) override;
};
