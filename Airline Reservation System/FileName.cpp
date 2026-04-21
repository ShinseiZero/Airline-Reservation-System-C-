#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h> // only for decoration purpose

using namespace std;
//cover page function prototype
void cover();
//admin page function prototype
void adminpage();

//flight menu page function prototype
void flightmenu();
//filter options function prototype
void filteroriginFlight();
void filterdestinationFlight();
void filterflightnumber();
//reservation seat function prototype
void bookflight();

const int ROWS = 25;
const int COLUMNS = 4;
const int NUM_FLIGHTS = 40;
int totalseat;
//show seat chart of every flight funtion 
void readSeatingChart(int i, int& totalseat);
//create seat chart while adding flight function
void writeSeatingChart(int);
char seats[ROWS][COLUMNS];
string filename[40] = { "flight1.txt", "flight2.txt", "flight3.txt","flight4.txt","flight5.txt","flight6.txt","flight7.txt","flight8.txt","flight9.txt","flight10.txt","flight11.txt","flight12.txt","flight13.txt","flight14.txt","flight15.txt","flight16.txt","flight17.txt","flight18.txt","flight19.txt","flight20.txt","flight21.txt","flight22.txt","flight23.txt","flight24.txt","flight25.txt","flight26.txt","flight27.txt","flight28.txt","flight29.txt","flight30.txt","flight31.txt","flight32.txt","flight33.txt","flight34.txt","flight35.txt","flight36.txt","flight37.txt","flight38.txt","flight39.txt","flight40.txt", };
//payment page function prototype
void paymentpage(int,int,int);

//Size of flight array
const int maxNumber = 40;

//struct of flight details

struct FlightDetails {
    string flightNumber;
    string origin;
    string destination;
    string date;
    string departureTime;
    string arrivalTime;
    string duration;
    int seat = 0;
    double price = 0.0;
};

//add flight function prototype
void addFlight(FlightDetails flight[], int& no);
//display flight function prototype
void displayFlight(FlightDetails flight[], int& no);
//update flight function prototype
void editFlight(FlightDetails flight[], int& no);
//delete flight function prototype
void deleteFlight(FlightDetails flight[], int& no);

void reservationmenu();
void custumerReserve();
void changeflightdetail(); //yes
void specialrequest();//yes
void cancelreservation();
void axiabar(); //yes

int main()
{
    cover();//call function for cover page

    int option;
    string password;
    string pass = "admin1234"; //admin password
    int adminChoice = 0;


    do
    {

        cout << "================================================================\n";
        cout << "|+++++++++++++++\033[35m AXIA Airline Reservation System \033[0m+++++++++++++++|\n";
        cout << "================================================================\n";
        cout << " \033[36m" << endl;
        cout << "             ______\n";
        cout << "         _I _~-I___\n";
        cout << " =  = ==(____AA____D\n";
        cout << "             [_____]___________________,-~~~~~~~`-.._\n";
        cout << "             /     o O o o o o O O o o o o o o O __|-',_\n";
        cout << "             |   []    AXIA  Airline  o  o o o o|__| o o o ]  \n";
        cout << "             \\~-.__        ___..----..                   )\n";
        cout << "                   `---~~|___________/------------````'`\n";
        cout << "                   =  ===(_________D\n";
        cout << " \033[0m" << endl;

        cout << "     \033[32m Welcome to the Axia Airline Reservation System! \033[0m\n\n";
        cout << "     Please select an option:\n";
        cout << "     ===================================\n";
        cout << "     | Option |       Description       |\n";
        cout << "     ===================================\n";
        cout << "     |   1    |     Search for flights  |\n";
        cout << "     |   2    |       Book a flight     |\n";
        cout << "     |   3    |     Show reservations   |\n";
        cout << "     |   4    |    Cancel a reservation |\n";
        cout << "     |   5    |      ***admin login***  |\n";
        cout << "     |   6    |            Exit         |\n";
        cout << "     ===================================\n\n";
        /*cout << "                     ______                          \n";
        cout << "                    |7 back|                          \n";
        cout << "                     ------                          \n";*/


        cout << "Dear user, please key in your 0ption: ";
        while (!(cin >> option)) // to make sure admin input int only but not char or string.
        {
            cout << "\033[31m";
            cout << "\nInvalid input. Please enter an integer: ";
            cout << "\033[0m";
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }
        system("cls");



        switch (option) {
        case 1:
            // code to search for flights and filter flight
            cout << "searching for flights......." << endl;
            Sleep(2000);
            system("cls");

            flightmenu();
            break;
        case 2:
            // code to book a flight and payment
            bookflight();
            break;
        case 3:
            // code to Show reservations
            cout << "loading for reservation......" << endl;
            Sleep(2000);
            system("cls");

            reservationmenu();
            break;
        case 4:
            // code to cancel a reservation
            break;
        case 5:
            //code for entering admin page
            cout << "    5: Admin Login\n";
            cout << "\033[33m" << endl;
            cout << "************************************************************************" << endl;
            cout << "*    _____     ._        .__.        .__.                 .__.         *" << endl;
            cout << "*   /  _  |  __| | _____ |__| _____  |  |   _____   _____ |__| _____   *" << endl;
            cout << "*  /  /_| | / __ |/     ||  |/     | |  |  /  _  | /  _  ||  |/     |  *" << endl;
            cout << "* /    |  |/ /_/ |  Y Y ||  |   |  | |  |_ | '_' |/  '_' /|  |   |  |  *" << endl;
            cout << "* |____|__|`_____|__|_|_||__|___|__| |____/`____/ |___  / |__|___|__|  *" << endl;
            cout << "*                                                /_____/               *" << endl;
            cout << "************************************************************************" << endl;
            cout << "\033[0m" << endl;
            cout << "                             ______                          \n";
            cout << "                            |7 back|                          \n";
            cout << "                             ------                          \n";


            do
            {
                cout << "Please enter your password: ";
                cin >> password;

                if (password == pass)
                {
                    cout << " Login succesfull...\n Entering administrator mode....\n";
                }
                else
                {
                    cout << "\033[31m";
                    cout << "Wrong password... Please reenter password.\n";
                    cout << "\033[0m";
                }
                if (password == "7")
                {
                    system("cls");
                    main();
                }
            } while (password != pass);

            system("cls");
            cout << " \033[32m Login succesfull...\n\n Entering administrator mode....\033[0m\n\n";
            Sleep(1700);
            system("cls");
            adminpage(); // call function of admin page
            break;
        case 6:

            cout << "  d888888P dP                         dP" << endl;
            cout << "     88    88                         88                " << endl;
            cout << "     88    88d888b. .d8888b. 88d888b. 88  .dP  .d8888b. " << endl;
            cout << "     88    88'  `88 88'  `88 88'  `88 88888    Y8ooooo. " << endl;
            cout << "     88    88    88 88.  .88 88    88 88  `8b.       88 " << endl;
            cout << "     dP    dP    dP `88888P8 dP    dP dP   `YP `88888P' " << endl << endl;


            cout << "   d8b                    8                      w                           = " << endl;
            cout << "   8'  .d8b. 8d8b    .d8b 8d8b. .d8b. .d8b. d88b w 8d8b. .d88    8   8 d88b  = " << endl;
            cout << " *w8ww 8' .8 8P      8    8P Y8 8' .8 8' .8 `Yb. 8 8P Y8 8  8    8b d8 `Yb.  = " << endl;
            cout << "   8   `Y8P' 8       `Y8P 8   8 `Y8P' `Y8P' Y88P 8 8   8 `Y88    `Y8P8 Y88P    " << endl;
            cout << "   *                                                     wwdP                0 " << endl;


            cout << "   ____                                                            " << endl;
            cout << "  (  _``                                                  _        " << endl;
            cout << "  | (_(_)   __     __      _   _       _ _    __     _ _ (_)  ___  " << endl;
            cout << "  ` __ `  /'__`i /'__`i   ( ) ( )    /'_` ) /'_ `i /'_` )| |/' _ `i " << endl;
            cout << "  ( )_) |(  ___/(  ___/   | (_) |   ( (_| |( (_) |( (_| || || ( ) |" << endl;
            cout << "  `i____)`i____)`i____)   `i___/'   `i__,_)`i__  |`i__,_)(_)(_) (_)" << endl;
            cout << "                                           ( )_) |                 " << endl;
            cout << "                                            i___/'                 " << endl;




            cout << "Thank you for using Axia Airline Reservation System!\n";
            system("pause");
            break;

        default:

            cout << "\033[31m"; //change to red colour
            cout << " #### ##    ## ##     ##    ###    ##       #### ######## " << endl;
            cout << "  ##  ###   ## ##     ##   ## ##   ##        ##  ##     ## " << endl;
            cout << "  ##  ####  ## ##     ##  ##   ##  ##        ##  ##     ## " << endl;
            cout << "  ##  ## ## ## ##     ## ##     ## ##        ##  ##     ## " << endl;
            cout << "  ##  ##  ####  ##   ##  ######### ##        ##  ##     ## " << endl;
            cout << "  ##  ##   ###   ## ##   ##     ## ##        ##  ##     ## " << endl;
            cout << " #### ##    ##    ###    ##     ## ######## #### ######## " << endl;
            cout << "\n*******Invalid option selected. \n";

            cout << "\033[0m"//change back default colour
                << "    Key in number range from       \n\n"

                << "     ####   @      O        \n"
                << "    #    #  # # #  O  #  #  \n"
                << "    #    #  #   #  O  #  #  \n"
                << "     ####   #   #  O  ####  \n"
                << "                         #  \n"
                << "                      ####  \n"

                << "\033[33m"//change to yellow colour
                << "  O))                      O)) O))) \n"
                << " @ O))                     O))      \n"
                << "   O))        ######       O)))O))* \n"
                << "   O))                     0)   0** \n"
                << "   O))                     0)   O)) \n"
                << " *O))))*                   O))) O)) \n"
                << "                                    \n"
                << "\033[0m"
                << "*****Please try again.******\n";
            cout << " +++++++++++++++++++++++++++++Loading+++++++++++++++++++++++++++++++++" << endl;
            Sleep(2700);
            system("cls");
            break;
        }
    } while (option <= 0 || option >= 7);

    system("pause");
    return 0;
}

