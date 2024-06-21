#pragma once
#include"TEAM header.h"
#include"NEWS.h";
#include<fstream>
using namespace std;

class MATCH:public TEAM {
public:
	string team1;
	string team2;
	string team3;
	string date;
	string venue;
	string match_type;
	string tournament_name;
	string commentators;
	string umpires;
	string match_status;
	int mostruns=4001;
	int scores = 278;;
	int six = 463;
	int fours = 360;
	int most_centuries = 4;
	int highest_avg = 52.74;
	int highest_battingstrike = 180;
	int most_wickets = 134;
	int best_bowling_avg = 12.29;
	int x;
	int u;
	int a, b;
	int alpha;
	int beta;
	int winner;
	int num;
	int choice;


	void conduct_match();
	void already_match();
	void shedule_match();
	void Display_worldREcords();
	void update_world_record();
	void update_team_ranking();
	//void update_player_ranking();
	void display_upcomig_matches();
	void display_recent_matches();


};

