# include <iostream>
# include <vector>
# include <ctime>
# include <iomanip>
# include <string>

using namespace std;

//struct variable contains movie information
struct movie {
    string name;
    string time1,time2,time3;
    float normal1,normal2,normal3,couple1,couple2,couple3,vip1,vip2,vip3;
    int place1,place2,place3;
};


//struct variable to store the variable of booked movie
struct ticket{
	string name;
	string time;
	float price;
	int hall;
	string seat;
};


//struct variable to store the seat number and type chosen by the user
struct seat{
	string seatNum;
	int type;
};
//to record the seat chosen by the user
vector<seat> S;
vector<seat>::iterator ss;


//function to print out the current time
void current_time()
{
	time_t t;
	t=time(0);
	tm* mt;
	mt=localtime(&t);
	cout<<"\t\t\tThe current time is ";
	cout<<mt->tm_year+1900<<"-"<<mt->tm_mon+1<<"-"<<mt->tm_mday<<" ";
	cout<<mt->tm_hour<<":"<<setfill('0')<<setw(2)<<mt->tm_min;
}


//store User Information
class Data
{
    public:
        string phone;
        string userName;
        void get_phone()
		{
            cout<<"\n\t\t\t\tEnter Your Phone number: 60-";
            cin>>phone;
			if(AllareNum(phone)==0){
				cout<<"\n\t\t\t\tPlease check your input, they should be all digits ;)"<<endl;
				get_phone();
			}
        }
        void get_userName()
        {
            cout<<"\t\t\t\tWhat is your name: ";
            getline(cin, userName);
        }
        string returnPhone (void)
        {  return phone;  }
        string returnUserName ()
        {  return userName;  }
		bool AllareNum(string str)  
		{  
		    for (int i = 0; i < str.size(); i++)
		    {
		        int tmp = (int)str[i];
		        if (tmp >= 48 && tmp <= 57)  //range of numebr in ASCII
		        {
		            continue;
		        }
		        else
		        {
		            return false;
		        }
		    } 
		    return true;}
		};
//movie information
movie m1={"Doctor Strange In The Multiverse Of Madness","10:05-12:05","14:05-16:05","18:05-20:05",25,25,25,50,48,0,35,0,33,1,2,3};
movie m2={"Munafik 2","12:05-13:45","18:05-19:45","19:05-20:45",26,26,26,52,50,0,34,0,32,1,2,3};
movie m3={"Hantu Kak Limah","14:05-16:05","16:05-18:05","12:05-14:05",23,23,23,46,44,0,39,0,34,1,2,3};
movie m4={"Ejen Ali: The Movie","16:05-18:05","12:05-14:05","14:05-16:05",24,24,24,48,46,0,38,0,35,1,2,3};
movie m5={"The Lion King","18:05-19:45","12:05-13:45","20:05-21:45",22,22,22,44,42,0,37,0,36,1,2,3};
movie m6={"Frozen II","20:05-21:45","10:05-12:05","14:05-15:45" ,27,27,27,54,44,0,36,0,39,1,2,3};
//to record the movie chosen by the user
vector<movie> M;
vector<movie>::iterator it;


//User Information
//class Ticket for storing and printing movie ticketed information
class Ticket
{
	private:
		vector<ticket> booked;       //record the movie booked
		vector<ticket>::iterator tt; 
	
	public:
		//get the information of movie booked
		void getInfo(string n, string t, float p, int h, string s);
		//print out the Ticket
		void printInfo(Data x);
};

//to store the information needed to print the ticket
void Ticket::getInfo(string n, string t, float p, int h, string s)
{
	ticket t1;
	t1.name=n;
	t1.time=t;
	t1.price=p;
	t1.hall=h;
	t1.seat=s;
    booked.push_back(t1);
}

