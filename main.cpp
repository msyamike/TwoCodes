/* -----------------------------------------------------------
   Program 4: Two Codes
   Pair Program
   Class: CS 141, Spring 2020.  Tues 4pm lab
   System: CLion
   Author: Krish Bavana
   Partner: Madhava Sai Yamike
    -----------------------------------------------------------
 */
#include <iostream> //for cout and cin
#include <cctype> //for tolower() and toupper()
#include <fstream> //for inputing a file
#include <vector> //for using vectors to store values
using namespace std; //so I dont need to preface std:: every single time

//constant variables
const int FileSizeMin = 0; //lowest number of line number in the txt file
const int FileSizeMax = 250; //highest number of line numbers without spaces in the txt files
const char fileName[] = "ConstitutionAndBillOfRights.txt"; //setting up the file name, so I don't need to call everywhere

//---------------------------------------------------------------------------
//to convert the string into lower cases because it is eaiser to compare words
string toLowerWord(string word){
    for(int i = 0; i < word.size(); i++){ //loop to convert all the letters of the word into lower case
        word[i] = tolower(word[i]); //using tolower()
    }
    return word; //returning all the
}//end toLowerWord()

//---------------------------------------------------------------------------
//this function returns the vector filled with lines with chracter > 1, so dont store any empty lines into vector
//this vector functions will open the constitutionAndBillOfRights.txt and it will store all the sentence into vector
vector<string> vectorFiller() {
    // Open a file for reading
    ifstream inStream;             // declare an input stream
    inStream.open(fileName); //opens the files
    if (!inStream.is_open()) { //if file is not open then it says couldn't find the txt file
        cout << "Could not find ConstitutionAndBillOfRights.txt.  Exiting..." << endl;
        exit(-1); //to exit, if the file not found
    }
    string sentence; //this string to store get line by line and store into a string
    vector<string> vecSentence; //this vector is what we will return after this is filled with sentences
    while (inStream) {
        getline(inStream, sentence); //to get every line and store into the sentence
        if (sentence.length() > 1) { //if the sentence length is > 1, then will only, it will store into the vector
            vecSentence.push_back(sentence); //to add the sentence into the vector
        }//end if
    }//end while
    return vecSentence; //returning the filled vector
}//end vectorFiller()

//-------------------------------------------------------------------------------------
//this function is to check for the word the user is inputting
//whenever the user types 'W' or 'w' this is what we will call
string wordMatch(vector<string> allWords, //this vector will filled with all the sentences and we will pass filled vector
                 string userInputWord, //this is the userInputWord, this is used check if the word userInputted exists or not in the file
                 int &lineNumber){ //Passing this as reference because we need print both line number and the sentence and we can't return two items, so sending this as a reference
    userInputWord = toLowerWord(userInputWord); //to convert the userInput word into lower, so it eaiser to check
    string checkSentence; //to store the lower string values and check it
    string noneWord = "That word is not in the constitution"; //to return if nothing was found
    for(int i = 0; i <= allWords.size(); i++) {
        checkSentence = toLowerWord(allWords[i]);
        if (checkSentence.find(userInputWord) != string::npos) { //if the word is found or not
            lineNumber = i; //lineNumber so we can print later and it should match according to loop
            return allWords[i]; //return the sentence
        }
    }
    return noneWord;//return if no word was found
}//end wordMatch()

//---------------------------------------------------------------------
//this function is to return the previous line in the displaying text of 'w'
//user need to input 'p' or 'P' to access this function
string previousWord(vector<string> allWords, //this vector will filled with all the sentences and we will pass filled vector
                    int &lineNumber){ //Passing this as reference because we need print both line number and the sentence and we can't return two items, so sending this as a reference
    lineNumber = lineNumber - 1; //we are decreasing the line number so we can get the previous line
    return allWords.at(lineNumber); //return the previous line
}//end previousWord()

//---------------------------------------------------------------------
//this function is to return the following line in the displaying text of 'w'
//user need to input 'f' or 'F' to access this function
string followingWord(vector<string> allWords, //this vector will filled with all the sentences and we will pass filled vector
                     int &lineNumber){ //Passing this as reference because we need print both line number and the sentence and we can't return two items, so sending this as a reference
    lineNumber = lineNumber + 1; //we are increasing the line number so we can get the following line
    return allWords.at(lineNumber); //returning the following line
}//end followingWord()

