// implementation of the OLX

// created by NMIT CSE_3 => Shubham Kr. Singh

//header files//
#include <cstdlib>
#include<iostream>
#include<string.h>
#include<string>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<iomanip>
#define MAX_LENGHT     128
#define ENTER           13
#define BACKSPACE        8
#define QUITER          113

using namespace std;

//function for getting date//


void getdate(char *tday){
	time_t tim;
	tim=time(NULL);
	struct tm *d=localtime(&tim);
	//char tday[10];
	sprintf(tday,"%02d/%02d/%d",d->tm_mday,d->tm_mon+1,d->tm_year+1900);
}

//****************************************************//
//base class for login and signup classes//
//****************************************************//
class base1
{
   protected:      char name[50];
                    char mob[50];
                    char email_id[50];
                   char ch;
                   char password[MAX_LENGHT];
                   char passcheck[30];
                    int pos1=0;
                    int pos2=0;
                    char loa[30];
   public:       virtual void getdata()=0;

};

class signup:private base1
{
    public:
                    void getdata()
                    {
                        int count =0;
                        cout<<"\n Email ID: ";
                        cin>>email_id;
                    LOOP:{

                            cout<<" \nPassword : ";
                            while(true)
                            {
                                ch=getch();
                                if(pos1>=MAX_LENGHT) {cout<<'\a'; continue;} //beep sound if password is long than 128//

                                if(ch==ENTER) break;  //if ch = '13' then break//

                                else if(ch==BACKSPACE)  //if ch='8' backspace was pressed //
                                {
                                    cout <<"\b \b";
                                password[--pos1]='\0';       //assign the previous position as null //
                                }
                                else // write to the password array//
                                {
                                    cout <<"*";
                                    password[pos1++]=ch;
                                    password[pos1]='\0';
                                }
                                if(pos1<=0) pos1=0;
                            }

                            cout<<"\nRetype password : " ;
                            while(true)
                            {
                            ch=getch();
                            if(pos2>=MAX_LENGHT) {cout<<'\a'; continue;}

                            if(ch==ENTER) break;

                            else if(ch==BACKSPACE)
                                {
                                cout <<"\b \b";
                                passcheck[--pos2]='\0';
                                }
                            else
                                {
                                cout <<"*";
                                passcheck[pos2++]=ch;
                                passcheck[pos2
                                ]='\0';
                                 }
                               if(pos2<=0) pos2=0;
                             }
                         if(strcmp(password,passcheck)==0)
                         {
                            cout <<"\n\nPassword Accepted!";
                            cout<<"\nAccount Created Successfully \n";
                              pos1=0,pos2=0;
                               cout<<"\nName : ";
                        getchar();
                        gets(name);
                        Loopx:cout<<"\nMobile No. : ";
                        while(true)
                            {
                                ch=getch();
                                if(pos1>10)
                                {
                                cout<<'\a';pos1=0;
                                cout<<"\nInvalid Mobile No.";
                                goto Loopx; } //beep sound if password is long than 128//

                                if(ch==ENTER)
                                {   pos1=0;
                                    break;  //if ch = '13' then break//
                                }
                                else if(ch==BACKSPACE)  //if ch='8' backspace was pressed //
                                {
                                    cout <<"\b \b";
                                mob[--pos1]='\0';       //assign the previous position as null //
                                }
                                else // write to the password array//
                                {
                                    cout <<ch;
                                    mob[pos1++]=ch;
                                    mob[pos1]='\0';
                                }
                                if(pos1<=0) pos1=0;
                            }
                         }

                         else
                         {  count+=1;
                         if(count==3)
                         {  pos1=0,pos2=0;
                            return;
                         }
                            cout <<"\nPassword Did not Match!\n";
                            pos1=0,pos2=0;
                            goto LOOP;
                         }
                        }
                        cout<<" \n Make a recovery code: ";
                        cin>>loa;
                        cout<<"\n\n please take a minute to write it down ";
                    }


                    void show()
                    {
                       cout<<email_id<<setw(40)<<name<<setw(30)<<mob<<endl;
                    }

                    char *retname()
                    {
                        return name;
                    }
};


class login: private base1
{
    public:
                char ch;

                void getdata()
                {
                    system("cls");
                    HANDLE  hConsole;
                            int k=010;

                            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                            SetConsoleTextAttribute(hConsole, k);
                            cout<<"\n\t\tLogin Page" << endl;
                            k=03;
                            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                            SetConsoleTextAttribute(hConsole, k);
                            Loop2: cout<<"\n\n Email_id: ";
                            cin>>email_id;
                            cout<<"\n\n Password: ";
                            while(true)
                             {
                               ch=getch();
                               if(pos1>=MAX_LENGHT) {cout<<'\a'; continue;} /* beep if password is too long */

                               if(ch==ENTER) break;  /* User have pressed ENTER*/

                               else if(ch==BACKSPACE)  /* BACKSPACE was pressed*/
                                 {
                                   cout <<"\b \b";
                                   password[--pos1]='\0';
                                 }
                               else
                                 {
                                   cout <<"*";
                                   password[pos1++]=ch;
                                   password[pos1]='\0';
                                 }
                               if(pos1<=0) pos1=0;
                             }
                }
                    int complaint();
                    int notification();
void modifyuser()
                    {

                      LOOP:{
                            cout<<"\n\nNew password : ";
                            while(true)
                            {
                                ch=getch();
                                if(pos1>=MAX_LENGHT) {cout<<'\a'; continue;} //beep sound if password is long than 128//

                                if(ch==ENTER) break;  //if ch = '13' then break//

                                else if(ch==BACKSPACE)  //if ch='8' backspace was pressed //
                                {
                                    cout <<"\b \b";
                                password[--pos1]='\0';       //assign the previous position as null //
                                }
                                else // write to the password array//
                                {
                                    cout <<"*";
                                    password[pos1++]=ch;
                                    password[pos1]='\0';
                                }
                                if(pos1<=0) pos1=0;
                            }

                            cout<<"\nRetype password : " ;
                            while(true)
                            {
                            ch=getch();
                            if(pos2>=MAX_LENGHT) {cout<<'\a'; continue;}

                            if(ch==ENTER) break;

                            else if(ch==BACKSPACE)
                                {
                                cout <<"\b \b";
                                passcheck[--pos2]='\0';
                                }
                            else
                                {
                                cout <<"*";
                                passcheck[pos2++]=ch;
                                passcheck[pos2
                                ]='\0';
                                 }
                               if(pos2<=0) pos2=0;
                             }

                         if(strcmp(password,passcheck)==0)
                         {
                            cout <<"\n\nPassword Accepted!";
                            cout<<"\nPassword Change Successful \n";
                              pos1=0,pos2=0;
                         }

                         else
                         {
                            cout <<"\nPassword Did Not Match!\n";
                            pos1=0,pos2=0;
                            goto LOOP;
                         }
                        }

                    }


                    char* retemail()
                    {
                        return email_id;
                    }

                    char* retrec()
                    {
                        return loa;
                    }

                    char* retpass()
                    {
                        return password;
                    }

};





//****************************************************//
//ADMIN CLASS//
//****************************************************//

class ADMIN
{
    char adminid[50];
     char adminpass[MAX_LENGHT];
     char passcheck[30];
     char ch;
     int pos1=0;
     int pos2=0;
     int rec;

public:     void getdata();
            int Notification();
             int complaint();
            void removeuser(char*);
            char* retemail()
                    {
                        return adminid;
                    }

                    char* retpass()
                    {
                        return adminpass;
                    }

};



//****************************************************//
//INTRO FUNC.//
//****************************************************//

void intro()
{
system("cls");
    cout<<"=========================================================================\n";
	cout<<setw(20)<<"SIMULATION"<<setw(20)<<"OF"<<setw(20)<<"OLX"<<endl;
	cout<<"=========================================================================\n";
	cout<<"\n\nMade By : Shubham Kr. Singh\n ";
	cout<<"\n\nCollege Name : NMIT";

	getch();
}


//*************
//declaring date//
void date();
//**********


//****************************************************//
//title for the pages//
//****************************************************//