//print out the ticket
void Ticket::printInfo(Data x)
{
	int tol_price=0;
    string y;
    string c;
	y=x.returnUserName();
    c=x.returnPhone();

	cout<<"\n\n\n\n\t\t\t__________________________________________________________________________________\n";
    cout<<"\t\t\t|                                                                                 |\n";
    cout<<"\t\t\t|   Dear "<<left<<setfill(' ')<<setw(73)<<y<<"|\n";
    cout<<"\t\t\t|       You have bought your ticket successfully. This is your admission ticket.  |\n";

    cout<<"\t\t\t|                                                                                 |\n";
    cout<<"\t\t\t|   Booking time:                                                                 |\n";
    cout<<"\t\t\t|";

    current_time();
    cout<<"\t\t\t  |\n";
    cout<<"\t\t\t|                                                                                 |\n";


    cout<<"\t\t\t|                  THE DETAILS:                                                   |\n";

    for(tt=booked.begin();tt!=booked.end();++tt){
    	cout<<"\t\t\t|                       MOVIE HALL: "<<left<<setfill(' ')<<setw(46)<<tt->hall<<"|\n";
        cout<<"\t\t\t|                       MOVIE NAME: "<<left<<setfill(' ')<<setw(46)<<tt->name<<"|\n";
        cout<<"\t\t\t|                       MOVIE TIME: "<<left<<setfill(' ')<<setw(46)<<tt->time<<"|\n";
        cout<<"\t\t\t|                       MOVIE SEAT: "<<left<<setfill(' ')<<setw(46)<<tt->seat<<"|\n";
		cout<<"\t\t\t|                                                                                 |\n";
        tol_price+=tt->price;

	}
    cout<<"\t\t\t|                                                                                 |\n";
    cout<<"\t\t\t|                  The total price is "<<left<<setfill(' ')<<setw(44)<<tol_price<<"|\n";
    cout<<"\t\t\t|                  Your Phone No. 60-"<<left<<setfill(' ')<<setw(45)<<c<<"|\n";

    cout<<"\t\t\t|_________________________________________________________________________________|\n";

}



//Hall Information
//General hall function provided for following interitance
class General{
	friend class Hall1;
	friend class Hall2;
	friend class Hall3;
	private:
		char** arr;
	public:
	    //to get the seat number keyed in by the user
	    string getData(){
		    string p;
		    cout<<"\n\t\t\tEnter seat number or N to end: ";
		    cin>>p;
		    return p;
	    }

		//to get the seat information chosen by the user
		void getSeatInfo(string s, int n);

	    //update the seat status
	    void update(int row,int col){
	    	cout<<"\n\t\t\tWell done! Your seat is avaliable. System will reserve it for you.\n";
	        cout<<"\n\t\t\t........................Updating seat status......................\n";
	        arr[row][col]='X';
	    }
};

void General::getSeatInfo(string s, int n)
{
	seat s1;
	s1.seatNum=s;
	s1.type=n;
	S.push_back(s1);
}

//class for hall1 operation 
class Hall1:virtual public General{
	public:
	    void initialSeat1();
	    void display1();
	    void ticketing1(); // leading function
		int check(string s);
	    int allOccupied();
};
	
//initialize the seat
void Hall1::initialSeat1()
{
	arr=new char *[12];
	for(int i=0;i<12;i++){
		arr[i]=new char [10];
		for(int j=0;j<10;j++){
			arr[i][j]='A'+j; 
		}
	}
}

//to display the seats
void Hall1::display1(){ 
    cout<<"\n\t\t\t-----------------------------------SCREEN------------------------------------"<<endl;
    cout<<"  "<<endl;
	//vip and normal (previous 10 rows)
	for(int i=0;i<10;i++){ 
	    cout<<"\t\t\t";
		for(int j=0;j<10;j++){
			if(arr[i][j]=='X'){
				cout<<"["<<"X "<<"]"<<"    ";
			} 		
			else if(i>7){
				cout<<"["<< "V" << i-7 << arr[i][j] << "]" << "   ";
			}
			else {
				cout<< "[" << i+1 << arr[i][j] << "]" << "    ";
				} 		//i+1--actual row number
		}
		cout<<endl;
	}
	//couple (last two rows)
	for(int i=10;i<12;i++){
		int k=0;
		char temp='A';
		cout<<"\t\t\t";
		for(int j=0;j<5;j=j+1){
			if(arr[i][j]=='X'){
				cout<<"["<<"     X     "<<"]"<<"   ";
				k++;
			}
			else{
				temp='A'+k;
				cout<<"[    "<< " C"<<i-9<<temp <<"   ]" << "   ";
				k++;
			}
		}
		cout<<endl;
	}

	return;
}


//to check whether all sits are occupied or not
int Hall1::allOccupied(){ 
	int count=0;
	for(int i=0;i<12;i++){
		for(int j=1;j<10;j++)
		if(arr[i][j]=='X') //when enconter X (means this has been occupied)
			count++;
	}

	if(count==110) // the left 10 are not seats
		return 1;
	return 0;
}

