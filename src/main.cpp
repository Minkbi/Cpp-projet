#include <cstdlib>
#include <ctime>
#include <iostream>

/** @todo Inclure les fichiers de définition du problème */

#include "window.h"

int main(int argc, char** argv) {

  /** @todo Initialiser des paramètres de simulation */
  double lx = 1000;
  double ly = 1000;
  int nx = 100;
  int ny = 100;

  /** @todo Initialiser du modèle*/
  double dir[2];
  dir[0] = 1;
  dir[1] = 0;
  double dir2[2];
  dir[0] = -0.5;
  dir[1] = 0.5;
  GerstnerWaveModel model(dir,1,1,1);
  //GerstnerWave wave(dir2,5,5,5);
  //model.addWave(wave);
  /** @todo Initialiser du champ de hauteur */
  Height H(lx,ly,nx,ny);

  /** @todo Initialiser de l'océan */
  ocean = new Ocean(lx,ly,nx,ny,model,H);

  /* Initialisation de la fenêtre d'affichage */
  Window::init(WIDTH, HEIGHT, "Houle", argc, argv, "AZERTY", 50, 1);

  /* Execute la simulation */
  Window::launch();

  /* Libère la mémoire */
  Window::quit();

  delete ocean;

  return 0;

}