//cover page function heading
void cover()
{
    cout << "\033[35m";
    cout << "      / $$$$$$  $$    /$$ /$$$$$$  /$$$$$$   \n";
    cout << "     /$$__  $$| $$  / $$|_  $$_/ /$$__  $$  \n";
    cout << "    | $$    $$|  $$/ $$/  | $$  | $$    $$  \n";
    cout << "    | $$$$$$$$    $$$$/   | $$  | $$$$$$$$  \n";
    cout << "    | $$__  $$  >$$  $$   | $$  | $$__  $$  \n";
    cout << "    | $$  | $$ /$$/   $$  | $$  | $$  | $$  \n";
    cout << "    | $$  | $$| $$    $$ /$$$$$$| $$  | $$  \n";
    cout << "    |__/  |__/|__/  |__/|______/|__/  |__/  \n";
    cout << "                                        \n";
    cout << "                                        \n";
    cout << "                                        \n";
    cout << "\033[36m";
    cout << "     / $$$$$$   /$$         | $$ /$$                      \n";
    cout << "    / $$__  $$ |__/         | $$|__/                      \n";
    cout << "    | $$    $$ /$$  /$$$$$$ | $$ /$$ /$$$$$$$   /$$$$$$   \n";
    cout << "    | $$$$$$$$| $$ /$$__  $$| $$| $$| $$__  $$ /$$__  $$  \n";
    cout << "    | $$__  $$| $$| $$  \\__/| $$| $$| $$    $$| $$$$$$$$  \n";
    cout << "    | $$  | $$| $$| $$      | $$| $$| $$  | $$| $$_____/  \n";
    cout << "    | $$  | $$| $$| $$      | $$| $$| $$  | $$|  $$$$$$$  \n";
    cout << "    |__/  |__/|__/|__/      |__/|__/|__/  |__/  _______/  \n";
    cout << "                                                          \n";
    cout << "                                                          \n";
    cout << "       .............Loading..........                     \n";
    cout << "                                                          \n";
    cout << "\033[0m";

    //system("pause");//press enter to enter user main menu
    Sleep(2500); //delay for 2 sec
    system("cls");
}

//adminpage function heading
void adminpage()
{
    int choice;

    FlightDetails flight[maxNumber];
    int no = 0;
    do
    {
        cout << "\033[33m" << endl;
        cout << "   ______   _____    _________  _____  ______     ______   ______   ______   ______    \n";
        cout << "  |*|  |*| |*|  |*| |*| |*| |*|  |*|  |*|  |*|   | |  | | | |  | | | | ____ | |        \n";
        cout << "  |*|__|*| |*|  |*| |*| |*| |*|  |*|  |*|  |*|   | |__|_/ | |__| | | |  | | | |----    \n";
        cout << "  |*|  |*| |_|_/_/  |_| |_| |_| _|_|_ |_|  |_|   |_|      |_|  |_| |_|__|_| |_|____    \n";
        cout << "**************************************************************************************\n\n";
        cout << "\033[0m";
        cout << "     Please select an option:\n";
        cout << "     ==================================\n";
        cout << "     |  #####  ADMIN PAGE MENU   ##### |\n";
        cout << "     ==================================\n";
        cout << "     | Option |         Action         |\n";
        cout << "     ==================================\n";
        cout << "     |   1    |       Add flight       |\n";
        cout << "     |   2    |      Update flight     |\n";
        cout << "     |   3    |      Delete flight     |\n";
        cout << "     |   4    |   Show flight schedule |\n";
        cout << "     |   5    |          Logout        |\n";
        cout << "     ==================================\n\n";



        cout << "Enter your choice: ";
        while (!(cin >> choice)) // to make sure admin input int only but not char or string.
        {
            cout << "\033[31m";
            cout << "\nInvalid input. Please enter an integer: ";
            cout << "\033[0m";
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }
        cin.ignore();
        system("cls");

        switch (choice) {
        case 1:
            cout << "You selected option 1: Add Flight\n";

            // code for adding a flight 
            addFlight(flight, no); //call function of add flight
            cout << "added and save succesfully" << endl;
            system("cls");
            break;
        case 2:
            cout << "You selected option 2: Update Flight\n";
            // code for updating a flight
            editFlight(flight, no); // call function of update flight
            system("cls");
            break;
        case 3:
            cout << "You selected option 3: Delete Flight\n";
            // code for deleting a flight
            deleteFlight(flight, no);
            system("cls");
            break;
        case 4:
            cout << "You selected option 4: Show Flight Schedule\n";
            // code for displaying flights 
            cout << "*******Flight schedule*******\n";
            cout << " \033[35m" << endl;
            cout << " 8888888b  dP oo          dP         dP      .d88888b           dP                      dP          dP          " << endl;
            cout << " 88        88             88         88      88.                88                      88          88          " << endl;
            cout << " 88aaaa    88 dP .d8888b. 88d888b. d8888P    `Y88888b. .d8888b. 88d888b. .d8888b. .d888b88 dP    dP 88 .d8888b. " << endl;
            cout << " 88        88 88 88'  `88 88'  `88   88            `8b 88'      88'  `88 88ooood8 88'  `88 88    88 88 88ooood8 " << endl;
            cout << " 88        88 88 88.  .88 88    88   88      d8'   .8P 88.      88    88 88.  ... 88.  .88 88.  .88 88 88.  ... " << endl;
            cout << " dP        dP dP `8888P88 dP    dP   dP       Y88888P  `88888P' dP    dP `88888P' `88888P8 `88888P' dP `88888P' " << endl;
            cout << "oooooooooooooooooo~~~~.88~oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
            cout << "                  d8888P                                                                                        " << endl;
            cout << " \033[0m";
            displayFlight(flight, no);//call display flight function
            cout << "Press  \033[32m ENTER \033[0m to continue. \n";
            system("pause");
            system("cls");
            break;
        case 5:
            cout << " \033[33m" << endl;
            cout << "   $$\\                                    $$\\                                                 $$\\ " << endl;
            cout << "   $$ |                                   \\__|                                                $$| " << endl;
            cout << "  $$ |      $$$$$$\\   $$$$$$\\   $$$$$$\\  $$\\ $$$$$$$\\   $$$$$$\\         $$$$$$\\  $$\\   $$\\ $$$$$$\\    " << endl;
            cout << "  $$ |     $$  __$$\\ $$  __$$\\ $$  __$$\\ $$ |$$  __$$\\ $$  __$$\\       $$  __$$\\ $$ |  $$ |\\_$$  _|   " << endl;
            cout << "  $$ |     $$ /  $$ |$$ /  $$ |$$ /  $$ |$$ |$$ |  $$ |$$ /  $$ |      $$ /  $$ |$$ |  $$ |  $$ |     " << endl;
            cout << "  $$ |     $$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |$$ |  $$ |$$ |  $$ |      $$ |  $$ |$$ |  $$ |  $$ |$$\\  " << endl;
            cout << "  $$$$$$$$\\\\$$$$$$  |\\$$$$$$$ |\\$$$$$$$ |$$ |$$ |  $$ |\\$$$$$$$ |      \\$$$$$$  |\\$$$$$$  |  \\$$$$  | " << endl;
            cout << "  \\________|\\______/  \\____$$ | \\____$$ |\\__|\\__|  \\__| \\____$$ |       \\______/  \\______/    \\____/  " << endl;
            cout << "                     $$\\   $$ |$$\\   $$ |              $$\\   $$ |                                     " << endl;
            cout << "                     \\$$$$$$  |\\$$$$$$  |              \\$$$$$$  |                                     " << endl;
            cout << "                      \\______/  \\______/                \\______/                                      " << endl;
            cout << " \033[0m" << endl;
            cout << "................................................Logging out....................................\n";
            Sleep(2200);
            system("cls");
            main();
            break;
        default:
            cout << "\033[31m";
            cout << " #### ##    ## ##     ##    ###    ##       #### ######## " << endl;
            cout << "  ##  ###   ## ##     ##   ## ##   ##        ##  ##     ## " << endl;
            cout << "  ##  ####  ## ##     ##  ##   ##  ##        ##  ##     ## " << endl;
            cout << "  ##  ## ## ## ##     ## ##     ## ##        ##  ##     ## " << endl;
            cout << "  ##  ##  ####  ##   ##  ######### ##        ##  ##     ## " << endl;
            cout << "  ##  ##   ###   ## ##   ##     ## ##        ##  ##     ## " << endl;
            cout << " #### ##    ##    ###    ##     ## ######## #### ######## " << endl;
            cout << "\033[0m";
            cout << "Invalid choice. Please try again.\n";
            cout << " +++++++++++++++++++++++++++++Loading+++++++++++++++++++++++++++++++++" << endl;
            Sleep(1200);
            system("cls");
            break;
        }
    } while (choice != 5);

}


