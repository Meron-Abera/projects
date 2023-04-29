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
void Bus (busInfo B);
void Trecord (Traveler &T);
bool seat_checker (int seat);
int seatReserve ();
bool legality_checker ();
bool regular_checker ();
//sort
void display (Traveler info);
void Gticket ();
void search ();

int Cchoice, bus_num, seat;
char answer, y, n;

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


int main(){
    int Cchoice;
    char answer,y, n;
    busInfo B;
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

