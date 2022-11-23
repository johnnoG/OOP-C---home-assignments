//
//  main.cpp
//  HW2
//
//  Created by Yonatan Glanzman on 12/11/2022.
//

#include "DataFile.hpp"




int main() {
    int FilesAmount = 0;
    int MaxFilesAmount = 0;
    DataFile** dataArr = new DataFile*[FilesAmount+1];
    DataFile newfile;
    char filename[30];
    char data[100];
    char name[50];
    int act;
    
    
    if (FilesAmount <= 0) {
        FilesAmount = 0;
    }
    do{
        cout <<"1. Print Files"<< endl;
        cout <<"2. Add File"<< endl;
        cout <<"3. Edit File"<< endl;
        cout <<"4. Exit"<< endl;
        cin >> act;
        switch (act) {
            case 1:
                
                if (dataArr[FilesAmount-1]->IsEmpty(FilesAmount)) {
                    break;
                }
                else{
                    for (int i = 0; i < FilesAmount; i++) {
                        cout << "file number " << i+1 << " is : ";
                        dataArr[i]->dir();
                        cout << "\n";
                    }
                }
                break;
                
            case 3:
                if (dataArr[FilesAmount-1]->IsEmpty(FilesAmount)) {
                    break;
                }
                else{
                    cout << "Inster file name to edit: " << endl;
                    cin.clear();
                    cin >> name;
                    int i = 0;
                    while (i < FilesAmount) {
                        if(!strcmp(dataArr[i]->getFileName(), name)){
                            char ndata[100];
                            cout << "Insert new data: " << endl;
                            cin.clear();
                            cin.getline(data,100,' ');
                            dataArr[i]->setData(ndata);
                            dataArr[i]->setTime();
                            break;
                        }
                        if(i == FilesAmount-1 && strcmp(dataArr[i]->getFileName(), name)){
                            cout << "The file was not found" << endl;
                            break;
                        }
                        i++;
                    }
                    
                    break;
                }
                case 2:
                    cout << "Enter file name : " << endl;
                    cin.clear();
                    cin >> filename;
                    newfile.setFileName(filename);
                    cout << "Enter file data: " << endl;
                    cin.clear();
                    cin.getline(data, 100,' ');
                    newfile.setData(data);
                    newfile.setTime();
                    dataArr[FilesAmount] = new DataFile[sizeof(DataFile*)];
                    dataArr[FilesAmount]->addfile(newfile, dataArr, FilesAmount, MaxFilesAmount);
                    newfile.~DataFile();
                    
                default:
                    break;
                }
        }while(act!=4);
        
        if (act == 4){
            delete [] dataArr;
            dataArr = NULL;
            cout << "Program has been deallocated successfully"<< endl;
        }
        return 0;
    }