//add flight function heading
void addFlight(FlightDetails flight[], int& no)
{
    ofstream outFile("flightDetails.txt", ios::app);
    char choice;
    int noFlight = 0;
    outFile << fixed << setprecision(2);

    //if user want exit
    do
    {
        cout << "Do you want to add flight? (Y/N) : \n";
        while (!(cin >> choice)) // to make sure admin input char only but not int or string.
        {
            cout << "\033[31m";
            cout << "\nInvalid input. Please enter an integer: ";
            cout << "\033[0m";
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }

        cin.ignore();
        if (toupper(choice) == 'N')
        {
            system("cls");
            adminpage();
        }
        if (toupper(choice) != 'Y')
        {
            cout << "\033[31m";
            cout << "\nInvalid input. Try again.\n";
            cout << "\033[0m";
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }
    } while (toupper(choice) != 'Y');
    system("cls");
    cout << "You choose to add flight. Entering the details below...\n" << endl;


    // Check if file exists and has content, and add a newline character at the end of the last line
    ifstream inFile("flightDetails.txt");
    if (inFile.peek() != std::ifstream::traits_type::eof()) {  ///***need to ask whether can use or not
        inFile.seekg(-1, std::ios_base::end);
        char lastChar = ' ';
        inFile.get(lastChar);
        if (lastChar != '\n') {
            outFile << "\n";
        }
    }
    do {
        // prompt user for adding flight details
        cout << "Enter flight number : ";
        getline(cin, flight[noFlight].flightNumber);


        cout << "Enter origin: ";
        getline(cin, flight[noFlight].origin);


        cout << "Enter destination: ";
        getline(cin, flight[noFlight].destination);


        cout << "Enter date (DD/MM/YYYY): ";
        getline(cin, flight[noFlight].date);


        cout << "Enter departure time (HH:MM): ";
        cin >> flight[noFlight].departureTime;


        cout << "Enter arrival time (HH:MM): ";
        cin >> flight[noFlight].arrivalTime;


        cout << "Enter duration (HH:MM): ";
        cin >> flight[noFlight].duration;


        cout << "Enter number of available seats (0-100) : ";
        while ((!(cin >> flight[noFlight].seat)) || (flight[noFlight].seat > 100) || (flight[noFlight].seat < 0))  // to make sure admin input int only but not char or string.
        {
            cout << "\033[31m";
            cout << "\nInvalid input. \033[0m Please enter an integer and in range of (0-100): ";
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }
        writeSeatingChart(flight[noFlight].seat);


        cout << "Enter ticket price : ";
        while (!(cin >> flight[noFlight].price))
        {
            cout << "\033[31m";
            cout << "\nInvalid input. Please enter number: ";
            cout << "\033[0m";
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }

        //write out data to txt file to store it
        outFile << flight[noFlight].flightNumber << endl;
        outFile << flight[noFlight].origin << endl;
        outFile << flight[noFlight].destination << endl;
        outFile << flight[noFlight].date << endl;
        outFile << flight[noFlight].departureTime << endl;
        outFile << flight[noFlight].arrivalTime << endl;
        outFile << flight[noFlight].duration << endl;
        outFile << flight[noFlight].seat << endl;
        outFile << flight[noFlight].price;
        noFlight++;

        do
        {
            cout << "Do you want to key in more? (Y/N) : ";
            while (!(cin >> choice)) // to make sure admin input char only
            {
                cout << "\033[31m";
                cout << "\nInvalid input. Please enter (Y/N): ";
                cout << "\033[0m";
                cin.clear();
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            }
            if (toupper(choice) != 'Y' && toupper(choice) != 'N')
            {
                cout << "\033[31m";
                cout << "Invalid input.\n";
                cout << "\033[0m";
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            }
        } while (toupper(choice) != 'Y' && toupper(choice) != 'N');
        cin.ignore();

        if (toupper(choice) == 'Y')
            outFile << endl;


    } while (toupper(choice) == 'Y');

    if (outFile.fail())
    {
        cout << "\033[31m";
        cout << "Error writing to file." << endl;
        cout << "\033[0m";
    }
    outFile.close();


    cout << " \033[32m Flight details succesfully added.\033[0m" << endl;
    cout << "------------Loading-----------" << endl;
    Sleep(2200);

}

