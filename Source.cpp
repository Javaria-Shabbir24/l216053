#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;
int size1 = 4;
/******************CODE FOR LESCO EMPLOYEES ****************************/

/*function of activities of employees*/
void add_customer()
{
	int random = 0;
		int ask = 0;
	ofstream fout;
	fout.open("CustomerSample");
	cout << "Enter if you want to add new customer";
	cin >> ask;
	if (ask == 1)
	{
		/*ifstream read;
		ofstream wwrite;
		char coma=',';
		size1 = size1 + 1;
		int* entry=new int[size1];
		int* pass=new int[size1];
		string name;
		string address;
		string phone;
		string type ;
		string phase;
		string date ;
		int *hours = new int[size1];
		int *peek = new int[size1];
		read.open("CustomerInfo.txt");
		wwrite.open("Customersample.txt");
		int i = 0;
		for (; i < size1-1; i++)
		{
				read >> entry[i];
				wwrite << entry[i] << " ";
				read >> coma;
				wwrite << coma << " ";
				read >> pass[i];
				wwrite << pass[i] << " ";
				read >> coma;
				wwrite << coma << " ";
				read >> name;
				wwrite << name<<" ";
				read >> coma;
				wwrite << coma << " ";
				read >> address;
				wwrite << address<<" ";
				read >> coma;
				wwrite << coma << " ";
				read >> phone;
				wwrite << phone<<" ";
				read >> coma;
				wwrite << coma << " ";
				read >> type;
				wwrite << type<<" ";
				read >> coma;
				wwrite << coma << " ";
				read >> phase[i];
				wwrite << phase << " ";
				read >> coma;
				wwrite << coma << " ";
				read >> date;
				wwrite << date << " ";
				read >> coma;
				wwrite << coma << " ";
				read >> hours[i];
				wwrite << hours[i] << " ";
				read >> coma;
				wwrite << coma << " ";
				read >> peek[i];
				wwrite << peek[i] << " ";
		}
		cout << "Enter the id of the customer : ";
		cin >> entry[i];
		cout << endl;
		cout << "Enter the cnic of the customer : ";
		cin >> pass[i];
		cout << endl;
		cout << "Enter the name of the customer : ";
		cin >> name[i];
		cout << endl;
		cout << "Enter the address of the customer : ";
		cin >> address[i];
		cout << endl;
		cout << "Enter the phoneno of the customer : ";
		cin >> phone[i];
		cout << endl;
		cout << "Enter the type of the customer : ";
		cin >> type[i];
		cout << endl;
		cout << "Enter the phasetype of the customer : ";
		cin >> phase[i];
		cout << endl;
		cout << "Enter the dateofconnection of the customer : ";
		cin >> date[i];
		cout << endl;
		cout << "Enter the regular units consumed by the customer : ";
		cin >> hours[i];
		cout << endl;
		cout << "Enter the peek hours units consumed by the customer : ";
		cin >> peek[i];
		cout << endl;
			wwrite << entry[i] << " ";
			wwrite << coma << " ";
			wwrite << pass[i] << " ";
			wwrite << coma << " ";
			wwrite << name << " ";
			wwrite << coma << " ";
			wwrite << address[i] << " ";
			wwrite << coma << " ";
			wwrite << phone[i] << " ";
			wwrite << coma << " ";
			wwrite << type[i] << " ";
			wwrite << coma << " ";
			wwrite << phase[i] << " ";
			wwrite << coma << " ";
			wwrite << date[i] << " ";
			wwrite << coma << " ";
			wwrite << hours[i] << " ";
			wwrite << coma << " ";
			wwrite << peek[i] << " ";
			wwrite << endl;*/
	}
}


void install_meter()
{
	ifstream fin;
	int cnic;
	fin.open("NADRADB.txt");
	int* id = new int[size1];
	int* issuedate = new int[size1];
	int* expirydate = new int[size1];
	int count = 0;
	cout << "Enter your cnic number : ";
	cin >> cnic;
	for (int i = 0; i < size1; i++)
	{
		fin >> id[i];
		fin >> issuedate[i];
		fin >> expirydate[i];
		if (id[i] == cnic)
		{
			count++;
		}
	}
	if (count < 3)
	{
		add_customer();
	}
	else
	{
		cout << "Already registered three metres " << endl;
	}
}

