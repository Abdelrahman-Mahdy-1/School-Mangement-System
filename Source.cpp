#include<iostream>
#include<string>
#include <cstdlib>
#include<Windows.h>
using namespace std;
struct Name
{
	string fname;
	string lname;
};
struct Data
{
	Name funame;
	string name;
	int grade;
	int id, nationalID;
	double ENG, MAth, Arabic;
	double total = ENG + MAth + Arabic;
};
struct Student
{
	Data student;
	Student* next;
};

class SchoolMangement
{
private:

	Student* top, * cur;

	void Swap(Student* temp, Student* temp2)
	{
		Data z = temp->student;
		temp->student = temp2->student;
		temp2->student = z;
	}

	string checkName(string name)
	{
		while (true)
		{

		}
	}

	int checkGrade(int x)
	{
		while (true)
		{
			if (x > 0 && x < 7)
				break;
			else
			{
				cout << endl << "Grade Must be between 1 to 6!" << endl;
				cout << "Enter Grade: ";
				cin >> x;
			}
		}
		return x;
	}

	int checkID(int x)
	{
		cur = top;
		while (cur != NULL && x == cur->student.id || x <= 0)
		{
			if(x <= 0)
			{
				cout << endl << "Write the Syntax of ID Crorcctly!" << endl;
				cout << "Enter ID: ";
				cin >> x;
			}
			else
			{
				cout << endl << "This ID is already used!" << endl;
				cout << "Enter ID: ";
				cin >> x;
			}
			cur = top;
			while (cur != NULL && x != cur->student.id)
			{
				cur = cur->next;
			}	
		}
		return x;
	}

	int checkNationalID2(int x)
	{
		cur = top;
		string sx = "";
		while (cur != NULL && x == cur->student.nationalID || x < 0 || sx.length() != 8)
		{
			sx = to_string(x);
			if (x < 0 || sx.length() != 8)
			{
				cout << endl << "Write the Syntax of National ID Crorcctly!" << endl;
				cout << "Enter National ID: ";
				cin >> x;
			}
			cur = top;
			while (cur != NULL && x != cur->student.nationalID)
			{
				cur = cur->next;
			}
		}
		return x;
	}

	int checkNationalID(int x)
	{
		Student* save = nullptr;
		Student* cur2 = top;
		bool cheack = true;
		while (true)
		{
			try
			{
				while (cur != NULL)
				{
					if (x == cur->student.nationalID)
					{
						save = cur;
						cheack = false;
						throw  "This National ID is already used!";
					}
					cur = cur->next;
				}
				if (cheack)
				{
					while (true)
					{
						string sx = to_string(x);
						if (x > -1 && sx.length() == 8)
						{
							cur = top;
							while (cur != NULL)
							{
								if (x == cur->student.nationalID)
								{
									save = cur;
									while (true)
									{
										string sx = to_string(x);
										cur2 = top;
										while (cur2 != nullptr)
										{
											if (x == cur2->student.nationalID)
											{
												save = cur2;
												break;
											}
											cur2 = cur2->next;
										}
										if (x == save->student.nationalID)
										{
											cout << endl << "This National ID is already used!" << endl;
											cout << "Enter National ID: ";
											cin >> x;
										}
										else if (x != save->student.nationalID && x < 0 || sx.length() != 8)
										{
											cout << endl << "Write the Syntax of National ID Crorcctly and should be 8 numbers!" << endl;
											cout << "Enter National ID: ";
											cin >> x;
										}
										else if (x != save->student.nationalID && x > -1 && sx.length() == 8)
											break;
									}
								}
								cur = cur->next;
							}
							break;
						}
						else
						{
							cout << endl << "Write the Syntax of National ID Crorcctly and should be 8 numbers!" << endl;
							cout << "Enter National ID: ";
							cin >> x;
							fflush(stdin);
						}
					}
					break;
				}
			}
			catch (...)
			{
				while (true)
				{
					string sx = to_string(x);
					cur = top;
					while (cur != NULL)
					{
						if (x == cur->student.nationalID)
						{
							save = cur;
							while (true)
							{
								string sx = to_string(x);
								cur2 = top;
								while (cur2 != nullptr)
								{
									if (x == cur2->student.nationalID)
									{
										save = cur2;
										break;
									}
									cur2 = cur2->next;
								}
								if (x == save->student.nationalID)
								{
									cout << endl << "This National ID is already used!" << endl;
									cout << "Enter National ID: ";
									cin >> x;
								}
								else if (x != save->student.nationalID && x < 0 || sx.length() != 8)
								{
									cout << endl << "Write the Syntax of National ID Crorcctly!" << endl;
									cout << "Enter National ID: ";
									cin >> x;
								}
								else if (x != save->student.nationalID && x > -1 && sx.length() == 8)
									break;
							}
						}
						cur = cur->next;
					}
					break;
				}
				break;
			}
		}
		return x;
	}

