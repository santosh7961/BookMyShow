#pragma once
#include "Interfaces.h"
#pragma warning(push)
#pragma warning(disable:4251)
//your declarations that cause 4251
#pragma warning(pop)

#ifdef _EXPORTING
#define CLASS_DECLSPEC    _declspec(dllexport)
#else
#define CLASS_DECLSPEC    _declspec(dllimport)
#endif

//template class __declspec(dllexport) std::basic_string<char>;//for warnings

class CLASS_DECLSPEC User:public IUser
{
	long userId;
	string password;
	string name;
	string emailId;
	string gender;
	string city;
	
public:
	User() {};
	~User() {};
	
	// Inherited via IUser
	virtual long GetMobileNumber() override;
	virtual void SetMobileNumber(long mobileNo) override;
	virtual string GetPassword() override;
	virtual void SetPassword(string password) override;
	virtual string GetName() override;
	virtual void SetName(string name) override;
	virtual string GetEmailId() override;
	virtual void SetEmailId(string emailId) override;
	virtual string GetGender() override;
	virtual void SetGender(string gender) override;
	virtual string GetCity() override;
	virtual void SetCity(string city) override;
};

