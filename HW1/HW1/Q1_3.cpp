//
//  Q1_3.cpp
//  HW1
//
//  Created by Yonatan Glanzman on 29/10/2022.
//


#include <iostream>
#include <cstdlib>
#include <cstring>
#include "sentence.hpp"

using namespace std;

int main(){
    char str[] = "hi my name is yonatan" ;
    int size;
    char** Wstr = SplitSentence(str, &size);
    
    for (int i = 0 ; i < size; i++) {
        Wstr[i] = multiply(Wstr[i]);
        cout << "array " << i+1 << " place is : " << Wstr[i] << endl;
    }
    
    for (int  i = 0 ; i< size ; i++ ){
        delete [] Wstr[i];
    }
    delete [] Wstr;
}
