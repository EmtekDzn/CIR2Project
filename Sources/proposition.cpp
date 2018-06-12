#include "../Headers/proposition.hpp"

Proposition::Proposition(string prp, int id_qst) {
    proposition = prp;
    id_question = id_qst;
}

string Proposition::getProposition() {
    return proposition;
}
