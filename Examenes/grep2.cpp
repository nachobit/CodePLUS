#include <cstdlib>
#include <iostream>
#include <cstring>
#include <assert.h>
 
#define LINE_SIZE 100
 
using namespace std; 
 
 
/* Splits the  parameter @pattern in substrings delimited either by '*' or '?'
 * and stores each substring in the parameter string array @subpatterns.
 * 
 * PRECONDITIONS:
 * @pattern and @subpatterns have to be allocated by the caller
 */
void tokenizePattern(
		char pattern[LINE_SIZE], 
		char subpatterns[LINE_SIZE][LINE_SIZE]) {
	assert(pattern);
	assert(subpatterns);
	
	char buffer[LINE_SIZE];				// A buffer containing each subpattern
	unsigned short int bfrIndex = 0;	// Count of chars inserted in @buffer
	unsigned short int subptrnsIndex = 0;// Count of subpatterns in @subpatterns
	
	for (int i=0; i<LINE_SIZE && pattern[i]!='\0'; i++){
		// If it reads BACKSLASH && it's not the last char in the line
		// it might be a case of an escaped wildcard char.
		if (pattern[i] == '\\' && i != LINE_SIZE-1){	
			switch (pattern[i+1]){
				case '*':			
					buffer[bfrIndex++] = '*';
					i++;
					break;
				case '?':
					buffer[bfrIndex++] = '?';
					i++;
					break;	
			}
		}
		else if (pattern[i] == '*'){	// If it's the wildcard '*'
			// If the wildcard was the first char in the pattern 
			if (i == 0){
				// Mark that next subpattern occured because of '*'
				buffer[0] = '*';
				bfrIndex++;
			}
			else{
				// Terminate substring
				buffer[bfrIndex++] = '\0';
				// Copy subpattern found before wildcard to @subpatterns
				strncpy(subpatterns[subptrnsIndex++], buffer, bfrIndex);
				// Mark that next subpattern occured because of '*'
				buffer[0] = '*';
			}
			bfrIndex = 1;
		}
		else if (pattern[i] == '?'){	// If it's the wildcard '?'
			// If the wildcard was the first char in the pattern 
			if (i == 0){
				// Mark that next subpattern occured because of '?'
				buffer[0] = '?';
				bfrIndex++;
			}
			else{
				// Terminate substring
				buffer[bfrIndex++] = '\0';
				// Copy subpattern found before wildcard to @subpatterns
				strncpy(subpatterns[subptrnsIndex++], buffer, bfrIndex);
				// Mark that next subpattern occured because of '?'
				buffer[0] = '?';
			}
			bfrIndex = 1;
		}
		else{		// If it is an ordinary character, just insert in @buffer
			buffer[bfrIndex++] = pattern[i];
		}
	}
	// Terminate last substring
	buffer[bfrIndex++] = '\0';
	// Copy last buffer to @subpatterns
	strncpy(subpatterns[subptrnsIndex], buffer, bfrIndex);
}
 
/* Prints an array of strings and it's index, each in a new line.
 * 
 * POSTCONDITION:
 * Only the non empty strings will be printed
 */
void printStringArray (char strings[LINE_SIZE][LINE_SIZE]){
	assert(strings);
	
	cout << "--- SUB-PATTERNS PRINTOUT --------------------------\n";
	for (int i=0; i<LINE_SIZE; i++){
		assert(strings[i]);
		if (strings[i][0] != '\0'){
			cout << i << ":\t"<< strings[i] << endl;
		}
		else { break; }
	}
	cout << endl;
}
 
/* Searches @str to find the substrings stored in @subpatterns in the the same 
 * order they are stored in the array. Will take into account following 
 * wildcards:
 * '*' : 0 or more characters between pre- and succeeding substrings
 * '?' : 1 or more characters between pre- and succeeding substrings
 * 
 * PRECONDITIONS:
 * @subpatterns and @str are allocated by caller
 * Each substring follows format: [<wildcard>]<substring>
 * 
 * RETURNS:
 * True if full pattern from @subpatterns is matched in @str
 * False if not
 */
bool isPatternInString(
		char subpatterns[LINE_SIZE][LINE_SIZE], 
		char line[LINE_SIZE]){
	
	char * tmpString = line;
	
	for (int i=0; i<LINE_SIZE && subpatterns[i][0]!='\0'; i++){
		switch (subpatterns[i][0]){
			case '*':
				tmpString = strstr(tmpString, subpatterns[i]+sizeof(char));
				if (tmpString == NULL){ return false; }
				continue;
			case '?':
				tmpString = strstr(tmpString+sizeof(char), 
						subpatterns[i]+sizeof(char));
				if (tmpString == NULL){ return false; }
				continue;
			default:
				tmpString = strstr(tmpString, subpatterns[i]);
				if (tmpString == NULL){ return false; }
				continue;
		}
	}
	return true;
}
 
/* A program that simulates the functionality of grep linux tool.
 * Reads the first line of input stream for the @pattern which it will try to 
 * match in each following line.
 * Following wildcards are supported in a pattern:
 * '*' : 0 or more characters between pre- and succeeding substrings
 * '?' : 1 or more characters between pre- and succeeding substrings
 * Wildcards can be escaped in the pattern if preceeded by a '\'.
 * 
 * e.g. Pattern: pi*co will match with 11picoxx, pihhhhhco, picco, pi**7***co, 
 * pi47836r236gssco
 * 
 * POSTCONDITIONS:
 * Will print each line where the pattern was matched and the total count of 
 * matches.
 */
int main(int argc, char** argv) {
 
	char input[LINE_SIZE], pattern[LINE_SIZE];
	char subpatterns[LINE_SIZE][LINE_SIZE];
	unsigned int line = 2, foundCount = 0;
	
	// Terminate all strings of the subpatterns array
	for (int i=0; i<LINE_SIZE; i++){ subpatterns[i][0] = '\0'; }
 
	// Read the pattern according to which the following input will be searched
	if (!cin.eof()){ cin.getline(pattern, LINE_SIZE); }
	
	// Tokenize main search pattern into subpatterns delimited by the wildcards
	tokenizePattern(pattern, subpatterns);
	
//	printStringArray(subpatterns); // Uncomment for verbosity
	
	// For each line of input stream, search if provided pattern is present
	cout << "--- PATTERN WAS MATCHED IN THE FOLLOWING LINES -----\n";
	cout << "Searching for:\t" << pattern <<"\n\n";
	for ( ; !cin.eof(); line++){
		cin.getline(input, LINE_SIZE);
		if (isPatternInString(subpatterns, input)){
			foundCount++;
			cout << line <<":\t" << input << endl;
		}
	}
	cout << "\nTotal count of times the pattern was matched: " << foundCount;
	cout << "\n";
	
	return 0;
}