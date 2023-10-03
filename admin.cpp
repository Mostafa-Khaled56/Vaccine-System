#include "admin.h"
#include "user.h"
#include <string>
#include<iostream>
#include <cstdlib>
#include<cctype>
#include<iomanip>
#include<iostream>
#include<fstream>
#include <ctype.h>
#include<queue>
#include<string>
#include<vector>


using namespace std;

bool admin::admin_Login()
{
	string name;
	string password;
	system("cls");

	while (true)
	{
		cout << "enter your name  (X to exit) " << endl;
		cin >> name;

		if (name == "admin")
		{
			cout << "enter password :" << endl;
			cin >> password;
			if (password == "admin") {
				cout << "succfully login" << endl;
				return true;
			}
			else if (password != "admin")
			{
				cout << "wrong password " << endl;
				return false;
			}
		}
		else if (name == "X")
		{
			return false;
		}
		else
		{
			cout << "Wrong username, please try again. (X to exit)\n";
		}
	}
}

void admin::Display(long long id, vector <user>& savedata)
{
	int j = -1;
	for (int i = 0; i < savedata.size(); i++)
	{
		if (savedata[i].id == id)
		{
			j = i;
			break;
		}
	}
	if (j == -1)
	{
		cout << "This ID does not exist\n";
	}
	else
	{

		cout << "===================================================================================\n";
		cout << "id\tpass\tfirst name\tlast name\tage\tgender\t\tgovernorate\n";
		cout << "===================================================================================\n";
		cout << "" << savedata[j].id << setw(9) << savedata[j].pass << setw(10) << savedata[j].fname
			<< setw(15) << savedata[j].lname << setw(11) << savedata[j].age << setw(11)
			<< savedata[j].gender << setw(15) << savedata[j].governate << endl 
			<< "Vaccinated: " << savedata[j].isVaccinated << "\t\t" << "Number of dosages: " << savedata[j].numofDosage;
	}
}

void admin::DisplayAll(vector <user>& savedata)
{
	cout << "\n\n\t\tlist of users\n\n";
	
	{
		for (int j = 0; j < savedata.size(); j++)
		{
			cout << "===================================================================================\n";
			cout << "id\tpass\tfirst name\tlast name\tage\tgender\t  governorate\n";
			cout << "===================================================================================\n";
			cout << "" << savedata[j].id << setw(9) << savedata[j].pass << setw(10) << savedata[j].fname
				<< setw(15) << savedata[j].lname << setw(11) << savedata[j].age << setw(11)
				<< savedata[j].gender << setw(15) << savedata[j].governate << endl
				<< "Vaccinated: " << savedata[j].isVaccinated << "\t\t" << "Number of dosages: " << savedata[j].numofDosage << "\n\n";;

		}
	}
}

void admin::DisplayWaitingList(queue <long long> &waitinglist, vector <user> &savedata)
{
	while (true)
	{
		int index;
		char choice;
		for (int i = 0; i < savedata.size(); i++)
		{
			if (savedata[i].id == waitinglist.front())
			{
				index = i;
				break;
			}
		}

		cout << "===================================================================================\n";
		cout << "id\tpass\tfirst name\tlast name\tage\tgender\t\tgovernorate\n";
		cout << "===================================================================================\n";
		cout << "" << savedata[index].id << setw(12) << savedata[index].pass << setw(10) << savedata[index].fname
			<< setw(15) << savedata[index].lname << setw(11) << savedata[index].age << setw(11)
			<< savedata[index].gender << setw(15) << savedata[index].governate << endl
			<< "Vaccinated: " << savedata[index].isVaccinated << "\t\t" << "Number of dosages: " << savedata[index].numofDosage << "\n\n";
		cout << "Do you want to remove this user from waiting list? (Y/N)";
			cin >> choice;
			if (choice == 'Y')
			{
				savedata[index].numofDosage = 2;
				savedata[index].isVaccinated = true;
				waitinglist.pop();
				if (waitinglist.empty())
				{
					break;
				}
			}
			else if (choice == 'N')
				break;
			else
				cout << "Invalid Entry.\n";
	}
}

void admin::Delete(long long id, vector <user>& savedata)
{
	int j = -1;
	for (int i = 0; i < savedata.size(); i++)
	{
		if (savedata[i].id == id)
		{
			savedata.erase(savedata.begin() + i);
			j = i;
			break;
		}
	}

	if (j == -1)
	{
		cout << "This ID does not exist\n";
	}
}

void admin::DeleteAll(vector <user>& savedata)
{
	savedata.clear();
}
