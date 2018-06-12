#include "../Headers/theme.hpp"

Theme::Theme(string ctg, int id_ctg)
{
    categorie = ctg;
    id_categorie = id_ctg;
}

string Theme::getCategorie() {
    return categorie;
}

int Theme::getIdCategorie() {
    return id_categorie;
}