void title(){
    system("cls");
	cout<<"==============================================================================="<<endl;
	cout<<"\t\t**************** OLX *****************"<<endl;
	cout<<"==============================================================================="<<endl;
}

//****************************************************//
//complaint and notification for the user//
//****************************************************//

int login::complaint()
{

                    system("cls");
                        ofstream out("complaint.dat",ios::binary|ios::out|ios::app);
                        if(!out){
                            cout<<"Unable to open complaint file ";
                            return -1;
                        }

                        title();
                        char today[11],note[500];
                        getdate(today);
                         cout<<"\t\t\t\t\t\t\t    Today : "<<today;
                        cout<<"\nEnter Complaint: \n";
                        fflush(stdin);
                        cin.getline(note,500);
                            out<<"\n\n__________________________________________________________       "<<today<<"\n"<<" "<<note<<"\t -"<<email_id<<"\n\n\n";

                        out.close();
                        cout<<endl<<" Complaint given successfully..."; cin.get();


}

int login::notification()
{
    system("cls");
	char ch;
    ifstream in("notification.dat",ios::binary|ios::in);
    if(!in)
       {
              cout<<"FILE NOT FOUND ";
        }

	title();
	date();
	in.seekg(0);
	cout<<"\n ";
    while(!in.eof()){
    in.get(ch);
    cout<<ch;
    }

    cout<<"\nPress any key to return...";
	in.close();
	getch();
}

//****************************************************//
//for printing the current date//
//****************************************************//
void date()
{
      char today[11];
        getdate(today);
         cout<<"\n\n                                                    \t Date: "<<today<<endl;
}


//****************************************************//
//category class => the base class for other categories//
//****************************************************//
class category
{
    protected:  char prodno[40];
                char namep[40];
                char price[40];
                char names[40];
                char mobno[40];
                char city[50];
                char descp[40];
                char seckey[40];

    public:
            category(){};
            void getdet();
            virtual void createlist()=0;
            virtual void modify_prod()=0;
            virtual void showprod()=0;
            virtual void report()=0;


};


void category::getdet()
{

    cout<<"\nEnter Product Number: ";
    cin>>prodno;
    cout<<"\nEnter Product Name : ";
    getchar();
        gets(namep);
    cout<<"\nEnter the Price : " ;
    cin>>price;
    cout<<"\nEnter the Description : ";
     getchar();
        gets(descp);
    cout<<"\nEnter the Name of the seller : ";
    gets(names);
    cout<<"\nEnter the City : ";
    cin>>city;
    cout<<"\nEnter the Mobile Number : ";
    cin>>mobno;
}
//****************************************************//
//class inheriting form the category class//
//****************************************************//
class bandc : private category
{
    char modeltype[40];
    char adddet[40];

    public: void createlist()
            {
                category::getdet();
                cout<<"\nEnter the Type of Vehicle : ";
               getchar();
                gets(modeltype);
                cout<<"\nAny additional Details : ";
                gets(adddet);
                cout<<"\n Enter Private Key: ";
                gets(seckey);
            }


            void modify_prod()
            {
                cout<<"\nProduct no. : "<<prodno;
                cout<<"\nModify Product Name : ";
                getchar();
                gets(namep);
                cout<<"\nModify the Price : " ;
                cin>>price;
                cout<<"\nModify the Description : ";
                getchar();
                gets(descp);
                cout<<"\nModify the Name of the seller : ";
                gets(names);
                cout<<"\nModify the City : ";
                cin>>city;
                cout<<"\nModify the Mobile Number : ";
                cin>>mobno;
                cout<<"\nModify the Type of Vehicle : ";
               getchar();
                gets(modeltype);
                cout<<"\nAdd Any additional Details : ";
                gets(adddet);
            }

            void showprod()
            {
                cout<<"\nProduct Number : "<<prodno;
                cout<<"\n\nName Of Product : ";
                puts(namep);
                cout<<"\nPrice :"<<price;
                cout<<"\nDescription :";
                puts(descp);
                cout<<"\nType :";
                puts(modeltype);
                cout<<"\nAddition Details:";
                puts(adddet);
                cout<<"\nSeller Name: ";
                puts(names);
                cout<<"\nCity: ";
                puts(city);
                cout<<"\nMobile No. :"<<mobno;

            }
            void report()
            {
                {cout<<prodno<<setw(40)<<namep<<setw(30)<<price<<endl;}
            }

            char* retprodno()
        {
            return seckey;
        }

            char* retdetb()
            {
                return prodno;
            }

};






//**************************************************************
class eanda : private category
{
    char appltype[40];
    char adddet2[40];

    public:     void createlist()
                {
                 category::getdet();
                 cout<<"Enter the type of appliance ";
                getchar();
                     gets(appltype);
                     cout<<"\nAny additional Details : ";
                     gets(adddet2);
                     cout<<"\n Enter Private Key: ";
                     gets(seckey);

                }

                void modify_prod()
            {
                cout<<"\nProduct no. : "<<prodno;
                cout<<"\nModify Product Name : ";
                getchar();
                gets(namep);
                cout<<"\nModify the Price : " ;
                cin>>price;
                cout<<"\nModify the Description : ";
                getchar();
                gets(descp);
                cout<<"\nModify the Name of the seller : ";
                gets(names);
                cout<<"\nModify the City : ";
                cin>>city;
                cout<<"\nModify the Mobile Number : ";
                cin>>mobno;
                cout<<"\nModify the type of Appliance : ";
                getchar();
                gets(appltype);
                cout<<"\nAdd Any additional Details : ";
                gets(adddet2);
                }

                void showprod()
            {
                cout<<"\nProduct Number : "<<prodno;
                cout<<"\nName Of Product : ";
                puts(namep);
                cout<<"\nPrice :"<<price;
                cout<<"\nDescription :";
                puts(descp);
                cout<<"\n Type of Electronical Appliance :";
                puts(appltype);
                cout<<"\nAddition Details:";
                puts(adddet2);
                cout<<"\nSeller Name: ";
                puts(names);
                cout<<"\nCity: ";
                puts(city);
                cout<<"\nMobile No. :"<<mobno;

            }


            void report()
            {
                {cout<<prodno<<setw(40)<<namep<<setw(30)<<price<<endl;}
            }

            char* retprodnoe()
        {
            return seckey;
        }

        char* retdete()
            {
                return prodno;
            }
};

//**************************************************************


class fandp : private category
{
    char furtype[40];
    char adddet3[40];

    public:  void createlist()
            {
                category::getdet();
                cout<<"\nEnter the Type of Furniture : ";
               getchar();
                gets(furtype);
                cout<<"\nAny additional Details : ";
                gets(adddet3);
                cout<<"\n Enter Private Key: ";
                gets(seckey);
            }

            void modify_prod()
            {
                cout<<"\nProduct no. : "<<prodno;
                cout<<"\nModify Product Name : ";
                getchar();
                gets(namep);
                cout<<"\nModify the Price : " ;
                cin>>price;
                cout<<"\nModify the Description : ";
                getchar();
                gets(descp);
                cout<<"\nModify the Name of the seller : ";
                gets(names);
                cout<<"\nModify the City : ";
                cin>>city;
                cout<<"\nModify the Mobile Number : ";
                cin>>mobno;
                cout<<"\nModify the Type of Furniture : ";
               getchar();
                gets(furtype);
                cout<<"\nAdd Any additional Details : ";
                gets(adddet3);
            }

            void showprod()
            {
                cout<<"\nProduct Number : "<<prodno;
                cout<<"\nName Of Product : ";
                puts(namep);
                cout<<"\nPrice :"<<price;
                cout<<"\nDescription :";
                puts(descp);
                cout<<"\n Type :";
                puts(furtype);
                cout<<"\nAddition Details:";
                puts(adddet3);
                cout<<"\nSeller Name: ";
                puts(names);
                cout<<"\nCity: ";
                puts(city);
                cout<<"\nMobile No. :"<<mobno;

            }
            void report()
            {
                {cout<<prodno<<setw(40)<<namep<<setw(30)<<price<<endl;}
            }

            char* retprodnof()
        {
            return seckey;
        }

        char* retdetf()
            {
                return prodno;
            }

};


