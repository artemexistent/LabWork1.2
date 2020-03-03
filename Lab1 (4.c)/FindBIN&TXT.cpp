#pragma once
#include <iostream>
#include <cstdio>
#include <windows.h>
#include "HeaderBIN&TXT.h"
#include "Header.h"

using namespace std;

void FindBIN( char *name, char *numb, double popl, char *date1, char *date2, char *time1, char *time2, int key ){
    FILE *ptrFile = fopen( "Train.bin", "rb" );
    Train info;
    while ( true ){
        fread( &info, sizeof( Train ), 1, ptrFile );
        if ( feof( ptrFile ) )
            break;
        bool ans=0;
        switch ( key )
        {
            case 0: ans = compname( info.name, name ); break;
            case 1: ans = compnumbpopl( info.number, info.level, numb, popl ); break;
            case 2: ans = compdate( info.dateDep, info.dateArr, date1, date2, info.timeDep, info.timeArr, time1, time2 ); break;
        }
        if ( ans )
        cout << info.number << "   " << info.name << "   " << info.type << "   " << info.dateDep << "   " << info.timeDep << "   " << info.dateArr << "   " << info.timeArr << "   " << info.level << "\n";
    }
    fclose(ptrFile);
    system("pause");
    return;
}

void FindTXT( char *name, char *numb, double popl, char *date1, char *date2, char *time1, char *time2, int key ){
    FILE *ptrFile = fopen( "Train.txt", "r" );
    Train info;
    while ( true ){
        fread( &info, sizeof( Train ), 1, ptrFile );
        if ( feof( ptrFile ) )
            break;
        bool ans=0;
        switch ( key )
        {
            case 0: ans = compname( info.name, name ); break;
            case 1: ans = compnumbpopl( info.number, info.level, numb, popl ); break;
            case 2: ans = compdate( info.dateDep, info.dateArr, date1, date2, info.timeDep, info.timeArr, time1, time2 ); break;
        }
        if ( ans )
        cout << info.number << "   " << info.name << "   " << info.type << "   " << info.dateDep << "   " << info.timeDep << "   " << info.dateArr << "   " << info.timeArr << "   " << info.level << "\n";
    }
    fclose(ptrFile);
    system("pause");
    return;
}
