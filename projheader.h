
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include "RgbImage.h"
#include <time.h>

#define PI 3.14159

#define frand()			((float)rand()/RAND_MAX)
#define MAX_PARTICULAS  200

typedef struct {
	float   size;		// tamanho
	float	life;		// vida
	float	r, g, b;    // color
	GLfloat x, y, z;    // posicao
	GLfloat vx, vy, vz; // velocidade 
	GLint Angulo;     //angulo
	GLint rand;
} Particle;

Particle  particula1[MAX_PARTICULAS];
GLint    milisec = 17;

//================================================================================
//===========================================================Variaveis e constantes
 
GLfloat   walls = 5;
GLfloat   ang = 0;
GLint     qPress = 0;
GLfloat   xC = 20.0, yC = 20.0, zC = 100.0;
GLint     wScreen = 1000, hScreen = 1000;
GLfloat   cubo = 5;
GLfloat   miniCubo = 1.4;
GLfloat   floor_size = 5;
 
GLfloat diff[3] = { 1.0, 1.0, 1.0 };
GLfloat pos[4] = { 0.0, 0.0 ,1.0, 1.0 };
GLfloat spotDir[3] = { 0.0, 0.0, -1.0 };
 
GLfloat  rVisao = 10, aVisao = 0.5*PI, incVisao = 0.05;
GLfloat  obsP[] = { rVisao*cos(aVisao), 0, rVisao*sin(aVisao) };
 
GLint    nightMode = 0;
GLint    colorLight = 0;
GLint    particleOn = 0;
 
 
GLfloat luzGlobalCor[4] = { 1,1,1,1 };
 
GLfloat blackPlasticAmb[] = { 0.01 ,0.01 ,0.01,1 };
GLfloat blackPlasticDif[] = { 0.01 ,0.01 ,0.01,1 };
GLfloat blackPlasticSpec[] = { 0.10 ,0.10 ,0.10,1 };
GLint blackPlasticCoef = 0.25 * 128;

GLfloat  blackRubberAmb []={ 0.01 ,0.01 ,0.01,1 };
GLfloat  blackRubberDif []={   0.05 ,0.05 ,0.05,1 };
GLfloat  blackRubberSpec []={ 0.3 ,0.3 ,0.3,1 };
GLint  blackRubberCoef = 0.078125 *128;

GLfloat  blackRubberAmb2 []={ 0.01 ,0.01 ,0.01,0.5 };
GLfloat  blackRubberDif2 []={   0.05 ,0.05 ,0.05,0.5 };
GLfloat  blackRubberSpec2 []={ 0.3 ,0.3 ,0.3,0.5 };
GLint  blackRubberCoef2 = 0.078125 *128;

GLfloat  cyanRubberAmb[] = { 0.0 ,0.15 ,0.25,1 };
GLfloat  cyanRubberDif[] = { 0.4 ,0.55 ,0.7,1 };
GLfloat  cyanRubberSpec[] = { 0.04 ,0.5555 ,0.9 ,1};
GLint  cyanRubberCoef = 0.078125 * 128;
 
GLfloat  goldAmb[] = { 0.34725 ,0.2995 ,0.1745,1 };
GLfloat  goldDif[] = { 0.75164 ,0.70648 ,0.22648,1 };
GLfloat  goldSpec[] = { 0.628281 ,0.655802 ,0.366065 ,1};
GLint  goldCoef = 0.4 * 128;

GLfloat  gold2Amb[] = { 0.24725 ,0.1995 ,0.0745,1 };
GLfloat  gold2Dif[] = { 0.55164 ,0.50648 ,0.12648,1 };
GLfloat  gold2Spec[] = { 0.428281 ,0.455802 ,0.166065 ,1};
GLint  gold2Coef = 0.4 * 128;

GLfloat  woodAmb[] = { 0.54725 ,0.54725 ,0.54725 ,1};
GLfloat  woodDif[] = { 0.35164 ,0.35164  ,0.35164,1};
GLfloat  woodSpec[] = { 0.45678 ,0.45678 ,0.45678,1};
GLint  woodCoef = 0.7 * 128;
 
