#pragma once
#include <string>
#include"user.h"
#include <vector>


using namespace std;

class admin
{

public:
	string name;
	string pass;

	bool admin_Login();
	void Display(long long id, vector <user>& savedata);
	void DisplayAll(vector <user>& savedata);
	void DisplayWaitingList(queue <long long> &waitinglist, vector <user> &savedata);
	void Delete(long long id, vector <user>& savedata);
	void DeleteAll(vector <user>& savedata);

};

