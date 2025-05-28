/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                          OOP Concepts  -     ||      4-Pillars    ||
//                                              ||  1- Encapsulation ||  
//                                              ||  2- Inheritance   || 
//                                              ||  3- Abstraction   || 
//                                              ||  4- Polymorphism  || 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                   1- Structure                            [ Store different type data or data members - array of strut]                    
//                                   2- Classes                              [ a blueprint of object ]                    
//                                   3- Access Specifier                     [ Private + Public + Protected ]       
//                                   4- Constructor                          [ Default & Parameterized Constructor ]                     
//                                   5- File Handling                        [ ifstream == read    ofstream == write ]
//                                   6- Object Creation                      [ calls default const + destr + memory allocate ]                     
//                                   7- Encapsulation                        [ Group of Data members & Members function of Class]                                    
//                                   8- Member functions / Functions         [ Function in class + Function outside class ]                            
//                                   9- Getter/ Setter                       [ Set & Get value of data member ]                     
//                                   10- Destructor                          [ e.g: delete age (Free memory)  ]
//                                   11- Copy Constructor                    [ Shallow copy + Deep copy(Heap) (* new)  ]
//                                   12- Friend Fucntion + Friend Class      [ Access all type data from a class or function ]
//                                   13- Inheritance                         [ Single, Multiple, MultiLevel, Hybrid, Hierarchical]
//                                   14_ Modes of Inheritance                [ Public + Private + Protected ]
//                                   15- Static Classes & Functions          [ Accessable only Static to Static ]
//                                   16- Function Overloading + Overrriding  [ same name but different parameters + same name with virtual keyword ]
//                                   17- Polymorphism                        [ Compile-Overloading & Run time-Overriding ] 
//                                   18- Libraries                           [ #include .... libraries for specific purposes ]
//                                   19- UML - Unified Modeling Language     [ a Diagram that graphically represents block of code ]
//                                   20- Operator Overloading                [  overload an operator using +, -, *, /, ]
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////            
#include <iostream>    //     For Input & Output
#include <fstream>     //     File Handling
#include <string>      //     Check number of characters of string data type e.g: length()
#include <ctime>       //     For Time & Date
#include <cctype>      //     Checck a character is digit / alpha / upper / lower
#include <cmath>       //     Performs mathematical operations
#include <limits>      //     Know the boundary of Numerical data type
#include <iomanip>     //     Set Precision

//#include <curl/curl.h>      Pet API Integration              

using namespace std;


//   Class for Pet Shop Owner
class Owner{
	private:
		string name;
		string education;
		int age;
	public:
		Owner(){
			cout<<"Detail of Admin/Shop Owner. "<<endl;
		}
//		Getter/Setter using for Owner name
  void setname(string owner_name){
  	name=owner_name;
  }
  string getname(){
  	return name;
  }
//		Getter/Setter using for Owner age
    void setage(int owner_age){
  	age=owner_age;
  }
  int getage(){
  	return age;
  }
//		Getter/Setter using for Owner education
    void seteducation(string owner_education){
  	education=owner_education;
  }
  string geteducation(){
  	return education;
  }
};
//   Class of EndPortion that will show at end of the Program
class EndPortion{
	public:
	void Website(){
    cout<<endl;
	cout<<"                                                                                                                                                                                                                                                                                        Thanks for Visiting our Website!                       "<<endl;
	cout<<endl;
	cout<<"                       CopyRight @ 2025, Pet Master. All rights reserved. Powered by Shan Malik"<<endl;
		}
		
	friend class Customer;
};

class GmailAuthenticity{
   public:
       bool ValidGmail(string gmailing) {
        if (gmailing.empty()) {
            cout<<"Gmail cannot be eempty."<<endl;
            return false;
        }
        if (gmailing.find("@gmail.com") != string::npos) {
        return true;
        } 
		else {
        return false;
       }
        bool hasAt=false;
        bool hasDot=false;

        for (int i=0; i<gmailing.length(); i++){
        	char c=gmailing[i];
            if (isspace(c)) {
                cout << "Gmaiil contains whitespace.\n";
                return false;
            }
            if(gmailing[0]=='@' || gmailing[0]=='$' || gmailing[0]=='&' || gmailing[0]=='#' || gmailing[0]=='.' || gmailing[0]=='*'){
            	cout<<"Gmail is starting wiht invalid character! "<<endl;
            	return false;
			}
            if (c == '@') 
			hasAt = true;
            if (c == '.') 
			hasDot = true;
        }
        if (!hasAt || !hasDot) {
            cout << "Gmail must contain '@' and '.'"<<endl;
            return false;
        } 
        return true;
    }
};

//  Class for Login  & Sign_up  -  Inheitance
class CreateAccount: public GmailAuthenticity{
		int count;
		string gmail1, gmail2, gmail3;
		string password1, password2, password3;
	public:
		
