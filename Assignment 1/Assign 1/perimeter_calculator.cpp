/*ID block  ----------------------------+
+ Programmer : Jason Rubalcaba     +
+ Course: CSCI 1                   +
+ Assignment : 1                   +
+ Due Date   : September 18, 2007   +
+------------------------------------------
//              Program statement
//  The purpose of this program is to calculate the area and perimeter of a rectangle given by a student
******************Analysis****************************
1.Data Needed
	First and last name of the user
	Legnth of the rectangle
	Width of the rectangle
2.Constants Given
	None
3.Calculations
	Assumptions: The length and width given will be positive real nubers
		Calculate Perimeter
		Calculate Area
************************ Algorithm ***************************************************************	
Step 1
	Input
		Prompt User for first name (string)
		Prompt User for last name (string)
		Prompt User for width of the rectangle (float)
		Prompt User for the length of the rectangle (float)
Step 2
	Process
		Area = width * length 
		Perimeter = 2*(lenth+width)
Step 3
	Output
		Print first and last name labeled as user name on line 1
		Print the word Area followed by it’s calculation on line 2
		Print the word Perimeter followed by it’s calculation on line 3 */
/************************ End of Algorithm *********************************************************/
/************ Code segment ******************************************/
#include <iostream>
#include <string>
using namespace std;
void main()
{
	float Length, Width, Perimeter, Area;
	string First, Last;

	cout << "Enter your First name:\n   ";
	cin >> First;
	cout << "Enter your Last name:\n   ";
	cin >> Last;
	cout << "Enter the Length:\n   ";
	cin >> Length;
	cout << "Enter the Width:\n   ";
	cin >> Width;

	Area = Width * Length;
	Perimeter = 2 * (Length + Width);

	cout << "Name:\t\t" + First + " " + Last + "\n";
	cout << "Perimeter:\t" << Perimeter << "\n";
	cout << "Area:\t\t" << Area << "\n";
}
