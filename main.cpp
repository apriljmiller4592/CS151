/**
Author: April J Miller
Lab 8 Project #1 (palindrome)
Checks to see if a word is a palindrome
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <bits/stdc++.h> 

using namespace std;

//function prototype
bool isPalindrome(string test_string);

int main() 
{	
	//Test cases
	string test[] = {"Chic", "Book", "Kayak", "Don't nod", "12345", "25 ABC 9cba52", "Not even close.", "Campus motto: Bottoms up, Mac!", 
			"A man, a plan, a canal -- Panama"};
			
	for(int i = 0; i < sizeof(test)/sizeof(test[0]); i++)
	{
		isPalindrome(test[i]);
	}
	system("pause");
	return 0;
}

//Takes given string returns true if the string is a palindrome, false if not
bool isPalindrome(string test_string)
{
	bool result;
	string temp = "";
	
	// converts string to lowercase
	for_each(test_string.begin(), test_string.end(), [](char &c) 
	{ 
		c = tolower(c) ; 
	}); 
    
    //loop through the string
    for (int i = 0; i < test_string.length(); i++)
    {
    	if (test_string[i] < '0' || 
		   (test_string[i] > '9' && test_string[i] < 'a') || 
		    test_string[i] > 'z')
    	{
    		continue;	
		}
    	else
    	{
    		temp += test_string[i]; 
    	}
	}
    
    string reverse_test = temp;
    
    //Reversing string
    int n = temp.length();
	for (int i = 0 ; i < n / 2 ; i++) 
	{  
	    swap(reverse_test[i], reverse_test[n - i - 1]);
  	}
	
	result = temp.compare(reverse_test);
	
	//Output the results
	if (result == 0)
	{
		cout << "Testing: \"" << test_string << "\"" << " ---> is a palindrome!" << endl;
	}
	else
	{
		cout << "Testing: \"" << test_string << "\"" << " ---> is NOT a palindrome!" << endl;
	}	
    return result;
}
