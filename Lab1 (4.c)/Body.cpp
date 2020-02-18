#pragma once
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "LabWorkHeader1.h"
//#include "Find.h"
using namespace std;


int menu();
int main()
{
    int answer;
    do{
        answer=menu();
        switch (answer)
        {
            case 0: Add(); break;
            case 1: Delete(); break;
            case 2: View(); break;
            case 3: FinD(); break;
            case 4: cout << "You are logged out.\n"; return 0;
        }
    }while(answer!=4);
    return 0;
}

int menu() {

        int key=0;
        int code;
        do {
               system("cls");
                key=(key+5)%5;
                if (key==0) cout<<"-> Add new train"<<endl;
                        else  cout<<"   Add new train"<<endl;
                if (key==1) cout<<"-> Delete train"<<endl;
                        else  cout<<"   Delete train"<<endl;
                if (key==2) cout<<"-> View all trains"<<endl;
                        else  cout<<"   View all trains"<<endl;
                if (key==3) cout<<"-> Find a train"<<endl;
                        else  cout<<"   Find a train"<<endl;
                if (key==4) cout<<"-> Sign Out"<<endl;
                        else  cout<<"   Sign Out"<<endl;
                code=_getch();
                if (code==224)
                {
                    code=_getch();
                    if (code==80) key++;
                    if (code==72) key--;
                        }
           }while(code!=13);
        system("cls");
        return key;
}
