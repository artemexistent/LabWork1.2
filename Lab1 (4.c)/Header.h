#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <conio.h>
#include <vector>
#include <windows.h>
#include <time.h>
#include "HeaderBIN&TXT.h"

using namespace std;
struct Train{
    char number[6]={'0'};
    char name[100]={'0'};
    char type[20]={'0'};
    char dateDep[7]={'0'};
    char timeDep[7]={'0'};
    char dateArr[7]={'0'};
    char timeArr[7]={'0'};
    double level;
    int ID;

};
void Demo();
void Bech();

int Menu();

int StartMenu();

int menu();

int menu2();

void FinD( int key );

bool compname( char *a,char *b );

bool compdate( char *date11, char *date12, char *date21, char *date22,
              char *time11, char *time12, char *time21, char *time22 );

bool compnumbpopl( char * numb1, double lvl1, char *numb2, double lvl2 );

bool IfNumber( char *str );

bool IfTime( char *str );

bool IfType( char *str );

bool IfDate( char *str );

void InputNumber( char *str );

void InputName( char *str );

void InputType( char *str );

void InputDate( char *str );

void InputTime( char *str );