//******************************************************************
class sando : private category
{
    char spotype[40];
    char adddet4[40];

    public:  void createlist()
            {
                category::getdet();
                cout<<"\nEnter the Type of Sports Equipment : ";
               getchar();
                gets(spotype);
                cout<<"\nAny additional Details : ";
                gets(adddet4);
                cout<<"\n Enter Private Key: ";
                gets(seckey);
            }

            void modify_prod()
            {
                cout<<"\nProduct no. : "<<prodno;
                cout<<"\nModify Product Name : ";
                getchar();
                gets(namep);
                cout<<"\nModify the Price : " ;
                cin>>price;
                cout<<"\nModify the Description : ";
                getchar();
                gets(descp);
                cout<<"\nModify the Name of the seller : ";
                gets(names);
                cout<<"\nModify the City : ";
                cin>>city;
                cout<<"\nModify the Mobile Number : ";
                cin>>mobno;
                cout<<"\nModify the Type of Equipment : ";
               getchar();
                gets(spotype);
                cout<<"\nAdd Any additional Details : ";
                gets(adddet4);
            }

            void showprod()
            {
                cout<<"\nProduct Number : "<<prodno;
                cout<<"\nName Of Product : ";
                puts(namep);
                cout<<"\nPrice :"<<price;
                cout<<"\nDescription :";
                puts(descp);
                cout<<"\n Type :";
                puts(spotype);
                cout<<"\nAddition Details:";
                puts(adddet4);
                cout<<"\nSeller Name: ";
                puts(names);
                cout<<"\nCity: ";
                puts(city);
                cout<<"\nMobile No. :"<<mobno;

            }
            void report()
            {
                {cout<<prodno<<setw(40)<<namep<<setw(30)<<price<<endl;}
            }

            char* retprodnos()
        {
            return seckey;
        }

            char* retdets()
            {
                return prodno;
            }

};
//**********************************************************
class mandg : private category
{
    char gadtype[40];
    char adddet5[40];

    public:  void createlist()
            {
                category::getdet();
                cout<<"\nEnter the Type of Mobile or Gadgets : ";
               getchar();
                gets(gadtype);
                cout<<"\nAny additional Details : ";
                gets(adddet5);
                cout<<"\n Enter Private Key: ";
                gets(seckey);
            }

            void modify_prod()
            {
                cout<<"\nProduct no. : "<<prodno;
                cout<<"\nModify Product Name : ";
                getchar();
                gets(namep);
                cout<<"\nModify the Price : " ;
                cin>>price;
                cout<<"\nModify the Description : ";
                getchar();
                gets(descp);
                cout<<"\nModify the Name of the seller : ";
                gets(names);
                cout<<"\nModify the City : ";
                cin>>city;
                cout<<"\nModify the Mobile Number : ";
                cin>>mobno;
                cout<<"\nModify the Type of Equipment : ";
               getchar();
                gets(gadtype);
                cout<<"\nAdd Any additional Details : ";
                gets(adddet5);
            }

            void showprod()
            {
                cout<<"\nProduct Number : "<<prodno;
                cout<<"\nName Of Product : ";
                puts(namep);
                cout<<"\nPrice :"<<price;
                cout<<"\nDescription :";
                puts(descp);
                cout<<"\n Type :";
                puts(gadtype);
                cout<<"\nAddition Details:";
                puts(adddet5);
                cout<<"\nSeller Name: ";
                puts(names);
                cout<<"\nCity: ";
                puts(city);
                cout<<"\nMobile No. :"<<mobno;

            }
            void report()
            {
                {cout<<prodno<<setw(40)<<namep<<setw(30)<<price<<endl;}
            }

            char* retprodnom()
        {
            return seckey;
        }
            char* retdetm()
            {
                return prodno;
            }

};

//************************************************
class bando : private category
{
    char booktype[40];
    char adddet6[40];

    public:  void createlist()
            {
                category::getdet();
                cout<<"\nEnter the Type of Product : ";
               getchar();
                gets(booktype);
                cout<<"\nAny additional Details : ";
                gets(adddet6);
                cout<<"\n Enter Private Key: ";
                gets(seckey);
            }

            void modify_prod()
            {
                cout<<"\nProduct no. : "<<prodno;
                cout<<"\nModify Product Name : ";
                getchar();
                gets(namep);
                cout<<"\nModify the Price : " ;
                cin>>price;
                cout<<"\nModify the Description : ";
                getchar();
                gets(descp);
                cout<<"\nModify the Name of the seller : ";
                gets(names);
                cout<<"\nModify the City : ";
                cin>>city;
                cout<<"\nModify the Mobile Number : ";
                cin>>mobno;
                cout<<"\nModify the Type of Equipment : ";
               getchar();
                gets(booktype);
                cout<<"\nAdd Any additional Details : ";
                gets(adddet6);
            }

            void showprod()
            {
                cout<<"\nProduct Number : "<<prodno;
                cout<<"\nName Of Product : ";
                puts(namep);
                cout<<"\nPrice :"<<price;
                cout<<"\nDescription :";
                puts(descp);
                cout<<"\n Type :";
                puts(booktype);
                cout<<"\nAddition Details:";
                puts(adddet6);
                cout<<"\nSeller Name: ";
                puts(names);
                cout<<"\nCity: ";
                puts(city);
                cout<<"\nMobile No. :"<<mobno;

            }
            void report()
            {
                {cout<<prodno<<setw(40)<<namep<<setw(30)<<price<<endl;}
            }

            char* retprodnob()
        {
            return seckey;
        }
            char* retdeto()
            {
                return prodno;
            }

};



//****************************************************//
//declarations of file streams and objects of all the classes//
//****************************************************//
fstream fp,fp1;
signup s;
login l;
bandc bc;
eanda ea;
fandp fap;
sando so;
mandg mg;
bando bo;
ADMIN a;

//****************************************************//
//functions to create a new product and write in the file//
//****************************************************//


void newprodb()
{
    char ch;

    fp.open("bikes&cars.dat",ios::out|ios::app);
    do
	{
		system("cls");
		title();
		date();
		bc.createlist();
		fp.write((char*)&bc,sizeof(bandc));
		cout<<"\n Listing Done";
		getch();
	}while(ch=='13');
	fp.close();
}

void newprode()
{
    char ch;
    fp.open("electronic&appliance.dat",ios::out|ios::app);
    do
    {
        system("cls");
        title();
        date();
        ea.createlist();
        fp.write((char*)&ea,sizeof(eanda));
        cout<<"\nListing Done";
        getch();
    }
    while(ch=='13');
    fp.close();
}

void newprodf()
{
    char ch;
      title();
      date();
    fp.open("furniture&products.dat",ios::out|ios::app);
    do
	{
		system("cls");
		title();
		fap.createlist();
		fp.write((char*)&fap,sizeof(fandp));
		cout<<"\n Listing Done";
		getch();
	}while(ch=='13');
	fp.close();
}


void newprods()
{
    char ch;
      title();
      date();
    fp.open("sports&others.dat",ios::out|ios::app);
    do
	{
		system("cls");
		title();
		so.createlist();
		fp.write((char*)&so,sizeof(sando));
		cout<<"\n Listing Done";
		getch();
	}while(ch=='13');
	fp.close();
}


void newprodm()
{
    char ch;
      title();
      date();
    fp.open("mobile&gadgets.dat",ios::out|ios::app);
    do
	{
		system("cls");
		title();
		mg.createlist();
		fp.write((char*)&mg,sizeof(mandg));
		cout<<"\n Listing Done";
		getch();
	}while(ch=='13');
	fp.close();
}


void newprodo()
{
    char ch;
      title();
      date();
    fp.open("book&others.dat",ios::out|ios::app);
    do
	{
		system("cls");
		title();
		bo.createlist();
		fp.write((char*)&bo,sizeof(bando));
		cout<<"\n Listing Done";
		getch();
	}while(ch=='13');
	fp.close();
}