		bool CheckPasword(string password){
			if(password.length()<8  || password.length()>16){
				cout<<"Invalid password.. It must be between 8 to 16 characters."<<endl;
				cout<<"Register Again..."<<endl;
				return false;
			}
			if(password.empty()){
				cout<<"Password cannot be empty. "<<endl;
				return false;
			}			
			if(password[0]=='@' || password[0]=='$' || password[0]=='&' || password[0]=='#' || password[0]=='*'){
				cout<<"Invalid password. It cannot start with Special symbol. "<<endl;
				cout<<"Register Again..."<<endl;
				return false;
			}
			
			bool containUpper=false;
			bool containLower=false;
			bool containDigit=false;
			bool containSpecial=false;
			
			for (int i=0; i<password.length(); ++i) {
            char c=password[i];
				if(islower(c)){
					containLower=true;
				}
	            if(isspace(c)){
						cout<<"Invalid Password. Whitespaces not allowed. Enter again!. "<<endl;
						return false;
			    }
				if(isupper(c)){
					containUpper=true;
				}
				
				if(isdigit(c)){
					containDigit=true;
				}
				if(!isalnum(c)){
					containSpecial=true;
				}
			}
		if (!containUpper) {
            cout << "Invalid Password. It must have at least one uppercase letter." << endl;
            cout<<"Register Again..."<<endl;
			return false;
        }
        if (!containSpecial) {
            cout << "Invalid Password. It has no special symbol." << endl;
            cout<<"Register Again..."<<endl;
			return false;
        }
        if (!containLower || !containDigit) {
            cout << "Invalid Password. It must contain both letters and numbers." << endl;
            cout<<"Register Again..."<<endl;
			return false;
        }
        return true;
}


//   Member Function for Login
		bool login(){
			GmailAgain:
			string gmails, pass;
			count=0;
				cout<<"Enter gmail: ";
				cin>>gmail1;
				if(ValidGmail(gmail1)){
					cout<<"";
				}
				else{
					cout<<"Invalid Gmail. "<<endl;
					goto GmailAgain;
				}
				PassAgain:
				cout<<"Enter Password: ";
				cin>>password1;
				if(CheckPasword(password1)){
					cout<<"";
				}
				else{
					cout<<"Invalid Password. "<<endl;
					cout<<"It must contain special symbol, uppercase, lowercase, digit and 8 to 16 characters. "<<endl;
					goto PassAgain;
				}
			ifstream fin("Records.txt");
			while(fin>>gmails>>pass){
				if(gmails==gmail1 && pass==password1){
					count=1;
				}
			}
			fin.close();
			
			if(count==1){
				system("cls");
				cout<<"Login Successfully..."<<endl;
				return true;
			}
			else{
				cout<<"User in not registered. Sign_Up first. "<<endl;
		        return false;
			}
			
		}
		
//		Member Function of Registration
		void registration(){
			again:
			  cout<<"Enter your gamil: ";
               cin>>gmail2;
               	if(ValidGmail(gmail2)){
					cout<<"Gmail is Correct. "<<endl;
				}
				else{
					cout<<"Invalid Gmail. "<<endl;
					goto again;
				}
			AgainPass:
			 cout<<"Enter the password: ";
             cin>>password2;
				if(CheckPasword(password2)){
					cout<<"";
				}
				else{
					cout<<"Invalid Password. "<<endl;
					cout<<"It must contain special symbol, uppercase, lowercase, digit and 8 to 16 characters. "<<endl;
					goto AgainPass;
				}
			 ofstream f2("Records.txt", ios::app);
			 f2<<gmail2<<' '<<password2<<endl;
			 system("cls");
			 cout<<"Registration is Successful. "<<endl;
			 cout<<endl;
		}
		
//		Member Function for Forgot Passord
		bool forgot(){ 
			string Gmail, new_password;
			cout<<"You forgot the password? Don't Worry! "<<endl;
			cout<<"Find your Password by your Gmail "<<endl;
				int count=0;
				Again:
				cout<<"Enter your Gmail: ";
				cin>>gmail3;
				if(ValidGmail(gmail3)){
					cout<<"";
				}
				else{
					cout<<"Invalid Gmail. "<<endl;
					goto Again;
				}
				ifstream f2("Records.txt");
				while(f2>>Gmail>>new_password){
					if(Gmail==gmail3){
						count=1;
					}
				}
						f2.close();
						if(count==1){
							system("cls");
							cout<<"Your account is found. "<<endl;
							cout<<"Your password is: "<<new_password<<endl;
							return true;
						}
						else{
							cout<<"Sorry! Account Not Found."<<endl;
							return false;
						}
			}

//     Member Function for Account Verifiction
		void Accounts(){
		start:
			cout<<endl;
			cout<<"Create an Account first. "<<endl;
	        cout<<"                       Press  1-   Login"<<endl;
			cout<<"                       Press  2-   Sign-up"<<endl;
			cout<<"                       Press  3-   Forgot Password"<<endl;
			int choice;
			cout<<"Enter your choice: ";
			cin>>choice;
			cout<<endl;
			switch(choice){
				case 1:
						if(login()==false){
						goto start;
						}
					break;
				case 2:
				registration();
					break;
				case 3:
					if(forgot()==false){
						goto start;
						}
					break;
				default:
					cout<<"Enter valid choice. "<<endl;
					break;
			}
		}			
};

class checkRecord:public CreateAccount{
	public:
		checkRecord(){}
	    void Record(){
		string gmail, newGmail, newPassword;
		setGmail:
		int start=0;
		cout<<"Enter you Gmail: ";
		cin>>gmail;
		if(ValidGmail(gmail)){}
				else{
					cout<<"Invalid Gmail. "<<endl;
					goto setGmail;
				}
			ifstream f2("Records.txt");
	         while(f2>>newGmail>>newPassword){
					if(gmail==newGmail){
                        start=1;
					}
				}
					f2.close();
					if(start==1){
						cout<<"Your Credential Found! You can procced with your previous detial. "<<endl;
					}
					else{
						cout<<"It think you are new Here. Create an Account first. "<<endl;
						Accounts();
					}
		}
};

