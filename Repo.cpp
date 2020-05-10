#include "Repo.h"
void Repo::add(Medikamente m) {
    Change();
    for (vector<Medikamente>::iterator i = med.begin(); i < med.end(); i++)
        // Wenn das Medikament existiert, update Anzahl
        if (i->get_name()==m.get_name() && i->get_konzentration()== m.get_konzentration()) {  
            i->set_anzahl(i->get_anzahl() + m.get_anzahl());
            undo_list.push_back(med);
            cap++;
            index++;
            return;
        }
    // Wenn das Medikament nicht existiert, wird es eingefugt
    med.push_back(m);

    undo_list.push_back(med);
    cap++;
    index++;
}
void Repo::remove(Medikamente m) {
    Change();
    for (vector<Medikamente>::iterator i = med.begin(); i < med.end(); i++) 
        //medikament loschen
        if (i->get_name() == m.get_name() && i->get_konzentration() == m.get_konzentration()){
            med.erase(i); 
            undo_list.push_back(med);
            cap++;
            index++;
            return;
        }

}
void Repo::update(Medikamente m, Medikamente new_m) {
    for (vector<Medikamente>::iterator i = med.begin(); i < med.end(); i++) {
        if (i->get_name() == m.get_name() && i->get_konzentration() == m.get_konzentration()) {// wenn das medikament existiert, die attribute werden verendert
            i->set_name(new_m.get_name());
            i->set_konzentration(new_m.get_konzentration());
            i->set_anzahl(new_m.get_anzahl());
            i->set_preis(new_m.get_preis());
            undo_list.push_back(med);
            cap++;
            index++;
            return;
        }
    }
}

void Repo::undo() {
    if (index > 0) {
        index--;
        med = undo_list[index];
    }

}
void Repo::redo() {
    if (cap > index) {
        index++;
        med = undo_list[index];
    }
}
void Repo::Change() {

    if (index < this->cap) {
        int diff = this->cap - index;
        while (diff) {
            undo_list.erase(undo_list.end() - 1);
            diff--;
        }

        this->cap = index;
    }
}

int Repo::Grosse() {
    return med.size();
}