//****************************************************//
//function to modify the products and write in the file//
//****************************************************//
void modify_datab()
            {
                char n[30];
                int found=0;
                system("cls");
                  title();
                  date();
                cout<<"\n\n\tModify Details.... ";
                cout<<"\n\n\tEnter The Secret key ";
                cin>>n;
                fp.open("bikes&cars.dat",ios::in|ios::out);
                while(fp.read((char*)&bc,sizeof(bandc)) && found==0)
                {
                    if(strcmpi(bc.retprodno(),n)==0)
                {
                bc.showprod();
                cout<<"\nEnter The New Details of Product"<<endl;
                bc.modify_prod();
                int pos=-1*sizeof(bc);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&bc,sizeof(bandc));
                    cout<<"\n\n\t Product Updated";
                    found=1;
            }
        }

            fp.close();
            if(found==0)
                cout<<"\n\n Record Not Found ";
            getch();
            }

void modify_datae()
{
                char n[30];
                int found=0;
                system("cls");
                  title();
                  date();
                cout<<"\n\n\tModify Details.... ";
                cout<<"\n\n\tEnter The Secret key ";
                cin>>n;
                fp.open("electronic&appliance.dat",ios::in|ios::out);
                while(fp.read((char*)&ea,sizeof(eanda)) && found==0)
                {
                    if(strcmpi(ea.retprodnoe(),n)==0)
                {
                ea.showprod();
                cout<<"\nEnter The New Details of Product"<<endl;
                ea.modify_prod();
                int pos=-1*sizeof(ea);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&ea,sizeof(eanda));
                    cout<<"\n\n\t Product Updated";
                    found=1;
            }
        }

            fp.close();
            if(found==0)
                cout<<"\n\n Record Not Found ";
            getch();
}

void modify_dataf()
            {
                char n[30];
                int found=0;
                system("cls");
                  title();
                  date();
                cout<<"\n\n\tModify Details.... ";
                cout<<"\n\n\tEnter The Secret key ";
                cin>>n;
                fp.open("furniture&products.dat",ios::in|ios::out);
                while(fp.read((char*)&fap,sizeof(fandp)) && found==0)
                {
                    if(strcmpi(fap.retprodnof(),n)==0)
                {
                fap.showprod();
                cout<<"\nEnter The New Details of Product"<<endl;
                fap.modify_prod();
                int pos=-1*sizeof(bc);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&fap,sizeof(fandp));
                    cout<<"\n\n\t Product Updated";
                    found=1;
            }
        }

            fp.close();
            if(found==0)
                cout<<"\n\n Record Not Found ";
            getch();
}


void modify_datas()
            {
                char n[30];
                int found=0;
                system("cls");
                  title();
                  date();
                cout<<"\n\n\tModify Details.... ";
                cout<<"\n\n\tEnter The Secret key ";
                cin>>n;
                fp.open("sports&others.dat",ios::in|ios::out);
                while(fp.read((char*)&so,sizeof(sando)) && found==0)
                {
                    if(strcmpi(so.retprodnos(),n)==0)
                {
                so.showprod();
                cout<<"\nEnter The New Details of Product"<<endl;
                so.modify_prod();
                int pos=-1*sizeof(bc);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&so,sizeof(sando));
                    cout<<"\n\n\t Product Updated";
                    found=1;
            }
        }

            fp.close();
            if(found==0)
                cout<<"\n\n Record Not Found ";
            getch();
}


void modify_datam()
            {
                char n[30];
                int found=0;
                system("cls");
                  title();
                  date();
                cout<<"\n\n\tModify Details.... ";
                cout<<"\n\n\tEnter The Secret key ";
                cin>>n;
                fp.open("mobile&gadgets.dat",ios::in|ios::out);
                while(fp.read((char*)&mg,sizeof(mandg)) && found==0)
                {
                    if(strcmpi(mg.retprodnom(),n)==0)
                {
                mg.showprod();
                cout<<"\nEnter The New Details of Product"<<endl;
                mg.modify_prod();
                int pos=-1*sizeof(bc);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&mg,sizeof(mandg));
                    cout<<"\n\n\t Product Updated";
                    found=1;
            }
        }

            fp.close();
            if(found==0)
                cout<<"\n\n Record Not Found ";
            getch();
}


void modify_datao()
            {
                char n[30];
                int found=0;
                system("cls");
                  title();
                  date();
                cout<<"\n\n\tModify Details.... ";
                cout<<"\n\n\tEnter The Secret key ";
                cin>>n;
                fp.open("book&others.dat",ios::in|ios::out);
                while(fp.read((char*)&bo,sizeof(bando)) && found==0)
                {
                    if(strcmpi(bo.retprodnob(),n)==0)
                {
                bo.showprod();
                cout<<"\nEnter The New Details of Product"<<endl;
                bo.modify_prod();
                int pos=-1*sizeof(bc);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&bo,sizeof(bando));
                    cout<<"\n\n\t Product Updated";
                    found=1;
            }
        }

            fp.close();
            if(found==0)
                cout<<"\n\n Record Not Found ";
            getch();
}



//****************************************************//
//function to delete a product when the user has buied//
//****************************************************//

void delete_bandc(char n[])
{
	int flag=0;
    system("cls");
      title();
      date();
    	fp.open("bikes&cars.dat",ios::in|ios::out);
    	fstream fp2;
    	fp2.open("Temp1.dat",ios::out);
    	fp.seekg(0,ios::beg);
    	while(fp.read((char*)&bc,sizeof(bandc)))
	{
		if(strcmpi(bc.retdetb(),n)!=0)
	     		fp2.write((char*)&bc,sizeof(bandc));
		else
	   		flag=1;
	}

	fp2.close();
    	fp.close();
    	remove("bikes&cars.dat");
    	rename("Temp1.dat","bikes&cars.dat");
    	if(flag==1)

     		cout<<"\n"<<setw(40)<<"Congratulations On Buying The Product :) ";
    	getch();
}




void delete_eanda(char n[])
{
	int flag=0;
    system("cls");
      title();
      date();
    	fp.open("electronic&appliance.dat",ios::in|ios::out);
    	fstream fp2;
    	fp2.open("Temp2.dat",ios::out);
    	fp.seekg(0,ios::beg);
    	while(fp.read((char*)&ea,sizeof(eanda)))
	{
		if(strcmpi(ea.retdete(),n)!=0)
	     		fp2.write((char*)&ea,sizeof(eanda));
		else
	   		flag=1;
	}

	fp2.close();
    	fp.close();
    	remove("electronic&appliance.dat");
    	rename("Temp2.dat","electronic&appliance.dat");
    	if(flag==1)

     		cout<<"\n"<<setw(40)<<"Congratulations On Buying The Product :) ";
    	getch();
}

void delete_fandp(char n[])
{
	int flag=0;
    system("cls");
      title();
      date();
    	fp.open("furniture&products.dat",ios::in|ios::out);
    	fstream fp2;
    	fp2.open("Temp2.dat",ios::out);
    	fp.seekg(0,ios::beg);
    	while(fp.read((char*)&fap,sizeof(fandp)))
	{
		if(strcmpi(fap.retdetf(),n)!=0)
	     		fp2.write((char*)&fap,sizeof(fandp));
		else
	   		flag=1;
	}

	fp2.close();
    	fp.close();
    	remove("furniture&products.dat");
    	rename("Temp2.dat","furniture&products.dat");
    	if(flag==1)

     		cout<<"\n"<<setw(40)<<"Congratulations On Buying The Product :) ";
    	getch();
}

void delete_sando(char n[])
{
	int flag=0;
    system("cls");
      title();
      date();
    	fp.open("sports&others.dat",ios::in|ios::out);
    	fstream fp2;
    	fp2.open("Temp3.dat",ios::out);
    	fp.seekg(0,ios::beg);
    	while(fp.read((char*)&so,sizeof(sando)))
	{
		if(strcmpi(so.retdets(),n)!=0)
	     		fp2.write((char*)&so,sizeof(sando));
		else
	   		flag=1;
	}

	fp2.close();
    	fp.close();
    	remove("sports&others.dat");
    	rename("Temp3.dat","sports&others.dat");
    	if(flag==1)

     		cout<<"\n"<<setw(40)<<"Congratulations On Buying The Product :) ";
    	getch();
}

