//
//  sentence.cpp
//  HW1
//
//  Created by Yonatan Glanzman on 29/10/2022.
//

#include "sentence.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;


//סעיף א:
char** SplitSentence(char* str,int* size){
    
//    counting how many spaces() in the sentece to understand the number of words in it
    char* ptr;
    ptr = strpbrk(str, " ");
    int S_num = 0;
    
    while (ptr) {
        ptr = strpbrk(ptr+1, " ");
        S_num++;
    }

    *size = S_num + 1;
    char** wordstr = new char* [*size];
    //    Splitting sentence into words
    char* Wptr = strtok (str," ,.-");
    
    for (int i = 0; i<*size; i++) {
        if(!Wptr){
            break;
        }
        wordstr[i] = new char[strlen(Wptr)+1];
        strcpy(wordstr[i],Wptr);
        Wptr = strtok(NULL, " ,.-");
           
    }
    return wordstr;
}


//סעיף ב:

char* multiply(char* str){
    
    int newSize = ((int)strlen(str)*2) + 1;
    
    char* newStr = new char[newSize];
    strcpy(newStr, str);
    strcat(newStr,str);
    
    return newStr;

}
    
  
