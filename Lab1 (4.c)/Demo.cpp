#include "Header.h"

void DemoVec();
void DemoTxt();
void DemoBin();


void Demo(){
    //DemoVec();
    system("cls");
    DemoTxt();
    system("cls");
    //DemoBin();
}

void DemoVec(){
    srand(time(0));
    cout << "Vector\n";
    cout << "Add new train Kol:";
    int Kol = rand()%20;
    vector <Train> train;
    cout << Kol << "\n";
    for ( int i = 0;i < Kol;i ++ ){
        Train a;
        for (int j=0;j<4;j++)
            a.number[j] = char(rand()%10 + '0');
            cout << a.number << "\t";
        for (int j=0;j<5;j++)
            a.name[j] = char(rand() % ('z' - 'a') + 'a');
            cout << a.name << "\t";
       a.type[0]='o'; a.type[1]='r'; a.type[2]='d'; a.type[3]='i'; a.type[4]='n'; a.type[5]='a'; a.type[6]='r'; a.type[7]='y';
        cout << a.type << "\t";

       for (int j=0;j<5;j++)
            if (j!=2)
                a.dateDep[j] = char(rand()%2 + '0');
            else a.dateDep[j]='.';
            cout << a.dateDep << "\t";
       for (int j=0;j<5;j++)
            if (j!=2)
                a.timeDep[j] = char(rand()%3 + '0');
            else a.timeDep[j]=':';
            cout << a.timeDep << "\t";
       for (int j=0;j<5;j++)
            if (j!=2)
                a.dateArr[j] = char(rand()%2 + '0');
            else a.dateArr[j] = '.';
        cout << a.dateArr << "\t";
        for (int j=0;j<5;j++)
            if (j!=2)
                a.timeArr[j] = char(rand()%3 + '0');
            else a.timeArr[j]=':';
        cout << a.timeArr << "\t";
        a.ID = i + 1;
        a.level = double ((rand()%14)/13.0);
        cout << a.level << "\t" << a.ID << endl;
        train.push_back(a);
      //  cout << a.number << "   " << a.name << "   " << a.type << "   " << a.dateDep << "   " << a.timeDep << "   " << a.dateArr << "   " << a.timeArr << "   " << a.level << "   " << a.ID <<  "    Added\n";
        Sleep(500);
    }
    Sleep(3000);

    cout << "\n\n\n";
    cout << "Find by name beginning:";
    char name[] = {char(rand() % ('z' - 'a') + 'a')};
    cout << name[0] << endl;
    for ( int i = 0;i < train.size();i ++ ){
        bool ans=0;
        ans = compname( train[i].name, name );
        if ( ans && train[i].ID !=0 )
        cout << train[i].number << "   " << train[i].name << "   " << train[i].type << "   " << train[i].dateDep << "   " << train[i].timeDep << "   " << train[i].dateArr << "   " << train[i].timeArr << "   " << train[i].level << "   " << train[i].ID << "\n";
    }
    Sleep(3000);
    cout << "\n\n";
    char numb[5];
    for (int j=0;j<4;j++)
            numb[j] = char(rand()%10 + '0');
    double popl = 0.5;
    cout << "Find not less than the specified number and  no more than a given level of popularity:  ";
    cout << numb << " " << popl << "\n";
    for ( int i = 0;i < train.size();i ++ ){
        bool ans=0;
        ans = compnumbpopl( train[i].number, train[i].level, numb, popl );
        if ( ans && train[i].ID !=0 )
        cout << train[i].number << "   " << train[i].name << "   " << train[i].type << "   " << train[i].dateDep << "   " << train[i].timeDep << "   " << train[i].dateArr << "   " << train[i].timeArr << "   " << train[i].level << "   " << train[i].ID << "\n";
    }
    Sleep(3000);
    cout << "\n\n";
    cout << "Find in a given date and time range 15.02 - 15.05  15:15 - 15:35\n";
    char date1[] = {'0','2','.','0','1'};
    char date2[] = {'1','2','.','0','2'};
    char time1[] = {'1','2',':','0','2'};
    char time2[] = {'1','2',':','2','0'};
    for ( int i = 0;i < train.size();i ++ ){
        bool ans=0;
        ans = compdate( train[i].dateDep, train[i].dateArr, date1, date2, train[i].timeDep, train[i].timeArr, time1, time2 );
        if ( ans && train[i].ID !=0 )
        cout << train[i].number << "   " << train[i].name << "   " << train[i].type << "   " << train[i].dateDep << "   " << train[i].timeDep << "   " << train[i].dateArr << "   " << train[i].timeArr << "   " << train[i].level << "   " << train[i].ID << "\n";
    }
    Sleep(3000);
    cout << "\n\n";
    for ( int i = 0;i < Kol / 2;i ++ ){
        cout << "Delete Number:";
        int number = rand()%Kol;
        Kol --;
        cout << number << "  ";
        int sIze = 0;
        for ( int i = 0;i < train.size();i ++ ){
            if ( train[i].ID != 0 )
                sIze++;
            if ( sIze == number ){
                train[i].ID = 0;
                break;
            }
         }
         cout << "Train removed.\n";
         Sleep(500);
    }
    Sleep(3000);
    cout << "\n\nView all:\n";
    for ( int i = 0;i < train.size();i ++ )
        if ( train[i].ID != 0 )
            cout << train[i].number << "   " << train[i].name << "   " << train[i].type << "   " << train[i].dateDep << "   " << train[i].timeDep << "   " << train[i].dateArr << "   " << train[i].timeArr << "   " << train[i].level << "   " << train[i].ID <<  "\n";


    system("pause");
}





