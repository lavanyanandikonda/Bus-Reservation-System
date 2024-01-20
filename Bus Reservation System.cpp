#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
static int p=0;
class a
{
    string busn,driver,arrival,depart,from,to;
    char seat[8][4][10];
    public:
    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);
}bus[10];
void vline(char ch)
{
    cout<<endl;
    for(int i=80;i>0;i--)
    {
        cout<<ch;
    }
}
void a::install()
{
    cout<<"Enter Bus No. :- ";
    cin>>bus[p].busn;
    cout<<endl<<"Enter Driver's Name :- ";
    cin>>bus[p].driver;
    cout<<endl<<"Arrival Time :- ";
    cin>>bus[p].arrival;
    cout<<endl<<"Departure Time :- ";
    cin>>bus[p].depart;
    cout<<endl<<"Origin :- ";
    cin>>bus[p].from;
    cout<<endl<<"Destination :- ";
    cin>>bus[p].to;
    bus[p].empty();
    p++;
}
void a::allotment()
{
    int seat;
    char number[10];
    top:
    cout<<endl<<"Enter Bus Number :- ";
    cin>>number;
    int n;
    for(n=0;n<=p;n++)
    {
        if(bus[n].busn==number)
            break;
    }
    while(n<=p)
    {
        cout<<endl<<"Seat Number :- ";
        cin>>seat;
        if(seat>32)
        {
            try
            {
                throw seat;
            }
            catch(int s)
            {
                cout<<"Exception : There are only 32 seats available in this bus";
            }
        }
        else
        {
            if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
            {
                cout<<endl<<"Enter Passenger's Name :- ";
                cin>>bus[n].seat[seat/4][(seat%4)-1];
                break;
            }
            else
            {
                cout<<endl<<"This seat is already reserved.";
            }
        }
    }
    if(n>p)
    {
        cout<<endl<<"Enter a proper bus number :- ";
        goto top;
    }
}
void a::empty()
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<4;j++)
        {
            strcpy(bus[p].seat[i][j],"Empty");
        }
    }
}
void a::show()
{
    int n;
    string number;
    cout<<endl<<"Enter Bus No. :- ";
    cin>>number;
    for(n=0;n<=p;n++)
    {
        if(bus[n].busn==number)
        {
            break;
        }
    }
    while(n<=p)
    {
        vline('*');
        cout<<endl<<"Bus Number :- \t"<<bus[n].busn;
        cout<<endl<<"Driver :- \t"<<bus[n].driver;
        cout<<endl<<"Arrival Time :- "<<bus[n].arrival<<"\tDeparture Time :- "<<bus[n].depart;
        cout<<endl<<"From :- "<<bus[n].from<<"\tTo :- "<<bus[n].to<<endl;
        vline('*');
        bus[0].position(n);
        int a=1;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<4;j++)
            {
                a++;
                if(bus[n].seat[i][j]=="Empty")
                {
                    cout<<endl<<"The seat no. "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j];
                }
            }
        }
        break;
    }
    if(n>p)
    {
        cout<<"Enter a proper Bus No. :- ";
    }
}
void a::position(int l)
{
    int s=0,p=0;
    for(int i=0;i<8;i++)
    {
        cout<<endl;
        for(int j=0;j<4;j++)
        {
            s++;
            if(strcmp(bus[l].seat[i][j],"Empty")==0)
            {
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[l].seat[i][j];
                p++;
            }
            else
            {
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[l].seat[i][j];
            }
        }
    }
    cout<<endl<<"No. of empty seats :- "<<p;
}
void a::avail()
{
    for(int n=0;n<p;n++)
    {
        vline('*');
        cout<<endl<<"Bus Number :- \t"<<bus[n].busn;
        cout<<endl<<"Driver :- \t"<<bus[n].driver;
        cout<<endl<<"Arrival Time :- \t"<<bus[n].arrival<<"\tDeparture Time :- \t"<<bus[n].depart;
        cout<<endl<<"From :- \t"<<bus[n].from<<"\tTo :- \t"<<bus[n].to<<endl;
        vline('*');
        vline('_');
    }
}
int main()
{
    int w;
    while(1)
    {
        cout<<endl<<endl;
        cout<<endl<<"Welcome to SRM-AP Bus Management and Reservation System";
        cout<<"\n\n\n\n";
        cout<<"\t\t\t1. Install\n\t\t\t"<<"2. Reservation\n\t\t\t"<<"3. Show\n\t\t\t"<<"4. Available Buses\n\t\t\t"<<"5. Exit";
        cout<<endl<<"Enter your choice :-> ";
        cin>>w;
        switch(w)
        {
            case 1:
                    bus[p].install();
                    break;
            case 2:
                    bus[p].allotment();
                    break;
            case 3:
                    bus[p].show();
                    break;
            case 4:
                    bus[p].avail();
                    break;
            case 5:
                    exit(0);
        }
    }
    return 0;
}