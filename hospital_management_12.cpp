/*
Project Title: Hospital Record Management System
Version      : 1.0
Developed By : Sachleen Kaur
School       : Delhi Public School R.K. Puram
*/


/************************************************************************************
 This is a menu-driven program which does the following:
 1. Takes input details of a Patient (Registration No, Name, Age, Blood Group, etc.) and stores them in a sorted binary file   
 2. Searches details of a patient based on Registration No and displays the same
 3. Allows modification of an existing Patient record after searching by Registration No 
 4. Delete a Patient record after searching for it on the basis of Registration No  
 5. Display all Patient details on screen    
 6. Binary file used by this program is called "PATIENT.DAT" ,if it doesn't exist, it will be created.
Authors: Sachleen Kaur
 Class Section: XII-K 
 Date: 25/02/2018
 *************************************/

#include <iostream.h>
#include <string.h>
#include <stdio.h>
#include <fstream.h>
#include<conio.h>

class patient
{
int regno;
char name[20];
	int age;
char doctor[30];
	char address[1000];
	char symptoms[70];
	char disease[50];
	char consultationdate[30];
	long int phoneno;
	int bloodgroup;
	char dateadmitted[20];
	char datedischarged[20];
		int bill;
       public:
int get_regno();
void get_data();
void display();
void modify_data();
void calcbill();
};

/**************************************
 *   Following is a member function of the class patient which returns the private data member regno.                       
*************************************/

int patient::get_regno()
{
return regno;
}

/**************************************
 *   Following is a member function of the class patient which takes input from user for patient’s name,  *
 *   regno, age, address, phone no, symptoms, disease, doctor, date admitted, date discharged and bill. *                                                                   
*************************************/

void patient::get_data()
{
cout<<endl;
cout<< "Enter regno: ";
cin>> regno;
cout<< "Enter Name: ";
gets(name);
cout<< "Enter Age: ";
cin>>age;
cout<< "Enter Address:  ";
gets(address);
cout<< "Enter Doctor’s Name: ";
gets(doctor);
cout<<"Enter Symptoms: ";
gets(symptoms);
cout<<"Enter Disease: ";
gets(disease);
cout<<"Enter Consultation Date in words: (eg: 21 November 2017) ";
gets(consultationdate);
cout<<"Enter Phone no: ";
cin>>phoneno;
cout << endl;
cout << "Selection" <<"\t\t" << "Blood Group" << endl;
cout << "------------" <<"\t\t" << "-------" << endl;
cout << "1" << "\t \t \t" << "A+" << endl;
cout << "2" << "\t\t\t" << "A-" << endl;
cout << "3" << "\t\t\t" << "B+" << endl;
cout << "4" << "\t\t\t" << "B-" << endl;
cout << "5" << "\t\t\t" << "AB+" << endl;
cout << "6" << "\t\t\t" << "AB-" << endl;
cout << "7" << "\t\t\t" << "O+" << endl;
cout << "8" << "\t\t\t" << "O-" << endl;
cout<<"Enter Blood Group (Select 1-8) ";
cin>>bloodgroup;
while ((bloodgroup <1)||(bloodgroup > 8))
            {
                cout << endl << " **** Invalid Selection - Selection Should Be Between 1 and 8 *** "                <<endl<<endl;
                cout << "Enter Blood Group (Select 1-8) : ";
                cin >> bloodgroup;
            }
cout<<"Enter Date Admitted in words: (eg: 21 November 2017) ";
gets(dateadmitted);
cout<<"Enter Date Discharged in words: (eg: 21 November 2017) ";
gets(datedischarged);
cout<<"Enter the initial bill charge: ";
cin>>bill;
	}

/**************************************
 *   Following is a member function of the class patient which displays one patient record on the screen.    *
******************************************************************/
void patient::display()
{
cout<<endl;
cout<< "Name: " <<name<<endl;
cout<< "Registration No: " <<regno <<endl;
cout<< "Age: " <<age<<endl;
cout<< "Doctor: " << doctor <<endl<<endl;
cout<< "Address: "  << address<<endl;
cout<< "Symptoms: "  << symptoms<<endl;
cout<< "Disease: "  << disease<<endl;
cout<< "Consultation Date: "  << consultationdate<<endl;
cout<< "Phone No: "  << phoneno<<endl;
switch (bloodgroup)
           			 {
            				  case 1 :
                				cout<<"A+"<<endl; 
break;
              				case 2:
                				cout<<"A-"<<endl; 
break;
              				case 3 :
                				cout<<"B+"<<endl; 
break;
                			case 4:
                				cout<<"B-"<<endl; 
break;              					
case 5:
                				cout<<"AB+"<<endl; 
break;
              				case 6:
                				cout<<"AB-"<<endl; 
break;
              				case 7:
                				cout<<"O+"<<endl; 
break;
				case 8 :
                				cout<<"O-"<<endl; 
break;
              				default:
                				cout<< "invalid choice" << endl;
                				break;
			}
cout<< "Date Admitted: "  <<dateadmitted<<endl;
cout<< "Date Discharged: "  << datedischarged<<endl;
cout<< "Initial Bill: "  << bill<<endl;

cout<< "-------" <<"\t\t\t" << "-----" <<endl;
}

