#include "Header.h"


void BechVec(){
    ofstream out("BechVec.txt");
    srand(time(0));
    out << "Vector:  \n\n";
    clock_t start, end;
    start = clock();
    end = clock();
    out << "Add and Find:\n";
    for (int Kol=10;((double) end - start) / ((double) CLOCKS_PER_SEC)<10.0;Kol+=10){
        vector <Train> train;
        for ( int i = 0;i < Kol;i ++ ){
            Train a;
            for (int j=0;j<4;j++)
                a.number[j] = char(rand()%10 + '0');
            for (int j=0;j<5;j++)
                a.name[j] = char(rand() % ('z' - 'a') + 'a');
           a.type[0]='o'; a.type[1]='r'; a.type[2]='d'; a.type[3]='i'; a.type[4]='n'; a.type[5]='a'; a.type[6]='r'; a.type[7]='y';
           for (int j=0;j<5;j++)
                if (j!=2)
                    a.dateDep[j] = char(rand()%2 + '0');
                else a.dateDep[j]='.';
           for (int j=0;j<5;j++)
                if (j!=2)
                    a.timeDep[j] = char(rand()%3 + '0');
                else a.timeDep[j]=':';
           for (int j=0;j<5;j++)
                if (j!=2)
                    a.dateArr[j] = char(rand()%2 + '0');
                else a.dateArr[j] = '.';
            for (int j=0;j<5;j++)
                if (j!=2)
                    a.timeArr[j] = char(rand()%3 + '0');
                else a.timeArr[j]=':';
            a.ID = i + 1;
            a.level = double ((rand()%14)/13.0);
            train.push_back(a);
        }
        char name[] = {char(rand() % ('z' - 'a') + 'a')};
        for ( int i = 0;i < train.size();i ++ ){
            bool ans=0;
            ans = compname( train[i].name, name );
        }
        char numb[5];
        for (int j=0;j<4;j++)
                numb[j] = char(rand()%10 + '0');
        double popl = 0.5;
        for ( int i = 0;i < train.size();i ++ ){
            bool ans=0;
            ans = compnumbpopl( train[i].number, train[i].level, numb, popl );
        }
         char date1[] = {'0','2','.','0','1'};
        char date2[] = {'1','2','.','0','2'};
        char time1[] = {'1','2',':','0','2'};
        char time2[] = {'1','2',':','2','0'};
        for ( int i = 0;i < train.size();i ++ ){
            bool ans=0;
            ans = compdate( train[i].dateDep, train[i].dateArr, date1, date2, train[i].timeDep, train[i].timeArr, time1, time2 );
        }
        end = clock();
        out << Kol << " " << ((double) end - start) / ((double) CLOCKS_PER_SEC) << " " << sizeof(Train)*Kol << "\n";
    }
    out.close();
    return;
}



void BechTxt(){
    ofstream out("BechTxt.txt");
    srand(time(0));
    out << "Vector:  \n\n";
    clock_t start, end;
    start = clock();
    end = clock();
    out << "Add and Find:\n";
    for (int Kol=10;((double) end - start) / ((double) CLOCKS_PER_SEC)<10.0;Kol+=10){
        for ( int i = 0;i < Kol;i ++ ){
            Train a;
            for (int j=0;j<4;j++)
                a.number[j] = char(rand()%10 + '0');
            for (int j=0;j<5;j++)
                a.name[j] = char(rand() % ('z' - 'a') + 'a');
           a.type[0]='o'; a.type[1]='r'; a.type[2]='d'; a.type[3]='i'; a.type[4]='n'; a.type[5]='a'; a.type[6]='r'; a.type[7]='y';
           for (int j=0;j<5;j++)
                if (j!=2)
                    a.dateDep[j] = char(rand()%2 + '0');
                else a.dateDep[j]='.';
           for (int j=0;j<5;j++)
                if (j!=2)
                    a.timeDep[j] = char(rand()%3 + '0');
                else a.timeDep[j]=':';
           for (int j=0;j<5;j++)
                if (j!=2)
                    a.dateArr[j] = char(rand()%2 + '0');
                else a.dateArr[j] = '.';
            for (int j=0;j<5;j++)
                if (j!=2)
                    a.timeArr[j] = char(rand()%3 + '0');
                else a.timeArr[j]=':';
            a.ID = i + 1;
            a.level = double ((rand()%14)/13.0);
            FILE *ptrFile = fopen( "Train.txt", "a" );
            fwrite( &a , sizeof( Train ), 1, ptrFile );
            fclose( ptrFile );
        }

        FILE *ptrFile = fopen( "Train.txt", "r" );
        char name[] = {char(rand() % ('z' - 'a') + 'a')};
        Train info;
        while ( true ){
            fread( &info, sizeof( Train ), 1, ptrFile );
            if ( feof( ptrFile ) )
                break;
            bool ans=0;
            ans = compname( info.name, name );
        }
        fclose(ptrFile);

        char numb[5];
        for (int j=0;j<4;j++)
                numb[j] = char(rand()%10 + '0');
        double popl = 0.5;

        ptrFile = fopen( "Train.txt", "r" );
        while ( true ){
            fread( &info, sizeof( Train ), 1, ptrFile );
            if ( feof( ptrFile ) )
                break;
            bool ans=0;
            ans = compnumbpopl( info.number, info.level, numb, popl );
        }
        fclose(ptrFile);


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
        }
        fclose(ptrFile);

        ifstream file("Train.txt");
        int size = 0;
        file.seekg (0, std::ios::end);
        size = file.tellg();
        file.close();
        end = clock();
        out << Kol << " " << ((double) end - start) / ((double) CLOCKS_PER_SEC) << " " << size << "\n";
    }
    out.close();
    return;
}

