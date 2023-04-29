#include<iostream>
using namespace std;

struct Traveler {
	string name;
    float bill=200; // For Experimenting on the Discount function.
};

float discount(Traveler info);

int main(){
	
	Traveler a;
	
	cout<<discount(a);
	
	return 0;
}

float discount(Traveler info){	
	int discPerc=0;

	if(info.bill>150){
		discPerc = 15;
	}
	
	int afterDiscount = info.bill - (info.bill * discPerc / 100);
	
	return afterDiscount;
}
