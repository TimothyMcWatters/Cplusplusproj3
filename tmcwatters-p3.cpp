/****************************
Timothy McWatters
tmcwatters-p3.cpp
programming in C++ project 3

Write a program called English-Metric
Converter that makes a simple, 
menu-driven conversion sofware package. 
It will present the user with a menu of 
choices, if appropriate it will take input
from the user for length and width in M or Ft
and execute the operation selected 
in the menu. Finally it will output this data to 
the screen.
*****************************/
#include <iostream>
using namespace std;

const double METERS_PER_FOOT = 0.3048; // Global Constant conversion rate

int menu();
void metersToFeet(double& a, double& b);
void FeetToMeters(double& a, double& b);
void rectangleFeet(double a, double b);
void rectangleMeters(double a, double b);

int main()
{
   int option, optionReturn;
   double length, width;
   
   do { // Loops the program as long as 1 - 4 are input for menu selections        
      optionReturn = menu();
 
         // Only asks for inputs when a valid menu option is selected
         if ((optionReturn >= 1) && (optionReturn <= 4)) {
            cout << "Input a length and width: " << endl;
            cin >> length >> width;
         }
   
         // Switch statement for menu selection that 
         // calls the appropriate function based on menu's return
         switch (optionReturn)
         {
            case 1:
               metersToFeet(length, width);
               break;
            case 2:
               FeetToMeters(length, width);
               break;
            case 3:
               rectangleFeet(length, width);
               break;
            case 4:
               rectangleMeters(length, width);
               break;
            default: //Does nothing
               break;
         }   
   } while ((optionReturn > 0) && (optionReturn < 5));

   return 0;
}

// Shows the user their options, and returns to main a valid selection (1-5)
int menu()
{
   int a;
   
   do {
   cout << "English-Metric Converter" << endl;
   cout << "\t1) Convert from meters to feet" << endl;
   cout << "\t2) Convert from feet to meters" << endl;
   cout << "\t3) Compute area of a rectangle in square feet given length and width in meters" << endl;
   cout << "\t4) Compute area of a rectangle in square meters given the length and width in feet" << endl;
   cout << "\t5) Quit the program" << endl;
   cout << "Please enter a number (1-5) ->" << endl;
   cin >> a;
   } while ((a <= 0) || (a > 5)); 
   
   return a;
}

// Takes 2 pointers for length/width and converts them to feet from meters
// and then outputs the result to the screen.
void metersToFeet(double& a, double& b)
{
   a = a * METERS_PER_FOOT;
   b = b * METERS_PER_FOOT;
   
   cout << "Length is: " << a << " Ft" << endl;
   cout << "Width is: " << b << " Ft" << endl;
   
   return;
}

// Takes 2 pointers for length/width and converts them to meters from feet
// and then outputs the result to the screen.
void FeetToMeters(double& a, double& b)
{
   a = a / METERS_PER_FOOT;
   b = b / METERS_PER_FOOT;
   
   cout << "Length is: " << a << " M" << endl;
   cout << "Width is: " << b << " M" << endl;
   
   return;
}

// Takes 2 values in meters, calls the function that converts
// the values to feet, and outputs L, W, and A in both M & Ft
void rectangleFeet(double a, double b)
{
   cout << "Length is: " << a << " M" << endl;
   cout << "Width is: " << b << " M" << endl;
   cout << "Area is: " << a * b << " M\n" << endl;
   
   metersToFeet(a, b);
   cout << "Area is: " << a * b << " Ft" << endl;
   
   return;
}

// Takes 2 values in feet, calls the function that converts
// the values to meters, and outputs L, W, and A in both M & Ft
void rectangleMeters(double a, double b)
{
   cout << "Length is: " << a << " Ft" << endl;
   cout << "Width is: " << b << " Ft" << endl;
   cout << "Area is: " << a * b << " Ft\n" << endl;
   
   FeetToMeters(a, b);
   cout << "Area is: " << a * b << " M" << endl;
   
   return;
}