//to check whether the seat chosen by the user can be processed or not
int Hall1::check(string s){
	
	int row=-1,col=-1;
	//for vip & couple
	if (s[0]=='V' || s[0]=='C')
	{
		if(s[1]>'2' || s[1]<'1' || s[2]>'J' || s[2]<'A'){
			cout<<"\n\t\t\tInvalid seat number : \n"; 
			return 0;
		}
		if(s[0]=='C'&& s[2]>'E'){
			cout<<"\n\t\t\tInvalid seat number : \n"; 
			return 0;
		}
		if(s[0]=='C'&& s[2]<'A'){
			cout<<"\n\t\t\tInvalid seat number : \n"; 
			return 0;
		}
		
		//for vip
		if(s[0]=='V'){ 
		    for(int i=8; i<10;i++){
			    char a;
			    a='1'+(i-8);     //traverse the seat position
			    if(a==s[1]){ 	//no need to compare with arr[i][0]
			        row=i;
			        break;
			    }
		    }
			for(int j=0;j<10;j++){
			if(arr[row][j]==s[2])
			    col=j;
		    }
		    if(col==-1){
		    	cout<<"\n\t\t\tSeat is already occupied.\n";
			    return 0;
		    }
		    else{
				getSeatInfo(s, 1);//collent the seat infomation and store it in the S vector
			    update(row,col);
		    } 
		}
		else{
			//for Couple
			for(int i=10; i<12; i++) {
			    char a;
			    a='1'+(i-10);    //traverse the seat position
			    if(a==s[1]){
			        row=i;
			        break;
				}
			}
			for(int j=0;j<10;j++){
			    if(arr[row][j]==s[2])
			        col=j;
		    }
		    if(col==-1){
		    	cout<<"\n\t\t\tSeat is already occupied.\n";
		    	return 0;
		    }
		    else{
				getSeatInfo(s, 2);
			    update(row,col);
	    	}
		}
		return 1;
	}
		//eliminate the error input
	else if(s[0]>'8' || s[0]<'1' || s[1]>'J' || s[1]<'A'){
		if(s[0]!='V' || s[0]!='C')
		cout<<"\n\t\t\tInvalid seat number : \n"<<endl; //invalid seat no. 
		return 0;
	}
	// this is for row1-row8
	else{ 
		//find the row no. of the user sit
		for(int i=0; i<8;i++){
			char a;
			a='1'+i; 
			if(a==s[0]){ 		//no need to compare with arr[i][0]
				row=i;		//assign the value
				break;
			}
		}
		for(int j=0;j<10;j++){  //array traverse from 0
		if(arr[row][j]==s[1])   
		col=j;
		}
		//check whether seat is already occupied or not.
		if(col==-1){
			cout<<"\n\t\t\tSeat is already occupied.\n";
			return 0;
		}
		else{
			//if it's a valid seat & not occupied, 
			//process the requested & update the sit as occupied 
			getSeatInfo(s, 3);
			update(row,col);   	//uptate the seat status
		}
		return 1;
	}
}


//Seat chosen process
void Hall1::ticketing1(){
	// user can stop process by pressing 'N'
	cout<<"\n\t\t\tEnter N if you are done!\n"; 
	string s;
	while(true){ 
		s=getData(); //get user input 
		if(s[0]=='N') 
			break;
		//process the request & check according to
		if(check(s)) //return 0/1
			display1();

		if(allOccupied()){ //if all seats are occupied
			cout<<"\n\t\t\tSorry, no more seats left!!!!";
			break; 
		}
	}
	cout<<"\n\t\t\tThanks for your purchasing!"<<endl; 
}





//class for Hall2 information
class Hall2:virtual public General{
	public:
	    void initialSeat2();
        void display2();
	    void ticketing2(); // leading function
	    int check(string s);
	    int allOccupied();
};

//initialoze the seat position
void Hall2::initialSeat2()
{
	arr=new char* [8];
	for (int i=0;i<8;i++){
		arr[i]=new char[10];
	    for(int j=0;j<10;j++){
	    	arr[i][j]='A'+j;
		}
	} 
}

