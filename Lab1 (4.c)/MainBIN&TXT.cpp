#pragma once
#include <iostream>
#include <cstdio>
#include <vector>
#include <windows.h>
#include "HeaderBIN&TXT.h"
#include "Header.h"

using namespace std;

void AddBIN(){
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
    fwrite( &train , sizeof( Train ), 1, ptrFile );
    fclose( ptrFile );
    cout << "Train " << '"' << train.name << '"' <<" was successfully added.\n";
    system( "pause" );
    return;
}

void DeleteBIN(){
     system( "cls" );
     FILE *ptrFile = fopen( "Train.bin", "rb" );
     char number[4];
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

void ViewBIN(){
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

void AddTXT(){
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
    FILE *ptrFile = fopen( "Train.txt", "a" );
    fwrite( &train , sizeof( Train ), 1, ptrFile );
    fclose( ptrFile );
    cout << "Train " << '"' << train.name << '"' <<" was successfully added.\n";
    system( "pause" );
    return;
}

void DeleteTXT(){
     system( "cls" );
     FILE *ptrFile = fopen( "Train.txt", "r" );
     char number[4];
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
     remove( "Train.txt" );
     FILE *ptrFil = fopen( "Train.txt", "w" );
     for ( int i = 0;i < base.size();i ++ ){
        if ( !compname( base[i].number, number ) )
        fwrite( &base[i], 1, sizeof( Train ), ptrFil );
     }
     fclose( ptrFil );
     cout << "Train removed.\n";
     system( "pause" );
     return;
}

void ViewTXT(){
    FILE *ptrFile = fopen( "Train.txt", "r" );
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

