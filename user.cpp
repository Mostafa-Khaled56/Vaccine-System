#include "user.h"
#include"assert.h"
#include"admin.h"
#include<iostream>
#include<string>
#include <cassert>
#include <iomanip>
#include <queue>


using namespace std;

user::user()
{
}

user::user(long long id, string pass, string fname, string lname,
	int age, string governate, string gender, int numofDosage)
{
	this->id = id;
	this->pass = pass;
	this->fname = fname;
	this->lname = lname;
	this->age = age;
	this->governate = governate;
	this->gender = gender;
	this->numofDosage = numofDosage;
	if (numofDosage == 0 || numofDosage == 1)
		this->isVaccinated = false;
	else
		this->isVaccinated = true;
}

void user::INTRO()
{


	{
		cout << "\n\n\n\t  VACCINE";
		cout << "\n\n\tTRACKING ";
		cout << "\n\n\t  SYSTEM";
		cout << "\n\n\n\nMADE BY : BIO_9";

		cin.get();
	}




}

void user::registeretion(vector <user>& savedata, queue <long long>& waitinglist4) {

	int temp;
	char te;
	string gender;

	cout << "are you an egyptian resident? (Y/N)" << endl;
	cin >> te;

	if (toupper(te) == 'N')
	{
		cout << "this service is only available for egyptian residence" << endl;
	}

	else if (toupper(te) == 'Y')
	{
		cout << "enter your id" << endl;
		cin >> id;
		for (int i = 0; i < savedata.size(); i++) {
				if ((id == savedata[i].id) || id < 10000000000000)
				{
					cout << "Invalid id, try another id" << endl;
					cin >> id;
					i = 0;
				}
			}
		cout << "enter your password" << endl;
		cin >> pass;
		cout << "enter your first name" << endl;
		cin >> fname;
		cout << "enter your last name" << endl;
		cin >> lname;
		cout << "enter your age" << endl;
		cin >> age;
		cout << "enter your governate" << endl;
		cin >> governate;
		cout << "enter your gender (female/male) " << endl;
		cin >> gender;
		cout << "enter number of dosages" << endl;
		cin >> temp;
		if (temp == 2) {

			cout << "vaccinated!" << endl;
			numofDosage = temp;
		}
		else if (temp == 1 || temp == 0)
		{
			numofDosage = temp;
			waitinglist4.push(id);
		}
		cout << endl << "succefully regstired!";

		user registringUser(id, pass, fname, lname, age, governate, gender, numofDosage);
		savedata.push_back(registringUser);
		return ;
	}

	else
	{
		cout << "Invalid entry.\n";
	}

}

bool user::login(int &index, vector <user>& savedata)
{
	cout << "enter your id" << endl;
	cin >> id;
	cout << "enter your password" << endl;
	cin >> pass;

	for (int i = 0; i < savedata.size(); i++)
	{
		if (savedata[i].id == id && savedata[i].pass == pass)
		{
			index = i;
			return true;
		}
	}
	return false;
}

bool user::checkuser(long long id, string pass)
{

	if (this->id == id && this->pass == pass)
	{
		return true;
	}
	else
	{
		cout << "wrong password or wrong id" << endl;
		return false;
	}
}

void user::checkIfWaiting(long long id, bool isVaccinated, queue <long long> &waitinglist4)
{
	queue <long long> sub;

	if (!isVaccinated)
	{
		waitinglist4.push(id);
		return;
	}
	else
	{
		int tmp_index = waitinglist4.size();
		for (int i = 0; i < tmp_index; i++)
		{
			if (waitinglist4.front() != id)
			{
				sub.push(waitinglist4.front());
			}
			waitinglist4.pop();
		}
		waitinglist4 = sub;
	}
}

void user::edit(int index, vector <user>& savedata, queue <long long> &waitinglist4) {

	system("cls");
	cout << "1-Number of dosages" << endl;
	cout << "2-password" << endl;
	cout << "3-first name" << endl;
	cout << "4-last name" << endl;
	cout << "5- age" << endl;
	cout << "6-gender" << endl;
	cout << "7-governorate" << endl;
	cout << "8-to save data\n\n";
	int choice;
	int temp;

	do
	{
		bool isExit = false, tmp = savedata[index].isVaccinated;
		cout << "what would you like to change?  ";
		cin >> choice;


		switch (choice)
		{
		case 1:cout << "enter your new number of dosages" << endl;

			cin >> numofDosage;
			savedata[index].numofDosage = numofDosage;

			if ((numofDosage == 1 || numofDosage == 0) && tmp)
			{
				isVaccinated = false;
				checkIfWaiting(savedata[index].id, isVaccinated, waitinglist4);
			}
			else if (savedata[index].numofDosage == 2 && !tmp)
			{
				isVaccinated = true;
				checkIfWaiting(savedata[index].id, isVaccinated, waitinglist4);
			}

			savedata[index].isVaccinated = isVaccinated;

			break;
		case 2:
			cout << "enter your password" << endl;
			cin >> pass;
			savedata[index].pass = pass;
			break;
		case 3:

			cout << "enter your first name" << endl;
			cin >> fname;
			savedata[index].fname = fname;
			break;
		case 4:
			cout << "enter your last name" << endl;
			cin >> lname;
			savedata[index].lname = lname;
			break;
		case 5:
			cout << "enter your new age" << endl;
			cin >> age;
			savedata[index].age = age;
			break;
		case 6:
			cout << "enter your gender" << endl;
			cin >> gender;
			savedata[index].gender = gender;
			break;
		case 7:
			cout << "enter your governate" << endl;
			cin >> governate;
			savedata[index].governate = governate;
		case 8:

			cout << "Data updated succefully.";
			isExit = true;
			break;
		default: cout << "Invalid choice" << endl;
			break;
		}

		if (isExit)
			break;

	} while (choice != 8);


	return;

}