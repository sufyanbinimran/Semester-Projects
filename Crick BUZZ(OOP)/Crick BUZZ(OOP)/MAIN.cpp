#include<iostream>
#include"PLAYER HEADER.h"
#include"TEAM HEADER.h"
#include"MATCH HEADER.h"
#include "n.h"
using namespace std;

int main()
{
	TEAM obj;

	TEAM obj2;

	PLAYER* ptr = &obj;

	PLAYER* ptr2 = &obj2;
	
	MATCH o;
	
	n N;


	int y = 0;


	cout << "                                                                                  ";
	cout << "                                                                                  ";
	cout << "                                                                                  ";
	cout << "                                                                                  ";
	cout << "                                                                                  ";
	cout << "                                                                                  "<<endl;
	cout << "           **************  WELCOME TO CRICK BUZZ   **************"<<endl;
	cout << "           ************** Created By: Sufyan MAlik **************"<<endl;
	cout << "           ************** Created By: Mustafa Baig **************"<<endl;
	cout << "           ************** Roll number : 21F-9197   **************"<<endl;
	cout << "           ************** Roll number : 21F-9257   **************"<<endl;
	cout << "                                                                                  ";
	cout << "                                                                                  ";
	cout << "                                                                                  ";
	cout << "                                                                                  ";
	cout << "                                                                                  ";


	cout << endl;
	system("Pause");
	system("cls");

	obj2.setpassword();
	cout << endl;
	system("Pause");
	system("cls");


	cout << " $$$ Welcome to player class section $$$" << endl;
	cout << " ^^^^^ Pakistan team players ^^^^^" << endl;

	ptr->setname_player1("a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k");
	ptr->setshirt_no1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
	ptr->set_avg1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
	ptr->seticc_ranking1("1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th", "10th", "11th");
	ptr->setruns1(100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100);
	ptr->setmatch1(10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110);
	ptr->setwickets1(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
	ptr->display1();
	cout << endl;

	cout << " ^^^^^ Indian team players ^^^^^" << endl;
	ptr2->setname_player2("a0", "b0", "c0", "d0", "e0", "f0", "g0", "h0", "i0", "j0", "k0");
	ptr2->setshirt_no2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
	ptr2->set_avg2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
	ptr2->seticc_ranking2("0th", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th", "10th", "11th");
	ptr2->setruns2(100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100);
	ptr2->setmatch2(10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110);
	ptr2->setwickets2(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
	ptr2->display1();
	cout << endl;

	int num;
	int lol=1;
	while (lol)
	{
		cout << "$$$ Functions of Player and Team Class $$$" << endl;
		cout << "To add any player press 1" << endl;
		cout << "To remove any player press 2" << endl;
		cout << "To search any player press 3" << endl;
		cout << "To update any player press 4" << endl;
		cout << "To check teams status press 5" << endl;
		cout << "To check shedule of matches press 6" << endl;
		cout << "To update any of the team captan press 7" << endl;
		cout << "To update any of the team coach press 8" << endl;


		cin >> num;


		switch (num)
		{
			
		case 1:
			int enter;
			cout << "Enter you want to add player in team one or two ";
			cin >> enter;
			if (enter == 1)
			{
				ptr->add_player("A", 1, 2, "5th", 5, 7, 6);
				ptr->display1();
			}
			else if (enter == 2)
			{
				ptr2->add_player("H", 1, 2, "5th", 5, 7, 6);
				ptr2->display1();
			}
			cout << endl;

			break;
		case 2:

			while (1)
			{

				cout << "Which team player you want to remove 1 or 2 ";

				int option;
				cin >> option;
				if (option == 1)
				{
					ptr->remove_player();
					break;
				}
				else if (option == 2)
				{
					ptr2->remove_player();
					break;
				}
				else
				{
					exit(0);
				}
				
			}
			break;
		case 3:
			int x;
			cout << "From which team you want to search players team 1 or team 2 ";
			cin >> x;
			if (x == 1)
			{
				ptr->search_player();
				break;
			}
			else if (x == 2)
			{
				ptr2->search_player();
				break;
			}
			break;
		case 4:


			cout << "From which team you want to update players team 1 or team 2 ";
			cin >> y;
			if (y == 1)
			{
				ptr->update_player();
				ptr->display1();
				break;
			}
			else if (y == 2)
			{
				ptr2->update_player();
				ptr2->display1();
				break;
			}
			break;
		case 5:
			obj2.display_team();
			obj2.DISPAYT();

			break;
		case 6:
			obj2.display_matches();
			break;
		case 7:
			obj2.display_team();
			obj2.update_captain();
			break;
		case 8:
			obj2.display_team();
			obj2.update_coach();
			break;
		}
		cout << "If you want to continue in this class press 1 :"<<endl;
		cout << "If you want to exit from this class press any number :"<<endl;
		cin >> lol;
		if (lol != 1)
		{
			break;
		}


	}

	


	cout << endl;
	cout << endl;


	


	int lol2=1;
	while (lol2)
	{
		int x;
		cout << "********* You are in match Class section *********" << endl;
		cout << "If you want to conduct match press 1 " << endl;
		cout << "If you want to Update throughout press 2 " << endl;
		cout << "If you want to See upcoming matches shedule press 3 " << endl;
		cout << "If you want to See recent matches shedule press 4 " << endl;
		cout << "If you want to See and update world records press 5 " << endl;

		cin >> x;
		switch (x)
		{
		case 1:
			o.conduct_match();
			break;
		case 2:
			o.update_team_ranking();
			cout << "After update your display look like this :" << endl;

			break;
		case 3:
			o.display_upcomig_matches();
			break;
		case 4:
			o.display_recent_matches();
			break;
		case 5:
			o.Display_worldREcords();
			break;
		default:
			break;
		}
		cout << "If you want to continue in this class press 1 :" << endl;
		cout << "If you want to exit from this class press any number :" << endl;
		cin >> lol2;
		if (lol2 != 1)
		{
			break;
		}

	}
		
	int lol3=1;
	while (lol3)
	{
		int c;
		cout << "$$$ You are in News class Section $$$" << endl;
		cout << "To hear any news press 1"<<endl;
		cout << "To check rank of any player press 2"<<endl;
		cin >> c;
		if (c == 1)
		{
			N.dis();
		}
		else if (c == 2)
		{
			cout << "For pak press 1 and for ind press 2"<<endl;
			int option;
			cin >> option;
			if (option == 1)
			{
				cout << "Now enter player number :";
				cin >> option;
				cout << obj.returnrank(option);
				cout << endl;
			}
			else if (option == 2)
			{
				cout << "Now enter player number :";
				cin >> option;
				cout << obj2.returnrank(option);
				cout << endl;
			}

			
		}
		else
			exit(0);

		cout << endl;
		cout << "If you want to continue in this class press 1 :" << endl;
		cout << "If you want to exit from this class press any number :" << endl;
		cin >> lol2;
		
		if (lol3 != 1)
		{
			break;
		}
	}
	
}