//display the seat status
void Hall2::display2(){ 
    cout<<"\n\t\t\t-----------------------------------SCREEN------------------------------------"<<endl;
	// for normal (previous 6 rows)
	for(int i=0;i<6;i++){ 
	    cout<<"\t\t\t";
		for(int j=0;j<10;j++){
			if(arr[i][j]=='X'){
				cout<<"["<<"X "<<"]    ";
				} 		
			else {
				cout<< "[" << i+1 << arr[i][j] << "]" << "    ";
				} 		//i+1 accord with the actual #line
		}
		cout<<endl; // new row
	}

	//for couple (row7-row8)
	for(int i=6;i<8;i++){
		int k=0;
		char temp='A';
		cout<<"\t\t\t";
		for(int j=0;j<5;j=j+1){ //only display first 5 columns
			if(arr[i][j]=='X'){ //occupied
				cout<<"["<<"    X     "<<"]    ";
				k++;
			}
			else{
				temp='A'+k;
				cout<<"[   "<< " C"<<i-5<<temp <<"   ]" << "    ";
				k++;
			}
		}
		cout<<endl; //new row
	}

	return;
}


//seat chosen process
void Hall2::ticketing2(){
	// user can stop process by pressing 'N'
	cout<<"\n\t\t\tEnter N if you are done!\n"; 
	string s;
	while(true){ 
		s=getData(); //get user input 
		if(s[0]=='N') 
			break;
		//process the request & check according to
		if(check(s)) //return 0/1
			display2();

		if(allOccupied()){ //if all sits are occupied
			cout<<"\n\t\t\tSorry, no more seats left!!!!!"<<endl;
			break; 
		}
	}
	cout<<"\n\t\t\tThanks for your purchasing, see you around!"<<endl; //end of program
}

//checking whether the seat chosen by the user can be processed or not
int Hall2::check(string s){
	
	int row=-1,col=-1;
	//for COUPLE 7r~8r
	if (s[0]=='C')
	{	
		if(s[1]>'2' || s[1]<'1' || s[2]>'E' || s[2]<'A'){
		cout<<"\n\t\t\tInvalid seat number : \n"; 
		return 0;
		}
		for(int i=6; i<8; i++) {
			char a;
			a='1'+(i-6);
			if(a==s[1]){
				row=i;
				break;
			}
		}
		// start to check in columns
		for(int j=0;j<10;j++){
			if(arr[row][j]==s[2]){
				col=j;
				break;
			}
		}
		if(col==-1){
			cout<<"\n\t\t\tSeat is already occupied.\n";
			return 0;
		}
		else{
			getSeatInfo(s,2);
			update(row,col); //successfully choose the seat 
		}
		return 1;
}

	else if(s[0]>'6' || s[0]<'1' || s[1]>'J' || s[1]<'A'){ 
		if (s[0]!='C')
		cout<<"\n\t\t\tInvalid seat number : \n"; 
		return 0;
	}

	else{ //normal 1r~6r
	    //find the row no of the user sit
	    for(int i=0; i<6;i++){
	    	char a;
	    	a='1'+i; 
	    	if(a==s[0]){ 		//no need to compare with arr[i][0]
	    		row=i;		//assign the value
	    		break;
	    	}
	    }
	    for(int j=0;j<10;j++){  //array  start to traverse from the bottom
	    	if(arr[row][j]==s[1])  
	    	col=j;
        }
		if(col==-1){
			cout<<"\n\t\t\tSeat is already occupied\n";
			return 0;
		}
		else{
			getSeatInfo(s,3);
			update(row,col); 
		}
		return 1;
	}

}

//to check whether all sits are occupied or not
int Hall2::allOccupied(){ 
	int count=0;
	for(int i=0;i<8;i++){
		for(int j=1;j<10;j++)
		if(arr[i][j]=='X') //when enconter X (means this has been occupied)
			count++;
	}

	if(count==70) // the left 10 are not seats
		return 1;
	return 0;
}



//class operation for Hall3 operation
class Hall3:virtual public General{
	public:
		void initialSeat3();
		void display3();
	    void ticketing3(); // leading function
	    int check(string s);
	    int allOccupied();
};

//initialize the seat position
void Hall3::initialSeat3()
{
	arr=new char* [6];
	for (int i=0;i<6;i++){
		arr[i]=new char[10];
	    for(int j=0;j<10;j++){
	    	arr[i][j]='A'+j;
		}
	} 
	
}

