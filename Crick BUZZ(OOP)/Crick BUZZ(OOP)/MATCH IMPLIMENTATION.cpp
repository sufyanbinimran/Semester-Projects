
//#include"PLAYER HEADER.h"
//#include"TEAM HEADER.h"
#include"MATCH HEADER.h"
#include<iomanip>


void MATCH::update_world_record()
{
	 
	cout << "To update most runs press 1"<<endl;
	cout << "To update most scores press 2"<<endl;
	cout << "To update most sixes press 3"<<endl;
	cout << "To update most fours press 4"<<endl;
	cout << "To update most centuries press 5"<<endl;
	cout << "To update highest batting avg press 6"<<endl;
	cout << "To update best batting strike press 7"<<endl;
	cout << "To update most wickets press 8"<<endl;
	cout << "To update best bowling avg press 9"<<endl;

	cin >> x;
	switch (x)
	{
	case 1:
		cout << "if greater then kohli Enter most runs in t20" << endl;
		cout << "Enter most runs :";
		cin >> mostruns;
		cout << "Most runs after update are :";
		Display_worldREcords();
		break;
	case 2:
		cout << "Enter most scores :";
		cin >> scores;
		cout << "Most scores after update are :"<< endl;
		Display_worldREcords();
		break;
	case 3:
		cout << "Enter most sixes :";
		cin >> six;
		cout << "Most six after update are :" <<endl;
		Display_worldREcords();
		break;
	case 4:
		cout << "Enter most fours :";
		cin >> fours;
		cout << "Most fours after update are :" << endl;
		Display_worldREcords();
		break;
	case 5:
		cout << "Enter most centuries :";
		cin >> most_centuries;
		cout << "Most centuries after update are :" <<  endl;
		Display_worldREcords();
		break;
	case 6:
		cout << "Enter highest batting avg :";
		cin >> highest_avg;
		cout << "highest batting avg after update are :" << endl;
		Display_worldREcords();
		break;
	case 7:
		cout << "Enter best batting strik :";
		cin >> highest_battingstrike;
		cout << "best batting strik after update are :"  << endl;
		Display_worldREcords();
		break;
	case 8:
		cout << "Enter most wickets :";
		cin >> most_wickets;
		cout << "most wickets after update are :" <<  endl;
		Display_worldREcords();
		break;
	case 9:
		cout << "Enter best bowling avg :";
		cin >> best_bowling_avg;
		cout << "best bowling avg after update are :" << endl;
		Display_worldREcords();
		break;

	default:

		cout << " ********** WORLD WIDE RANKING TEAM **********"<<endl;
		cout << "***** Team ranking for Nepal is 1st Worlwide  *****" << endl;
		cout << "***** Team ranking for Pakistan is 2nd Worlwide *****" << endl;
		cout << "***** Team ranking for Bangladesh is 3rd Worlwide *****" << endl;

		cout << "You can decide which team do want to rank  " << endl;
		cout << "1 for Pakistan and 2 for India"<<endl;
		update_team_ranking();


	}
	

	

}
void MATCH::already_match()
{
	
	cout << "Dec 15   ******** England vs Pakistan ********"<<endl;
	cout << "Dec 16   ******** Nepal vs Pakistan ********"<<endl;
	cout << "Dec 17   ******** England vs Honkong ********"<<endl;
	cout << "Dec 18   ******** India vs Pakistan ********"<<endl;
	cout << "Select which one you want to conduct form 1,2,3,4" << endl;
	cin >> u;
	cout << endl;
	switch (u)
	{
	case 1:
		cout << "England won by 5 wickets";
		break;
	case 2:
		cout << "Pakistan won by 9 wickets";
		break;
	case 3:
		cout << "Honkomg won by 3 wickets";
		break;
	case 4:
		cout << "India won by 1 wicket";
		break;
	default:
		break;
	}
	cout << endl;
}
void MATCH::shedule_match()
{
	team1 = "Nepal";
	team2 = "Bangladesh";
	team3 = "Pakistan";
	cout << "Avaialable teams are :"<<endl;
	cout << team1 << endl;
	cout << team2 << endl;
	cout << team3 << endl;

	cout << "Select any 2 teams for match 1 for nepal 2 for bangladesh 3 for pakistan";
	
	cin >> a>> b;
	if (a == 1 && b == 2)
	{
		cout << "You have conducted a match between nepal and bangladesh"<<endl;
		cout << "Set date on which you want to shedule match";
		cin >> date;
		cout << "Enter venue :";
		cin >> venue;
		cout << "Enter match type like ODI,T20 ,Test etc";
		cin >> match_type;
		cout << "Enter commentatros ";
		cin >> commentators;
		cout << "Enter empire names :";
		cin >> umpires;
		cout << "Enter match status (upcoming,recent)";
		cin >> match_status;
		cout << endl;

		cout << date << "   " << venue << "   " << match_type << "   " << commentators << "   " << umpires << "   " << umpires << "   " << match_status<<endl;
		cout << endl;

		
		
	}
			
	else if (a == 1 && b== 3)
	{
		cout << "You have conducted a match between nepal and pakistan";
		cout << "Set date on which you want to shedule match";
		cin >> date;
		cout << "Enter venue :";
		cin >> venue;
		cout << "Enter match type like ODI,T20 ,Test etc";
		cin >> match_type;
		cout << "Enter commentatros ";
		cin >> commentators;
		cout << "Enter empire names :";
		cin >> umpires;
		cout << "Enter match status (upcoming,recent)";
		cin >> match_status;
		cout << endl;

		cout << date << "   " << venue << "   " << match_type << "   " << commentators << "   " << umpires << "   " << umpires << "   " << match_status << endl;

		cout << "****** These are the world recores that are set by deafualt ******" << endl;
		mostruns = 4001;
		cout << "Most runs in t20 is of Virat kohli " << endl;
		cout << mostruns << endl;

		scores = 278;
		cout << "Most scores in T20 are " << endl;
		cout << scores << endl;

		six = 463;
		cout << "Most sixes are:";
		cout << six << endl;

		fours = 360;
		cout << "Most fours in t20 are " << endl;
		cout << fours << endl;

		most_centuries = 4;
		cout << "Most centuries in t20 are " << endl;
		cout << most_centuries << endl;

		highest_avg = 52.74;
		cout << "Highest batting average is " << endl;
		cout << highest_avg << endl;

		highest_battingstrike = 180;
		cout << "Highest batting strike is " << endl;
		cout << highest_battingstrike << endl;

		most_wickets = 134;
		cout << "Most wickets in t20 are " << endl;
		cout << most_wickets << endl;

		best_bowling_avg = 12.29;
		cout << "Best bowling average is " << endl;
		cout << best_bowling_avg << endl;


		cout << "If you want to update world records  press 1 ";
		cin >> alpha;
		if (alpha == 1)
		{
			update_world_record();
		}
		else
		{
			exit;
		}



	}
	else if (a == 2 && b == 3)
	{
		cout << "You have conducted a match between bangladesh and pakistan";
		cout << "Set date on which you want to shedule match";
		cin >> date;
		cout << "Enter venue :";
		cin >> venue;
		cout << "Enter match type like ODI,T20 ,Test etc";
		cin >> match_type;
		cout << "Enter commentatros ";
		cin >> commentators;
		cout << "Enter empire names :";
		cin >> umpires;
		cout << "Enter match status (upcoming,recent)";
		cin >> match_status;
		cout << endl;

		cout << date << "   " << venue << "   " << match_type << "   " << commentators << "   " << umpires << "   " << umpires << "   " << match_status << endl;

		cout << "****** These are the world recores that are set by deafualt ******" << endl;
		mostruns = 4001;
		cout << "Most runs in t20 is of Virat kohli " << endl;
		cout << mostruns << endl;

		scores = 278;
		cout << "Most scores in T20 are " << endl;
		cout << scores << endl;

		six = 463;
		cout << "Most sixes are:";
		cout << six << endl;

		fours = 360;
		cout << "Most fours in t20 are " << endl;
		cout << fours << endl;

		most_centuries = 4;
		cout << "Most centuries in t20 are " << endl;
		cout << most_centuries << endl;

		highest_avg = 52.74;
		cout << "Highest batting average is " << endl;
		cout << highest_avg << endl;

		highest_battingstrike = 180;
		cout << "Highest batting strike is " << endl;
		cout << highest_battingstrike << endl;

		most_wickets = 134;
		cout << "Most wickets in t20 are " << endl;
		cout << most_wickets << endl;

		best_bowling_avg = 12.29;
		cout << "Best bowling average is " << endl;
		cout << best_bowling_avg << endl;


		cout << "If you want to update world records  press 1 ";
		cin >> alpha;
		if (alpha == 1)
		{
			update_world_record();
		}
		else
		{
			exit;
		}


	}


}
void MATCH::update_team_ranking()
{

	cout << "Press 1 if you want to update in Pakistan team (Throughout )"<<endl;
	cout << "Press 2 if you want to update in Indian team (Throughout )"<<endl;
	cin >> choice;
	ofstream out;
	ifstream in;
	out.open("sufyan.txt", ios::app);

	if (choice == 1)
	{
		cout << "Update icc_ranking of team Pakistan " << endl;
		for (int i = 0; i < 11; i++)
		{
			cout << "Enter for player " << i << endl;


			cout << "Enter name :"; cin >> name1[i];
			
			cout << "Enter Shirt number :"; cin >> shirt_no[i];
			
			cout << "Enter average :"; cin >> average[i];
			
			cout << "Enter Icc ranking "; cin >> icc_rankig[i];
			
			cout << "Enter total runs :"; cin >> total_runs[i];
			
			cout << "Enter total matches :"; cin >> total_match[i];
			
			cout << "Enter total wickets :"; cin >> total_wickets[i];
			
			

			out << name1[i] << setw(5);
			out << shirt_no[i] << setw(5);
			out << average[i] << setw(5);
			out << icc_rankig[i] << setw(5);
			out << total_runs[i] << setw(5);
			out << total_match[i] << setw(5);
			out << total_wickets[i] << setw(5);
			out << endl;

			ifstream in("sufyan.txt");
			if (in.is_open())  
			in >> shirt_no[i];
			in >> average[i] ;
			in >> icc_rankig[i] ;
			in >> total_runs[i] ;
			in >> total_match[i] ;
			in >> total_wickets[i] ;

			cout << name1[i] << setw(5);
			cout << shirt_no[i] << setw(5);
			cout << average[i] << setw(5);
			cout << icc_rankig[i] << setw(5);
			cout << total_runs[i] << setw(5);
			cout << total_match[i] << setw(5);
			cout << total_wickets[i] << setw(5);
			cout << endl;


		}

	}
	else if (choice == 2)
	{
		cout << "Update icc_ranking of team India " << endl;
		for (int i = 0; i < 11; i++)
		{
			cout << "Enter for player " << i << endl;


			cout << "Enter name :"; cin >> name1[i];
			cout << "Enter Shirt number :"; cin >> shirt_no[i];
			cout << "Enter average :"; cin >> average[i];
			cout << "Enter Icc ranking "; cin >> icc_rankig[i];
			cout << "Enter total runs :"; cin >> total_runs[i];
			cout << "Enter total matches :"; cin >> total_match[i];
			cout << "Enter total wickets :"; cin >> total_wickets[i];
		}
	}
	

	
}
void MATCH::display_upcomig_matches()
{
	cout << "England tour of Pakistan, 2022"<<endl;
	cout << "Sep 20 - Dec 21" << endl;
		cout << "December 2022" << endl;
		cout << "India tour of Bangladesh, 2022" << endl;
		cout << "Dec 04 - Dec 26" << endl;
		cout << " South Africa tour of Australia, 2022 - 23" << endl;
		cout << "Dec 09 - Jan 17" << endl;
		cout << "East Africa T20I Series 2022" << endl;
		cout << "Dec 13 - Dec 23" << endl;
		cout << "Malaysia Quadrangular Series 2022 - 23" << endl;
		cout << "Dec 15 - Dec 23" << endl;
}
void MATCH::display_recent_matches()
{
	cout << " Australia v West Indies"<<endl;
	cout << "Bangladesh v India" << endl;
	cout << "Pakistan v England" << endl;
	cout << "West Indies v England(W)" << endl;
	cout << " New Zealand v Bangladesh(W)" << endl;
	cout << "India v Australia(W)" << endl;
	cout << "Australia v South Africa" << endl;
	cout << " Pakistan v New Zealand" << endl;
}
void MATCH::Display_worldREcords()
{
	cout << "****** These are the world recores that are set by deafualt ******" << endl;
	
	cout << "Most runs in t20 is of Virat kohli :";
	cout << mostruns << endl;

	
	cout << "Most scores in T20 are : ";
	cout << scores << endl;

	
	cout << "Most sixes are:";
	cout << six << endl;

	
	cout << "Most fours in t20 are : " ;
	cout << fours << endl;

	
	cout << "Most centuries in t20 are :" ;
	cout << most_centuries << endl;

	
	cout << "Highest batting average is :";
	cout << highest_avg << endl;

	
	cout << "Highest batting strike is :";
	cout << highest_battingstrike << endl;

	
	cout << "Most wickets in t20 are : ";
	cout << most_wickets << endl;

	
	cout << "Best bowling average is : ";
	cout << best_bowling_avg << endl;
	cout << endl;


	cout << "If you want to update world records  press 1 ";
	cin >> alpha;
	if (alpha == 1)
	{
		update_world_record();
	}
	else
	{
		exit(0);

	}
	
}
void MATCH::conduct_match()
{
	cout << endl;
	cout << "If you want to impliment already conduct match press 1 or want to shedule match press 2:";	
	cin >> beta;;
	if (beta == 1)
	{
		already_match();
	}
	else if (beta== 2)
	{
		shedule_match();
	}
}