void delete_mandg(char n[])
{
	int flag=0;
    system("cls");
      title();
      date();
    	fp.open("mobile&gadgets.dat",ios::in|ios::out);
    	fstream fp2;
    	fp2.open("Temp4.dat",ios::out);
    	fp.seekg(0,ios::beg);
    	while(fp.read((char*)&mg,sizeof(mandg)))
	{
		if(strcmpi(mg.retdetm(),n)!=0)
	     		fp2.write((char*)&mg,sizeof(mandg));
		else
	   		flag=1;
	}

	fp2.close();
    	fp.close();
    	remove("mobile&gadgets.dat");
    	rename("Temp4.dat","mobile&gadgets.dat");
    	if(flag==1)

     		cout<<"\n"<<setw(40)<<"Congratulations On Buying The Product :) ";
    	getch();
}

void delete_bando(char n[])
{
	int flag=0;
    system("cls");
      title();
      date();
    	fp.open("book&others.dat",ios::in|ios::out);
    	fstream fp2;
    	fp2.open("Temp5.dat",ios::out);
    	fp.seekg(0,ios::beg);
    	while(fp.read((char*)&bo,sizeof(bando)))
	{
		if(strcmpi(bo.retdeto(),n)!=0)
	     		fp2.write((char*)&bo,sizeof(bando));
		else
	   		flag=1;
	}

	fp2.close();
    	fp.close();
    	remove("book&others.dat");
    	rename("Temp5.dat","book&others.dat");
    	if(flag==1)

     		cout<<"\n"<<setw(40)<<"Congratulations On Buying The Product :) ";
    	getch();
}





//****************************************************//
//function to show the details of the product selected by the user//
//****************************************************//

void display_sbc(char n[])
{   char fin;
  title();
  date();
	cout<<"\n"<<setw(40)<<"PRODUCT DETAILS\n";
	int flag=0;
	fp.open("bikes&cars.dat",ios::in);
	while(fp.read((char*)&bc,sizeof(bandc)))
	{
		if(strcmpi(bc.retdetb(),n)==0)
		{
			bc.showprod();
		 	flag=1;
		}
	}
	fp.close();
	if(flag==0)
    {

		cout<<"\n\nProduct does not exist";
		getch();
		return;
    }
    cout<<"\n\nContact The Owner for Images of the Product";
    cout<<"\n\nDid u finalize the Product(y/n) ? ";
    cin>>fin;
    if(fin=='y'||fin=='Y')
    {
        delete_bandc(n);

    }



}





void display_sea(char n[])
{   char fin;
  title();
  date();
	cout<<"\n"<<setw(40)<<"PRODUCT DETAILS\n";
	int flag=0;
	fp.open("electronic&appliance.dat",ios::in);
	while(fp.read((char*)&ea,sizeof(eanda)))
	{
		if(strcmpi(ea.retdete(),n)==0)
		{
			ea.showprod();
		 	flag=1;
		}
	}
	fp.close();
	if(flag==0)
    {

		cout<<"\n\nProduct does not exist";
		getch();
		return;
    }
    cout<<"\n\nContact The Owner for Images of the Product";
    cout<<"\n\nDid u finalize the Product(y/n) ? ";
    cin>>fin;
    if(fin=='y'||fin=='Y')
    {
        delete_eanda(n);

    }



}




void display_sfp(char n[])
{   char fin;
  title();
  date();
	cout<<"\n"<<setw(40)<<"PRODUCT DETAILS\n";
	int flag=0;
	fp.open("furniture&products.dat",ios::in);
	while(fp.read((char*)&fap,sizeof(fandp)))
	{
		if(strcmpi(fap.retdetf(),n)==0)
		{
			fap.showprod();
		 	flag=1;
		}
	}
	fp.close();
	if(flag==0)
    {

		cout<<"\n\nProduct does not exist";
		getch();
		return;
    }
    cout<<"\n\nContact The Owner for Images of the Product";
    cout<<"\n\nDid u finalize the Product(y/n) ? ";
    cin>>fin;
    if(fin=='y'||fin=='Y')
    {
        delete_fandp(n);

    }



}

void display_sso(char n[])
{   char fin;
  title();
  date();
	cout<<"\n"<<setw(40)<<"PRODUCT DETAILS\n";
	int flag=0;
	fp.open("sports&others.dat",ios::in);
	while(fp.read((char*)&so,sizeof(sando)))
	{
		if(strcmpi(so.retdets(),n)==0)
		{
			so.showprod();
		 	flag=1;
		}
	}
	fp.close();
	if(flag==0)
    {

		cout<<"\n\nProduct does not exist";
		getch();
		return;
    }
    cout<<"\n\nContact The Owner for Images of the Product";
    cout<<"\n\nDid u finalize the Product(y/n) ? ";
    cin>>fin;
    if(fin=='y'||fin=='Y')
    {
        delete_sando(n);

    }



}


void display_smg(char n[])
{   char fin;
  title();
  date();
	cout<<"\n"<<setw(40)<<"PRODUCT DETAILS\n";
	int flag=0;
	fp.open("mobile&gadgets.dat",ios::in);
	while(fp.read((char*)&mg,sizeof(mandg)))
	{
		if(strcmpi(mg.retdetm(),n)==0)
		{
			mg.showprod();
		 	flag=1;
		}
	}
	fp.close();
	if(flag==0)
    {

		cout<<"\n\nProduct does not exist";
		getch();
		return;
    }
    cout<<"\n\nContact The Owner for Images of the Product";
    cout<<"\n\nDid u finalize the Product(y/n) ? ";
    cin>>fin;
    if(fin=='y'||fin=='Y')
    {
        delete_mandg(n);

    }



}

void display_sbo(char n[])
{   char fin;
  title();
  date();
	cout<<"\n"<<setw(40)<<"PRODUCT DETAILS\n";
	int flag=0;
	fp.open("book&others.dat",ios::in);
	while(fp.read((char*)&bo,sizeof(bando)))
	{
		if(strcmpi(bo.retdeto(),n)==0)
		{
			bo.showprod();
		 	flag=1;
		}
	}
	fp.close();
	if(flag==0)
    {

		cout<<"\n\nProduct does not exist";
		getch();
		return;
    }
    cout<<"\n\nContact The Owner for Images of the Product";
    cout<<"\n\nDid u finalize the Product(y/n) ? ";
    cin>>fin;
    if(fin=='y'||fin=='Y')
    {
        delete_bando(n);

    }



}







//****************************************************//
//function to display all the products under one category//
//****************************************************//

void display_allbandc()
{

        system("cls");
        title();
        date();
     	fp.open("bikes&cars.dat",ios::in);
     	if(!fp)
     	{
       		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
       		return;
     	}

	cout<<"\n\n\t\tBIKES & CARS\n\n";
	cout<<"===========================================================================\n";
	cout<<"\tProduct No."<<setw(20)<<"Name"<<setw(30)<<"Price\n";
	cout<<"===========================================================================\n";

	while(fp.read((char*)&bc,sizeof(bandc)))
	{
		bc.report();
	}
	fp.close();
	char ans;
    cout<<"\n\nDo you want to buy a product (y/n) ? ";
    cin>>ans;
    if(ans=='y'||ans=='Y')
    {
                char num[20];
	       		system("cls");
	       		cout<<"\n\n\tPlease Enter The product No. : ";
	       		cin>>num;
	       		display_sbc(num);
    }


}

void display_alleanda()
{
system("cls");
title();
date();
     	fp.open("electronic&appliance.dat",ios::in);
     	if(!fp)
     	{
       		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
       		return;
     	}

	cout<<"\n\n\t\tELECTRONICS & APPLIANCES\n\n";
	cout<<"===========================================================================\n";
	cout<<"\tProduct No."<<setw(20)<<"Name"<<setw(30)<<"Price\n";
	cout<<"===========================================================================\n";

	while(fp.read((char*)&ea,sizeof(eanda)))
	{
		ea.report();
	}

	fp.close();
	char ans;
    cout<<"\n\nDo you want to buy a product (y/n) ? ";
    cin>>ans;
    if(ans=='y'||ans=='Y')
    {
                char num[20];
	       		system("cls");
	       		cout<<"\n\n\tPlease Enter The product No. : ";
	       		cin>>num;
	       		display_sea(num);
    }


}


