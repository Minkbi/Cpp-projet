#include <cstdio>
#include <cstdlib>
#include "GerstnerWaveModel.h"

int main(int argc, char* argv[])
{
  FILE * file;
  file = fopen ("aaa","w");
  if (file!=NULL)
  {
    double dir[2];
    dir[0] = 1;
    dir[1] = 0;
    GerstnerWaveModel gWave(dir,8,9,10);
    GerstnerWave wave(dir, 11,12,13);
    gWave.addWave(wave);
    for (int i = 0 ; i < 10; i++) {
      for (int j = 0 ; j < 10; j++) {
	char ligne[1000];	
	sprintf(ligne,"%f %f %f\n", (float)i,(float)j,gWave(i,j,6));
	printf("%s",ligne);
        fputs(ligne,file);
      }
    }
    fclose (file);
  }
  return 0;
}
