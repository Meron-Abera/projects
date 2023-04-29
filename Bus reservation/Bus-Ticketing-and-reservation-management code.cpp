#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct busInfo{
	string busType, driverName, color, departureTime, From, To;
	int distance;
}buses[5];
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
    char sex, BusType;
    Date DoT;
};

bool seat_occupied[80];
bool isRegular[80];

int Cchoice, searchChoice,number, reserved,seat_no,option, maxim_limit=80, size, cost;
char answer, y, n, SearchName[30], SearchSex,SearchPhone, SearchBusType,reply,take,legal;

string Btype,temp;
float price =0;
Traveler T[100],a,b;
busInfo B;
Traveler newTraveler[100];

void Bus ();
Traveler *Trecord (Traveler T[]);
bool Seat_check(int available);
int reserve_seat();
void sort();
void display (Traveler T[]);



int main(){
    Traveler *store;
    Traveler w,z;
    reenter:
    	system ("cls");
    	system("color B0");
    	cout<< "\n\n\n\n" ;
    cout<<setfill(' ')<<setw(66)<<"      |#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*|\n"<<endl;
    cout<<setfill(' ')<<setw(66)<<"      |*#                                                                                    *#|\n"<<endl;
	cout<<setfill(' ')<<setw(66)<<"      |*#                           Bus ticket reservation system                            *#|\n"<<endl;
	cout<<setfill(' ')<<setw(74)<<"      |*#------------------------------------------------------------------------------------*#|\n"<<endl;
	cout<<setfill(' ')<<setw(72)<<"      |*#                   press 1: To display bus information                              *#|\n"<<endl;
	cout<<setfill(' ')<<setw(65)<<"      |*#                   press 2: To reserve seat                                         *#|\n"<<endl;
	cout<<setfill(' ')<<setw(65)<<"      |*#                   press 3: To display details                                      *#|\n"<<endl;
	cout<<setfill(' ')<<setw(53)<<"      |*#                   press 4: To search a specific Travel                             *#|\n"<<endl;
	cout<<setfill(' ')<<setw(53)<<"      |*#                   press 5: To exit                                                 *#|\n"<<endl;
	cout<<setfill(' ')<<setw(74)<<"      |*#------------------------------------------------------------------------------------*#|\n"<<endl;
	cout<<setfill(' ')<<setw(74)<<"      |*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#|\n" <<endl;
	cout<<setfill(' ')<<setw(74)<<"\t\tplease enter your choice: ";
	cin>>Cchoice;
	renum:


	switch(Cchoice)
		{
		    case 1:
		    	Bus();
               break;
			case 2:
				cout<<"\n"<<setfill(' ')<<setw(60)<<"Enter total number of Travelers : ";
    			cin>>number;

				if(number < 1 || number > 80)
        		{
            		cout<<"Invalid input: please enter again "<<endl;
            	goto renum;
        		}
    			for (int i =1; i <= maxim_limit; i++){
        		seat_occupied[i] = false;
    			}
                store = Trecord(T);
			    break;
            case 3:
                display (T);
			    break;
			case 4:
				break;
			case 5:
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
void Bus (){
    string bustype;
	system ("cls");
	system("color 0B");
    busInfo buses[5] = {{"INFERNO","Mikyas Solomon", "Blue", "12 A.M", "Addis Ababa", "Bahir Dar",490},
							{"SUCCESS", "Ermiyas Mulatu", "Black", "3 A.M", "Dire Dawa", "Addis Ababa",452},
							{"RIVER ", "Abel Tesfa", "Silver", "4 A.M", "Addis Ababa", "Hawassa",279},
							{"INFINITY", "Muluemebet Tarekegn", "Brown", "5 A.M", "Jimma", "Addis Ababa",352},
							{"ZEMECHA","Yishak Abreham","White", "1:30 A.M", "Arba Minch", "Adama",92}};

	cout<<setw(20)<<"\nBus Type"<<left<<"\t    "<<setw(22)<<"Driver Name"<<left<<setw(18)<<"Bus Color"<<left<<setw(18)
	<<"Departure Time"<<left<<setw(18)<<"From"<<left<<setw(18)<<"To"<<setw(18)<<"Distance"<<endl;

	for (int i=0; i<5; i++)
	{
		cout<<endl;
		cout<<setw(20)<<buses[i].busType<<left<<setw(22)<<buses[i].driverName<<left<<setw(18)<<buses[i].color<<left<<setw(18)
		<<buses[i].departureTime<<left<<setw(18)<<buses[i].From<<left<<setw(18)<<buses[i].To<<buses[i].distance;
		cout<<endl;
	}

	cout<<"\n\nPlease Choose your Bus Type from the given alternatives: "<<endl;
    cin>>bustype;
    Btype = bustype;
}
//********************************************************************************************************
//********************************************************************************************************
Traveler *Trecord (Traveler T[]){
	system ("cls");
	system("color 0D");

	for (int i=0; i<number; i++)
	{
		cout<<"\nTraveler "<<i+1<<": ";
		cout<<"\nEnter your Full name: ";
		cin>>T[i].name;
		cout<<"\nEnter your Gender: ";
		cin>>T[i].sex;
		cout<<"\nEnter your Age: ";
		cin>>T[i].age;
		cout<<"\nEnter your phone number: ";
		cin>>T[i].phoneNum;
		cout<<"\nEnter your Address (city): ";
		cin>>T[i].TA.city;
		cout<<"\nEnter your Address ( street number): ";
		cin>>T[i].TA.streetNum;
		cout<<"\nEnter your date of travel (date, month, year in Ethiopian Calander): ";
		cin>>T[i].DoT.day>>T[i].DoT.month>>T[i].DoT.year;
		cout<<"\nEnter your time of travel (please insert PM or AM with the time in local time): ";
		cin>>T[i].DoT.time;
		cout<<"\n Do you have criminal record Enter 'y' if any otherwise enter 'n' : ";
		cin>>legal;
			if(legal =='y' ){
				cout<<"\nsorry you can not use any of our buses";
				exit(EXIT_FAILURE);
			}
			else{
				reserve_seat();
			}
		cout<<endl;
	}
    return T;
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
    cout<<setfill(' ')<<setw(34)<<"\nplease choose a seat number (from 1-80) :  ";
    cin>>seat_no;
    reserved = seat_no;

    if (seat_no > 80) {
        cout<<"\n\tInput out of range: please enter again  "<<endl;
        goto retry;
    }
    else if(seat_occupied[seat_no] == true){
        cout<<"\n\tYou have entered an occupied seat: please choose another seat: "<<endl;
        goto retry;
    }

    for (int j=0;j<=30;j++){
        if(seat_occupied[seat_no] == true){
            cout<<"\n\tAll seats are reserved, would you like to take another Bus? "<<endl;
            cout<<"\n\tIf yes please enter 1 otherwise please enter 2"<<endl;
            cin.ignore();
            cout<<"\t";
            cin>>option;
            if(option == '1')
        		Bus();
            else
                cout<<"\n\tThank you for choosing us. Good bye. ";
            }
    }
    seat_occupied[seat_no] = true;
    return seat_no;
}	

//********************************************************************************************************
//********************************************************************************************************
void sort(){
	for(int i =0;i<number;i++){
		for(int j=i+1; j<number;++j){
			if(T[i].name > T[j].name){
				temp = T[i].name;
				T[i].name = T[j].name;
				T[j].name = temp;
			}
		}
	}

}
//********************************************************************************************************
//********************************************************************************************************
void display (Traveler T[]){
    cout<<" *******************************************DISPLAY INFORMATION****************************************************"<<endl;
    cout<<" _________________________________________________________________________________________________________________"<<endl;
    cout << "\n|No.||Name  ||Gender ||Age\t||Phone Number ||Address||Date of travel||Time of Travel||Bus type||Seat Number||Price\n";
	sort();
    cout<<"\n\n";
    for (int i=0; i<number; i++)
	{
		cout<<i+1<<": "<<left;
		cout<<"  "<<T[i].name<<left;
		cout<<"\t  "<<T[i].sex<<left;
		cout<<"\t"<<T[i].age<<left;
		cout<<"\t\t"<<T[i].phoneNum<<left;
		cout<<"\t"<<T[i].TA.city<<":"<<T[i].TA.streetNum<<left;
		cout<<"       \t"<<T[i].DoT.day<<"/"<<T[i].DoT.month<<"/"<<T[i].DoT.year<<left;
		cout<<"    \t"<<T[i].DoT.time<<left;
		cout<<"\t   "<<Btype<<left;
        cout<<"\t"<<seat_no<<left;
        cout<<"\t  "<<price<<left;
		cout<<endl;
	}
    cout << "\n\n";
   cout<<setfill(' ')<<setw(74)<<"|*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*END*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#|\n" <<endl;

}


