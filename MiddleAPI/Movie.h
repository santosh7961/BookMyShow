#pragma once

#include "../Common/Interfaces.h"
#pragma warning(push)
#pragma warning(disable:4251)
//your declarations that cause 4251
#pragma warning(pop)

#ifdef _EXPORTING
#define CLASS_DECLSPEC    _declspec(dllexport)
#else
#define CLASS_DECLSPEC    _declspec(dllimport)
#endif


class CLASS_DECLSPEC MovieMiddle
{
public:
	MovieMiddle();
	~MovieMiddle();
	static vector<IMovieDetails*> GetMovieDetails(string city);
};

