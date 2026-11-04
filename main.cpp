//STATUS: Added Display Details option.

#include <iostream>
#include <string>
#include <conio.h>
#include <unistd.h>
using namespace std;


void directing(); 
void lost_and_found();
void lost_and_found_animate(); 
void display_LI_inputs(struct Details *LI_person);
void display_FI_inputs(struct Details *FI_person);
bool is_LI_input_blank(struct Details *LI_person);
bool is_FI_input_blank(struct Details *FI_person);

unsigned int DELAY = 60000;   /*41900*/
/* bool is_lost_active = false; */
/* bool is_found_active = false; */

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
    string Contact_Info;
    
};

enum {
    LOST_ITEM          = '1',
    FOUND_ITEM         = '2',
    SEARCH_ITEM        = '3',
    DISPLAY_DETAILS    = '4',
    EXIT               = '5',
};

    struct Details LI_person;
    struct Details FI_person;

int main() {


    int menu_option;
    int display_details_option;
    bool is_first_launch = false;

    system("cls");
    cout << "\n\n";
    cout << "  Lost and Found Smart Campus" << endl;
    cout << "--------------------------------------------";
    cout << "\n\n\n";

    cout << "   Enter Name \n\n > ";
    getline(cin, LI_person.Name);


    if (LI_person.Name.empty()) {
        cout << endl << " Error: No input found" << endl;
        return 0;
    }

    cout << "\n\n";

    cout << "   Enter ID \n\n > ";
    getline(cin, LI_person.ID);

    while (LI_person.ID.length() < 8) {

    if (LI_person.ID.empty() || LI_person.ID.length() < 8) {
        cout << endl << " Error: Invalid ID.Please try again" << endl << endl;
        cout << " Enter ID: ";
        getline(cin, LI_person.ID);
    }
    }//end of while()
     
    FI_person.Name = LI_person.Name;
    FI_person.ID   = LI_person.ID;
     
     


    directing();

    do { //Main loop

        do { //Menu loop

            system("cls");

            if (is_first_launch) {
                lost_and_found();
            }

            else{
                lost_and_found_animate();
            }

            cout << "\n\n\n\n";
            cout << "\t\t\t\t\t\t    [1] Report Lost Item" << endl << endl;
            cout << "\t\t\t\t\t\t    [2] Report Found Item" << endl << endl;
            cout << "\t\t\t\t\t\t    [3] Search Items" << endl << endl;
            cout << "\t\t\t\t\t\t    [4] Display Details" << endl << endl;
            cout << "\t\t\t\t\t\t    [5] Exit" << endl << endl;

            cout << endl << "\t\t\t\t\t\t    Enter option : ";
            menu_option = getche();

            if (menu_option == EXIT) {
                cout << endl << endl << endl << " Exited successfully...";
                return 0;
            }

            if (menu_option == DISPLAY_DETAILS) {

                cout << endl << endl << "\t\t\t\t\t\t    [1] Lost Item Details" << endl;
                cout << "\t\t\t\t\t\t    [2] Found Item Details" << endl << endl;
                
                do {
                    cout << "\t\t\t\t\t\t    Option : ";
                    display_details_option = getche();
                	
                	if (display_details_option == LOST_ITEM || display_details_option == FOUND_ITEM) {
                		break;
					}
					
					if (display_details_option != LOST_ITEM && display_details_option != FOUND_ITEM) {
						cout << endl << endl << "  Error: Invalid Option" << endl;
					}
				}while(display_details_option != LOST_ITEM && display_details_option != FOUND_ITEM);
            }// end of outer if()

            if (menu_option == LOST_ITEM || menu_option == FOUND_ITEM || menu_option == SEARCH_ITEM || menu_option == DISPLAY_DETAILS) {
                break;
            }

        }while (menu_option != LOST_ITEM && menu_option != FOUND_ITEM && menu_option != SEARCH_ITEM && menu_option != DISPLAY_DETAILS && menu_option != EXIT);

        system("cls");

        switch (menu_option) {


            case LOST_ITEM:

                cout << endl << endl << "  Report Lost Item" << endl;
                cout << "----------------------------------" << endl << endl << endl;
                display_LI_inputs(&LI_person);

                    if (!is_LI_input_blank(&LI_person)) {
                        cout << endl << "  All details are provided.";
                    }

                break;



            case FOUND_ITEM:
                cout << endl << endl << "  Report Found Item" << endl;
                cout << "----------------------------------" << endl << endl << endl;

                    display_FI_inputs(&FI_person);

                    if (!is_FI_input_blank(&FI_person)) {
                        cout << endl <<  "  All details are provided.";
                    }
                break;

            case SEARCH_ITEM:
                cout << endl << endl << "  Search Item" << endl;
                cout << "----------------------------------";
                break;
                
                case DISPLAY_DETAILS:

                if (display_details_option == LOST_ITEM) {

                cout << endl << endl << "  Lost Item Details" << endl;
                cout << "----------------------------------" << endl << endl << endl;
                cout << "   Name                : " << LI_person.Name << endl;
                cout << "   ID                  : " << LI_person.ID << endl;
                cout << "   Category            : " << LI_person.Category << endl;
                cout << "   Item name           : " << LI_person.Item_Name << endl;
                cout << "   Brand name          : " << LI_person.Brand_Name << endl;
                cout << "   Item color          : " << LI_person.Item_Color << endl;
                cout << "   Unique ID           : " << LI_person.Unique_ID << endl;
                cout << "   Last seen location  : " << LI_person.Last_Seen_Location << endl;
                cout << "   Date time           : " << LI_person.Date_Time << endl;
                cout << "   Contact info        : " << LI_person.Contact_Info << endl;

                }

                if (display_details_option == FOUND_ITEM) {

                cout << endl << endl << "  Found Item Details" << endl;
                cout << "----------------------------------" << endl << endl << endl;
                cout << "   Name                : " << FI_person.Name << endl;
                cout << "   ID                  : " << FI_person.ID << endl;
                cout << "   Category            : " << FI_person.Category << endl;
                cout << "   Item name           : " << FI_person.Item_Name << endl;
                cout << "   Brand name          : " << FI_person.Brand_Name << endl;
                cout << "   Item color          : " << FI_person.Item_Color << endl;
                cout << "   Unique ID           : " << FI_person.Unique_ID << endl;
                cout << "   Last seen location  : " << FI_person.Last_Seen_Location << endl;
                cout << "   Date time           : " << FI_person.Date_Time << endl;
                cout << "   Contact info        : " << FI_person.Contact_Info << endl;

                }
                
                break;
                	


        }//end of switch
         
        cout << endl << endl << "  Press any key... ";
        (void)getch();
        is_first_launch = true;
         

    }while (1);

    return 0;

}//end of main()


