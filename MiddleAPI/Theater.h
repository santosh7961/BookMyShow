#pragma once
#include "../Common/Interfaces.h"

#ifdef _EXPORTING
#define CLASS_DECLSPEC    _declspec(dllexport)
#else
#define CLASS_DECLSPEC    _declspec(dllimport)
#endif
class CLASS_DECLSPEC Theater
{
public:
	Theater(){}
	~Theater(){}
	static vector<IMovieDetails*> GetTheaterDetails(string city);
};

