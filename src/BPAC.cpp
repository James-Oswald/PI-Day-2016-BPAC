/*
This is a 2020 Github reupload, reworked some of the libraries 
Original 2016 header is as follows:

James Oswald
Pi Day Progect 2016
BPAC : Basic Pi Applications Console

In order to run this program you need Microsoft Visual C++ the lvp folder
in: "C:\Program Files (x86)\Microsoft Visual Studio\VC98\Include"
Please Include it there if you have not included it already or else this
program will not work.

Works Cited:
Joke credits to: http://mytowntutors.com/2014/03/pi-day-jokes-101-pi-day-jokes-for-math-teachers/
Pi Origins credit to: http://www.exploratorium.edu/pi/history_of_pi/
*/

//--------------------------------------------------------------------------------------
//inclusion section

#include<iostream.h>
#include<lvp/lvpString.h>
#include<lvp/random.h>
using namespace std;

//--------------------------------------------------------------------------------------

void Start()
{
	cout<<"                           "<<endl;
	cout<<"  ____  _____        _____ "<<endl;
	cout<<" |  _ \\|  __ \\ /\\   / ____|"<<endl;
	cout<<" | |_) | |__) /  \\ | |     "<<endl;
	cout<<" |  _ <|  ___/ /\\ \\| |     "<<endl;
	cout<<" | |_) | |  / ____ \\ |____ "<<endl;
	cout<<" |____/|_| /_/    \\_\\_____|"<<endl;
	cout<<"                           "<<endl;
	cout<<" Basic Pi Aplications Console"<<endl;
	cout<<"     Made By James Oswald    "<<endl;
	cout<<" Coppyright Oswald PiDay Inc "<<endl;
	cout<<" Leap Into Pi Day! 3/14/2016 "<<endl<<endl;
}

//--------------------------------------------------------------------------------------

void BeginOutput(String cmd) //Multipurpose Output Function
{
	if (cmd != "Start Up Login")
	{
		cout<<"Ending: Main Console"<<endl;
	}
	cout<<"------------------------------------------------------------------------------"<<endl;
	cout<<"Now Running: "<<cmd<<endl<<endl;
}

//--------------------------------------------------------------------------------------

void EndOutput(String cmd) //Multipurpose Output Function
{
	cout<<endl<<endl<<"Ending: "<<cmd<<endl;
	cout<<"------------------------------------------------------------------------------"<<endl;
	cout<<"Now Running: Main Console"<<endl;
}

//--------------------------------------------------------------------------------------

//objectives:
//"check" checks to see if the enterd username is valid
//"new" creates a new user, if the slot is occupied asks if it should rewrite it
//"bypassNew" rewrites a user

int UserPassDB(String obj, int obj2, String user, String pass) //Interactive System Library
{
	static String users [5] = {"","","","",""}; //user library
	static String passwords [5] ={"","","","",""}; //password library
	int rv; //return value
	if (obj == "check") //check
	{
		if (obj2 == 0) //check for vaild username
		{
			int c; //looping variable
			c = 0;
			do
			{
				if (users [c] == user)
				{
					rv = 1;
				}
				c++;
			}
			while (c <= 4);
		}
		else if (obj2 == 1) //checks for a valid password
		{
			int ul; //user location
			int c;  //looping variable
			int pl; //password location
			c = 0;
			do
			{
				if (users [c] == user)
				{
					 ul = c;              //gets location of username
				}
				c++;
			}
			while (c <= 4);
			c = 0;
			do
			{
				if (passwords [c] == pass)
				{
					 pl = c;			//gets location of password
				}
				c++;
			}
			while (c <= 4);
			if (ul == pl)					
			{
				rv = 1;
			}
		}
	}
	else if (obj == "new")  // creates new users
	{
		obj2--;
		if (users [obj2] == "")
		{
			users [obj2] = user;
			passwords [obj2] = pass;
			rv = 1;
		}
		else
		{
			rv = 0;
		}
	}
	else if (obj == "bypassNew")
	{
		obj2--;
		users [obj2] = user;
		passwords [obj2] = pass;
		rv = 0;
	}
	else
	{
		cout<<"Unexpected error"<<endl<<endl; //this shouldn't be possible to hit
	}
	return rv;
}

//--------------------------------------------------------------------------------------

