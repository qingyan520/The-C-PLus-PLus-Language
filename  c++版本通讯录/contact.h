#pragma once
#define MAX 100
#include<iostream>
#include<string>
using namespace std;
enum option
{
	ExitContact,
	AddContact,
	ShowContact,
	DeleteContact,
	SearchContact,
	MOdityContact,
	SortContact,
	CleanContact
};
struct PeopleInfortation
{
	string Name;
	int Sex;
	int Age;
	string Phone;
	string Addr;
};
struct Contact
{
	struct PeopleInfortation contact[MAX];
	int size = 0;
};
void Add(struct Contact* ps);
void Show(struct Contact* ps);
void Delete(struct Contact* ps);
void Search(struct Contact* ps);
void Modity(struct Contact* ps);
void Sort(struct Contact* ps);
void Clean(struct Contact* ps);