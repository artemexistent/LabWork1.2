#pragma once
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "LabWorkHeader1.h"

using namespace std;

int main()
{
    remove( "Train.bin" );
    int answer;
    do{
        answer=menu();
        switch ( answer )
        {
            case 0: Add(); break;
            case 1: Delete(); break;
            case 2: View(); break;
            case 3: FinD(); break;
            case 4: cout << "You are logged out.\n"; return 0;
        }
    }while( answer != 4 );
    return 0;
}