String Login() //Auto-Executing System Command
{
	int c; // looping variable
	String un; //username string
	String pass; //password string
	c = 1;
	cout<<"Please Login, if you do not have an account use the \"Guest\"(capital G) account"<<endl;
	cout<<"or create a new one once logged onto Guest"<<endl<<endl;
	do
	{
		cout<<"Username: ";
		cin>>un;
		if (un == "Admin")
		{
			c = 0;
		}
		else if (un == "Guest")
		{
			c = 0;
		}
		else if (UserPassDB("check", 0, un, "null") == 1)
		{
			cout<<endl;
			cout<<"Password: ";
			cin>>pass;
			if(UserPassDB("check", 1, un, pass) == 1)
			{
				c = 0;
			}
			else
			{
				cout<<endl<<endl;
				cout<<"Incorect Password for the selected user account";
			}
		}
		else
		{
			cout<<endl;
			cout<<"Invalid Username! Please use the \"Guest\" accout"<<endl<<endl;
		}
	}
	while (c == 1);
	return un;
}
//--------------------------------------------------------------------------------------

int levelGet(String user) //System Function
{
	int lvl; //permission level variable
	if (user == "Admin")
	{
		lvl = 2;

	}
	else if (user == "Guest")
	{
		lvl = 0;
;
	}
	else
	{
		lvl = 1;
	}
	return lvl;
}

//--------------------------------------------------------------------------------------

String commandGet(String user, int lvlD) //System Input Function
{
	String lvl; //level prompted to user
	String cmd; //command entered by user
	if (lvlD == 2)
	{
		lvl = "Administrator";
		user = "James";
	}
	else if (lvlD == 0)
	{
		lvl = "Guest";
		user = "GuestUser";
	}
	else
	{
		lvl = "User";
	}
	cout<<endl;
	cout<<lvl<<":"<<user<<"> ";
	cin>>cmd;
	cout<<endl;
	return cmd;
}

//---------------------------------------------------------------------------------------

void NewUser() //System Command
{
	int loc; //location within the user array
	int valid; //slot taken or untaken 1 = taken, 0 = untaken
	int l;  //upper looping variable
	String un;
	String pass;
	l = 1;
	do
	{
		cout<<"What user location would you like (spots 1-5)"<<endl;
		cin>>loc;
		if ((loc <= 0)||(loc >= 6))
		{
			cout<<"Invalid User Location, you may only use (1-5)"<<endl;
		}
		else
		{
			l = 0;
		}
	}
	while (l == 1);
	cout<<"What would you like your 1 word name to be?"<<endl;
	cin>>un;
	cout<<"What would you like your 1 word password to be?"<<endl;
	cin>>pass;
	valid = UserPassDB("new", loc, un, pass);
	if (valid == 1)
	{
		cout<<endl<<"New user created!"<<endl;
	}
	else if (valid == 0) // if the user slot in the array of users is taken
	{
		int c; //lower looping variable
		c = 1;
		do
		{
			String yn; //user response
			cout<<endl<<endl;
			cout<<"That username spot is already taken!\nwould you like to go ahead and rewrite it?(yes or no responce)"<<endl;
			cin>>yn;
			if ((yn == "Yes")||(yn == "yes"))
			{
				UserPassDB("bypassNew", loc, un, pass);
				cout<<endl<<"New user created!"<<endl;
				c = 0;
			}
			else if ((yn == "No")||(yn == "no"))
			{
				cout<<endl<<"Will not create new user."<<endl;
				c = 0;
			}
			else  //invalid response handler
			{
				cout<<endl<<"yes or no responces only please."<<endl<<endl;
			}
		}
		while (c == 1);
	}
	else
	{
		cout<<"unexpectd error!!"<<endl;   //this should never happen
	}
}

//#######################################################################################
//Past This line is the User & Admin command handler area
//#######################################################################################

//Objectives:
//"list" List Commands in Library
//"check" = Check if command is valid

int SystemLibrary(String obj, String cmd) //Command Library
{
	const String SystemCommands [10] = {"Exit", "Reboot", "Logout", "NewUser", "List", "exit", "reboot", "logout", "newuser", "list"};
	const String SystemCommandDescriptions [5] = {"Exits the program, Deletes custom users.", "Reboots the program, Dosent delete custom users", "Logs out the curently loged in user.", "Creates a new custom user", "Lists all commands and their descriptions."};
	int rv; //return value
	if (obj == "check")
	{
		int c; //looping variable
		c = 0;
		do
		{
			if (SystemCommands [c] == cmd)
			{
				rv = 1;
			}
			c++;
		}
		while (c <= 9);
	}
	else if (obj == "list")  //return value uneeded
	{
		cout<<"(System level commands)"<<"\t:\t"<<"(Description)"<<endl;
		int c; //looping variable
		c = 0;
		do
		{
			cout<<SystemCommands [c]<<"\t\t\t:\t"<<SystemCommandDescriptions[c]<<endl;
			c++;
		}
		while (c <= 4);
	}
	else
	{
		cout<<"unexpectd error!!"<<endl;   //this should never happen
	}
	return rv;
}

