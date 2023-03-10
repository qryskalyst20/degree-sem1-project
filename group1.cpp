//GROUP 1

//2214227 MUHAMMAD NURIMAN QUDDUS BIN FAIZUL
//2211973 MUHAMMAD AZIM ZUFAYRI BIN NORAZAM
//2215009 MUHAMMAD IHSAN SHAMIL BIN MOHAMMAD RAFIDI
//2214417 MUHAMMAD IRFAN BIN ROSDIN
//2214467 MUHAMMAD FAIZ SUFIAN BIN MOHD FAHRUL

#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

void DisplayMenu();
void printCharacter();
void printScene(string);
void printart(int);
void Continue();
double GoRestaurant(string, double*);
double GoGym(double*);
double Workout();
double Sport();

class Player{
	
	private:
		double height;
		double weight;
		string name;
		int age;
		
	public:
		Player(string n, int a, double h, double w){
			height = h;
			weight = w;
			name = n;
			age = a;
		}
		
		~Player(){
			cout << endl << "Program terminated" << endl;
			cout << "Character died xoxo" << endl;
		}
		
		void setheight(double h){height = h;}
		double getheight(){return height;}
		
		void setweight(double w){weight = w;}
		double getweight(){return weight;}
		
		void setname(string n){name = n;}
		string getname(){return name;}
		
		void setage(int a){age = a;}
		int getage(){return age;}

		double calorieNeeds(double, double, int);
	
};

double Player::calorieNeeds(double height, double weight, int age){
	return 66.5+(13.75*weight)+(5.003*height)-(6.75*age);
}

int main(){
	
	int age, choice;
	double height, weight, calorie, intake=0, burned=0, currentcalorie=0;
	string name;
	
	cout << setw(70) << "\\\\-----WELCOME TO CALORIE COUNTER SIMULATOR!-----//" << endl << endl;
	cout << setw(60) << "The purpose of this program is to calculate calorie intake based on daily activity. Use at your own risk." << endl;
	cout << setw(60) << endl << "-----CREATE YOUR CHARACTER-----" << endl;
	
	cout << setw(45) << "Player name: ";
	getline(cin, name);
	cout << setw(45) << "Player age: ";
	cin >> age;
	cout << setw(45) << "Enter height(cm): ";
	cin >> height;
	cout << setw(45) << "Enter weight(kg): ";
	cin >> weight;
	
	Player player(name, age, height, weight);
	calorie = player.calorieNeeds(player.getheight(), player.getweight(), player.getage());
	
	printCharacter();	
	cout << "Your character has finished!" << endl;
	cout << "You need to fulfill " << calorie << " kcal/day in your activities. Lets's go!" << endl << endl;
	Continue();
	
	do{
		system("cls");
		printScene(player.getname());
		
		cout << "Ideal calorie: " << calorie << "kcal!" << endl;
		cout << "Current calorie: " << currentcalorie << "kcal!" << endl << endl;
		cout << "(1) Go to restaurant" << endl << "(2) Go to gym" << endl << "(3) Terminate Program" << endl << endl;
		cout << "Now what you wanna do => ";
		cin >> choice;
		switch(choice){
			case 1:
				system("cls");
				intake+=GoRestaurant(player.getname(), &calorie);
				currentcalorie+=intake; break;
			case 2:
				system("cls");
				burned-=GoGym(&calorie);
				currentcalorie-=burned; break;
			default:
				break;
		}
	}while(choice!=3);
	
	return 0;
}

