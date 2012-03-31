// DNA encryption
// Written by Alex Jordan from Sunday, March 11th 2012 to Monday, March 26th 2012
// This program is for the 1012 Google Science Fair. It is not intended to be useful in any other context.

// Notes:
// If plugging in an int to encrypt() or decrypt(), you MUST convert it to a string in the arguments!

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <assert.h>
using namespace std;

/*
// I unfortunately spent some time on this only to find out that I didn't need it;
// I'm keeping it around so I don't feel like I wasted that time
string changeStringValue(string originalString, int stringValueToReplace, char replacingCharacter) {
	string newString;
	
	for (int i = 0; i <= originalString.size(); i++) {
		if (i != stringValueToReplace) {
			newString += originalString[i];
		} else if (i == stringValueToReplace) {
			newString += replacingCharacter;
		}
	}
	
	return newString;
}
*/

string getNextSequence(string previousSequence, fstream dumpfile) {
	//code complete
	dumpfile << "\n" << "calculating next sequence. previous sequence was" << previousSequence;
	string nextSequence = previousSequence;
	bool stillChanging = true;
	
	for (int i = previousSequence.size(); stillChanging = true;) {
		char previousSequenceChar = previousSequence[i];
		if (previousSequenceChar == 'A') {
			nextSequence[i] = 'T';
			stillChanging = false;
		} else if (previousSequenceChar == 'T') {
			nextSequence[i] = 'C';
			stillChanging = false;
		} else if (previousSequenceChar == 'C') {
			nextSequence[i] = 'G';
			stillChanging = false;
		} else if (previousSequenceChar == 'G') {
			i--;
			nextSequence[i] = 'A';
		}
	}
	
	dumpfile << "\n" << "new sequence is" << nextSequence;
	return nextSequence;
}

int convertDnaToInt(string sequence) {
	//code complete
	int intSequence;
	
	for (int i = 0; i < sequence.size(); i++) {
		int DnaNumberEquivalent;
		if (sequence[i] == 'A') {
			DnaNumberEquivalent = 1;
		} else if (sequence[i] == 'T') {
			DnaNumberEquivalent = 2;
		} else if (sequence[i] == 'C') {
			DnaNumberEquivalent = 3;
		} else if (sequence[i] == 'G') {
			DnaNumberEquivalent = 4;
		}
		
		intSequence = intSequence*10;
		intSequence = intSequence+DnaNumberEquivalent;
	}
	
	return intSequence;
}

int convertLetterToNumber(char letter) {
	//code complete
	// redundant; for better code understanding
	int l = letter;
	int n;
	
	if (l == 'A') {
		n = 1;
	} else if (l == 'B') {
		n = 2;
	} else if (l == 'C') {
		n = 3;
	} else if (l == 'D') {
		n = 4;
	} else if (l == 'E') {
		n = 5;
	} else if (l == 'F') {
		n = 6;
	} else if (l == 'G') {
		n = 7;
	} else if (l == 'H') {
		n = 8;
	} else if (l == 'I') {
		n = 9;
	} else if (l == 'J') {
		n = 10;
	} else if (l == 'K') {
		n = 11;
	} else if (l == 'L') {
		n = 12;
	} else if (l == 'M') {
		n = 13;
	} else if (l == 'N') {
		n = 14;
	} else if (l == 'O') {
		n = 15;
	} else if (l == 'P') {
		n = 16;
	} else if (l == 'Q') {
		n = 17;
	} else if (l == 'R') {
		n = 18;
	} else if (l == 'S') {
		n = 19;
	} else if (l == 'T') {
		n = 20;
	} else if (l == 'U') {
		n = 21;
	} else if (l == 'V') {
		n = 22;
	} else if (l == 'W') {
		n = 23;
	} else if (l == 'X') {
		n = 24;
	} else if (l == 'Y') {
		n = 25;
	} else if (l == 'Z') {
		n = 26;
	}
	
	// if we didn't get a value for number, something went wrong. crash.
	assert(n != NULL);
	
	// again, redundant; it's for better code understanding
	int number = n;
	return number;
}