//#######################################################################################

int UserLibrary(String obj, String cmd) //Command Library
{
	const String UserCommands [10] = {"Circumference", "Area", "Pi", "Joke", "Origin", "circumference", "area", "pi", "joke", "origin"};
	const String UserCommandDescriptions [5] = {"Finds the circumference of a circle.", "Finds the Area of a circle.", "Aproximates pi 1000 places", "Tells a pi joke.", "Tells about why pi was called pi."};
	int rv; //return value
	if (obj == "check")
	{
		int c; //looping variable
		c = 0;
		do
		{
			if (UserCommands [c] == cmd)
			{
				rv = 1;
			}
			c++;
		}
		while (c <= 9);
	}
	else if (obj == "list")  //return value uneeded  
	{
		cout<<"(User level commands)"<<"\t:\t"<<"(Description)"<<endl;
		int c; //looping variable
		c = 0;
		do
		{
			if (c == 0)
			{
				cout<<UserCommands [c]<<"\t\t:\t"<<UserCommandDescriptions [c]<<endl;
			}
			else
			{
				cout<<UserCommands [c]<<"\t\t\t:\t"<<UserCommandDescriptions [c]<<endl;
			}
			c++;
		}
		while (c <= 4);
	}
	else
	{
		cout<<"Unexpectd Error!!"<<endl;   //this should never happen
	}
	return rv;
}

//#######################################################################################
/*
The Admin Commands are made as tests
and Have no relation to pi whatsoever
*/

int AdminLibrary(String obj, String cmd) //Command Library
{
	const String AdminCommands [4] = {"Ping","Ayyy","ping","ayyy"};
	const String AdminCommandDescriptions [2] = {"Pong", "Lmao"};
	int rv; //return value
	if (obj == "check")
	{
		int c; //looping variable
		c = 0;
		do
		{
			if (AdminCommands [c] == cmd)
			{
				rv = 1;
			}
			c++;
		}
		while (c <= 3);
	}
	else if (obj == "list")  //return value uneeded
	{
		cout<<"(Admin level commands)"<<"\t:\t"<<"(Description)"<<endl;
		int c; //looping variable
		c = 0;
		do
		{
			cout<<AdminCommands [c]<<"\t\t\t:\t"<<AdminCommandDescriptions [c]<<endl;
			c++;
		}
		while (c <= 1);
	}
	else
	{
		cout<<"Unexpectd Error!!"<<endl;   //this should never happen
	}
	return rv;
}

//#######################################################################################

int Avalible(String cmd, int lvl) //Command Handler Function
{
	int ava; //availability variable and return value
	if (lvl == 0)
	{
		if (SystemLibrary("check", cmd) == 1)
		{
			ava = 1;
		}
		else
		{
			ava = 0;
		}
	}
	else if (lvl == 1)
	{
		if ((SystemLibrary("check", cmd) == 1) || (UserLibrary("check", cmd) == 1))
		{
			ava = 1;
		}
		else
		{
			ava = 0;
		}
	}
	else if (lvl == 2)
	{
		if ((SystemLibrary("check", cmd) == 1) || (UserLibrary("check", cmd) == 1) || (AdminLibrary("check", cmd) == 1))
		{
			ava = 1;
		}
		else
		{
			ava = 0;
		}
	}
	else
	{
		cout<<"Unexpected Error"; //this should never happen
	}
	return ava;
}

//#######################################################################################

int dcTypeYesNoHandler(String statement, int c) //Internal User Command Function
{
	int d;
	d = 1;
	do
	{
		String yn; //yes or no response
		cout<<statement<<"(yes or no)"<<endl;
		cin>>yn;
		if ((yn == "Yes")||(yn == "yes"))
		{
			d = 0;
		}
		else if ((yn == "No")||(yn == "no"))
		{
			c = 0;
			d = 0;
		}
		else  //invalid response handler
		{
				cout<<endl<<"yes or no responses only please."<<endl<<endl;
		}
	}
	while (d == 1);	
	return c;
}



