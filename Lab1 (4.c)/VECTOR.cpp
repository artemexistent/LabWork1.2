#include "Header.h"

vector <Train> train;


void AddVEC(){
    system( "cls" );
    Train a;
    cout << "Enter:";
    cout << "\n   train number(four-digit number):"; InputNumber( a.number );
    cout << "\n   optional train name:"; InputName( a.name );
    cout << "\n   type of train(international, high-speed, ordinary, suburban):"; InputType( a.type );
    cout << "\n   date of departure:"; InputDate( a.dateDep );cout << "\n" << a.dateDep << "\n";
    cout << "\n   time of departure:"; InputTime( a.timeDep );
    cout << "\n   date of arrival:"; InputDate( a.dateArr );
    cout << "\n   time of arrival:"; InputTime( a.timeArr );
    cout << "\n   level of popularity of tickets:"; cin >> a.level;
    a.ID = train.size() + 1;
    system( "cls" );
    train.push_back( a );
    cout << "Train " << '"' << a.name << '"' <<" was successfully added.\n";
    system( "pause" );
    return;
}

void DeleteVEC(){
     system( "cls" );
     int number;
     cout << "Enter the train number you want to delete:"; cin >> number;
     int Kol = 0;
     for ( int i = 0;i < train.size();i ++ ){
        if ( train[i].ID != 0 )
            Kol++;
        if ( Kol == number ){
            train[i].ID = 0;
            break;
        }
     }
     cout << "Train removed.\n";
     system( "pause" );
     return;
}

void ViewVEC(){
    for ( int i = 0;i < train.size();i ++ )
        if ( train[i].ID != 0 )
            cout << train[i].number << "   " << train[i].name << "   " << train[i].type << "   " << train[i].dateDep << "   " << train[i].timeDep << "   " << train[i].dateArr << "   " << train[i].timeArr << "   " << train[i].level << "   " << train[i].ID <<  "\n";
    system( "pause" );
    return;
}

void FindVEC( char *name, char *numb, double popl, char *date1, char *date2, char *time1, char *time2, int key ){
    for ( int i = 0;i < train.size();i ++ ){
        bool ans=0;
        switch ( key )
        {
            case 0: ans = compname( train[i].name, name ); break;
            case 1: ans = compnumbpopl( train[i].number, train[i].level, numb, popl ); break;
            case 2: ans = compdate( train[i].dateDep, train[i].dateArr, date1, date2, train[i].timeDep, train[i].timeArr, time1, time2 ); break;
        }
        if ( ans && train[i].ID != 0)
        cout << train[i].number << "   " << train[i].name << "   " << train[i].type << "   " << train[i].dateDep << "   " << train[i].timeDep << "   " << train[i].dateArr << "   " << train[i].timeArr << "   " << train[i].level << "   " << train[i].ID << "\n";
    }
    system("pause");
    return;
}
