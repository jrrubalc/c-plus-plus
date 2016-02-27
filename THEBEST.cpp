/*ID block  ---------------------+
+ Programmer : Jason Rubalcaba   +
+ Course: CSCI 1                 +
+ Assignment : 5                 +
+ Due Date   : Nov. 20, 2007     +
+--------------------------------+

              Program statment 
This program will process the numbers in an array.
******************Analysis****************************
1.Data Needed
	Input File
	Ouput File
2.Constants Given
	None
3.Calculations
	Find Sum
	Find Average
	Find Standard Deviation
	Find Maximum
	Find Minimum
************************ Algorithm ***************************************************************	
Call Print_Header
Call Open_files
 If successful
	Call Read Data
	if length not equal to zero
		Call sum
		Call Average
		Call Calc_SD_Mean
		Call Maximum
		Call Minimum
		Call Report Results
	else
		output "Empty File"

Print_Header Function
	Print Infomation About Program
	Prompt for input and output file
Read Data Function
	Read numbers in the file
	Return amount of numbers
Sum Function
	Add All numbers togther
	Return Sum
Average Function
	return sum/length
Calc_SD_Mean Function
	return standard deviation
Maximum Function
	Return maximum value
Minimum Function
	Retun minimum Value
Report_Results
	Output
		File Names
		Numbers
		Length 
		Average
		Standard Deviation
		Maximum
		Minimum
/************************ End of Algorithm *********************************************************/
/************ Code segment ******************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>


using namespace std;

void Print_Header(string&, string&);
bool Open_files(ifstream &, ofstream &, string, string);
int Read_Data(double[50] , ifstream& inData);
double sum(double num[50], int); 
double Average(int length, double Sum); 
double Calc_SD_Mean(double[50],double,int);
void Report_Res(string, string, double num[50], double, double, double, double, double, ofstream &);
double Maximum(double [50], int); 
double Minimum(double [50], int); 

int main()
{
	double num[50], Sum, Ave, Standard, Max, Min;
	int length;
	string in, out;
	ifstream inData;
	ofstream outData; 
	Print_Header(in, out);
	if (Open_files(inData, outData, in, out))
		{
		length = Read_Data(num, inData);
		if(length!=0&&length<=50)
		{
		Sum = sum(num, length);
		Ave = Average( length, Sum); 
		Standard = Calc_SD_Mean(num,Ave,length);
		Max = Maximum(num, length);
		Min = Minimum(num, length);
		Report_Res(in, out, num, length, Ave, Standard, Max, Min, outData); 
		}
		else 
			cout << "Bad File" <<endl;
		}
	
	return 0;

}

void Print_Header(string& Ifile, string& Ffile)
{
	cout << "Jason Rubalcaba - Comp. Science - Program 6\n\n";
	cout << "This program will produce statistics (Mean, Standard Deviation,\n" ;
	cout << "Maximum and Minimum values of the list) for a list of real values.\n" ;
	cout << "The user will provide the names of input and output files.\n\n";
	cout << "Enter the name of the input file:  ";
	cin >> Ifile;
	cout << "Enter the name of the output file: ";
	cin >> Ffile;
	cout<<endl;


}


bool Open_files(ifstream &inData, ofstream &outData, string Input, string Output)
{
	
	inData.open(Input.c_str());
	if( inData.fail())
	{
		cout<<endl<<"Bad Input File Name" <<endl;
		return false;
	}
	else 
	{
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
int Read_Data(double num[],ifstream& inData)
	{
		int i=0,dummy;
		inData>>num[i];
		while(inData)
		{
			if(i<=48)
				inData>>num[++i];	
			else
			{
				inData>>dummy;
				i++;
			}
		}
		inData.close();
		if (i>50)
		{
			cout<<"*******Extra numbers will be excluded*******\n";
			i=50;
		}
		return i;
		

	}
double sum(double num[], int length) 
{
	int i=0;
    double total = 0.0;
    for (i; i<length; i++)
        total =total + num[i];  
    return total;
}
double Average(int length, double Sum) 
{
    return (Sum/static_cast<double>(length));
}
double Calc_SD_Mean(double num[], double Ave , int length)
{
	double sigma = 0.0;
    for (int i=0; i<length; i++) 
	{
        sigma = sigma + (num[i] - Ave)*(num[i] - Ave) ;
    }
	sigma = sigma / static_cast<double>(length);
	sigma = pow(sigma,0.5);
	return sigma;
 }
double Maximum(double num[], int length) 
{
	int i=0;
	double max = num[0];
	for (length, i; i<length; i++)
		if (max < num[i]) 
			max = num[i];
	return max; 
}
double Minimum(double num[], int length) 
{
	int i=0;
	double min = num[0];
	for (length, i; i<length; i++)
		if (min > num[i]) 
			min = num[i];
	return min; 
}


void Report_Res(string in, string out, double num[50],double size, double mean, double std_dev, double great, double least, ofstream & fout)
{
	int i=0;
	cout << "Reading values . . ."<<endl;
	fout << "Jason Rubalcaba - Comp. Science - Program 6\n\n";
	fout << "This program produced statistics (Mean, Standard Deviation,\n" ;
	fout << "Maximum and Minimum values of the list) for a list of real values.\n\n" ;
	fout<<"Input file: "<<in<<endl;
	fout<<"Output file: "<<out<<endl;
	fout << "\nReading values . . ."<<endl;
		while (i<size)
			{
				if(0==i%10&&!i==0)
				{
					cout << "\n";
					fout << "\n";
				}
				cout<<num[i]<<" ";
				fout<<num[i]<<" ";
				i++;
			}
	cout<<"\n\n"<< setw(25) << right << "Number of values read : " << size << endl;
	cout<< setw(25) << "Mean of the values : "<< mean <<endl;
	cout<< setw(25) << "Standard deviation : " << std_dev << endl;
	cout<< setw(25) << "Greatest value : "<< great << endl;
	cout<< setw(25) << "Least value : "<< least << endl << endl;
	fout<<"\n\n"<< setw(25) << right << "Number of values read: " << size << endl;
	fout<< setw(25) << "Mean of the values: "<< mean <<endl;
	fout<< setw(25) << "Standard deviation: "<< std_dev <<endl;
	fout<< setw(25) << "Greatest value: "<< great << endl;
	fout<< setw(25) << "Least value: "<< least << endl ;
	fout.close();
}
