/*ID block  ----------------------------+
+ Programmer : Jason Rubalcaba     +
+ Course: CSCI 1                   +
+ Assignment : 3                   +
+ Due Date   : Oct 3, 2007   +
+------------------------------------------
//              Program statement
//  This program will calculate zeros for a ploynomial function
******************Analysis****************************
1.Data Needed
	A Coefficient 
	B Coefficient  
	C Coefficient 
2.Constants Given
	None
3.Calculations
	Assumptions: The equation will be given in Ax^2+Bx+C form 
	This program will find the zeros using the quadratic formuala
		(-B+sqrt(B^2-4*A*C))/(2*A) and (-B-sqrt(B^2-4*A*C))/(2*A)
	If the descriminat value is less than zero the solution will
		be seperated into the real and imaginary part
	If the descrimiant is zero only one value will be given
//	
************************ Algorithm ***************************************************************	
Step 1
	Input
		Promt the user for A, B, and C coefficients
Step 2		
	Process
		Descriminant value positive (two solutions)
			Solution 1 = (-B+sqrt(B^2-4*A*C))/(2*A)
			Solution 2 = (-B-sqrt(B^2-4*A*C))/(2*A)
		Descriminant value negative (two solutions)
			Solution 1 = (-B)/(2*A)+ sqrt(-(B^2-4*A*C))/(2*A)I
			Solution 2 = (-B)/(2*A)- sqrt(-(B^2-4*A*C))/(2*A)I
		Descriminant value zero (one solutions)
			Solution = (-B+sqrt(B^2-4*A*C))/(2*A)
		
Step 3
	Output
		Display the function created
		If A is zero display no solution
		If the descriminant value is positive display the two real solutions
		If the descriminant value is negative display the two imaginary solutions
		If the descriminant value is zero display the two real solutions
		
/************************ End of Algorithm *********************************************************/

/************ Code segment *******************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void main()
{
	double A, B, C, Discr, real1, real2, zero;
	
	cout << "\n\nThis program will calculate the solutions for a polynomial\n";
	cout << "in the form of Ax^2 + Bx + C\n";
	cout << "with A, B, and C being real numbers.\n\n";
	cout << "Enter the A Coefficient:\t";
	cin >> A;
	cout << endl<< "Enter the B Coefficient:\t";
	cin >> B;
	cout << endl<< "Enter the C Coefficient:\t";
	cin >> C;
	
	Discr = B*B-4*A*C;

	cout << "\n" << "For the function f(x) = " << A << showpos <<"x^2" << B << "x" << C << "\n\n";
	cout << left << fixed << showpoint << setprecision(3)<< scientific << noshowpos ;
	if (A==0)
		cout <<scientific << "Solutions will not be calculated\n\nA can not be zero\n\n";
	else if(Discr == 0)
	{
		zero=(-B)/(2*A);
		cout << setw(37)<< "There is one real solution:" << zero << "\n\n";
	}
	else if(Discr>0)
	{
		real1 = (-B+sqrt(Discr))/(2*A);
		real2 = (-B-sqrt(Discr))/(2*A);
		cout <<setw(37)<< "There are two real solutions:" << real1 <<","<< "\n\n";
		cout << right << setw(37) << "and         "<< real2 << "\n\n";
	}
	else if(Discr<0)
	{
		cout << setw(37)<< "There are two imaginary solutions:" << (-B)/(2*A)<<"+("<<(sqrt(-Discr))/(2*A)<<")i," << "\n\n";
		cout << right << setw(37)<< "and   " << (-B)/(2*A)<<"-("<<(sqrt(-Discr))/(2*A)<< ")i\n\n";
	}

}
