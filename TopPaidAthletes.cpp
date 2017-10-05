// TopPaidAthletes.cpp : Defines the entry point for the console application.
//Purpose: This program will read in information reguarding 5HighestPaidAthletes.csv
//Purpose cont: This program will also export all data to Totals.txt
////////////////////////////////////////////////////////////////////////////////
//Author: Katlynn Stone
//Format of the file is:

//Total of salaries, Average of salaries, Total of endorsements, Average of endorsements, and total of endorsements and salaries

//The output file should be named Totals.txt


//This program has been written by Katlynn Stone

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	//File variables
	ifstream inFile;
	ofstream outFile;

	//Variables that hold data from file "TopPaidAthletes.txt".
	int iRank;
	string strName;
	string strSport;
	string strCountry;
	double dPay;
	double dEndorse;

	//Local varaibles
	double SalTotal;
	double SalAv;
	double EndTotal;
	double EndAv;
	double AbTot;

	//Attempt to open in File "TopPaidAthletes.txt"
	inFile.open("TopPaidAthletes.txt");
	if (inFile.fail())
	{
		cout << "Error loading files";
		return 1;
	}

	//Attempt to open out File "Totals.txt"
	outFile.open("Totals.txt");
	if (outFile.fail())
	{
		cout << "Error loading files";
		return 1;
	}

	//Header for program
	cout << left << "............................................................." << endl;
	cout << left << " ITCS 2530 - Programming Assignment for week #2" << endl;
	cout << left << "............................................................." << endl;
	cout << endl;

	//Save header in "Totals.txt"
	outFile << left << "............................................................." << endl;
	outFile << left << " ITCS 2530 - Programming Assignment for week #2" << endl;
	outFile << left << "............................................................." << endl;
	outFile << endl;

	//Read in data...
	//To read in data by brute force must execute 5 times...
	//First execution.
	inFile >> iRank >> strName >> strSport >> strCountry >> dPay >> dEndorse;
	SalTotal = SalTotal + dPay;
	EndTotal = EndTotal + dEndorse;
	
	//Second execution.
	inFile >> iRank >> strName >> strSport >> strCountry >> dPay >> dEndorse;
	SalTotal = SalTotal + dPay;
	EndTotal = EndTotal + dEndorse;
	
	//Third execution.
	inFile >> iRank >> strName >> strSport >> strCountry >> dPay >> dEndorse;
	SalTotal = SalTotal + dPay;
	EndTotal = EndTotal + dEndorse;
	
	//Fourth execution
	inFile >> iRank >> strName >> strSport >> strCountry >> dPay >> dEndorse;
	SalTotal = SalTotal + dPay;
	EndTotal = EndTotal + dEndorse;
	
	//Fifth execution
	inFile >> iRank >> strName >> strSport >> strCountry >> dPay >> dEndorse;
	SalTotal = SalTotal + dPay;
	EndTotal = EndTotal + dEndorse;
	/////////////////////////////////////////////////////////////////////////////
	
	//Find averages
	SalAv = SalTotal / 5;
	EndAv = EndTotal / 5;
	
	//Read out top 5 highest paid atheletes
	cout << left << "Of the top 5 highest paid atheletes..." << endl;
	cout << endl;
	outFile << left << "Of the top 5 highest paid atheletes..." << endl;
	outFile << endl;

	//Ensures all variables come out with the same spaces after the decimal point
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(4);

	//Read out the total and averages of the top 5 athletes salaries
	cout << left << "Total of all salaries:\t\t\t\t\t" << "$" << SalTotal << " (million)" << endl;
	cout << left << "Average of all salaries:\t\t\t\t" << "$" << SalAv << " (million)" << endl;
	outFile << left << "Total of all salaries:\t\t\t\t\t" << "$" << SalTotal << " (million)" << endl;
	outFile << left << "Average of all salaries:\t\t\t\t" << "$" << SalAv << " (million)" << endl;
	
	//Add a free line in between the first and second block
	cout << endl;
	outFile << endl;

	//Read out total and averages of the top 5 atheletes endorsements
	cout << left << "Total of all endorsements:\t\t\t\t" << "$" << EndTotal << " (million)" << endl;
	cout << left << "Average of all endorsements:\t\t\t\t" << "$" << EndAv << " (million)" << endl;
	outFile << left << "Total of all endorsements:\t\t\t\t" << "$" << EndTotal << " (million)" << endl;
	outFile << left << "Average of all endorsements:\t\t\t\t" << "$" << EndAv << " (million)" << endl;

	//Find the total of the salaries and endorsements
	//Since their totals were saved as local varaibles we need to just add the two variables up!
	AbTot = EndTotal + SalTotal;

	//Space out the second and third block of code
	cout << endl;
	outFile << endl;

	//Read out the absolute total now
	cout << left << "The total of all salaries and all endorsements!\t\t" << "$" << AbTot << " (million)" << endl;
	outFile << left << "The total of all salaries and all endorsements!\t\t" << "$" << AbTot << " (million)" << endl;
	//Clean up
	inFile.close();
	outFile.close();
	
	system("pause");
    return 0;
}

