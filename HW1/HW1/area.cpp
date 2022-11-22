//
//  area.cpp
//  HW1
//
//  Created by Yonatan Glanzman on 28/10/2022.
//

#include "area.hpp"
#include <iostream>
#include <cmath>

using namespace std;
const  float PI = 3.14;

float area( float a, float b){
    float area = (a*b)/2;
    return area;
}

float area( float a, float b, float h){
    float area = (a+b)*h/2;
    return area;
}

float area(float R){
    float area = PI * pow(R,2);
    return area;
}

float area(double R, float r,float tmp, float tmp1){
    float area = PI* (pow(R,2) - pow(r,2));
    return area;
}
