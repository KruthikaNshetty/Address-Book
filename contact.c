#include <stdio.h>
#include "contact.h"
#include<string.h>
#include<ctype.h>
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"

/* Function definitions */
// void init_intitalization(AddressBook *addressbook)
// {
// }
int create_contact(AddressBook *addressbook)//function adds a new contact to the address book
{
    int i=1;
    while(i)// // Loop to allow adding multiple contacts
    {
    char name[32],mobile_number[20],mail[30];// // Temporary variables for new contact
    get_name(name);  // function  call to get and validate name
    strcpy(addressbook->contact_details[addressbook->contact_count].Name,name);

    get_mobile_number(addressbook,mobile_number); // function  call to get and validate mobile number
    strcpy(addressbook->contact_details[addressbook->contact_count].Mobile_number,mobile_number);

     get_mail_ID(addressbook,mail);     //function  call to  get and validate email ID
     strcpy(addressbook->contact_details[addressbook->contact_count].Mail_ID,mail);
    
     (addressbook->contact_count)++; // Increase contact count
     printf(GREEN "Contact added successfully!\n" RESET);

      printf(YELLOW"Do you continue :(1-->yes 0-->No)"RESET);  // Ask user if they want to continue
      scanf("%d",&i);
    }

    return 0;
}
void list_contacts(AddressBook *addressbook)//function displays all stored contacts
{
    if(addressbook->contact_count==0) //Condition to check whether contacts are present or not
    {
        printf(RED"There is no contact in address book\n"RESET);
    }
    else{

    for(int i=0;i<addressbook->contact_count;i++)//print all the contacs
    printf(MAGENTA"name :%s\nmobile.:%s\nEmail :%s\n"RESET,addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
}
}

int search_contacts(AddressBook *addressbook)//function searches for a contact based on user choice
{
    int ch,ind;
    
    scanf("%d",&ch);// Read menu choice
    switch(ch)
    {
        case 1:
        ind=name_search(addressbook);// Search by name
        break;

        case 2:
         ind=Mobile_number_search(addressbook);// Search by mobile number
         break;

         case 3:
          ind=Mail_ID_search(addressbook);// Search by mail ID
          break;

          case 4:
          return 0;// Exit search

          default:
          printf(RED"Invalid input !\n"RESET);
          return 1;
    }
    if(ind==-1) // condition to check if contact not found
    {
    printf(RED"contact not found !\n"RESET);
    return 1;
    }
    else //Display found contact
    {
         printf(GREEN "Contact Found..\n" RESET);
         printf("\nname :%s\nmobile.:%s\nEmail :%s\n",
            addressbook->contact_details[ind].Name,addressbook->contact_details[ind].Mobile_number,addressbook->contact_details[ind].Mail_ID);
        return 1;
        }
    }
int edit_contact(AddressBook *addressbook)//function to edit a selected contact’s details
{
    int ch,choice,ind,flag;//declaring the variables
    char name[32],mobile[11],mail[35];
   
    scanf("%d",&ch);// Read user's choice of search type
    switch(ch)
    {
        case 1:
        ind=name_search(addressbook);
        break;

        case 2:
         ind=Mobile_number_search(addressbook);
         break;
         case 3:
          ind=Mail_ID_search(addressbook);
          break;
          case 4:
          return 0;
          default:
          printf(RED"Invalid input"RESET);
          return 1;
    }
    if(ind==-1) // If contact not found
    {
    printf(RED"contact not found\n"RESET);
    return 1;
    }
    else
    {   // Display current contact details
        printf(YELLOW"Contact details : \n"RESET);
        printf("name :%s\nmobile.:%s\nEmail :%s\n",addressbook->contact_details[ind].Name,addressbook->contact_details[ind].Mobile_number,addressbook->contact_details[ind].Mail_ID);
        
        printf(MAGENTA"\nEdit\n1.name\n2.Mobile number\n3.Mail_id\n4.All\n"RESET);
        printf(YELLOW"Enter the option to edit : "RESET);  // Menu for which field to edit
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            get_name(name); // Edit name
            strcpy(addressbook->contact_details[ind].Name,name);
            break;

            case 2:
            get_mobile_number(addressbook,mobile);// Edit mobile
            strcpy(addressbook->contact_details[ind].Mobile_number,mobile);
            break;

            case 3:
            get_mail_ID(addressbook,mail);// Edit mail
            strcpy(addressbook->contact_details[ind].Mail_ID,mail);
            break;

            case 4:
            get_name(name);// Edit all fields
            strcpy(addressbook->contact_details[ind].Name,name);
            get_mobile_number(addressbook,mobile);
            strcpy(addressbook->contact_details[ind].Mobile_number,mobile);
            get_mail_ID(addressbook,mail);
            strcpy(addressbook->contact_details[ind].Mail_ID,mail);
            break;

            default:
            printf(RED"INVALID INPUT !\n"RESET);


        }
        }
    
    return 1;
}
int delete_contact(AddressBook *addressbook)//function to delete a selected contact from the address book
{
     int ch,ind,choice,new=0;
    
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        ind=name_search(addressbook);
        break;

        case 2:
         ind=Mobile_number_search(addressbook);
         break;

         case 3:
          ind=Mail_ID_search(addressbook);
          break;

          case 4:
            return 0;

          default:
          printf(RED"Invalid input !"RESET);
          return 1;
    }
    if(ind==-1)// If contact not found
    {
    printf(RED"contact not found !\n"RESET);
    return 1;
    }
    else
    {
         // Display selected contact
         printf("name :%s\nmobile.:%s\nEmail :%s\n",addressbook->contact_details[ind].Name,addressbook->contact_details[ind].Mobile_number,addressbook->contact_details[ind].Mail_ID);
        printf(RED"Do you want to delete or not(1-->y 0-->no):"RESET);   // Ask for confirmation to delete
        scanf("%d",&choice);
        if(choice)// If user confirms deletion
        {
            for(int i=0;i<addressbook->contact_count;i++)  // Shift all contacts except the one to delete
            {
                if(i!=ind)
                {
                    addressbook->contact_details[new]=addressbook->contact_details[i];
                    new++;

                }
    
            }
            addressbook->contact_count=new; // Update contact count
            printf(GREEN "Contact deleted successfully...\n" RESET);
           
        }
         return 1; 
    }
        
}

