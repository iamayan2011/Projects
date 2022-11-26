#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

void mainMenu();
void mainMenu2();
void firstPage();
void displayMenu();
void foodOptions();

class Management
{
public:
    Management()
    {
        firstPage();
    }
};

void firstPage()
{
    cout << "\n___________________________________________________________________________________" << endl;
        cout << "____________________________WELCOME TO XYZ RAILWAYS______________________________" << endl
             << endl;
    cout << "\t\t|\t 1. Admin Mode    \t|" << endl;
    cout << "\t\t|\t 2. User Mode     \t|" << endl;
    cout << "\t\t|\t 3. Exit          \t|" << endl;
    int choice;
    string id = "admin";
    string password = "admin";
    string eid, pass;

    cout << "Select: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        cout << "____________________________________________________________" << endl;
        cout << endl
             << "Enter Admin Username: ";
        cin >> eid;
        if (id == eid)
        {
            cout << "\nEnter Admin Password: ";
            cin >> pass;
            if (pass == password)
            {
                mainMenu();
                firstPage();
            }

            else
            {
                cout << "Password is wrong, Please try again!" << endl;
                firstPage();
            }
        }

        else
        {
            cout << "Entered Admin ID is wrong, Please Try Again!" << endl;
            firstPage();
        }

        break;
    }

    case 2:
    {
        cout << "\n_______________________________________________________________________________" << endl;
        cout << "WELCOME TO USER MODE" << endl;
        cout << "\t1. Create New Account" << endl;
        cout << "\t2. Login using existing account" << endl;
        cout << "\n\tSelect: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string uid, upass;
            cout << "__________________________________________________________________________________" << endl;
            cout << "______________________________CREATING NEW ACCOUNT_________________________________" << endl;
            cout << "\nEnter the New ID: ";
            cin >> uid;
            cout << "\nEnter Password: ";
            cin >> upass;

            fstream f("user.txt", ios::app);
            f << uid << " " << upass << endl;
            f.close();
            cout << "New User ID created!";
            cout << "Your User ID is " << uid << " and password is " << upass << endl;
            cout << "Use this as Login Credentials!" << endl
                 << endl;
            firstPage();

            break;
        }

        case 2:
        {
            cout << "__________________________________________________________________________________" << endl;
            cout << "__________________________________LOGING IN_______________________________________" << endl;

            string uid, upass;
            string cuid, cupass;

            cout << "\nEnter ID: ";
            cin >> uid;

            cout << "\nEnter Password: ";
            cin >> upass;

            fstream f1("user.txt", ios::in);
            while (!f1.eof())
            {

                f1 >> cuid >> cupass;
                cout << endl;

                if (uid == cuid && upass == cupass)
                {
                    cout << "\nCredentials Matched!" << endl;
                    cout << "\n_____________________________________________________________________________________" << endl;
                    mainMenu2();
                    firstPage();
                    return;
                }
            }

            cout << "Please enter correct details" << endl;
            cout << "\n_____________________________________________________________________________________" << endl;
            firstPage();

            break;
        }

        default:
            break;
        }

        break;
    }

    case 3:
    {

        cout << "___________________Thanks for using XYZ Railways_____________________" << endl
             << endl;
        exit(0);
    }
    }
}

class Details
{
public:
    static string name[6], gender[6];
    int phoneNo;
    static int age[6];
    static string bp[6];
    static int cId[6];
    char arr[100];
    static int pnr;
    static int n;
    // pnr = 1000000000 + (rand() % 9000000000);

    void information()
    {
        srand(time(NULL));
        pnr = 1000000000 + (rand() % 9000000000);
        cout << "\nYour PNR number is: " << pnr << endl;
        cout << "\nEnter the number of passengers: ";
        cin >> n;
        if (n > 6)
        {
            cout << "You can book tickets for only 6 passengers in a ticket!" << endl
                 << endl;
            mainMenu();
        }
        for (int i = 0; i < n; i++)
        {

            cout << "\n Enter the customer ID :";
            cin >> cId[i];

            cout << "\n Enter the Name :";
            cin >> name[i];
            cout << "\n Enter the age :";
            cin >> age[i];
            cout << "\n Enter Birth Preference :";
            cin >> bp[i];
            cout << "\n Gender:";
            cin >> gender[i];
            // cout << "Yours details are saved with us.\n";
        }

        /* cout << "\n Enter the customer ID :";
         // cin >> cId;
         cout << "\n Enter the Name :";
         cin >> name;
         cout << "\n Enter the age :";
         cin >> age;
         cout << "\n Enter the address :";
         cin >> add;
         cout << "\n Gender:";
         cin >> gender;*/
        cout << "Yours details are saved with us.\n";

        cout << "Your PNR number is: " << pnr << endl;
        cout << "Please use this PNR number to book tickets!" << endl
             << endl;
    }
};

