//
//  func.hpp
//  HW1
//
//  Created by Yonatan Glanzman on 28/10/2022.
//

#ifndef func_hpp
#define func_hpp

#include <iostream>

#endif /* Exp_hpp */


typedef struct Expression{
    char sign;
    char* arrNums[3];
}Expression;


void createExpression(Expression* &Exp);
void reverse(char str[], int length);
char* itoa(int num, char* str, int base);
void calculation(Expression* &Exp);
void printExpression( Expression* &Exp);
