#pragma once
#include <iostream>
#include <cstdio>
#include <windows.h>

using namespace std;


struct Train{

    string number,name,type,dateDep,timeDep,dateArr,timeArr;
    double level;

};

bool compname(string a,string b);
bool compdate(string date11, string date12, string date21, string date22,string time11, string time12, string time21, string time22 );
bool compnumbpopl(string numb1,double lvl1,string numb2,double lvl2);
void Find(string name, string numb,double popl,  string date1, string date2, string time1, string time2, int key);


int menu2(){


    int key=0;
     int code;
        do {
               system("cls");
              cout << " Search for a train:\n";
                key=(key+4)%4;
                if (key==0) cout<<"-> by name beginning"<<endl;
                        else  cout<<"   by name beginning"<<endl;
                if (key==1) cout<<"-> not less than the specified number and  no more than a given level of popularity"<<endl;
                        else  cout<<"   not less than the specified number and  no more than a given level of popularity"<<endl;
                if (key==2) cout<<"-> in a given date and time range"<<endl;
                        else  cout<<"   in a given date and time range"<<endl;
                if (key==3) cout << "-> Back" << endl;
                        else cout << "   Back" << endl;
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

void FinD(){



    string name="",numb="",date1="",date2="",time1="",time2="";
    double popl=0.0;
    int answer;
    do{
        answer=menu2();
        switch(answer){

        case 0: cout << "Enter begin name train:"; cin >> name; break;

        case 1: cout << "Enter specified number:"; cin >> numb;
                cout << "\nEnter level of popularity:"; cin >> popl; break;

        case 2: cout << "Enter first date:"; cin >> date1;
                cout << "\nEnter second date:"; cin >> date2;
                cout << "\nEnter first time:"; cin >> time1;
                cout << "\nEnter second time:"; cin >> time2; break;
        case 3: cout << "Bye";return;

        }


        Find(name,numb,popl,date1,date2,time1,time2,answer);

    }while(answer!=3);


    system("pause");

    return;

}




void Find(string name, string numb,double popl,  string date1, string date2, string time1, string time2, int key){


    FILE * ptrFile = fopen("Train.bin", "rb");

    Train info;

    while (true){


        fread(&info,sizeof(Train),1,ptrFile);

        if (feof(ptrFile))
            break;

/*        bool ans=0;

        switch (key)
        {
            case 0: ans=compname(info.name,name); break;
            case 1: ans=compnumbpopl(info.number,info.level,numb,popl); break;
            case 2: ans=compdate(info.dateDep,info.dateArr,date1,date2,info.timeDep,info.timeArr,time1,time2); break;
        }
*/
        if (1)
        cout << info.number << "   " << info.name << "   " << info.type << "   " << info.dateDep << "   " << info.timeDep << "   " << info.dateArr << "   " << info.timeArr << "   " << info.level << "\n";

    }
    fclose(ptrFile);

    system("pause");
    return;

}

bool compname(string a,string b){


    cout << a << " " << b << endl;
    for (int i=0;i<b.size();i++){

        if (a[i]!=b[i]){
            return 0;
        }

    }

    return 1;

}

bool compnumbpopl(string numb1,double lvl1,string numb2,double lvl2){

    for (int i=0;i<4;i++){
        if (numb1[i]<numb2[i])
            return 0;
    }
 //   if (fabs(lvl))
    return 1;
}

bool compdate(string date11, string date12, string date21, string date22,string time11, string time12, string time21, string time22 ){


    int mnth11=(date11[3]-'0')*10+(date11[4]-'0');
    int mnth12=(date12[3]-'0')*10+(date12[4]-'0');
    int mnth21=(date21[3]-'0')*10+(date21[4]-'0');
    int mnth22=(date22[3]-'0')*10+(date22[4]-'0');

    if (mnth11<mnth21)
        return 0;
    if (mnth12>mnth22)
        return 0;

    int chi11=(date11[0]-'0')*10+(date11[1]-'0');
    int chi12=(date12[0]-'0')*10+(date12[1]-'0');
    int chi21=(date21[0]-'0')*10+(date21[1]-'0');
    int chi22=(date22[0]-'0')*10+(date22[1]-'0');

    if (mnth11==mnth21 && chi11<chi21)
        return 0;
    if (mnth12==mnth22 && chi12>chi22)
        return 0;

    int hour11=(time11[0]-'0')*10+(time11[1]-'0');
    int hour12=(time12[0]-'0')*10+(time12[1]-'0');
    int hour21=(time21[0]-'0')*10+(time21[1]-'0');
    int hour22=(time22[0]-'0')*10+(time22[1]-'0');

    if (mnth11==mnth21 && chi11==chi21 && hour11<hour21)
        return 0;
    if (mnth12==mnth22 && chi12==chi22 && hour12>hour22)
        return 0;


    int min11=(time11[3]-'0')*10+(time11[4]-'0');
    int min12=(time12[3]-'0')*10+(time12[4]-'0');
    int min21=(time21[3]-'0')*10+(time21[4]-'0');
    int min22=(time22[3]-'0')*10+(time22[4]-'0');

    if (mnth11==mnth21 && chi11==chi21 && hour11==hour21 && min11<min21)
        return 0;
    if (mnth12==mnth22 && chi12==chi22 && hour12==hour22 && min12>min22)
        return 0;



    return 1;


}