void view_bil()
{
	ifstream Cin;
	ofstream Cout;
	char get[90];
	char id[5];
	int customers_n = 0;
	Cin.open("billinginfo.txt", ios::in);
	while (Cin.getline(get, 90))
	{
		customers_n++;
	}
	Cin.close();
	char** list = NULL;
	list = new char* [customers_n];
	for (int i = 0; i < customers_n; i++)
	{
		list[i] = new char[90];
	}
	Cin.open("billinginfo.txt", ios::in);
	for (int i = 0; i < customers_n; i++)
	{
		Cin.getline(list[i], 90);
	}

	bool flag = 0;
	cout << "Enter customer Id: ";
	while (1)
	{
		cin.getline(id, 5);
		for (int i = 0; i < customers_n; i++)
		{
			if (list[i][0] == id[i])
			{
				for (int j = 0; j < size1; j++)
				{
					if (list[i][j] != id[j])
					{
						flag = 0;
						break;
					}
					else {
						flag = 1;
					}
				}
			}
		}
		if (flag)
		{
			break;
		}
		else {
			cout << " Id not found." << endl;
			cout << "Re-enter Id: ";
		}
	}
	int m = 0;
	for (int i = 0; i < customers_n; i++)
	{
		if (list[i][0] == id[0]) {
			m = i;
			break;
		}
	}
	int p = 0;
	cout << "Your  Bill is: ";
	for (int i = 0; list[m][i] != '\0'; i++)
	{
		if (list[m][i] == ',')
		{
			p++;
			if (p == 8)
			{
				for (int j = i + 1; list[m][j] != ','; j++) {
					cout << list[m][j];
				}
			}
		}
	}
	cout << endl;
	Cin.close();
}

