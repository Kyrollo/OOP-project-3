#include <iostream>
#include <vector>
#include <string>
using namespace std; 
void traffic_lights(vector<string> extra, int m)
{
	if (m == 0)
	{
		for (int i = 0; i < extra.size(); i++) {
			cout << extra[i];
		}
		cout << endl;
	}
	else
	{
		extra.push_back("  RED  ");
		traffic_lights(extra, m - 1);
		extra.pop_back();
		extra.push_back(" GREEN ");
		traffic_lights(extra, m - 1);
	}
}

void traffic_lights_with_yellow(vector<string> extra, int m)
{
	if (m == 0)
	{
		for (int i = 0; i < extra.size(); i++) {
			cout << extra[i];
		}
		cout << endl;
	}
	else
	{
		extra.push_back("  RED  ");
		traffic_lights_with_yellow(extra, m - 1);
		extra.pop_back();
		extra.push_back(" GREEN ");
		traffic_lights_with_yellow(extra, m - 1);
		extra.pop_back();
		extra.push_back(" Yellow ");
		traffic_lights_with_yellow(extra, m - 1);
	}
}

int main()
{
	vector<string> extra;
	int choice;
	cout << "choose if you want to seee the possible outcomes of the traffic lights with two lights of three lights";
	cout << "for two colours choose 1 for three colours choose 2 : ";
	cin >> choice;
	if (choice == 1)
	{
		traffic_lights(extra, 2);
	}
	else if (choice == 2)
	{
		traffic_lights_with_yellow(extra, 2);
	}
	else {
		cout << "please choose a valid input ";
	}



}