//display flight details function heading
void displayFlight(FlightDetails flight[], int& no)
{
    int noFlight = 0;
    // write file into struct array

    ifstream inFile("flightDetails.txt");
    if (inFile.is_open())
    {
        while (!inFile.eof() && noFlight < maxNumber)
        {
            getline(inFile, flight[noFlight].flightNumber);
            getline(inFile, flight[noFlight].origin);
            getline(inFile, flight[noFlight].destination);
            getline(inFile, flight[noFlight].date);
            getline(inFile, flight[noFlight].departureTime);
            getline(inFile, flight[noFlight].arrivalTime);
            getline(inFile, flight[noFlight].duration);
            inFile >> flight[noFlight].seat;
            inFile >> flight[noFlight].price;
            inFile.ignore();
            noFlight++;

        }
        inFile.close();
    }
    else {
        cout << "\033[31m";
        cout << "Error in opening file.\n";
        cout << "\033[0m";
        return;
    }
    //display flight details
    cout << "Flight details list." << endl;

    // Display table header
    cout << "\033[33m" << setfill('-') << setw(100) << "-" << setfill(' ') << endl;   //for decorasion purpose
    cout << "|" << setw(3) << "No" << "|"
        << setw(10) << "Flight No." << "|"
        << setw(14) << "Origin" << "|"
        << setw(14) << "Destination" << "|"
        << setw(11) << "Date" << "|"
        << setw(9) << "Dep.Time" << "|"
        << setw(9) << "Arr.Time" << "|"
        << setw(9) << "Duration" << "|"
        << setw(5) << "Seat" << "|"
        << setw(6) << "Price" << "|" << endl;
    cout << setfill('-') << setw(100) << "-" << setfill(' ') << "\033[0m" << endl;   //for decorasion purpose

    for (int i = 0; i < noFlight; i++)
    {
        cout << "|" << setw(3) << i + 1 << "|"
            << "\033[36m"
            << setw(10) << flight[i].flightNumber << "\033[0m" << "|"
            << setw(14) << flight[i].origin << "|"
            << setw(14) << flight[i].destination << "|"
            << setw(11) << flight[i].date << "|"
            << setw(9) << flight[i].departureTime << "|"
            << setw(9) << flight[i].arrivalTime << "|"
            << setw(9) << flight[i].duration << "|"
            << setw(5) << flight[i].seat << "|"
            << setw(6) << flight[i].price << "|" << endl;

        cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl; //for decoration purpose
    }

}
//update flight function heading
void editFlight(FlightDetails flight[], int& no)
{
    displayFlight(flight, no);//call display flight function

    cout << "                     _______                  \n";
    cout << "                    |99 back|                  \n";
    cout << "                     -------                  \n";

    int flightIndex; // to know when to perform do..while loop
    int j = -1; //to know when to cout flight not found
    int k = 0; // to know what index to update flight array
    bool flightsearch = 0;

    int noFlight = 0;
    // write file into struct array, for user to choose for update
    ifstream inFile("flightDetails.txt");
    if (inFile.is_open())
    {
        while (!inFile.eof() && noFlight < maxNumber)
        {
            getline(inFile, flight[noFlight].flightNumber);
            getline(inFile, flight[noFlight].origin);
            getline(inFile, flight[noFlight].destination);
            getline(inFile, flight[noFlight].date);
            getline(inFile, flight[noFlight].departureTime);
            getline(inFile, flight[noFlight].arrivalTime);
            getline(inFile, flight[noFlight].duration);
            inFile >> flight[noFlight].seat;
            inFile >> flight[noFlight].price;
            inFile.ignore();
            noFlight++;

        }
        inFile.close();
    }
    else {
        cout << "\033[31m";
        cout << "Error in opening file.\n";
        cout << "\033[0m";
        return;
    }
    //ask user which to update
    do
    {
        cout << "\n Enter the flight index to update: ";
        while (!(cin >> flightIndex)) // to make sure admin input int only but not char or string.
        {
            cout << "\033[31m";
            cout << "\nInvalid input. Please enter an integer: ";
            cout << "\033[0m";
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }
        cin.ignore();
        //Search for the flight details

        for (int i = 0; i < noFlight; i++)
        {
            if (flightIndex == i + 1)
            {
                system("cls");
                flightsearch = 1;
                k = i;
                j = k;
                cout << "\n The flight you choose to edit is " << i + 1 << ". Flight " << flight[i].flightNumber << " . " << endl;
                // Display table header
                cout << "\033[33m" << setfill('-') << setw(100) << "-" << setfill(' ') << endl;   //for decorasion purpose
                cout << "|" << setw(3) << "No" << "|"
                    << setw(10) << "Flight No." << "|"
                    << setw(14) << "Origin" << "|"
                    << setw(14) << "Destination" << "|"
                    << setw(11) << "Date" << "|"
                    << setw(9) << "Dep.Time" << "|"
                    << setw(9) << "Arr.Time" << "|"
                    << setw(9) << "Duration" << "|"
                    << setw(5) << "Seat" << "|"
                    << setw(6) << "Price" << "|" << endl;
                cout << setfill('-') << setw(100) << "-" << setfill(' ') << "\033[0m" << endl;   //for decorasion purpose



                cout << "|" << setw(3) << i + 1 << "|"
                    << setw(10) << "\033[36m" << flight[i].flightNumber << "\033[0m" << "|"
                    << setw(14) << flight[i].origin << "|"
                    << setw(14) << flight[i].destination << "|"
                    << setw(11) << flight[i].date << "|"
                    << setw(9) << flight[i].departureTime << "|"
                    << setw(9) << flight[i].arrivalTime << "|"
                    << setw(9) << flight[i].duration << "|"
                    << setw(5) << flight[i].seat << "|"
                    << setw(6) << flight[i].price << "|" << endl;

                cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl; //for decoration purpose

                break;
            }

        }
        if (flightIndex == 99)
        {
            system("cls");
            adminpage();

        }
        else if (j != k)
        {
            cout << "\033[31m";
            cout << "\nFLight not found...Please try again. \n";
            cout << "\033[0m";
        }

    } while (flightsearch == 0);

    //user key in update selected flight details
    cout << "\n*##Enter the new flight details.*##\n\n";
    cout << "Enter Flight Number : ";
    getline(cin, flight[k].flightNumber);
    cout << "Enter Origin : ";
    getline(cin, flight[k].origin);
    cout << "Enter Destination : ";
    getline(cin, flight[k].destination);
    cout << "Enter Date (DD/MM/YYYY) : ";
    getline(cin, flight[k].date);
    cout << "Enter Departure Time (HH:MM) : ";
    getline(cin, flight[k].departureTime);
    cout << "Enter Arrival Time (HH:MM) : ";
    getline(cin, flight[k].arrivalTime);
    cout << "Enter Duration (HH:MM) : ";
    getline(cin, flight[k].duration);
    cout << "Enter Number of available seats (0-100) : ";
    while ((!(cin >> flight[k].seat)) || (flight[k].seat > 100) || (flight[k].seat < 0))  // to make sure admin input int only but not char or string.
    {
        cout << "\033[31m";
        cout << "\nInvalid input. \033[0m Please enter an integer and in range of (0-100): ";
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    }
    cout << "Enter Ticket Price : ";
    while (!(cin >> flight[k].price))
    {
        cout << "\033[31m";
        cout << "\nInvalid input. Please enter number: ";
        cout << "\033[0m";
        cin.clear();
        cin.ignore();
    }
    cout << "\n\n";

    cout << "\033[32m The flight details succesfully updated...\033[0m";

    //write back updated flight struct array to file.
    ofstream outFile("flightDetails.txt");
    for (int i = 0; i < noFlight; i++)
    {
        outFile << flight[i].flightNumber << endl;
        outFile << flight[i].origin << endl;
        outFile << flight[i].destination << endl;
        outFile << flight[i].date << endl;
        outFile << flight[i].departureTime << endl;
        outFile << flight[i].arrivalTime << endl;
        outFile << flight[i].duration << endl;
        outFile << flight[i].seat << endl;
        outFile << flight[i].price;

        if (i + 1 < noFlight) //when still have details, enter nxt line
            //i+1 because when last details, no need enter nxt line
        {
            outFile << endl;
        }
    }
    cout << "\n ***succefully saved***\n";
    outFile.close();
    Sleep(2200);


}

