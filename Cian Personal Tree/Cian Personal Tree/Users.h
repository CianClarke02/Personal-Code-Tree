#pragma once
#include <ostream>
#include <string>
using namespace std;

class User {
#pragma region Fields
		string user_id;
		int rank;
		string fName;
		string email;
#pragma endregion;

public:

#pragma region Constructors
	User(string user_id, int rank, string fName, string email)
		: user_id(user_id), rank(rank), fName(fName), email(email)
	{
	}
#pragma endregion

};