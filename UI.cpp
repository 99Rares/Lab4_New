#include "UI.h"
#include <iostream>
using namespace std;

UI::UI(Controller ct) : c(ct) {
}

void text() {
	cout << "\n\n";
	cout << " 0. Exit\n 1. ADD\n 2. Remove\n 3. Update\n 4. Search\n 5. Search ob knapp\n 6. Group price\n 7. undo\n 8. redo\n";
}
void UI::ui() {
	text();
	int x;
	string name, n_name, str;
	double kz, anz, preis, n_kz, n_anz, n_preis,wert;
	Medikamente a = Medikamente("aaa", 1, 1, 1);
	Medikamente aa = Medikamente("aaa", 2, 2, 2);
	Medikamente b = Medikamente("bbb", 2, 2, 2);
	Medikamente ce = Medikamente("ccc", 3, 3, 3);
	Medikamente d = Medikamente("ddd", 4, 4, 4);
	Medikamente e = Medikamente("eee", 5, 5, 5);
	c.r.add(a);
	c.r.add(aa);
	c.r.add(b);
	c.r.add(ce);
	c.r.add(d);
	c.r.add(e);
	cout << "\nWahl: "; cin >> x;
	while (x != 0) {
		if (x == 1) {
			cout << "ADD\n";
			cout << "Name: "; cin.ignore(); getline(cin,name);
			cout << "Konzentration: "; cin >> kz;
			cout << "Anzahl: "; cin >> anz;
			cout << "Preis: "; cin >> preis;
			Medikamente m = Medikamente(name, kz, anz, preis);
			c.r.add(m);
		}
		else if (x == 2) {
			cout << "Remove\n";
			cout << "Name: "; cin.ignore(); getline(cin, name);
			cout << "Konzentration: "; cin >> kz;
			Medikamente m = Medikamente(name, kz, 0, 0);
			c.r.remove(m);
		}
		else if (x == 3) {
			cout << "Update\n";
			cout << "Name: "; cin.ignore(); getline(cin, name);
			cout << "Konzentration: "; cin >> kz;
			cout << "new Name: "; cin.ignore(); getline(cin, n_name);
			cout << "new Konzentration: "; cin >> n_kz;
			cout << "new Anzahl: "; cin >> n_anz;
			cout << "new Preis: "; cin >> n_preis;
			Medikamente m = Medikamente(name, kz, 0, 0);
			Medikamente m2 = Medikamente(n_name, n_kz, n_anz, n_preis);
			c.r.update(m, m2);
		}
		else if (x == 4) {
			cout << "Search:";
			cout << "\nSimbol: ";
			cin.ignore(); getline(cin, str);
			c.search(str);
		}
		else if (x == 5) {
			cout << "Search nach wenig:";
			cout << "\Wert: "; cin >>wert;
			c.wenig_med(wert);
		}
		else if (x == 6) {
			cout << "Sort Price:";
			c.grup();
		}
		else if (x == 7) {
			std::cout << '\n';
			c.r.undo();
		}
		else if (x == 8) {
			std::cout << '\n';
			c.r.redo();
		}
		text();
		cout << "\nWahl: "; cin >> x;
	}
}