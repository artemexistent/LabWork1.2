#include "Header.h"

void BIN( int answer );
void TXT( int answer );
void VEC( int answer );
int Main();

int main(){
    int answer;
    do{
        answer = Menu();
        switch ( answer ){
            case 0: Main(); break;
            case 1: Demo(); break;
            case 2: Bech(); break;
        }
    }while( answer != 4 );
    return 0;
}


int Main()
{
    int key = StartMenu();
    int answer;
    do{
        answer = menu();
        switch (key){
            case 0: VEC( answer ); break;
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
            case 3: FinD( 1 ); break;
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
            case 3: FinD( 2 ); break;
            case 4: cout << "You are logged out.\n"; return ;
        }
    return;
}

void VEC( int answer ){
    switch ( answer )
        {
            case 0: AddVEC(); break;
            case 1: DeleteVEC(); break;
            case 2: ViewVEC(); break;
            case 3: FinD( 3 ); break;
            case 4: cout << "You are logged out.\n"; return ;
        }
    return;
}
