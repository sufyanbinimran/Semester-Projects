#include"n.h"

void n::dis()
{
	cout << endl;
	cout << "To display upcoming matches press 1 "<<endl;
	cout << "To display recent matches press 2"<<endl;
	cin >> num1;
	if (num1 == 1)
	{
		display_upcomig_matches();
	}
	else if (num1 == 2)
	{
		display_recent_matches();
	}
}
void n::ranking()
{
	cout << "*** You are in search ranking section ***" << endl;
	{
		cout << "For pakistan press 2 and for india press 3" << endl;
		cin >> pop;
		if (pop == 2)
		{
			TEAM obj;

			cout<<obj.returnrank(1);
		}

	}
}