//   Inheritance using------A Parent Class of Entering Customer detail    
class Customer{
	private:
		string cnic;
		string cont_num;
		string name;
		int age;
		string country;
		bool containDigit;
		string CountryCode;
	public:
//		Constructor of License Class
		Customer(){
			cin.ignore();
			NameAgain:
			cout<<"Enter Your Name: ";
		   	getline(cin,name);
				if(name.empty()){
					cout<<"Name cannot be empty."<<endl;
					goto NameAgain;
				}		   	
            for(int i=0; i<name.length(); i++){
            	char c=name[i];
            	if(isdigit(c)){
            		cout<<"Invalid Name. Only Alphabetic. Enter Again!. "<<endl;
            		goto NameAgain;
				}
			}
		}			
			
//		    Member Function for  Cnic entering
		    void enter_cnic(){
			Enter:
		    cout<<"Enter you CNIC (13 digits): ";
			cin>>cnic;
            for(int i=0; i<cnic.length(); i++){
            	char c=cnic[i];
            	if(isspace(c)){
            		cout<<"Invalid CNIC. Space not Allowed. Enter Again!. "<<endl;
            		goto Enter;
				}
			}
            for(int i=0; i<cnic.length(); i++){
            	char c=cnic[i];
            	if(isalpha(c)){
            		cout<<"Invalid CNIC. Only Digit. Enter Again!. "<<endl;
            		goto Enter;
				}
			}
				if(cnic.empty()){
					cout<<"CNIC cannot be empty. ";
					goto Enter;
				}
			int length=cnic.length();
			if(length<13){
				cout<<"Error: Too short CNIC."<<endl;
				cout<<"CNIC must be 13 digits long. & You entered "<<cnic.length()<<" digits only. "<<endl;
		          goto Enter;
			}
			else if(length>13){
				cout<<"Error: Too long CNIC."<<endl;
				cout<<"CNIC must be 13 digits long. & You entered  "<<cnic.length()<<" digits. "<<endl;
				goto Enter;
			}
			else {
				cout<<"<<<    CNIC is 100% correct.   >>>"<<endl;
			    }
			    
			}
			
//			Member Function for Phone Number Entering
			void enter_number(){
					cout<<"Enter your contact number But First"<<endl;
					CountryAgain:
					cout<<"Enter your country: ";
					cin.ignore();
					getline(cin,country);
					CAgain:
					if(country=="Pakistan" || country=="pakistan"){
						CountryCode="+92";
						cout<<"+92 ";
					}
					else if(country=="India" || country=="india"){
						CountryCode="+91";
						cout<<"+91 ";
					} 
					else if(country=="dubai" || country=="Dubai"){
						CountryCode="+971";
						cout<<"+971 ";
					}
					else if(country=="america" || country=="America"){
						CountryCode="+1";
						cout<<"+1 ";
					}
					else if(country=="australia" || country=="Australia"){
						CountryCode="+62";
						cout<<"+62 ";
				    }
					else if(country=="iran" || country=="Iran"){
						CountryCode="+98";
						cout<<"+98 ";
					}
					else if(country=="saudi arabia" || country=="Saudi Arabia" || country=="Saudi arabia"){
						CountryCode="+966";
						cout<<"+966 ";
					}
					else if(country=="afghanistan" || country=="Afghanistan"){
						CountryCode="+93";
						cout<<"+93 ";
					}
					else{
						cout<<" Sorry! Out of range country. Or Select Country Again! "<<endl;
						goto CountryAgain;
					}

			cin>>cont_num;
            for(int i=0; i<cont_num.length(); i++){
            	char c=cont_num[i];
            	if(isspace(c)){
            		cout<<"Invalid Contact Number. Spaces not Allowed. Enter Again!. "<<endl;
            		goto CAgain;
				}
			}
            for(int i=0; i<cont_num.length(); i++){
            	char c=cont_num[i];
            	if(isalpha(c)){
            		cout<<"Invalid Contact Number. Only Digit Allowed. Enter Again!. "<<endl;
            		goto CAgain;
				}
			}
			int length=cont_num.length();
			if(length<10){
				cout<<"Error: Too short Number."<<endl;
				cout<<"Contact number must be 11 or 10 digits long. & You entered "<<cont_num.length()<<" digits only. "<<endl;
			goto CAgain;
			}
			else if(length>11){
				cout<<"Error: Too Long Contact Number."<<endl;
				cout<<"Contact number must be 11 or 10 digits long. & You entered  "<<cont_num.length()<<" digits. "<<endl;
			goto CAgain;
			}
			else {
				cout<<"---Contact number is 100% correct.--- "<<endl;
			}
			}
			//		Member Function for Age verification
	     void verification(EndPortion& Age){
			cout<<"Enter your age: ";
			cin>>age;
		    if(age>=18){
			system("cls");
			cout<<"Welcome to our Pet Shop Sir!"<<endl;
			cout<<"______________________________________"<<endl;
		}
		else{
			cout<<"Sorry! Privacy Policy for under 18. "<<endl;
			cout<<"You cannot keep or buy Animals or Birds. "<<endl;
			Age.Website();
			exit(0);
		}
	}
//			Member Function for printing Viewer Data
            void print_data(){
            				cout<<endl;
							cout<<"Your name is: "<<name<<endl;
            				cout<<"Your cnic is: "<<cnic<<endl;
            				cout<<"Your Contact Number is: ";
            				cout<<CountryCode;
							cout<<" "<<cont_num<<endl;
            				cout<<"Your Age is: "<<age<<endl;
            				cout<<"Your record has been saved. "<<endl;
            				cout<<"__________________________"<<endl;
			}
		
};



//   Inheritance using------A "Male" child Class of Customer Class  
class male:public Customer{
	public:
		male(){
			cout<<"Okay, Our male Manager will guide you about Pet Shop. "<<endl;
			cout<<"____________________"<<endl;
		}
		
};

//   Inheritance using------A "Female" child Class of Customer class
class female:public Customer{
	public:
		female(){
			cout<<"Okay, Our female Manager will guide you about Pet Shop. "<<endl;
			cout<<"_____________________"<<endl;
		}
		
};
//       Class for pet shops and available cities
class PetShop{
	private:
		int pet_shops;
		string city;
	public:
//		Constructor of Class
		PetShop(){
           pet_shops=2;
		}
		
//		Destructor of Class
		  ~PetShop() 
		{
        cout <<"PetShop 1 & 2"<< endl;
        }
//		Member function for nearest cities to shop
		void cityNearShop(){
			pet_shops=2;
			cout<<"There are "<<pet_shops<<" Pet Shops of Birds & Animals at same location. "<<endl;
			cout<<endl;
			cout<<"   List of cities that can easily access to our Pet shops and check distance   "<<endl;
			cout<<"1- Lahore"<<endl<<"2- Karachi"<<endl<<"3- Islamabad"<<endl<<"4- Multan"<<endl<<"5- Hydrabad"<<endl<<"6- Sahiwal"<<endl<<"7- Okara  "<<endl;
			cout<<"Enter your city name: ";
			cin>>city;
		}
		
//		Member function for checking distance city to shop
		void city_distance(){
			if(city=="Lahore" || city=="lahore"){
				system("cls");
				cout<<"    Distance from shop to Lahore is 70 KM "<<endl;
				cout<<"                By Bike                      By Auto                      By Car     "<<endl;
				cout<<"            1 hour 50 minutes            2 hour 30 minutes            1 hour 20 minutes"<<endl;
				cout<<endl;
			}
			else if(city=="Islamabad" || city=="islamabad"){
				system("cls");
				cout<<"    Distance from shop to Islamabad is 150 kM "<<endl;
				cout<<"               By Bike                      By Auto                      By Car     "<<endl;
				cout<<"          2 hour 50 minutes             3 hour 10 minutes            1 hour 50 minutes"<<endl;
			}
			else if(city=="karachi" || city=="Karachi"){
				system("cls");
				cout<<"    Distance from shop to Karachi is 130 kM "<<endl;
				cout<<"              By Bike                      By Auto                      By Car     "<<endl;
				cout<<"          2 hour 30 minutes              3 hour 10 minutes           1 hour 40 minutes"<<endl;
				cout<<endl;
			}
			else if(city=="multan" || city=="Multan" ){
				system("cls");
				cout<<"    Distance from shop to Multan is 50 KM"<<endl;
				cout<<"             By Bike                      By Auto                      By Car     "<<endl;
				cout<<"          1 hour 10 minutes            1 hour 50 minutes           1 hour 00 minutes"<<endl;
				cout<<endl;
			}
			else if(city=="Hydrabad" || city=="hydrabad"){
				system("cls");
				cout<<"    Distance from shop to Hydrabad is 120 KM "<<endl; 
				cout<<"            By Bike                      By Auto                      By Car     "<<endl;
				cout<<"         2 hour 20 minutes           3 hour 00 minutes           1 hour 30 minutes"<<endl;
				cout<<endl;
			}
			else if(city=="Sahiwal" || city=="sahiwal"){
				system("cls");
				cout<<"    Distance from shop to Sahiwal is   80 KM. "<<endl;
				cout<<"           By Bike                      By Auto                      By Car     "<<endl;
				cout<<"        1 hour 05 minutes           1 hour 20 minutes           0 hour 50 minutes"<<endl;
				cout<<endl;
			}
			else if(city=="Okara" || city=="okara"){
				system("cls");
				cout<<"    Distance from shop to Okara is    100 KM  "<<endl;
				cout<<"           By Bike                      By Auto                      By Car     "<<endl;
				cout<<"         1 hour 20 minutes           1 hour 55 minutes           1 hour 05 minutes"<<endl;
				cout<<endl;
			}
			else{
				system("cls");
					cout<<"    Sorry! Invalid City or Your city is far away from our pet shops"<<endl;
					cout<<"===    But You can get some informtion about pets    ==="<<endl;
			}
		}	
   };