	double cheakMarks(double x)
	{
		while (true)
		{
			if (x >= 0 && x <= 100)
				break;
			else
			{
				cout << endl << "Mark must be between 0 to 100!" << endl;
				cout << "Enter Mark: ";
				cin >> x;
			}
		}
		return x;
	}

public:

	SchoolMangement()
	{
		top = nullptr;
	}

	void Push(Student newstudent)
	{
		cur = top;
		Student* save = new Student;
		int x = 0;
		double d = 0;
		cout << "Enter First Name: ";
		getline(cin, newstudent.student.funame.fname);
		cout << "Enter Last Name: ";
		getline(cin, newstudent.student.funame.lname);
		newstudent.student.name = newstudent.student.funame.fname + " " + newstudent.student.funame.lname;
		cout << "Enter grade of Student: ";
		cin >> x;
		fflush(stdin);
		newstudent.student.grade = checkGrade(x);
		cout << "Enter ID of Student: ";
		cin >> x;
		fflush(stdin);
		newstudent.student.id = checkID(x);
		cout << "Enter National ID of Student: ";
		cin >> x;
		fflush(stdin);
		newstudent.student.nationalID = checkNationalID2(x);
		cout << "Enter ENG Mark of Student: ";
		cin >> d;
		fflush(stdin);
		newstudent.student.ENG = cheakMarks(d);
		cout << "Enter Math Mark of Student: ";
		cin >> d;
		fflush(stdin);
		newstudent.student.MAth = cheakMarks(d);
		cout << "Enter Arabic Mark of Student: ";
		cin >> d;
		fflush(stdin);
		newstudent.student.Arabic = cheakMarks(d);
		cin.get();
		newstudent.student.total = newstudent.student.ENG + newstudent.student.MAth + newstudent.student.Arabic;
		if (isEmpty())
		{
			save->next = nullptr;
			save->student = newstudent.student;
			save->next = top;
			top = save;
		}
		else
		{
			save->student = newstudent.student;
			save->next = top;
			top = save;
		}
	}

	bool isEmpty()
	{
		return top == 0;
	}

	void Pop()
	{
		if (isEmpty())
			cout << endl << "The removal operation failed because the school is empty!" << endl;
		else
		{
			cur = top;
			top = top->next;
			cur = cur->next = 0;
			delete cur;
			cout << endl << "The removal process was completed successfully" << endl;
		}
	}

	void Print()
	{
		if (isEmpty())
			cout << endl << "Printing failed because the school is empty!";
		else
		{
			cout << "Students in School: " << endl << endl;
			cur = top;
			cout << endl << "===========================================" << endl;
			while (cur != 0)
			{
				cout << "Name of Student: " << cur->student.name << endl;
				cout << "Grade: " << cur->student.grade << endl;
				cout << "ID: " << cur->student.id << endl;
				cout << "National ID: " << cur->student.nationalID << endl;
				cout << "English Marks: " << cur->student.ENG << endl;
				cout << "Math Marks: " << cur->student.MAth << endl;
				cout << "Arabic Marks: " << cur->student.Arabic << endl;
				cout << "Total of Marks: " << cur->student.total << endl;
				cout << "===========================================" << endl;
				cur = cur->next;
			}
			cout << endl;
		}
	}

