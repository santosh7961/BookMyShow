#include "stdafx.h"
#include "User.h"
#include "../Backend/PerformDatabaseActions.h"


IUser* User::LogIn(long mobileNo, string password)
{
	IUser *pUser = PerformDatabaseActions::ValidateUserDetails(mobileNo, password);
	return pUser;
}

bool User::RegiseterNewUser(long mobileNo, string password, string name, string emailId, string gender, string city)
{
	return PerformDatabaseActions::RegisterNewUser(mobileNo, password, name, emailId, gender, city);
}

long User::GetMobileNumber()
{
	return userId;
}

void User::SetMobileNumber(long mobileNo)
{
	this->userId = mobileNo;
}

string User::GetPassword()
{
	return password;
}

void User::SetPassword(string password)
{
	this->password=password;
}

string User::GetName()
{
	return name;
}

void User::SetName(string name)
{
	this->name = name;
}

string User::GetEmailId()
{
	return emailId;
}

void User::SetEmailId(string emailId)
{
	this->emailId = emailId;
}

string User::GetGender()
{
	return gender;
}

void User::SetGender(string gender)
{
	this->gender = gender;
}

string User::GetCity()
{
	return city;
}

void User::SetCity(string city)
{
	this->city = city;
}
