#include"TEAM HEADER.h"
//#include"PLAYER HEADER.h"
#include <iomanip>


void TEAM::setname_player1(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k)
{
	
	this->name1[0] = a;
	this->name1[1] = b;
	this->name1[2] = c;
	this->name1[3] = d;
	this->name1[4] = e;
	this->name1[5] = f;
	this->name1[6] = g;
	this->name1[7] = h;
	this->name1[8] = i;
	this->name1[9] = j;
	this->name1[10] = k;
	
}
void TEAM::setshirt_no1(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
	this->shirt_no[0] = a;
	this->shirt_no[1] = b;
	this->shirt_no[2] = c;
	this->shirt_no[3] = d;
	this->shirt_no[4] = e;
	this->shirt_no[5] = f;
	this->shirt_no[6] = g;
	this->shirt_no[7] = h;
	this->shirt_no[8] = i;
	this->shirt_no[9] = j;
	this->shirt_no[10] = k;

}
void TEAM::set_avg1(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
	this->average[0] = a;
	this->average[1] = b;
	this->average[2] = c;
	this->average[3] = d;
	this->average[4] = e;
	this->average[5] = f;
	this->average[6] = g;
	this->average[7] = h;
	this->average[8] = i;
	this->average[9] = j;
	this->average[10] = k;
}
void TEAM::seticc_ranking1(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k)
{
	this->icc_rankig[0] = a;
	this->icc_rankig[1] = b;
	this->icc_rankig[2] = c;
	this->icc_rankig[3] = d;
	this->icc_rankig[4] = e;
	this->icc_rankig[5] = f;
	this->icc_rankig[6] = g;
	this->icc_rankig[7] = h;
	this->icc_rankig[8] = i;
	this->icc_rankig[9] = j;
	this->icc_rankig[10] = k;

}
void TEAM::setruns1(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
	this->total_runs[0] = a;
	this->total_runs[1] = b;
	this->total_runs[2] = c;
	this->total_runs[3] = d;
	this->total_runs[4] = e;
	this->total_runs[5] = f;
	this->total_runs[6] = g;
	this->total_runs[7] = h;
	this->total_runs[8] = i;
	this->total_runs[9] = j;
	this->total_runs[10] = k;
}
void TEAM::setmatch1(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
	this->total_match[0] = a;
	this->total_match[1] = b;
	this->total_match[2] = c;
	this->total_match[3] = d;
	this->total_match[4] = e;
	this->total_match[5] = f;
	this->total_match[6] = g;
	this->total_match[7] = h;
	this->total_match[8] = i;
	this->total_match[9] = j;
	this->total_match[10] = k;
}
void TEAM::setwickets1(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
	this->total_wickets[0] = a;
	this->total_wickets[1] = b;
	this->total_wickets[2] = c;
	this->total_wickets[3] = d;
	this->total_wickets[4] = e;
	this->total_wickets[5] = f;
	this->total_wickets[6] = g;
	this->total_wickets[7] = h;
	this->total_wickets[8] = i;
	this->total_wickets[9] = j;
	this->total_wickets[10] = k;
}

