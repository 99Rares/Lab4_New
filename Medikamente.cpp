#include "Medikamente.h"
#include <iostream>

Medikamente::Medikamente(string name, double konzentration, double anzahl, double preis) {
	this->name = name;
	this->konzentration = konzentration;
	this->anzahl = anzahl;
	this->preis = preis;
}

string Medikamente::get_name() const {
	return this->name;
}

double Medikamente::get_konzentration() const {
	return this->konzentration;
}

double Medikamente::get_anzahl() const {
	return this->anzahl;
}
double Medikamente::get_preis() const {
	return this->preis;
}
void Medikamente::set_name(string name) {
	this->name = name;
}

void Medikamente::set_konzentration(double kz) {
	this->konzentration = kz;
}

void Medikamente::set_anzahl(double anzahl) {
	this->anzahl = anzahl;
}

void Medikamente::set_preis(double preis) {
	this->preis = preis;
}

void Medikamente::_str_(){
	std::cout << "Medikament \nName: " << this->get_name() << '\n' << "Konzentration: " << this->get_konzentration() << '\n' << "anzahl: " << this->get_anzahl() << '\n' << "Preis: " << this->get_preis() << "\n\n";
}
bool operator == (const Medikamente& a, const Medikamente& b) {
	return (a.get_name() == b.get_name() && a.get_konzentration() == b.get_konzentration());
}

bool operator != (const Medikamente& a, const Medikamente& b) {
	return !(a == b);
}