//display the seat status
void Hall3::display3(){ 
    cout<<"\n\t\t\t-----------------------------------SCREEN------------------------------------"<<endl;
    cout<<"  "<<endl;
	//vip and normal
	for(int i=0;i<6;i++){ 
	    cout<<"\t\t\t";
		for(int j=0;j<10;j++){
			if(arr[i][j]=='X'){
				if(i>3)
					cout<<"["<<"X  "<<"]"<<"   ";
				else{
					cout<<"["<<"X  "<<"]"<<"   ";
				}
			} 		
			else if(i>3){
				cout<<"["<< "V" << i-3 << arr[i][j] << "]" << "   ";
			}
			else {
				cout<< "[" << i+1 << arr[i][j] << "]" << "    ";
				} 		//i+1 accord with the actual #line
		}
		cout<<endl;
	}

	return;
}

//Seat chosen process
void Hall3::ticketing3(){
	// user can stop process by pressing 'N'
	cout<<"\n\t\t\tEnter N if you are done!\n"; 
	string s;
	while(true){ 
		s=getData(); //get user input 
		if(s[0]=='N') 
			break;
		//process the request & check according to
		if(check(s)) //return 0/1
			display3();

		if(allOccupied()){ //if all sits are occupied
			cout<<"\n\t\t\tSorry, no more seats left!!!!!!"<<endl;
			break; //break
		}
	}
	cout<<"\n\t\t\tThanks for your purchasing, see you around ;)"<<endl; //end of program
}

//checking whether the seat chosen by the user request can be processed or not
int Hall3::check(string s){
	
	int row=-1,col=-1;
	//for vip 5r~6r
	if (s[0]=='V')
	{	
	for(int i=4; i<6; i++) {
		char a;
		a='1'+(i-4);
		if(a==s[1]){
			row=i;
			break;
		}
	}
	// start to check in columns
	for(int j=0;j<10;j++){
		if(arr[row][j]==s[2])
		col=j;
	}
	if(col==-1){
		cout<<"\n\t\t\tSeat is already occupied.\n";
		return 0;
	}
	else{
		getSeatInfo(s, 1);
		update(row,col); //successfully choose the seat 
	}
	
	return 1;
}

	else if(s[0]>'4' || s[0]<'1' || s[1]>'J' || s[1]<'A'){ 
		if (s[0]!='V')
		cout<<"\n\t\t\tInvalid seat number :( \n"; 
		return 0;
	}

	else{ //for normal 1r~4r
	//find the row no of the user sit

	for(int i=0; i<4;i++){
		char a;
		a='1'+i; 
		if(a==s[0]){    //no need to compare with arr[i][0]
			row=i;		//assign the value
			break;
		}
	}
	for(int j=0;j<10;j++){  //array  start to traverse from the bottom
		if(arr[row][j]==s[1])  
		col=j;
}
	if(col==-1){
		cout<<"\n\t\t\tSeat is already occupied\n";
		return 0;
	}
	else{
        getSeatInfo(s,3);
		update(row,col); 
	}
	return 1;
	}

}

//to check whether all sits are occupied or not
int Hall3::allOccupied(){ 
	int count=0;
	for(int i=0;i<6;i++){
		for(int j=1;j<10;j++)
		if(arr[i][j]=='X') //when enconter X (means this has been occupied)
			count++;
	}

	if(count==60) // the left 10 are not seats
		return 1;
	return 0;
}




//Movie Information
//class for movie information 
class Movie: virtual public Ticket, virtual public Hall1, virtual public Hall2, virtual public Hall3
{
    public:
        int c,n;   //c--session option    n--movie option
        void MovieList();
        void Session(movie m);
        void get_c();   //get the user selected option for session
        void get_n();   //get the user selected option for movie
};

