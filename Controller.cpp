#include "Controller.h"
#include <iostream>

Controller::Controller() {
	Repo repo;
	this->r = repo;
}


Controller::Controller(Repo repo) : r(repo) {

}
void Controller::add(Medikamente m) {
	r.add(m);
}
void Controller::search(string substr) {
	vector<	Medikamente> aux = r.get_repo();
	if (substr == "") {
		std::vector<std::string> med;

		for (vector<Medikamente>::iterator i = aux.begin(); i < aux.end(); i++)
			med.push_back(i->get_name());
		sort(med.begin(), med.end());
		for (vector < std::string > ::iterator i = med.begin(); i < med.end(); i++)
		{
			std::cout << *i <<' ';
		}
	}
	else
	{
		std::vector<std::string> med;

		for (vector<Medikamente>::iterator i = aux.begin(); i < aux.end(); i++)
			if (i->get_name().find(substr) != -1) {
				med.push_back(i->get_name());
			}

		sort(med.begin(), med.end());
		for (vector < std::string > ::iterator i = med.begin(); i < med.end(); i++)
		{
			std::cout << *i << ' ';
		}
	}
	std::cout << '\n';
}

void Controller::wenig_med(double x) {
	vector<	Medikamente> aux = r.get_repo();
	for (vector<Medikamente>::iterator i = aux.begin(); i < aux.end(); i++) {
		if (i->get_anzahl() < x)
		{
			std::cout << i->get_name() << ' ';
		}
	}
	std::cout << '\n';
}
void Controller::grup() {
	vector<	Medikamente> aux = r.get_repo();
	std::vector<Medikamente> preis;
	for (vector<Medikamente>::iterator i = aux.begin(); i < aux.end(); i++) {

		preis.push_back(*i);

	}

	for (vector<Medikamente>::iterator i = preis.begin();i < preis.end(); i++) {

		for (std::vector<Medikamente>::iterator j = preis.begin();
			j < preis.end(); j++) {

			if (j->get_preis() < i->get_preis()) {
				Medikamente aux2 = *i;
				*i = *j;
				*j = aux2;
			}

		}
	}
	
	std::vector<Medikamente>::iterator i = preis.begin();
	while (i <preis.end()) {

		std::cout << i->get_preis() << ": ";
		double aux = i->get_preis();
		while (aux == i->get_preis()) {
			std::cout << i->get_name() << ' ';
			i++;
			if (i == preis.end()) {
				return;
			}
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}
