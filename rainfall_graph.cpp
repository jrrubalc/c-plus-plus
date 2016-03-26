/*ID block  ---------------------+
+ Programmer : Jason Rubalcaba   +
+ Course: CSCI 1                 +
+ Assignment : 5                 +
+ Due Date   : Nov. 1, 2007      +
+--------------------------------+

              Program statment 
This program will create a graph representing the rainfall in Springfeild for a 
given year.
******************Analysis****************************
1.Data Needed
	Year
	Months
	Amount of rainfall
2.Constants Given
	None
3.Calculations
	Convert each inch of rain to five stars

************************ Algorithm ***************************************************************	
Call information function
Call Open_files function
	If successful read Year
		Loop until end of file
			Read month, rain
			Call write_month
			Call draw_line
		End Loop
		Call Draw_Scale function
		Close Files
	Print "end of program"

Information Function 
	Output purpose of program
Open_files function
	Prompt for imput file
	Prompt for output file
	open imput file
		If unsuccessful output error message
	open ouput file
		If unsuccessful output error message
Write_Month Function
	Evaluate a number value into a month
Draw line
	Output stars

/************************ End of Algorithm *********************************************************/
/************ Code segment ******************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
void Information(void);
bool Open_files(ifstream &, ofstream &);
void write_month(ofstream&, int);
void draw_line(ofstream&, int);
void draw_scale(ofstream&);
int main()
{
	int year, month, stars;
	float rain;
	ifstream inData;
	ofstream outData; 
	Information ();
	if(Open_files(inData, outData))
	{
		inData >> year;
		if (!inData.eof())
		{
		outData<< "Graph representing rainfall for year: " << year << endl;
		inData >> month >> rain;
		while (!inData.eof())
		{
			stars=(int)floor(rain*5);
			write_month(outData, month);
			draw_line(outData, stars);
			inData >> month >> rain;
		}
		draw_scale(outData);
		}
		else
			cout<<"Empty File Entered\n";
	inData.close();
	outData.close();
	}
	cout<<"End of Program"<<endl<<endl;
	return 0;

}

void Information (void)
{
	
	cout <<"This Program will create a graph representing the rain fall\n";
	cout <<"in Spiringfield using two outside files.\n\n";
}

bool Open_files(ifstream &inData, ofstream &outData)
{
	string Input, Output;
	cout << "Please enter input file name: ";
	cin >> Input ;
	inData.open(Input.c_str());
	if( inData.fail())
	{
			cout<<endl<<"Bad Input File Name" <<endl;
		return false;
	}
	else 
	{
		cout << "Please enter output file name: ";
		cin >> Output ;
		outData.open(Output.c_str());
		if (outData.fail())
			{
				cout<<endl<<"Bad Output File Name" <<endl;
				return false;
			}
		else
			return true;
	}
}

void write_month( ofstream& outData, int month)
{
	string Month;
	switch (month) 
	{
		case 1:
			Month="January";
			break;
		case 2:
			Month="February";
			break;
		case 3:
			Month="March";
			break;
		case 4:
			Month="April";
			break;
		case 5:
			Month="May";
			break;
		case 6:
			Month="June";
			break;
		case 7:
			Month="July";
			break;
		case 8:
			Month="August";
			break;
		case 9:
			Month="September";
			break;
		case 10:
			Month="October";
			break;
		case 11:
			Month="November";
			break;
		case 12:
			Month="December";
			break;
			default:
			Month="invalid";
	}

	outData << left << setw(10)<< Month << "|" ;
}


void draw_line( ofstream& outData, int stars )
{
	outData<<right<<setw(stars)<<setfill('*') << ""<<setfill(' ')<< endl;
}


void draw_scale(ofstream& outData)
{
	outData<<right<<setw(11)<<"|";
	outData<<"----1----2----3----4----5----6----7----8----9---10---11---12";
	outData<<"\n"<<setw(52)<<"Inches of Rainfall";
	
}