void display_all_patient_details()
        	{
fstream f;
patient s;
f.open("PATIENT.DAT", ios::in|ios::binary);
f.read((char*)&s, sizeof(s));
while(!f.eof())
           		{
s.display();
f.read((char*)&s, sizeof(s));
           		}
f.close();
        	}
/**************************************
 *   Following is a member function of the class patient which takes input from user to modify a patient record.          *
 **************************************/
void patient::modify_data()
{
cout<<endl;
cout<< "Enter regno: ";
cin>> regno;
cout<< "Enter Name: ";
gets(name);
cout<< "Enter Age";
cin>>age;
cout<< "Enter Address ";
gets(address);
cout<< "Enter Doctor’s Name";
gets(doctor);
cout<<"Enter Symptoms";
gets(symptoms);
cout<<"Enter Disease";
gets(disease);
cout<<"Enter Consultation Date";
gets(consultationdate);
cout<<"Enter Phone no";
cin>>phoneno;
cout << endl;
cout << "Selection" <<"\t\t" << "Blood Group" << endl;
cout << "------------" <<"\t\t" << "-------" << endl;
cout << "1" << "\t \t \t" << "A+" << endl;
cout << "2" << "\t\t\t" << "A-" << endl;
cout << "3" << "\t\t\t" << "B+" << endl;
cout << "4" << "\t\t\t" << "B-" << endl;
cout << "5" << "\t\t\t" << "AB+" << endl;
cout << "6" << "\t\t\t" << "AB-" << endl;
cout << "7" << "\t\t\t" << "O+" << endl;
cout << "8" << "\t\t\t" << "O-" << endl;
cout<<"Enter Blood Group (Select 1-8) ";
cin>>bloodgroup;
while ((bloodgroup <1)||(bloodgroup > 8))
            {
                cout << endl << " **** Invalid Selection - Selection Should Be Between 1 and 8 *** "                <<endl<<endl;
                cout << "Enter Blood Group (Select 1-8) :";
                cin >> bloodgroup;
            }
cout<<"Enter Date Admitted";
gets(dateadmitted);
cout<<"Enter Date Discharged";
gets(datedischarged);
cout<<"Enter the initial bill charge";
cin>>bill;
	}

/**************************************
 *   Following is a member function of the class patient, which calculates bill for a patient.          *
 **************************************/

void patient::calcbill()
	{
		clrscr();	
		int total;
		cout << "*******************************************************************************";
		cout<< "\n\n\t\t\t\tPatient Fee Charge\n\n ";
		cout << "*******************************************************************************";
		cout << "\nHospital Room Charges :\t 3000";
		cout << "\nHospital Care Charges :\t 1000";
		cout << "\nHospital Maintaince Charges:\t 750";
		cout << "\nPatient Individual Charges:\t " << bill;
		total = 3000 + 1000 + 750 + bill;
		cout << "\nTotal Fee Charge:\t" << total<<"\n";
		cout<<"********************************************************************************";
	}
/**************************************
 *   Following  function writes one patient record in a binary  file.    *
*************************************/
void write_to_file()
	{
		ofstream file("PATIENT.DAT",ios::binary);
		patient s;
		char ch;
		do
		{
			s.get_data();
			file.write((char*)&s,sizeof(s));
			cout<<"y/n"<<endl;
			cin>>ch;
		}
		while(ch=='y');
		file.close();
  	}
