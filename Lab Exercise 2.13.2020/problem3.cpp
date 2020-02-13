//Lab Exercise 2/13/2020 Problem 3
//Author: nmessa

#include <iostream>
#include <iomanip>
using namespace std;

//Define constant values
#define QP 1.6e-19
#define QE 1.6e-19
#define K 9.0e9
#define M 9.11e-31
#define C 3e8

//Function prototype
double calcVelocity(double);

int main()
{
	//Declare variables
	bool isValid = false;
	double radius, velocity;

	//Ensure valid radius entered
	while (!isValid)
	{
		cout << "Enter the radius of electron orbit (6e-11 >= radius >= 3e-15): ";
		cin >> radius;
		if (radius < 6e-11)
			isValid = true;
	}

	//Get electron velocity
	velocity = calcVelocity(radius);

	//Output velocity of electron as a percentage of the speed of light
	cout << setprecision(2);
	cout << velocity << " m/s" << endl;
	cout << velocity/C * 100 << "% of the speed of light" << endl;
	return 0;
}

//This function calculates the velocity of an electron
double calcVelocity(double r)
{
	double force, velocity;
	force = (K * QP * QE) / (r * r);
	velocity = sqrt(r * force / M);
	return velocity;
}

//Output
//Enter the radius of electron orbit (6e-11 >= radius >= 3e-15): 4e-15
//2.5e+008 m/s
//84% of the speed of light