GLfloat  silverAmb[] = { 0.39225 ,0.39225 ,0.39225,1 };
GLfloat  silverDif[] = { 0.60754 ,0.60754 ,0.60754,1 };
GLfloat  silverSpec[] = { 0.208273 ,0.208273 ,0.208273,1 };
GLint  silverCoef = 0.4 * 128;
 
GLfloat  redPlasticAmb[] = { 0.3 ,0.0 ,0.0,1 };
GLfloat  redPlasticDif[] = { 0.6 ,0.0 ,0.0,1 };
GLfloat  redPlasticSpec[] = { 0.7 ,0.2 ,0.2,1 };
GLint  redPlasticCoef = 0.25 * 128;
 
GLfloat  jadeAmb[] = { 0.235 ,0.5225 ,0.2575,1 };
GLfloat  jadeDif[] = { 0.24 ,0.6 ,0.23,1 };
GLfloat  jadeSpec[] = { 0.116228 ,0.216228 ,0.116228 ,1};
GLint   jadeCoef = 0.1 * 128;
 
GLfloat  brassAmb[] = { 0.429412 ,0.4294129 ,0.429412 ,1};
GLfloat  brassDif[] = { 0.0780392 ,0.07803927 ,0.0780392,1 };
GLfloat  brassSpec[] = { 0.992157 ,0.941176 ,0.807843,1 };
GLint  brassCoef = 0.21794872 * 128;


GLfloat  glassAmb[] = { 0.429412 ,0.4294129 ,0.429412 ,0.3};
GLfloat  glassDif[] = { 0.0780392 ,0.07803927 ,0.0780392,0.3 };
GLfloat  glassSpec[] = { 0.992157 ,0.941176 ,0.807843,0.3};
GLint  glassCoef = 0.21794872 * 128;


GLfloat  copperAmb []={ 0.29125 ,0.0235 ,0.0325,1 };
GLfloat  copperDif []={   0.7038 ,0.27048 ,0.0828,1 };
GLfloat  copperSpec []={ 0.256777 ,0.137622 ,0.086014 ,1};
GLint  copperCoef = 0.1 *128;


GLfloat lightOnePos[4] = {-10,10,-10,1};
GLfloat lightTwoPos[4] = {-10,10,15,1};
GLfloat lightThreePos[4] = {-50,10,-10,1};
GLfloat lightFourPos[4] = {-55,10,10,1};

GLfloat AmbLightPos[4] = { 0,1,1,0 };

GLfloat matAmbiente[] = {0.2,0.2,0.2,1.0};	  
GLfloat matDifusa[]   = {1.0,1.0,1.0,1.0};	  
GLfloat matEspecular[]= {1.0, 1.0, 1.0, 1.0}; 
GLint   especMaterial = 10;


GLfloat matAmbienteR[] = {1.0,1.0,1.0,1.0};	  
GLfloat matDifusaR[]   = {1.0,1.0,1.0,1.0};	  
GLfloat matEspecularR[]= {1.0, 1.0, 1.0, 1.0}; 

GLfloat matAmbienteG[] = {1.0,1.0,1.0,1.0};	  
GLfloat matDifusaG[]   = {1.0,1.0,1.0,1.0};	  
GLfloat matEspecularG[]= {1.0, 1.0, 1.0, 1.0}; 

GLfloat matAmbienteB[] = {1.0,1.0,1.0,1.0};	  
GLfloat matDifusaB[]   = {1.0,1.0,1.0,1.0};	  
GLfloat matEspecularB[]= {1.0, 1.0, 1.0, 1.0}; 

GLfloat matAmbienteY[] = {1.0,1.0,1.0,1.0};	  
GLfloat matDifusaY[]   = {1.0,1.0,1.0,1.0};	  
GLfloat matEspecularY[]= {1.0, 1.0, 1.0, 1.0}; 

GLuint textures[2];
RgbImage imag;