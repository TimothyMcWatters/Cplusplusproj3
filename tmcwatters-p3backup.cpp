/****************************
Timothy McWatters
tmcwatters-p3.cpp
programming in C++ project 3

Write a program called English-Metric
Converter that makes a simple, 
menu-driven conversion sofware package. 
It will present the user with a menu of 
choices and execute the operation specified.
*****************************/
#include <iostream>
using namespace std;

const double METERS_PER_FOOT = 0.3048;

int menu();
void metersToFeet(double& a, double& b);
void FeetToMeters(double& a, double& b);
void rectangleFeet(double a, double b);
void rectangleMeters(double a, double b);

int main()
{
   int option, optionReturn;
   double length, width;
   
   do {
      do { 
        optionReturn = menu();
      } while ((optionReturn <= 0) || (optionReturn > 5));

         if ((optionReturn >= 1) && (optionReturn <= 4)) {
            cout << "Input a length and width: " << endl;
            cin >> length >> width;
         }
   
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

int menu()
{
   int a;
   
   cout << "English-Metric Converter" << endl;
   cout << "\t1) Convert from meters to feet" << endl;
   cout << "\t2) Convert from feet to meters" << endl;
   cout << "\t3) Compute area of a rectangle in square feet given length and width in meters" << endl;
   cout << "\t4) Compute area of a rectangle in square meters given the length and width in feet" << endl;
   cout << "\t5) Quit the program" << endl;
   cout << "Please enter a number (1-5) ->" << endl;
   cin >> a;
   
   return a;
}

void metersToFeet(double& a, double& b)
{
   a = a * METERS_PER_FOOT;
   b = b * METERS_PER_FOOT;
   
   cout << "Length is: " << a << " Ft" << endl;
   cout << "Width is: " << b << " Ft" << endl;
   
   return;
}

void FeetToMeters(double& a, double& b)
{
   a = a / METERS_PER_FOOT;
   b = b / METERS_PER_FOOT;
   
   cout << "Length is: " << a << " M" << endl;
   cout << "Width is: " << b << " M" << endl;
   
   return;
}

void rectangleFeet(double a, double b)
{
   cout << "Length is: " << a << " M" << endl;
   cout << "Width is: " << b << " M" << endl;
   cout << "Area is: " << a * b << " M\n" << endl;
   
   metersToFeet(a, b);
   cout << "Area is: " << a * b << " Ft\n" << endl;
   
   return;
}

void rectangleMeters(double a, double b)
{
   cout << "Length is: " << a << " Ft" << endl;
   cout << "Width is: " << b << " Ft" << endl;
   cout << "Area is: " << a * b << " Ft\n" << endl;
   
   FeetToMeters(a, b);
   cout << "Area is: " << a * b << " M\n" << endl;
   
   return;
}