/**************************************
 *   Following function inserts a patient record in a sorted binary file "PATIENT.DAT". The file is sorted by regno (Registration no). To do the sorting, records are read from file "PATIENT.DAT" and written to a file "temp.dat" till right position for the new record is found. After inserting the new record in the right position, the function writes the rest of the records from the file "PATIENT.DAT" to "temp.dat". Finally the function deletes "PATIENT.DAT"and renames "temp.dat" to "PATIENT.DAT". In case "PATIENT.DAT" does not exist, the function creates the file "PATIENT.DAT and writes the record.                                                                                  *
*************************************/
void add_patient_details()
{
int write_flag = 0;
patient s_in, s_out;
fstream fin, fout;
fin.open("PATIENT.DAT", ios::in|ios::binary|ios::out);
int length;
fin.seekg(0, ios::end);
length = fin.tellg();
if ( length == 0 )
{
	s_in.get_data();
             	fin.write((char*)&s_in, sizeof(s_in));
               fin.close();
}
else
{
	fin.seekg(0);
s_in.get_data();
fout.open("temp.dat", ios::out|ios::binary);
fin.read((char*)&s_out, sizeof(s_out));
while(!fin.eof())
              		 	{
if(s_in.get_regno() == s_out.get_regno())
                   		 {
cout<<endl<< " ** Patient Record with This Registration No. Already Exists ** ";
fout.close();	
fin.close();
remove("temp.dat");
return;
                   		 }
if ((write_flag == 0)&&(s_in.get_regno() <s_out.get_regno()))
                    		{
fout.write((char*)&s_in, sizeof(s_in));
fout.write((char*)&s_out, sizeof(s_out));
write_flag = 1;
                    		}
else
                    		{
fout.write((char*)&s_out, sizeof(s_out));
                   		 }
fin.read((char*)&s_out, sizeof(s_out));
               	 }
if(write_flag == 0)
fout.write((char*)&s_in, sizeof(s_in));
fout.close();
fin.close();
remove("PATIENT.DAT");
rename("temp.dat", "PATIENT.DAT");
		}
            	}

/*************************************************** 
 *   Following function takes Registration No as input from user and searches and displays a patient record by regno.*
 *   in a sorted binary file "PATIENT.DAT". This function uses "patient" class member function "display()" to display     *
 *   patient record on the screen.  *
*************************************/
void search_patient_details_by_reg_no()
{
            		fstream f;
            		patient s;
            		int sregno;
            		int found = 0;
            		f.open("PATIENT.DAT", ios::in|ios::binary);
            		int length;
f.seekg(0, ios::end);
length = f.tellg();
if ( length == 0 )
            		{
                		cout << "**** PATIENT.DAT doesn't exist ****" << endl;
            		}
            		else
            		{
			f.seekg(0);
                		cout << endl << "Enter Registration No to be Searched : ";
                		cin >> sregno;
                		f.read((char*)&s, sizeof(s));
                		while(!f.eof())
                		{
                    			if (sregno == s.get_regno())
                    			{
                        				s.display();
                        				found = 1;
                        				break;
                   			}
                    			f.read((char*)&s, sizeof(s));
                		}
                		if(!found)
                		{
                    			cout << endl << " **** Patient Record Not Found **** " << endl;
                		}
            		}
            		f.close();
        	}

/*************************************************** 
 *   Following function takes reg no as input from user and modifies a patient record with that reg no in a sorted  *
 *   binary file "PATIENT.DAT". This function uses "modify_data" class member function.   *
*************************************/
void modify_patient_details_by_reg_no()
{
    		fstream f;
            		patient s;
            		int sregno;
            		int found = 0;
            		long pos;
            		f.open("PATIENT.DAT", ios::in|ios::out|ios::binary);
            		int length;
f.seekg(0, ios::end);
length = f.tellg();
if ( length == 0 )
{
 cout << endl<< " **** PATIENT.DAT doesn't exist **** " << endl;
            		}
            		else
            		{
                		f.seekg(0);
cout << endl << "Enter Registration No of Patient Whose Details To Be Modified: ";
                		cin >> sregno;
                		f.read((char*)&s, sizeof(s));
                		while(!f.eof())
                		{
                    			if ((found == 0) && (sregno == s.get_regno()))
                    			{
								pos = f.tellg();
                        				s.modify_data();
                        				f.seekp(pos-sizeof(s));
                        				f.write((char *)&s, sizeof(s));
                        				found = 1;
                    			}
                    	}
                		if(!found)
                		{
                    			cout << endl <<" **** Patient Record Not Found **** " << endl;
                		}
            		}
            		f.close();
        	}