void display_allfandp()
{
system("cls");
title();
date();
     	fp.open("furniture&products.dat",ios::in);
     	if(!fp)
     	{
       		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
       		return;
     	}

	cout<<"\n\n\t\tFurnitures & Products\n\n";
	cout<<"===========================================================================\n";
	cout<<"\tProduct No."<<setw(20)<<"Name"<<setw(30)<<"Price\n";
	cout<<"===========================================================================\n";

	while(fp.read((char*)&fap,sizeof(fandp)))
	{
		fap.report();
	}

	fp.close();
    char ans;
    cout<<"\n\nDo you want to buy a product (y/n) ? ";
    cin>>ans;
    if(ans=='y'||ans=='Y')
    {
                char num[20];
	       		system("cls");
	       		cout<<"\n\n\tPlease Enter The product No. : ";
	       		cin>>num;
	       		display_sfp(num);
    }
}



void display_allsando()
{
system("cls");
title();
date();
     	fp.open("sports&others.dat",ios::in);
     	if(!fp)
     	{
       		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
       		return;
     	}

	cout<<"\n\n\t\tSports & Others\n\n";
	cout<<"===========================================================================\n";
	cout<<"\tProduct No."<<setw(20)<<"Name"<<setw(30)<<"Price\n";
	cout<<"===========================================================================\n";

	while(fp.read((char*)&so,sizeof(sando)))
	{
		so.report();
	}

	fp.close();
	char ans;
    cout<<"\n\nDo you want to buy a product (y/n) ? ";
    cin>>ans;
    if(ans=='y'||ans=='Y')
    {
                char num[20];
	       		system("cls");
	       		cout<<"\n\n\tPlease Enter The product No. : ";
	       		cin>>num;
	       		display_sso(num);
    }
}




void display_allmandg()
{
system("cls");
title();
date();
     	fp.open("mobile&gadgets.dat",ios::in);
     	if(!fp)
     	{
       		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
       		return;
     	}

	cout<<"\n\n\t\tMobiles & Gadgets\n\n";
	cout<<"===========================================================================\n";
	cout<<"\tProduct No."<<setw(20)<<"Name"<<setw(30)<<"Price\n";
	cout<<"===========================================================================\n";

	while(fp.read((char*)&mg,sizeof(mandg)))
	{
		mg.report();
	}

	fp.close();
	char ans;
    cout<<"\n\nDo you want to buy a product (y/n) ? ";
    cin>>ans;
    if(ans=='y'||ans=='Y')
    {
                char num[20];
	       		system("cls");
	       		cout<<"\n\n\tPlease Enter The product No. : ";
	       		cin>>num;
	       		display_smg(num);
    }

}


void display_allbando()
{
system("cls");
title();
date();
     	fp.open("book&others.dat",ios::in);
     	if(!fp)
     	{
       		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
       		return;
     	}

	cout<<"\n\n\t\tMobiles & Gadgets\n\n";
	cout<<"===========================================================================\n";
	cout<<"\tProduct No."<<setw(20)<<"Name"<<setw(30)<<"Price\n";
	cout<<"===========================================================================\n";

	while(fp.read((char*)&bo,sizeof(bando)))
	{
		bo.report();
	}

	fp.close();
	char ans;
    cout<<"\n\nDo you want to buy a product (y/n) ? ";
    cin>>ans;
    if(ans=='y'||ans=='Y')
    {
                char num[20];
	       		system("cls");
	       		cout<<"\n\n\tPlease Enter The product No. : ";
	       		cin>>num;
	       		display_sbo(num);
    }
}

//****************************************************//
//Loading screen//
//****************************************************//


int loader()
{   system("cls");
    char ch;
cout<<"\n\n\n"<<setw(40) << "Loading";
cout.flush();
for (int j=0;j<1;j++ )
{
for (int i = 0; i < 3; i++)
{
std::cout << ".";
std::cout.flush();
for(double counter = 0; counter < 100000000; counter++);
}
std::cout << "\b\b\b   \b\b\b";
}
return 0;

}


//****************************************************//
//function for sign up//
//****************************************************//

void signuped()
{
    char ch;

    fp.open("signupdet.txt",ios::out|ios::app);
    do
	{
		system("cls");
		title();
		date();
        cout<< "\t\t\t\t Signup\n";
        s.getdata();
		fp.write((char*)&s,sizeof(signup));
		cout<<"\n Press Enter to Continue";
		getch();
	}while(ch=='13');
	fp.close();
}

//****************************************************//
//function if the user has forgotten password//
//****************************************************//
void forgpass()
{           int found = 0;
            char e[50];
            char r[40];
            char choo;
            system("cls");
              title();
              date();
            cout<<"\n\nForgot Password";
            cout<<"\n\n\tEmail id : ";
            cin>>e;
            cout<<"\n\n\tEnter Recovery code : ";
            cin>>r;
            fp.open("signupdet.txt",ios::in|ios::out);
            while(fp.read((char*)&l,sizeof(login)) && found==0)
                {
                    if(strcmpi(l.retemail(),e)==0&&strcmpi(l.retrec(),r)==0)
                {   found=1;


                    l.modifyuser();
                    int pos=-1*sizeof(l);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&l,sizeof(login));
                    found=1;

                }

                }
                 fp.close();
                 if(found==0)
                 {
                      cout<<"\nWrong Email ID or recovery code ";
                    cout<<"\n\nPress any key to go back to the Login Page"<<endl;
                    getch();
                    return;
                 }
}



//****************************************************//
//if the user has entered wrong password at login//
//****************************************************//



void failmenu()
{   char fm;
  title();
  date();
    cout<<"\n\n";
    cout<<"\t Wrong Credentials Have Been Entered 3 times \n\n";
    cout<<"\n\n";
    cout<<setw(30)<<" 1. Forgot Password\n\n 2. Signup\n\n  3. Return to Main Menu";
    fm=getch();
    switch(fm)
    {
        case '1' : forgpass();
                  break;
        case '2' :  signuped();
                   break;
        case '3' :  return;
        default:  '\a';
    }

}

//****************************************************//
//Sell function to sell products once the user has logged in//
//****************************************************//
void sellmenu()
{
    system("cls");

        int ch3;
        for(;;)
        {
        system("cls");
        title();
        date();
        cout<<"\n\n\n\tCATEGORIES";
        cout<<"\n\n\t1.BIKES & CARS";
        cout<<"\n\n\t2.ELECTRONICS & APPLIANCES";
        cout<<"\n\n\t3.FURNITURES & PRODUCTS ";
        cout<<"\n\n\t4.SPORTS EQUIPMENT & OTHERS";
        cout<<"\n\n\t5.MOBILES & GADGETS ";
        cout<<"\n\n\t6.BOOKS & OTHERS";
        cout<<"\n\n\t7.BACK TO MAIN MENU";

         ch3=getch();
                switch(ch3)
	{
    		case '1': newprodb();
                    break;
    		case '2': newprode();
                    break;
    		case '3': newprodf();
                    break;
            case '4': newprods();
                    break;
      		case '5': newprodm();
                    break;
            case '6': newprodo();
                      break;
            case '7':   return;
			default: cout<<'\a';

    }
        }
}

//****************************************************//
//buy function for both the user and the guest//
//****************************************************//

void buymenu()
{
        system("cls");
        int ch2;
        for(;;)
        {
        system("cls");
        title();
        date();
        cout<<"\n\n\tBUY MENU :";
        cout<<"\n\n\n\tCATEGORIES";
        cout<<"\n\n\t1.BIKES & CARS";
        cout<<"\n\n\t2.ELECTRONICS & APPLIANCES";
        cout<<"\n\n\t3.FURNITURES & PRODUCTS ";
        cout<<"\n\n\t4.SPORTS EQUIPMENT & OTHERS";
        cout<<"\n\n\t5.MOBILES & GADGETS ";
        cout<<"\n\n\t6.BOOKS & OTHERS";
        cout<<"\n\n\t7.BACK TO MAIN MENU";

        ch2=getch();
        switch(ch2)
	{
    		case '1': display_allbandc();
                    break;
    		case '2': display_alleanda();
                    break;
    		case '3': display_allfandp();
                    break;
            case '4': display_allsando();
                    break;
      		case '5': display_allmandg();
                    break;
            case '6': display_allbando();
                    break;
            case '7':   return;
                        break;
			default: cout<<'\a';

    }
        }
}

