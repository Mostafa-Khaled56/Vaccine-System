#pragma once
#include<string>
#include<queue>
#include<vector>

using namespace std;
class user
{

public:
	long long id;
	string pass;
	string fname;
	string lname;
	int age;
	string governate;
	string gender;
	int numofDosage;
	bool isVaccinated;

public:

	user();
	user(long long, string, string, string, int, string, string, int);
	void registeretion(vector <user>& savedata, queue <long long>& waitinglist4);
	bool checkuser(long long, string);
	void checkIfWaiting(long long, bool, queue <long long> &waitinglist4);
	void edit(int index, vector <user>& savedata, queue <long long> &waitinglist4);
	bool login(int &index, vector <user>& savedata);
	void INTRO();
};