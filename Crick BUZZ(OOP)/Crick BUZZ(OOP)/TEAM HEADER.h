#pragma once
#include<iostream>
using namespace std;
#include"PLAYER HEADER.h"
class TEAM :public PLAYER
{
public:

	string team_name[2];
	string ICC_ranking[2];
	int no_of_players[2];
	int total_match_won[2];
	int total_match_lost[2];
	string team_captan[2];
	string coach[2];
	string admin_username;
	string admin_password;
	int num=11;
	string returnrank(int num);


	void add_player(string a, int b, int c, string d, int e, int f, int g);
	void remove_player();
	void search_player();
	void update_player();
	void display_matches();
	void DISPAYT();
	void setpassword();
	void update_captain();
	void update_coach();
	void display_team();

	void setname_player1(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k);	
    void setshirt_no1(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) ;
    void set_avg1(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
	void seticc_ranking1(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k);
	void setruns1(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) ;
	void setmatch1(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) ;
	void setwickets1(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) ;
	void display1();
	
	void setname_player2(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k);
	void setshirt_no2(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
	void set_avg2(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
	void seticc_ranking2(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k);
	void setruns2(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
	void setmatch2(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
	void setwickets2(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
	

};