//---------------------------------------------------------------------
//this function is to return all the word from the userinput
// user need to input 'a' or 'A' to access this function
string allMatchWord(vector<string> allWords, //this vector will filled with all the sentences and we will pass filled vector
        string userInputWord,  //this is the userInputWord, this is used check if the word userInputted exists or not in the file
        int &lineNumber){ //Passing this as reference because we need print both line number and the sentence and we can't return two items, so sending this as a reference
    userInputWord = toLowerWord(userInputWord); //to convert the userInput word into lower, so it eaiser to check
    string checkSentence; //to store the lower string values and check it
    string noneWord = "That word is not in the constitution"; //to return if the word is not found
    for(int i = 0; i <= allWords.size(); i++) {
        checkSentence = toLowerWord(allWords[i]);
        if (checkSentence.find(userInputWord) != string::npos) {//if the word is found in the txt file
            lineNumber = i; //to update line Number
            cout<<"Line "<<lineNumber<<": "<<endl;
            cout<<allWords[i]<<endl;
        }
    }
    return noneWord;
}//end allMatchWord()

int main() { //main
    char userInput; //for using input the options
    string userInputWord; //for the user to input the key word or sentence or phrase
    int lineNumber = 1; //line Number to print
    int tracker = 1; //to make the program print two options before and multiple options later
    while(userInput != 'x' || userInput != 'X') { //to repeated ask the user for question
        if (tracker <= 1) { //to make sure options 'w' and 'x' prints only once
            cout << "Select from the following choices: \n"
                    "   W  Enter word or phrase to find, and display enclosing text \n"
                    "   X  Exit program \n"
                    "Your choice: " << endl;
            cin >> userInput; //userInput about the options
            cin.get(); //to clear the buffer
        } else { //to print multiple number of times
            cout << "Select from the following choices: \n"
                    "   W  Enter word or phrase to find, and display enclosing text \n"
                    "   P  Display previous text \n"
                    "   F  Display following text \n"
                    "   A  Display all occurrences of found word or phrase\n"
                    "   X  Exit program \n"
                    "Your choice: " << endl;
            cin >> userInput; //to get the userInput
            cin.get(); //to clear the buffer
        }
        tracker = tracker + 1; //so we dont print the options of 2 multiple times
        if(userInput == 'x' || userInput == 'X'){ //to exit the program
            cout<<"Exiting program."<<endl;
            exit(-0);
        }
        else if (userInput == 'w' || userInput == 'W') { //to check for a word or phrase
            cout << "Enter word or phrase: " << endl;
            getline(cin, userInputWord); //used getline to check for phrases and doesn't carry any buffer
            wordMatch(vectorFiller(), userInputWord, lineNumber); //calling so lineNumber gets updated
            cout << "Line " << lineNumber << ": " << endl;
            cout << wordMatch(vectorFiller(), userInputWord, lineNumber) << endl; //printing the return statements of wordmatch()
        }
        else if (userInput == 'p' || userInput == 'P') { //to print the previous lines
            if (lineNumber > FileSizeMin) { //if lines greater than 0 lines then only access
                cout << "Line " << lineNumber - 1 << ": " << endl;  //printing the line Number but not changing the line Number value here
                cout << previousWord(vectorFiller(), lineNumber) << endl; //printing the previous line
            } else {
                cout << "There is no previous file contents. " << endl; //if lines less then 0, no file contents
            }
        }
        else if (userInput == 'f' || userInput == 'F') {
            if (lineNumber < FileSizeMax) { //if less 250 lines then only access
                cout << "Line " << lineNumber + 1 << ": " << endl; //printing the line Number but not changing the line Number value here
                cout << followingWord(vectorFiller(), lineNumber) << endl; //printing the previous line
            } else {
                cout << "There is no following file contents. " << endl; //if lines greater than 251 then no file contents
            }
        }
        else if (userInput == 'a' || userInput == 'A') { //if userInput is 'a or 'A'
            allMatchWord(vectorFiller(), userInputWord, lineNumber); //print all the sentences that match the word
        }
        else {
            cout << "PLEASE ENTER A VALID CHARACTER" << endl; //if userInput is Invalid
        }
    }
    return 0; //to satisfy C++
}//end main()
