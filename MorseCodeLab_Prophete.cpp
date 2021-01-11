// © copyright 2020 Ricky Prophete. All Rights Reserved.
// Author: Ricky Prophete
// Date: 3/10/2020
// Contact: ricky.prophete@live.lagcc.cuny.edu
// Description: A program to translate characters into Morse Code
#include <iostream> // default
#include <windows.h> // access Sleep(), Beep(), SetConsoleTitle() … library functions
#include <cstring> // string type access.
using namespace std;
// function definitions
void morseCode(char);
void dot() {
 Beep(466.16, 100); // sound of a DOT
 cout << '.'; // print a DOT
 Sleep(1000); // wait for 1ooo milliseconds
}
void dash() {
 Beep(440, 200); // sound of a DASH
 cout << '-'; // print a DASH
 Sleep(1000); // wait 1ooo milliseconds
}
int main () {
 double cost = 0;
 string input; // from string
 cout<< "Enter your Message: ";
 getline(cin, input, '\n'); // includes blank spaces
 int len = input.length(); // get length of string.
 cost = len*(0.01);        // Track the cost of the message
for(int i = 0; i < len; i++)
{
 char letter = input[i]; // get ith character from string.
 cout << letter <<":\t"; // display character
 morseCode( letter ); // convert to Morse code sound and dot-dash print
 if (input[i]==' '){cout<<'/';
    Sleep(1500);} // wait 1500 milliseconds
 cout << endl; // skip a line on output
}
 cout<< "Balance: "<<'$'<< cost<<endl;
 return 0; } // end of main
// INPUT: character
// OUTPUT: Morse Code sounds and dot-dash print
void morseCode(char letter)
// Input a character &
// change character into its Morse code sounds.
{
 switch( toupper(letter) ) {
 // Convert all characters to uppercase
 // When a match is found, play Morse code sounds
 case 'A':
 dot();dash();Sleep(500);//play sound of Morse code and wait 200 milliseconds
 break;
 case 'B':
 dash();dot();dot();dot();Sleep(500);
 break;
 case 'C':
 dash();dot();dash();dot();Sleep(500);
 break;
 case 'D':
 dash();dot();dot();Sleep(500);
 break;
 case 'E':
 dot();Sleep(500);
 break;
 case 'F':
 dot();dot();dash();dot();Sleep(500);
 break;
 case 'G':
 dash(); dash(); dot();Sleep(500);
 break;
 case 'H':
 dot();dot();dot();dot();Sleep(500);
 break;
 case 'I':
 dot();dot();Sleep(500);
 break;
 case 'J':
 dot();dash();dash();dash();Sleep(500);
 break;
 case 'K':
 dash(); dot(); dash();Sleep(500);
 break;
 case 'L':
 dot();dash();dot();dot();Sleep(500);
 break;
 case 'M':
 dash();dash();Sleep(500);
 break;
 case 'N':
 dash();dot();Sleep(500);
 break;
 case 'O':
 dash();dash();dash();Sleep(500);
 break;
 case 'P':
 dot();dash();dash();dot();Sleep(500);
 break;
 case 'Q':
 dash();dash();dot();dash();Sleep(500);
 break;
 case 'R':
 dot(); dash(); dot();Sleep(500);
 break;
 case 'S':
 dot();dot();dot();Sleep(500);
 break;
 case 'T':
 dash();Sleep(500);
 break;
 case 'U':
 dot();dot();dash();Sleep(500);
 break;
 case 'V':
 dot(); dot(); dot();dash();Sleep(500);
 break;
 case 'W':
 dot(); dash(); dash();Sleep(500);
 break;
 case 'X':
 dash(); dot(); dot();dash();Sleep(500);
 break;
 case 'Y':
 dash();dot();dash();dash();Sleep(500);
 break;
 case 'Z':
 dash();dash();dot();dot();Sleep(500);
 break;
 case '0':
 dash();dash();dash();dash();dash();Sleep(500);
 break;
 case '1':
 dot();dash();dash();dash();dash();Sleep(500);
 break;
 case '2':
 dot(); dot();dash();dash();dash();Sleep(500);
 break;
 case '3':
 dot();dot();dot();dash();dash();Sleep(500);
 break;
 case '4':
 dot(); dot(); dot();dot();dash();Sleep(500);
 break;
 case '5':
 dot(); dot(); dot();dot();dot();Sleep(500);
 break;
 case '6':
 dash(); dot(); dot();dot();dot();Sleep(500);
 break;
 case '7':
 dash();dash(); dot(); dot();dot();Sleep(500);
 break;
 case '8':
 dash();dash();dash();dot();dot();Sleep(500);
 break;
 case '9':
 dash();dash();dash();dash();dot();Sleep(500);
 break;
 case ' ':
 Sleep(1000);
 break;
 default:
 cout<<"** Error: Please Enter only letters and numbers **"<< endl;
 }

} // end of Morse code
