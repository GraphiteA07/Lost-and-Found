//STATUS: Working

#include <iostream>
#include <conio.h>
#include <unistd.h>
using namespace std;


void welcome_animate(); 
void welcome();
void directing(); 

unsigned int DELAY = 60000;   /*41900*/
const int MAX_LEN = 30;
const int MIN_LEN = 11;

/* struct UserDetails { */
/*     char Name[MIN_LEN]; */
/*     char ID[MIN_LEN]; */
/* }; */

enum {
    LOST_ITEM   = '1',
    FOUND_ITEM  = '2',
    SEARCH_ITEM = '3',
    EXIT        = '4',
};


int main() {

    char user_name[MAX_LEN];
    char user_ID[MAX_LEN];
    int menu_option;
    int first_launch;

    system("cls");
    cout << "\n\n";
    cout << "  Lost and Found Smart Campus" << endl;
    cout << "--------------------------------------------";
    cout << "\n\n\n";

    cout << "   Enter Name \n\n > ";
    cin.getline(user_name, sizeof(user_name));

    if (user_name[0] == '\0') {
        cout << endl << " Error: No input found" << endl;
        return 0;
    }

    cout << "\n\n";
    cout << "   Enter ID \n\n > ";
    cin.getline(user_ID, sizeof(user_ID));

    if (user_ID[0] == '\0') {
        cout << endl << " Error: No input found" << endl;
        return 0;
    }

    directing();

    do { //Main loop

        do { //Menu loop

            system("cls");

            if (first_launch == 1) {
                welcome();
            }

            else{
                welcome_animate();
            }

            cout << "\n\n\n\n";
            cout << "\t\t  [1] Report Lost Item" << endl << endl;
            cout << "\t\t  [2] Report Found Item" << endl << endl;
            cout << "\t\t  [3] Search Items" << endl << endl;
            cout << "\t\t  [4] Exit" << endl << endl;

            cout << endl << "\t\t  Enter option : ";
            menu_option = getche();

            if (menu_option == EXIT) {
                cout << endl << endl << endl << " Exited successfully...";
                return 0;
            }

            if (menu_option == LOST_ITEM || menu_option == FOUND_ITEM || menu_option == SEARCH_ITEM) {
                break;
            }

        }while (menu_option != LOST_ITEM && menu_option != FOUND_ITEM && menu_option != SEARCH_ITEM && menu_option != EXIT);

        system("cls");

        switch (menu_option) {

            case LOST_ITEM:
                cout << endl << endl << "  Report Lost Item" << endl;
                cout << "----------------------------------";
                break;

            case FOUND_ITEM:
                cout << endl << endl << "  Report Found Item" << endl;
                cout << "----------------------------------";
                break;

            case SEARCH_ITEM:
                cout << endl << endl << "  Search Item" << endl;
                cout << "----------------------------------";
                break;


        }//end of switch
         
        cout << endl << endl << "  Press any key... ";
        (void)getch();
        first_launch = 1;
         

    }while (1);

    return 0;

}//end of main()


void welcome_animate() {

    cout << endl << endl;
    cout << "   db   d8b   db d88888b db       .o88b.  .d88b.  .88b  d88. d88888b\n";
    usleep(DELAY);
    cout << "   88   I8I   88 88'     88      d8P  Y8 .8P  Y8. 88'YbdP`88 88'     \n";
    usleep(DELAY);
    cout << "   88   I8I   88 88ooooo 88      8P      88    88 88  88  88 88ooooo \n";
    usleep(DELAY);
    cout << "   Y8   I8I   88 88~~~~~ 88      8b      88    88 88  88  88 88~~~~~ \n";
    usleep(DELAY);
    cout << "   `8b d8'8b d8' 88.     88booo. Y8b  d8 `8b  d8' 88  88  88 88.     \n";
    usleep(DELAY);
    cout << "    `8b8' `8d8'  Y88888P Y88888P  `Y88P'  `Y88P'  YP  YP  YP Y88888P \n";
    /* printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n"); */
} 

void welcome() {

    cout << endl << endl;
    cout << "   db   d8b   db d88888b db       .o88b.  .d88b.  .88b  d88. d88888b\n";
    cout << "   88   I8I   88 88'     88      d8P  Y8 .8P  Y8. 88'YbdP`88 88'     \n";
    cout << "   88   I8I   88 88ooooo 88      8P      88    88 88  88  88 88ooooo \n";
    cout << "   Y8   I8I   88 88~~~~~ 88      8b      88    88 88  88  88 88~~~~~ \n";
    cout << "   `8b d8'8b d8' 88.     88booo. Y8b  d8 `8b  d8' 88  88  88 88.     \n";
    cout << "    `8b8' `8d8'  Y88888P Y88888P  `Y88P'  `Y88P'  YP  YP  YP Y88888P \n";
    /* printf("\n -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n"); */
} 




void directing() {

    cout << "\n\n  Directing";
    usleep(95000); 
    cout << ".";
    usleep(95000); 
    cout << ".";
    usleep(95000); 
    cout << ".";
    usleep(99999); 
    cout << "\n";
} 

