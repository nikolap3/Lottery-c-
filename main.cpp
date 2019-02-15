#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;

WORD GetConsoleTextAttribute (HANDLE hCon)
{
    CONSOLE_SCREEN_BUFFER_INFO con_info;
    GetConsoleScreenBufferInfo(hCon, &con_info);
    return con_info.wAttributes;
}

int main()
{
    //------------------------
    //Console editing code
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int saved_colors = GetConsoleTextAttribute(hconsole);
    //saved_colors is equal to the starting colors
    //------------------------------
    srand(time(0));
    int n[6],num;
    bool k=false;
    bool green=false;
    if(saved_colors == (FOREGROUND_GREEN | FOREGROUND_INTENSITY))green=true;
    //after we made sure the user didnt start with green letters we start the program
    cout<< "Enter 6 numbers (1-48)"<<endl;
    for(int i=0;i<6;i++)cin>>n[i];
    //user input
    //and the lottery
    cout<<"Numbers picked out are: "<<endl;
    for(int i=0;i<35;i++)
    {
        k=false;
        num=rand()%48+1;//random number generation
        for(int j=0;j<6;j++)
        {
            if(num==n[j])
            {
                k=true;
                break;
            }
        }
        if(k)
        {
            if(!green)SetConsoleTextAttribute(hconsole,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            else SetConsoleTextAttribute(hconsole,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            if(i%5==0)cout<<endl;
            cout<<num<<" ";
            SetConsoleTextAttribute(hconsole,saved_colors);
        }
        else
        {
            if(i%5==0)cout<<endl;
            cout<<num<<" ";
        }
        //if a number is the same as the one you entered,then change its color
    }
    cout<<endl<<endl<<"Press a key to exit the program"<<endl;
    while(!_kbhit())
    {
    }
    return 0;
}