void BechBin(){
    ofstream out("BechBin.txt");
    srand(time(0));
    out << "Vector:  \n\n";
    clock_t start, end;
    start = clock();
    end = clock();
    out << "Add and Find:\n";
    for (int Kol=10;((double) end - start) / ((double) CLOCKS_PER_SEC)<10.0;Kol+=10){
        for ( int i = 0;i < Kol;i ++ ){
            Train a;
            for (int j=0;j<4;j++)
                a.number[j] = char(rand()%10 + '0');
            for (int j=0;j<5;j++)
                a.name[j] = char(rand() % ('z' - 'a') + 'a');
           a.type[0]='o'; a.type[1]='r'; a.type[2]='d'; a.type[3]='i'; a.type[4]='n'; a.type[5]='a'; a.type[6]='r'; a.type[7]='y';
           for (int j=0;j<5;j++)
                if (j!=2)
                    a.dateDep[j] = char(rand()%2 + '0');
                else a.dateDep[j]='.';
           for (int j=0;j<5;j++)
                if (j!=2)
                    a.timeDep[j] = char(rand()%3 + '0');
                else a.timeDep[j]=':';
           for (int j=0;j<5;j++)
                if (j!=2)
                    a.dateArr[j] = char(rand()%2 + '0');
                else a.dateArr[j] = '.';
            for (int j=0;j<5;j++)
                if (j!=2)
                    a.timeArr[j] = char(rand()%3 + '0');
                else a.timeArr[j]=':';
            a.ID = i + 1;
            a.level = double ((rand()%14)/13.0);
            FILE *ptrFile = fopen( "Train.bin", "ab" );
            fwrite( &a , sizeof( Train ), 1, ptrFile );
            fclose( ptrFile );
        }

        FILE *ptrFile = fopen( "Train.bin", "rb" );
        char name[] = {char(rand() % ('z' - 'a') + 'a')};
        Train info;
        while ( true ){
            fread( &info, sizeof( Train ), 1, ptrFile );
            if ( feof( ptrFile ) )
                break;
            bool ans=0;
            ans = compname( info.name, name );
        }
        fclose(ptrFile);

        char numb[5];
        for (int j=0;j<4;j++)
                numb[j] = char(rand()%10 + '0');
        double popl = 0.5;

        ptrFile = fopen( "Train.bin", "rb" );
        while ( true ){
            fread( &info, sizeof( Train ), 1, ptrFile );
            if ( feof( ptrFile ) )
                break;
            bool ans=0;
            ans = compnumbpopl( info.number, info.level, numb, popl );
        }
        fclose(ptrFile);


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
        }
        fclose(ptrFile);

        ifstream file("Train.bin");
        int size = 0;
        file.seekg (0, std::ios::end);
        size = file.tellg();
        file.close();
        end = clock();
        out << Kol << " " << ((double) end - start) / ((double) CLOCKS_PER_SEC) << " " << size << "\n";
    }
    out.close();
    return;
}


void Bech(){
   // BechVec();
   // BechTxt();
    BechBin();
}
