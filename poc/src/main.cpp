
#include <iostream>
#include "Worker.h"
#include "TaskCarEngine.h"
#include "TaskCarDoor.h"
#include "boost/timer.hpp"

int main(int argc, char** argv){

    /** Variables pour les exemples **/

    //Tache pour creer des portieres
    TaskCarDoor     tDoor;

    //Tache pour creer un moteur
    TaskCarEngine   tEngine;

    //Ouvriers
    Worker wa("OuvrierA");
    Worker wb("OuvrierB");

    //Minuteur, pour mesurer le temps de chaque exemple
    boost::timer timer;



    /** Exemple 1 - avec un seul travailleur **/

    //Demarrage du chrono
    timer.restart();
    std::cout << "Exemple 1: demarrage\n";

    //Execute la tache "portieres"
    wa.setTask(&tDoor);
    wa.start();

    //On attent que sa tache ait terminé
    wa.waitEnd();

    //Execute la tache "moteur"
    wa.setTask(&tEngine);
    wa.start();

    //On attend que sa tache ait terminé
    wa.waitEnd();

    //Temps d'execution:
    std::cout   << "Exemple 1: temps d'execution: "
                << timer.elapsed() << "\n";

    /** Exemple 2 - avec 2 travailleurs **/

    //Reset du chrono
    timer.restart();
    std::cout << "Exemple 2: demarrage\n";

    //Affectation des taches
    wa.setTask(&tDoor);
    wb.setTask(&tEngine);

    //Execution des taches
    wa.start();
    wb.start();

    //On attend qu'ils finissent
    wa.waitEnd();
    wb.waitEnd();

    //Temps d'execution:
    std::cout   << "Exemple 2: temps d'execution: "
                << timer.elapsed() << "\n";

    return 0;
}
