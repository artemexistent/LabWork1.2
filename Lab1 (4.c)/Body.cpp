#pragma once
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "HeaderBIN&TXT.h"
#include "Header.h"

using namespace std;

struct Train{

    char number[4];
    char name[100];
    char type[20];
    char dateDep[5];
    char timeDep[5];
    char dateArr[5];
    char timeArr[5];
    double level;

};

void BIN( int answer );
void TXT( int answer );

int main()
{
    int key = StartMenu();
    int answer;
    do{
        answer = menu();
        switch (key){
            case 1: BIN( answer ); break;
            case 2: TXT( answer ); break;
        }
    }while( answer != 4 );
    return 0;
}


void BIN( int answer ){
    switch ( answer )
        {
            case 0: AddBIN(); break;
            case 1: DeleteBIN(); break;
            case 2: ViewBIN(); break;
            case 3: FinD( true ); break;
            case 4: cout << "You are logged out.\n"; return ;
        }
    return;
}

void TXT( int answer ){
    switch ( answer )
        {
            case 0: AddTXT(); break;
            case 1: DeleteTXT(); break;
            case 2: ViewTXT(); break;
            case 3: FinD( false ); break;
            case 4: cout << "You are logged out.\n"; return ;
        }
    return;
}
