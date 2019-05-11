#include "stdafx.h"
#include "User.h"
#include "../Backend/PerformDatabaseActions.h"


IUser* UserMiddle::LogIn(long mobileNo, string password)
{
	IUser *pUser = PerformDatabaseActions::ValidateUserDetails(mobileNo, password);
	return pUser;
}

bool UserMiddle::RegiseterNewUser(long mobileNo, string password, string name, string emailId, string gender, string city)
{
	return PerformDatabaseActions::RegisterNewUser(mobileNo, password, name, emailId, gender, city);
}

UserMiddle::UserMiddle()
{
}


UserMiddle::~UserMiddle()
{
}
