/*
*
*  Program: arrays.cc
*  Name: Zachary Knoblauch
*  Date: 26/March/2019
*  Description: Program reads two connected files.
*               Program finds the largest and lowest values in the price array and the locations of each.
*               Program then prints off the price of the largest and smallest item
*               Program also prints off the names of the two items using the locations from the first array
*
*/


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

double findLowest(double x[], int &loc);
double findLargest(double x[], int&loc);

int main(int argc, char *argv[]){

  std::cout << std::fixed;
  std::cout << std::setprecision(2);//shows numbers to 2 decimal places

  ifstream costs;
  ifstream names;
  costs.open("data1.txt");//price file
  if(costs.fail())
    exit(1);
  names.open("data2.txt");//item name file
  if(names.fail())
    exit(1);

  double price[6];
  string items[6];
  for(int i = 0; i < 6; ++i){//fills array with costs
  costs >> price[i];
  }
  for(int i = 0; i < 6; ++i){//fills array with names
  names >> items[i];
  }
  int location = 0;//location in array of smallest price
  int location2 = 0;//location in array of largest price
  double lowest = findLowest(price, location);//finds lowest number in array
  double largest = findLargest(price, location2);//finds largest number in array

  cout << "The name of the least expensive part is " << items[location] << " at  $" << lowest << endl;
  cout << "The name of the most expensive part is " << items[location2] << " at $" << largest << endl;

  costs.close();//closes costs file
  names.close();//closts names file
  return 0;
}

double findLowest(double x[], int &loc){//find smallest number in array

  double lowest = 10000000;
  for(int i = 0; i < 6; ++i){
    if(x[i] < lowest){//if current element is smaller than lowest, replace lowest with current element
      lowest = x[i];
      loc = i;
    }
  }
  return lowest;
}

double findLargest(double x[], int&loc){//find largest number in array

  double largest = 0;
  for(int i = 0; i < 6; ++i){
    if(x[i] > largest){//if current element is smaller than largest, replace largest with current element
      largest = x[i];
      loc = i;
    }
  }
  return largest;
}