//***************************************************************************************
//This is the User and Admin command execution section.
//***************************************************************************************

void Circumference() //User Command Function
{
	const double PI = 3.141592; //pi constant
	int radius; //radius variable
	int c;  //Greater looping variable
	c = 1;
	cout<<"This function takes a radius and retuns the circumference"<<endl;
	cout<<"of the circle with the given radius."<<endl<<endl;
	do 
	{
		cout<<"Enter the radius"<<endl<<endl;
		cout<<"Radius: ";
		cin>>radius;
		cout<<endl<<"The circumference of a circle for the given radius is:"<<endl<<endl;
		cout<<"Circumference: "<<(PI * (radius * 2))<<endl<<endl;
		c = dcTypeYesNoHandler("Would you like to preform another circumference calculation?",c);
	}
	while (c == 1);
}

//***************************************************************************************

void Area() //User Command Function
{	
	const double PI = 3.141592; //pi constant
	int radius; //radius variable
	int c;  //Greater looping variable
	cout<<"This function takes a radius and retuns the Area"<<endl;
	cout<<"of the circle with the given radius."<<endl<<endl;
	c = 1;
	do 
	{
		cout<<"Enter the radius"<<endl<<endl;
		cout<<"Radius: ";
		cin>>radius;
		cout<<endl<<"The Area of a circle for the given radius is:"<<endl<<endl;
		cout<<"Area: "<<(PI * (radius ^ 2))<<endl<<endl;
		c = dcTypeYesNoHandler("Would you like to preform another area calculation?", c);
	}
	while (c == 1);
}


//***************************************************************************************

void Pi() //User Command Function
{
	cout<<"This function returns pi to the 1000th digit"<<endl<<endl;
	cout<<"3.14159265358979323846264338327950288419716939937510"<<endl;
	cout<<"  58209749445923078164062862089986280348253421170679"<<endl;
	cout<<"  82148086513282306647093844609550582231725359408128"<<endl;
	cout<<"  48111745028410270193852110555964462294895493038196"<<endl;
	cout<<"  44288109756659334461284756482337867831652712019091"<<endl;
	cout<<"  45648566923460348610454326648213393607260249141273"<<endl;
	cout<<"  72458700660631558817488152092096282925409171536436"<<endl;
	cout<<"  78925903600113305305488204665213841469519415116094"<<endl;
	cout<<"  33057270365759591953092186117381932611793105118548"<<endl;
	cout<<"  07446237996274956735188575272489122793818301194912"<<endl;
	cout<<"  98336733624406566430860213949463952247371907021798"<<endl;
	cout<<"  60943702770539217176293176752384674818467669405132"<<endl;
	cout<<"  00056812714526356082778577134275778960917363717872"<<endl;
	cout<<"  14684409012249534301465495853710507922796892589235"<<endl;
	cout<<"  42019956112129021960864034418159813629774771309960"<<endl;
	cout<<"  51870721134999999837297804995105973173281609631859"<<endl;
	cout<<"  50244594553469083026425223082533446850352619311881"<<endl;
	cout<<"  71010003137838752886587533208381420617177669147303"<<endl;
	cout<<"  59825349042875546873115956286388235378759375195778"<<endl;
	cout<<"  18577805321712268066130019278766111959092164201989"<<endl;
}

//***************************************************************************************