	void Print(Student* student)
	{
		cout << endl << "===========================================" << endl;
		cout << "Name of Student: " << student->student.name << endl;
		cout << "Grade: " << student->student.grade << endl;
		cout << "ID: " << student->student.id << endl;
		cout << "National ID: " << student->student.nationalID << endl;
		cout << "English Marks: " << student->student.ENG << endl;
		cout << "Math Marks: " << student->student.MAth << endl;
		cout << "Arabic Marks: " << student->student.Arabic << endl;
		cout << "Total of Marks: " << student->student.total << endl;
		cout << "===========================================" << endl;
		cout << endl;
	}

	int Size()
	{

		int size = 0;
		cur = top;
		while (cur != 0)
		{
			size++;
			cur = cur->next;
		}
		return size;
	}

	Student* LastStudent()
	{
		if (isEmpty())
			cout << "Sorry School is Empty!" << endl;
		else
			return top;
	}

	Student* MidStudent()
	{
		if (isEmpty())
			cout << "Sorry School is Empty!" << endl;
		else
		{
			int smid = 0;
			if (Size() < 5)
				smid = Size() / 2;
			else
				smid = Size() / 2 + 1;
			int count = 0;
			cur = top;
			Student* mid{};
			while (cur != nullptr)
			{
				count++;
				if (count == smid)
				{
					mid = cur;
				}
				cur = cur->next;
			}
			return mid;
		}
	}

	Student* FirstStudent()
	{
		if (isEmpty())
			cout << "Sorry School is Empty!" << endl;
		else
		{
			int count = Size();
			Student* first{};
			cur = top;
			while (cur != nullptr)
			{
				count--;
				if (count == NULL)
				{
					first = cur;
				}
				cur = cur->next;
			}
			return first;
		}
	}

