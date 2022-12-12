#pragma once
#include <ostream>
#include <string>
using namespace std;

class UKey {
#pragma region Fields
	int rank;
	string fName;
	string email;
#pragma endregion;

public:

#pragma region Constructors
	UKey(int rank, string fName, string email)
		: rank(rank), fName(fName), email(email)
	{
	}
#pragma endregion

#pragma region Get/Set
	int getRank() const { return this->rank; }
	string getFName() const { return this->fName; }
	string getEmail() const { return this->email; }
#pragma endregion

#pragma region Operators & Hash

	bool operator==(const UKey& player)
	{
		return this->rank == player.rank
			&& this->fName == player.fName
			&& this->email == player.email;
	}

	friend ostream& operator<<(ostream& output, UKey& player) {
		output << player.rank << ",";
		output << player.fName << ",";
		output << player.email;
		return output;
	}

	friend istream& operator>>(istream& input, UKey& player)
	{
		string playerAsStr;
		input >> playerAsStr;

		return input;
	}

	std::size_t hash() const
	{
		size_t hash = std::hash<int>()(this->rank)
			+ 73 * std::hash<string>()(this->fName)
			+ 154 * std::hash<string>()(this->email);
	}

#pragma endregion
};