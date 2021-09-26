#include <iostream>
#include <cstring>
using namespace std;

class Person
{
public:
	char *name;
	char *addr;
	Person(const char *name, const char *addr);
	Person(const Person &person);
	Person(Person &&person);
	~Person();
	void print() const;
	void chAddr(const char *newAddr);
	Person copyPerson();
};

Person::Person(const char *name, const char *addr)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->addr = new char[strlen(addr) + 1];
	strcpy(this->addr, addr);
	cout << "Person 객체 생성함(" << name << ")" << endl;
}

Person::Person(const Person &person)
{
	this->name = new char[strlen(person.name)];
	strcpy(this->name, person.name);
	this->addr = new char[strlen(person.addr)];
	strcpy(this->addr, person.addr);
	cout << "Person 객체 생성함(" << this->name << ")" << endl;
}

Person::Person(Person &&person) : name{person.name}, addr{person.addr}
{
	person.name = nullptr;
	person.addr = nullptr;
}

Person::~Person()
{
	cout << "Person 객체 제거함(" << name << ")" << endl;
	delete[] name;
	delete[] addr;
}

Person Person::copyPerson()
{
	Person tmp(this->name, this->addr);
	return tmp;
}

int main()
{
	Person p1("doobu", "github");
	Person p2(p1);
	Person p3(p2.copyPerson());
	strcpy(p1.name, "boobu");
	strcpy(p2.name, "coobu");
	return 0;
}