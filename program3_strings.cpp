
/*****************************************************
 *Assignment Description:                            *
 *A program that takes in a string for (2) cases.    *
 *Case (1) determines if the input is a palindrome.  *
 *Case (2) modifies the input to create a new string.*
 *****************************************************/   


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;


//function prototypes

/******************************************************************************************************
 * Function Name: palindrome
 * 
 * Precondition: Takes in one parameter of type string
 * 
 * Postcondition: Prints out if input parameter is a palindrome
 * 
 * Description: Takes the input string and determines if it meets the requirements to be a palindrome
 * 
 * ****************************************************************************************************/
bool palindrome(const string &s);


/******************************************************************************************************
 * Function Name: replace_all
 * 
 * Precondition: Takes in three parameter(s), all of type string
 * 
 * Postcondition: Occurrences of old_string are replaced by new_string in original_string 
 * 
 * Description: Uses the find function of strings to find and replace old substring with new substring
 * 
 * ****************************************************************************************************/
string replace_all(const string & original_string, const string & old_substring, const string & new_substring);



int main(int argc, char **argv)
{
	string string1, string2, string3, string4, modified;
	
	while(true)
	{
		int selection;
		cout<<"**************************************"<<endl;
		cout<<"*Please select from the given options*"<<endl;
		cout<<"**************************************"<<endl;
		cout<<"* (1)-  Palindrome Option            *"<<endl;
		cout<<"* (2)-  String Replacement Option    *"<<endl;
		cout<<"* (-1)- Exit                         *"<<endl;
		cout<<"**************************************"<<endl;
		cout<<"Enter Selection> ";
		cin>>selection;
		cin.ignore();
		cout<<endl;
	
		if (selection ==1)
			{ 
				cout<<"Enter a string: ";
				getline(cin, string1);
				cout<<endl;
				cout<<"The string entered is : "<<string1<<endl;
	
				if(palindrome(string1))
					cout<< "\nThe string is a palindrome.\n"<<endl;
				else 
					cout<<"\nThe string is not a palindrome.\n"<<endl;
			}		
		else if (selection ==2) 
			{
				cout<<"Enter the original string: ";
				cout<<endl;
		
				getline(cin, string4);
				cout<<"The original string is: "<<string4<<endl;
				
				cout<<"\nEnter the old substring: ";
				cout<<endl;
				getline(cin, string2);
				cout<<"The old substring is: "<<string2<<endl;
				
				cout<<"Enter the new substring: ";
				cout<<endl;
				getline(cin, string3);
				cout<<"\nThe new substring is: "<<string3<<endl;
				string modified=replace_all(string4, string2, string3);
				
				cout<<"\nThe modified string is: "<<modified<<endl;
			}
		else if (selection == -1)
			{
				cout<<"Exiting Program!"<<endl;
				break;
			}
		else
			{
				cout<<"Invalid Choice."<<endl;
			}
	}
	
	return 0;
}


//function definitions
bool palindrome(const string &s)
{
	int length = s.length();
	for (int i=0; i<length /2; i++)
	{
		if(s[i] != s[length-i-1])
			return false;
	}
	return true;
}

string replace_all(const string & original_string, const string & old_substring, const string & new_substring)
{
	string s=original_string;
	int old_length=old_substring.length();
	while(s.find(old_substring) != string::npos)
	{
		int i=s.find(old_substring);
		s.replace(i, old_length, new_substring);
	}
	return s;
}

