// DNA encryption
// Written by Alex Jordan from Sunday, March 11th 2012 to Monday, March 26th 2012
// This program is for the 1012 Google Science Fair. It is not intended to be useful in any other context.

// Notes:
// If plugging in an int to encrypt(), decrypt(), or getNextRandomNumber(), you MUST convert it to a string in the arguments!

// Uncomment the following line to turn on dumpfiles. Note: this support was badly broken/inconsistent when I turned it off!
//#define DUMPFILE_SUPPORT_ENABLED

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <assert.h>
#include <sstream>
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
	
	return newstring;
}
*/

#ifdef DUMPFILE_SUPPORT_ENABLED
string getNextRandNumber(string previousNumber, ofstream dumpfile) {
#else
string getNextRandNumber(string previousNumber) {
#endif
	//code complete
	#ifdef DUMPFILE_SUPPORT_ENABLED
	dumpfile << "\n" << "calculating next random number. previous random number was " << previousNumber;
	#endif
	string nextNumber = previousNumber;
	bool stillChanging = true;
	
	for (int i = 0; stillChanging;) {
		if (previousNumber[i] = '0') {
			previousNumber[i] = '1';
			stillChanging = false;
		} else if (previousNumber[i] = '1') {
			previousNumber[i] = '2';
			stillChanging = false;
		} else if (previousNumber[i] = '2') {
			previousNumber[i] = '3';
			stillChanging = false;
		} else if (previousNumber[i] = '3') {
			previousNumber[i] = '4';
			stillChanging = false;
		} else if (previousNumber[i] = '4') {
			previousNumber[i] = '5';
			stillChanging = false;
		} else if (previousNumber[i] = '5') {
			previousNumber[i] = '6';
			stillChanging = false;
		} else if (previousNumber[i] = '6') {
			previousNumber[i] = '7';
			stillChanging = false;
		} else if (previousNumber[i] = '7') {
			previousNumber[i] = '8';
			stillChanging = false;
		} else if (previousNumber[i] = '8') {
			previousNumber[i] = '9';
			stillChanging = false;
		} else if (previousNumber[i] = '9') {
			previousNumber[i] = '1';
			i++;
		}
		
		assert(previousNumber[i] != nextNumber[i]);
	}
	
	return nextNumber;
}

#ifdef DUMPFILE_SUPPORT_ENABLED
string getNextSequence(string previousSequence, ofstream dumpfile) {
#else
string getNextSequence(string previousSequence) {
#endif
	//code complete
	#ifdef DUMPFILE_SUPPORT_ENABLED
	dumpfile << "\n" << "calculating next sequence. previous sequence was " << previousSequence;
	#endif
	string nextSequence = previousSequence;
	bool stillChanging = true;
	
	for (int i = previousSequence.size(); stillChanging;) {
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
	
	#ifdef DUMPFILE_SUPPORT_ENABLED
	dumpfile << "\n" << "new sequence is" << nextSequence;
	#endif
	return nextSequence;
}

string convertIntToStr(int integer) {
    ostringstream out;
    out << integer;
    return out.str();
}

string convertToUpperCase(string& strToConvert) {
	for(unsigned int i=0;i<strToConvert.length();i++) {
		strToConvert[i] = toupper(strToConvert[i]);
	}
	
	return strToConvert;
}

int convertDnaToInt(char sequenceChar) {
	//code complete
	int intSequence;
	string sequence;
	
	sequence[0] = sequenceChar;
	
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

char convertNumberToLetter(int number) {
	//code complete
	// redundant; for better code understanding
	int n = number;
	char l;
	
	if (n == 1) {
		l = 'A';
	} else if (n == 2) {
		l = 'B';
	} else if (n == 3) {
		l = 'C';
	} else if (n == 4) {
		l = 'D';
	} else if (n == 5) {
		l = 'E';
	} else if (n == 6) {
		l = 'F';
	} else if (n == 7) {
		l = 'G';
	} else if (n == 8) {
		l = 'H';
	} else if (n == 9) {
		l = 'I';
	} else if (n == 10) {
		l = 'J';
	} else if (n == 11) {
		l = 'K';
	} else if (n == 12) {
		l = 'L';
	} else if (n == 13) {
		l = 'M';
	} else if (n == 14) {
		l = 'N';
	} else if (n == 15) {
		l = 'O';
	} else if (n == 16) {
		l = 'P';
	} else if (n == 17) {
		l = 'Q';
	} else if (n == 18) {
		l = 'R';
	} else if (n == 19) {
		l = 'S';
	} else if (n == 20) {
		l = 'T';
	} else if (n == 21) {
		l = 'U';
	} else if (n == 22) {
		l = 'V';
	} else if (n == 23) {
		l = 'W';
	} else if (n == 24) {
		l = 'X';
	} else if (n == 25) {
		l = 'Y';
	} else if (n == 26) {
		l = 'Z';
	}
	
	// if we didn't get a value for letter, something went wrong. crash.
	assert(l != NULL);

	// again, redundant; it's for better code understanding
	char letter = l;
	return letter;
}

string convertCharToString(char character) {
	//code complete
	// redundant; for improved code understanding. get used to it.
	char c = character;
	string s;
	
	if (c == 'A') {
		s = "A";
	} else if (c == 'B') {
		s = "B";
	} else if (c == 'C') {
		s = "C";
	} else if (c == 'D') {
		s = "D";
	} else if (c == 'E') {
		s = "E";
	} else if (c == 'F') {
		s = "F";
	} else if (c == 'G') {
		s = "G";
	} else if (c == 'H') {
		s = "H";
	} else if (c == 'I') {
		s = "I";
	} else if (c == 'J') {
		s = "J";
	} else if (c == 'K') {
		s = "K";
	} else if (c == 'L') {
		s = "L";
	} else if (c == 'M') {
		s = "M";
	} else if (c == 'N') {
		s = "N";
	} else if (c == 'O') {
		s = "O";
	} else if (c == 'P') {
		s = "P";
	} else if (c == 'Q') {
		s = "Q";
	} else if (c == 'R') {
		s = "R";
	} else if (c == 'S') {
		s = "S";
	} else if (c == 'T') {
		s = "T";
	} else if (c == 'U') {
		s = "U";
	} else if (c == 'V') {
		s = "V";
	} else if (c == 'W') {
		s = "W";
	} else if (c == 'X') {
		s = "X";
	} else if (c == 'Y') {
		s = "Y";
	} else if (c == 'Z') {
		s = "Z";
	}
	
	//guess why this is here
	//if you don't get it you either haven't read the beginning of this method and methods above it or you're stupid
	string charString = s;
	
	return charString;
}

string encrypt(string plaintextString, string keyString) {
	string ciphertext;
	int plaintext[plaintextString.size()];
	int key[keyString.size()];

	//reading the key into an int
	for (int i = 0; i < keyString.size(); i++) {
		if (keyString[0] == 'A' || keyString[0] == 'T' || keyString[0] == 'C' || keyString[0] == 'G') {
			// Key is DNA
			key[i] = convertDnaToInt(keyString[i]);
		} else {
			// Key is number
			// typecasts whoo - wait actually not. custom methods whoo
			string keyIntTransitive = convertCharToString(keyString[i]);
			
			key[i] = atoi(keyIntTransitive.c_str());
		}
		//make sure key[i] exists, mostly because I like using assertions
		assert(key[i] != NULL);
	}
	
	for (int i = 0; i < plaintextString.size(); i++) {
		//set plaintext value i
		plaintext[i] = convertLetterToNumber(plaintextString[i]);;
		//perform algorithm
		ciphertext[ciphertext.size()+1] = (convertNumberToLetter(plaintext[i] + key[i]));
	}
	
	return ciphertext;
}

string decrypt(string ciphertextString, string keyString) {
	int key[keyString.size()];
	int ciphertext[ciphertextString.size()];
	string plaintext;
	
	//reading the key into an int
	for (int i = 0; i < keyString.size(); i++) {
		if (keyString[0] == 'A' || keyString[0] == 'T' || keyString[0] == 'C' || keyString[0] == 'G') {
			// Key is DNA
			char charKeyTransitive = keyString[i];
			key[i] = convertDnaToInt(charKeyTransitive);
		} else {
			// Key is number
			// typecasts whoo - wait actually not. custom methods whoo
			string keyIntTransitive = convertCharToString(keyString[i]);
			
			key[i] = atoi(keyIntTransitive.c_str());
		}
		//make sure key[i] exists, mostly because I like using assertions
		assert(key[i] != NULL);
	}
	
	for (int i = 0; i < ciphertextString.size(); i++) {
		//set ciphertext value i
		ciphertext[i] = convertLetterToNumber(ciphertextString[i]);
		//perform algorithm
		plaintext[plaintext.size()+1] = (convertNumberToLetter(ciphertext[i] - key[i]));
	}
	
	return plaintext;
}

int main() {
	
	// declare (mostly)
	bool verbose = false;
	bool willDumpData = true;
	int iterations;
	int randnumberdigits;
	int dnanumbervalues;
	string plaintext;
	string dumpLocation = "~/sciencefair.txt";
	#ifdef DUMPFILE_SUPPORT_ENABLED
	ofstream dumpfile;
	#endif
	
	// ask 1
	cout << "show verbose output? (y/n): ";
	string charverbose;
	cin >> charverbose;
	if (charverbose == "y") {
		verbose = true;
	} else if (charverbose == "n") {
		verbose = false;
	}
	
	#ifdef DUMPFILE_SUPPORT_ENABLED
	// ask 2
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
	#else
	cout << "\n" << "dumpfile support is disabled in this build.";
	#endif
	
	// ask 3
	cout << "\n" << "select number of test iterations: ";
	cin >> iterations;
	
	// declare (completely)
	//initialize arrays to store the random numbers/sequences, ciphertexts that we generate, and number of times we tried decryption for each method: we can't do this at the top because we don't know how many test iterations there will be
	int dnaDecryptionTries[iterations-1];
	int numDecryptionTries[iterations-1];
	int randnumber[iterations-1];
	string randsequence[iterations-1];
	string numciphertext[iterations-1];
	string dnaciphertext[iterations-1];
	
	/*
	cout << "\n" << "ok. select number of digits for the random numbers (no more than 9, please): ";
	cin >> randnumberdigits;
	assert(randnumberdigits < 10);
	#ifdef DUMPFILE_SUPPORT_ENABLED
	if (willDumpData) dumpfile << "\n" << "selected " << randnumberdigits << " digits for random nubmers";
	#endif
	
	cout << "\n" << "select number of values in the DNA sequence (A, T, C, and G will be converted from numbers 1-4 to perform encryption): ";
	cin >> dnanumbervalues;
	#ifdef DUMPFILE_SUPPORT_ENABLED
	if (willDumpData) dumpfile << "selected " << dnanumbervalues << " as the number of values in the DNA sequence";
	#endif
	*/
	
	// ask 4
	cout << "\n" << "specify plaintext to encrypt (no more than 9 characters, please; plaintext will be converted to uppercase): ";
	cin >> plaintext;
	assert(plaintext.size() < 10);
	if (verbose) cout << "\n" << "converting to uppercase";
	plaintext = convertToUpperCase(plaintext);
	if (verbose) cout << "\n" << "got " << plaintext;
	#ifdef DUMPFILE_SUPPORT_ENABLED
	if (willDumpData) dumpfile << "selected plaintext \"" << plaintext << "\"";
	#endif
	
	cout << "\n" << "setting number of digits/values of numbers/DNA to " << plaintext.size() << ".";
	randnumberdigits = plaintext.size();
	dnanumbervalues = plaintext.size();
	
	// generate
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
	for (int i = 0; i < iterations; i++) {
		int trynumber;
		if (verbose) {
			cout << "\n" << "generating random number " << i+1;
		}
		bool numbervalid = false;
		
		if (i = 0) {
			//initialize random seed
			srand ( time(NULL) );
			//generate random number
			trynumber = rand();
		} else {
			//new seed whee
			srand ( randnumber[i-1] );
			//new random number whee
			trynumber = rand();
		}

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
			       
			}
			
			if (verbose) {
				if (numbervalid == true) {
					cout << "\n" << "number of digits matched requested number of digits. generation of random number " << i+1 << "is complete";
				}
				if (numbervalid == false) {
					cout << "\n" << "number of digits does not match requested number of digits. clipping numbers to get closer to a match";
					trynumber = trynumber / 10;
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
	
	// encrypt
	cout << "\n" << "encrypting plaintext using DNA";
	for (int i = 0; i < iterations; i++) {
		if (verbose) cout << "\n" << "generating ciphertext " << i+1;
		dnaciphertext[i] = encrypt(plaintext, randsequence[i]);
		if (verbose) cout << "\n" << "generated " << dnaciphertext[i] << " from key " << randsequence[i];
	}
	
	cout << "\n" << "done encrypting using DNA. encrypting using random numbers";
	
	for (int i = 0; i < iterations; i++) {
		if (verbose) cout << "\n" << "generating ciphertext " << i+1;
		numciphertext[i] = encrypt(plaintext, convertIntToStr(randnumber[i]));
		if (verbose) cout << "\n" << "generated " << numciphertext[i] << "from key " << randnumber[i];
	}
	
	cout << "\n" << "done encrypting plaintext using random numbers";
	
	// test
	cout << "\n" << "testing";
	for (int i = 0; i < iterations; i++) {
		string dnaTryKey = randsequence[i];
		for (int j = 0; j < dnanumbervalues; j++) {
			dnaTryKey.append("A");
		}
		
		string numTryKey;
		for (int j = 0; j < randnumberdigits; j++) {
			numTryKey.append("0");
		}
		
		if (verbose) cout << "\n" << "running test iteration " << i+1;
		bool stillTestingDna = true;
		bool stillTestingNum = true;
		for (; stillTestingDna == true || stillTestingNum == true; ) {
			string decryptedPlaintext;
			
			if (stillTestingDna) {
				decryptedPlaintext = decrypt(dnaciphertext[i], dnaTryKey);
				if (decryptedPlaintext == plaintext) {
					stillTestingDna = false;
				} else {
					#ifdef DUMPFILE_SUPPORT_ENABLED
					dnaTryKey = getNextSequence(dnaTryKey, dumpfile);
					#else
					dnaTryKey = getNextSequence(dnaTryKey);
					#endif
				}
				dnaDecryptionTries[i]++;
			}
			
			if (stillTestingNum == true) {
				decryptedPlaintext = decrypt(numciphertext[i], numTryKey);
				if (decryptedPlaintext == plaintext) {
					stillTestingNum = false;
				} else {
					#ifdef DUMPFILE_SUPPORT_ENABLED
					numTryKey = getNextSequence(numTryKey, dumpfile);
					#else
					numTryKey = getNextSequence(numTryKey);
					#endif
				}
				numDecryptionTries[i]++;
			}
		}
		if (verbose) cout << "\n" << "done running test iteration " << i+1;
	}
	cout << "\n" << "done testing";
	
	// summary
	cout << "\n" << "\n" << "summary of results (best viewed with a fixed-width font):";
	cout << "\n" << "test               ||";
	for (int i = 0; i < iterations-1; i++) {
		for (int j = 0; j < (20-convertIntToStr(iterations).size())/2; i++) {
			cout << " ";
		}
		cout << i+1;
		for (int j = 0; j < (20-convertIntToStr(iterations).size())/2; i++) {
			cout << " ";
		}
		cout << "|";
	}
	cout << "\n" << "plaintext          ||";
	for (int i = 0; i < iterations-1; i++) {
		for (int j = 0; j < (20-plaintext.size())/2; i++) {
			cout << " ";
		}
		cout << plaintext;
		for (int j = 0; j < (20-plaintext.size())/2; i++) {
			cout << " ";
		}
		cout << "|";
	}
	cout << "\n" << "dna sequence key   ||";
	for (int i = 0; i < iterations-1; i++) {
		for (int j = 0; j < (20-randsequence[i].size())/2; i++) {
			cout << " ";
		}
		cout << randsequence[i];
		for (int j = 0; j < (20-randsequence[i].size())/2; i++) {
			cout << " ";
		}
		cout << "|";
	}
	cout << "\n" << "random number key  ||";
	for (int i = 0; i < iterations-1; i++) {
		for (int j = 0; j < (20-convertIntToStr(randnumber[i]).size())/2; i++) {
			cout << " ";
		}
		cout << randnumber[i];
		for (int j = 0; j < (20-convertIntToStr(randnumber[i]).size())/2; i++) {
			cout << " ";
		}
		cout << "|";
	}
	cout << "\n" << "dna ciphertext     ||";
	for (int i = 0; i < iterations-1; i++) {
		for (int j = 0; j < (20-dnaciphertext[i].size())/2; i++) {
			cout << " ";
		}
		cout << dnaciphertext[i];
		for (int j = 0; j < (20-dnaciphertext[i].size())/2; i++) {
			cout << " ";
		}
		cout << "|";
	}
	cout << "\n" << "number ciphertext  ||";
	for (int i = 0; i < iterations-1; i++) {
		for (int j = 0; j < (20-numciphertext[i].size())/2; i++) {
			cout << " ";
		}
		cout << numciphertext[i];
		for (int j = 0; j < (20-numciphertext[i].size())/2; i++) {
			cout << " ";
		}
		cout << "|";
	}
	cout << "\n" << "tries to break num ||";
	for (int i = 0; i < iterations-1; i++) {
		for (int j = 0; j < (20-convertIntToStr(numDecryptionTries[i]).size())/2; i++) {
			cout << " ";
		}
		cout << numDecryptionTries[i];
		for (int j = 0; j < (20-convertIntToStr(numDecryptionTries[i]).size())/2; i++) {
			cout << " ";
		}
		cout << "|";
	}
	cout << "\n" << "tries to break dna ||";
	for (int i = 0; i < iterations-1; i++) {
		for (int j = 0; j < (20-convertIntToStr(dnaDecryptionTries[i]).size())/2; i++) {
			cout << " ";
		}
		cout << dnaDecryptionTries[i];
		for (int j = 0; j < (20-convertIntToStr(dnaDecryptionTries[i]).size())/2; i++) {
			cout << " ";
		}
		cout << "|";
	}
	
	
	// clean up
	#ifdef DUMPFILE_SUPPORT_ENABLED
	dumpfile.close();
	#endif
	
	// exit
	return 0;
}
