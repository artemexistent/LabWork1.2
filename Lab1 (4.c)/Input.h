#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include <windows.h>
#include "Find.h"
using namespace std;

char numberSize = 5;
char dateSizetime = 6;
char nameSize = 100;
char typeSize = 20;

bool IfNumber( char *str );
bool IfTime( char *str );
bool IfType( char *str );
bool IfDate( char *str );

void InputNumber( char *str ){
  cin.getline( str, numberSize );
  while ( cin.fail() ) {
    cin.clear();
    cin.ignore( INT_MAX, '\n' );
    cout << "\tSo big word, enter less than " << (int)numberSize-1 << " symbols" << endl;
    cin.getline( str, numberSize );
  }
  while ( IfNumber( str ) ){
    cin.clear();
    cin.ignore( INT_MAX, '\n' );
    cout << "\tThis entry contains invalid characters. " << endl;
    cin.getline( str, numberSize );
  }
}

void InputName( char *str ) {
  cin.getline( str, nameSize );
  while ( cin.fail() ) {
    cin.clear();
    cin.ignore( INT_MAX, '\n' );
    cout << "\tSo big name, enter less than " << (int)nameSize << " symbols" << endl;
    cin.getline( str, nameSize );
  }
}

void InputType( char *str ) {
  cin.getline( str, typeSize );
  while ( IfType( str ) ){
    cin.clear();
    cin.ignore( INT_MAX, '\n' );
    cout << "\tThis type of train does not exist." << endl;
    cin.getline( str, typeSize );
  }
}

void InputDate( char *str ) {
  cin.getline( str, dateSizetime );
  while ( cin.fail() ) {
    cin.clear();
    cin.ignore( INT_MAX, '\n' );
    cout << "\tSo big name, enter less than " << (int)dateSizetime-1 << " symbols" << endl;
    cin.getline( str, dateSizetime );
  }
  while ( IfDate(str) ){
    cin.clear();
    cin.ignore( INT_MAX, '\n' );
    cout << "\tDate entered is incorrect (example date: 16.08 )"  << endl;
    cin.getline( str, dateSizetime );
  }
}

void InputTime( char *str ) {
  cin.getline( str, dateSizetime );
  while ( cin.fail() ) {
    cin.clear();
    cin.ignore( INT_MAX, '\n' );
    cout << "\tSo big name, enter less than " << (int)dateSizetime-1 << " symbols" << endl;
    cin.getline( str, dateSizetime );
  }
  while ( IfTime(str) ){
    cin.clear();
    cin.ignore( INT_MAX, '\n' );
    cout << "\tTime entered is incorrect (example Time: 16:08 )"  << endl;
    cin.getline( str, dateSizetime );
  }
}

bool IfNumber( char *str ){
    for ( int i = 0;i < 4;i ++ )
        if ( str[i] < '0' || str[i] > '9' )
            return 1;
    return 0;
}

bool IfDate( char *str ){
    if ( str[2] != '.' )
        return 1;
    if ( ( str[3] - '0' ) * 10 + str[4] - '0' > 12 )
        return 1;
    int daTe = ( str[0] - '0' ) * 10 + str[1] - '0';
    switch ( ( str[3] - '0' ) * 10 + str[4] - '0' ){
        case 1:  if ( daTe > 31 ) return 1;  break;
        case 2:  if ( daTe > 29 ) return 1;  break;
        case 3:  if ( daTe > 31 ) return 1;  break;
        case 4:  if ( daTe > 30 ) return 1;  break;
        case 5:  if ( daTe > 31 ) return 1;  break;
        case 6:  if ( daTe > 30 ) return 1;  break;
        case 7:  if ( daTe > 31 ) return 1;  break;
        case 8:  if ( daTe > 31 ) return 1;  break;
        case 9:  if ( daTe > 30 ) return 1;  break;
        case 10: if ( daTe > 31 ) return 1;  break;
        case 11: if ( daTe > 30 ) return 1;  break;
        case 12: if ( daTe > 31 ) return 1;  break;
    }
    return 0;
}

bool IfTime( char *str ){
    if ( str[2] != ':' )
        return 1;
    if ( ( str[3] - '0' ) * 10 + str[4] - '0' > 60 )
        return 1;
    if ( ( str[0] - '0' ) * 10 + str[1] - '0' > 24 )
        return 1;
    return 0;
}

bool IfType( char *str ){
    int sizeStr =  strlen( str );
    if ( sizeStr > 13 || sizeStr < 8 )
        return 1;
    if ( sizeStr == 8 ){
        bool f1 = 0, f2 = 0;
        string a =  "ordinary", b = "suburban";
        for ( int i = 0;i < 8 && f1 == 0;i ++ )
            if ( str[i] != a[i] )
                f1 = 1;
        for ( int i = 0;i < 8 && f2 == 0;i ++ )
            if ( str[i] != b[i] )
                f2 = 1;
        if ( f1 == f2 && f2 == 1 )
            return 1;
        return 0;
    }
    if ( sizeStr == 10 ){
        string a = "high-speed";
        for ( int i = 0;i < 10;i ++ )
            if ( str[i] != a[i] )
                return 1;
        return 0;
    }
    if ( sizeStr == 13 ){
        string a = "international";
        for ( int i = 0;i < 13;i ++ )
            if ( str[i] != a[i] )
                return 1;
        return 0;
    }
    return 0;
}


