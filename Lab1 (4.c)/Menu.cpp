#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include <windows.h>
#include "HeaderBIN&TXT.h"
#include "Header.h"

using namespace std;

int StartMenu() {
    int key = 0;
    int code;
    do {
        system( "cls" );
        cout << "Choose storage format:\n";
        key = ( key + 3 ) % 3;
        if ( key == 0 ) cout<<"-> Vector"<<endl;
            else  cout<<"   Vector"<<endl;
        if ( key == 1 ) cout<<"-> BinFile"<<endl;
            else  cout<<"   BinFile"<<endl;
        if ( key == 2 ) cout<<"-> TxtFile"<<endl;
            else  cout<<"   TxtFile"<<endl;
        code = _getch();
        if ( code == 224 ){
            code = _getch();
            if ( code == 80 ) key ++;
            if ( code == 72 ) key --;
        }
    }while( code != 13 );
    system( "cls" );
    return key;
}

int menu() {
    int key = 0;
    int code;
    do {
        system( "cls" );
        key = ( key + 5 ) % 5;
        if ( key == 0 ) cout<<"-> Add new train"<<endl;
            else  cout<<"   Add new train"<<endl;
        if ( key == 1 ) cout<<"-> Delete train"<<endl;
            else  cout<<"   Delete train"<<endl;
        if ( key == 2 ) cout<<"-> View all trains"<<endl;
            else  cout<<"   View all trains"<<endl;
        if ( key == 3 ) cout<<"-> Find a train"<<endl;
            else  cout<<"   Find a train"<<endl;
        if ( key == 4 ) cout<<"-> Sign Out"<<endl;
            else  cout<<"   Sign Out"<<endl;
        code = _getch();
        if ( code == 224 ){
            code = _getch();
            if ( code == 80 ) key ++;
            if ( code == 72 ) key --;
        }
    }while( code != 13 );
    system( "cls" );
    return key;
}

int menu2(){
    int key = 0;
    int code;
    do {
        system( "cls" );
        cout << " Search for a train:\n";
        key = ( key + 4 ) % 4;
        if ( key == 0 ) cout<<"-> by name beginning"<<endl;
            else  cout<<"   by name beginning"<<endl;
        if ( key == 1 ) cout<<"-> not less than the specified number and  no more than a given level of popularity"<<endl;
            else  cout<<"   not less than the specified number and  no more than a given level of popularity"<<endl;
        if ( key == 2 ) cout<<"-> in a given date and time range"<<endl;
            else  cout<<"   in a given date and time range"<<endl;
        if ( key == 3 ) cout << "-> Back" << endl;
            else cout << "   Back" << endl;
        code = _getch();
        if ( code == 224 ){
            code = _getch();
            if ( code == 80 ) key ++;
            if ( code == 72 ) key --;
        }
    }while( code != 13 );
    system( "cls" );
    return key;
}

