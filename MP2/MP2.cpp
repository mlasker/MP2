/* School Admissions Calculator

			by Mark Lasker
			
									*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string> 
using namespace std;

int main()
{
	// File stream to read in file

	ifstream inFile("Text.txt");


	// Declare variables to store number of acceptances and applicants

	int numOfApplicants = 0;
	int liberalArtsAcceptances = 0;
	int musicAcceptances = 0;

	// Declare variables for data read in from file 

	char school, legacy;
	double gpa;
	int mathSAT, verbalSAT;


	// While read-in file has more lines, stores pre-formatted line data into variables

	while (inFile >> school >> gpa >> mathSAT >> verbalSAT >> legacy) {

		// String var to hold denial reasons and boolean to flag for denial

		string denialReason = "";
		bool denied = false;
		numOfApplicants++;

		// Loop to process student is school is 'L' - Liberal Arts

		if (school == 'L') {

			if (liberalArtsAcceptances > 4) {
				denied = true;
				denialReason += "Max LA applicants reached, ";
			}
			if (legacy == 'Y') {
				if (gpa < 3) {
					denied = true;
					denialReason += "Insufficient GPA, ";
				}
				if (mathSAT + verbalSAT < 1000) {
					denied = true;
					denialReason += "Insufficient SAT,";
				}
			}
			if (legacy == 'N') {
				if (gpa < 3.5) {
					denied = true;
					denialReason += "Insufficient GPA,";
				}
				if (mathSAT + verbalSAT < 1200) {
					denied = true;
					denialReason += "Insufficient SAT,";
				}
			}

			// Display data

			cout << "Applicant #" << numOfApplicants << endl;
			cout << "School= " << school << " GPA= " << gpa << " Math SAT= " << mathSAT <<
				" Verbal SAT= " << verbalSAT << " Legacy Applicant: " << legacy << endl;
			cout << "Applying to School of Liberal Arts . . .\n";
			if (!denied) {
				liberalArtsAcceptances++;
				cout << "Accepted!" << endl << endl;
			}
			else {
				cout << "DENIED\n";
				cout << "Reason(s) for denial: " << denialReason << endl << endl;
			}
			cout << "*************************************************\n\n";

		}

		// Loop to process student is school is 'L' - Liberal Arts

		if (school == 'M') {

			if (musicAcceptances > 2) {
				denied = true;
				denialReason += "Max M applicants reached, ";
			}
			if (mathSAT < 500 || verbalSAT < 500){
				denied = true;
				denialReason += "Insufficient SAT scores";
			}

			// Display data

			cout << "Applicant #" << numOfApplicants << endl;
			cout << "School= " << school << " GPA= " << gpa << " Math SAT= " << mathSAT <<
				" Verbal SAT= " << verbalSAT << " Legacy Applicant: " << legacy << endl;
			cout << "Applying to School of Music . . .\n";
			if (!denied) {
				musicAcceptances++;
				cout << "Accepted!" << endl << endl;
			}
			else {
				cout << "DENIED\n";
				cout << "Reason(s) for denial: " << denialReason << endl << endl;
			}
			cout << "*************************************************\n\n";

		}

		
	}
	cout << "Number of applicants = " << numOfApplicants << endl;
	cout << "Number of acceptances to Liberal Arts = " << liberalArtsAcceptances << endl;
	cout << "Number of acceptances to Music = " << musicAcceptances << endl;
	cout << "";

    return 0;
}