//           Structure of Birds Data
struct PetBirds
{
		string bird_name;
		int bird_price;
		bool isBird_Available;
		int bird_age;
		int totalBirds;
};

//     Function for dispalying Birds data
void display_Birds(PetBirds bird)
{
	cout<<"Bird name is: "<<bird.bird_name<<endl;
	cout<<"Bird Price is: "<<bird.bird_price<<endl;
	cout<<"Bird Age is: "<<bird.bird_age<<endl;
	cout<<"Bird Availability: "<<(bird.isBird_Available ? "It is available": "It is not available.")<<endl;
	cout<<"Total "<<bird.bird_name<<" are: "<<bird.totalBirds<<endl;
} 

//          Function for Finding bird by Name
void find_Birds(PetBirds B1[], PetBirds B2[]){
	string search;
	cout<<"Enter Bird_pet Name you find: ";
	cin>>search;
	bool flag=false;
	for(int i=0; i<9; i++){
		if(search==B1[i].bird_name || search==B2[i].bird_name){
			cout<<"Bird age is: "<<B1[i].bird_age<<"  years"<<endl;
			cout<<"Bird Price is: "<<B1[i].bird_price<<endl;
			cout<<"Bird Availibiltiy: "<<(B1[i].isBird_Available ? "Yes, It is available. " : "It is not available. ")<<endl;
			cout<<"Total "<<B1[i].bird_name<<" are: "<<B1[i].totalBirds<<endl;
			flag=true;
		}
	}
	if(!flag){
		cout<<">>>   Sorrry, this Bird-pet is not available. "<<endl;
	}
}

// Function for buying Birds
void buy_bird(PetBirds B1[], PetBirds B2[]){
	string enter_bird;
	double Bird_discount=0.0, finalPrice=0.0;
	cout<<"Enter bird name you want to buy: ";
	cin>>enter_bird;
	bool flagg=false;
	for(int i=0; i<9; i++){
		if((enter_bird==B1[i].bird_name || enter_bird==B2[i].bird_name)  && B1[i].isBird_Available==true){
			startFromBird:
			cout<<"How many "<<B1[i].bird_name<<" you want to buy? "<<endl;
			int howMany;
			cin>>howMany;
			if(howMany>B1[i].totalBirds){
				cout<<"Sorry, there are only "<<B1[i].totalBirds<<" available. "<<endl;
				cout<<"You can buy maximum "<<B1[i].totalBirds<<endl;
				goto startFromBird;
			}
			else{
			cout<<"                      Congratulations! You  bought it. "<<endl;
			}
			cout<<"                      It's original Price is: "<<B1[i].bird_price<<endl;
			cout<<"                      The total amount of "<<howMany<<" "<<B1[i].bird_name<<" will be: "<<B1[i].bird_price*howMany<<endl;
			Bird_discount=B1[i].bird_price*howMany*0.15;
			finalPrice=(B1[i].bird_price*howMany)-Bird_discount;
			cout<<"                      But with discount, it will be "<<fixed<<setprecision(5)<<finalPrice<<endl;
			cout<<"                      If you want to get online delievery then 1000 will be add in total amount. "<<endl;
			string saying;
			cout<<"Enter yes or no for delievery: ";
			cin>>saying;
			if(saying=="yes" || saying=="Yes"){
			cout<<"                      Total price of "<<B1[i].bird_name<<" will be: "<<finalPrice+1000<<endl;
			cout<<"                      One Bird has been Sold. "<<endl;
			}
			else{
				cout<<"<<<   Thanks for replying.   >>>"<<endl;
			}
			 flagg = true; // Set flagg to true
            break;
		}
	}
	if(!flagg){
		cout<<"Sorry! This bird is not available or has already bought. "<<endl;
		cout<<"Bird Not Sold. "<<endl;
	}
}


//   Structure of Animals
struct PetAnimals
{
		string animal_name;
		int animal_price;
		bool isAnimal_Available;
		int animal_age;
		int totalAnimals;
};

//   Function for finding Animnals by its name
void find_Animals(PetAnimals A1[], PetAnimals A2[])
{
	cout<<"<<<       Get & Find Animal Data by name     >>>"<<endl;
	string search_animal;
	cout<<"Enter Animal_pet Name you find: ";
	cin>>search_animal;
	bool flag=false;
	for(int i=0; i<12; i++){
		if(search_animal==A1[i].animal_name || search_animal==A2[i].animal_name){
			cout<<"Animal age is: "<<A1[i].animal_age<<"  years"<<endl;
			cout<<"Animal Price is: "<<A1[i].animal_price<<endl;
			cout<<"Animal Availibiltiy: "<<(A1[i].isAnimal_Available ? "Yes, It is available. " : "It is not available. ")<<endl;
			cout<<"Total "<<A1[i].animal_name<<" are "<<A1[i].totalAnimals<<endl;
		}
		flag=true;
	}
	if(!flag){
		cout<<"    Sorrry, this Animal-pet is not available. "<<endl;
	}
}