void DemoTxt(){

    srand(time(0));
    cout << "TxtFile\n";
    cout << "Add new train Kol:";
    int Kol = rand()%20;
    cout << Kol << "\n";
    for ( int i = 0;i < Kol;i ++ ){
        Train a;
        for (int j=0;j<4;j++)
            a.number[j] = char(rand()%10 + '0');
            cout << a.number << "\t";
        for (int j=0;j<5;j++)
            a.name[j] = char(rand() % ('z' - 'a') + 'a');
            cout << a.name << "\t";
       a.type[0]='o'; a.type[1]='r'; a.type[2]='d'; a.type[3]='i'; a.type[4]='n'; a.type[5]='a'; a.type[6]='r'; a.type[7]='y';
        cout << a.type << "\t";

       for (int j=0;j<5;j++)
            if (j!=2)
                a.dateDep[j] = char(rand()%2 + '0');
            else a.dateDep[j]='.';
            cout << a.dateDep << "\t";
       for (int j=0;j<5;j++)
            if (j!=2)
                a.timeDep[j] = char(rand()%3 + '0');
            else a.timeDep[j]=':';
            cout << a.timeDep << "\t";
       for (int j=0;j<5;j++)
            if (j!=2)
                a.dateArr[j] = char(rand()%2 + '0');
            else a.dateArr[j] = '.';
        cout << a.dateArr << "\t";
        for (int j=0;j<5;j++)
            if (j!=2)
                a.timeArr[j] = char(rand()%3 + '0');
            else a.timeArr[j]=':';
        cout << a.timeArr << "\t";
        a.ID = i + 1;
        a.level = double ((rand()%14)/13.0);
        cout << a.level << "\t" << a.ID << endl;
        FILE *ptrFile = fopen( "Train.txt", "a" );
        fwrite( &a , sizeof( Train ), 1, ptrFile );
        fclose( ptrFile );
        //cout << a.number << "   " << a.name << "   " << a.type << "   " << a.dateDep << "   " << a.timeDep << "   " << a.dateArr << "   " << a.timeArr << "   " << a.level << "   " << a.ID <<  "    Added\n";
        Sleep(500);
    }
    Sleep(3000);

    cout << "\n\n\n";
    cout << "Find by name beginning:";
    char name[] = {char(rand() % ('z' - 'a') + 'a')};
    cout << name[0] << endl;
    FILE *ptrFile = fopen( "Train.txt", "r" );
    Train info;
    while ( true ){
        fread( &info, sizeof( Train ), 1, ptrFile );
        if ( feof( ptrFile ) )
            break;
        bool ans=0;
        ans = compname( info.name, name );
        if ( ans && info.ID != 0 )
        cout << info.number << "   " << info.name << "   " << info.type << "   " << info.dateDep << "   " << info.timeDep << "   " << info.dateArr << "   " << info.timeArr << "   " << info.level << "\n";
    }
    fclose(ptrFile);

    Sleep(3000);
    cout << "\n\n";
    char numb[5];
    for (int j=0;j<4;j++)
            numb[j] = char(rand()%10 + '0');
    double popl = 0.5;
    cout << "Find not less than the specified number and  no more than a given level of popularity:  ";
    cout << numb << " " << popl << "\n";
    ptrFile = fopen( "Train.txt", "r" );
    while ( true ){
        fread( &info, sizeof( Train ), 1, ptrFile );
        if ( feof( ptrFile ) )
            break;
        bool ans=0;
        ans = compnumbpopl( info.number, info.level, numb, popl );
        if ( ans && info.ID != 0 )
        cout << info.number << "   " << info.name << "   " << info.type << "   " << info.dateDep << "   " << info.timeDep << "   " << info.dateArr << "   " << info.timeArr << "   " << info.level << "\n";
    }
    fclose(ptrFile);
    Sleep(3000);
    cout << "\n\n";
    cout << "Find in a given date and time range 15.02 - 15.05  15:15 - 15:35\n";
    char date1[] = {'0','2','.','0','1'};
    char date2[] = {'1','2','.','0','2'};
    char time1[] = {'1','2',':','0','2'};
    char time2[] = {'1','2',':','2','0'};
    ptrFile = fopen( "Train.txt", "r" );
    while ( true ){
        fread( &info, sizeof( Train ), 1, ptrFile );
        if ( feof( ptrFile ) )
            break;
        bool ans=0;
        ans = compdate( info.dateDep, info.dateArr, date1, date2, info.timeDep, info.timeArr, time1, time2 );
        if ( ans && info.ID != 0 )
        cout << info.number << "   " << info.name << "   " << info.type << "   " << info.dateDep << "   " << info.timeDep << "   " << info.dateArr << "   " << info.timeArr << "   " << info.level << "\n";
    }
    fclose(ptrFile);
    Sleep(3000);
    cout << "\n\n";
    for ( int i = 0;i < Kol / 2;i ++ ){
        cout << "Delete Number:";
        int number = rand()%Kol;
        Kol --;
        cout << number << "  ";
        FILE *ptrFile = fopen( "Train.txt", "r" );
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
            if ( base[i].ID != number )
            fwrite( &base[i], 1, sizeof( Train ), ptrFil );
         }
         fclose( ptrFil );
         cout << "Train removed.\n";
         Sleep(500);
    }
    Sleep(3000);
    cout << "\n\nView all:\n";
    ptrFile = fopen( "Train.txt", "r" );
    while ( true ){
        fread( &info, sizeof( Train ), 1, ptrFile );
        if ( feof( ptrFile ) )
            break;
        cout << info.number << "   " << info.name << "   " << info.type << "   " << info.dateDep << "   " << info.timeDep << "   " << info.dateArr << "   " << info.timeArr << "   " << info.level << "   " << info.ID <<  "\n";
    }
    fclose( ptrFile );
    system("pause");


}




