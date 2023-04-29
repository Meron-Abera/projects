#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct busInfo{
	string busType, driverName, color, arrivalTime, departureTime;
};
struct Date{
	int day, month, year;
	string time;
};

struct Address{
	string city;
	int streetNum;
};
struct Traveler {
    busInfo myBus;
    string name;
    int age;
    Address TA;
    int phoneNum, seatNum;
    string criminalRecord;
    Date DoT;
};

bool seat_occupied[80];
int number, reserved,seat_no,option, maxim_limit=80;


void Bus (busInfo B);
void Trecord (Traveler &T);
bool Seat_check(int available);
int reserve_seat();
bool legality_checker ();
bool regular_checker ();
void display (Traveler info);
void Gticket ();
void search ();

int Cchoice, bus_num, seat;
char answer, y, n;


busInfo B;

int main(){
    int Cchoice;
    char answer,y, n;

    for (int i =1; i <= maxim_limit; i++){
        seat_occupied[i] = false;
    }

    reenter:
    cout<<setfill(' ')<<setw(66)<<"      |#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*|\n"<<endl;
    cout<<setfill(' ')<<setw(66)<<"      |*#                                                                                *#|\n";
	cout<<setfill(' ')<<setw(66)<<"|\tBus ticket reservation system \t| "<<endl;
	cout<<setfill(' ')<<setw(74)<<"|---------------------------------------|\n";
	cout<<setfill(' ')<<setw(72)<<"|\tpress 1: To display bus information| \n"
		<<setfill(' ')<<setw(65)<<"|\tpress 2: To reserve seat     \t|\n"
		<<setfill(' ')<<setw(65)<<"|\tpress 3: To display details \t|\n"
		<<setfill(' ')<<setw(53)<<"|\tpress 4: To exit\t\t|"<<endl;
	cout<<setfill(' ')<<setw(74)<<"|---------------------------------------|\n";
	cout<<"\t\t\t\t \tplease enter your choice: ";
	cin>>Cchoice;
	switch(Cchoice)
		{
		    case 1:
		    	Bus(B);
               break;
			case 2:
			    renum:
                    cout<<"\n"<<setfill(' ')<<setw(60)<<"Enter the number of people you want to book a ticket for: ";
                    cin>>number;

				if(number < 1 || number > 80)
                {
                    cout<<"Invalid input: please enter again "<<endl;
                    goto renum;
                }

                for( int i=1;i<=number;i++)
                {
                    reserve_seat();
                }
			    break;
            case 3:
			    break;
			case 4:
				exit(EXIT_FAILURE);
				break;

		}
    cout<<"\n\n------------------------------------------------------------------------"<<endl;
    cout<<setfill(' ')<<setw(57)<<"do you want to continue? (enter Y for yes & N for no) "<<endl;
    cout<<setfill(' ')<<setw(12)<<"Answer = ";
    cin>>answer;

		if(answer =='y' || answer=='Y')
        {
            goto reenter;
        }
		else if(answer =='n' || answer=='N')
        {
			cout<<setfill(' ')<<setw(48)<<"Thank you for choosing us come back next time"<<endl;
		}
    cout<<"\n------------------------------------------------------------------------"<<endl;

    return 0;
}
//********************************************************************************************************
//********************************************************************************************************
void Bus (busInfo B){
	system ("cls");
	system("color 0B");
	busInfo buses[5] = { {"Habesha", "Abebe Kebede", "Blue", "12 A.M", "12 P.M"}, {"Abay", "Ermiyas Mulatu", "Black", "12 A.M", "12 P.M"},
							{"River Moon", "Geremew Lake", "Purple", "12 A.M", "12 P.M" }, {"golden", "Muluemebet Tarekegn", "Brown", "12 A.M","12 P.M" },
							{"Zemecha","Manyazewal Mentesnot", "White", "12 A.M", "12 P.M"}
							};
	cout<<"\nBus Type"<<setw(25)<<"Driver Name"<<setw(25)<<"Bus Color"<<setw(25)<<"Arrival Time"<<setw(25)<<"Departure Time"<<endl;
	for (int i=0; i<5; i++)
	{
		cout<<endl;
		cout<<buses[i].busType<<setw(25)<<buses[i].driverName<<setw(25)<<buses[i].color<<setw(25)<<buses[i].arrivalTime<<setw(25)<<buses[i].departureTime;
		cout<<endl;
	}
}
//********************************************************************************************************
//********************************************************************************************************
bool Seat_check(int available){

    if (seat_occupied[available] == true){
        return false;
    }
    return true;
}
//********************************************************************************************************
//********************************************************************************************************
int reserve_seat(){
retry:
    cout<<setfill(' ')<<setw(34)<<"please choose a seat number (from 1-80) :  ";
    cin>>seat_no;
    reserved = seat_no;

    if (seat_no > 80) {
        cout<<"\tInput out of range: please enter again  "<<endl;
        goto retry;
    }
    else if(seat_occupied[seat_no] == true){
        cout<<"\tYou have entered an occupied seat: please choose another seat: "<<endl;
        goto retry;
    }

    for (int j=0;j<=30;j++){
        if(seat_occupied[seat_no] == true){
            cout<<"\tAll seats are reserved, would you like to take another Bus? "<<endl;
            cout<<"\tIf yes please enter 1 otherwise please enter 2"<<endl;
            cin.ignore();
            cout<<"\t";
            cin>>option;
            if(option == '1')
        		Bus(B);
            else
                cout<<"\tThank you for choosing us. Good bye. ";
            }
    }
    seat_occupied[seat_no] = true;
    return seat_no;
}



