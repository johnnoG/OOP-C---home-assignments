//
//  DataFile.hpp
//  HW2
//
//  Created by Yonatan Glanzman on 12/11/2022.
//

#ifndef DataFile_hpp
#define DataFile_hpp

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class DataFile{
    char* FileName;
    tm LastUpdateTime;
    char* Data;
    float getSize() const;
    
public:
    /* Constructors declaration */
    DataFile(char* FileName ,char* Data);
    DataFile();
    DataFile(const DataFile & NDataFile);
    ~DataFile();
    
    /* Methods declaration */
    const DataFile & operator=(const DataFile& other);
    void setData(char* Data);
    char* getData() const;
    void setFileName(char* FileName);
    char* getFileName() const;
    void setTime();
    char* getTime() const;
    void dir() const;
    bool IsEmpty(int arrsize);
    void addfile(DataFile &Nfile,DataFile** &Filesarr ,int &Filesamount,int &MaxFilesAmount);
    

};



#endif /* DataFile_hpp */

