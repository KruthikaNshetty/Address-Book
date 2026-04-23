/*
Name:Kruthika N Shetty
 Project Description: This project implements a basic Telephone Directory Management System in C, 
 designed to efficiently store and manage contact information. It supports key operations such as 
 adding, searching, editing, deleting, and displaying contacts. Each record contains a name,
 mobile number, and email ID. The system also uses file handling to ensure that all contacts 
are securely saved and retained across program executions.

Functionality Explanation:-

1. Add Contact:
Allows the user to create a new contact by entering the name, mobile number, and email. The details are then stored in the directory.

2. Display Contacts
Shows all saved contacts in a clean, readable format so the user can view the entire directory at once.

3. Search Contact:
Enables the user to search a contact by name, mobile number, or email ID. If multiple matches exist,
the system guides the user to refine the search. Displays the complete contact details when found.

4. Edit Contact:
Allows modification of an existing contact’s name, phone number, or email. This helps keep information up to date.

5. Delete Contact:
Removes a specific contact from the directory after the user selects or confirms the entry.

6. Save Contacts:
Saves all contact details to a file so that the information remains available even after closing the program.

7. Save & Exit:
Stores all updated contact information and closes the program safely.
*/

#include <stdio.h>
#include "contact.h"
/* Structure declaration */
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

int main()
{
    
    int option;
    AddressBook addressbook;
    addressbook.contact_count = 0;


    Load_contacts(&addressbook);// Load contacts from file

    int ch; // Stores submenu options for Search/Edit/Delete menus

    while (1)// Main program loop 
    {
        printf(BLUE"\n<------* ADDRESS BOOK MENU *------>\n\n"RESET); 
        printf(CYAN "1.Add contact\n2.search contact\n3.Edit contact\n4.Delete contact\n5.Display contact\n6.Save contact\n7.Save and Exit\n\n"RESET);// Display main menu 
        printf(YELLOW"Enter the option : \n"RESET);
        scanf("%d", &option);//Enter user choice
        
        switch (option) //Perform selected operation
        {
        case 1:
        {
            create_contact(&addressbook); // Add new contact
            break;
        }

        case 2:
        {
            ch=1;
            while(ch)
            {
            printf(CYAN"Search Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\n");//Submenu for searching contact
            printf(YELLOW"Enter the option : "RESET); 
            ch=search_contacts(&addressbook);//returns 0 to exit submenu
            }
            break;
        }
        case 3:
        {
            ch=1;
            while(ch)
            {
            printf(CYAN"Edit Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : "RESET); //Submenu for editing contact
           ch= edit_contact(&addressbook);
            }
            break;
        }

        case 4:
        {
            ch=1;
            while(ch)
            {
                printf(CYAN"Delete Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\n"RESET);//Submenu for deleting contact
                 printf(YELLOW"Enter the option : "RESET); 
                ch= delete_contact(&addressbook);
            }
            break;
        }
        case 5:
        {

            printf(GREEN "List Contacts:\n"RESET);//Display all contacts 
            list_contacts(&addressbook);
            break;
        }

        case 6:
            printf(GREEN "Saving contacts\n"RESET);//Save contacts to file
            save_contacts(&addressbook);
            break;

        case 7:
            printf(GREEN "INFO : Save and Exit...\n"RESET);//Exit after saving
             save_contacts(&addressbook);
            return 0;

        default:
            printf(RED"Invalid option \n"RESET);//Invalid option handling 
            break;
        }
        getchar();
       
        
    }
    return 0;

}