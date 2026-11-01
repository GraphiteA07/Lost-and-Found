//STATUS: Added Lost Item Details.

#include <iostream>
#include <string>
#include <conio.h>
#include <unistd.h>
using namespace std;


void welcome_animate(); 
void welcome();
void directing(); 
void display_missing_inputs(struct Details *p);
bool is_blank(struct Details *p);

unsigned int DELAY = 60000;   /*41900*/
bool is_lost_active = false;
/* unsigned const int MIN_LEN = 11; */
/* unsigned const int MAX_LEN = 40; */

struct Details {
    string Name;
    string ID;
    string Category;
    string Item_Name;
    string Brand_Name;
    string Item_Color;
    string Unique_ID;
    string Last_Seen_Location;
    string Date_Time;
};

enum {
    LOST_ITEM   = '1',
    FOUND_ITEM  = '2',
    SEARCH_ITEM = '3',
    EXIT        = '4',
};


int main() {

    struct Details person;

    int menu_option;
    bool is_first_launch = false;

    system("cls");
    cout << "\n\n";
    cout << "  Lost and Found Smart Campus" << endl;
    cout << "--------------------------------------------";
    cout << "\n\n\n";

    cout << "   Enter Name \n\n > ";
    getline(cin, person.Name);

    if (person.Name.empty()) {
        cout << endl << " Error: No input found" << endl;
        return 0;
    }

    cout << "\n\n";

    cout << "   Enter ID \n\n > ";
    getline(cin, person.ID);

    while (person.ID.length() < 8) {

    if (person.ID.empty() || person.ID.length() < 8) {
        cout << endl << " Error: Invalid ID.Please try again" << endl << endl;
        cout << " Enter ID: ";
        getline(cin, person.ID);
    }
    }//end of while()


    directing();

    do { //Main loop

        do { //Menu loop

            system("cls");

            if (is_first_launch) {
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
                cout << "----------------------------------" << endl << endl << endl;



                if (!is_lost_active) {

                cout << "  For Example: [Electronics | Documents | Apparel | Valuables | Other]" << endl << endl; 
                cout << "  Enter Item Category: ";
                getline(cin, person.Category);
                cout << endl << "  Enter Item Name: ";
                getline(cin, person.Item_Name);
                cout << endl << "  Enter Brand Name: ";
                getline(cin, person.Brand_Name);
                cout << endl << "  Enter Color: ";
                getline(cin, person.Item_Color);
                cout << endl << "  For Example: [Serial # | Stickers | dents | Custom marks | Other]" << endl; 
                cout << endl << "  Enter Unique Identifiers: ";
                getline(cin, person.Unique_ID);
                cout << endl << "  Enter Last Seen Location: ";
                getline(cin, person.Last_Seen_Location);
                cout << endl << "  Enter Date and Time (DD-MM-YYYY HH:MM AM/PM): ";
                getline(cin, person.Date_Time);

                is_lost_active = true;
                }

                else {
                    display_missing_inputs(&person);

                    if (!is_blank(&person)) {
                        cout << endl <<  "  All details are provided.";
                    }
                }

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
        is_first_launch = true;
         

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

bool is_blank(struct Details *p) {

    if(p->Category.empty() || p->Item_Name.empty() || p->Brand_Name.empty() ||
       p->Item_Color.empty() || p->Unique_ID.empty() || p->Last_Seen_Location.empty() ||
       p->Date_Time.empty()) {
        return true;
    }

    else {
        return false;
    }
}

void display_missing_inputs(struct Details *p) {

    if (is_lost_active) {

        if (p->Category.empty()) {
                cout << "  For Example: [Electronics | Documents | Apparel | Valuables | Other]" << endl << endl; 
                cout << "  Enter Item Category: ";
                getline(cin, p->Category);
        }

         if (p->Item_Name.empty()) {
                cout << endl << "  Enter Item Name: ";
                getline(cin, p->Item_Name);
        }

         if (p->Brand_Name.empty()) {
                cout << endl << "  Enter Brand Name: ";
                getline(cin, p->Brand_Name);
        }

         if(p->Item_Color.empty()) {
                cout << endl << "  Enter Color: ";
                getline(cin, p->Item_Color);
        }

         if (p->Unique_ID.empty()) {
                cout << endl << "  For Example: [Serial # | Stickers | dents | Custom marks | Other]" << endl; 
                cout << endl << "  Enter Unique Identifiers: ";
                getline(cin, p->Unique_ID);
        }

         if (p->Last_Seen_Location.empty()) {
                cout << endl << "  Enter Last Seen Location: ";
                getline(cin, p->Last_Seen_Location);
        }

         if (p->Date_Time.empty()) {
                cout << endl << "  Enter Date and Time (DD-MM-YYYY HH:MM AM/PM): ";
                getline(cin, p->Date_Time);
        }
    }//end of outer if()
}