//delete flight function heading
void deleteFlight(FlightDetails flight[], int& no)
{
    displayFlight(flight, no);//call display flight function


    cout << "   **************       _______                  \n";
    cout << "\033[31m";
    cout << "  [88 delete all]      ";
    cout << "\033[0m";
    cout << "|99 back|                 \n";
    cout << "   **************       -------                  \n";


    int flightIndex; // to know when to perform do..while loop
    int j = -1; //to know when to cout flight not found
    int k = 0; // to know what index to delete flight array
    bool flightsearch = 0;
    char Delete;

    int noFlight = 0;
    // write file into struct array, for user to choose for delete
    ifstream inFile("flightDetails.txt");
    if (inFile.is_open())
    {
        while (!inFile.eof() && noFlight < maxNumber)
        {
            getline(inFile, flight[noFlight].flightNumber);
            getline(inFile, flight[noFlight].origin);
            getline(inFile, flight[noFlight].destination);
            getline(inFile, flight[noFlight].date);
            getline(inFile, flight[noFlight].departureTime);
            getline(inFile, flight[noFlight].arrivalTime);
            getline(inFile, flight[noFlight].duration);
            inFile >> flight[noFlight].seat;
            inFile >> flight[noFlight].price;
            inFile.ignore();
            noFlight++;

        }
        inFile.close();
    }
    else {
        cout << "Error in opening file.\n";
        return;
    }
    //ask user which to delete
    do
    {
        cout << "\n Enter the flight index to delete: ";
        while (!(cin >> flightIndex)) // to make sure admin input int only but not char or string.
        {
            cout << "\033[31m";
            cout << "\nInvalid input. Please enter an integer: ";
            cout << "\033[0m";
            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        }


        if (flightIndex == 99)
        {
            system("cls");
            adminpage();

        }

        if (flightIndex == 88)
        {
            do
            {
                cout << "\033[34m";
                cout << "\n**Do you sure want to delete all?** (Y/N) : ";
                cout << "\033[0m";
                while (!(cin >> Delete)) // to make sure admin input char only
                {
                    cout << "\033[31m";
                    cout << "\nInvalid input. Please enter an (Y/N) : ";
                    cout << "\033[0m";
                    cin.clear();
                    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                }

                if (toupper(Delete) == 'N')
                {
                    cout << "\nyou choose not to delete all... back to admin menu..";
                    Sleep(1000);
                    system("cls");
                    adminpage();

                }
                if (toupper(Delete) != 'Y')
                {
                    cout << "\033[31m";
                    cout << "\nInvalid input. Try again.\n";
                    cout << "\033[0m";
                    cin.clear();
                    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                }
            } while (toupper(Delete) != 'Y');//always loop when Delete !=Y


            // Open the file in truncate mode to overite the opening file
            ofstream outFile("flightDetails.txt", ios::trunc);

            // Check if file is opened
            if (outFile.is_open())
            {


                // Close the file
                outFile.close();
                system("cls");

                // Display a message indicating success
                cout << "____ ,    ,       ____ ,    ___ ____ ,  , ___" << endl;
                cout << "|__| |    |       |___ |     |  | __ |__|  |       " << endl;
                cout << "|  | |___ |___    |    |___ _|_ |__] |  |  |       " << endl;
                cout << "                                                 " << endl;
                cout << "  ,  , ____ ,  , ____    ___  ____ ____ ,  ,     " << endl;
                cout << "  |__| |__| |  | |___    |__] |___ |___ |` |     " << endl;
                cout << "  |  | |  |  `/  |___    |__] |___ |___ | `|     " << endl;
                cout << "                                                 " << endl;
                cout << "                                                                      " << endl;
                cout << "\033[31m" << endl;
                cout << "      eeeeee eeee e     eeee eeeee eeee eeeee                         " << endl;
                cout << "      8    8 8    8     8      8   8    8   8                         " << endl;
                cout << "      8    8 8eee 8e    8eee   8e  8eee 8e  8                         " << endl;
                cout << "      8    8 88   88    88     88  88   88  8                         " << endl;
                cout << "      888ee8 88ee 88eee 88ee   88  88ee 88ee8                         " << endl;
                cout << "\033[32m" << endl;
                cout << "                                                                      " << endl;
                cout << "  888888                                                              " << endl;
                cout << "  8      e   e eeee eeee eeee eeeee eeeee eeee e   e e     e   e    e " << endl;
                cout << "  8eeeee 8   8 8  8 8  8 8    8   8 8   8 8    8   8 8     8   8    8 " << endl;
                cout << "      88 8e  8 8e   8e   8eee 8eeee 8eeee 8eee 8e  8 8e    8e  8eeee8 " << endl;
                cout << "  e   88 88  8 88   88   88      88    88 88   88  8 88    88    88   " << endl;
                cout << "  8eee88 88ee8 88e8 88e8 88ee 8ee88 8ee88 88   88ee8 88eee 88eee 88   " << endl << endl;
                cout << "\033[0m" << endl;
                cout << " +++++++++++++++++++++++++++++Loading+++++++++++++++++++++++++++++++++" << endl;



                cout << "\nAll flights have been deleted...." << endl;
                Sleep(3500);
            }

            else
            {
                // Display an error message if file could not be opened
                cout << "Error in opening file." << endl;
                return;
            }
            system("cls");
            adminpage();

        }



        //Search for the flight details
        for (int i = 0; i < noFlight; i++)
        {
            if (flightIndex == i + 1)
            {
                system("cls");
                flightsearch = 1;
                k = i;
                j = k;
                cout << "\n The flight you choose to delete is " << "\033[34m" << i + 1 << "\033[0m" << ". Flight " << "\033[36m" << flight[i].flightNumber << "\033[0m" << " . " << endl;
                // Display table header

                cout << "\033[33m" << setfill('-') << setw(100) << "-" << setfill(' ') << endl;   //for decorasion purpose
                cout << "|" << setw(3) << "No" << "|"
                    << setw(10) << "Flight No." << "|"
                    << setw(14) << "Origin" << "|"
                    << setw(14) << "Destination" << "|"
                    << setw(11) << "Date" << "|"
                    << setw(9) << "Dep.Time" << "|"
                    << setw(9) << "Arr.Time" << "|"
                    << setw(9) << "Duration" << "|"
                    << setw(5) << "Seat" << "|"
                    << setw(6) << "Price" << "|" << endl;
                cout << setfill('-') << setw(100) << "-" << setfill(' ') << "\033[0m" << endl;   //for decorasion purpose



                cout << "|" << setw(3) << i + 1 << "|"
                    << "\033[36m" << setw(10) << flight[i].flightNumber << "\033[0m" << "|"
                    << setw(14) << flight[i].origin << "|"
                    << setw(14) << flight[i].destination << "|"
                    << setw(11) << flight[i].date << "|"
                    << setw(9) << flight[i].departureTime << "|"
                    << setw(9) << flight[i].arrivalTime << "|"
                    << setw(9) << flight[i].duration << "|"
                    << setw(5) << flight[i].seat << "|"
                    << setw(6) << flight[i].price << "|" << endl;

                cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl; //for decoration purpose

                cout << "\033[31m" << "\nDeleting...." << "\033[34m" << i + 1 << "\033[0m" << ". Flight " << "\033[36m" << flight[i].flightNumber << "\033[0m" << endl << endl;
                cout << "Press  \033[32m ENTER \033[0m to continue. \n";
                system("pause");
                system("cls");

                //to delete,shift the following flight after the selected flight infront 1 number to fill it.
                for (int i = flightIndex - 1; i < noFlight - 1; i++)
                {
                    flight[i] = flight[i + 1];
                }
                break;
            }


        }
        if (j != k)
        {
            cout << "\033[31m" << endl;
            cout << "\nFLight not in list...Please try again. \n";
            cout << "\033[0m" << endl;
        }




    } while (flightsearch == 0);



    //write back new flight struct array to file.
    ofstream outFile("flightDetails.txt");
    for (int i = 0; i < noFlight - 1; i++) //-1 as delete 1 flight
    {
        outFile << flight[i].flightNumber << endl;
        outFile << flight[i].origin << endl;
        outFile << flight[i].destination << endl;
        outFile << flight[i].date << endl;
        outFile << flight[i].departureTime << endl;
        outFile << flight[i].arrivalTime << endl;
        outFile << flight[i].duration << endl;
        outFile << flight[i].seat << endl;
        outFile << flight[i].price;

        if (i + 2 < noFlight) //when still have details, enter nxt line
            //i+2 because when last details, no need enter nxt line
        {
            outFile << endl;
        }
    }
    cout << "\033[32m" << endl;
    cout << "  888888                                                              " << endl;
    cout << "  8      e   e eeee eeee eeee eeeee eeeee eeee e   e e     e   e    e " << endl;
    cout << "  8eeeee 8   8 8  8 8  8 8    8   8 8   8 8    8   8 8     8   8    8 " << endl;
    cout << "      88 8e  8 8e   8e   8eee 8eeee 8eeee 8eee 8e  8 8e    8e  8eeee8 " << endl;
    cout << "  e   88 88  8 88   88   88      88    88 88   88  8 88    88    88   " << endl;
    cout << "  8eee88 88ee8 88e8 88e8 88ee 8ee88 8ee88 88   88ee8 88eee 88eee 88   " << endl;
    cout << "                                                                      " << endl;
    cout << "                                                                      " << endl;
    cout << "\033[31m" << endl;
    cout << "       eeeee eeee e     eeee eeeee eeee eeeee                         " << endl;
    cout << "       8   8 8    8     8      8   8    8   8                         " << endl;
    cout << "       8   8 8eee 8e    8eee   8e  8eee 8e  8                         " << endl;
    cout << "       8   8 88   88    88     88  88   88  8                         " << endl;
    cout << "       88ee8 88ee 88eee 88ee   88  88ee 88ee8                         " << endl << endl;
    cout << "\033[0m" << endl;
    cout << " +++++++++++++++++++++++++++++Loading+++++++++++++++++++++++++++++++++" << endl;

    cout << "\n ***succefully deleted***\n";
    outFile.close();
    Sleep(2200);

}