//****************************************************//
//modify function for the person who has put up listing of a product//
//****************************************************//


void modifymenu()
{
     system("cls");
       title();
       date();
        int ch3;
        for(;;)
        {
        system("cls");
        cout<<"\n\n\n\tCATEGORIES";
        date();
        cout<<"\n\n\n\tSELECT THE CATEGORY OF YOUR PRODUCT";
        cout<<"\n\n\t1.MODIFY BIKES & CARS POST";
        cout<<"\n\n\t2.MODIFY ELECTRONICS & APPLIANCES POST";
        cout<<"\n\n\t3.MODIFY FURNITURES & PRODUCTS POST";
        cout<<"\n\n\t4.MODIFY SPORTS EQUIPMENT & OTHERS POST";
        cout<<"\n\n\t5.MODIFY MOBILES & GADGETS POST";
        cout<<"\n\n\t6.MODIFY BOOKS & OTHERS POST";
        cout<<"\n\n\t7.BACK TO MAIN MENU";

        ch3=getch();
        switch(ch3)
	{
    		case '1': modify_datab();
                    break;
    		case '2': modify_datae();
                    break;
    		case '3': modify_dataf();
                    break;
            case '4': modify_datas();
                    break;
      		case '5': modify_datam();
                    break;
            case '6': modify_datao();
                      break;
            case '7':   return;
			default: cout<<'\a';

    }
        }
}
//****************************************************//
//opening the bike&cars file and closing it//
//****************************************************//

void worker()
{
     fp.open("bikes&cars.dat",ios::in|ios::out);
     fp.close();
}

//****************************************************//
//if the credentials entered by the user are correct //
//****************************************************//
void logsuccess(char *email_id)
{   system("cls");
    char ch9;
    worker();
    for(;;)
    {
        system("cls");
              title();
              date();
               cout<<"\tLogin ID :   ["<<email_id<<"]"<<endl;
    cout<<"\n"<<setw(30)<<"Welcome to OLX \n\n";

    cout<<"\n"<<setw(30)<<"1. Sell    2. Buy    3. Modify Post   4. Issue Complaint    5. See Notifications    6. Logout \n";
    ch9=getch();
    switch(ch9)
    {
        case '1' : sellmenu();
                   break;
        case '2' : system("cls");
                   buymenu();
                   break;
        case '3' :  modifymenu();
                    break;
        case '4' :  l.complaint();
                    break;
        case '5'  : l.notification();
                    break;
        case '6' :  cout<<"\n\n\tLogging Out : ["<<email_id<<"]"<<endl;;
                    Sleep(1000);
                    return;
    }
    }
}
//****************************************************//
//login page //
//****************************************************//
void loginuped()

{
            char ch;
            int pos1=0;
            char ch2;
            char e[30];
            char p[40];
            int found=0;
            int count=0;
             system("cls");
         LOOP:     title();
             date();
            HANDLE  hConsole;
            HANDLE m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
             SetConsoleTextAttribute ( m_hConsole,
                              FOREGROUND_BLUE |
                              FOREGROUND_INTENSITY|
                              BACKGROUND_RED|
                              BACKGROUND_GREEN|
                              BACKGROUND_BLUE|
                              BACKGROUND_INTENSITY);

            cout<<"\n\t\tLogin Page" << endl;
            cout<<"\n\t\t\t\t\t\t\t\t\tPress q to Quit\t\npress any key to continue";
            ch=getch();
                  if(ch==QUITER)
                  return;
            cout<<"\n\n\tEmail id : ";
            cin>>e;
            cout<<"\n\n\tEnter Password : ";
            while(true)
                            {
                                ch=getch();

                                if(pos1>=MAX_LENGHT) {cout<<'\a'; continue;} //beep sound if password is long than 128//

                                if(ch==ENTER) break;  //if ch = '13' then break//

                                else if(ch==BACKSPACE)  //if ch='8' backspace was pressed //
                                {
                                    cout <<"\b \b";
                                p[--pos1]='\0';       //assign the previous position as null //
                                }
                                else // write to the password array//
                                {
                                    cout <<"*";
                                    p[pos1++]=ch;
                                    p[pos1]='\0';
                                }
                                if(pos1<=0) pos1=0;
                            }
                         SetConsoleTextAttribute ( m_hConsole,
                              FOREGROUND_RED |
                              FOREGROUND_GREEN |
                              FOREGROUND_BLUE );

            fp.open("signupdet.txt",ios::in|ios::out);
            while(fp.read((char*)&l,sizeof(login)) && found==0)
                {
                    if(strcmpi(l.retemail(),e)==0&&strcmp(l.retpass(),p)==0)
                {   found=1;
                     cout<< "\n"<<setw(10)<<"\nLogin successful :)";
                     getch();
                     logsuccess(l.retemail());

                }
                }
            fp.close();
            if(found==0)
            {   pos1=0;
                count+=1;
                cout<<"\n\n\t Login Failed ";
                getch();
                if(count==3)

                {
                     failmenu();
                     count=0;
                     return;
                }
                goto LOOP;


            }

}

//****************************************************//
//DECLARING THEADMIN MENU FOR THE ADMIN//
//****************************************************//


void adminmenu(char*);


//****************************************************//
//function of the ADMIN class//
//****************************************************//

void ADMIN::getdata()
{   int count;
    system("cls");
    title();
    date();
    cout<< "\t\t\t\t New Admin\n";
    cout<<"\n Email ID: ";
                        cin>>adminid;
                    LOOP:{

                            cout<<" \nPassword : ";
                            while(true)
                            {
                                ch=getch();
                                if(pos1>=MAX_LENGHT) {cout<<'\a'; continue;} //beep sound if password is long than 128//

                                if(ch==ENTER) break;  //if ch = '13' then break//

                                else if(ch==BACKSPACE)  //if ch='8' backspace was pressed //
                                {
                                    cout <<"\b \b";
                                adminpass[--pos1]='\0';       //assign the previous position as null //
                                }
                                else // write to the password array//
                                {
                                    cout <<"*";
                                    adminpass[pos1++]=ch;
                                    adminpass[pos1]='\0';
                                }
                                if(pos1<=0) pos1=0;
                            }

                            cout<<"\nRetype password : " ;
                            while(true)
                            {
                            ch=getch();
                            if(pos2>=MAX_LENGHT) {cout<<'\a'; continue;}

                            if(ch==ENTER) break;

                            else if(ch==BACKSPACE)
                                {
                                cout <<"\b \b";
                                passcheck[--pos2]='\0';
                                }
                            else
                                {
                                cout <<"*";
                                passcheck[pos2++]=ch;
                                passcheck[pos2
                                ]='\0';
                                 }
                               if(pos2<=0) pos2=0;
                             }
                         if(strcmp(adminpass,passcheck)==0)
                         {
                            cout <<"\n\nPassword Accepted!";
                            cout<<"\nAccount Created Successfully \n";
                              pos1=0,pos2=0;
                         }

                         else
                         {  count+=1;
                         if(count==3)
                            return;
                            cout <<"\nPassword Did not Match!\n";
                            pos1=0,pos2=0;
                            goto LOOP;
                         }
                        }
}





int ADMIN::Notification(){
	system("cls");
	ofstream putf("notification.dat",ios::binary|ios::out|ios::app);
	if(!putf){
		cout<<"Unable to open notifications file ";
		return -1;
	}

	title();
	char today[11],note[500];
	getdate(today);
	 cout<<"\t\t\t\t\t\t\t    Today : "<<today;
	cout<<"\nEnter Notifications: \n";
	fflush(stdin);
	cin.getline(note,500);
    putf<<"\n_________________________________________________________________        "<<today<<"\n"<<note<<"--"<<"\t\t\t"<<adminid<<"\n\n\n";
	putf.close();
	cout<<endl<<" Notification added successfully..."; cin.get();
}


