#pragma once
#include <string>
using std::string;
class Medikamente
{
private:
	string name;
	double konzentration;
	double anzahl;
	double preis;

public:
	/* Constructor */
	Medikamente(string name, double konzentration, double anzahl, double preis);

	/* Gibt den Namen des Medikaments zurück */
	string get_name() const;

	/* Gibt die Konzentration des Medikamentes dar  */
	double get_konzentration() const;

	// Gibt Anzahl aller Medikamente
	double get_anzahl()const;

	// Gibt Preis von Medikamenten dar
	double get_preis()const;
	
	// Verandert Name eines Medikament
	void set_name(string _name);

	// Verandert die Konzentration eines Medikament
	void set_konzentration(double);

	// Verandert die Anzahl der gegebenen Medikamenten
	void set_anzahl(double);

	// Verandert den preis von den Medikamenten
	void set_preis(double);

	// Zeigt Info uber das Medikament
	void _str_();

	~Medikamente(){}
};