	void BubbleSort()
	{
		cout << "1) Sort by name || 2) Sort by id || 3) Sort by subjectmark || 4) Sort by totalmarks" << endl;
		string var = "";
		getline(cin, var);
		Student* ptr = top;
		Student* temp = top;
		Student* temp2 = top->next;
		Data z;
		if (var == "1")
		{
			cout << "1) Descending || 2) Ascending" << endl;
			string var2 = "";
			getline(cin, var2);
			if (var2 == "1")
			{
				while (ptr != nullptr)
				{
					while (temp2 != nullptr)
					{
						if (temp->student.name < temp2->student.name)
						{
							Swap(temp, temp2);
						}
						temp = temp->next;
						temp2 = temp2->next;
					}
					temp = top;
					temp2 = top->next;
					ptr = ptr->next;
				}
			}
			else if (var2 == "2")
			{
				while (ptr != 0)
				{
					while (temp2 != 0)
					{
						if (temp->student.name > temp2->student.name)
						{
							Swap(temp, temp2);
						}
						temp = temp->next;
						temp2 = temp2->next;
					}
					temp = top;
					temp2 = top->next;
					ptr = ptr->next;
				}
			}
			else
				cout << endl << "Choose and Write What you want Corecctly!" << endl << endl;
		}

		else if (var == "2")
		{
			cout << "1) Descending || 2) Ascending" << endl;
			string var2 = "";
			getline(cin, var2);
			if (var2 == "1")
			{
				while (ptr != 0)
				{
					while (temp2 != 0)
					{
						if (temp->student.id > temp2->student.id)
						{
							Swap(temp, temp2);
						}
						temp = temp->next;
						temp2 = temp2->next;
					}
					temp = top;
					temp2 = top->next;
					ptr = ptr->next;
				}
			}
			else if (var2 == "2")
			{
				while (ptr != 0)
				{
					while (temp2 != 0)
					{
						if (temp->student.id < temp2->student.id)
						{
							Swap(temp, temp2);
						}
						temp = temp->next;
						temp2 = temp2->next;
					}
					temp = top;
					temp2 = top->next;
					ptr = ptr->next;
				}
			}
			else
				cout << endl << "Choose and Write What you want Corecctly!" << endl << endl;
		}

		else if (var == "3")
		{
			cout << "Choose: 1) English || 2) Math || 3) Arabic" << endl;
			string var2 = "";
			getline(cin, var2);
			if (var2 == "1")
			{
				cout << " 1) Descending || 2) Ascending" << endl;
				string var3 = "";
				getline(cin, var3);
				if (var3 == "1")
				{
					while (ptr != 0)
					{
						while (temp2 != 0)
						{
							if (temp->student.ENG > temp2->student.ENG)
							{
								Swap(temp, temp2);
							}
							temp = temp->next;
							temp2 = temp2->next;
						}
						temp = top;
						temp2 = top->next;
						ptr = ptr->next;
					}
				}
				else if (var3 == "2")
				{
					while (ptr != 0)
					{
						while (temp2 != 0)
						{
							if (temp->student.ENG < temp2->student.ENG)
							{
								Swap(temp, temp2);
							}
							temp = temp->next;
							temp2 = temp2->next;
						}
						temp = top;
						temp2 = top->next;
						ptr = ptr->next;
					}
				}
				else
					cout << endl << "Choose and Write What you want Corecctly!" << endl << endl;
			}
			else if (var2 == "2")
			{
				cout << "1) Descending || 2) Ascending" << endl;
				string var3 = "";
				getline(cin, var3);
				if (var3 == "1")
				{
					while (ptr != 0)
					{
						while (temp2 != 0)
						{
							if (temp->student.MAth > temp2->student.MAth)
							{
								Swap(temp, temp2);
							}
							temp = temp->next;
							temp2 = temp2->next;
						}
						temp = top;
						temp2 = top->next;
						ptr = ptr->next;
					}
				}
				else if (var3 == "2")
				{
					while (ptr != 0)
					{
						while (temp2 != 0)
						{
							if (temp->student.MAth < temp2->student.MAth)
							{
								Swap(temp, temp2);
							}
							temp = temp->next;
							temp2 = temp2->next;
						}
						temp = top;
						temp2 = top->next;
						ptr = ptr->next;
					}
				}
				else
					cout << endl << "Choose and Write What you want Corecctly!" << endl << endl;
			}
			else if (var2 == "3")
			{
				cout << "1) Descending || 2) Ascending" << endl;
				string var3 = "";
				getline(cin, var3);
				if (var3 == "1")
				{
					while (ptr != 0)
					{
						while (temp2 != 0)
						{
							if (temp->student.Arabic > temp2->student.Arabic)
							{
								Swap(temp, temp2);
							}
							temp = temp->next;
							temp2 = temp2->next;
						}
						temp = top;
						temp2 = top->next;
						ptr = ptr->next;
					}
				}
				else if (var3 == "2")
				{
					while (ptr != 0)
					{
						while (temp2 != 0)
						{
							if (temp->student.Arabic < temp2->student.Arabic)
							{
								Swap(temp, temp2);
							}
							temp = temp->next;
							temp2 = temp2->next;
						}
						temp = top;
						temp2 = top->next;
						ptr = ptr->next;
					}
				}
				else
					cout << endl << "Choose and Write What you want Corecctly!" << endl << endl;
			}
			else
				cout << endl << "Choose and Write What you want Corecctly!" << endl << endl;
		}
		else if (var == "4")
		{
			cout << "1) Descending || 2) Ascending" << endl;
			string var3 = "";
			getline(cin, var3);
			if (var3 == "1")
			{
				while (ptr != 0)
				{
					while (temp2 != 0)
					{
						if (temp->student.total > temp2->student.total)
						{
							Swap(temp, temp2);
						}
						temp = temp->next;
						temp2 = temp2->next;
					}
					temp = top;
					temp2 = top->next;
					ptr = ptr->next;
				}
			}

			else if (var3 == "2")
			{
				while (ptr != 0)
				{
					while (temp2 != 0)
					{
						if (temp->student.total < temp2->student.total)
						{
							Swap(temp, temp2);
						}
						temp = temp->next;
						temp2 = temp2->next;
					}
					temp = top;
					temp2 = top->next;
					ptr = ptr->next;
				}
			}
			else
				cout << endl << "Choose and Write What you want Corecctly!" << endl << endl;
		}
		else
			cout << endl << "Choose and Write What you want Corecctly!" << endl << endl;
	}

