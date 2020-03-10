#include "Header.h"

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
  while ( !IfNumber( str ) ){
    cout << "\tThis entry contains invalid characters. " << endl;
    InputNumber( str );
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
  while ( !IfType( str ) ){
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
  while ( !IfDate(str) ){
    cout << "\tDate entered is incorrect (example date: 16.08 )"  << endl;
    InputDate( str );
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
  while ( !IfTime(str) ){
    cout << "\tTime entered is incorrect (example Time: 16:08 )"  << endl;
    InputTime( str );
  }
}

bool IfNumber( char *str ){
    for ( int i = 0;i < 4;i ++ )
        if ( str[i] < '0' || str[i] > '9' )
            return false;
    return true;
}

bool IfDate( char *str ){
    if ( str[2] != '.' )
        return false;
    if ( ( str[3] - '0' ) * 10 + str[4] - '0' > 12 )
        return false;
    int daTe = ( str[0] - '0' ) * 10 + str[1] - '0';
    switch ( ( str[3] - '0' ) * 10 + str[4] - '0' ){
        case 1:  if ( daTe > 31 ) return false;  break;
        case 2:  if ( daTe > 29 ) return false;  break;
        case 3:  if ( daTe > 31 ) return false;  break;
        case 4:  if ( daTe > 30 ) return false;  break;
        case 5:  if ( daTe > 31 ) return false;  break;
        case 6:  if ( daTe > 30 ) return false;  break;
        case 7:  if ( daTe > 31 ) return false;  break;
        case 8:  if ( daTe > 31 ) return false;  break;
        case 9:  if ( daTe > 30 ) return false;  break;
        case 10: if ( daTe > 31 ) return false;  break;
        case 11: if ( daTe > 30 ) return false;  break;
        case 12: if ( daTe > 31 ) return false;  break;
    }
    return true ;
}

bool IfTime( char *str ){
    if ( str[2] != ':' )
        return false;
    if ( ( str[3] - '0' ) * 10 + str[4] - '0' > 60 )
        return false;
    if ( ( str[0] - '0' ) * 10 + str[1] - '0' > 24 )
        return false;
    return true ;
}

bool IfType( char *str ){
    int sizeStr =  strlen( str );
    if ( sizeStr > 13 || sizeStr < 8 )
        return false;
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
            return false;
        return true ;
    }
    if ( sizeStr == 10 ){
        string a = "high-speed";
        for ( int i = 0;i < 10;i ++ )
            if ( str[i] != a[i] )
                return false;
        return true ;
    }
    if ( sizeStr == 13 ){
        string a = "international";
        for ( int i = 0;i < 13;i ++ )
            if ( str[i] != a[i] )
                return false;
        return true ;
    }
    return true ;
}


