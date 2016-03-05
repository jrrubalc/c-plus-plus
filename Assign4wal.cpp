/*ID block  ----------------------------+
+ Programmer : Jason Rubalcaba     +
+ Course: CSCI 1                   +
+ Assignment : 4                   +
+ Due Date   : Oct 22, 2007   +
+------------------------------------------

              Program statment 
This program will genreate a tables of tangents for angles in a user defined range  
  
******************Analysis****************************
1.Data Needed
	Starting Angle
	Ending Angle
2.Constants Given
	Pi = 3.14159
3.Calculations
	Assumptions: Angles must first be converted to radians
	Angles will be rounded to one decimal place
	Tangent function
		Tan = tan(minimum*(3.14159/180.00))

************************ Algorithm ***************************************************************	
Declare Variables
	Use the type double for minimum, maximum, tan, start, finish, and i.  
Loop 
	Prompt user for minimum and maximum values for the left of the table
	Input the minimum and maximum values for the table
	Round the number to one decimal place by the following method
		Start = floor (10.0*minimum+.5)
		minimum = Start/10.0;
		Finish = floor (10.0*maximum+.5)
		maximum = Finish/10.0
	(The start and finish values will be used as the start and stop of the next loop)
	If the minimum < maximum, maximum < 90 and minimum > = 0 then create 
		The “Table of Tangents”
				Output 0 1 2 3 4 5 6 7 8 9 to label the hundredth place decimal
				Output --------------------- as a separator 
		Loop (as long as start < = finish, add 1 to start) 
			Output Minimum to one decimal place
			Output a | to separate it form the tangents
			Loop for 10 times
				Tan = tan(minimum*(3.14159/180.00))
				If the Tan > 0.0 and Tan < = 1 then set
					Set Percision to four
						Ouput Tan
				Else 
					Set percision to five
						Ouput Tan
				Add .01 to minimum
			End loop
				Move to next line
		End Loop
	Else 
		Output “The table generation has been halted.”
		Use break to end the loop.
End of Loop

/************************ End of Algorithm *********************************************************/
/************ Code segment ******************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void main()
{
	double minimum, maximum, Tan, Start,Finish;
	const double pi = 3.14159;
	cout << "Jason Rubalcaba - Computer Science 1 - Program 4\n\n";
	cout << "This program will generate tables of tangents.\nEnter a number >=90 or < 0 or numbers in wrong order,to terminate\n";
	cout << "\n\n***\t***\t***\t***\t***\t***\t***\t***\t***\t***\n\n";
	for( ; ; )
	{
		cout<<"Minimum and maximum values for the left column of the table:\t";
		cin>> minimum>> maximum;	

		Start = floor (10.0*minimum+.5);
		minimum = Start/10.0;
		Finish = floor (10.0*maximum+.5);
		maximum = Finish/10.0;
		
		if ( minimum < maximum && maximum < 90 && minimum >=0 )
		{

			cout<<"\n\n"<<right<<setw(51)<<"Partial Table of Tangents\n\n";
			cout<< "          0      1      2      3      4      5      6      7      8      9\n";
			cout<< "-----------------------------------------------------------------------------\n";
			for(Start,Finish ; Start<=Finish ; Start++)
			{
				cout<< left << fixed << setw(4) << setprecision(1) << showpoint <<minimum<<" | ";
			for(int i=0 ; i<10 ; i++)
			{
				Tan = tan(minimum*(pi/180.00));
				if (Tan>=0.0&&Tan<=1)
				cout << setprecision(4) << setw(6) << Tan << " ";
				else
				{
					cout.unsetf(ios::fixed);
					cout << setprecision(5)<< setw(6) << Tan << " ";
				}
				minimum+=.01;	
			}
				cout<<"\n";
			}
			cout << "\n\n***\t***\t***\t***\t***\t***\t***\t***\t***\t***\n\n";

		}
		else
		{
			cout<< "\n\n*** Table generation has been halted ***\n\n";
			break;
		}
		cout<<"\n";
	}	
}