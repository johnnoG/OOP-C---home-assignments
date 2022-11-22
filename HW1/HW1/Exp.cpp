//
//  func.cpp
//  HW1
//
//  Created by Yonatan Glanzman on 28/10/2022.
//

#include "Exp.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;


void createExpression(Expression* &Exp){
    for (int i = 0; i < 2; i++) {
        
        cout << "enter the "<< i+1 <<" number: " << endl;
        int number;
        cin >> number;
        
//      using a temporery array to convert integer to sring
        char tmp[30];
        itoa(number, tmp, 10);
        int strsize = (int)strlen(tmp);
        
//      allocting a specific size to the string secondary arry
        char *str = new char[strsize + 1];
        strcpy(str, tmp);
        
//      initializing the first to spots of the primary array
        Exp->arrNums[i] = str;
        delete [] str ;
    }
    
    cout << "enter the mathematical operation you wish to perform: " << endl;
    cin >> Exp->sign;
}

void calculation( Expression* &Exp){
    int num1;
    int num2;
    int result;
    int strsize;
    char tmp[30];
    char* str = NULL;
    
    switch (Exp->sign) {
        case '-':
//          converting strings to integers
            num1 = atoi(Exp->arrNums[0]);
            num2 = atoi(Exp->arrNums[1]);
            
//          saving the absulut value of the result
            result = abs(num1 - num2);
            
//          converting integer to sring
            
            itoa(result, tmp, 10);
            strsize = (int)strlen(tmp);
            
//          allocting a specific size to the string secondary arry
            str = new char[strsize + 1];
            strcpy(str, tmp);
//          initializing the first to spots of the primary array
            Exp->arrNums[2] = str;
            delete [] str ;
            break;
            
        case '+':
//          converting strings to integers
            num1 = atoi(Exp->arrNums[0]);
            num2 = atoi(Exp->arrNums[1]);
                        
//          saving the absulut value of the result
            result = abs(num1 + num2);
                        
//          using a temporery array to convert integer to sring
            
            itoa(result, tmp, 10);
            strsize = (int)strlen(tmp);
                    
//          allocting a specific size to the string secondary arry
            str = new char[strsize + 1];
            strcpy(str, tmp);
            Exp->arrNums[2] = str;
            delete [] str ;
            break;
            
        case '*':
//          converting strings to integers
            num1 = atoi(Exp->arrNums[0]);
            num2 = atoi(Exp->arrNums[1]);
                        
//          saving the absulut value of the result
            result = abs(num1 * num2);
                        
//          using a temporery array to convert integer to sring
            
            itoa(result, tmp, 10);
            strsize = (int)strlen(tmp);
                    
//          allocting a specific size to the string secondary arry
            str = new char[strsize + 1];
            strcpy(str, tmp);
            Exp->arrNums[2] = str;
            delete [] str ;
            break;
            
        case '/':
//          converting strings to integers
            num1 = atoi(Exp->arrNums[0]);
            num2 = atoi(Exp->arrNums[1]);
            
            if (num2 == 0) {
                cout << "Sorry, deviding by 0 is not allowed \n please try again"<< endl;
                break;
            }
                        
//          saving the absulut value of the result
            result = abs(num1 / num2);
                        
//          using a temporery array to convert integer to sring
            
            itoa(result, tmp, 10);
            strsize = (int)strlen(tmp);
                    
//          allocting a specific size to the string secondary arry
            str = new char[strsize + 1];
            strcpy(str, tmp);
            Exp->arrNums[2] = str;
            delete [] str ;
            break;
            
        case '%':
//          converting strings to integers
            num1 = atoi(Exp->arrNums[0]);
            num2 = atoi(Exp->arrNums[1]);
                        
//          saving the absulut value of the result
            result = abs(num1 % num2);
                        
//          using a temporery array to convert integer to sring
            
            itoa(result, tmp, 10);
            strsize = (int)strlen(tmp);
                    
//          allocting a specific size to the string secondary arry
            str = new char[strsize + 1];
            strcpy(str, tmp);
            Exp->arrNums[2] = str;
            delete [] str ;
            break;
            
        default:
            cout << "no action performed, exiting program" << endl;
            break;
    }
    
}

void printExpression(Expression* & Exp){
    if (!Exp->arrNums[2]) {
        cout << "Sorry, can't perform expression wanted" << endl;
        exit(0);
    }
    cout << "The absulut value of your expression is: " << Exp->arrNums[0] << " " <<  Exp->sign << " " << Exp->arrNums[1] << " = " << Exp->arrNums[2] << endl;
}








// private functions!!
void reverse(char str[], int length){
    int start = 0;
    int end = length -1;
    while (start < end){
        swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}

// Implementation of itoa()
char* itoa(int num, char* str, int base){
    int i = 0;
    bool isNegative = false;

    /* Handle 0 explicitly, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }
    // Process individual digits
        while (num != 0){
            int rem = num % base;
            str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
            num = num/base;
        }

        // If number is negative, append '-'
        if (isNegative){
            str[i++] = '-';
        }
        str[i] = '\0'; // Append string terminator

        // Reverse the string
        reverse(str, i);
        return str;
    }