//use to enter filtering options
void flightmenu() {
    FlightDetails flight[maxNumber];
    int no = 0;
    displayFlight(flight, no);
    string choice;
    cout << "=============================================================\n"
        << "                    Select an option :\n"
        << "                   1. Filter by origin place\n"
        << "                   2. Filter by destination place\n"
        << "                   3. Search for Flight Number\n"
        << "                   4. Back\n"
        << "=============================================================" << endl;
    cout << "Please select an option :";
    cin >> choice;
    cout << endl;
    if (choice == "1") {
        filteroriginFlight(); // choose to filter by origin place name

    }
    else if (choice == "2") {
        filterdestinationFlight();// choose to filter by destination place name
    }
    else if (choice == "3") {
        filterflightnumber();
    }
    else if (choice == "4") {
        system("cls");
        main();
    }
    else {
        system("cls");
        cout << "Invalid choice. Please enter a number Range(1-4).\n";
        flightmenu();

    }
}
//filter flight details by origin place
void filteroriginFlight()
{
    string origin;
    cout << "              N. Back\n";
    cout << "Enter Origin Place(full as shown, exp:kl): ";
    cin >> origin;
    cout << endl;
    if (origin == "N")
    {
        system("cls");
        flightmenu();
    }
    else {
        FlightDetails flight[maxNumber];
        int noFlight = 0;
        ifstream inFile;
        inFile.open("flightDetails.txt");
        if (inFile.is_open())
        {
            while (!inFile.eof() && noFlight < maxNumber)
            {
                getline(inFile, flight[noFlight].flightNumber);
                getline(inFile, flight[noFlight].origin);
                getline(inFile, flight[noFlight].destination);
                getline(inFile, flight[noFlight].date);
                inFile >> flight[noFlight].departureTime;
                inFile >> flight[noFlight].arrivalTime;
                inFile >> flight[noFlight].duration;
                inFile >> flight[noFlight].seat;
                inFile >> flight[noFlight].price;
                inFile.ignore();
                noFlight++;
            }
        }
        else
        {
            cout << "Error in opening file.\n";
            return;

        }
        cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
        cout << "|" << setw(3) << "No" << "|"
            << setw(10) << "Flight No." << "|"
            << setw(14) << "Origin" << "|"
            << setw(14) << "Destination" << "|"
            << setw(11) << "Date" << "|"
            << setw(9) << "Dep.Time" << "|"
            << setw(9) << "Arr.Time" << "|"
            << setw(9) << "Duration" << "|"
            << setw(5) << "Seat" << "|"
            << setw(6) << "Price" << "|" << endl;
        cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
        for (int i = 0; i < noFlight; i++) {
            if (flight[i].origin == origin) {
                cout << "|" << setw(3) << i + 1 << "|"
                    << setw(10) << flight[i].flightNumber << "|"
                    << setw(14) << flight[i].origin << "|"
                    << setw(14) << flight[i].destination << "|"
                    << setw(11) << flight[i].date << "|"
                    << setw(9) << flight[i].departureTime << "|"
                    << setw(9) << flight[i].arrivalTime << "|"
                    << setw(9) << flight[i].duration << "|"
                    << setw(5) << flight[i].seat << "|"
                    << setw(6) << flight[i].price << "|" << endl;

                cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
            }
        }
        inFile.close();
        system("pause");
        system("cls");
        flightmenu();
    }
}
//filter flight details by destination place
void filterdestinationFlight()
{
    string destination;
    cout << "              N. Back\n";
    cout << "Enter Your Destination(full as shown, exp:kl): ";
    cin >> destination;
    cout << endl;
    if (destination == "N")
    {
        system("cls");
        flightmenu();
    }
    else {
        FlightDetails flight[maxNumber];
        int noFlight = 0;
        ifstream inFile;
        inFile.open("flightDetails.txt");
        if (inFile.is_open())
        {
            while (!inFile.eof() && noFlight < maxNumber)
            {
                getline(inFile, flight[noFlight].flightNumber);
                getline(inFile, flight[noFlight].origin);
                getline(inFile, flight[noFlight].destination);
                getline(inFile, flight[noFlight].date);
                inFile >> flight[noFlight].departureTime;
                inFile >> flight[noFlight].arrivalTime;
                inFile >> flight[noFlight].duration;
                inFile >> flight[noFlight].seat;
                inFile >> flight[noFlight].price;
                inFile.ignore();
                noFlight++;
            }
        }
        else
        {
            cout << "Error in opening file.\n";
            return;

        }
        cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
        cout << "|" << setw(3) << "No" << "|"
            << setw(10) << "Flight No." << "|"
            << setw(14) << "Origin" << "|"
            << setw(14) << "Destination" << "|"
            << setw(11) << "Date" << "|"
            << setw(9) << "Dep.Time" << "|"
            << setw(9) << "Arr.Time" << "|"
            << setw(9) << "Duration" << "|"
            << setw(5) << "Seat" << "|"
            << setw(6) << "Price" << "|" << endl;
        cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
        for (int i = 0; i < noFlight; i++) {
            if (flight[i].destination == destination) {
                cout << "|" << setw(3) << i + 1 << "|"
                    << setw(10) << flight[i].flightNumber << "|"
                    << setw(14) << flight[i].origin << "|"
                    << setw(14) << flight[i].destination << "|"
                    << setw(11) << flight[i].date << "|"
                    << setw(9) << flight[i].departureTime << "|"
                    << setw(9) << flight[i].arrivalTime << "|"
                    << setw(9) << flight[i].duration << "|"
                    << setw(5) << flight[i].seat << "|"
                    << setw(6) << flight[i].price << "|" << endl;

                cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
            }
        }
        inFile.close();
        system("pause");
        system("cls");
        flightmenu();
    }
}
//search flight using flight number
void filterflightnumber()
{
    string flightnumber;
    cout << "              N. Back\n";
    cout << "Enter Flight Number(full as shown, exp:A6006): ";
    cin >> flightnumber;
    cout << endl;
    if (flightnumber == "N")
    {
        system("cls");
        flightmenu();
    }
    else {
        FlightDetails flight[maxNumber];
        int noFlight = 0;
        ifstream inFile;
        inFile.open("flightDetails.txt");
        if (inFile.is_open())
        {
            while (!inFile.eof() && noFlight < maxNumber)
            {
                getline(inFile, flight[noFlight].flightNumber);
                getline(inFile, flight[noFlight].origin);
                getline(inFile, flight[noFlight].destination);
                getline(inFile, flight[noFlight].date);
                inFile >> flight[noFlight].departureTime;
                inFile >> flight[noFlight].arrivalTime;
                inFile >> flight[noFlight].duration;
                inFile >> flight[noFlight].seat;
                inFile >> flight[noFlight].price;
                inFile.ignore();
                noFlight++;
            }
        }
        else
        {
            cout << "Error in opening file.\n";
            return;

        }
        cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
        cout << "|" << setw(3) << "No" << "|"
            << setw(10) << "Flight No." << "|"
            << setw(14) << "Origin" << "|"
            << setw(14) << "Destination" << "|"
            << setw(11) << "Date" << "|"
            << setw(9) << "Dep.Time" << "|"
            << setw(9) << "Arr.Time" << "|"
            << setw(9) << "Duration" << "|"
            << setw(5) << "Seat" << "|"
            << setw(6) << "Price" << "|" << endl;
        cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
        for (int i = 0; i < noFlight; i++) {
            if (flight[i].flightNumber == flightnumber) {
                cout << "|" << setw(3) << i + 1 << "|"
                    << setw(10) << flight[i].flightNumber << "|"
                    << setw(14) << flight[i].origin << "|"
                    << setw(14) << flight[i].destination << "|"
                    << setw(11) << flight[i].date << "|"
                    << setw(9) << flight[i].departureTime << "|"
                    << setw(9) << flight[i].arrivalTime << "|"
                    << setw(9) << flight[i].duration << "|"
                    << setw(5) << flight[i].seat << "|"
                    << setw(6) << flight[i].price << "|" << endl;

                cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
            }
        }
        inFile.close();
        system("pause");
        system("cls");
        flightmenu();
    }
}
//Function to select and reserve a seat
void bookflight()
{
    FlightDetails flight[maxNumber];
    int no = 0;
    displayFlight(flight, no);
    int noFlight = 0;
    ifstream inFile;
    inFile.open("flightDetails.txt");
    {if (inFile.is_open())
    {
        while (!inFile.eof() && noFlight < maxNumber)
        {
            getline(inFile, flight[noFlight].flightNumber);
            getline(inFile, flight[noFlight].origin);
            getline(inFile, flight[noFlight].destination);
            getline(inFile, flight[noFlight].date);
            inFile >> flight[noFlight].departureTime;
            inFile >> flight[noFlight].arrivalTime;
            inFile >> flight[noFlight].duration;
            inFile >> flight[noFlight].seat;
            inFile >> flight[noFlight].price;
            inFile.ignore();
            noFlight++;
        }
    }
    else {
        cout << "Unable to open flightDetails.txt file" << endl;
    }
    }
    inFile.close();
    cout << "Please select flight number :";
    cin >> no;
    cout << endl;
    int i = no - 1; //the 1. of flight details shown was stored in array[0], so -1 to get the exact array of the flightdetails.
    char response;
    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
    cout << "|" << setw(3) << "No" << "|"
        << setw(10) << "Flight No." << "|"
        << setw(14) << "Origin" << "|"
        << setw(14) << "Destination" << "|"
        << setw(11) << "Date" << "|"
        << setw(9) << "Dep.Time" << "|"
        << setw(9) << "Arr.Time" << "|"
        << setw(9) << "Duration" << "|"
        << setw(5) << "Seat" << "|"
        << setw(6) << "Price" << "|" << endl;
    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
    cout << "|" << setw(3) << i + 1 << "|"
        << setw(10) << flight[i].flightNumber << "|"
        << setw(14) << flight[i].origin << "|"
        << setw(14) << flight[i].destination << "|"
        << setw(11) << flight[i].date << "|"
        << setw(9) << flight[i].departureTime << "|"
        << setw(9) << flight[i].arrivalTime << "|"
        << setw(9) << flight[i].duration << "|"
        << setw(5) << flight[i].seat << "|"
        << setw(6) << flight[i].price << "|" << endl;

    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
    cout << "Do you wish to book this flight ? (Y/N): ";
    cin >> response;
    if (toupper(response) == 'Y') {
        do {
            // Read the seats array from the file
            ifstream inFile(filename[i]);
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLUMNS; j++) {
                    inFile >> seats[i][j];

                }
            }
            // Display Available Seats for selected flight
            cout << "Seating Chart:" << endl;
            for (int j = 0; j < COLUMNS; j++) {
                cout << "\t" << j;
            }
            cout << endl;
            for (int i = 0; i < ROWS; i++) {
                cout << i;
                for (int j = 0; j < COLUMNS; j++) {
                    cout << "\t|" << seats[i][j] << "| ";
                }
                cout << endl;
            }
            // Close the file
            inFile.close();
            //call function to read available seats for this flight
            readSeatingChart(i, totalseat);
            int row, col;
            cout << "Please Select Your Seat ~\n";
            cout << " O = empty seat" << endl;
            cout << " X = occupied seat" << endl;
            cout << "---------------------------------------------\n";

            bool ok = false;
            do {
                cout << "Row   : ";
                cin >> row;
                cout << endl;
                cout << "Column: ";
                cin >> col;
                cout << endl;
                if (row > 24)
                    cout << "Please reenter your ROW " << endl;
                else if (col > 3)
                    cout << "Please reenter your COLUMN" << endl;
                else if (seats[row][col] == 'X') // X means seat is occupied
                {
                    cout << "the seat is occupied, Please try again...." << endl;
                }
                else if (row <= 24 && col <= 3 && seats[row][col] == 'O') //if the seats is available and not out of range
                {
                    ok = true;
                }
            } while (ok != true);
            char proceed;
            do {
                cout << "Procced to payment? (Y/N):" << endl;
                cin >> proceed;
                if (toupper(proceed) != 'Y' && toupper(proceed) != 'N') {
                    cout << "Error input please try again" << endl;
                }
                else {
                    cout << "Proceeding..." << endl;
                }
            } while (toupper(proceed) != 'Y' && toupper(proceed) != 'N');
            if (toupper(proceed) == 'Y')
            {
                cout << "The price for this seat : " << flight[i].price << endl;
                paymentpage(i,row,col);
                flight[i].seat--; //Once payment is done, total seats will be reduce by 1
                
                system("cls");
                cout << "Payment is Completed!!!Thanks You Very Much!!!" << endl;
                cout << "\nYour seat is " << row << "-" << col << endl;

                seats[row][col] = 'X'; // change char of the seat reserved to 'X'
                ofstream outFile(filename[i]);// rewrite the char of each seat of the flight
                for (int i = 0; i < ROWS; i++) {
                    for (int j = 0; j < COLUMNS; j++) {
                        outFile << seats[i][j] << " ";
                    }
                    outFile << endl;
                }
                outFile.close();
            }
            ofstream outFile("flightDetails.txt"); // update the total seats of the flight details
            for (int i = 0; i < noFlight; i++)
            {
                outFile << flight[i].flightNumber << endl;
                outFile << flight[i].origin << endl;
                outFile << flight[i].destination << endl;
                outFile << flight[i].date << endl;
                outFile << flight[i].departureTime << endl;
                outFile << flight[i].arrivalTime << endl;
                outFile << flight[i].duration << endl;
                outFile << flight[i].seat << endl;
                outFile << flight[i].price;

                if (i + 1 < noFlight) //when still have details, enter nxt line
                    //i+1 because when last details, no need enter nxt line
                {
                    outFile << endl;
                }
            }
            outFile.close();
            
            cout << endl;
            do {
                cout << "Do you wish to book another seat?(Y/N) " << endl;
                cin >> response;
                if (toupper(response) != 'Y' && toupper(response) != 'N') {
                    cout << "Error input please try again" << endl;
                }
                else {
                    cout << "Proceeding..." << endl;
                }
            } while (toupper(response) != 'Y'&& toupper(response) != 'N');
            system("cls");
        } while (toupper(response) == 'Y');
        cout << "Heading Back to Main Menu...." << endl;
        Sleep(2000);
        system("cls");
        main();
    }
    else
        system("cls");
    bookflight();

}
//read available seats from the seat chart
void readSeatingChart(int i, int& totalseat) {
    totalseat = 0;
    i = i + 1;// i had been -1 to select the correct array before, add back +1 to select number of file 
    char ACI = 'O'; // use to check if it match char of seat[ROWS][COLUMNS]
    // Select the filename for the input file
    string filename = "flight" + to_string(i) + ".txt";// select file according to name exp:flight1.txt,flight2.txt
    ifstream inFile(filename);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            inFile >> seats[i][j];
            if (static_cast<int>(seats[i][j]) == static_cast<int>(ACI))// if value of seats match '0', it means available
            {
                totalseat++;
            }
        }
    }

    cout << "Total available Seats are " << totalseat << endl;
    //close the file
    inFile.close();

}
//creat seat chart to store available seats inside txt
void writeSeatingChart(int x) {
    FlightDetails flight[40];
    ifstream inFile("flightDetails.txt");
    int flightNum = 0;
    if (inFile.is_open())
    {
        while (!inFile.eof() && flightNum < maxNumber)
        {
            getline(inFile, flight[flightNum].flightNumber);
            getline(inFile, flight[flightNum].origin);
            getline(inFile, flight[flightNum].destination);
            getline(inFile, flight[flightNum].date);
            getline(inFile, flight[flightNum].departureTime);
            getline(inFile, flight[flightNum].arrivalTime);
            getline(inFile, flight[flightNum].duration);
            inFile >> flight[flightNum].seat;
            inFile >> flight[flightNum].price;
            inFile.ignore();
            flightNum++;

        }
        inFile.close();
    }
    // Create the filename for the output file
    string filename = "flight" + to_string(flightNum) + ".txt";
    ofstream outFile(filename);
    int count = 0;
    int totalseat = 0;
    // Write the seats array to the file
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            {
                if (count < x) {
                    seats[i][j] = 'O';
                    totalseat++;
                }
                else {
                    seats[i][j] = 'X';
                }
            }
            outFile << seats[i][j] << " ";
            count++;
        }
        outFile << endl;
    }
    cout << "Total seats are " << totalseat << endl;
    // Close the file
    outFile.close();
}