//      Function for dispalying all Animals data that are available
void display_Animals(PetAnimals animal)
{
	cout<<"Animal name is: "<<animal.animal_name<<endl;
	cout<<"Animal Price is: "<<animal.animal_price<<endl;
	cout<<"Animal Age is: "<<animal.animal_age<<endl;
	cout<<"Animal Availability: "<<(animal.isAnimal_Available ? "It is available": "It is not available.")<<endl;
	cout<<"Total "<<animal.animal_name<<" are "<<animal.totalAnimals<<endl;
}

//     Function for buying Animal
void buy_animal(PetAnimals A1[], PetAnimals A2[]){
	string enter_animal;
	double Animal_discount=0.0, finalPrice=0.0;
	cout<<"Enter animal name you want to buy: ";
	cin>>enter_animal;
	bool flagg=false;
	for(int i=0; i<12; i++){
		if((enter_animal==A1[i].animal_name || enter_animal==A2[i].animal_name)  && A1[i].isAnimal_Available==true){
		    startFromAnimal:
			cout<<"How many "<<A1[i].animal_name<<" you want to buy? "<<endl;
			int howMany;
			cin>>howMany;
			if(howMany>A1[i].totalAnimals){
				cout<<"Sorry, there are only "<<A1[i].totalAnimals<<" available. "<<endl;
				cout<<"You can buy maximum "<<A1[i].totalAnimals<<endl;
				goto startFromAnimal;
			}
			else{
			cout<<"                    Congratulations! You  bought it. "<<endl;
			}
			cout<<"                    It's Original Price is: "<<A1[i].animal_price<<endl;
			cout<<"                    The total amount of "<<howMany<<" "<<A1[i].animal_name<<" will be "<<A1[i].animal_price*howMany<<endl;
			Animal_discount=A1[i].animal_price*howMany*0.25;
			finalPrice=(A1[i].animal_price*howMany)-Animal_discount;
			cout<<"                    But with discount, it will be "<<fixed<<setprecision(5)<<finalPrice<<endl;
			cout<<"                    If you want to get online delievery then 2000 will be add in total amount. "<<endl;
			string saying;
			cout<<"Enter yes or no for delievery: ";
			cin>>saying;
			if(saying=="yes" || saying=="Yes"){
				cout<<"                Then total price of "<<A1[i].animal_name<<" will be: "<<finalPrice+2000<<endl;
	            cout<<"                One Animal has been Sold. "<<endl;		
			}
			else{
				cout<<"<<<   Thanks for replying.   >>>"<<endl;
			}
			 flagg = true; // Set flagg to true
            break;
		}
	}
	if(!flagg){
		cout<<"Sorry! This Animal is not available or has already bought. "<<endl;
	cout<<"Animal not Sold. "<<endl;
	}
}


//    Class of About us
class AboutUs{
	private:
		int put;
public:
	void check(){
		system("cls");
		cout<<"Recaptcha checking! Prove you are human.."<<endl;
		int put;
		cout<<" 5*5/5+9= ";
		cin>>put;
		if(put==14){
			cout<<"Proved Successfully! You can check our information. "<<endl;
	cout<<"                _____________________________ About us ____________________________"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"***********************************************************************************************************"<<endl;
	cout<<"About us: "<<endl;
	cout<<"         Looking for the best pet shop in Pakistan? PetMaster is the leading "<<endl;
	cout<<"         online pet store in Pakistan, offering a wide range of pet products "<<endl; 
	cout<<"    	    including premium pet food, pet accessories, grooming supplies, "<<endl; 
	cout<<"  		and toysall in one place."<<endl;
	cout<<endl;
	cout<<"Why Choose us? "<<endl;
	cout<<"    100% Satishfied               Best Choice For             Healthy             Pets Under Professional   "<<endl;
	cout<<"       Customer                        You                      Pets                    Doctors             "<<endl;
	cout<<"    ________________              ________________           _________            ________________________  "<<endl; 
	cout<<endl;
	cout<<"                          Visit our Website        "<<endl;
    cout<<"        Website:  https://www.linkedin.com/in/shan-maliik/"<<endl;
    cout<<"        Website:  file:///C:/Users/New%20User/Downloads/Pet%20Mangement%20system/Shan%20Malik.html"<<endl;
    cout<<endl;
    cout<<"************************************************************************************************************"<<endl;
	     
    cout<<endl;
		}
		else{
			cout<<"Sorry! It seems you are robot. "<<endl;
		cout<<endl;
		}
	}
};

//         Class of Contact Us Detail
class ContactUs{
	private:
		string contact_number1;
		string contact_number2;
		string telephone;
		string gmail;
	public:
		ContactUs(){
			contact_number1="+923093391591";
			contact_number2="+923294676752";
			telephone= "042 33339878";
			gmail="f2024266410@umt.edu.pk";
		}
	void Contact(){
		cout<<"*************************************************************************************************"<<endl;
		cout<<"                          <<<   24/7 Service Available    >>>"<<endl;
		cout<<"    Contact us:                   Email Us:                        Telephone Hotline:     "<<endl;
		cout<<"   "<<contact_number1<<"           "<<gmail<<"                        "<<telephone<<endl;
		cout<<"   "<<contact_number2<<"           "<<gmail<<"                        "<<telephone<<endl;
		cout<<"*************************************************************************************************"<<endl; 
		cout<<endl;
	}
};