void lost_and_found_animate() {

    cout << endl << endl;
    cout << "  $$\\                            $$\\                                     $$\\       $$$$$$$$\\                                  $$\\ \n";
    usleep(DELAY);
    cout << "  $$ |                           $$ |                                    $$ |      $$  _____|                                 $$ |\n";
    
    usleep(DELAY);
    cout << "  $$ |      $$$$$$\\   $$$$$$$\\ $$$$$$\\          $$$$$$\\  $$$$$$$\\   $$$$$$$ |      $$ |    $$$$$$\\  $$\\   $$\\ $$$$$$$\\   $$$$$$$ |\n";

    usleep(DELAY);
    cout << "  $$ |     $$  __$$\\ $$  _____|\\_$$  _|         \\____$$\\ $$  __$$\\ $$  __$$ |      $$$$$\\ $$  __$$\\ $$ |  $$ |$$  __$$\\ $$  __$$ |\n";
    usleep(DELAY);
    cout << "  $$ |     $$ /  $$ |\\$$$$$$\\    $$ |           $$$$$$$ |$$ |  $$ |$$ /  $$ |      $$  __|$$ /  $$ |$$ |  $$ |$$ |  $$ |$$ /  $$ |\n";
    usleep(DELAY);
    cout << "  $$ |     $$ |  $$ | \\____$$\\   $$ |$$\\       $$  __$$ |$$ |  $$ |$$ |  $$ |      $$ |   $$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |\n";
    usleep(DELAY);
    cout << "  $$$$$$$$\\\\$$$$$$  |$$$$$$$  |  \\$$$$  |      \\$$$$$$$ |$$ |  $$ |\\$$$$$$$ |      $$ |   \\$$$$$$  |\\$$$$$$  |$$ |  $$ |\\$$$$$$$ |\n";

    usleep(DELAY);

    cout << "  \\________|\\______/ \\_______/    \\____/        \\_______|\\__|  \\__| \\_______|      \\__|    \\______/  \\______/ \\__|  \\__| \\_______|\n";

    usleep(DELAY);


} 

