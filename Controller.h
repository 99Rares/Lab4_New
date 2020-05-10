#pragma once
#include"Repo.h"
#include <string>
class Controller
{
public:
	Repo r;
	Controller();
	Controller(Repo r);
	void add(Medikamente);
	//sucht der Name des Medikaments
	void search(string substr);
	//sucht alle Medikamente die kleiner als ein gegebenes Wert x sind
	void wenig_med(double x);

	//Grupiert alle Medikamente nach Preis
	void grup();
};

