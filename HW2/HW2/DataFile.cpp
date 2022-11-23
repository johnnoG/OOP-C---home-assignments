//
//  DataFile.cpp
//  HW2
//
//  Created by Yonatan Glanzman on 12/11/2022.
//

#include "DataFile.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


/* Methods Execution  */
void DataFile:: setData(char* Data){
    
    if (!Data) {
        this->Data = NULL;
    }

    else{
        
        this->Data = new char(strlen(Data) + 1);
        strcpy(this->Data, Data);
    }
}

char* DataFile:: getData() const{
    return Data;
}

void DataFile:: setFileName(char* FileName){
    

    char key[] = "></\?:*";
    char* pch;
    pch = strpbrk (FileName, key);

        if(pch)
        {
            cout << "A file can't contain any of the following characters : (> < / \\ ? : *) , please try again."<< endl;
            
        }

    this->FileName = new char(strlen(FileName) + 1);
    strcpy(this->FileName, FileName);
    
}

char* DataFile:: getFileName() const{
    return FileName;
}
void DataFile:: setTime(){
    
    // current date/time based on current system
    time_t t1 = time(0);
    struct tm* now =localtime(&t1);
    LastUpdateTime = *now;
}

char* DataFile:: getTime() const{
    
    char buf[80];
    strftime(buf, sizeof(buf), "%d/%m/%Y %X", &LastUpdateTime);
    char* stringTime = new char[strlen(buf) + 1];
    strcpy(stringTime, buf);
    return stringTime;
}

float DataFile:: getSize() const{
    
    return strlen(this->Data)+1;
}

void DataFile:: dir() const{
    
    cout << getTime() << " " << getSize() / 1024 << " KB " << getFileName()<< ".txt"<<endl;
}

bool DataFile::IsEmpty(int arrsize){
    
    if (!arrsize) {
        cout << "There are no existing files" << endl;
        return true;
    }
    return false;
}



void DataFile:: addfile(DataFile& Nfile,DataFile** &Filesarr ,int &Filesamount,int &MaxFilesAmount){
    
    if (Filesamount == MaxFilesAmount) {
        //        increasing the size of the original arrey
        DataFile** NewArr = new DataFile* [MaxFilesAmount + 1];
        //copy the old values of Filearr into NewArr
        memcpy(NewArr, Filesarr, sizeof(DataFile)*(MaxFilesAmount+1));
        
        //        dealocating old arr
        delete [] Filesarr;
        
        Filesarr = NewArr;
        //        updating maxFilesAmount
        MaxFilesAmount = MaxFilesAmount + 1;
    }
    *Filesarr[Filesamount] = Nfile;
    Filesamount++;
}









/* Constructors execution */
DataFile:: DataFile() {
    
    char str[] = "somefile";
    char* data = NULL;
    setFileName(str);
    setData(data);
//    DataFile file(str,data);
    
}

DataFile:: DataFile(char* FileName ,char* Data){
    
    this->setFileName(FileName);
    this->setData(Data);
    this->setTime();
}

DataFile:: ~DataFile(){
    delete [] FileName;
    FileName = NULL;
    delete [] Data;
    Data = NULL;
    
}

DataFile:: DataFile(const DataFile & NDataFile){
    FileName = NULL;
    Data = NULL;
    *this = NDataFile;
}
const DataFile& DataFile:: operator=(const DataFile& other){
    
    if (this != &other) {
        
        delete [] FileName;
        setFileName(other.FileName);
        
        
        LastUpdateTime = other.LastUpdateTime;
        
        delete [] Data;
        setData(other.Data);
        
    }
    return *this;
}