void lost_and_found() {

    cout << endl << endl;
    cout << "  $$\\                            $$\\                                     $$\\       $$$$$$$$\\                                  $$\\ \n";
    cout << "  $$ |                           $$ |                                    $$ |      $$  _____|                                 $$ |\n";
    cout << "  $$ |      $$$$$$\\   $$$$$$$\\ $$$$$$\\          $$$$$$\\  $$$$$$$\\   $$$$$$$ |      $$ |    $$$$$$\\  $$\\   $$\\ $$$$$$$\\   $$$$$$$ |\n";
    cout << "  $$ |     $$  __$$\\ $$  _____|\\_$$  _|         \\____$$\\ $$  __$$\\ $$  __$$ |      $$$$$\\ $$  __$$\\ $$ |  $$ |$$  __$$\\ $$  __$$ |\n";
    cout << "  $$ |     $$ /  $$ |\\$$$$$$\\    $$ |           $$$$$$$ |$$ |  $$ |$$ /  $$ |      $$  __|$$ /  $$ |$$ |  $$ |$$ |  $$ |$$ /  $$ |\n";
    cout << "  $$ |     $$ |  $$ | \\____$$\\   $$ |$$\\       $$  __$$ |$$ |  $$ |$$ |  $$ |      $$ |   $$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |  $$ |\n";
    cout << "  $$$$$$$$\\\\$$$$$$  |$$$$$$$  |  \\$$$$  |      \\$$$$$$$ |$$ |  $$ |\\$$$$$$$ |      $$ |   \\$$$$$$  |\\$$$$$$  |$$ |  $$ |\\$$$$$$$ |\n";
    cout << "  \\________|\\______/ \\_______/    \\____/        \\_______|\\__|  \\__| \\_______|      \\__|    \\______/  \\______/ \\__|  \\__| \\_______|\n";

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

bool is_LI_input_blank(struct Details *LI_person) {

    if(LI_person->Category.empty() || LI_person->Item_Name.empty() || LI_person->Brand_Name.empty() ||
       LI_person->Item_Color.empty() || LI_person->Unique_ID.empty() || LI_person->Last_Seen_Location.empty() ||
       LI_person->Date_Time.empty() || LI_person->Contact_Info.empty()) {
        return true;
    }

    else {
        return false;
    }
}

bool is_FI_input_blank(struct Details *FI_person) {

    if(FI_person->Category.empty() || FI_person->Item_Name.empty() || FI_person->Brand_Name.empty() ||
       FI_person->Item_Color.empty() || FI_person->Unique_ID.empty() || FI_person->Last_Seen_Location.empty() ||
       FI_person->Date_Time.empty() || FI_person->Contact_Info.empty()) {
        return true;
    }

    else {
        return false;
    }
}



void display_LI_inputs(struct Details *LI_person) {

    /* if (is_lost_active) { */

        if (LI_person->Category.empty()) {
                cout << "  For Example: [Electronics | Documents | Apparel | Valuables | Other]" << endl << endl; 
                cout << "  Enter Item Category: ";
                getline(cin, LI_person->Category);
        }

         if (LI_person->Item_Name.empty()) {
                cout << endl << "  Enter Item Name: ";
                getline(cin, LI_person->Item_Name);
        }

         if (LI_person->Brand_Name.empty()) {
                cout << endl << "  Enter Brand Name: ";
                getline(cin, LI_person->Brand_Name);
        }

         if(LI_person->Item_Color.empty()) {
                cout << endl << "  Enter Color: ";
                getline(cin, LI_person->Item_Color);
        }

         if (LI_person->Unique_ID.empty()) {
                cout << endl << "  For Example: [Serial # | Stickers | dents | Custom marks | Other]" << endl; 
                cout << endl << "  Enter Unique Identifiers: ";
                getline(cin, LI_person->Unique_ID);
        }

         if (LI_person->Last_Seen_Location.empty()) {
                cout << endl << "  Enter Last Seen Location: ";
                getline(cin, LI_person->Last_Seen_Location);
        }

         if (LI_person->Date_Time.empty()) {
                cout << endl << "  Enter Date and Time (DD-MM-YYYY HH:MM AM/PM): ";
                getline(cin, LI_person->Date_Time);
        }

         if (LI_person->Contact_Info.empty()) {
                cout << endl << "  Enter Contact Info \n(For Example: [Phone Number | Gmail | Other]): ";
                getline(cin, LI_person->Contact_Info);
         }


    /* }//end of outer if() */
     
     
}


void display_FI_inputs(struct Details *FI_person) {

    /* if (is_found_active) { */

        if (FI_person->Category.empty()) {
                cout << "  For Example: [Electronics | Documents | Apparel | Valuables | Other]" << endl << endl; 
                cout << "  Enter Item Category: ";
                getline(cin, FI_person->Category);
        }

         if (FI_person->Item_Name.empty()) {
                cout << endl << "  Enter Item Name: ";
                getline(cin, FI_person->Item_Name);
        }

         if (FI_person->Brand_Name.empty()) {
                cout << endl << "  Enter Brand Name: ";
                getline(cin, FI_person->Brand_Name);
        }

         if(FI_person->Item_Color.empty()) {
                cout << endl << "  Enter Color: ";
                getline(cin, FI_person->Item_Color);
        }

         if (FI_person->Unique_ID.empty()) {
                cout << endl << "  For Example: [Serial # | Stickers | dents | Custom marks | Other]" << endl; 
                cout << endl << "  Enter Unique Identifiers: ";
                getline(cin, FI_person->Unique_ID);
        }

         if (FI_person->Last_Seen_Location.empty()) {
                cout << endl << "  Enter Last Seen Location: ";
                getline(cin, FI_person->Last_Seen_Location);
        }

         if (FI_person->Date_Time.empty()) {
                cout << endl << "  Enter Date and Time (DD-MM-YYYY HH:MM AM/PM): ";
                getline(cin, FI_person->Date_Time);
        }

         if (FI_person->Contact_Info.empty()) {
                cout << endl << "  Enter Contact Info \n(For Example: [Phone Number | Gmail | Other]): ";
                getline(cin, FI_person->Contact_Info);
         }


    /* }//end of outer if() */
     
     
}