bool addBirds(PetBirds B1[], PetBirds B2[]){
	string checkEntity;
	int howMany;
	bool flag=false;
	string username, password;
	cout<<"Are you a admin?  Yes or No: ";
	cin>>checkEntity;
	if(checkEntity=="yes" || checkEntity=="Yes"){
		cout<<"Enter Username: ";
		cin>>username;
		cout<<"Enter password: ";
		cin>>password;
		if(username=="admin" && password=="1122"){
			system("cls");
			cout<<"Successfully Admin portal Open. Now you can add Birds. "<<endl;
			cout<<"Currently there are 9 birds availabel. "<<endl;
			cout<<"Here is the list: "<<endl;
	        for(int i=0; i<9; i++){
	        	cout<<"                    Total "<<B1[i].bird_name<<" are:       "<<B1[i].totalBirds<<endl;
			}
			string wantAllBirds;
			cout<<"Do you want to add all Birds? ";
			cin>>wantAllBirds;
            if(wantAllBirds=="yes" || wantAllBirds=="Yes"){
            	for(int  i=0; i<9; i++){
            	cout<<"How many "<<B1[i].bird_name<<" do you want to add? ";
            	cin>>howMany;
            	cout<<"                    Now the total "<<B1[i].bird_name<<" are: "<<B1[i].totalBirds+howMany<<endl;
            	B1[i].totalBirds=B1[i].totalBirds+howMany;
			}
			}
			else if(wantAllBirds=="No" || wantAllBirds=="no"){
				string addBird;
				cout<<"Enter bird Name you want to add: ";
				cin>>addBird;
				for(int i=0; i<9; i++){
					if(addBird==B1[i].bird_name || addBird==B2[i].bird_name){
						cout<<"How many "<<B1[i].bird_name<<" you want to add? ";
						cin>>howMany;
						cout<<"                Now the total "<<B1[i].bird_name<<" are: "<<B1[i].totalBirds+howMany<<endl;
						B1[i].totalBirds=B1[i].totalBirds+howMany;
						flag=true;
					}
				}
				if(!flag){
				cout<<"Sorry! Bird with this name is not available. "<<endl;
			}
		}
		else{
			cout<<"Invalid Entry! "<<endl;
		}
		}
        else{
        	return false;
		}
		return true;
	}
		else{
			cout<<"Only admin can add new birds. "<<endl;
			return false;
		}
}

bool addAnimals(PetAnimals A1[], PetAnimals A2[]){
	string checkEntity;
	int howMany;
	bool flag=false;
	string username, password;
	cout<<"Are you a admin?  Yes or No: ";
	cin>>checkEntity;
	if(checkEntity=="yes" || checkEntity=="Yes"){
		cout<<"Enter Username: ";
		cin>>username;
		cout<<"Enter password: ";
		cin>>password;
		if(username=="admin" && password=="1122"){
			system("cls");
			cout<<"Successfully Admin portal Open. Now you can add Animals. "<<endl;
			cout<<"Currently there are 12 Animals availabel. "<<endl;
			cout<<"Here is the list: "<<endl;
	        for(int i=0; i<12; i++){
	        	cout<<"                    Total "<<A1[i].animal_name<<" are:       "<<A1[i].totalAnimals<<endl;
			}
			string wantAllAnimals;
			cout<<"Do you want to add all Animals? ";
			cin>>wantAllAnimals;
            if(wantAllAnimals=="yes" || wantAllAnimals=="Yes"){
            	for(int  i=0; i<12; i++){
            	cout<<"How many "<<A1[i].animal_name<<" do you want to add? ";
            	cin>>howMany;
            	cout<<"                    Now the total "<<A1[i].animal_name<<" are: "<<A1[i].totalAnimals+howMany<<endl;
            	A1[i].totalAnimals=A1[i].totalAnimals+howMany;
			}
			}
			else if(wantAllAnimals=="No" || wantAllAnimals=="no"){
				string addAnimals;
				cout<<"Enter Animal Name you want to add: ";
				cin>>addAnimals;
				for(int i=0; i<12; i++){
					if(addAnimals==A1[i].animal_name || addAnimals==A2[i].animal_name){
						cout<<"How many "<<A1[i].animal_name<<" you want to add? ";
						cin>>howMany;
						cout<<"                Now the total "<<A1[i].animal_name<<" are: "<<A1[i].totalAnimals+howMany<<endl;
						A1[i].totalAnimals=A1[i].totalAnimals+howMany;
						flag=true;
					}
				}
				if(!flag){
				cout<<"Sorry! Animal with this name is not available. "<<endl;
			}
		}
		else{
			cout<<"Invalid Entry! "<<endl;
		}
		}
        else{
        	return false;
		}
		return true;
	}
		else{
			cout<<"Only admin can add new Animals. "<<endl;
			return false;
		}
}

void ShowDateTime(){
	time_t current_dt=time(0);
	char* result=ctime(&current_dt);
	cout<<"                  Current Time & date is:      "<<result;
	cout<<"*********************************************************************************************************"<<endl;
	cout<<"Welcome to Our Pet-Shop                 Email us: f2024266410@umt.edu.pk     HotLine: +92-3093391591 "<<endl;
	cout<<"*********************************************************************************************************"<<endl;
	cout<<endl;
}