void Joke() //User Command Function
{
	int c; //greater looping variable
	int jokenum; //joke number variable
	randomize();
	c = 1;
	do
	{
		jokenum = random(10);
		if (jokenum == 0)
		{
			cout<<endl<<"What do you get when you cut a jack o\'lantern by its \ndiameter? Pumpkin Pi!"<<endl;
		}
		else if (jokenum == 1)
		{
			cout<<endl<<"What do you get when you take green cheese and divide its \ncircumference by its diameter? Moon Pi."<<endl;
		}
		else if (jokenum == 2)
		{
			cout<<endl<<"What do you get when you take the sun and divide its \ncircumference by its diameter? Pi in the sky."<<endl;
		}
		else if (jokenum == 3)
		{
			cout<<endl<<"Mathematician: \"Pi r squared\" Baker: \"No! Pies are \nround, cakes are square!\""<<endl;
		}
		else if (jokenum == 4)
		{
			cout<<endl<<"What do we get when we take the object and order the rim \nby the diameter? Pi in the sky by and by."<<endl;
		}
		else if (jokenum == 5)
		{
			cout<<endl<<"In Alaska, where it gets very cold, pi is only 3.00. As you know, \neverything shrinks in the cold. They call it Eskimo pi."<<endl;
		}
		else if (jokenum == 6)
		{
			cout<<endl<<"What do you get if you divide the circumference of a bowl of \nice cream by its diameter? Pi a\'la mode."<<endl;
		}
		else if (jokenum == 7)
		{
			cout<<endl<<"3.14% of Sailors are PI rates!"<<endl;
		}
		else if (jokenum == 8)
		{
			cout<<endl<<"A mathematician, a physicist, and an engineer are all given identical rubber"<<endl;
			cout<<"balls and told to find the volume. They are given anything theywant to measure"<<endl;
			cout<<"it, and have all the time they need. The mathematician pulls out a measuring"<<endl;
			cout<<"tape and records the circumference. He then divides by two times pi to get"<<endl;
			cout<<"the radius, cubes that, multiplies by pi again, and then multiplies by"<<endl;
			cout<<"four-thirds and thereby calculates the volume.The physicist gets a bucket"<<endl;
			cout<<"of water, places 1.00000 gallons of water in the bucket, drops in the ball,"<<endl;
			cout<<"and measures the displacement to six significant figures. And the engineer? He"<<endl;
			cout<<"writes down the serial number of the ball, and looks it up."<<endl;
		}
		else if (jokenum == 9)
		{
			cout<<endl<<"The roundest knight at King Arthur�s was Sir Cumference He ate too much Pi!"<<endl;
		}
		else
		{
			cout<<"Unexpected Error"; //this should never happen
		}
		cout<<endl;
		c = dcTypeYesNoHandler("Would you like to hear another joke?", c);
	}
	while (c == 1);
}

//***************************************************************************************

void Origin() //User Command Function
{
	cout<<"The ancient Babylonians calculated the area of a circle by taking 3"<<endl;
	cout<<"times the square of its radius, which gave a value of pi = 3. One"<<endl;
	cout<<"Babylonian tablet (ca. 1900-1680 BC) indicates a value of 3.125 for"<<endl;
	cout<<"pi, which is a closer approximation."<<endl<<endl;
	cout<<"The Rhind Papyrus (ca.1650 BC) gives us insight into the mathematics"<<endl;
	cout<<"of ancient Egypt. The Egyptians calculated the area of a circle by a"<<endl;
	cout<<"formula that gave the approximate value of 3.1605 for pi."<<endl<<endl;
	cout<<"The first calculation of pi was done by Archimedes of Syracuse"<<endl;
	cout<<"(287-212 BC), one of the greatest mathematicians of the ancient world."<<endl;
	cout<<"Archimedes approximated the area of a circle by using the"<<endl;
	cout<<"Pythagorean Theorem to find the areas of two regular polygons:"<<endl;
	cout<<"the polygon inscribed within the circle and the polygon within which"<<endl;
	cout<<"the circle was circumscribed. Since the actual area of the circle lies"<<endl;
	cout<<"between the areas of the inscribed and circumscribed polygons, the areas"<<endl;
	cout<<"of the polygons gave upper and lower bounds for the area of the circle."<<endl;
	cout<<"Archimedes knew that he had not found the value of pi but only an"<<endl;
	cout<<"approximation within those limits. In this way, Archimedes showed that"<<endl;
	cout<<"pi is between 3 1/7 and 3 10/71."<<endl<<endl;
	cout<<"A similar approach was used by Zu Chongzhi (429-501), a brilliant"<<endl;
	cout<<"Chinese mathematician and astronomer. Zu Chongzhi would not have been"<<endl;
	cout<<"familiar with Archimedes� method but because his book has been lost,"<<endl;
	cout<<"little is known of his work. He calculated the value of the ratio of the"<<endl;
	cout<<"circumference of a circle to its diameter to be 355/113. To compute this"<<endl;
	cout<<"accuracy for pi, he must have started with an inscribed regular 24,576-gon"<<endl;
	cout<<"and performed lengthy calculations involving hundreds of square roots"<<endl;
	cout<<"carried out to 9 decimal places."<<endl<<endl;
	cout<<"Mathematicians began using the Greek letter p in the 1700s. Introduced by"<<endl;
	cout<<"William Jones in 1706, use of the symbol was popularized by Leonhard Euler,"<<endl;
	cout<<"who adopted it in 1737."<<endl<<endl;
	cout<<"An Eighteenth century French mathematician named Georges Buffon devised a"<<endl;
	cout<<"way to calculate pi based on probability."<<endl;
}

