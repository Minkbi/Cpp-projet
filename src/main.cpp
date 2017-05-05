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
  Dvector dir(2);
  dir(0) = 1;
  dir(1) = 0;
  Dvector dir2(2);
  dir(0) = -0.5;
  dir(1) = 0.5;
  WaveModel *model;
  if (argc > 1) {
    if (argv[1][0] == '-') {
      switch (argv[1][1]) {
      case 'g':
	{
	  model = new GerstnerWaveModel(dir,1,1,1);
	  GerstnerWave wave(dir,10,10,10);
	  ((GerstnerWaveModel*)model)->addWave(wave);
	  GerstnerWave wave2(dir2,7,7,7);
	  ((GerstnerWaveModel*)model)->addWave(wave2);
	  break;
	}
      case 'p':
	{
	  model = new PhilipsWaveModel(dir,10,10,10,nx,ny);
	}
	break;
      default: 
	cout << "./main nomModel\nModel disponible :\n\n"
	     << "Gerstner : -g\n"
	     << "Philips  : -p\n"
	     << "default model : Gerstner\n\n";
	exit(0);
	break;
      }
    } else {
      cout << "./main nomModel\nModel disponible :\n\n"
	   << "Gerstner : -g\n"
	   << "Philips  : -p\n"
	   << "default model : Gerstner\n\n";
      exit(0);
    }
  } else {
    model = new GerstnerWaveModel(dir,1,1,1);
    GerstnerWave wave(dir,10,10,10);
    ((GerstnerWaveModel*)model)->addWave(wave);
    GerstnerWave wave2(dir2,7,7,7);
    ((GerstnerWaveModel*)model)->addWave(wave2);
  }
  WaveModelPtr modelPtr(model);
  /** @todo Initialiser du champ de hauteur */
  Height H(lx,ly,nx,ny);

  /** @todo Initialiser de l'océan */
  ocean = new Ocean(lx,ly,nx,ny,modelPtr,H);
  /* Initialisation de la fenêtre d'affichage */
  Window::init(WIDTH, HEIGHT, "Houle", argc, argv, "AZERTY", 50, 1);
  /* Execute la simulation */
  Window::launch();
  /* Libère la mémoire */
  Window::quit();
  delete ocean;

  return 0;

}
