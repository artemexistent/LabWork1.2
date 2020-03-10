#include "Header.h"

bool compname( char *a,char *b );

bool compdate( char *date11, char *date12, char *date21, char *date22,
              char *time11, char *time12, char *time21, char *time22 );

bool compnumbpopl( char * numb1, double lvl1, char *numb2, double lvl2 );

void FindBIN( char *name, char *numb, double popl, char *date1, char *date2,
          char *time1, char *time2, int key );

void FinD( int key ){
    char name[100];
    char date1[5];
    char date2[5];
    char numb[4];
    char time1[5];
    char time2[5];
    double popl = 0.0;
    int answer;
    do{
        answer=menu2();
        switch( answer ){
            case 0: cout << "Enter begin name train:"; InputName( name ); break;

            case 1: cout << "Enter specified number:"; InputNumber( numb );
                    cout << "\nEnter level of popularity:"; cin >> popl; break;

            case 2: cout << "Enter first date:"; InputDate( date1 );
                    cout << "\nEnter second date:"; InputDate( date2 );
                    cout << "\nEnter first time:"; InputTime( time1 );
                    cout << "\nEnter second time:"; InputTime( time2 ); break;
            case 3: cout << "Bye"; return;
        }
        if (key == 1) FindBIN( name, numb, popl, date1, date2, time1, time2, answer );
        if (key == 2) FindTXT( name, numb, popl, date1, date2, time1, time2, answer );
        if (key == 3) FindVEC( name, numb, popl, date1, date2, time1, time2, answer );
    }while( answer!=3 );
    system( "pause" );
    return;
}


bool compname( char *a, char *b ){
	if ( strlen( b ) == 0 ) return 0;

    for ( int i = 0;i < strlen( b );i ++ ){
        if ( a[i] != b[i] ){
            return 0;
        }
    }
    return 1;
}

bool compnumbpopl( char *numb1, double lvl1, char *numb2, double lvl2 ){
    for ( int i = 0;i < 4;i ++ ){
        if ( numb1[i] < numb2[i] )
            return 0;
    }
    if ( lvl1 > lvl2 )
    	return 0;
    return 1;
}

bool compdate( char *date11, char *date12, char *date21, char *date22, char *time11, char *time12, char *time21, char *time22 ){
    int mnth11 = ( date11[3] - '0' ) * 10 + ( date11[4] - '0' );
    int mnth12 = ( date12[3] - '0' ) * 10 + ( date12[4] - '0' );
    int mnth21 = ( date21[3] - '0' ) * 10 + ( date21[4] - '0' );
    int mnth22 = ( date22[3] - '0' ) * 10 + ( date22[4] - '0' );
    if ( mnth11 < mnth21 )
        return 0;
    if ( mnth12 > mnth22 )
        return 0;
    int chi11 = ( date11[0] - '0' ) * 10 + ( date11[1] - '0' );
    int chi12 = ( date12[0] - '0' ) * 10 + ( date12[1] - '0' );
    int chi21 = ( date21[0] - '0' ) * 10 + ( date21[1] - '0' );
    int chi22 = ( date22[0] - '0' ) * 10 + ( date22[1] - '0' );
    if ( mnth11 == mnth21 && chi11 < chi21 )
        return 0;
    if ( mnth12 == mnth22 && chi12 > chi22 )
        return 0;
    int hour11 = ( time11[0] - '0' ) * 10 + ( time11[1] - '0' );
    int hour12 = ( time12[0] - '0' ) * 10 + ( time12[1] - '0' );
    int hour21 = ( time21[0] - '0' ) * 10 + ( time21[1] - '0' );
    int hour22 = ( time22[0] - '0' ) * 10 + ( time22[1] - '0' );
    if ( mnth11 == mnth21 && chi11 == chi21 && hour11 < hour21 )
        return 0;
    if ( mnth12 == mnth22 && chi12 == chi22 && hour12 > hour22 )
        return 0;
    int min11 = ( time11[3] - '0' ) * 10 + ( time11[4] - '0' );
    int min12 = ( time12[3] - '0' ) * 10 + ( time12[4] - '0' );
    int min21 = ( time21[3] - '0' ) * 10 + ( time21[4] - '0' );
    int min22 = ( time22[3] - '0' ) * 10 + ( time22[4] - '0' );
    if ( mnth11 == mnth21 && chi11 == chi21 && hour11 == hour21 && min11 < min21 )
        return 0;
    if ( mnth12 == mnth22 && chi12 == chi22 && hour12 == hour22 && min12 > min22 )
        return 0;
    return 1;
}