//***************************************************************************************

void Ping() //Admin Command Function
{
	cout<<"Pong"<<endl;
}

//***************************************************************************************

void Ayyy() //Admin Command Function
{
	cout<<"Lmao"<<endl;
}

//***************************************************************************************
//This is the End of User and Admin command execution section.
//***************************************************************************************

void ExecuteCommand(String cmd) //Command Executer
{
	if ((cmd == "Circumference")||(cmd == "Circumference"))
	{
		Circumference();
	}
	else if ((cmd == "Area")||(cmd == "area"))
	{
		Area();
	}
	else if ((cmd == "Pi")||(cmd == "pi"))
	{
		Pi();
	}
	else if ((cmd == "Joke")||(cmd == "joke"))
	{
		Joke();
	}
	else if ((cmd == "Origin")||(cmd == "origin"))
	{
		Origin();
	}
	else if ((cmd == "Ping")||(cmd == "ping"))  //Admin Test Function No Purpose or relation to pi
	{
		Ping();
	}
	else if ((cmd == "Ayyy")||(cmd == "ayyy"))  //Admin Test Function No Purpose or relation to pi
	{
		Ayyy();
	}
	else
	{
		cout<<"Unexpected Error"; //this should never happen
	}
}

//#######################################################################################

void cmdHandler(String cmd, int lvl) //Command Handler
{
	if (Avalible(cmd, lvl) == 1) //checks if command exists for given permission level
	{
		BeginOutput(cmd);
		ExecuteCommand(cmd);
		EndOutput(cmd);
	}
	else
	{
		BeginOutput("Invalid Command");
		cout<<endl<<"The Command you have enterd is illegal!"<<endl;
		cout<<"Please note that C++ is case sensitive and this program"<<endl;
		cout<<"only accepts commands in propercase and lowercase!"<<endl;
		cout<<"If your having trouble discovering commands please run"<<endl;
		cout<<"The \"List\" command for a list of vailid BPAC commands"<<endl;
		cout<<"for your user level"<<endl;
		EndOutput("Invalid Command");
	}	
}



//#######################################################################################
//End of command handeler area
//#######################################################################################

void List(int lvl) //System Command
{
	if (lvl == 0)
	{
		cout<<endl;
		SystemLibrary("list", "null");
		cout<<endl;
	}
	else if (lvl == 1)
	{
		cout<<endl;
		SystemLibrary("list", "null");
		cout<<endl;
		UserLibrary("list", "null");
		cout<<endl;
	}
	else if (lvl == 2)
	{
		cout<<endl;
		SystemLibrary("list", "null");
		cout<<endl;
		UserLibrary("list", "null");
		cout<<endl;
		AdminLibrary("list", "null");
		cout<<endl;
	}

}

//---------------------------------------------------------------------------------------

int main() //Main Function
{
	int c; //exit looping variable
	int r; //reboot looping variable
	int l; //logout looping variable
	int lvl; //user permission level
	int fl; //first login 
	String un; //username string
	String cmd; //command string
	fl = 1;
	c = 1;
	do
	{
		r = 1;
		Start();
		do
		{
			r = 1;
			l = 1;
			if (fl == 1)
			{
				BeginOutput("Start Up Login");
				un = Login();
				EndOutput("Start Up Login");
				fl = 0;
			}
			else
			{
				BeginOutput("Login");
				un = Login();
				EndOutput("Login");
			}
			do
			{
				lvl = levelGet(un);
				cmd = commandGet(un, lvl);
				if ((cmd == "exit")||(cmd == "Exit")) //Exit Executed
				{
					BeginOutput(cmd);
					c = 0;
				}
				else if ((cmd == "reboot")||(cmd == "Reboot")) //Reboot Executed
				{
					r = 0;
				}
				else if ((cmd == "logout")||(cmd == "Logout")) //Logout Executed
				{
					l = 0; 
				}
				else if ((cmd == "newuser")||(cmd == "NewUser")) //New User Executed
				{
					BeginOutput(cmd);
					NewUser();
					EndOutput(cmd);
				}
				else if ((cmd == "list")||(cmd == "List")) //List Executed
				{
					BeginOutput(cmd);
					List(lvl);
					EndOutput(cmd);
				}
				else 
				{
					cmdHandler(cmd, lvl);
				}
			}
			while ((l == 1) && (r == 1) && (c == 1));
		}
		while ((r == 1) && (c == 1));
	}
	while (c == 1);
}