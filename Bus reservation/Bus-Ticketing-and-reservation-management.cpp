#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int Cchoice;
    char answer,y, n;
    reenter:
    cout<<setfill(' ')<<setw(72)<<"****************************************"<<endl;
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
