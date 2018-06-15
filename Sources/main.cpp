#include "../Headers/mainwindow.hpp"
#include <QApplication>

/*!
 * \file main.cpp
 * \brief Fichier principal de l'application
 * \author Pierre-Alban Lagadec
 * \version 0.1
 */

int main(int argc, char *argv[]) {
    QApplication a(argc, argv); // Lancement de l'appli Qt
    MainWindow w;   // Creation de la fenetre principale
    w.show();  // Affichage

    return a.exec();
}
