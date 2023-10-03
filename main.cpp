#include <iostream>
#include <assert.h>
#include "user.h"
#include "admin.h"
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

vector <user> savedata;

int main()
{

	admin Admin;
	user mainUser;
	user tmpusers(2000, "1111", "mostafa", "sayed", 21, "cairo", "male", 1);
	savedata.push_back(tmpusers);
	user tmpusers1(3000, "2222", "syada", "sayed", 31, "cairo", "female", 0);
	savedata.push_back(tmpusers1);
	user tmpusers2(4000, "3333", "eman", "sayed", 23, "cairo", "female", 2);
	savedata.push_back(tmpusers2);

	queue < long long > waitingList;
	waitingList.push(2000);
	waitingList.push(3000);

	bool isadmin;
	int temp;
	char ch;
	int num, index;
	long long id;
	string pass;

	mainUser.INTRO();

	do
	{
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. NEW ACCOUNT";
		cout << "\n\n\t02. ADMIN LOGIN ";
		cout << "\n\n\t03. USER LOGIN ";
		cout << "\n\n\t04. Exit";

		cout << "\n\n\tSelect Your Option (1-4): ";

		cin >> ch;
		char sh;

		system("cls");

		switch (ch)
		{

		case '1':

			mainUser.registeretion(savedata, waitingList);
			break;

		case '2': 

			isadmin = Admin.admin_Login();
			if (isadmin)
			{
				cout << "successfully login!" << endl;
				system("cls");
				do
				{
					bool isExit = false;
					if (isadmin)
					{
						cout << "\n\n\t01. DISPLAY USER " << endl;
						cout << "\n\n\t02. DISPLAY ALL USER " << endl;
						cout << "\n\n\t03. DELETE USER" << endl;
						cout << "\n\n\t04. DELETE ALL USER" << endl;
						cout << "\n\n\t05. VIEW WAITING LIST" << endl;
						cout << "\n\n\t06. RETURN TO MAIN MENU" << endl;
						cin >> num;

						system("cls");
						switch (num) {
						case 1:
							system("cls");
							cout << "Enter user national ID:  ";
							cin >> num;
							Admin.Display(num, savedata);
							break;

						case 2:
							system("cls");
							Admin.DisplayAll(savedata);
							cout << "*********************************************" << endl;
							system("pause");
							break;

						case 3:
							system("cls");
							cout << "Enter user national ID:  ";
							cin >> num;
							Admin.Delete(num, savedata);
							break;

						case 4:
							system("cls");
							Admin.DeleteAll(savedata);
							break;

						case 5:
							system("cls");
							if (!waitingList.empty())
								Admin.DisplayWaitingList(waitingList, savedata);
							else
								cout << "Waiting List is Empty. \n\n";
							break;

						case 6:
							isExit = true;
							break;

						default:
							cout << "Invalid entry\n";
							break;

						}
					}

				} while (num != 6);
			}
			else
				cout << "Invalid Information.";
		    break;

		case '3':

			if (mainUser.login(index, savedata))
			{
				while (true)
				{
					bool isExit = false;
					cout << "\n\n\t01. DISPLAY ACCOUNT INFO";
					cout << "\n\n\t02. DELETE ACCOUNT";
					cout << "\n\n\t03. EDIT ACCOUNT INFO";
					cout << "\n\n\t04. EXIT\n";
					cout << "\n\n\tSelect your option: ";
					cin >> num;

					switch (num)
					{
					case 1:
						system("cls");
						Admin.Display(savedata[index].id, savedata);
						break;
					case 2:
						system("cls");
						Admin.Delete(savedata[index].id, savedata);
						isExit = true;
						break;
					case 3:
						system("cls");
						mainUser.edit(index, savedata, waitingList);
						break;
					case 4:
						isExit = true;
						system("cls");
						break;
					default:
						cout << "You have entered an invalid option. Try again";
						break;
					}
					if (isExit)
					{
						break;
					}
				}
			}
			else
				cout << "You have entered invalid information";
			break;
		case '4':

			cout << "\n\n\tThanks for using vaccine tracking system";
			return 0;

		default:
			cout << "\a";

		}

		cin.ignore();
		cin.get();

	} while (ch != '6');

	return 0;

}