string encrypt(string plaintextString, string keyString) {
	string ciphertext;
	int plaintext[plaintextString.size()];
	int key[keyString.size()];
	
	if (keyString[0] == 'A' || keyString[0] == 'T' || keyString[0] == 'C' || keyString[0] == 'G') {
		// Key is DNA
		key = convertDnaToInt(keyString);
	} else {
		// Key is number
		for (int i = 0; i < keyString.size(); i++) {
			// typecasts whoo
			string keyIntTransitive = string(keyString[i]);
			
			key[i] = atoi(keyIntTransitive.c_str());
		}
	}
	
	for (int i = 0; i < plaintextString.size(); i++) {
		//set plaintext value i
		plaintext[i] = convertLetterToNumber(plaintextString[i]);;
		//make sure key[i] exists, mostly because I like using assertions
		assert(key[i] != NULL);
		//perform algorithm
		plaintext[i] = plaintext[i] + key[i];
	}
	
	return ciphertext;
}

string decrypt(string ciphertext, string key) {
	string plaintext;
	
	
	
	return plaintext;
}

int main() {
	
	bool verbose = false;
	bool willDumpData = true;
	int iterations;
	int randnumberdigits;
	int dnanumbervalues;
	string plaintext;
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
		//FIXME
		//dumpfile.open(dumpLocation);
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
	
	//initialize arrays to store the random numbers/sequences and ciphertexts that we generate: we can't do this at the top because we don't know how many numbers/sequences there will be
	int randnumber[iterations-1];
	string randsequence[iterations-1];
	string numciphertext[iterations-1];
	string dnaciphertext[iterations-1];
	
	cout << "\n" << "ok. select number of digits for the random numbers (no more than 9, please): ";
	cin >> randnumberdigits;
	assert(randnumberdigits < 10);
	if (willDumpData) dumpfile << "\n" << "selected " << randnumberdigits << " digits for random nubmers";
	
	cout << "\n" << "select number of values in the DNA sequence (A, T, C, and G will be converted from numbers 1-4 to perform encryption): ";
	cin >> dnanumbervalues;
	if (willDumpData) dumpfile << "selected " << dnanumbervalues << " as the number of values in the DNA sequence";
	
	cout << "\n" << "specify plaintext to encrypt: ";
	cin >> plaintext;
	if (willDumpData) dumpfile << "selected plaintext \"" << plaintext << "\"";
	
	cout << "\n" << "ok. generating random numbers";
	/* // This clearly didn't work.
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
	*/
	for (int i = 0; i != iterations; i++) {
		int trynumber;
		if (verbose) {
			cout << "\n" << "generating random number " << i+1;
		}
		bool numbervalid = false;
		
		//initialize random seed
		srand ( time(NULL) );
		//generate random number
		trynumber = rand();

		do {
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
				cout << "\n" << "determining number of digits";
			}
			int digits = 1;
			for (int j = trynumber; j > 10; digits++) {
				j = j/10;
			}
			if (verbose) {
				cout << "\n" << "number has " << digits << " digits";
			}
			
			//determine if number of digits matches requested number of digits; if so, flip numbervalid to true; if not, clip digits
			if (digits == randnumberdigits) {
				numbervalid = true;
			} else if (digits > randnumberdigits) {
				trynumber -= trynumber % 10;
			}
			
			if (verbose) {
				if (numbervalid == true) {
					cout << "\n" << "number of digits matches requested number of digits. generation of random number " << i+1 << "is complete";
				}
				if (numbervalid == false) {
					cout << "\n" << "number of digits does not match requested number of digits. clipping numbers to get closer to a match";
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
	
	cout << "\n" << "encrypting plaintext using ";
	//TODO
	
	//clean up and exit
	dumpfile.close();
	return 0;
}