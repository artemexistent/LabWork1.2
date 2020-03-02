#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include <windows.h>
#include "Find.h"

using namespace std;

void Add(){
    system( "cls" );
    Train train;
    cout << "Enter:";
    cout << "\n   train number(four-digit number):"; InputNumber( train.number );
    cout << "\n   optional train name:"; InputName( train.name );
    cout << "\n   type of train(international, high-speed, ordinary, suburban):"; InputType( train.type );
    cout << "\n   date of departure:"; InputDate( train.dateDep );
    cout << "\n   time of departure:"; InputTime( train.timeDep );
    cout << "\n   date of arrival:"; InputDate( train.dateArr );
    cout << "\n   time of arrival:"; InputTime( train.timeArr );
    cout << "\n   level of popularity of tickets:"; cin >> train.level;
    system( "cls" );
    FILE *ptrFile = fopen( "Train.bin", "ab" );
    fwrite( &train , 1, sizeof( Train ), ptrFile );
    fclose( ptrFile );
    cout << "Train " << '"' << train.name << '"' <<" was successfully added.\n";
    system( "pause" );
    return;
}

void Delete(){
     system( "cls" );
     FILE *ptrFile = fopen( "Train.bin", "rb" );
     char *number = new char[4];
     cout << "Enter the train number you want to delete:"; InputNumber( number );
     vector <Train> base;
     Train info;
     while (true){
        fread( &info, sizeof( Train ), 1, ptrFile );
        if ( feof ( ptrFile ) )
            break;
        base.push_back( info );
     }
     fclose( ptrFile );
     remove( "Train.bin" );
     FILE *ptrFil = fopen( "Train.bin", "wb" );
     for ( int i = 0;i < base.size();i ++ ){
        if ( !compname( base[i].number, number ) )
        fwrite( &base[i], 1, sizeof( Train ), ptrFil );
     }
     fclose( ptrFil );
     cout << "Train removed.\n";
     system( "pause" );
     return;
}

void View(){
    FILE *ptrFile = fopen( "Train.bin", "rb" );
    Train info;
    while ( true ){
        fread( &info, sizeof( Train ), 1, ptrFile );
        if ( feof( ptrFile ) )
            break;
        cout << info.number << "   " << info.name << "   " << info.type << "   " << info.dateDep << "   " << info.timeDep << "   " << info.dateArr << "   " << info.timeArr << "   " << info.level << "\n";
    }
    fclose( ptrFile );
    system( "pause" );
    return;
}