//Payment page of payment method function
void paymentpage(int i,int row,int col) {
    string customername;
    string choice;
    cout << "====================================================\n"
        << "=                                                  =\n"
        << "=  Please choose your preferred payment method:    =\n"
        << "=             1. Online Banking                    =\n"
        << "=             2. Tounch 'n Go                      =\n"
        << "=             3. Credit/Debit Card                 =\n"
        << "=             4. Google Pay                        =\n"
        << "=             5. Back                              =\n"
        << "=                                                  =\n"
        << "====================================================\n"
        << endl;
    do {
        cout << "Enter number range 1-5 :";
        cin >> choice;
        cin.ignore();
        cout << endl;
        if (choice == "5") {
            system("cls");
            bookflight();
        }
        else {

        }
    } while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5");
    system("cls");
    cout << "Please enter your name: ";
    getline(cin, customername);
    cin.ignore();
    cout << "Proceeding Transaction...... Please wait for a while" << endl;
    Sleep(2000);
    system("cls");
    string captcha;
    string captchapass = "ACDL";
    cout << "===============================================" << endl;
    cout << " / $$$$$$   / $$$$$$  / $$$$$$$  / $$" << endl;
    cout << "/ $$__  $$ / $$__  $$ | $$__  $$ | $$" << endl;
    cout << "| $$  | $$ | $$  |__/ | $$  | $$ | $$      " << endl;
    cout << "| $$$$$$$$ | $$       | $$  | $$ | $$      " << endl;
    cout << "| $$__  $$ | $$       | $$  | $$ | $$      " << endl;
    cout << "| $$  | $$ | $$    $$ | $$  | $$ | $$      " << endl;
    cout << "| $$  | $$ |  $$$$$$/ | $$$$$$$/ | $$$$$$$$" << endl;
    cout << "|__/  |__/  |______/  |_______/  |________/" << endl;
    cout << "===============================================" << endl;
    cout << "                 7. Back                        " << endl;
    do {
        cout << "\nPlease enter captcha above:";
        cin >> captcha;
        if (captcha == "7") {
            system("cls");
            paymentpage(i, row, col);
        }
        else if (captcha == captchapass)
        {
            cout << "Correct" << endl;
        }
        else {
            cout << "Please enter it in UPPERCASE" << endl;
        }
    } while (captcha != captchapass);
    
    system("cls");
   

    FlightDetails flight[maxNumber];
    int noFlight = 0;
    ifstream inFile("flightDetails.txt");
    if (inFile.is_open())
    {
        while (!inFile.eof() && noFlight < maxNumber)
        {
            getline(inFile, flight[noFlight].flightNumber);
            getline(inFile, flight[noFlight].origin);
            getline(inFile, flight[noFlight].destination);
            getline(inFile, flight[noFlight].date);
            getline(inFile, flight[noFlight].departureTime);
            getline(inFile, flight[noFlight].arrivalTime);
            getline(inFile, flight[noFlight].duration);
            inFile >> flight[noFlight].seat;
            inFile >> flight[noFlight].price;
            inFile.ignore();
            noFlight++;

        }
       
    }
    else {
        cout << "file not exist" << endl;
    }
    inFile.close();
    
    ofstream outFile;
    outFile.open("custumer_reserve.txt", ios::app);

    {
        outFile <<"\n"<< customername << endl;
        outFile << flight[i].flightNumber << endl;
        outFile << flight[i].origin << endl;
        outFile << flight[i].destination << endl;
        outFile << flight[i].date << endl;
        outFile << flight[i].departureTime << endl;
        outFile << flight[i].arrivalTime << endl;
        outFile << flight[i].duration << endl;
        outFile << row << "-" << col << endl;
        outFile << flight[i].price;
    }
   
    
    outFile.close();
}

