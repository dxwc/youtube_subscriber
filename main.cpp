#include <iostream>
#include "yt_functions.h"

using std::cout;
using std::string;

int main(int numOfCommand, char * commandArr[ ])
{
	const string help =
		"# To subscribe:"
		"\n\t./run -sub <a youtube video watch or channel url>"
		"\n# To show list of subscribed channel name and id:"
		"\n\t./run -list"
		"\n# To generate html (on the same directory):"
		"\n\t./run -gen"
		"\n# To generate html and view in firefox:"
		"\n\t./run -gen -view"
		"\n# To view previously generated html:"
		"\n\t./run -view"
		"\n# Tip: use alias for common uses\n";

	if(numOfCommand <= 1 || numOfCommand > 3)
	{
		cout << help;
		return 0;
	}

	string a_command;

	yt_functions yt;
	a_command = commandArr[1];

	if    (a_command == "-view")
	{
		yt.view_html();
	}
	else if(a_command == "-gen")
	{
		yt.generate_html();
		if(numOfCommand == 3)
		{
			a_command = commandArr[2];

			if(a_command == "-view")
			{
				yt.view_html();
			}
			else
			{
				cout << help;
			}
		}

	}
	else if(a_command == "-sub")
	{
		if(numOfCommand == 3)
		{
			a_command = commandArr[2];
			yt.subscribe(a_command);
		}
		else
		{
			cout << help;
		}
	}
	else if(a_command == "-list")
	{
		yt.sub_list();
	}
	else
	{
		cout << help;
	}


	return 0;
}