double GoRestaurant(string name, double *calorie){
	
	string drinkname[11] = {"sky juice", "milo kaw", "kopi luwak", "xtrajoss", "triple mango", "cappucino", "latte", "mocha", "espresso", "choc coffee", "milk choc"};
	double drinkcal[11][2] = {{0, 8}, {135, 143}, {50, 58}, {0, 8}, {126, 134}, {130, 138}, {206, 214}, {394, 402}, {309, 317}, {86, 94}, {152, 160}};
	string foodname[8] = {"roti canai", "nasi lemak", "dim sum", "kaya toast", "chinese fried rice", "mamak fried rice", "pataya fried rice", "fried noodle"};
	double foodcal[8] = {301, 400, 900, 448, 163, 1362.1, 1597, 460};
	
	int i, j;
	double calorieintake=0;
	string order, hc, yn;
	
	printart(1);
	DisplayMenu();
	
	do{
		cout << endl << "Anne: Drink?" << endl;
		cout << name << ": Give me => ";
		cin.ignore();
		getline(cin, order);
		for(int x=0; x<11; x++){
			if(order==drinkname[x]){
				i=x;
			}
		}
		
		cout << "Anne: Hot or cold?" << endl;
		cout << name << ": ";
		cin >> hc;
		if(hc=="hot"){
			j = 0;
		}else{
			j = 1;
		}
		
		calorieintake+=drinkcal[i][j];
		
		cout << "Anne: Anything else?(y/n)" << endl;
		cout << name << ": ";
		cin >> yn;
	}while(yn == "y");
	
	do{
		cout << endl << "Anne: Eat?" << endl;
		cout << name << ": Give me => ";
		cin.ignore();
		getline(cin, order);
		for(int i=0; i<8; i++){
			if(order==foodname[i]){
				calorieintake+=foodcal[i];
			}
		}
		
		cout << "Anne: Anything else?(y/n)" << endl;
		cout << name << ": ";
		cin >> yn;	
	}while(yn == "y");
	
	cout << endl << "Calorie intake: " << calorieintake << "kcal" << endl;
	if(calorieintake<*calorie){
		cout << "You need " << *calorie-calorieintake << " more!" << endl << endl;
	}else{
		cout << "You have exceeded by " << calorieintake-*calorie << "! Enought calorie for today!" << endl << endl;
	}
	
	Continue();
	return calorieintake;
}

double GoGym(double *calorie){

	int choice;
	double burned;
	
	printart(2);
	
	cout << "What you wanna do?" << endl << "(1) Workout" << endl << "(2) Sport" << endl;
	cout << "=> ";
	cin >> choice;
	
	switch(choice){
		case 1:
			burned = Workout(); break;
		case 2:
			burned = Sport(); break;
	}
	*calorie-=burned;
	cout << "You just burned " << burned << "kcal! Good job!" << endl << endl;
	Continue();
	
	return burned;
}

double Workout(){
	
	int hours;
	
	printart(3);
	cout << "How many hours do you workout? => ";
	cin >> hours;
	
	return hours*365;
}

double Sport(){
	
	int hours;
	
	printart(4);
	cout << "How many hours do you play? => ";
	cin >> hours;
	
	return hours*365;
}

void Continue(){
	
	cout << "Press any key to continue..." << endl;
	getch();
	
}

void DisplayMenu(){
	
	cout << "+--------------------------------------------------------------------+" << endl;
	cout << "|                               MENU                                 |" << endl;
	cout << "+-------------------------------+----------------+-------------------+" << endl;
	cout << "|            BREAKFAST          |    BEVERAGES   |   HOT       COLD  |" << endl;
	cout << "+---------------------+---------+----------------+-------------------+" << endl;
	cout << "|  ROTI CANAI         | 301kcal |  SKY JUICE     |   0kcal     8kcal |" << endl;
	cout << "|  NASI LEMAK         | 400kcal |  MILO KAW      | 135kcal   143kcal |" << endl;
	cout << "|  DIM SUM            | 900kcal |  KOPI LUWAK    |  50kcal    58kcal |" << endl;
	cout << "|  KAYA TOAST         | 448kcal |  XTRAJOSS      |   0kcal     8kcal |" << endl;
	cout << "+---------------------+---------+  TRIPLE MANGO  | 126kcal   134kcal |" << endl;
	cout << "|             LUNCH             |  CAPPUCINO     | 130kcal   138kcal |" << endl;
	cout << "+---------------------+---------+  LATTE         | 206kcal   214kcal |" << endl;
	cout << "|  CHINESE FRIED RICE | 163kcal |  MOCHA         | 394kcal   402kcal |" << endl;
	cout << "|  MAMAK FRIED RICE   | 1.3kCal |  ESPRESSO      | 309kcal   317kcal |" << endl;
	cout << "|  PATAYA FRIED RICE  | 1.6kCal |  CHOC COFFEE   |  86kcal    94kcal |" << endl;
	cout << "|  FRIED NOODLE       | 460kcal |  MILK CHOC     | 152kcal   160kcal |" << endl;
	cout << "|                     |         |                |                   |" << endl;
	cout << "+---------------------+---------+----------------+-------------------+" << endl << endl;
	
	//1000cal=1kcal,, 1kcal=1C
}