void chargebill() {
	int* iddd = new int[4]; int si = -44;
	ifstream idread;
	char commmmma;
	int* curreentt = new int[4];
	int* peeeaaakk = new int[4];
	string* month = new string[4];
	int* coe = new int[4];
	int* tax = new int[4];
	int* fixed = new int[4];
	int* total = new int[4];
	string* date = new string[4];
	string* date2 = new string[4];
	string* status = new string[4];
	while (99) {
		cout << "Enter User ID to charge bill: \n";
		int id;
		cin >> id;
		if (id <= 1000 && id >= 9999) {
			cout << "Enter Valid ID:(\n";
		}
		idread.open("billinginfo.txt");
		for (int p = 0; p < size1; p++) {
			idread >> iddd[p];
			idread >> commmmma;
			idread >> month[p]; //month
			idread >> commmmma;
			idread >> curreentt[p]; // reg
			idread >> commmmma;
			idread >> peeeaaakk[p]; // peak
			idread >> commmmma;
			idread >> date[p]; // date
			idread >> commmmma;
			idread >> coe[p]; // coe
			idread >> commmmma;
			idread >> tax[p]; // tax
			idread >> commmmma;
			idread >> fixed[p]; // fixed
			idread >> commmmma;
			idread >> total[p]; // total
			idread >> commmmma;
			idread >> date2[p]; // datte
			idread >> commmmma;
			idread >> status[p]; // status
		}
		bool flag = false; int indexxx = -33;
		for (int ii = 0; ii < 4; ii++) {
			if (id == iddd[ii]) {
				si = iddd[ii];
				flag = true;
				indexxx = ii;
			}
		}
		if (si == -44) {
			cout << "User Not Found\n";
		}
		if (flag) {
			cout << "Enter new units: & Peak units: \n";
			int unittt; int unit2=0;
			cin >> unittt;
			cin >> unit2;
			curreentt[indexxx] = unittt;
			peeeaaakk[indexxx] = unit2;
			break;
		}
		idread.close();
	}
	ofstream idwrite;
	idwrite.open("billinginfo.txt");
	for (int p = 0; p < size1; p++) {
		idwrite << iddd[p];
		idwrite << " , ";
		idwrite << month[p]; //month
		idwrite << " , ";
		idwrite << curreentt[p]; // reg
		idwrite << " , ";
		idwrite << peeeaaakk[p]; // peak
		idwrite << " , ";
		idwrite << date[p]; // date
		idwrite << " , ";
		idwrite << coe[p]; // coe
		idwrite << " , ";
		idwrite << tax[p]; // tax
		idwrite << " , ";
		idwrite << fixed[p]; // fixed
		idwrite << " , ";
		idwrite << total[p]; // total
		idwrite << " , ";
		idwrite << date2[p]; // datte
		idwrite << " , ";
		idwrite << status[p]; // status
		idwrite << endl;
	}
}
void enter_customerinformation()
{
	/*srand(time(0));*/
	int random;

	//each row represents 1 customers whole detail
	//and we are starting with 4 customers
	ofstream fout;
	fout.open("Customerfile.txt");
	if (!fout)
	{
		cout << "Not opened";
	}
	string arr[4][10] = {};
	cout << "Enter the customer details : " << endl << endl;
	for (int i = 0; i < size1; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (j == 1)
			{
				cout << "Enter the cnic number of customer (13 digits) " << i + 1 << " : ";
				while (arr[i][j].size() != 13)
				{
					cin >> arr[i][j];
					if (arr[i][j].size() < 13 || arr[i][j].size() > 13)
					{
						cout << "invalid input,enter again : " << endl;

					}
				}
			}
			else if (j == 1)
			{
				cout << "Enter the name of customer  " << i + 1 << " :";
				cin >> arr[i][j];
			}
			else if (j == 2)
			{
				cout << "Enter the address of customer " << i + 1 << " :";
				cin >> arr[i][j];
			}
			else if (j == 3)
			{
				cout << "Enter the phone number of customer  " << i + 1 << " :";
				cin >> arr[i][j];
			}
			else if (j == 4)
			{
				cout << "Enter the customer's type (DOMESTIC/COMMERCIAL) : ";
				cin >> arr[i][j];
			}
			else if (j == 5)
			{
				cout << "Enter the customer's METER TYPE ( S-PHASE / T-PHASE) : ";
				cin >> arr[i][j];
			}
			else if (j == 6)
			{
				cout << "Enter the connection date in the format (dd/mm/yyyy): ";
				cin >> arr[i][j];
			}
			else if (j == 7)
			{
				cout << "Enter the customer's regular units consumed : ";
				cin >> arr[i][j];
			}
			else if (j == 8)
			{
				cout << "Enter the customer's peak hour units consumed : ";
				cin >> arr[i][j];
			}
		}
		cout << endl;
	}
	for (int i = 0; i < 4; i++)
	{
		random = (rand() % 9999) + 1000;
		fout << random;
		fout << ",";
		int j = 1;
		for (; j < 9; j++)
		{
			fout << arr[i][j] << " , ";
		}
		fout << arr[i][j];
		fout << endl;
	}
	fout.close();
}
void regularhourunits_price()
{
	ifstream fin;
	ofstream fout;
	int array[100], array1[100], array2[100], array3[100];
	fin.open("TariffTaxInfo.txt");
	fout.open("taxnew.txt");
	int regularhours;
	string phase_type;
	char comma;
	char customertype;
	char phasetype1;
	cout << "Select the customer type ";
	cout << endl;
	cout << "1.Press d for domestic type";
	cout << endl;
	cout << "2.Press c for commercial type";
	cout << endl;
	cout << "The customer type is : ";
	cin >> customertype;
	cout << "Select the phase type ";
	cout << endl;
	cout << "1.Press s for single phase type";
	cout << endl;
	cout << "2.Press t for three phase type";
	cout << endl;
	cout << "The phase type is : ";
	cin >> phasetype1;
	cout << "Enter the new price of regular hour units : " << endl;
	cin >> regularhours;
	int j = 0;
	for (int i = 0; i < size1; i++)
	{
		fin >> phase_type;
		fout << phase_type << " ";
		fin >> comma;
		fout << comma << " ";
		if (customertype == 'd'&& phasetype1=='s')
		{
			if (j == 0)
			{
				fin >> array[j];
				array[j] = regularhours;
				fout << array[j] << " ";
			}
			else
			{
				fin >> array[j];
				fout << array[j] << " ";
			}
		}
		else if (customertype == 'c' && phasetype1 == 's')
		{
			if (j == 1)
			{
				fin >> array[j];
				array[j] = regularhours;
				fout << array[j] << " ";
			}
			else
			{
				fin >> array[j];
				fout << array[j] << " ";
			}
		}
		else if (customertype == 'd' && phasetype1 == 't')
		{
			if (j == 2)
			{
				fin >> array[j];
				array[j] = regularhours;
				fout << array[j] << " ";
			}
			else
			{
				fin >> array[j];
				fout << array[j] << " ";
			}
		}
		else if (customertype == 'c' && phasetype1 == 't')
		{
			if (j == 3)
			{
				fin >> array[j];
				array[j] = regularhours;
				fout << array[j] << " ";
			}
			else
			{
				fin >> array[j];
				fout << array[j] << " ";
			}
		}
		fin >> comma;
		fout << comma << " ";
		fin >> array1[j];
		fout << array1[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array2[j];
		fout << array2[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array3[j];
		fout << array3[j] << " ";
		fout << endl;
		j++;
	}
	fin.close();
	fout.close();
	
	fin.open("taxnew.txt");
	fout.open("TariffTaxInfo.txt");
	for (int i = 0; i < size1; i++)
	{
		fin >> phase_type;
		fout << phase_type << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array[j];
		fout << array[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array1[j];
		fout << array1[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array2[j];
		fout << array2[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array3[j];
		fout << array3[j] << " ";
		fout << endl;
		j++;
	}
	fout.close();
	fin.close();
}
void peakhourunits_price()
{
	ifstream fin;
	ofstream fout;
	int array[100], array1[100], array2[100], array3[100];
	fin.open("TariffTaxInfo.txt");
	fout.open("taxnew.txt");
	int peakhours;
	string phase_type;
	char comma;
	char customertype;
	cout << "Select the customer type ";
	cout << endl;
	cout << "1.Press d for domestic type";
	cout << endl;
	cout << "2.Press c for commercial type";
	cout << endl;
	cout << "The customer type is : ";
	cin >> customertype;
	cout << "Enter the new price of peak hour units : " << endl;
	cin >> peakhours;
	int j = 0;
	for (int i = 0; i < size1; i++)
	{
		fin >> phase_type;
		fout << phase_type << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array[j];
		fout << array[j] << " ";
		fin >> comma;
		fout << comma << " ";
		if (customertype == 'd')
		{
			if (j == 2)
			{
				fin >> array1[j];
				array1[j] = peakhours;
				fout << array1[j] << " ";
			}
			else
			{
				fin >> array1[j];
				fout << array1[j] << " ";
			}
		}
		else if (customertype == 'c')
		{
			if (j == 3)
			{
				fin >> array1[j];
				array1[j] = peakhours;
				fout << array1[j] << " ";
			}
			else
			{
				fin >> array1[j];
				fout << array1[j] << " ";
			}
		}
		fin >> comma;
		fout << comma << " ";
		fin >> array2[j];
		fout << array2[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array3[j];
		fout << array3[j] << " ";
		fout << endl;
		j++;
	}

	fout.close();
	fin.close();
	fin.open("taxnew.txt");
	fout.open("TariffTaxInfo.txt");
	for (int i = 0; i < 4; i++)
	{
		fin >> phase_type;
		fout << phase_type << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array[j];
		fout << array[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array1[j];
		fout << array1[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array2[j];
		fout << array2[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array3[j];
		fout << array3[j] << " ";
		fout << endl;
		j++;
	}
	fout.close();
	fin.close();
}
void update_fixedcharges()
{
	ifstream fin;
	ofstream fout;
	int array[100], array1[100], array2[100], array3[100];
	fin.open("TariffTaxInfo.txt");
	fout.open("taxnew.txt");
	int fixed_charges;
	string phase_type;
	char comma;
	char customertype;
	cout << "Select the customer type ";
	cout << endl;
	cout << "1.Press d for domestic type";
	cout << endl;
	cout << "2.Press c for commercial type";
	cout << endl;
	cout << "The customer type is : ";
	cin >> customertype;
	cout << "Enter the new value of fixed charges  " << endl;
	cin >> fixed_charges;
	int j = 0;
	for (int i = 0; i < size1; i++)
	{
		fin >> phase_type;
		fout << phase_type << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array[j];
		fout << array[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array1[j];
		fout << array1[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array2[j];
		fout << array2[j] << " ";
		fin >> comma;
		fout << comma << " ";
		if (customertype == 'd')
		{
			if (j == 0 || j == 2)
			{
				fin >> array3[j];
				array3[j] = fixed_charges;
				fout << array3[j] << " ";
			}
			else
			{
				fin >> array3[j];
				fout << array3[j] << " ";
			}
		}
		else if (customertype == 'c')
		{
			if (j == 1 || j == 3)
			{
				fin >> array3[j];
				array3[j] = fixed_charges;
				fout << array3[j] << " ";
			}
			else
			{
				fin >> array3[j];
				fout << array3[j] << " ";
			}
		}
		
		fout << endl;
		j++;
	}
	fout.close();
	fin.close();
	fin.open("taxnew.txt");
	fout.open("TariffTaxInfo.txt");
	for (int i = 0; i < 4; i++)
	{
		fin >> phase_type;
		fout << phase_type << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array[j];
		fout << array[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array1[j];
		fout << array1[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array2[j];
		fout << array2[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array3[j];
		fout << array3[j] << " ";
		fout << endl;
		j++;
	}
	fout.close();
	fin.close();
}

void update_tax()
{
	ifstream fin;
	ofstream fout;
	int array[100],array1[100],array2[100],array3[100];
	fin.open("TariffTaxInfo.txt");
	fout.open("taxnew.txt");
	int tax;
	string phase_type;
	char comma;
	char customertype;
	cout << "Select the customer type ";
	cout << endl;
	cout << "1.Press d for domestic type";
	cout << endl;
	cout << "2.Press c for commercial type";
	cout << endl;
	cin >> customertype;
	cout << "Enter the new value of tax " << endl;
	cin >> tax;
	int j = 0;
	for (int i = 0; i < size1; i++)
	{
		fin >> phase_type;
		fout << phase_type<<" ";
		fin >> comma;
		fout << comma << " ";
		fin >> array[j];
		fout << array[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array1[j];
		fout << array1[j] << " ";
		fin >> comma;
		fout << comma << " ";
		if (customertype == 'd')
		{
			if (j == 0 || j == 2)
			{
				fin >> array2[j];
				array2[j] = tax;
				fout << array2[j] << " ";
			}
			else
			{
				fin >> array2[j];
				fout << array2[j] << " ";
			}
		}
		else if (customertype == 'c')
		{
			if (j == 1 || j == 3)
			{
				fin >> array2[j];
				array2[j] = tax;
				fout << array2[j] << " ";
			}
			else
			{
				fin >> array2[j];
				fout << array2[j] << " ";
			}
		}
		fin >> comma;
		fout << comma << " ";
		fin >> array3[j];
		fout << array3[j] << " ";
		fout << endl;
		j++;
	}
	fout.close();
	fin.close();
	fin.open("taxnew.txt");
	fout.open("TariffTaxInfo.txt");
	for (int i = 0; i < size1; i++)
	{
		fin >> phase_type;
		fout << phase_type << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array[j];
		fout << array[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array1[j];
		fout << array1[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array2[j];
		fout << array2[j] << " ";
		fin >> comma;
		fout << comma << " ";
		fin >> array3[j];
		fout << array3[j] << " ";
		fout << endl;
		j++;
	}
	fout.close();
	fin.close();
}

/*function for display of employees's activities*/
void select()
{
	cout << endl;
	cout << "What activity do you want to perform ? Select its number " << endl;
	cout << "1.View the bill";
	cout << endl;
	cout << "2.Update tax";
	cout << endl;
	cout << "3.Update fixed charges ";
	cout << endl;
	cout << "4.Change peak hour units price  ";
	cout << endl;
	cout << "5.Change regular hour units price  ";
	cout << endl;
	cout << "6.Enter customer's all information in a file ";
	cout << endl;
	cout << "7. Add a customer";
	cout << endl;
	cout << "8. Charge bill";
	cout << endl;
}
/*login function for employees*/
void login_employees()
{
	select();
	int entry;
	cin >> entry;
	 if (entry == 1)
	{
		view_bil();
	}
	else if (entry == 2)
	{
		update_tax();
	}
	else if (entry == 3)
	{
		update_fixedcharges();
	}
	else if (entry == 4)
	{
		peakhourunits_price();
	}
	else if (entry == 5)
	{
		regularhourunits_price();
	}
	else if (entry == 6)
	{
		enter_customerinformation();
	}
	else if (entry == 7)
	{
		install_meter();
	}
	else if (entry == 8)
	{
		chargebill();
	}
	else
	{
		cout << endl << "Select a valid number " << endl;
		login_employees();
	}

}
/*input function for employees*/
void Employee()
{
	ifstream fin;
	ofstream fout;
	char username[25];
	char password[25];
	char new_password[25];
	int f=0;
	char check;
	string word;
	string word2;
	int count = 0;
	fin.open("EmployeesData.txt");
	fout.open("Employeenew.txt");
	cout << endl << "Enter your username : " << endl;
	cin >> username;
	cout << endl << "Enter your password : " << endl;
	cin >> password;
	/* check if the username and passwords are valid or not */
	while (!fin.eof() && f < 5)
	{
		fin >> word;
		fin >> check;
		fin >> word2;
		if (username == word && password == word2)
		{
			break;
		}
		f++;
	}
	if (f == 5)
	{
		cout << endl << "INVALID INPUTS " << endl;
		cout << "ENTER THE INFORMATION AGAIN " << endl;
		Employee();
	}
	fin.close();
	fout.close();
	fin.open("EmployeesData.txt");
	fout.open("Employeenew.txt");
	cout << endl;
	cout << "Press  C if you want to change the password ";
	cout << endl;
	cout << "Press L if you want to login ";
	cout << endl;
		cin >> check;
		if (check == 'L' || check == 'l')
		{
			login_employees();
		}
		else if (check == 'C' || check == 'c')
		{
			/*reading from original file and writing in new file with new password*/
			int j = 0;
			while (!fin.eof()&&j<5)
			{
				j++;
				fin >> word;
				fout << word<<" ";
				if (username != word)
				{
					fin >> check;
					fout << check;
					fin >> word2;
					fout << " " << word2;
					fout << endl;
				}
				else if (username == word)
				{
					fin >> check;
					fout<< check <<" ",
					fin >> word2;
					{
						cout << endl << "Enter the new password :";
						cin >> new_password;
						fout << new_password;
						cout << endl << "Password has been changed successfully" << endl;
						fout << endl;
					}
				}
			}
			fin.close();
			fout.close();
			/*reading from new file and writing in the original file*/
			fout.open("EmployeesData.txt");
			fin.open("Employeenew.txt");
			int i = 0;
			while (!fin.eof()&& !fout.eof()&&i<5)
			{
				fin >> word;
				fout << word<<" ";
				fin >> check;
				fout << check;
				fin >> word2;
				fout <<" " << word2<<endl;
				i++;
			}
			fin.close();
			fout.close();
		}
}
/* Code for customers */
void pay(int username1)
{
	
	int* iddd = new int[4];
	ifstream idread;
	char commmmma;
	int* curreentt = new int[4];
	int* peeeaaakk = new int[4];
	string* month = new string[4];
	int* coe = new int[4];
	int* tax = new int[4];
	int* fixed = new int[4];
	int* total = new int[4];
	string* date = new string[4];
	string* date2 = new string[4];
	string* status = new string[4];
	ofstream idwrite;
	
	idread.open("billinginfo.txt");
	idwrite.open("billingnew.txt");
	for (int p = 0; p < size1; p++) {
		idread >> iddd[p]; // ID
		idread >> commmmma;
		idread >> month[p]; //month
		idread >> commmmma;
		idread >> curreentt[p]; // reg
		idread >> commmmma;
		idread >> peeeaaakk[p]; // peak
		idread >> commmmma;
		idread >> date[p]; // date
		idread >> commmmma;
		idread >> coe[p]; // coe
		idread >> commmmma;
		idread >> tax[p]; // tax
		idread >> commmmma;
		idread >> fixed[p]; // fixed
		idread >> commmmma;
		idread >> total[p]; // total
		idread >> commmmma;
		idread >> date2[p]; // datte
		idread >> commmmma;
		idread >> status[p]; // status
		if (iddd[p] == username1)
		{
			peeeaaakk[p] = 0;
			curreentt[p] = 0;
			coe[p] = 0;
			total[p] = 0;
			status[p] = "Paid";
			tax[p] = 0;

		}

		idwrite << iddd[p];
		idwrite << " , ";
		idwrite << month[p]; //month
		idwrite << " , ";
		idwrite << curreentt[p]; // reg
		idwrite << " , ";
		idwrite << peeeaaakk[p]; // peak
		idwrite << " , ";
		idwrite << date[p]; // date
		idwrite << " , ";
		idwrite << coe[p]; // coe
		idwrite << " , ";
		idwrite << tax[p]; // tax
		idwrite << " , ";
		idwrite << fixed[p]; // fixed
		idwrite << " , ";
		idwrite << total[p]; // total
		idwrite << " , ";
		idwrite << date2[p]; // datte
		idwrite << " , ";
		idwrite << status[p]; // status
		idwrite << endl;
	}
	idread.close();
	idwrite.close();
	idwrite.open("billinginfo.txt");
	idread.open("billingnew.txt");
	for (int p = 0; p < size1; p++) {
		idread >> iddd[p]; // ID
		idread >> commmmma;
		idread >> month[p]; //month
		idread >> commmmma;
		idread >> curreentt[p]; // reg
		idread >> commmmma;
		idread >> peeeaaakk[p]; // peak
		idread >> commmmma;
		idread >> date[p]; // date
		idread >> commmmma;
		idread >> coe[p]; // coe
		idread >> commmmma;
		idread >> tax[p]; // tax
		idread >> commmmma;
		idread >> fixed[p]; // fixed
		idread >> commmmma;
		idread >> total[p]; // total
		idread >> commmmma;
		idread >> date2[p]; // datte
		idread >> commmmma;
		idread >> status[p]; // status
		/*************************************/
		idwrite << iddd[p];
		idwrite << " , ";
		idwrite << month[p]; //month
		idwrite << " , ";
		idwrite << curreentt[p]; // reg
		idwrite << " , ";
		idwrite << peeeaaakk[p]; // peak
		idwrite << " , ";
		idwrite << date[p]; // date
		idwrite << " , ";
		idwrite << coe[p]; // coe
		idwrite << " , ";
		idwrite << tax[p]; // tax
		idwrite << " , ";
		idwrite << fixed[p]; // fixed
		idwrite << " , ";
		idwrite << total[p]; // total
		idwrite << " , ";
		idwrite << date2[p]; // datte
		idwrite << " , ";
		idwrite << status[p]; // status
		idwrite << endl;
		idread.close();
		idwrite.close();
	}
}
void pay_bill()
{
	int username1;
	cout <<endl<< "Enter your username : ";
	cin >> username1;
	string credit_card;
	char test;
	cout << endl << "Enter your credit card number : " << endl;
	cin >> credit_card;
	if (credit_card.size() == 16)
	{
		cout << "Do you really want to pay the bill ";
		cout << endl;
		cout << "Press y for yes and n for no " << endl;
		cin >> test;
		if (test == 'y')
		{
			pay(username1);
			cout << "Payment successful";
		}
		else if (test == 'n')
		{
			cout << "Payment not successful";
		}
	}
	else if (credit_card.size() != 16)
	{
		cout << endl << "invalid number ,enter again" << endl;
		pay_bill();
	}
	
}
void generate_bills() {
	int* iddd = new int[4];
	ifstream idread;
	ofstream idwrite;
	char commmmma;
	int* curreentt = new int[4];
	int* peeeaaakk = new int[4];
	string* month = new string[4];
	int* coe = new int[4];
	int* tax = new int[4];
	int* fixed = new int[4];
	int* total = new int[4];
	string* date = new string[4];
	string* paymentdate = new string[4];
	string* date2 = new string[4];
	string* status = new string[4];
	idread.open("billinginfo.txt");
	for (int p = 0; p < size1; p++) {
		idread >> iddd[p]; // ID
		idread >> commmmma;
		idread >> month[p]; //month
		idread >> commmmma;
		idread >> curreentt[p]; // reg
		idread >> commmmma;
		idread >> peeeaaakk[p]; // peak
		idread >> commmmma;
		idread >> date[p]; // date
		idread >> commmmma;
		idread >> coe[p]; // coe
		idread >> commmmma;
		idread >> tax[p]; // tax
		idread >> commmmma;
		idread >> fixed[p]; // fixed
		idread >> commmmma;
		idread >> total[p]; // total
		idread >> commmmma;
		idread >> date2[p]; // datte
		idread >> commmmma;
		idread >> status[p]; // status
	}
	idread.close();
	int* prevregularunits = new int[4];
	int* prevpeakunits = new int[4];
	string wastee;
	//.........................................................
	idread.open("CustomerInfo.txt");
	for (int p = 0; p < size1; p++) {
		idread >> wastee; // ID
		idread >> commmmma;
		idread >> wastee; //cnic
		idread >> commmmma;
		idread >> wastee; // name
		idread >> commmmma;
		idread >> wastee; // address
		idread >> commmmma;
		idread >> wastee; // phone
		idread >> commmmma;
		idread >> wastee; // usertype
		idread >> commmmma;
		idread >> wastee; // metretypee
		idread >> commmmma;
		idread >> wastee; // datee
		idread >> commmmma;
		idread >> prevregularunits[p]; // reg
		idread >> commmmma;
		idread >> prevpeakunits[p]; // peak
	}
	for (int p = 0; p < size1; p++) {
		coe[p] = ((curreentt[p] - prevregularunits[p]) * 18) + ((peeeaaakk[p] - prevpeakunits[p]) * 25);
		tax[p] = (coe[p]) + (coe[p] * 20) / 100;
		total[p] = coe[p] + tax[p] + fixed[p];
	}
	idread.close();

	//.........................................................
	
	idwrite.open("billinginfo.txt");
	for (int p = 0; p < size1; p++) {
		idwrite << iddd[p];
		idwrite << " , ";
		idwrite << month[p]; //month
		idwrite << " , ";
		idwrite << curreentt[p]; // reg
		idwrite << " , ";
		idwrite << peeeaaakk[p]; // peak
		idwrite << " , ";
		idwrite << date[p]; // date
		idwrite << " , ";
		idwrite << coe[p]; // coe
		idwrite << " , ";
		idwrite << tax[p]; // tax
		idwrite << " , ";
		idwrite << fixed[p]; // fixed
		idwrite << " , ";
		idwrite << total[p]; // total
		idwrite << " , ";
		idwrite << date2[p]; // datte
		idwrite << " , ";
		idwrite << status[p]<<endl; // status
	}
	idwrite.close();
}
/*Input function for customers*/
void customers()
{
	
		char num;
		cout << endl<<"Which activity do you want to perform ? Enter it's number." << endl;
		cout << "a. View bill" << endl;
		cout << "b. Pay bill" << endl;
		cout << "c. Install a new meter" << endl;
		cout << "Enter the number : " << endl;
		cin >> num;
		if (num == 'a')
		{
			view_bil();
		}
		else if (num == 'b')
		{
			pay_bill();
		}
}
void display()
{
	cout << "**********************WElCOME TO THE LESCO BILLING SYSTEM ******************************" << endl;
	cout << "**********Press C if you are a customer and E if you are an employee **********" << endl;
}
/*code to identify the user */
void menu()
{
	char enter;
	cin >> enter;
	if (enter == 'c' || enter == 'C')/*calls the customer function*/
	{
		customers();
	}
	else if (enter == 'e' || enter == 'E')/*calls the employee function*/
	{
		Employee();
	}
	else
	{
		cout << endl << "Invalid input" << endl << "Enter again" << endl;
		menu();
	}

}
int main()
{
	generate_bills();
	display();
	menu();
	system("pause");
	return 0;
}