void TEAM::setname_player2(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k)
{
	
	this->name1[0] = a;
	this->name1[1] = b;
	this->name1[2] = c;
	this->name1[3] = d;
	this->name1[4] = e;
	this->name1[5] = f;
	this->name1[6] = g;
	this->name1[7] = h;
	this->name1[8] = i;
	this->name1[9] = j;
	this->name1[10] = k;
	
}
void TEAM::setshirt_no2(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
	this->shirt_no[0] = a;
	this->shirt_no[1] = b;
	this->shirt_no[2] = c;
	this->shirt_no[3] = d;
	this->shirt_no[4] = e;
	this->shirt_no[5] = f;
	this->shirt_no[6] = g;
	this->shirt_no[7] = h;
	this->shirt_no[8] = i;
	this->shirt_no[9] = j;
	this->shirt_no[10] = k;

}
void TEAM::set_avg2(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
	this->average[0] = a;
	this->average[1] = b;
	this->average[2] = c;
	this->average[3] = d;
	this->average[4] = e;
	this->average[5] = f;
	this->average[6] = g;
	this->average[7] = h;
	this->average[8] = i;
	this->average[9] = j;
	this->average[10] = k;
}
string TEAM::returnrank(int num)
{
	return icc_rankig[num];
}
void TEAM::seticc_ranking2(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k)
{

	this->icc_rankig[0] = a;
	this->icc_rankig[1] = b;
	this->icc_rankig[2] = c;
	this->icc_rankig[3] = d;
	this->icc_rankig[4] = e;
	this->icc_rankig[5] = f;
	this->icc_rankig[6] = g;
	this->icc_rankig[7] = h;
	this->icc_rankig[8] = i;
	this->icc_rankig[9] = j;
	this->icc_rankig[10] = k;

}
void TEAM::setruns2(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
	this->total_runs[0] = a;
	this->total_runs[1] = b;
	this->total_runs[2] = c;
	this->total_runs[3] = d;
	this->total_runs[4] = e;
	this->total_runs[5] = f;
	this->total_runs[6] = g;
	this->total_runs[7] = h;
	this->total_runs[8] = i;
	this->total_runs[9] = j;
	this->total_runs[10] = k;
}
void TEAM::setmatch2(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
	this->total_match[0] = a;
	this->total_match[1] = b;
	this->total_match[2] = c;
	this->total_match[3] = d;
	this->total_match[4] = e;
	this->total_match[5] = f;
	this->total_match[6] = g;
	this->total_match[7] = h;
	this->total_match[8] = i;
	this->total_match[9] = j;
	this->total_match[10] = k;
}
void TEAM::setwickets2(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
	this->total_wickets[0] = a;
	this->total_wickets[1] = b;
	this->total_wickets[2] = c;
	this->total_wickets[3] = d;
	this->total_wickets[4] = e;
	this->total_wickets[5] = f;
	this->total_wickets[6] = g;
	this->total_wickets[7] = h;
	this->total_wickets[8] = i;
	this->total_wickets[9] = j;
	this->total_wickets[10] = k;
}
void TEAM::add_player(string a, int b, int c, string d, int e, int f, int g)
{

	

		this->name1[num] = a;
		this->shirt_no[num] = b;
		this->average[num] = c;
		this->icc_rankig[num] = d;
		this->total_runs[num] = e;
		this->total_match[num] = f;
		this->total_wickets[num] = g;
		
		
		num++;
		
		
}