void printCharacter(){
	
	cout << endl << endl;
	cout << "\\            " << endl;
	cout << " \\    O      " << endl;
	cout << " _\\|  |  }   " << endl;
	cout << "   M_/|\\_|}  " << endl;
	cout << "      |  }   " << endl;
	cout << "     / \\     " << endl;
	cout << "   _/   \\_   " << endl << endl;
	
}

void printScene(string name){
	
	cout << endl << endl;
	cout << "          ___   ____   " << endl;
	cout << "        /' --;^/ ,-_\\     \\ | /" << endl;
	cout << "       / / --o\\ o-\\ \\\\   --(_)--" << endl;
	cout << "      /-/-/|o|-|\\-\\|\\\\    / | \\" << endl;
	cout << "       '`  ` |-|   `` '" << endl;
	cout << "             |-|" << endl;
	cout << "             |-|O" << endl;
	cout << "             |-(\\,__" << endl;
	cout << "          ...|-|\\--,\\_...." << endl;
	cout << "      ,;;;;;;;;;;;;;;;;;;;;;;;;,." << endl;
	cout << "~~,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,  ______   ---------   _____     ------" << endl << endl;
	
	cout << "Welcome " << name << "! You just wake up on your private island. Life is good. " << endl << endl;
	
}

void printart(int n){
	
	if(n==1){
		cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
		cout << "                                _    ," << endl;
		cout << "__   __   __   __   __   --  -,_/\\\\_~0_\\ ___    __   __   __" << endl;
		cout << "                      --    /  ___ \\-  `___`+-," << endl;
		cout << "                    ---    `--( @ )----( @ )---`" << endl;
		cout << "                               '-'      '-'" << endl;
		cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl << endl;
		cout << "Le you driving to the restaurant..." << endl;
		cout << "You parked and take a seat..." << endl;
		cout << "The waiter gives you the menu..." << endl << endl;
		
		
	}else if(n==2){
		cout << endl << endl;
		cout << "   __o            __o  <-You       __o            __o            __o " << endl;
		cout << " _`\\<,_         _`\\<,_         _`\\<,_         _`\\<,_         _`\\<,_" << endl;
		cout << "(_)/ (_)       (_)/ (_)       (_)/ (_)       (_)/ (_)       (_)/ (_)" << endl;
		cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
		cout << "Le you cycling to gym..." << endl << endl;

	}else if(n==3){
		
		cout << endl << endl;
		cout << "                                                                 O--,---,--O" << endl;
		cout << "                                          ._O_.     O--=-O-=--O     \\ O /" << endl;
		cout << "    _._                      ,_O_,     O--<-+->--O      '-'          - -" << endl;
		cout << "   / O \\        ,-O-,     O--(---)--O       X            v            -" << endl;
		cout << "   \\| |/     O--=---=--O      >'>          / \\          / )          / \\" << endl;
		cout << "O--+=-=+--O      2''2          - -         -   -        ~  z        =   =" << endl << endl;
		return;
		
	}else if(n==4){
			
	cout << "		               !###" << endl;
	cout << "                       ! ###" << endl;
	cout << "                       !  ###" << endl;
	cout << "                       !   ###" << endl;
	cout << "  *   _________________!____###________O_______" << endl;
	cout << "/            O          \\    ##!     ==||       \\" << endl;
	cout << "\\O         /||--         \\    #!       //        \\" << endl;
	cout << "||\\_        \\\\            \\    !      _\\\\   O     \\" << endl;
	cout << "\\\\           LL            \\   !          ==||     \\" << endl;
	cout << " LL                         \\  !            //      \\" << endl;
	cout << "   \\                         \\ !           _\\       \\" << endl;
	cout << "    \\_________________________\\!______________________\\" << endl;
	return;
	}
	
	Continue();
	system("cls");
}