	void BubbleSort(string var)
	{
		Student* ptr = top;
		Student* temp = top;
		Student* temp2 = top->next;
		Data z;
		if (var == "1")
		{
			while (ptr != 0)
			{
				while (temp2 != 0)
				{
					if (temp->student.name < temp2->student.name)
					{
						Swap(temp, temp2);
					}	
					temp = temp->next;
					temp2 = temp2->next;
				}
				temp = top;
				temp2 = top->next;
				ptr = ptr->next;
			}
		}
		else if (var == "2")
		{
			while (ptr != 0)
			{
				while (temp2 != 0)
				{
					if (temp->student.id < temp2->student.id)
					{
						Swap(temp, temp2);
					}
					temp = temp->next;
					temp2 = temp2->next;
				}
				temp = top;
				temp2 = top->next;
				ptr = ptr->next;
			}
		}
		else if (var == "3")
		{
			while (ptr != 0)
			{
				while (temp2 != 0)
				{
					if (temp->student.nationalID < temp2->student.nationalID)
					{
						Swap(temp, temp2);
					}
					temp = temp->next;
					temp2 = temp2->next;
				}
				temp = top;
				temp2 = top->next;
				ptr = ptr->next;
			}
		}
		else
			cout << endl << "Choose and Write What you want Corecctly!" << endl << endl;
	}

	void LinerSearch()
	{
		cout << "1) Search by Name || 2) Search by ID || 3) Search by National ID " << endl;
		string str = "";
		getline(cin, str);
		bool found = false;
		if (str == "1")
		{
			if (isEmpty())
				cout << "School is Empty!!" << endl << endl;
			else
			{
				cout << "Enter the name of student: ";
				string name = "";
				getline(cin, name);
				cur = top;
				while (cur != nullptr)
				{
					if (name == cur->student.name && name.length() == cur->student.name.length())
					{
						Print(cur);
						found = true;
					}
					else if (name.length() < 2)
					{
						for (size_t i = 0; i < name.length(); i++)
						{
							if (toupper(name[i]) == cur->student.name[i])
							{
								Print(cur);
								found = true;
								break;
							}
						}
					}
					else if (name.length() < cur->student.name.length())
					{
						if (name.length() > 4)
						{
							for (int i = name.length() - 2; i > name.length() - 3; i--)
							{
								if (name[i] == cur->student.name[i])
								{
									Print(cur);
									found = true;
									break;
								}
							}
						}
						else
						{
							for (int i = name.length() - 1; i > name.length() - 2; i--)
							{
								if (name[i] == cur->student.name[i])
								{
									Print(cur);
									found = true;
									break;
								}
							}
						}
					}
					cur = cur->next;
				}
				if (!found)
					cout << endl << "There is no student with this name!" << endl << endl;
			}
		}
		else if (str == "2")
		{
			if (isEmpty())
				cout << "School is Empty!!" << endl << endl;
			else
			{
				cout << "Enter the ID of student: ";
				int id = 0;
				cin >> id;
				fflush(stdin);
				cin.get();
				cur = top;
				while (cur != nullptr)
				{
					if (id == cur->student.id)
					{
						Print(cur);
						found = true;
						break;
					}
					cur = cur->next;
				}
				if (!found)
					cout << endl << "There is no student with this ID!" << endl << endl;
			}
		}
		else if (str == "3")
		{
			if (isEmpty())
				cout << "School is Empty!!" << endl << endl;
			else
			{
				cout << "Enter the National ID of student: ";
				int NationalID = 0;
				cin >> NationalID;
				fflush(stdin);
				cin.get();
				cur = top;
				while (cur != nullptr)
				{
					if (NationalID == cur->student.nationalID)
					{
						Print(cur);
						found = true;
						break;
					}
					else
						cur = cur->next;
				}
				if (!found)
					cout << endl << "There is no student with this National ID!" << endl << endl;
			}
		}
		else
			cout << endl << "Choose and Write What you want Corecctly!" << endl << endl;
	}