/*************************************************** 
 *   Following function takes registration number as input from user and modifies a patient record with that registration no in a sorted  *
 *   binary file "PATIENT.DAT". This function uses "modify_data" class member function.                                   *
*************************************/
void calculate_patient_bill_by_reg_no()
{
fstream f;
patient s;
int sregno;
int found = 0;
long pos;
f.open("PATIENT.DAT",ios::in|ios::out|ios::binary);
int length;
f.seekg(0, ios::end);
length = f.tellg();
if ( length == 0 )
{
	cout << endl<< " **** PATIENT.DAT doesn't exist **** " << endl;
}
else
{
	f.seekg(0);
cout<<endl<< "Enter Registration No of Patient Whose Bill is To Be Calculated: ";
cin>>sregno;
pos = f.tellg();
f.read((char*)&s, sizeof(s));
while(!f.eof())
                	{
if ((found == 0) && (sregno == s.get_regno()))
                    		{
s.calcbill();
f.seekp(pos);
f.write((char *)&s, sizeof(s));
found = 1;
                    		}
pos = f.tellg();
f.read((char*)&s, sizeof(s));
                	}
if(!found)
                	{
cout<<endl<<" **** Patient Record Not Found **** " <<endl;
                	}
f.close();
        	}
}


/*************************************************** 
 *   Following function takes reg no as input from user and deletes a patient record with that reg no in a sorted   *
 *   binary file "PATIENT.DAT". Records are read from file "PATIENT.DAT" and written to a file "temp.dat" till            *
 *   record is found. Based on the confirmation from user either the record is written to "temp.dat" or not               *
 *   written (deleted). The rest of the records from the file "PATIENT.DAT" to "temp.dat". Finally the function deletes   *
 *   "PATIENT.DAT" and renames "temp.dat" to "PATIENT.DAT".                                                               *
*************************************/
void delete_patient_details_by_reg_no()
{
            		int found = 0,sregno;
            		char confirm = 'n';
            		patient s;
            		fstream fin, fout;
            		fin.open("PATIENT.DAT", ios::in|ios::binary);
int length;
fin.seekg(0, ios::end);
length = fin.tellg();
if ( length == 0 )
{
cout << endl<< " **** PATIENT.DAT doesn't exist **** " << endl;
            		}
            		else
            		{
			fin.seekg(0);
                		cout << endl << "Enter Registration No of Patient Whose Details To Be Deleted: ";
                		cin >> sregno;
                		fout.open("temp.dat", ios::out|ios::binary);
                		fin.read((char*)&s, sizeof(s));
                		while(!fin.eof())
                		{
                    			if(s.get_regno() == sregno)
                    			{
                        				found = 1;
                        				cout << endl;
                        				s.display();
                        				cout << endl << "Are you sure you want to delete the record? (y/n): ";
                        				cin >> confirm;
                        				if (confirm == 'n')
                           					fout.write((char*)&s, sizeof(s));
                    			}
                    			else
                    			{
                        				fout.write((char*)&s, sizeof(s));
                    			}
                    			fin.read((char*)&s, sizeof(s));
                		}
                		if(found == 0)
                    		cout << endl << " **** Patient Record Not Found **** " << endl;
                		fout.close();
                		fin.close();
                		remove("PATIENT.DAT");
                		rename("temp.dat", "PATIENT.DAT");
            		}
        	}
        	
/***************************************************  
*   This is the main() function which drives the menu for user choice. It uses a case statement to call various   *
 *   relevant functions.    *                                                                                              **************************************/
void main()
{
int choice;
do
    		{
cout<<endl;
cout<< "           Menu" <<endl;
cout<< "           ----" <<endl;
cout<< "1.Add New Patient Details" <<endl;
cout<< "2.Display Existing Patient Details By Registration No" <<endl;
cout<< "3.Modify Patient Details by Registration No" <<endl;
cout<< "4.Delete Patient Details by Registration No" <<endl;
cout<< "5.Calculate Patient Bill by Registration No" <<endl;
cout<< "6.Display All Patient Details" <<endl;
cout<< "7.Exit" <<endl<<endl;
cout<< "Enter Choice : ";
cin>> choice;
switch (choice)
{
case 1 :
	clrscr();
add_patient_details();
break;
case 2 :
	clrscr();
search_patient_details_by_reg_no();
break;
case 3:
	clrscr();
modify_patient_details_by_reg_no();
break;
case 4:
	clrscr();
delete_patient_details_by_reg_no();
break;
				case 5:
					clrscr();
calculate_patient_bill_by_reg_no();
break;
case 6:
	clrscr();
display_all_patient_details();
break;
case 7:
break;
default:
cout<< "Invalid Choice" <<endl;
    			}    
}
while (choice != 7);
	}