//show the movie list
void Movie::MovieList()
{
	M.push_back(m1);
    M.push_back(m2);
    M.push_back(m3);
    M.push_back(m4);
    M.push_back(m5);
    M.push_back(m6);
	for(it=M.begin();it!=M.end();++it)
	{
		cout << "\n\n\t\t\t\t\t\tInformation of Movie: "<<it->name<<endl;
        cout << "\t\t\t=======================================================================================================";
        cout<<"\n\t\t\t"<<"\tMovie Time"<<"\t\t"<<"Hall"<<"\t"<<"Normal Price(RM)"<<"\t"<<"Couple Price(RM)"<<"\t"<<"VIP Price(RM)";
        cout << "\n\t\t\t "<<"1."<<"\t"<< it->time1 <<"\t\t  "<<it->place1<<"\t"<<it->normal1<<"\t\t\t"<<it->couple1<<"\t\t\t"<<it->vip1;
        cout << "\n\t\t\t "<<"2."<<"\t"<< it->time2 <<"\t\t  "<<it->place2<<"\t"<<it->normal2<<"\t\t\t"<<it->couple2<<"\t\t\t"<<it->vip2;
        cout << "\n\t\t\t "<<"3."<<"\t"<< it->time3 <<"\t\t  "<<it->place3<<"\t"<<it->normal3<<"\t\t\t"<<it->couple3<<"\t\t\t"<<it->vip3;
	}
	cout<<"\n\n";
}


void Movie::get_c()
{
    cin>>c;
}
void Movie::get_n()
{
    cin>>n;
}

//choose the session of movie
void Movie::Session(movie m)
{
	string Seat;
	int type;
	vector<seat>::iterator ss;
	cout << "\n\n\t\t\t\t\t\tInformation of Movie "<<m.name<<endl;
    cout << "\t\t\t======================================================================================================";
    cout<<"\n\t\t\t"<<"\tMovie Time"<<"\t\t"<<"Hall"<<"\t"<<"Normal Price(RM)"<<"\t"<<"Couple Price(RM)"<<"\t"<<"VIP Price(RM)";
    cout << "\n\t\t\t "<<"1."<<"\t"<< m.time1 <<"\t\t  "<<m.place1<<"\t"<<m.normal1<<"\t\t\t"<<m.couple1<<"\t\t\t"<<m.vip1;
    cout << "\n\t\t\t "<<"2."<<"\t"<< m.time2 <<"\t\t  "<<m.place2<<"\t"<<m.normal2<<"\t\t\t"<<m.couple2<<"\t\t\t"<<m.vip2;
    cout << "\n\t\t\t "<<"3."<<"\t"<< m.time3 <<"\t\t  "<<m.place3<<"\t"<<m.normal3<<"\t\t\t"<<m.couple3<<"\t\t\t"<<m.vip3;

	cout<<"\n\n\n\t\t\tPlease select the session you want:";
    get_c();
	cout<<"\n\t\t\tYou had selected movie "<<m.name<<" on ";
	switch(c)
	{
		case 1:
			cout<<m.time1<<" in hall "<<m.place1<<endl;
			initialSeat1();
			display1();
			ticketing1();
			if(!S.empty()){
				for(ss=S.begin();ss!=S.end();++ss){
                Seat=ss->seatNum;
				type=ss->type;
				if(type==1){
				getInfo(m.name, m.time1,m.vip1, m.place1,Seat);
			    }else if(type==2){
				getInfo(m.name, m.time1,m.couple1, m.place1,Seat);
			    }else{
				getInfo(m.name, m.time1,m.normal1, m.place1,Seat);
			    }
			}
			//Each time passing the seat information to the ticket using the getInfo function, clear the S.
			//this is to avoid duplicate output.
			S.clear();	
			}
			break;
		case 2:
			cout<<m.time2<<" in hall "<<m.place2<<endl;
			initialSeat2();
			display2();
			ticketing2();
			if(!S.empty()){
				for(ss=S.begin();ss!=S.end();++ss){
                Seat=ss->seatNum;
				type=ss->type;
				if(type==2){
				getInfo(m.name, m.time2,m.couple2, m.place2,Seat);
			    }else{
				getInfo(m.name, m.time2,m.normal2, m.place2,Seat);
			    }
			}
			S.clear();
			}
			break;
		case 3:
			cout<<m.time3<<" in hall "<<m.place3<<endl;
			initialSeat3();
			display3();
			ticketing3();
			if(!S.empty()){
				for(ss=S.begin();ss!=S.end();++ss){
                Seat=ss->seatNum;
				type=ss->type;
				if(type==1){
				getInfo(m.name, m.time3,m.vip3, m.place3,Seat);
		    	}else{
			    	getInfo(m.name, m.time3,m.normal3, m.place3,Seat);
		    	}
			}
			S.clear();
			}
			break;
		default:
            cout<<"\n\t\t\t\tInvalid Input. Please do it agian."<<endl;
            break;
	}
}




//Customer
//Customer operation process
class Customer:virtual public Movie
{
	public:
		Customer();
		void Introduction();
		void Interface();
		void book();
};