	void BinarySearch()
	{
		cout << "1) Search by Name || 2) Search by ID || 3) Search by National ID " << endl;
		string str = "";
		getline(cin, str);
		bool found = false;
		Student* mid = MidStudent();
		cur = top;
		if (str == "1")
		{
			BubbleSort("1");
			if (isEmpty())
				cout << "School is Empty!!" << endl << endl;
			else
			{
				cout << "Enter the name of student: ";
				string name = "";
				getline(cin, name);
				if (name.length() < 2)
				{
					cur = top;
					while (cur != nullptr)
					{
						for (size_t i = 0; i < name.length(); i++)
						{
							if (toupper(name[i]) == cur->student.name[i])
							{
								Print(cur);
								found = true;
								break;
							}
						}
						cur = cur->next;
					}
				}
				else if (name.length() < cur->student.name.length())
				{
					cur = top;
					while (cur != nullptr)
					{
						if (name.length() > 4)
						{
							for (int i = name.length() - 2; i > name.length() - 3; i--)
							{
								if (name[i] == cur->student.name[i])
								{
									Print(cur);
									found = true;
									break;
								}
							}
						}
						else
						{
							for (int i = name.length() - 1; i > name.length() - 2; i--)
							{
								if (name[i] == cur->student.name[i])
								{
									Print(cur);
									found = true;
									break;
								}
							}
						}
						cur = cur->next;
					}
				}
				else if (name == mid->student.name && name.length() == mid->student.name.length())
				{
					Print(mid);
					found = true;
				}
				else if (name < mid->student.name)
				{
					while (mid != nullptr)
					{
						if (name == mid->student.name)
						{
							Print(mid);
							found = true;
						}
						mid = mid->next;
					}
				}
				else if (name > mid->student.name)
				{
					while (cur != mid)
					{
						if (name == cur->student.name)
						{
							Print(cur);
							found = true;
						}
						else
							cur = cur->next;
					}
				}
				if (!found)
					cout << endl << "No Student have this Name!" << endl << endl;
			}
		}
		else if (str == "2")
		{
			BubbleSort("2");
			if (isEmpty())
				cout << "School is Empty!!" << endl << endl;
			else
			{
				cout << "Enter the ID of student: ";
				string sid = "";
				getline(cin, sid);
				int id = stoi(sid);
				if (id == mid->student.id)
				{
					Print(mid);
					found = true;
				}
				else if (id < mid->student.id)
				{
					while (mid != nullptr)
					{
						if (id == mid->student.id)
						{
							Print(mid);
							found = true;
							break;
						}
						else
							mid = mid->next;
					}
				}
				else if (id > mid->student.id)
				{
					while (cur != mid)
					{
						if (id == cur->student.id)
						{
							Print(cur);
							found = true;
							break;
						}
						cur = cur->next;
					}
				}
				if (!found)
					cout << endl << "No Student have this ID!" << endl << endl;
			}
		}
		else if (str == "3")
		{
			BubbleSort("3");
			if (isEmpty())
				cout << "School is Empty!!" << endl << endl;
			else
			{
				cout << "Enter the National ID of student: ";
				int nationalID = 0;
				cin >> nationalID;
				fflush(stdin);
				cin.get();
				if (nationalID == mid->student.nationalID)
				{
					Print(mid);
					found = true;
				}
				else if (nationalID < mid->student.nationalID)
				{
					while (mid != nullptr)
					{
						if (nationalID == mid->student.nationalID)
						{
							Print(mid);
							found = true;
							break;
						}
						mid = mid->next;
					}
				}
				else if (nationalID > mid->student.nationalID)
				{
					while (cur != mid)
					{
						if (nationalID == cur->student.nationalID)
						{
							Print(cur);
							found = true;
							break;
						}
						cur = cur->next;
					}
				}
				if (!found)
					cout << endl << "No Student have this National ID!" << endl << endl;
			}
		}
		else
			cout << endl << "Choose and Write What you want Corecctly!" << endl << endl;
	}
};
void main()
{
	SchoolMangement school{};

	while (true)
	{
		cout << endl << "================================================" << endl;
		cout << "1- Add Student" << endl;
		cout << "2- Delete Student" << endl;
		cout << "3- Print Data of All Students" << endl;
		cout << "4- Size of Students in School" << endl;
		cout << "5- Sorting" << endl;
		cout << "6- Searching " << endl;
		cout << "7- First Student Added" << endl;
		cout << "8- The Student in Mid" << endl;
		cout << "9- Last Student Added" << endl;
		cout << "10- Exit" << endl;
		cout << "================================================" << endl;
		string str = "";
		cout << endl << "Enter the number of the Selection you want: ";
		getline(cin, str);
		cout << endl;
		if (str == "1")
		{
			system("cls");
			Student student{ };
			school.Push(student);
			system("cls");
			cout << endl << "The addition process was completed successfully" << endl;
		}
		else if (str == "2")
		{
			system("cls");
			school.Pop();
			cout << endl << "The Deletion process was completed successfully" << endl;
		}
		else if (str == "3")
		{
			system("cls");
			school.Print();
			cout << endl;
		}
		else if (str == "4")
		{
			system("cls");
			if (school.isEmpty())
				cout << endl << "The counting failed because the school was empty!" << endl;
			else
			{
				system("cls");
				cout << endl << "The addition process was completed successfully" << endl;
				cout << endl << "Size of Students in school is: " << school.Size() << endl << endl;
			}
		}
		else if (str == "5")
		{
			system("cls");
			if (school.isEmpty())
				cout << endl << "The sorting operation failed because the school is empty!" << endl;
			else
			{
				if (school.Size() <= 1)
					cout << endl << "There must be at least two students!" << endl;
				else
				{
					school.BubbleSort();
					system("cls");
					cout << endl << "The Sorting process was completed successfully" << endl;
				}
			}
		}
		else if (str == "6")
		{
			system("cls");
			if (school.isEmpty())
				cout << endl << "The search failed because the school is empty!" << endl;
			else
			{
				cout << "1) Linear Search || 2) Binary Search" << endl;
				string str = "";
				getline(cin, str);
				if (str == "1")
				{
					school.LinerSearch();
					cout << endl;
				}
				else if (str == "2")
				{
					school.BinarySearch();
					cout << endl;
				}
				else
					cout << endl << "Write and Choose what you want Crocctly please!!" << endl;
			}
		}
		else if (str == "7")
		{
			system("cls");
			if (school.isEmpty())
				cout << endl << "The operation failed because the school was empty!" << endl;
			else
			{
				cout << endl << "The First Student is: " << endl;
				school.Print(school.FirstStudent());
				cout << endl;
			}
		}
		else if (str == "8")
		{
			system("cls");
			if (school.isEmpty())
				cout << endl << "The operation failed because the school was empty!" << endl;
			else
			{
				cout << endl << "The Mid Student is: " << endl;
				school.Print(school.MidStudent());
				cout << endl;
			}
		}
		else if (str == "9")
		{
			system("cls");
			if (school.isEmpty())
				cout << endl << "The operation failed because the school was empty!" << endl;
			else
			{
				cout << endl << "The Last Student is: " << endl;
				school.Print(school.LastStudent());
				cout << endl;
			}
		}
		else if (str == "10")
		{
			break;
		}
		else
		{
			system("cls");
			cout << endl << "Write and Choose what you want Crocctly please!" << endl;
		}
	}
}