void reservationmenu()
{
    int reserve = 0;
    string choice;
    cout << "====================================================\n"
        << "=                                                  =\n"
        << "=          What do you want to reserve             =\n"
        << "=             1. Custumer Purchase Detail          =\n"
        << "=             2. AXIA BAR                          =\n"
        << "=             3. Back                              =\n"
        << "=                                                  =\n"
        << "====================================================\n"
        << endl;

    cout << "Enter number range 1-3 :";
    cin >> choice;
    cout << endl;
    if (choice == "3")
    {
        system("cls");
        main();
    }
    else if (choice == "1")
    {
        cout << "*******Please Wait A Moment******** ";
        Sleep(2000);
        system("cls");

        custumerReserve();
    }
    else if (choice == "2")
    {
        Sleep(2000);
        system("cls");
        cout << "*******Please Be Patient,You Will Be Shocked******** ";
        Sleep(3500);
        system("cls");
        specialrequest();

    }
    else if (choice == "3")
    {
        cout << "*******Please Wait A Moment******** ";
        Sleep(2000);
        system("cls");

    }
    else
    {
        system("cls");
        cout << "Invalid Option.Please re-enter." << endl;
        Sleep(2000);
        system("cls");
        custumerReserve();
    }
}
//reservation menu heading
void custumerReserve()
{
    cout << "Dear customer ,here is your reservation\n" << endl;
    ifstream inFile;
    string customername, flightNum, origin, destination, date, departureTime, arrivalTime, duration, seat, price;
    inFile.open("custumer_reserve.txt");
    {
        while (!inFile.eof())
        {
            getline(inFile, customername);
            getline(inFile, flightNum);
            getline(inFile, origin);
            getline(inFile, destination);
            getline(inFile, date);
            getline(inFile, departureTime);
            getline(inFile, arrivalTime);
            getline(inFile, duration);
            getline(inFile, seat);
            getline(inFile, price);


            cout << "==========================" << endl;
            cout << "||   Customer name    : " << customername << endl;
            cout << "||  1. flight Number  : " << flightNum << endl;
            cout << "||  2. origin         : " << origin << endl;
            cout << "||  3. destination    : " << destination << endl;
            cout << "||  4. date           : " << date << endl;
            cout << "||  5. depature time  : " << departureTime << endl;
            cout << "||  6. arrival time   : " << arrivalTime << endl;
            cout << "||  7. duration       : " << duration << endl;
            cout << "||  8. seat           : " << seat << endl;
            cout << "||  9. price          : " << price << endl;
            cout << "==========================" << endl;

        }
    }
    inFile.close();
    system("pause");
    system("cls");
    main();

}
//custumer reserve heading
void cancelreservation()
{
    int flightCancel = 0;
    bool flight;
    bool flightsearch;
    char Delete;



    int noFlight = 0;
    ifstream inFile;
    string customername, flightNum, origin, destination, date, departureTime, arrivalTime, duration, seat, price;
    inFile.open("custumer_reserve.txt");
    {
        while (!inFile.eof())
        {
            getline(inFile, customername);
            getline(inFile, flightNum);
            getline(inFile, origin);
            getline(inFile, destination);
            getline(inFile, date);
            getline(inFile, departureTime);
            getline(inFile, arrivalTime);
            getline(inFile, duration);
            getline(inFile, seat);
            getline(inFile, price);


            cout << "==========================" << endl;
            cout << "||   Customer name    : " << customername << endl;
            cout << "||  1. flight Number  : " << flightNum << endl;
            cout << "||  2. origin         : " << origin << endl;
            cout << "||  3. destination    : " << destination << endl;
            cout << "||  4. date           : " << date << endl;
            cout << "||  5. depature time  : " << departureTime << endl;
            cout << "||  6. arrival time   : " << arrivalTime << endl;
            cout << "||  7. duration       : " << duration << endl;
            cout << "||  8. seat           : " << seat << endl;
            cout << "||  9. price          : " << price << endl;
            cout << "==========================" << endl;

        }
    }
    inFile.close();


    cout << "*********************************" << endl;
    cout << "\033[31m";
    cout << " Cancel all flight(Y=99) " << endl;
    cout << "\033[0m";
    cout << "*********************************" << endl;
    cout << "|100 back|                 \n";
    cout << "*********************************" << endl;
    cin >> flightCancel;

    if (flightCancel == 100)
    {
        system("cls");
        main();
    }
    if (flightCancel == 99)
    {
        do
        {
            cout << "\033[34m";
            cout << "\n**Do you sure want to cancel all?** (Y/N) : ";
            cout << "\033[0m";
            while (!(cin >> Delete))
            {
                cout << "\033[31m";
                cout << "\nInvalid input. Please enter an (Y/N) : ";
                cout << "\033[0m";
                cin.clear();
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            }

            if (toupper(Delete) == 'N')
            {
                cout << "\nyou choose not to delete all... So,let's back to main menu..";
                Sleep(2000);
                system("cls");
                main();

            }
            if (toupper(Delete) != 'Y')
            {
                cout << "\033[31m";
                cout << "\nInvalid input. Try again.\n";
                cout << "\033[0m";
                cin.clear();
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
            }
        } while (toupper(Delete) != 'Y');



        ofstream outFile("custumer_reserve", ios::trunc);


        if (outFile.is_open())
        {
            outFile.close();
            system("cls");

            cout << "\nAll flights have been deleted...." << endl;
            Sleep(3500);
        }

        else
        {

            cout << "Error in opening file." << endl;
            return;
        }


        system("cls");
        main();
    }
    system("pause");
    system("cls");
    main();
}
//cancel reservation heading


void specialrequest()
{
    char choice, payment;
    double  a, b, c, d, e;
    double totalPrice = 0;
    char y;
    bool cont = true;

    cout << "\033[32m" << endl;
    cout << " RRRRRR  RR       RR  RR   RRRRRR         RRRRRRRR    RRRRRR   RRRRRRRR  " << endl;
    cout << "RR    RR   RR  RR     RR  RR    RR        RR     RR  RR    RR  RR     RR " << endl;
    cout << "RRRRRRRR     RR       RR  RRRRRRRR        RRRRRRRRR  RRRRRRRR  RRRRRRRR  " << endl;
    cout << "RR    RR   RR  RR     RR  RR    RR        RR     RR  RR    RR  RR  RR    " << endl;
    cout << "RR    RR RR      RR   RR  RR    RR        RRRRRRRR   RR    RR  RR    RR  " << endl;
    cout << " \033[0m" << endl;
    cout << "=========================================================================\n" << endl;
    cout << "                                                                         \n" << endl;
    cout << "\033[35m";
    cout << "******** Welcome TO AXIA BAR ********";
    cout << "  \n" << endl;
    cout << "  \n" << endl;
    cout << "============================================" << endl;
    cout << "|| A. hamburger + cola        || RM5.00   ||" << endl;
    cout << "|| B. chickenchop + lemon tea || RM7.00   ||" << endl;
    cout << "|| C. chips + sprite          || RM2.50   ||" << endl;
    cout << "|| D. popcorn + revive        || RM3.50   ||" << endl;
    cout << "============================================" << endl;
    cout << "   \n" << endl;
    do
    {
        cout << "\033[0m" << endl;
        cout << "Please choose your set meal (A,B,C,D)" << endl;
        cin >> choice;
        if (choice == 'a')
        {
            a = 5.00;
            totalPrice += a;
        }
        else if (choice == 'b')
        {
            b = 7.00;
            totalPrice += b;
        }
        else if (choice == 'c')
        {
            c = 2.50;
            totalPrice += c;
        }
        else if (choice == 'd')
        {
            d = 3.50;
            totalPrice += d;
        }
        cout << "Do you want to continue to purchase(Y/N)??" << endl;
        cin >> y;
        if (toupper(y) == 'Y')
        {
            cont = true;
        }
        else
        {
            cont = false;
        }
    } while (cont);
    cout << fixed << setprecision(2);
    cout << "Dear custumer,total purchase is RM " << totalPrice << endl;



    cout << "====================================================\n"
        << "=                                                  =\n"
        << "=  Please choose your preferred payment method:    =\n"
        << "=             1. Online Banking                    =\n"
        << "=             2. Tounch 'n Go                      =\n"
        << "=             3. Credit/Debit Card                 =\n"
        << "=             4. Google Pay                        =\n"
        << "=             5. Back                              =\n"
        << "=                                                  =\n"
        << "====================================================\n"
        << endl;
    cout << "Enter number range 1-5 :";
    cin >> payment;
    cout << endl;
    if (payment == 5) {
        system("cls");
        reservationmenu;
    }
    else {
        cout << "Payment in Process ...... Please wait for a while" << endl;
        Sleep(2000);
        system("cls");
        cout << "Paid sucessful ...... Back To Main Menu" << endl;
        system("cls");
        Sleep(2000);
        system("cls");

        main();
    }
    system("cls");
    main();
}
//special request heading