//                 Main Body of Entire code    (Driver of Code)
int main(){

	ShowDateTime();
	cout<<"ReCaptcha Checking!  Prove that You are Human?  "<<endl;
	string prove="b";
	cout<<"5 * 6 - 10 + 5 ? "<<endl;
	cout<<"a. 29         b. 25          c. -45           d. 5"<<endl;
	cout<<"Enter you answer: a/b/c/d= ";
	cin>>prove;
	int length=prove.length();
	if(length== 1 && (prove=="b" || prove=="B")){
		cout<<"You are a Human. "<<endl;
	}
	else if(length>1){
		cout<<"It seems you are a robot. You cannot procced furthur more. "<<endl;
		exit(0);	
	}
	else{
		cout<<"It seems you are a robot. You cannot procced furthur more. "<<endl;
		exit(0);
	}
cout<<"                          Welcome to Pet Management System                    "<<endl;
cout<<"   ________________________________________________________________________________________________      "<<endl;
cout<<"   |    ________                                 _________                             ________   |      "<<endl;
cout<<"   |    |       |   _______         |            |           |                         |       |  |      "<<endl;
cout<<"   |    |       |   |      |    ____|____        |           |                         |       |  |      "<<endl;
cout<<"   |    |_______|   |______|        |            |________   |________    ___________  |       |  |      "<<endl;
cout<<"   |    |           |               |     =====           |  |       |   |          |  |_______|  |      "<<endl;
cout<<"   |    |           |               |                     |  |       |   |          |  |          |      "<<endl;
cout<<"   |    |           |_______        |____        _________|  |       |   |__________|  |          |      "<<endl;
cout<<"   |______________________________________________________________________________________________|      "<<endl;
cout<<endl;
 
    
   EndPortion end; 
   Owner shopOwner;
   shopOwner.setname("Shan Malik");
   shopOwner.setage(21);
   shopOwner.seteducation("BS Marketing & Sales");
   cout<<endl;
   cout<<"   Name of Shop Owner is        "<<"       Age of Shop Owner         "<<"    Education of Shop Owner is "<<endl;
   cout<<"        "<<shopOwner.getname()<<"                         is "<<shopOwner.getage()<<"                         "<<shopOwner.geteducation()<<endl;
   cout<<"  _________________________          ______________________          _________________________"<<endl; 
   cout<<endl;

   int checkCooky;
   cout<<"This website uses Cookies! "<<endl;
   cout<<"We use Cookies for user trust and legal compliance."<<endl;
   cout<<"                          Press 1-  Accept all Cookies            "<<endl;
   cout<<"                          Press 2- Deny or Not Accept              "<<endl;
   cout<<"Press: ";
   cin>>checkCooky;
   
   switch(checkCooky){
   	case 1:
   		cout<<"You can proceed furture more. "<<endl;
   		break;
   	case 2:
   		cout<<"Sorry! This is against our Cookies Policy. "<<endl;
   		end.Website();
   		exit(0);
   		break;
   	default:
   		cout<<"Invalid entry! "<<endl;
   		break;
   }

   string checkEntity;
   startEntity:
   cout<<"Are you a Customer or a Visitor? ";
   cin>>checkEntity;
   if(checkEntity=="Customer" || checkEntity=="customer"){
   	checkRecord check;
	starting:
	cout<<"Have you ever visited our Shop before?  Yes/No"<<endl;
	string tell;
	cin>>tell;
	if(tell=="Yes" || tell=="yes"){
		check.Record();
	}
	else{
			check.Accounts();
	}
   }
   else if(checkEntity=="Visitor" || checkEntity=="visitor"){
   	cout<<"No need of Account creation. But, You have no authority to buy pets."<<endl; 
	cout<<"But enter some personel information. "<<endl;
   }
   else{
   	cout<<"Invalid entry. "<<endl;
   	goto startEntity;
   }
	

//    Inheritance using 
    string gender;
    EnterGender:
    cout<<"Enter your gender: ";
    cin>>gender;
                for(int i=0; i<gender.length(); i++){
            	char c=gender[i];
            	if(isdigit(c)){
            		cout<<"Invalid Gender. Only Alphabetic. Enter Again!. "<<endl;
            		goto EnterGender;
				}
			}
    if(gender=="male" || gender=="Male"){
    	//	Making object of child class("male") of Customer class("parent")
    	male m1;
    	m1.enter_cnic();
    	m1.enter_number();
    	m1.verification(end);
    	m1.print_data();
	}
	else if(gender=="female" || gender=="Female"){
		//	Making object of child class("male") of Customer class("parent")
		female f1;
		f1.enter_cnic();
    	f1.enter_number();
    	f1.verification(end);
    	f1.print_data();
	}
	else{
		cout<<"Invalid entry.. "<<endl;
		end.Website();
		exit(0);
	}
	
	cout<<endl;
{
	cout<<"<<<<  Check your distance from shop to your city    >>>>"<<endl;
	PetShop city;
	city.cityNearShop();
	city.city_distance();
}
	cout<<endl;
	
	AboutUs detail;	
	ContactUs Now;
	
	double balance;
	string bank_name;
	string saying, say;
	
//     Array of Birds Structure starting with capital letter
PetBirds B1[9]=
{
          {"Parrot", 8000, true, 2, 20}, {"Kiwi", 6000, true, 4, 30}, {"Panguins", 3000, true, 4, 25},
          {"Eagle", 7000, true, 1, 50},   {"Duck", 9000, true, 3, 60}, {"Doves", 10000, true, 2, 40},
          {"Pigeons", 5000, true, 2, 45}, {"Owls", 3000, true, 2, 30}, {"Hen", 1000, true, 1, 55},
};

//     Array of Animal Structure starting with Capital letter
PetAnimals A1[12]=
{
         {"Lion", 50000, true, 2, 30},    {"Cat", 12000, true, 1, 60},            {"Bull Dog", 150000, true, 3, 10},
         {"Tiger", 200000, true, 2, 20}, {"White Rat", 9000, true, 4, 55},      {"Chinese Cat", 18000, true, 2, 15},
         {"Fox", 70000, true, 4, 45},     {"Snake", 10000, true, 5, 35},          {"Vixen", 40000, true, 2, 35},
         {"Zebra", 120000, true, 3, 30},  {"Black Panthar", 100000, true, 5, 10}, {"Husky", 40000, true, 3, 20},
};
//     Array of Birds Structure starting with samll letter
PetBirds B2[9]=
{
          {"parrot", 8000, true, 2, 20}, {"kiwi", 6000, true, 4, 30}, {"panguins", 3000, true, 4, 25},
          {"eagle", 7000, true, 1, 50},   {"duck", 9000, true, 3, 60}, {"doves", 10000, true, 2, 40},
          {"pigeons", 5000, true, 2, 45}, {"owls", 3000, true, 2, 30}, {"hen", 1000, true, 1, 55},
};

//     Array of Animals Structure starting with samll letter
PetAnimals A2[12]=
{
         {"lion", 50000, true, 2, 30},    {"cat", 12000, true, 1, 60},            {"bull dog", 150000, true, 3, 10},
         {"tiger", 200000, true, 2, 20}, {"white Rat", 9000, true, 4, 55},      {"chinese cat", 18000, true, 2, 15},
         {"fox", 70000, true, 4, 45},     {"snake", 10000, true, 5, 35},          {"vixen", 40000, true, 2, 35},
         {"zebra", 120000, true, 3, 30},  {"black panthar", 100000, true, 5, 10}, {"husky", 40000, true, 3, 20},
};

//        using start for goto Statement
start:
cout<<"                                          ******************************      "<<endl;
cout<<"                                          ** 	Menu of our Pet Shop **       "<<endl;
cout<<"                                          ******************************         "<<endl;
cout<<endl;
cout<<"                           ***********************************************************   "<<endl;
cout<<"                           *  Press  1-        View available Birds type & detail    *"<<endl;
cout<<"                           *  Press  2-        View available Animals type & detail  *"<<endl;
cout<<"                           *  Press  3-        Search Bird by Name                   *"<<endl;
cout<<"                           *  Press  4-        Search Animal by Name                 *"<<endl;
cout<<"                           *  Press  5-        Check Discount on Pets                *"<<endl;
cout<<"                           *  Press  6-        Buy Pets                              *"<<endl;
cout<<"                           *  Press  7-        Add Birds                             *"<<endl;
cout<<"                           *  Press  8-        Add Animals                           *"<<endl;
cout<<"                           *  Press  9-        About Us                              *"<<endl;
cout<<"                           *  Press  10-       Contact Us                            *"<<endl;
cout<<"                           *  Press  0-        Exit                                  *"<<endl;
cout<<"                           ***********************************************************    "<<endl;
cout<<endl;

int choice;
cout<<"Enter your choice: ";
cin>>choice;

//      Running switch statememt for performing above all 8 functionalities
switch(choice)
{
	case 1:
		   system("cls");
		   ShowDateTime();
		   cout<<"         Detail of 9 Available Birds           "<<endl;
		   cout<<endl;
	       for(int i=0; i<9; i++)
	       {
	           cout<<"<<<<   Bird type: "<<i+1<<"   >>>>"<<endl;
	           display_Birds(B1[i]);
	           cout<<"******************************************"<<endl;
           }
           cout<<endl;
           ContinueProgram:
           cout<<"Do you want to continue Program? ";
           cin>>say;
           if(say=="Yes" || say=="yes"){
           	system("cls");
           	ShowDateTime();
           	goto start;
		   }
		   else{
		   	end.Website();
		   	exit(0);
		   }
           break;
    case 2:
    	system("cls");
    	ShowDateTime();
   	       cout<<"     Detail of 12 Available Animals  "<<endl;
   	       cout<<endl;
	       for(int i=0; i<12; i++)
	       {
	           cout<<"<<<<   Animal type: "<<i+1<<"   >>>>"<<endl;
	           display_Animals(A1[i]);
	           cout<<"******************************************"<<endl;
           }
           cout<<endl;
           goto ContinueProgram;
           break;
    case 3:
    	   cout<<"*************Here is Bird detail you want************"<<endl;
    	   find_Birds(B1, B2);
    	   cout<<endl;
           goto ContinueProgram;
           break;
    case 4:
    	   cout<<"*************Here is Animal detail you want************"<<endl;
    	   find_Animals(A1, A2);
    	   cout<<endl;
           goto ContinueProgram;
           break;
    case 5:
        	cout<<"  The Discount on Birds is:     15%."<<endl;
        	cout<<"  The Discount on Animals is:   20%. "<<endl;
        	cout<<"_________________________________________"<<endl;
           goto ContinueProgram;
            break;
    case 6:
    	   if(checkEntity=="Customer" || checkEntity=="customer"){
    	   	cout<<"As a you are Customer, you can buy Pets. "<<endl;
		   }
		   else if(checkEntity=="Visitor" || checkEntity=="visitor"){
		   	cout<<"You are Visitor. You cannot buy Pets. Create an Account First! "<<endl;
		   	CreateAccount account;
		   	account.Accounts();
		   }
		   else{
		   	cout<<"You are Nor Customer nor a visitor. "<<endl;
		   }
    	   cout<<"If you want to buy both Birds & Animals then "<<endl;
		   cout<<"              Your Bank Balance should be greater than 500000"<<endl;
		   cout<<"              And Bank branch should be HBL, Meezan, Allied or BOP"<<endl;
		   cout<<"              Otherwise you can only buy birds. "<<endl;
			cout<<endl;
			
			cout<<"Enter you Balance: ";
			cin>>balance;
			cout<<"Enter Bank Name ( HBL - Meezan - Allied - BOFP ):  ";
			cin>>bank_name;
				if(balance>500000 && (bank_name=="HBL" || bank_name=="Meezan" || bank_name=="Allied" || bank_name=="BOFP"
				|| bank_name=="hbl" || bank_name=="meezan" || bank_name=="allied" || bank_name=="bofp"))
				{
				cout<<"You can buy both Birds and Animals"<<endl;
				cout<<"You want to buy Birds or Animals.  Yes/NO: ";
				 cin>>saying;
				 if(saying=="yes" || saying=="Yes"){
				 	cout<<"What do you want to buy __  Bird or Animal:  ";
				 	string set_name;
				 	cin>>set_name;
				 	if(set_name=="Birds" || set_name=="birds" || set_name=="Bird" || set_name=="bird"){
				 		 buy_bird(B1, B2);
					 }
					 else if(set_name=="Animals" || set_name=="animals" || set_name=="Animal" || set_name=="animal"){
					 	buy_animal(A1, A2);
					 }
			 		 else{
					 	cout<<"Enter relevant answer. "<<endl;
					 }
			}
		}
		
        	else{
				cout<<"You only can buy birds. "<<endl;
				cout<<"You want to buy Birds. ";
				 cin>>saying;
				 if(saying=="yes" || saying=="Yes"){
				 	buy_bird(B1, B2);
				 }
				 else{
				 	cout<<"Thanks for replying....."<<endl;
				 }
			}
		    cout<<endl;
           goto ContinueProgram;
    	  break;
    case 7: 
           if(true){
           	addBirds(B1, B2);
           }
           else{
           	 cout<<"Only admin cann add new Birds. "<<endl;
		   }
           goto ContinueProgram;
           break;
    case 8: 
           if(true){
           	addAnimals(A1, A2);
           }
           else{
           	 cout<<"Only admin cann add new Animals. "<<endl;
		   }
           goto ContinueProgram;
           break;
    case 9:
          detail.check();
          goto ContinueProgram;
		   break;
    case 10:
		  	Now.Contact();
		  	goto ContinueProgram;
		  	break;
	case 0:
            end.Website();
    	  	exit(0);
    	  	break;
    default: 
    	    cout<<"Invalid entry. "<<endl;
    	    cout<<endl;
            goto ContinueProgram;
            break;
}
      goto start;
	  return 0;
}


 
 
            
            
            
            
//            Start Working on this program from 15 April 2025          










//      the hard days of second semester and programming till 2 am to make a perfect project and inshalllah i will get high grade and 
//make promise to myself not to copy from AI but use when about to die
//
