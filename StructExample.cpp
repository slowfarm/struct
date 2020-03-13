#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

struct Person
{
	Person(const string& n, int& a, int& w) : name(n), age(a), weight(w) {};
	string name;
	int age;
	int weight;
};

bool initMenu(vector<Person>& persons);
void printPerson(Person person);
void printPersons(vector<Person> persons);
void findPersonByName(vector<Person> persons);
void deletePersonByName(vector<Person>& persons);
void addPerson(vector<Person>& persons);

int main()
{
	bool flag = true;
	vector<Person> persons;
	while (flag)
	{
		flag = initMenu(persons);
	}
	return 0;
}

bool initMenu(vector<Person>& persons) 
{
	system("cls");
	cout << "1-Add person" << endl;
	cout << "2-Find person by name" << endl;
	cout << "3-Delete person by name" << endl;
	cout << "4-Show all persons" << endl;
	cout << "0-Exit" << endl;
	int a;
	cin >> a;
	system("cls");
	switch (a) 
	{
	case 0:
		return false;
	case 1:
		addPerson(persons);
		printPersons(persons);
		system("pause");
		break;
	case 2:
		findPersonByName(persons);
		system("pause");
		break;
	case 3:
		deletePersonByName(persons);
		printPersons(persons);
		system("pause");
		break;
	case 4:
		printPersons(persons);
		system("pause");
		break;
	}
	return true;
}

void findPersonByName(vector<Person> persons) 
{
	string name;
	cout << "Enter name" << endl;
	cin >> name;
	for (Person person : persons)
	{
		if (person.name == name)
		{
			printPerson(person);
		}
	}
}

void deletePersonByName(vector<Person>& persons) 
{
	string name;
	cout << "Enter name" << endl;
	cin >> name;
	vector<Person>::iterator iterator;
	for (iterator = persons.begin(); iterator != persons.end();)
	{
		if (iterator->name == name)
		{
			iterator = persons.erase(iterator);
		}
		else 
		{
			++iterator;
		}
	}
}

void printPersons(vector<Person> persons) 
{
	cout << "List of persons" << endl;
	cout << "Name\tAge\tWeigth" << endl;
	cout << "=======================" << endl;
	for (Person person : persons) 
	{
		printPerson(person);
	}
}

void printPerson(Person person) 
{
	cout << person.name << "\t" << person.age << "\t" << person.weight << endl;
}

void addPerson(vector<Person>& persons)
{
	string name;
	int age;
	int weight;
	cout << "Add name: ";
	cin >> name;
	cout << "Add age: ";
	cin >> age;
	cout << "Add weigth: ";
	cin >> weight;
	cout << endl;
	persons.push_back(Person(name, age, weight));
}