int save_contacts(AddressBook *addressbook)//function to save all contacts to a file

{
    FILE *fptr=fopen("addressbook.txt","w");// Open file in write mode
    if(fptr==NULL)// Check if file is null or not
    {
         printf(RED"File not found\n"RESET);
         return 0;
    }
   
    fprintf(fptr,"#%d\n",addressbook->contact_count);// Save total contact count
    for(int i=0;i<addressbook->contact_count;i++) // Loop through each contact and save details
    {
        fprintf(fptr,"%s,%s,%s\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
    }   
    fclose(fptr);// Close file
    return 0;
}
int name_search(AddressBook *addressbook)// This function searches a contact by name
{

    char str[32],mobile[12],mail[30];
    int a[100],ch,count=0,flag=1,i;
    printf(YELLOW"Enter the name :"RESET);
    scanf(" %[^\n]",str);
    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(addressbook->contact_details[i].Name,str)==0)// Search for matching name
        {
            a[count]=i;// Store index
            count++;

        }
     
    }
    if(count>1)// condition to handle multiple matches
    {
        for(int i=0;i<count;i++)
        {
     
            printf("\nName :%s,Mobile number :%s,Email Id :%s\n",addressbook->contact_details[a[i]].Name,addressbook->contact_details[a[i]].Mobile_number,addressbook->contact_details[a[i]].Mail_ID);

        }
        printf(RED"\nMultiple contact found with this name\nplease try with mobile number or mail id\n"RESET);
        while(flag)
        {
            printf(CYAN"1.Mobile number\n2.Mail id\n"RESET);
            printf(YELLOW"Enter the option :\n"RESET);
            scanf("%d",&ch);
            
            switch(ch)
            {
                case 1:
                printf(YELLOW"Enter the mobile number: \n"RESET);//  search by mobile

                scanf(" %[^\n]",mobile);
                for(i=0;i<count;i++)
                {
                    if(strcmp(addressbook->contact_details[a[i]].Mobile_number,mobile)==0)
                    {
                        return a[i];

                    }
                }
                printf(RED"Mobile number not found ! Try again..\n\n"RESET);
                break;
                case 2:// Further search by mail
                printf(YELLOW"Enter the Mail ID : "RESET);
                scanf(" %[^\n]",mail);
                for(i=0;i<count;i++)
                {
                    if(strcmp(addressbook->contact_details[a[i]].Mail_ID,mail)==0)
                    {
                        return a[i];
                    }
                }
                printf(RED"Mail ID not found !Try again..\n"RESET);
                break;

                default:
                printf(RED"Invalid option ! Try again ..\n\n"RESET);
            }
        }
    }
    else if(count==0)
    return -1;//return -1 if contact not found
    return a[0]; // Return index if only one found

}
int Mobile_number_search(AddressBook *addressbook)// This function searches a contact by mobile number
{
    char str[32];
    printf(YELLOW"Enter the mobile number :"RESET);
    scanf(" %[^\n]",str);
    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(addressbook->contact_details[i].Mobile_number,str)==0)
        return i;
    }
    return -1;
}
int Mail_ID_search(AddressBook *addressbook)// This function searches a contact by mail ID
{
    char str[32];
    printf(YELLOW"Enter the email id :"RESET);
    scanf(" %[^\n]",str);
    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(addressbook->contact_details[i].Mail_ID,str)==0)
        return i;
    }
    return -1;
}
int validation_name(char *name)// This function validates the entered name
{
    int i=0,flag=0;
    
    while(name[i]!='\0')
    {
      if((name[i]>='a'&&name[i]<='z')|| (name[i]>='A'&&name[i]<='Z'||name[i]==' '))
      {
       i++;
      }  
      else
      {
        printf(RED"\nName should contain only alphabets and spaces !Try again.\n"RESET);
        flag=1;
        break;
      }
      
    }
    return flag;
}
int validation_mobile(char *mobile)// This function validates the entered mobile number
{
    int i=0,flag=0;
    
    while(mobile[i]!='\0')
    {
      if(isdigit(mobile[i]))
      {
       i++;
      }  
      else
      {
        printf(RED"Mobile number should contain only digit !Try again.\n"RESET);
        flag=1;
        break;
      }
    }
    if(flag==0)
    {
        if(i>10)
        {
            printf(RED"\nMobile number should only have 10 digits !Try anagin.\n"RESET);
            flag=1;
        }
        else if(i<10)
        {
            printf(RED"\nMobile number should have only 10 digits! Try again..\n"RESET);
            flag=1;
        }
      
    
            
        else if(mobile[0]<='5')
            {
            printf(RED"\nMObile number should pass from 6 or above !! Try again.\n"RESET);
            flag=1;
            }
    }
    return flag;
}
int validation_mail(char *mail)// This function validates the entered mail ID
{
    char *at_position=strchr(mail,'@');
    char  *dot_position=strchr(mail,'.');
    int len=strlen(mail);
    int flag=0;
    for(int i=0;i<=len;i++)
    {
        if((mail[i]>='A'&&mail[i]<='Z')||mail[i]==' ')
        {
            printf(RED"Mail Id should only contain numbers, lower case letters,@ symbol and full stop(.)! Try again.\n"RESET);
            return 1;
        }
    }
    if(at_position==NULL)
    {
        printf(RED"one @ symbol must be present ! Try again.\n"RESET);
        return 1;

    }
    if(at_position<mail+4)
    {
        printf(RED"Before @ there should be atleast 4 alphanumeric charcters ! Try again..\n"RESET);
        return 1;
    }
    if(strchr(at_position+1,'@')!=NULL)
    {
        printf(RED"Only one @ symbol should be in the Mail ID ! try again..\n"RESET);
        return 1;
    }
    if(dot_position==NULL)
    {
        printf(RED"Either .com or .in must be present at the end of the Mail ID !try again...\n"RESET);
        return 1;
    }
    if(dot_position==at_position+1)
    {
        printf(RED"Domain name should be present after @ symbol ! Try again.."RESET);
        return 1;
    }
    char *dot=strchr(at_position,'.');
    
    if(dot==NULL)
    {
        printf(RED"Either .com or .in must be present at the end of the Mail ID !try again...\n"RESET);
        return 1;
    }
    if(dot==at_position+1)
    {
        printf(RED"Domain name should be present after @ symbol ! Try again.."RESET);
        return 1;
    }

    if((strcmp(dot,".com")!=0)&& (strcmp(dot,".in")!=0))
    {
        printf(RED"Either .com or .in must be present at the end of mail ID! try again.\n"RESET);
        return 1;
    }
    while(mail<at_position)
    {
        if(*mail>='a'&&*mail<='z')
        {
            flag=1;
            break;
        }
        mail++;
    }
    if(flag==0)
    {
        printf(RED"Before @ there should be alphabet charecter also! Try again\n"RESET);
        return 1;
    }
    return 0;

}
void get_name(char *name)// This function gets a valid name from the user
{
    int flag =1;
    while(flag)
    {
        getchar();
        printf(YELLOW"Enter the name : "RESET);
        scanf("%[^\n]",name);
        flag=validation_name(name);
    }
}
void get_mobile_number(AddressBook *addressbook,char *mobile_number)// This function gets a valid mobile number from the user
{
    int flag=1;
    while(flag)
    {
        getchar();
        printf(YELLOW"Enter the mobile number : "RESET);
        scanf("%[^\n]",mobile_number);                                                                                                              
        flag=validation_mobile(mobile_number);
        if(flag==0)
        {
            for(int i=0;i<addressbook->contact_count;i++)
            {
                if(strcmp(addressbook->contact_details[i].Mobile_number,mobile_number)==0)
                {
                    printf(RED"\nThis number is already present.Mobile number should be unique ! Try again..\n"RESET);
                    flag=1;
                    break;
                }
            }
        }
    }
}
void get_mail_ID(AddressBook *addressbook,char *mail)// This function gets a valid mail ID from the user
{
    int flag=1;
    while(flag)
    {
        getchar();
        printf(YELLOW"Enter the email id : "RESET);
        scanf("%[^\n]",mail);
        flag=validation_mail(mail);
        if(flag==0)
        {
            for(int i=0;i<addressbook->contact_count;i++)
            {
                if(strcmp(addressbook->contact_details[i].Mail_ID,mail)==0)
                {
                    printf(RED"This mail Id is already presennt.Mail Id should be unique ! Try again..\n"RESET);
                    flag=1;
                    break;
                }
            }
        }
    }
}
void Load_contacts(AddressBook *addressbook)//// This function loads contacts from the file at program start
{
    FILE *fptr=fopen("addressbook.txt","r");
    if(fptr==NULL)
    printf(RED"File not found\n"RESET);
    fscanf(fptr,"#%d\n",&addressbook->contact_count);
    for(int i=0;i<addressbook->contact_count;i++)
    {
        fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);

    }
    fclose(fptr);
}