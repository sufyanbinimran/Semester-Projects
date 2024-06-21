#pragma once
#include<iostream>
using namespace std;

class PLAYER
{
public:
	PLAYER();
	string name1[20];
	int shirt_no[20];
	int average[20];
	string icc_rankig[15];
	int total_runs[20];
	int total_match[20];
	int total_wickets[20];
	int num = 11;

	virtual void add_player(string a, int b, int c, string d, int e, int f, int g) = 0;
	virtual void remove_player() = 0;
	virtual void search_player() = 0;
	virtual void update_player() = 0;
	

	virtual void setname_player1(string a, string b,string c,string d,string e,string f,string g, string h, string i, string j, string k) = 0;
	virtual void setshirt_no1(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) = 0;
	virtual void set_avg1(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)=0;
	virtual void seticc_ranking1(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k) = 0;
	virtual void setruns1(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) = 0;
	virtual void setmatch1(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) = 0;
	virtual void setwickets1(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) = 0;
	virtual void display1() = 0;
 
	virtual void setname_player2(string a, string b,string c,string d,string e,string f,string g, string h, string i, string j, string k) = 0;
	virtual void setshirt_no2(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) = 0;
	virtual void set_avg2(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)=0;
	virtual void seticc_ranking2(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k) = 0;
	virtual void setruns2(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) = 0;
	virtual void setmatch2(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) = 0;
	virtual void setwickets2(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) = 0;

	

}; 
