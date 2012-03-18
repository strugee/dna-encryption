// DNA encryption
// Written by Alex Jordan on Sunday, March 11th 2012
// This program is for the 1012 Google Science Fair. It is not intended to be useful in any other context.

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

string getNextSequence(string previousSequence, fstream dumpfile) {
	dumpfile << "\n" << "calculating next sequence. previous sequence was" << previousSequence;
	string nextSequence = previousSequence;
	bool stillChanging = true;
	
	//TODO
	for (int i = previousSequence.size(); stillChanging = true;) {
		char previousSequenceChar = previousSequence[i];
		if (previousSequenceChar == 'A') {
			nextSequence[i] = "T";
			stillChanging = false;
		} else if (previousSequenceChar == 'T') {
			nextSequence[i] = "C";
			stillChanging = false;
		} else if (previousSequenceChar == 'C') {
			nextSequence[i] = "G";
			stillChanging = false;
		} else if (previousSequenceChar == 'G') {
			i--;
			nextSequence[i] = "A";
		}
	}
	
	dumpfile << "\n" << "new sequence is" << nextSequence;
	return nextSequence;
}

int main() {
	
	bool verbose = false;
	bool willDumpData = true;
	int iterations;
	int randnumberdigits;
	int dnanumbervalues;
	string plaintext;
	string dnaciphertext;
	string numciphertext;
	string dumpLocation = "~/sciencefair.txt";
	ofstream dumpfile;
	
	cout << "show verbose output? (y/n): ";
	string charverbose;
	cin >> charverbose;
	if (charverbose == "y") {
		verbose = true;
	} else if (charverbose == "n") {
		verbose = false;
	}
	
	cout << "\n" << "dump data to file when done? (y/n) ";
	string chardumpData;
	cin >> chardumpData;
	if (chardumpData == "y") { 
		willDumpData = true;
		cout << "\n" << "specify file path to dump to: ";
		cin >> dumpLocation;
		dumpfile.open(dumpLocation);
		if (dumpfile.is_open() == false) {
			cout << "\n" << "opening the file failed. program will not dump.";
			willDumpData = false;
		} else {
			dumpfile << "initiated dumpfile";
		}
	} else if (chardumpData == "n") {
		willDumpData = false;
	}
	
	cout << "select number of test iterations: ";
	cin >> iterations;
	
	//initialize arrays to store the random numbers/sequences that we generate: we can't do this at the top because we don't know how many numbers/sequences there will be
	int randnumber[iterations-1];
	string randsequence[iterations-1];
	
	cout << "\n" << "ok. select number of digits for the random numbers: ";
	cin >> randnumberdigits;
	if (willDumpData) dumpfile << "\n" << "selected " << randnumberdigits << " digits for random nubmers";
	
	cout << "\n" << "select number of values in the DNA sequence (A, T, C, and G will be converted from numbers 1-4 to perform encryption): ";
	cin >> dnanumbervalues;
	if (willDumpData) dumpfile << "selected " << dnanumbervalues << " as the number of values in the DNA sequence";
	
	cout << "\n" << "specify plaintext to encrypt: ";
	cin >> plaintext;
	if (willDumpData) dumpfile << "selected plaintext \"" << plaintext << "\"";
	
	cout << "\n" << "ok. generating random numbers";
	for (int i = 0; i != iterations; i++) {
		int trynumber;
		if (verbose) {
			cout << "\n" << "generating random number " << i+1;
		}
		bool numbervalid = false;
		do {
			//initialize random seed
			srand ( time(NULL) );
			//generate random number
			trynumber = rand();
			
			if (verbose) {
				cout << "\n" << "generated " << trynumber;
			}
			
			//make sure the number is positive; if not, make it positive
			if (trynumber < 0) {
				//number is negative
				if (verbose) {
					cout << "\n" << "number is negative. multiplying by -1";
				}
				trynumber = trynumber*(-1);
				if (verbose) {
					cout << "\n" << "done. number is now " << trynumber;
				}
			} else {
				//number is positive
				if (verbose) {
					cout << "\n" << "number is positive. continuing ";
				}
			}
			
			//get the number of digits in the number
			if (verbose) {
				cout << "\n" << "determinig number of digits";
			}
			int digits = 1;
			for (int j = trynumber; j > 10; digits++) {
				j = j/10;
			}
			if (verbose) {
				cout << "\n" << "number has " << digits << " digits";
			}
			
			//determine if number of digits matches requested number of digits; if so, flip numbervalid to true
			if (digits == randnumberdigits) {
				numbervalid = true;
			}
			if (verbose) {
				if (numbervalid == true) {
					cout << "\n" << "number of digits matches requested number of digits. generation of random number " << i+1 << "is complete";
				}
				if (numbervalid == false) {
					cout << "\n" << "number of digits does not match requested number of digits. regenerating random number " << i+1;
				}
			}
		} while (numbervalid == false);
		randnumber[i] = trynumber;
		
	}
	cout << "\n" << "done generating random numbers";
	if (verbose) {
		for (int i = 0; i < iterations; i++)
		cout << "\n" << "random number " << i+1 << " was " << randnumber[i];
	}
	
	cout << "\n" << "generating random DNA sequences";
	for (int i = 0; i < iterations; i++) {
		string sequence;
		if (verbose) {
			cout << "\n" << "generating sequence " << i+1;
		}
		//generate a number between 1 and 4, inclusive; append it to the sequence
		for (int j = 0; j < dnanumbervalues; j++) {
			int trynumber;
			//initialize random seed
			srand ( time(NULL) );
			//generate random number
			trynumber == rand();
			//make sure trynumber is positive
			if (trynumber < 0) {
				trynumber = trynumber*(-1);
			}
			//in case the number was 0, add 4 (otherwise it would mess up when 4 gets subtracted until it's a number we like)
			if (trynumber == 0) {
				trynumber = trynumber+4;
			}
			//make it between 1 and 4, inclusive
			do {
				trynumber = trynumber-4;
			} while (trynumber != 1 && trynumber != 2 && trynumber != 3 && trynumber != 4);
			
			//we like this number now, turn it into a letter and append it to the sequence
			//A corresponds to 1
			//T corresponds to 2
			//C corresponds to 3
			//G corresponds to 4
			if (trynumber == 1) {
				sequence.append("A");
			} else if (trynumber == 2) {
				sequence.append("T");
			} else if (trynumber == 3) {
				sequence.append("C");
			} else if (trynumber == 4) {
				sequence.append("G");
			}
		}
		
		//store the sequence
		randsequence[i] = sequence;
		
		if (verbose) {
			cout << "\n" << "generated sequence " << i << " as " << sequence;
		}
	}
	cout << "\n" << "done generating sequences";
	
	cout << "\n" << "encrypting plaintext using";
	//TODO
	
	//clean up and exit
	dumpfile.close();
	return 0;
}