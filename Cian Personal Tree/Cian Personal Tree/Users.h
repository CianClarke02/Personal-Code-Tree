#pragma once
#include <ostream>
#include <string>
using namespace std;

class User {
#pragma region Fields
	string user_id;
	int rank;
	string fName;
	string lName;
	string gender;
	string email;
	int phone;
	string postcode;
	string address;
	string country;
	double lastLogTime;
	double credit;
#pragma endregion;

public:

#pragma region Constructors
	User(string user_id, int rank, string fName, string lName, string gender, string email, int phone, string postcode, string address, string country, double lastLogTime, double credit)
		: user_id(user_id), rank(rank), fName(fName), lName(lName), gender(gender), email(email), phone(phone), postcode(postcode), address(address), country(country), lastLogTime(lastLogTime), credit(credit)
	{
	}
#pragma endregion

#pragma region Get/Set
	string getUser_id() const { return this->user_id; }
	int getRank() const { return this->rank; }
	string getFName() const { return this->fName; }
	string getLName() const { return this->lName; }
	string getGender() const { return this->gender; }
	string getEmail() const { return this->email; }
	int getPhone() const { return this->phone; }
	string getPostcode() const { return this->postcode; }
	string getAddress() const { return this->address; }
	string getCountry() const { return this->country; }
	double getLastLogTime() const { return this->lastLogTime; }
	double getCredit() const { return this->credit; }
#pragma endregion

#pragma region Operators & Hash

	bool operator==(const User& player)
	{
		return this->user_id == player.user_id
			&& this->rank == player.rank
			&& this->fName == player.fName
			&& this->lName == player.lName
			&& this->gender == player.gender
			&& this->email == player.email
			&& this->phone == player.phone
			&& this->postcode == player.postcode
			&& this->address == player.address
			&& this->country == player.country
			&& this->lastLogTime == player.lastLogTime
			&& this->credit == player.credit;
	}

	friend ostream& operator<<(ostream& output, User& player) {
		output << player.user_id << ",";
		output << player.rank << ",";
		output << player.fName << ",";
		output << player.lName << ",";
		output << player.gender << ",";
		output << player.email << ",";
		output << player.phone << ",";
		output << player.postcode << ",";
		output << player.address << ",";
		output << player.country << ",";
		output << player.lastLogTime << ",";
		output << player.credit;
		return output;
	}

	friend istream& operator>>(istream& input, User& player)
	{
		string playerAsStr;
		input >> playerAsStr;

		return input;
	}

	std::size_t hash() const
	{
		size_t hash = std::hash<string>()(this->user_id)
			+ 73 * std::hash<int>()(this->rank)
			+ 220 * std::hash<string>()(this->fName)
			+ 204 * std::hash<string>()(this->lName)
			+ 62 * std::hash<string>()(this->gender)
			+ 94 * std::hash<string>()(this->email)
			+ 154 * std::hash<int>()(this->phone)
			+ 123 * std::hash<string>()(this->postcode)
			+ 182 * std::hash<string>()(this->address)
			+ 200 * std::hash<string>()(this->country)
			+ 15 * std::hash<double>()(this->lastLogTime)
			+ 157 * std::hash<double>()(this->credit);
	}

#pragma endregion
};