void TEAM::remove_player()
{
	display1();
	cout << "Which player you want to remove ";
	int x=0;
	cin >> x;
	for (int i = x; i < num-1; i++)
	{
		
		name1[i]=name1[i+1];
		shirt_no[i] = shirt_no[i + 1];
		average[i]= average[i+1];
		icc_rankig[i]=icc_rankig[i+1];
		total_runs[i]=total_runs[i+1];
		total_match[i]=total_match[i+1];
		total_wickets[i]=total_wickets[i+1];
		
	}
	num--;
	display1();
}
void TEAM::search_player()
{
	int x;
	cout << "Which player you want to search ";
	cin >> x;
	switch (x)
	{
	default:
		cout << name1[x] << setw(10) << shirt_no[x] << setw(10) << average[x] << setw(10) << icc_rankig[x] << setw(10) << total_runs[x] << setw(10) << total_match[x] << setw(10) << total_wickets[x] << endl;

	}
}
void TEAM::update_player()
{
	int x;
	cout << "Which player you want to update ";
	cin >> x;
	switch (x)
	{
	default:
		cin >> name1[x];
		cin >> shirt_no[x];
		cin >> average[x]; 
		cin >> icc_rankig[x];
		cin >> total_runs[x];
	    cin >> total_match[x]; 
		cin >> total_wickets[x] ;
		 
		cout << name1[x] << setw(10) << shirt_no[x] << setw(10) << average[x] << setw(10) << icc_rankig[x] << setw(10) << total_runs[x] << setw(10) << total_match[x] << setw(10) << total_wickets[x] << endl;
		
	}
	
}
void TEAM::display_team()
{
	this->team_name[0] = "Pakistan ";
	this->team_name[1] = "India";
	this->ICC_ranking[0] = "1st Rank";
	this->ICC_ranking[1] = "3rd Rank";
	this->no_of_players[0] = 11;
	this->no_of_players[1] = 11;
	this->total_match_won[0] = 56;
	this->total_match_won[1] = 46;
	this->team_captan[0] = "Afridi";
	this->team_captan[1] = "Sachin";
	this->coach[0] = "Boom Boom";
	this->coach[1] = "MS Dhoni";

	
}
void TEAM::DISPAYT()
{
	cout << "****** Pakistani team data ******"<<endl;
	cout<<"Team name is :"<<this->team_name[0] << endl;
	cout<<"ICC ranking of team is :"<<this->ICC_ranking[0] << endl;
	cout<<"Number of players :"<< this->no_of_players[0] << endl;
	cout<<"Total matches won :"<< this->total_match_won[0] << endl;
	cout<<"Team captan :"<< this->team_captan[0] << endl;
	cout<<"Team coach :"<< this->coach[0] << endl;

	cout << endl;
	cout << "****** Indian team data ******"<<endl;
	cout<<"Team name is :"<<this->team_name[1] << endl;
	cout<<"ICC ranking of team is :"<<this->ICC_ranking[1] << endl;
	cout<<"Number of players :"<< this->no_of_players[1] << endl;
	cout<<"Total matches won :"<< this->total_match_won[1] << endl;
	cout<<"Team captan :"<< this->team_captan[1] << endl;
	cout<<"Team coach :"<< this->coach[1] << endl;

}
void TEAM::setpassword()
{
	cout << "                                   ";
	cout << "                                   ";
	cout << "                                   ";
	cout << "                                   ";
	cout << "                                   ";
	cout << "                                   ";
	cout << "                                   "<<endl;
	cout << "               * Enter username :";
	cin >> admin_username;
	cout << "               * Enter Password :";
	cin >> admin_password;
	if (admin_password == "1234")
	{
		cout << "Successfully login to CRICK BUZZ";
	}
	else
	{
		cout << "Wrong password Login failed";
		exit(0);
	}
}
void TEAM::display_matches()
{
	int x;
	cout << "If you want to see Schedule of pakistani team matches press 1 else for india press 2:";
	cin >> x;
	if (x == 1)
	{
		cout << "****** Pakistan shedule section ****** "<<endl;
		cout << "**** Past matches ****"<<endl;
		cout << " September 2022 :: England Vs Pakistan "<<endl;
		cout << "  October 2022 :: Bangladesh Vs Pakistan" << endl;
		
		cout << "**** Future matches ****"<<endl;
		cout << " December 2022 :: India Vs Pakistan "<<endl;
		cout << " January 2023 :: Ireland Vs Pakistan" << endl;

	}
	if (x == 2)
	{
		cout << "****** Indian shedule section ******"<<endl;
		cout << "**** Past matches ****"<<endl;
		cout << " September 2022 :: England Vs India "<<endl;
		cout << "  October 2022 :: Bangladesh Vs India" << endl;
		
		cout << "**** Future matches ****"<<endl;
		cout << " December 2022 :: India Vs India "<<endl;
		cout << " January 2023 :: Ireland Vs India" << endl;

	}
	else
	{
		exit;
	}
}
void TEAM::update_captain()
{
	int x;
	cout << "Enter which team captan you want to update 1 for pak 2 for ind:";
	cin >> x;
	switch (x)
	{
	case 1:
		cout << "Pakistani team captan section";
		cout << "Before update captan name is :" << endl; DISPAYT();
		cout << endl;
		cout << "Enter new captan name :";
		cin >> this->team_captan[0];
		DISPAYT();
		break;
	case 2:
		cout << "India team captan section";
		cout << "Before update captan name is :" << endl; DISPAYT();
		cout << endl;
		cout << "Enter new captan name :";
		cin >> this->team_captan[1];
		DISPAYT();
	
	}
	
}
void TEAM::update_coach()
{
	int x;
	cout << "Enter which team coach you want to update 1 for pak 2 for ind:";
	cin >> x;
	switch (x)
	{
	case 1:
		cout << "Pakistani team coach section";
		cout << "Before update coach name is :" << endl; DISPAYT();
		cout << endl;
		cout << "Enter new coach name :";
		cin >> this->coach[0];
		DISPAYT();
		break;
	case 2:
		cout << "India team coach section"<<endl;
		cout << "Before update coach name is :"<<endl; DISPAYT();
		cout << endl;
		cout << "Enter new coach name :";
		cin >> this->coach[1];
		DISPAYT();
	}
}

void TEAM::display1()
{
	cout << endl;
	cout << "Names " << setw(10) << "Shirt " << setw(10) << "scores" << setw(9) << "ranking" << setw(6) << "runs" << setw(10) << "matches" << setw(10) << " wickets" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << name1[i] << setw(10) << shirt_no[i] << setw(10) << average[i] << setw(10) << icc_rankig[i] << setw(10) << total_runs[i] << setw(10) << total_match[i] << setw(10) << total_wickets[i] << endl;
	}

	cout << endl;

}