int Details::cId[6];
string Details::name[6];
string Details::gender[6];
int Details::pnr;
string Details::bp[6];
int Details::age[6];
int Details::n;

class registration : public Details
{
public:
    static int choice;
    int choice1;
    int back;
    static float charges;

    void trains()
    {
        string trainsN[] = {"DELHI", "KOLKATA", "PATNA", "NAGPUR", "JAIPUR", "MUMBAI"};

        for (int a = 0; a < 6; a++)
        {
            cout << (a + 1) << ".train to " << trainsN[a] << endl;
        }

        cout << "\nWELCOME TO THE RAIWAYS!" << endl;
        cout << "Press the number of the city you want to book the train:";
        cin >> choice;
        int f;

        switch (choice)
        {
        case 1:
        {
            cout << "_WELCOME TO DELHI_\n"
                 << endl;
            cout << " your comfort is our priority , Enjoy the journey!" << endl;
            cout << " Following are the Trains \n"
                 << endl;

            cout << " 1.DEL-123 " << endl;
            cout << "\t08-01-2022  8:00AM  10hrs  3A-Rs.2100 2A-Rs.3100 1A-Rs.5200" << endl;
            cout << " 2.DEL-345 " << endl;
            cout << "\t09-01-2022  10:00AM  15hrs  3A-Rs.2300 2A-Rs.3300 1A-Rs.5400" << endl;
            cout << " 3.DEL-456" << endl;
            cout << "\t10-01-2022  11:00AM  20hrs  3A-Rs.2400 2A-Rs.3500 1A-Rs.5100" << endl;

            cout << "\n Select the Trains you want to book : ";
            cin >> choice1;
            cout << "\n Enter the AC class in which u want to travel : ";
            cin >> f;

            if (choice1 == 1)
            {
                if (f == 3)
                {
                    charges = 2100;
                }
                else if (f == 2)
                {
                    charges = 3100;
                }
                else if (f == 1)
                {
                    charges = 5200;
                }

                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN DEL-123" << endl;

                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }

            else if (choice1 == 2)
            {
                if (f == 3)
                {
                    charges = 2300;
                }
                else if (f == 2)
                {
                    charges = 3300;
                }
                else if (f == 1)
                {
                    charges = 5400;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN DEL-345" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 3)
            {
                if (f == 3)
                {
                    charges = 2400;
                }
                else if (f == 2)
                {
                    charges = 3500;
                }
                else if (f == 1)
                {
                    charges = 5100;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN DEL-456" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else
            {
                cout << " Invalid input,shifting to previous menu" << endl;
                trains();
            }

            cout << " press any key to go back to the main menu: " << endl;
            cin >> back;

            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }

            break;
        }

        case 2:
        {
            cout << "_WELCOME TO KOLKATA_\n"
                 << endl;
            cout << " your comfort is our priority , Enjoy the journey!" << endl;
            cout << " Following are the Trains \n"
                 << endl;

            cout << " 1.KOL-897 " << endl;
            cout << "\t20-01-2022  8:00PM  10hrs 3A-Rs.1800 2A-Rs.2600 1A-Rs.4400" << endl;
            cout << " 2.KOL-567 " << endl;
            cout << "\t21-01-2022  10:00PM  15hrs 3AC-Rs.1900 2AC-Rs.2200 1AC-Rs.4800" << endl;
            cout << " 3.KOL-789" << endl;
            cout << "\t22-01-2022  11:00PM  20hrs 3A-Rs.1700 2A-Rs.2100 1A-Rs.4500" << endl;

            cout << "\n Select the TRAINS you want to book : ";
            cin >> choice1;
            cout << "\n Enter the AC class in which u want to travel : ";
            cin >> f;

            if (choice1 == 1)
            {
                if (f == 3)
                {
                    charges = 1800;
                }
                else if (f == 2)
                {
                    charges = 2600;
                }
                else if (f == 1)
                {
                    charges = 4400;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN KOL-897" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 2)
            {
                if (f == 3)
                {
                    charges = 1900;
                }
                else if (f == 2)
                {
                    charges = 2200;
                }
                else if (f == 1)
                {
                    charges = 4800;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN KOL-567" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 3)
            {
                if (f == 3)
                {
                    charges = 1700;
                }
                else if (f == 2)
                {
                    charges = 2100;
                }
                else if (f == 1)
                {
                    charges = 4500;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN KOL-789" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else
            {
                cout << " Invalid input,shifting to previous menu" << endl;
                trains();
            }

            cout << " press any key to go back to the main menu: " << endl;
            cin >> back;

            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }

            break;
        }

        case 3:
        {
            cout << "_WELCOME TO PATNA_\n"
                 << endl;
            cout << " your comfort is our priority , Enjoy the journey!" << endl;
            cout << " Following are the TRAINS \n"
                 << endl;

            cout << " 1.PAT-123 " << endl;
            cout << "\t24-01-2022  12:00AM  10hrs 3A-Rs.2200 2A-Rs.3200 1A-Rs.5500" << endl;
            cout << " 2.PAT-345 " << endl;
            cout << "\t25-01-2022  2:00PM 15hrs  3A-Rs.2300 2A-Rs.3400 1A-Rs.5600" << endl;
            cout << " 3.PAT-456" << endl;
            cout << "\t26-01-2022  4:00PM  20hrs  3A-Rs.2400 2A-Rs.3600 1A-Rs.5700" << endl;

            cout << "\n Select the TRAINS you want to book : ";
            cin >> choice1;
            cout << "\n Enter the AC class in which u want to travel : ";
            cin >> f;

            if (choice1 == 1)
            {
                if (f == 3)
                {
                    charges = 2200;
                }
                else if (f == 2)
                {
                    charges = 3200;
                }
                else if (f == 1)
                {
                    charges = 5500;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN PAT-123" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 2)
            {
                if (f == 3)
                {
                    charges = 2300;
                }
                else if (f == 2)
                {
                    charges = 3400;
                }
                else if (f == 1)
                {
                    charges = 5600;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN PAT-345" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 3)
            {
                if (f == 3)
                {
                    charges = 2400;
                }
                else if (f == 2)
                {
                    charges = 3600;
                }
                else if (f == 1)
                {
                    charges = 5700;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN PAT-456" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else
            {
                cout << " Invalid input,shifting to previous menu" << endl;
                trains();
            }

            cout << " press any key to go back to the main menu: " << endl;
            cin >> back;

            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }

            break;
        }
        case 4:
        {
            cout << "_WELCOME TO NAGPUR_\n"
                 << endl;
            cout << " your comfort is our priority , Enjoy the journey!" << endl;
            cout << " Following are the TRAINS \n"
                 << endl;

            cout << " 1.NAG-123 " << endl;
            cout << "\t14-03-2022  12:00AM  10hrs 3AC-Rs.1300 2AC-Rs.1900 1AC-Rs.3400" << endl;
            cout << " 1.NAG-345 " << endl;
            cout << "\t15-03-2022  2:00PM 15hrs  3AC-Rs.1400 2AC-Rs.2000 1AC-Rs.3500" << endl;
            cout << " 1.NAG-456" << endl;
            cout << "\t16-03-2022  4:00PM  20hrs 3AC-Rs.1500 2AC-Rs.2100 1AC-Rs.4200" << endl;

            cout << "\n Select the TRAINS you want to book : ";
            cin >> choice1;
            cout << "\n Enter the AC class in which u want to travel : ";
            cin >> f;

            if (choice1 == 1)
            {
                if (f == 3)
                {
                    charges = 1300;
                }
                else if (f == 2)
                {
                    charges = 1900;
                }
                else if (f == 1)
                {
                    charges = 3400;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN NAG-123" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 2)
            {
                if (f == 3)
                {
                    charges = 1400;
                }
                else if (f == 2)
                {
                    charges = 2000;
                }
                else if (f == 1)
                {
                    charges = 3500;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN NAG-345" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 3)
            {
                if (f == 3)
                {
                    charges = 1500;
                }
                else if (f == 2)
                {
                    charges = 2100;
                }
                else if (f == 1)
                {
                    charges = 4200;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN NAG-456" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else
            {
                cout << " Invalid input,shifting to previous menu" << endl;
                trains();
            }

            cout << " press any key to go back to the main menu: " << endl;
            cin >> back;

            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }

            break;
        }

        case 5:
        {
            cout << "_WELCOME TO JAIPUR_\n"
                 << endl;
            cout << " your comfort is our priority , Enjoy the journey!" << endl;
            cout << " Following are the TRAINS \n"
                 << endl;

            cout << " 1.JAI-123 " << endl;
            cout << "\t17-01-2022  12:00AM  10hrs 3A-Rs.2200 2A-Rs.3200 1A-Rs.5300" << endl;
            cout << " 2.JAI-345 " << endl;
            cout << "\t18-01-2022  2:00PM 15hrs 3A-Rs.2300 2A-Rs.3300 1A-Rs.5400" << endl;
            cout << " 3.JAI-456" << endl;
            cout << "\t19-01-2022  4:00PM  20hrs 3A-Rs.2400 2A-Rs.3500 1A-Rs.5500" << endl;

            cout << "\n Select the TRAINS you want to book : ";
            cin >> choice1;
            cout << "\n Enter the AC class in which u want to travel : ";

            cin >> f;

            if (choice1 == 1)
            {
                if (f == 3)
                {
                    charges = 2200;
                }
                else if (f == 2)
                {
                    charges = 3200;
                }
                else if (f == 1)
                {
                    charges = 5300;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN JAI-123" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 2)
            {
                if (f == 3)
                {
                    charges = 2300;
                }
                else if (f == 2)
                {
                    charges = 3300;
                }
                else if (f == 1)
                {
                    charges = 5400;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN JAI-345" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 3)
            {
                if (f == 3)
                {
                    charges = 2400;
                }
                else if (f == 2)
                {
                    charges = 3500;
                }
                else if (f == 1)
                {
                    charges = 5500;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN JAI-456" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else
            {
                cout << " Invalid input,shifting to previous menu" << endl;
                trains();
            }

            cout << " press any key to go back to the main menu: " << endl;
            cin >> back;

            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
            break;
        }

        case 6:
        {

            cout << "_WELCOME TO MUMBAI_\n"
                 << endl;
            cout << " your comfort is our priority , Enjoy the journey!" << endl;
            cout << " Following are the TRAINS \n"
                 << endl;

            cout << " 1.MUM-123 " << endl;
            cout << "\t04-09-2022  12:00AM  10hrs  3A-Rs.1500 2A-Rs.2200 1A-Rs.3700" << endl;
            cout << " 2.MUM-345 " << endl;
            cout << "\t05-09-2022  2:00PM 15hrs  3A-Rs.1600 2A-Rs.2300 1A-Rs.3800" << endl;
            cout << " 3.MUM-456" << endl;
            cout << "\t06-09-2022  4:00PM  20hrs  3A-Rs.1700 2A-Rs.2400 1A-Rs.3900" << endl;

            cout << "\n Select the TRAINS you want to book : ";
            cin >> choice1;
            cout << "\n Enter the AC class in which u want to travel : ";
            cin >> f;

            if (choice1 == 1)
            {
                if (f == 3)
                {
                    charges = 1500;
                }
                else if (f == 2)
                {
                    charges = 2200;
                }
                else if (f == 1)
                {
                    charges = 3700;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN MUM-123" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 2)
            {
                if (f == 3)
                {
                    charges = 1600;
                }
                else if (f == 2)
                {
                    charges = 2300;
                }
                else if (f == 1)
                {
                    charges = 3800;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN MUM-345" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 3)
            {
                if (f == 3)
                {
                    charges = 1700;
                }
                else if (f == 2)
                {
                    charges = 2400;
                }
                else if (f == 1)
                {
                    charges = 3900;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN MUM-456" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else
            {
                cout << " Invalid input,shifting to previous menu" << endl;
                trains();
            }

            cout << " press any key to go back to the main menu: " << endl;
            cin >> back;

            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }

            break;
        }
        default:
        {
            cout << " INVALID input,Shifting you to the main menu !" << endl;
            mainMenu();
            break;
        }
        }
    }
};

;

float registration::charges;
int registration::choice;

class ticket : public registration
{

public:
    void Bill()
    {

        string destination[6] = "";

        for (int i = 0; i < n; i++)
        {

            ofstream outf("tickets.txt", ios::app);
            {

                outf << pnr << "\t\t|";
                outf << cId[i] << "\t\t|";
                outf << name[i] << "\t|";
                outf << gender[i] << "\t|";

                if (registration::choice == 1)
                {
                    destination[i] = "Delhi";
                }

                else if (registration::choice == 2)
                {
                    destination[i] = "Chennai";
                }

                else if (registration::choice == 3)
                {
                    destination[i] = "Patna";
                }

                else if (registration::choice == 4)
                {
                    destination[i] = "Nagpur";
                }

                else if (registration::choice == 5)
                {
                    destination[i] = "Jaipur";
                }

                else if (registration::choice == 6)
                {
                    destination[i] = "Mumbai";
                }

                outf << "CHN"
                     << "\t\t|";
                outf << destination[i] << "\t\t|";
                outf << registration::charges << "\t|";
                outf << endl;
            }

            outf.close();
        }
        cout << "Total Cost: " << charges * n;
    }

    void database()
    {
        string destination[6] = "";

        for (int i = 0; i < n; i++)
        {

            ofstream outf("records.txt", ios::app);
            {

                outf << pnr << " ";
                outf << cId[i] << " ";
                outf << name[i] << " ";
                outf << gender[i] << " ";

                if (registration::choice == 1)
                {
                    destination[i] = "Delhi";
                }

                else if (registration::choice == 2)
                {
                    destination[i] = "Chennai";
                }

                else if (registration::choice == 3)
                {
                    destination[i] = "Patna";
                }

                else if (registration::choice == 4)
                {
                    destination[i] = "Nagpur";
                }

                else if (registration::choice == 5)
                {
                    destination[i] = "Jaipur";
                }

                else if (registration::choice == 6)
                {
                    destination[i] = "Mumbai";
                }

                outf << destination[i] << " ";
                outf << registration::charges;
                outf << endl;
            }

            outf.close();
        }
    }

    void dispBill()
    {

        cout << "____XYZ Railways_____" << endl;
        cout << "____Tickets______" << endl;
        cout << "___________" << endl
             << endl;
        ;

        cout << "PNR Num\t\t\t|"
             << "Customer ID\t|"
             << "Name\t|"
             << "Gender\t|"
             << "Boarding\t|"
             << "Destination\t|"
             << "Charge\t|" << endl;

        ifstream ifs("tickets.txt");
        {
            if (!ifs)
            {
                cout << "File error!" << endl;
            }

            while (!ifs.eof())
            {

                ifs.getline(arr, 100);
                cout << arr << endl;
            }
        }

        ifs.close();
    }

    void dispDatabase()
    {
        string cpnr,cid,cname,cgen,cdest,ccharge;

        cout << "____XYZ Railways_____" << endl;

        cout << "____Tickets______" << endl;
        cout << "___________" << endl
             << endl;
        ;

        cout << "|PNR Num\t|"
             << "Customer ID\t|"
             << "Name\t\t|"
             << "Gender\t|"
             << "Destination\t|"
             << "Charge\t\t|" << endl;

        ifstream ifs;
        ifs.open("records.txt");

        while(ifs>>cpnr>>cid>>cname>>cgen>>cdest>>ccharge){
            cout<<"|"<<cpnr<<"\t|"<<cid<<"\t\t|"<<cname<<"\t\t|"<<cgen<<"\t|"<<cdest<<"\t\t|Rs. "<<ccharge<<"\t|"<<endl;
        }


        ifs.close();
        cout<<endl;
    }

    void deletedata()
    {
        ticket obj;
        int w;
        cout << "Enter PNR no.:" << endl;
        cin >> w;
        string line;
        int cpnr, ccharges, ccid;
        string cname, cgen, cdest;

        ifstream myfile;
        ofstream temp;
        myfile.open("records.txt");
        temp.open("temp.txt");
        while (myfile >> cpnr >> ccid >> cname >> cgen >> cdest >> ccharges)
        {
            // myfile >> cpnr >> ccid >> cname >> cgen >> cdest >> ccharges;

            if (cpnr != w)
                temp << cpnr << " " << ccid << " " << cname << " " << cgen << " " << cdest << " " << ccharges << endl
                     << flush;
        }
        cout << "The record with the name " << w << " has been deleted if it exsisted" << endl;
        myfile.close();
        temp.close();
        remove("records.txt");
        getchar();
        rename("temp.txt", "records.txt");
    }
};

class orderFood : public ticket
{

public:
    string fpnr, cpnr, cname, ccid, cgen, cdest, ccharges;
    int fcharges;

    void foodOptions()
    {
        cout << "\n____________________________________________________________________" << endl;
        cout << "____________________WELCOME TO E-CATERING SERVICE_______________________" << endl
             << endl;
        cout << "\t1. View Menu and Order Food" << endl;
        cout << "\t2. Print Receipt" << endl;
        cout << "\t3. Back" << endl;
        cin >> choice1;
        cout << endl;

        switch (choice1)
        {
        case 1:
        {
            char filename[]="foodr.txt";
            remove(filename);
            getDetails();

            break;
        }

        case 2:
        {
            displayFoodReceipt();
            break;
        }

        case 3:
        {
            mainMenu2();
            
            break;
        }

        default:
        {
            cout << "Invalid Option! Try Again!" << endl;
            foodOptions();
        }
        }
    }

    void getDetails()
    {
        cout << "\n____________________________________________________________________" << endl;
        cout << "Enter Details to continue" << endl;
        cout << "\tEnter Your PNR number: ";
        cin >> fpnr;

        ifstream f1;
        f1.open("records.txt");
        do
        {
            if (f1.eof())
            {
                cout << "PNR does not match with our record!\nPlease Enter a valid PNR! " << endl;
                f1.close();
                getDetails();
            }

            f1 >> cpnr >> ccid >> cname >> cgen >> cdest >> ccharges;
            

        } while (cpnr != fpnr);
        f1.close();

        if (cpnr == fpnr)
        {
            cout << "Welcome " << cname << "! Please find the Menu!" << endl;
            displayMenu();
        }

        else
        {
            cout << "Try Again" << endl;
            getDetails();
        }
    }

    void displayMenu()
    {
        fcharges = 0;
        cout << "\n____________________________________________________________________" << endl;
        cout << "____________________________FOOD MENU_________________________________" << endl
             << endl;

        cout << "\t|S.no."
             << "\t|Item Name"
             << "\t\t\t\t|Price"
             << "\t\t|" << endl;
        cout << "\t|1."
             << "\t|Simple Veg Thali"
             << "\t\t\t|Rs. 190"
             << "\t\t|" << endl;
        cout << "\t|2."
             << "\t|Special Veg Thali"
             << "\t\t\t|Rs. 210"
             << "\t\t|" << endl;
        cout << "\t|3."
             << "\t|Veg Deluxe Thali"
             << "\t\t\t|Rs. 240"
             << "\t\t|" << endl;
        cout << "\t|4."
             << "\t|Simple Non-Veg Thali"
             << "\t\t\t|Rs. 210"
             << "\t\t|" << endl;
        cout << "\t|5."
             << "\t|Special Non-Veg Thali"
             << "\t\t\t|Rs. 250"
             << "\t\t|" << endl;
        cout << "\t|6."
             << "\t|Non-Veg Deluxe Thali"
             << "\t\t\t|Rs. 270"
             << "\t\t|" << endl;
        cout << "\t|7."
             << "\t|Simple South-Indian Thali"
             << "\t\t|Rs. 210"
             << "\t\t|" << endl;
        cout << "\t|8."
             << "\t|Special South-Indian Thali"
             << "\t\t|Rs. 240"
             << "\t\t|" << endl;

        int choicess[8], noOfItems;
        cout << "Enter the number of Items you want to book: " << endl;
        cin >> noOfItems;

        for (int i = 0; i < noOfItems; i++)
        {
        tryagain:
            cout << "Enter your Choice " << i + 1 << ": ";
            cin >> choicess[i];
            cout << endl;

            fstream f2;
            fstream f3;

            f2.open("foodr.txt", ios::app);
            f3.open("foodd.txt", ios::app);

            switch (choicess[i])
            {
            case 1:
            {
                cout << "\tSimple Veg Thali booked!" << endl;
                fcharges += 190;
                f2 << "\t|Simple Veg Thali"
                   << "\t\t"
                   << "Rs. 190" << endl;
                f3 << cpnr << " Simple Veg Thali"
                   << " 190" << endl;
                break;
            }

            case 2:
            {
                cout << "\tSpecial Veg Thali booked!" << endl;
                fcharges += 210;
                f2 << "\t|Special Veg Thali"
                   << "\t\t"
                   << "Rs. 210" << endl;
                f3 << cpnr << " Special Veg Thali"
                   << " 210" << endl;
                break;
            }

            case 3:
            {
                cout << "Veg Deluxe Thali booked!" << endl;
                fcharges += 240;
                f2 << "\t|Veg Deluxe Thali"
                   << "\t\t"
                   << "Rs. 210" << endl;
                f3 << cpnr << " Veg Deluxe Thali"
                   << " 210" << endl;
                break;
            }

            case 4:
            {
                cout << "Simple Non-Veg Thali booked!" << endl;
                fcharges += 210;
                f2 << "\t|Simple Non-Veg Thali"
                   << "\t\t"
                   << "Rs. 210" << endl;
                f3 << cpnr << " Simple Non-Veg Thali"
                   << " 210" << endl;
                break;
            }

            case 5:
            {
                cout << "Special Non-Veg Thali booked!" << endl;
                fcharges += 250;
                f2 << "\t|Simple Non-Veg Thali"
                   << "\t\t"
                   << "Rs. 250" << endl;
                f3 << cpnr << " Simple Non-Veg Thali"
                   << " 250" << endl;
                break;
            }

            case 6:
            {
                cout << "Non-Veg Deluxe Thali booked!" << endl;
                fcharges += 270;
                f2 << "\t|Non-Veg Deluxe Thali"
                   << "\t\t"
                   << "Rs. 270" << endl;
                f3 << cpnr << " Non-Veg Deluxe Thali"
                   << " 270" << endl;
                break;
            }

            case 7:
            {
                cout << "Simple South-Indian Thali booked!" << endl;
                fcharges += 210;
                f2 << "\t|Simple South-Indian Thali"
                   << "\t"
                   << "Rs. 210" << endl;
                f3 << cpnr << " Simple South-Indian Thali"
                   << " 210" << endl;
                break;
            }

            case 8:
            {
                cout << "Special South-Indian Thali booked!" << endl;
                fcharges += 240;
                f2 << "\t|Special South-Indian Thali"
                   << "\t"
                   << "Rs. 240" << endl;
                f3 << cpnr << " Special South-Indian Thali"
                   << " 240" << endl;
                break;
            }

            default:
            {
                cout << "Enter Valid Input!\n";
                f2.close();
                f3.close();
                goto tryagain;

                break;
            }
            }

            f2.close();
            f3.close();
        }

        cout << "Order Placed Successfully! Please collect your Reciept by Print Reciept option!" << endl;
        system("pause");
        foodOptions();
    }

    void displayFoodReceipt()
    {

        cout << "\n________________________________________________________________________" << endl;
        cout << "____________________________ORDER RECIEPT_________________________________" << endl
             << endl;

        cout << "\tPassenger Details:\n";
        cout << "\t|PNR Num\t\t|"
             << "Name\t|"
             << "Gender\t|"
             << "Boarding\t|"
             << "Destination\t|"
             << endl;
        cout << "\t|" << cpnr << "\t\t|" << cname << "\t|" << cgen << "\t|CHN\t\t|" << cdest << "\t\t|" << endl
             << endl;

        cout << "\tOrdered Food Details:\n";
        ifstream f4("foodr.txt");
        {
            if (!f4)
            {
                cout << "File error!" << endl;
            }

            while (!f4.eof())
            {

                f4.getline(arr, 100);
                cout << arr << endl;
            }
        }

        f4.close();
        system("pause");
        foodOptions();
    }

    void displayFoodDatabase()
    {

        string food1, food2, food3, price;

        cout << "\n________________________________________________________________________" << endl;
        cout << "____________________________FOOD DATABASE_________________________________" << endl
             << endl;

        cout << "\t|PNR no\t\t|Item Name\t\t\t\t|Price\t\t|" << endl;
        ;

        fstream f5("foodd.txt", ios::in);
        while (f5 >> cpnr >> food1 >> food2 >> food3 >> price)
        {

            cout << "\t|" << cpnr << "\t|" << food1 << " " << food2 << " " << food3 << "\t\t\t|Rs. " << price << "\t|" << endl;
            cout << flush;
        }

        f5.close();
        system("pause");
    }
};

void mainMenu()
{
    int lchoice;
    int schoice, back;

    cout << "\t               XYZ Railways " << endl
         << endl;
    cout << "\t_________________________Main Menu_______________________" << endl;

    cout << "\t___________________________________________________________" << endl;
    cout << "\t|\t\t\t\t\t\t\t|" << endl;

    cout << "\t|\t Press 1 to add the Customer Details    \t|" << endl;
    cout << "\t|\t Press 2 for Train Booking              \t|" << endl;
    cout << "\t|\t Press 3 for Ticket and Charges         \t|" << endl;
    cout << "\t|\t Press 4 to display Database            \t|" << endl;
    cout << "\t|\t Press 5 to Cancel                      \t|" << endl;
    cout << "\t|\t Press 6 to view E-Catering Database    \t|" << endl;    
    cout << "\t|\t Press 7 exit                           \t|" << endl;
    cout << "\t|\t\t\t\t\t\t\t|" << endl;
    cout << "\t___________________________________________________________" << endl;

    cout << "Enter the Choice: ";
    cin >> lchoice;

    Details d;
    registration r;
    ticket t;
    orderFood f;
    // cancel c;

    switch (lchoice)
    {
    case 1:
    {
        char filename[] = "tickets.txt";
        remove(filename);

        cout << "____Customers___" << endl
             << endl;
        d.information();
        cout << "Press any key to go back to the Main Menu" << endl;
        cin >> back;

        if (back == 1)
        {
            mainMenu();
        }

        else
        {
            mainMenu();
        }

        break;
    }

    case 2:
    {
        cout << "___Book a ticket in this section__" << endl
             << endl;
        r.trains();
        break;
    }

    case 3:
    {
        cout << "____Getting your Ticket___" << endl
             << endl;
        t.Bill();

        cout << "Your Ticket is printed, you can collect it" << endl
             << endl;

        cout << "Press 1 to display your ticket ";
        cin >> back;

        if (back == 1)
        {
            t.dispBill();
            t.database();
            cout << "Press any key to go back" << endl;
            cin >> back;

            if (back == 1)
            {
                mainMenu();
            }

            else
            {
                mainMenu();
            }
        }

        else
        {
            mainMenu();
        }
        break;
    }

    case 4:
    {
        t.dispDatabase();
        cout << "Press any key to go back" << endl;
        cin >> back;

        if (back == 1)
        {
            mainMenu();
        }

        else
        {
            mainMenu();
        }

        break;
    }

    case 5:
    {
        t.deletedata();
        cout << "Press any key to go back" << endl;
        cin >> back;

        if (back == 1)
        {
            mainMenu();
        }

        else
        {
            mainMenu();
        }

        break;
    }

    case 7:
    {
        cout << endl
             << endl;

        return;
        break;
    }

    case 6:
    {
        f.displayFoodDatabase();
        mainMenu();

        break;
    }

    default:
    {
        cout << "Invalid Input, Please try again!" << endl
             << endl;
        mainMenu();
        break;
    }
    }
}

// mainmenu2

void mainMenu2()
{
    int lchoice;
    int schoice, back;

    cout << "\t               XYZ Railways " << endl
         << endl;
    cout << "\t_________________________Main Menu_______________________" << endl;

    cout << "\t___________________________________________________________" << endl;
    cout << "\t|\t\t\t\t\t\t\t|" << endl;

    cout << "\t|\t Press 1 to add the Customer Details    \t|" << endl;
    cout << "\t|\t Press 2 for Train Booking              \t|" << endl;
    cout << "\t|\t Press 3 for Ticket and Charges         \t|" << endl;

    cout << "\t|\t Press 4 to Cancel                      \t|" << endl;
    cout << "\t|\t Press 5 to order food                  \t|" << endl;

    cout << "\t|\t Press 6 exit                           \t|" << endl;
    cout << "\t|\t\t\t\t\t\t\t|" << endl;
    cout << "\t____________________________________________________________" << endl;

    cout << "Enter the Choice: ";
    cin >> lchoice;

    Details d;
    registration r;
    ticket t;
    orderFood f;
    // cancel c;

    switch (lchoice)
    {
    case 1:
    {
        char filename[] = "tickets.txt";
        remove(filename);

        cout << "____Customers___" << endl
             << endl;
        d.information();
        cout << "Press any key to go back to the Main Menu" << endl;
        cin >> back;

        if (back == 1)
        {
            mainMenu();
        }

        else
        {
            mainMenu();
        }

        break;
    }

    case 2:
    {
        cout << "___Book a ticket in this section__" << endl
             << endl;
        r.trains();
        break;
    }

    case 3:
    {
        cout << "____Getting your Ticket___" << endl
             << endl;
        t.Bill();

        cout << "Your Ticket is printed, you can collect it" << endl
             << endl;

        cout << "Press 1 to display your ticket ";
        cin >> back;

        if (back == 1)
        {
            t.dispBill();
            t.database();
            cout << "Press any key to go back" << endl;
            cin >> back;

            if (back == 1)
            {
                mainMenu();
            }

            else
            {
                mainMenu();
            }
        }

        else
        {
            mainMenu();
        }
        break;
    }

    case 4:
    {
        t.deletedata();
        cout << "Press any key to go back" << endl;
        cin >> back;

        if (back == 1)
        {
            mainMenu();
        }

        else
        {
            mainMenu();
        }

        break;
    }

    case 5:
    {
        f.foodOptions();

        break;
    }

    case 6:
    {
        cout << endl
             << endl;

        firstPage();
        break;
    }

    default:
    {
        cout << "Invalid Input, Please try again!" << endl
             << endl;
        mainMenu();
        break;
    }
    }
};

int main()
{
    Management mobj;
    // orderFood f;
    // f.foodOptions();
    // f.displayFoodDatabase();

    return 0;
}