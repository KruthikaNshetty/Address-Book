#ifndef CONTACT_H
#define CONTACT_H

typedef struct Contact_data
{
    char Name[32];
    char Mobile_number[11];
    char Mail_ID[35];
} Contacts;

typedef struct AddressBook_Data
{
    Contacts contact_details[100];
    int contact_count;
} AddressBook;

/* Function declarations */
// void init_intitalization(AddressBook *);
int create_contact(AddressBook *);// This function adds a new contact to the address book
void list_contacts(AddressBook *);// This function displays all stored contacts
int search_contacts(AddressBook *);// This function searches for a contact based on user choice
int edit_contact(AddressBook *);// This function edits a selected contact’s details
int delete_contact(AddressBook *);// This function deletes a selected contact from the address book
int save_contacts(AddressBook *);// This function saves all contacts to a file
int name_search(AddressBook *);// This function searches a contact by name
int Mobile_number_search(AddressBook *);// This function searches a contact by mobile number
int Mail_ID_search(AddressBook *);// This function searches a contact by mail ID
int validation_name(char *);// This function validates the entered name
int validation_mobile(char *);//This function validates the entered mobile number
int validation_mail(char *);// This function validates the entered mail ID
void get_mail_ID(AddressBook *,char *);// This function gets a valid mail ID from the user
void get_mobile_number(AddressBook *,char *);// This function gets a valid mobile number from the user
void get_name(char *);// This function gets a valid name from the user
void Load_contacts(AddressBook *addressbook);// This function loads contacts from the file at program start
#endif // CONTACT_H
       // CONTACT_H
       