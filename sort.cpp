/*  PART 1:	The purpose of this program is to create 3 functions, each creates 10 txt files with a certain order 
   			(random, sorted, or reverse) per function, in which each text file includes a certain ammount of values in one of the orders
    PART 2:	The purpose of this program is to expand upon part 1 and create three functions each a different sorting 
    		algorithm in which we extract the numbers from the file into an array and then we sort it with ca
*/
#include <iostream>
#include <ctime> // so we can use time to generate random number every second
#include <cstdlib> //so we can use rand to generate random number values
#include <fstream> //so we can create/read/write to a file
#include <string> //to use string class to implement array of strings for file names
#include <sstream>
#include <chrono>
#include <algorithm>
#include <time.h>
#include <array>
#include <new>
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"

using namespace std;
using namespace std::chrono;

void GenerateRandomInputFiles() { //the purpose of this function is to generate files with a specific amount of numbers per file in random order
    string fileName[] = { "1000Random.txt","4000Random.txt", "8000Random.txt", "10000Random.txt", "40000Random.txt", "80000Random.txt", "100000Random.txt", "400000Random.txt", "800000Random.txt", "1000000Random.txt" };
    //create a string of file names
    for (int i = 0; i < 10; i++) { //loop to create files 
        fstream file; //calls file class to create/read/write 
        file.open(fileName[i], ios::out); //create file, give it a name from string array and open it for output/append operations, name of each file will come from string array names

        if (!file) { //if a file is not created you will be notified with which file wasnt created
            cout << "\nFile " << fileName[i] << " not created. Please try again." << endl;
        }
        else {
            cout << "File " << fileName[i] << " created successfully!" << endl; //if a file is created successfully the program will inform you
        }
        file.close();//close the file for safe keeping

        switch (i) { //switch statement to input a specific amount of values depending on the file/case 
        case 0: {
            file.open(fileName[i], ios::out);//opens the first file file in write mode
            for (int j = 0; j < 1000; j++) { //inputs 1000 random values unsorted
                int randNum = (rand() % 1000001); //generates a value between 0 and 1 million
                if (j != 999) { //if the loop isnt on its last iteration then the number will be input along with a comma
                    file << randNum << ",";
                }
                else //of the loop is on its last iteration it will print a value only without a comma at the end
                    file << randNum; 
            }
            file.close(); //close the file for safety 
            break; //break from switch statement and go back to the first for loop
        }
        case 1: {
            file.open(fileName[i], ios::out);
            for (int j = 0; j < 4000; j++) {
                int randNum = (rand() % 1000001); //generates a value between 0 and 1 million
                if (j != 3999) {
                    file << randNum << ", ";
                }
                else
                    file << randNum;
            }
            file.close();
            break;
        }
        case 2: {
            file.open(fileName[i], ios::app);
            for (int j = 0; j < 8000; j++) {
                int randNum = (rand() % 1000001); //generates a value between 0 and 1 million
                if (j != 7999) {
                    file << randNum << ", ";
                }
                else
                    file << randNum;
            }
            file.close();
            break;
        }
        case 3: {
            file.open(fileName[i], ios::app);
            for (int j = 0; j < 10000; j++) {
                int randNum = (rand() % 1000001); //generates a value between 0 and 1 million
                if (j != 9999) {
                    file << randNum << ", ";
                }
                else
                    file << randNum;
            }
            file.close();
            break;
        }
        case 4: {
            file.open(fileName[i], ios::app);
            for (int j = 0; j < 40000; j++) {
                int randNum = (rand() % 1000001); //generates a value between 0 and 1 million
                if (j != 39999) {
                    file << randNum << ", ";
                }
                else
                    file << randNum;
            }
            file.close();
            break;
        }
        case 5: {
            file.open(fileName[i], ios::app);
            for (int j = 0; j < 80000; j++) {
                int randNum = (rand() % 1000001); //generates a value between 0 and 1 million
                if (j != 79999) {
                    file << randNum << ", ";
                }
                else
                    file << randNum;
            }
            file.close();
            break;
        }
        case 6: {
            file.open(fileName[i], ios::app);
            for (int j = 0; j < 100000; j++) {
                int randNum = (rand() % 1000001); //generates a value between 0 and 1 million
                if (j != 99999) {
                    file << randNum << ", ";
                }
                else
                    file << randNum;
            }
            file.close();
            break;
        }
        case 7: {
            file.open(fileName[i], ios::app);
            for (int j = 0; j < 400000; j++) {
                int randNum = (rand() % 1000001); //generates a value between 0 and 1 million
                if (j != 399999) {
                    file << randNum << ", ";
                }
                else
                    file << randNum;
            }
            file.close();
            break;
        case 8: {
            file.open(fileName[i], ios::app);
            for (int j = 0; j < 800000; j++) {
                int randNum = (rand() % 1000001); //generates a value between 0 and 1 million
                if (j != 799999) {
                    file << randNum << ", ";
                }
                else
                    file << randNum;
            }
            file.close();
            break;
        }
        case 9: {
            file.open(fileName[i], ios::app);
            for (int j = 0; j < 10000000; j++) {
                int randNum = (rand() % 1000001); //generates a value between 0 and 1 million
                if (j != 999999) {
                    file << randNum << ", ";
                }
                else
                    file << randNum;
            }
            file.close();
            break;
        }
        }
    }
}
}
void GenerateSortedInputFiles(){ //the purpose of this function is to generate files with a specific amount of numbers per file in ascending order
	
    string fileName[] = { "1000Sorted.txt","4000Sorted.txt", "8000Sorted.txt", "10000Sorted.txt", "40000Sorted.txt", "80000Sorted.txt", "100000Sorted.txt", "400000Sorted.txt", "800000Sorted.txt", "1000000Sorted.txt" };
    //create a string of file names
    for (int i = 0; i < 10; i++) { //loop to create files fr
        fstream file; //call on file class to create/read/write files 
        file.open(fileName[i], ios::out); //create file, give it a name from string array and open it for output/append operations

        if (!file) { //the purpose of this function is to generate files with a specific range of numbers per file in ascending order
            cout << "\nFile " << fileName[i] << " not created. Please try again." << endl; //if the file is not created the program will inform you which one wasnt created 
        }
        else {
            cout << "File " << fileName[i] << " created successfully!" << endl; //program will inform if the file was created successfully
        }
        file.close(); //close file for saftey

        switch (i) { //swtich statement will populate each file with a different specified range of numbers in ascending order
        case 0: { //fileName[0] will be opened and have values 1 to 1000 input into it
            file.open(fileName[i], ios::out); //reopen the specific file to write into it
            for (int j = 1; j <= 1000; j++) { //for loop for values between 1 to 1000 in ascending order
                if (j != 1000) { //if the loop is not on its last iteration a comma will be printed after each numnber
                    file << j << ", ";
                }
                else { //if the loop is on its last iteration a comma will not be printed since its the last numner
                    file << j;
                }
            }
            file.close(); //close the file after writing for safely storing it
            break; //break after the case is finished so the program can go back to the first for loop to create the next file
        }
        case 1: {
            file.open(fileName[i], ios::out);
            for (int j = 1; j <= 4000; j++) {
                if (j != 4000) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        case 2: {
            file.open(fileName[i], ios::out);
            for (int j = 1; j <= 8000; j++) {
                if (j != 8000) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        case 3: {
            file.open(fileName[i], ios::out);
            for (int j = 1; j <= 10000; j++) {
                if (j != 10000) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        case 4: {
            file.open(fileName[i], ios::out);
            for (int j = 1; j <= 40000; j++) {
                if (j != 40000) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        case 5: {
            file.open(fileName[i], ios::out);
            for (int j = 1; j <= 80000; j++) {
                if (j != 80000) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        case 6: {
            file.open(fileName[i], ios::out);
            for (int j = 1; j <= 100000; j++) {
                if (j != 100000) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        case 7: {
            file.open(fileName[i], ios::out);
            for (int j = 1; j <= 400000; j++) {
                if (j != 400000) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        case 8: {
            file.open(fileName[i], ios::out);
            for (int j = 1; j <= 800000; j++) {
                if (j != 800000) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        case 9: {
            file.open(fileName[i], ios::out);
            for (int j = 1; j <= 10000000; j++) {
                if (j != 10000000) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        }
    }

}
void GenerateReverseInputFiles(){ //the purpose of this function is to generate files with a specific range of numbers per file in descending order

	string fileName[] = { "1000Reverse.txt","4000Reverse.txt", "8000Reverse.txt", "10000Reverse.txt", "40000Reverse.txt", "80000Reverse.txt", "100000Reverse.txt", "400000Reverse.txt", "800000Reverse.txt", "1000000Reverse.txt" };
    //create a string array of file names
    for (int i = 0; i < 10; i++) { //loop to create certain amount of files
        fstream file; //call on file class to create/read/write files
        file.open(fileName[i], ios::out); //create file, give it a name from string array and open it for output/append operations

        if (!file) { //if a file is not created you will be notified with which file wasnt created
            cout << "\nFile " << fileName[i] << " not created. Please try again." << endl;
        }
        else {
            cout << "File " << fileName[i] << " created successfully!" << endl; //will output to screen that file was created successfully
        }
        file.close(); //closes files after for loop to ensure safety of file

        switch (i) { //switch statement based on which file is in the current iteration of the for loop, switch statement will have cases to input values into the file within a range
        case 0: { //fileName[0] will have values between 1 to 1000 in descending order
            file.open(fileName[i], ios::out); //reopen ti file for writing
            for (int j = 1000; j > 0 ; j--) { //loop will iterate from 1000 to 1
                if (j != 1) { //if the value is not 1 it will be input into the file with a comma after the value
                    file << j << ", ";
                }
                else { //if the value is 1 only the value will be input into the file, without a comma
                    file << j;
                }
            }
            file.close(); //close the file after each case to save the file safely
            break; //ends the iteration of the case and goes back to the first for loop to go to the next file
        }
        case 1: {
            file.open(fileName[i], ios::out);
            for (int j = 4000; j > 0 ; j--) {
                if (j != 1) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        case 2: {
            file.open(fileName[i], ios::out);
            for (int j = 8000; j > 0; j--) {
                if (j != 1) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        case 3: {
            file.open(fileName[i], ios::out);
            for (int j = 10000; j > 0 ; j--) {
                if (j != 1) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        case 4: {
            file.open(fileName[i], ios::out);
            for (int j = 40000; j > 0; j--) {
                if (j != 1) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        case 5: {
            file.open(fileName[i], ios::out);
            for (int j = 80000; j > 0 ; j--) {
                if (j != 1) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        case 6: {
            file.open(fileName[i], ios::out);
            for (int j = 100000; j > 0 ; j--) {
                if (j != 1) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        case 7: {
            file.open(fileName[i], ios::out);
            for (int j = 400000; j > 0 ; j--) {
                if (j != 1) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        case 8: {
            file.open(fileName[i], ios::out);
            for (int j = 800000; j > 0 ; j--) {
                if (j != 1) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        case 9: {
            file.open(fileName[i], ios::out);
            for (int j = 10000000; j > 0 ; j--) {
                if (j != 1) {
                    file << j << ", ";
                }
                else
                    file << j;
            }
            file.close();
            break;
        }
        }
    }

}

int* createArray(int i){
	 fstream file;
	 string data;
	 int num = 0;
	 int size = 0;
	 int j, min, value;
	 int numSizes = 0;
	 int arraySize[29];
	 int *ptrSize = arraySize;
	 stringstream ss;
	 int numArrays = 30;
	 string fileName[] = { "1000Sorted.txt","1000Random.txt","1000Reverse.txt","4000Sorted.txt", "4000Random.txt", "4000Reverse.txt","8000Sorted.txt", "8000Random.txt", "8000Reverse.txt", "10000Sorted.txt", "10000Random.txt", "10000Reverse.txt",
	 "40000Sorted.txt", "40000Random.txt", "40000Reverse.txt","80000Sorted.txt", "80000Random.txt", "80000Reverse.txt","100000Sorted.txt", "100000Random.txt", "100000Reverse.txt","400000Sorted.txt", "400000Random.txt", "400000Reverse.txt",
	 "800000Sorted.txt", "800000Random.txt",  "800000Reverse.txt","1000000Sorted.txt",  "1000000Random.txt",  "1000000Reverse.txt"};
	                                 
        if (!file) { //the purpose of this function is to generate files with a specific range of numbers per file in ascending order
            cout << "\nFile " << fileName[i] << " not created. Please try again." << endl; //if the file is not created the program will inform you which one wasnt created 
        }
        else {
            cout << "File " << fileName[i] << " Successfully opened\n\n";
        }
    	switch (i) { 
	        case 0: { 	//1000sorted
        		file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[999];
					for(i = 0; i<1000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;	
					}
					return arr; 
				}
            	file.close();
            	break; 
        	}
        	case 1: { 	//1000random
            	file.open(fileName[i], ios::in);
            		while(!file.eof()){
					static int arr[999];
					for(i = 0; i<1000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
        	}
        	case 2: {  	//1000reverse
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[999];
					for(i = 0; i<8000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
        	}
       		case 3: {	//4000sorted
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[3999];
					for(i = 0; i<4000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
        	}
        	case 4: {	//4000random
            	file.open(fileName[i], ios::in);
        	    while(!file.eof()){
					static int arr[3999];
					for(i = 0; i<4000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
      		}
        	case 5: {	//4000reverse
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[3999];
					for(i = 0; i<4000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
       	 	}
        	case 6: {	//8000sorted
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[7999];
					for(i = 0; i<8000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
       		 }
        	case 7: {	//8000random
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[7999];
					for(i = 0; i<8000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
     	   }
        	case 8: {	//8000reverse
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[7999];
					for(i = 0; i<8000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					
					return arr;
				}
            	file.close(); 
            	break; 
        	}
        	case 9: {	//10ksorted
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[9999];
					for(i = 0; i<10000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
       		}
       		case 10:{   //10krandom
        		file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[9999];
					for(i = 0; i<10000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr; 	
					}
            	file.close(); 
            	break; 
        	}
        	case 11:{	//10kreverse
            	file.open(fileName[i], ios::in);
            		while(!file.eof()){
					static int arr[9999];
					for(i = 0; i<10000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
        	}
        	case 12:{	//40ksorted
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[39999];
					for(i = 0; i<40000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
        	}
       		case 13:{	//40krandom
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[39999];
					for(i = 0; i<40000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
        	}
        	case 14:{	//40kreverse
            	file.open(fileName[i], ios::in);
        	    while(!file.eof()){
					static int arr[39999];
					for(i = 0; i<40000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
      		}
        	case 15:{	//80ksorted
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[79999];
					for(i = 0; i<80000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
       	 	}
        	case 16:{	//80krandom
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[79999];
					for(i = 0; i<80000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
       		 }
        	case 17:{	//80kreverse
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[79999];
					for(i = 0; i<80000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
     	   }
        	case 18:{	//100ksorted
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[99999];
					for(i = 0; i<100000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					
					return arr;
				}
            	file.close(); 
            	break; 
        	}
        	case 19:{	//100krandom
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[99999];
					for(i = 0; i<100000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
       		}
       		case 20:{ 	//100kreverse
        		file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[99999];
					for(i = 0; i<100000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;	
					}
            	file.close(); 
            	break; 
        	}
        	case 21:{	//400ksorted
            	file.open(fileName[i], ios::in);
            		while(!file.eof()){
					static int arr[399999];
					for(i = 0; i<400000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
        	}
        	case 22:{	//400krandom
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[399999];
					for(i = 0; i<400000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
        	}
       		case 23:{	//400kreverse
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[399999];
					for(i = 0; i<400000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
        	}
        	case 24:{	//800ksorted
            	file.open(fileName[i], ios::in);
        	    while(!file.eof()){
					static int arr[799999];
					for(i = 0; i<800000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
      		}
        	case 25:{	//800krandom
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[799999];
					for(i = 0; i<800000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
       	 	}
        	case 26:{	//800kreverse
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[799999];
					for(i = 0; i<800000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
       		 }
        	case 27:{	//1000ksorted
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[999999];
					for(i = 0; i<1000000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
     	   }
        	case 28:{	//1000krandom
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[999999];
					for(i = 0; i<1000000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					
					return arr;
				}
            	file.close(); 
            	break; 
        	}
        	case 29:{	//1000kreverse
            	file.open(fileName[i], ios::in);
            	while(!file.eof()){
					static int arr[999999];
					for(i = 0; i<1000000; i ++){
						getline(file, data, ',');
						ss >> data;
						ss << data;
						num = stoi(data);
						arr[i] = num;
					}
					return arr;
				}
            	file.close(); 
            	break; 
       		}
       	}
    return 0;   	
}

void SelectionSort(int arr[], int arrayLength){
	int i, j, min, value;
		auto start = high_resolution_clock::now();
		 for(i=0; i<arrayLength-1 ; i++){
    		min = i;
    		for(j = i + 1; j < arrayLength; j++){
      			if(arr[j] < arr[min]){
        		min = j;
      			}
      		swap(arr[min], arr[i]);
    		}
  		}
  		auto stop = high_resolution_clock::now();
  		auto duration = duration_cast<milliseconds>(stop-start);
  		
  		cout << "\n\nSorted Array:\n";
  		for(i = 0; i < arrayLength; i++){
			cout << arr[i] << " ";
		}
		cout << "\n\nTime taken to Selection Sort: " << duration.count() << " milliseconds" << endl;
}
void BubbleSort(int arr[], int arrayLength){
	int count = 0;
	auto start = high_resolution_clock::now();
	
	for(int i = 0; i< arrayLength-1; i++){
		count++;
		int flag = false;
		for(int j = 0; j< arrayLength-i-1; j++){
			flag = true;
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
		if(flag == false){
			break;
		}
	}
	auto stop = high_resolution_clock::now();
  	auto duration = duration_cast<milliseconds>(stop-start);
  	
  	cout << "\n\nSorted Array:\n";
  		for(int i = 0; i < arrayLength; i++){
			cout << arr[i] << " ";
		}
  	
  	cout << "\n\nTime taken to Bubble Sort: " << duration.count() << " milliseconds" << endl;
}
void InsertionSort(int arr[], int arrayLength){
	int temp, i , j;
	
	auto start = high_resolution_clock::now();
	
	for(i = 1; i < arrayLength; i++){
		temp = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > temp){
			arr[j + 1] = arr[j];
			j = j - 1; 
		}
		arr[j + 1] = temp;
	}
	auto stop = high_resolution_clock::now();
  	auto duration = duration_cast<milliseconds>(stop-start);
  	
  	cout << "\n\nSorted Array:\n";
  		for(int i = 0; i < arrayLength; i++){
			cout << arr[i] << " ";
		}
  	
  	cout << "\n\nTime taken to Insertion Sort: " << duration.count() << " milliseconds" << endl;
}
void Merge(int arr[], int low, int high, int mid){
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k;
	int num = high-low+1;
	int* temp = new int[num];
	
	i = low;
	k = 0;
	j = mid + 1;
 
	while (i <= mid && j <= high){ // Merge the two parts into temp[]
		if (arr[i] < arr[j]){
			temp[k] = arr[i];
			k++;
			i++;
		}
		else{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}
	while (i <= mid){ // Insert all the remaining values from i to mid into temp[].
		temp[k] = arr[i];
		k++;
		i++;
	} 
	while (j <= high){ // Insert all the remaining values from j to high into temp[].
		temp[k] = arr[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++){ // Assign sorted data stored in temp[] to a[].
		arr[i] = temp[i-low];
	}
	delete[] temp;
}
void MergeSort(int arr[], int low, int high){ // A function to split array into two parts.
	int mid;
	if (low < high)	{
		mid=(low+high)/2; // Split the data into two half.
		
		MergeSort(arr, low, mid);
		MergeSort(arr, mid+1, high);
		
		Merge(arr, low, high, mid); // Merge them to get sorted output.
	}
}
void heapify(int arr[], int n, int root){
	int largest = root; //root is the largest element
	int left = 2*root + 1; 
	int right = 2*root + 2; 
	
	if(left < n && arr[left] > arr[largest]){ //if left value is larger than root
		largest = left; 
	}
	if(right < n && arr[right] > arr[largest]){ //if right value is larger than root
		largest = right;
	}
	if(largest != root){ //if largest is not root then swap the values
		swap(arr[root], arr[largest]);
		heapify(arr, n, largest); //recursively call heapify again
	}
}
void HeapSort(int arr[], int n){
	for(int i = n/2 - 1; i >= 0; i--){ //building heap
		heapify(arr, n, i);
	}
	for(int i = n-1; i >= 0; i--){ //removing elements from heap one by one
		swap(arr[0], arr[i]); //move the current root to the end
		heapify(arr, i, 0); //call heapify on the reduced heap
	}
}
void swap(int* a, int* b){
	int x = *a;
	*a = *b;
	*b = x;
}
int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int right = low - 1;	//index of smaller elements
	swap(&arr[right + 1], &arr[high]);
	return(right + 1);
}
void QuickSort(int arr[], int startIndex, int endIndex){
	while(startIndex < endIndex){
		
		int part = partition(arr, startIndex, endIndex);
		
		if(part - startIndex < endIndex - part){ //if left side is smaller then recur left and handle right iteratively
			QuickSort(arr, startIndex, part - 1);
			startIndex = part + 1;
		}
		else{ //else recur for right side
			QuickSort(arr, part + 1, endIndex);
			endIndex = part - 1;
		}
		
	}
}


int main() {
    
	GenerateRandomInputFiles(); //main calls random number input generator function
	GenerateSortedInputFiles();	//main calls sorted number input generator function
 	GenerateReverseInputFiles(); //main calls reverse sorted number input generator function
    
    cout<<"Please select from the following options by entering the corresponding number: \n"<<endl;
    cout<<"0.  1000Sorted.txt \t\t 1.  1000Random.txt \t\t 2.  1000Reverse.txt\n"<<
		  "3.  4000Sorted.txt \t\t 4.  4000Random.txt \t\t 5.  4000Reverse.txt\n"<<
		  "6.  8000Sorted.txt \t\t 7.  8000Random.txt \t\t 8.  8000Reverse.txt\n"<<
		  "9.  10000Sorted.txt \t\t 10. 10000Random.txt \t\t 11. 10000Reverse.txt\n"<<
		  "12. 40000Sorted.txt \t\t 13. 40000Random.txt \t\t 14. 40000Reverse.txt\n"<<
		  "15. 80000Sorted.txt \t\t 16. 80000Random.txt \t\t 17. 80000Reverse.txt\n"<<
		  "18. 100000Sorted.txt \t\t 19. 100000Random.txt \t\t 20. 100000Reverse.txt\n"<<
		  "21. 400000Sorted.txt \t\t 22. 400000Random.txt \t\t 23. 400000Reverse.txt\n"<<
		  "24. 800000Sorted.txt \t\t 25. 800000Random.txt \t\t 26. 800000Reverse.txt\n"<<
		  "27. 1000000Sorted.txt \t\t 28. 1000000Random.txt \t\t 29. 1000000Reverse.txt\n"<<
		  "30. Exit program\n"<<endl;
	
	int option, algo, size; 
	int size1k = 1000, size4k = 4000, size8k = 8000, size10k = 10000, size40k = 40000, size80k = 80000,
		size100k = 100000, size400k = 400000, size800k = 800000, size1000k = 1000000;
	int* create; 

	cin>>option; 
	
	if(option == 30){
		cout << "Program will exit now. Thank you. \n"<<endl;
		exit(0);
	}
	while(option != 30){
		if(option == 0 || option == 1 || option == 2){
		  	size = size1k;
		  }
		else if(option == 3 || option == 4 || option == 5){
		  	size = size4k;
		  }	
		else if(option == 6 || option == 7 || option == 8){
		  	size = size8k;
		  }	
		else if(option == 9 || option == 10 || option == 11){
		  	size = size10k;
		  }
		else if(option == 12 || option == 13 || option == 14){
		  	size = size40k;
		  }
		else if(option == 15 || option == 16 || option == 17){
		  	size = size80k;
		  }	
		else if(option == 18 || option == 19 || option == 20){
		  	size = size100k;
		  }	
		else if(option == 21 || option == 22 || option == 23){
		  	size = size400k;
		  }	
		else if(option == 24 || option == 25 || option == 26){
		  	size = size800k;
		  }	
		else if(option == 27 || option == 28 || option == 29){
		  	size = size1000k;
		  }			
		  
		create = createArray(option);
		  
		cout<<"Which Sorting algorithm would you like to calculate? \n"<<
		  	   "1. Selection sort \n2. Bubble Sort \n3. Insertion Sort \n4. Merge Sort \n5. Heap Sort \n6. Quick Sort \n"<<endl;
		  	cin>>algo;
		  	switch(algo){
		  		case 1:{
		  			SelectionSort(create, size);
					break;
				}
				case 2:{
					BubbleSort(create, size);
					break;
				}
				case 3:{
					InsertionSort(create, size);
					break;
				}
				case 4:{
					auto start = high_resolution_clock::now();
					MergeSort(create, 0, size-1);
					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<milliseconds>(stop-start);
	
					cout << "\n\nSorted Array:\n";
  					for(int i = 0; i < size; i++){
						cout << create[i] << " ";
					}
					cout << "\n\nTime taken to Merge Sort: " << duration.count() << " milliseconds" << endl;	
					break;
				}
				case 5:{
					auto start = high_resolution_clock::now();
					HeapSort(create, size);
					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<milliseconds>(stop-start);
	
					cout << "\n\nSorted Array:\n";
  					for(int i = 0; i < size; i++){
						cout << create[i] << " ";
					}
					cout << "\n\nTime taken to Heap Sort: " << duration.count() << " milliseconds" << endl;	
					break;
				}
				case 6:{
					auto start = high_resolution_clock::now();
					QuickSort(create, 0, size-1);
					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<milliseconds>(stop-start);
	
					cout << "\n\nSorted Array:\n";
  					for(int i = 0; i < size; i++){
						cout << create[i] << " ";
					}
					cout << "\n\nTime taken to Quick Sort: " << duration.count() << " milliseconds" << endl;	
					break;
				}
			}
		cout<<"Please select from the following options by entering the corresponding number: \n"<<endl;
		cout<<"0.  1000Sorted.txt \t\t 1.  1000Random.txt \t\t 2.  1000Reverse.txt\n"<<
		  "3.  4000Sorted.txt \t\t 4.  4000Random.txt \t\t 5.  4000Reverse.txt\n"<<
		  "6.  8000Sorted.txt \t\t 7.  8000Random.txt \t\t 8.  8000Reverse.txt\n"<<
		  "9.  10000Sorted.txt \t\t 10. 10000Random.txt \t\t 11. 10000Reverse.txt\n"<<
		  "12. 40000Sorted.txt \t\t 13. 40000Random.txt \t\t 14. 40000Reverse.txt\n"<<
		  "15. 80000Sorted.txt \t\t 16. 80000Random.txt \t\t 17. 80000Reverse.txt\n"<<
		  "18. 100000Sorted.txt \t\t 19. 100000Random.txt \t\t 20. 100000Reverse.txt\n"<<
		  "21. 400000Sorted.txt \t\t 22. 400000Random.txt \t\t 23. 400000Reverse.txt\n"<<
		  "24. 800000Sorted.txt \t\t 25. 800000Random.txt \t\t 26. 800000Reverse.txt\n"<<
		  "27. 1000000Sorted.txt \t\t 28. 1000000Random.txt \t\t 29. 1000000Reverse.txt\n"<<
		  "30. Exit program\n"<<endl;
		  cin>>option;
	}
}
