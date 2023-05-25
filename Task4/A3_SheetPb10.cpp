#include <bits/stdc++.h>
using namespace std;
void date_converter(string numdate)
{
    string arr[12]{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string month = " ", day = " ";
    int intmonth, intday;
    for (int i = 0; i < numdate.length(); i++)
    {
        month += numdate[i];
        if (numdate[i] == '/')
        {
            intmonth = stoi(month);
            day = numdate.substr(i + 1);
            intday = stoi(day);
            break;
        }
    }
    
    if (intmonth > 12 || intmonth < 1 || intday > 31)
    {
        throw "invalid day or month.. ";
    }
  
    else if ((intmonth == 4 || intmonth == 6 || intmonth == 9 || intmonth == 11) && intday > 30)
    {
        throw "days can not be more than 30.. ";
    }
  
    else if ((intmonth == 2) && intday > 29)
    {
        throw "days can not be more than 29 ";
    }

    else cout << arr[intmonth-1] << " " << intday << endl;
}

int main()
{
    string string_date;
    cin>>string_date;
    try
    {
        date_converter(string_date);
    }
    catch (const char* txtexebtion)
    {
        cout << "Exeption error: "<<txtexebtion;
    }
}