int ADMIN::complaint(){
	system("cls");
	char ch;
    ifstream in("complaint.dat",ios::binary|ios::in);
    if(!in.is_open()){
              return -1;
    }
	title();
	date();
	in.seekg(0);
	cout<<"\n ";
    while(!in.eof()){
    in.get(ch);
    cout<<ch;
    }

    cout<<"\nPress any key to return...";
	in.close();
	getch();

}

void ADMIN::removeuser(char *n)
{
    int flag=0;
    system("cls");
    worker();
      title();
      date();
    	fp.open("signupdet.txt",ios::in|ios::out);
    	fstream fp2;
    	fp2.open("Temp7.dat",ios::out);
    	fp.seekg(0,ios::beg);
    	while(fp.read((char*)&s,sizeof(signup)))
	{
		if(strcmpi(s.retname(),n)!=0)
	     		fp2.write((char*)&s,sizeof(signup));
		else

	   		flag=1;

	}

	fp2.close();
    	fp.close();
    	remove("signupdet.txt");
    	rename("Temp7.dat","signupdet.txt");
    	if(flag==1)

     		cout<<"\n"<<setw(40)<<"\nUser Removed Successfully ";
    	getch();
}


//****************************************************//
//function to display all the signed up users//
//****************************************************//
void reader()
{

    system("cls");
     	fp.open("signupdet.txt",ios::in);
     	if(!fp)
     	{
       		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
       		return;
     	}
    title();
    date();
	cout<<"\n\n\t\t\t\tUSER DETAILS\n\n";
	cout<<"========================================================================================================\n";
	cout<<setw(5)<<"EMAIL_ID"<<setw(40)<<"NAME"<<setw(40)<<"MOBILE NO.\n";
	cout<<"========================================================================================================\n";

	while(fp.read((char*)&s,sizeof(signup)))
	{
		s.show();
	}
	fp.close();
}





//****************************************************//
//function to make a new admin //
//****************************************************//


void adminuped()

{   fp.open("admin.dat",ios::app);
    fp.close();
    char ch;

    fp.open("admin.dat",ios::out|ios::app);
    do
	{
		system("cls");
		title();
		date();
        a.getdata();
		fp.write((char*)&a,sizeof(ADMIN));
		cout<<"\n Press Enter to Continue";
		getch();
	}while(ch=='13');
	fp.close();
}

//****************************************************//
//to check the admin login //
//****************************************************//
void adminlog()
{
    char ch;
            int count = 0;
            int pos1=0;
            char ch2;
            char e[30];
            char p[40];
            int found=0;
             system("cls");
             title();
             date();
            HANDLE  hConsole;
             HANDLE m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
             SetConsoleTextAttribute ( m_hConsole,
                              FOREGROUND_BLUE |
                              FOREGROUND_INTENSITY|
                              BACKGROUND_RED|
                              BACKGROUND_GREEN|
                              BACKGROUND_BLUE|
                              BACKGROUND_INTENSITY);

            cout<<"\n\t\tAdmin Login Page" << endl;
            cout<<"\n\n\tEmail id : ";
            cin>>e;
            cout<<"\n\n\tEnter Password : ";
            while(true)
                            {
                                ch=getch();
                                if(pos1>=MAX_LENGHT) {cout<<'\a'; continue;} //beep sound if password is long than 128//

                                if(ch==ENTER) break;  //if ch = '13' then break//

                                else if(ch==BACKSPACE)  //if ch='8' backspace was pressed //
                                {
                                    cout <<"\b \b";
                                p[--pos1]='\0';       //assign the previous position as null //
                                }
                                else // write to the password array//
                                {
                                    cout <<"*";
                                    p[pos1++]=ch;
                                    p[pos1]='\0';
                                }
                                if (pos1<=0) pos1=0;
                            }
                         SetConsoleTextAttribute ( m_hConsole,
                              FOREGROUND_RED |
                              FOREGROUND_GREEN |
                              FOREGROUND_BLUE );

            fp.open("admin.dat",ios::in|ios::out);
            while(fp.read((char*)&a,sizeof(ADMIN)) && found==0)
                {
                    if(strcmpi(a.retemail(),e)==0&&strcmp(a.retpass(),p)==0)
                    {
                      found=1;
                     cout<<"\n"<<setw(10)<<"\nLogin successful :)";
                     getch();
                     adminmenu(a.retemail());

                    }
                    else
                    {
                        count+= 1;
                        if(count==3)
                        {
                            cout<<"\n\n Please check your User name or password";
                            return;
                        }
                    }
                }
            fp.close();
            if(found==0)
            {
                system("CLS");
                title();
                cout<<"\n\nWrong Email Id or Password\n";
                cout<<"\n\n\t Login Failed ";
                getch();
                adminlog();
                return;
            }
}

//****************************************************//
//Defination of the Admin MEnu//
//****************************************************//
void adminmenu(char *adminid)
{   char ch;
    char n[40];
        for(;;)
        {
        system("cls");
        title();
         cout<<"\n\tAdmin ID :   ["<<adminid<<"]"<<endl;
         date();
         cout<<"\n\nADMIN MENU";
        cout<<"\n\n1.View Users\t\t 2.Issue Notification\t\t 3.See Complaints\t\t 4. New Admininstrator\t\t 5.Remove User\t\t 6.Log Out ";
        cout<<"\n\nEnter your Choice ?";
        ch=getch();
        switch(ch)
        {
            case '1' :  worker();
                        reader();
                        getch();
                       break;
            case '2'  : a.Notification();
                        break;
            case '3'  : a.complaint();
                        break;
            case '4'  :adminuped();
                        break;
            case '6'  : cout<<"\n\n\tLogging Out : ["<<adminid<<"]"<<endl;;
                        Sleep(1000);
                        return;
            case '5'  : system("cls");
                        title();
                        date();
                        cout<<"\n\n Enter the name of the user : ";
                        getchar();
                        gets(n);
                        a.removeuser(n);
                        break;
        }
        }
}

//****************************************************//
//to check if its the first time usage of the program//
//****************************************************//
int setup()
{
	title();
	date();
	ifstream in("admin.dat",ios::in);
	if(in)
        {
		return 1;
        }
	cout<<endl<<"Initiating the Program For first time usage... ";
	cout<<"\n Please wait ";
	Sleep(1300);
    adminuped();
}




//****************************************************//
//MAIN FUNCTION//
//****************************************************//






int main()
{        intro();
        char today[11];
        if(setup()==0) {
		cout<<"Files are missing and unable to create new files...\n Please try again..."; Sleep(2000);
		exit(0);
	}
            int count=0;
            getdate(today);
            loader();
            system("cls");
            if(!fp)
            {
                cout<<"\n File not found";
                return 0;
            }
            int chmain;

            for(;;)
            {
                 system("cls");
                 title();
                 HANDLE m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

                    SetConsoleTextAttribute ( m_hConsole,
                              BACKGROUND_RED |
                              BACKGROUND_GREEN |
                              BACKGROUND_INTENSITY|
                              BACKGROUND_INTENSITY|
                              BACKGROUND_BLUE );
                    cout << "\n\n"<<setw(20)<<"\t\tWELCOME TO OLX\n\n";
                     SetConsoleTextAttribute ( m_hConsole,
                              FOREGROUND_RED |
                              FOREGROUND_GREEN |
                              FOREGROUND_BLUE );


                 cout<<" \n\n +_+_+_+_+_+_+MAIN MeNU+_+_+_+_+_+_\n";
                 cout<<"\n\n                                                    \t Date: "<<today<<endl;
            cout<<"\n 1. Buy \n\n 2. Login \n\n 3. Signup \n\n 4. Administrator Login\n\n 5. Exit \n"<<endl ;
                chmain=getch();
                switch(chmain)
                {
                  case '1': system("cls");
                            buymenu();

                            break;

                  case '2':  loginuped();
                             break;


                  case '3':     signuped();
                                break;

                                break;
                  case '4':  adminlog();
                                break;
                  case '5':  cout<<"\nExiting...\n";
                            Sleep(1000);
                            exit(0);
                  case '6' : adminuped();
                  default:  cout<<"\a";
                            getch();
                            break;
                }
            }
}


//****************************************************//
//END OF THE PROGRAM//
//****************************************************//