//constructor---automatically execute the following operation
Customer::Customer()
{
	cout<<"\n\t\t\t\t"<<"~~~ Welcome to HLY Cinema! ~~~"<<endl<<endl;
	cout<<"\t\t\t\tHLY Cinema provided 3 types of halls, which include IMAX hall(hall_1), Regular hall(hall_2) and Boutique MINI(hall_3).\n"<<endl;
	cout<<"\t\t\t\tVIP seat, couple seat, and normal seat are kindly offered.\n\n"<<endl;
	cout<<"\t\t\t\tOpen time: 10am - 10pm on everyday.\n"<<endl;
	cout<<"\t";
	current_time();
	cout<<"\n\n\t\t\t\tPress to continue operation..."<<endl;
	system("pause");
	system("cls");
	Interface();
}

//Interface 
void Customer::Interface()
{
	cout<<"\n\n";
	Data x;
	x.get_userName();
	x.get_phone();

    cout<<"\n\t\t\t\tInitializing the movie schedule on HLY....... "<<endl;
    MovieList(); 	//call the movie list directly
	
	int sta=0;
	int nc=5;
    char* cus = new char[nc];
	while(1)
    {
		cout<<"\n\n";
    	cout<<"\t\t\t\t\t\t  "<<"--------------MENU--------------"<<endl;
	    cout<<"\t\t\t\t\t\t  "<<"|        1.Start Booking       |"<<endl;
	    cout<<"\t\t\t\t\t\t  "<<"|        2.Print the Ticket    |"<<endl;
	    cout<<"\t\t\t\t\t\t  "<<"|        3.Exit                |"<<endl;
	    cout<<"\t\t\t\t\t\t  "<<"--------------------------------"<<endl;
	    cout<<"\t\t\t\t\t\t  "<<"Enter the choice: ";
        
		cin>>cus;

        switch(*cus)
        {
			case '1':
                book();
                break;
            case '2':
            	printInfo(x);
            case '3':
            	cout<<"\n\n\t\t\t\t\t\t   Hope to see you in HLY cinema next time!\n\n";
                exit(0);
            default:
                cout<<"\n\t\t\t\t\t\tInvalid Input. Please try agian."<<endl;
                break;
        }
        cout<<"\n\n";
    }
	delete []cus;

}

//foe movie booking
void Customer::book()
{
	cout<<"\n\n";
	cout<<"\t\t\t============================================================================\n"<<endl;
    cout<<"\t\t\t==============================Choose Movie==================================\n"<<endl;
    cout<<"\t\t\t============================================================================\n"<<endl;
    cout<<"\n\t\t\t\t\t Press 1 : \"Doctor Strange In The Multiverse Of Madness\"\n";
    cout<<"\n\t\t\t\t\t Press 2 : \"Munafik 2\"\n";
    cout<<"\n\t\t\t\t\t Press 3 : \"Hantu Kak Limah\"\n";
    cout<<"\n\t\t\t\t\t Press 4 : \"Ejen Ali: The Movie\"\n";
    cout<<"\n\t\t\t\t\t Press 5 : \"The Lion King\"\n";
    cout<<"\n\t\t\t\t\t Press 6 : \"Frozen II\"\n"<<endl;
    cout<<"\t\t\t============================================================================\n"<<endl;
    cout<<"\n\t\t\t";
    get_n();

    //choose the session
    switch(n)
    {
    	case 1:
		    cout<<"\n\t\t\tYou had selected movie "<<m1.name;
            Session(m1);
		    break;
		case 2:
		    cout<<"\n\t\t\tYou had selected movie "<<m2.name;
		    Session(m2);
		    break;
		case 3:
		    cout<<"\n\t\t\tYou had selected movie "<<m3.name;
		    Session(m3);
		    break;
		case 4:
		    cout<<"\n\t\t\tYou had selected movie "<<m4.name;
		    Session(m4);
		    break;
		case 5:
		    cout<<"\n\t\t\tYou had selected movie "<<m5.name;
		    Session(m5);
		    break;
		case 6:
		    cout<<"\n\t\t\t You had selected movie "<<m6.name;
		    Session(m6);
		    break;
		default:
		    cout<<"\n\t\t\tInvalid Input. Please try it agian."<<endl;
			break;
	}
}




int main()
{
	Customer cc;
    
    return 0;
}