void DemoBin(){

    srand(time(0));
    cout << "BinFile\n";
    cout << "Add new train Kol:";
    int Kol = rand()%20;
    cout << Kol << "\n";
    for ( int i = 0;i < Kol;i ++ ){
        Train a;
        for (int j=0;j<4;j++)
            a.number[j] = char(rand()%10 + '0');
            cout << a.number << "\t";
        for (int j=0;j<5;j++)
            a.name[j] = char(rand() % ('z' - 'a') + 'a');
            cout << a.name << "\t";
       a.type[0]='o'; a.type[1]='r'; a.type[2]='d'; a.type[3]='i'; a.type[4]='n'; a.type[5]='a'; a.type[6]='r'; a.type[7]='y';
        cout << a.type << "\t";

       for (int j=0;j<5;j++)
            if (j!=2)
                a.dateDep[j] = char(rand()%2 + '0');
            else a.dateDep[j]='.';
            cout << a.dateDep << "\t";
       for (int j=0;j<5;j++)
            if (j!=2)
                a.timeDep[j] = char(rand()%3 + '0');
            else a.timeDep[j]=':';
            cout << a.timeDep << "\t";
       for (int j=0;j<5;j++)
            if (j!=2)
                a.dateArr[j] = char(rand()%2 + '0');
            else a.dateArr[j] = '.';
        cout << a.dateArr << "\t";
        for (int j=0;j<5;j++)
            if (j!=2)
                a.timeArr[j] = char(rand()%3 + '0');
            else a.timeArr[j]=':';
        cout << a.timeArr << "\t";
        a.ID = i + 1;
        a.level = double ((rand()%14)/13.0);
        cout << a.level << "\t" << a.ID << endl;
        FILE *ptrFile = fopen( "Train.bin", "ab" );
        fwrite( &a , sizeof( Train ), 1, ptrFile );
        fclose( ptrFile );
        cout << a.number << "   " << a.name << "   " << a.type << "   " << a.dateDep << "   " << a.timeDep << "   " << a.dateArr << "   " << a.timeArr << "   " << a.level << "   " << a.ID <<  "    Added\n";
        Sleep(500);
    }
    Sleep(3000);

    cout << "\n\n\n";
    cout << "Find by name beginning:";
    char name[] = {char(rand() % ('z' - 'a') + 'a')};
    cout << name[0] << endl;
    FILE *ptrFile = fopen( "Train.bin", "rb" );
    Train info;
    while ( true ){
        fread( &info, sizeof( Train ), 1, ptrFile );
        if ( feof( ptrFile ) )
            break;
        bool ans=0;
        ans = compname( info.name, name );
        if ( ans && info.ID != 0 )
        cout << info.number << "   " << info.name << "   " << info.type << "   " << info.dateDep << "   " << info.timeDep << "   " << info.dateArr << "   " << info.timeArr << "   " << info.level << "\n";
    }
    fclose(ptrFile);

    Sleep(3000);
    cout << "\n\n";
    char numb[5];
    for (int j=0;j<4;j++)
            numb[j] = char(rand()%10 + '0');
    double popl = 0.5;
    cout << "Find not less than the specified number and  no more than a given level of popularity:  ";
    cout << numb << " " << popl << "\n";
    ptrFile = fopen( "Train.bin", "rb" );
    while ( true ){
        fread( &info, sizeof( Train ), 1, ptrFile );
        if ( feof( ptrFile ) )
            break;
        bool ans=0;
        ans = compnumbpopl( info.number, info.level, numb, popl );
        if ( ans && info.ID != 0 )
        cout << info.number << "   " << info.name << "   " << info.type << "   " << info.dateDep << "   " << info.timeDep << "   " << info.dateArr << "   " << info.timeArr << "   " << info.level << "\n";
    }
    fclose(ptrFile);
    Sleep(3000);
    cout << "\n\n";
    cout << "Find in a given date and time range 15.02 - 15.05  15:15 - 15:35\n";
    char date1[] = {'0','2','.','0','1'};
    char date2[] = {'1','2','.','0','2'};
    char time1[] = {'1','2',':','0','2'};
    char time2[] = {'1','2',':','2','0'};
    ptrFile = fopen( "Train.bin", "rb" );
    while ( true ){
        fread( &info, sizeof( Train ), 1, ptrFile );
        if ( feof( ptrFile ) )
            break;
        bool ans=0;
        ans = compdate( info.dateDep, info.dateArr, date1, date2, info.timeDep, info.timeArr, time1, time2 );
        if ( ans && info.ID != 0 )
        cout << info.number << "   " << info.name << "   " << info.type << "   " << info.dateDep << "   " << info.timeDep << "   " << info.dateArr << "   " << info.timeArr << "   " << info.level << "\n";
    }
    fclose(ptrFile);
    Sleep(3000);
    cout << "\n\n";
    for ( int i = 0;i < Kol / 2;i ++ ){
        cout << "Delete Number:";
        int number = rand()%Kol;
        Kol --;
        cout << number << "  ";
        FILE *ptrFile = fopen( "Train.bin", "rb" );
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
            if ( base[i].ID != number )
            fwrite( &base[i], 1, sizeof( Train ), ptrFil );
         }
         fclose( ptrFil );
         cout << "Train removed.\n";
         Sleep(500);
    }
    Sleep(3000);
    cout << "\n\nView all:\n";
    ptrFile = fopen( "Train.bin", "rb" );
    while ( true ){
        fread( &info, sizeof( Train ), 1, ptrFile );
        if ( feof( ptrFile ) )
            break;
        cout << info.number << "   " << info.name << "   " << info.type << "   " << info.dateDep << "   " << info.timeDep << "   " << info.dateArr << "   " << info.timeArr << "   " << info.level << "   " << info.ID <<  "\n";
    }
    fclose( ptrFile );
    system("pause");


}
