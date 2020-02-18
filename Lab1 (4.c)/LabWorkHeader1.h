#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include <windows.h>
#include "Find.h"
using namespace std;


void Add(){

    system("cls");

    Train train;
    cout << "Enter:";
    cout << "\n   train number(four-digit number):"; cin >> train.number;
    cout << "\n   optional train name:"; cin >> train.name;
    cout << "\n   type of train(international, high-speed, ordinary, suburban):"; cin >> train.type;
    cout << "\n   date of departure:"; cin >> train.dateDep;
    cout << "\n   time of departure:"; cin >> train.timeDep;
    cout << "\n   date of arrival:"; cin >> train.dateArr;
    cout << "\n   time of arrival:"; cin >> train.timeArr;
    cout << "\n   level of popularity of tickets:"; cin >> train.level;

    system("cls");

    FILE * ptrFile = fopen("Train.bin", "ab");

    fwrite(&train,1, sizeof(Train), ptrFile);

    fclose(ptrFile);

    cout << "Train " << '"' << train.name << '"' <<" was successfully added.\n";
    system("pause");
    return;
}


void Delete(){

     system("cls");

      FILE * ptrFile = fopen("Train.txt", "rb");

     string number;

     cout << "Enter the train number you want to delete:"; cin >> number;

     vector <Train> base;
     Train info;
       int i=0;

    bool f=true;

    while (true){


        fseek(ptrFile,(sizeof(Train)*i),SEEK_SET);

        fread(&info,sizeof(Train),1,ptrFile);

        base.push_back(info);

        if (feof(ptrFile))
            break;

        i++;
    }

    fclose(ptrFile);

    remove("Train.txt");

    FILE * ptrFil = fopen("Train.txt", "ab");

    for (int i=0;i<base.size();i++){
        if (base[i].number!=number)
        fwrite(&base[i],1, sizeof(Train), ptrFil );

    }

    fclose(ptrFil);

        cout << "Train removed.\n";
        system("pause");

        return;


}



void View(){


    FILE * ptrFile = fopen("Train.bin", "rb");

    Train info;

    while (true){

        fread(&info,sizeof(Train),1,ptrFile);

        if (feof(ptrFile))
            break;

        cout << info.number << "   " << info.name << "   " << info.type << "   " << info.dateDep << "   " << info.timeDep << "   " << info.dateArr << "   " << info.timeArr << "   " << info.level << "\n";

    }

    fclose(ptrFile);

    system("pause");

    return;


}


