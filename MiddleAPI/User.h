#pragma once

#include "../Common/Interfaces.h"
#pragma warning(push)
#pragma warning(disable:4251)

#pragma warning(pop)

#ifdef _EXPORTING
#define CLASS_DECLSPEC    _declspec(dllexport)
#else
#define CLASS_DECLSPEC    _declspec(dllimport)
#endif


class CLASS_DECLSPEC UserMiddle
{
public:
	UserMiddle();
	~UserMiddle();

	static IUser* LogIn(long mobileNo, string password);
	static bool RegiseterNewUser(long mobileNo, string password, string name, string emailId, string gender, string city);

};

