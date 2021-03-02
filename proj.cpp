
#include "projheader.h"

void iniParticulas(Particle *particula){
	
	GLfloat v;
	int i;
	GLfloat px, py, pz;
	GLfloat ps;

	px = -5;
	py = -5;
	pz = -5;
	ps = 0.1;



	for (i = 0; i<MAX_PARTICULAS; i++) {

		//---------------------------------  
		v = 200 * frand();
		particula[i].size = ps;		// tamanh de cada particula
		particula[i].x = px + v;
		particula[i].y = py + v;
		particula[i].z = pz + v;

		particula[i].Angulo = 1 + (rand() % 360);
		particula[i].rand = ((rand() % 101) / 100);

	}
}

void showParticulas(Particle *particula, int sistema) {
	int i;

	for (i = 0; i<MAX_PARTICULAS; i++)
	{
		glMaterialfv(GL_FRONT, GL_AMBIENT, glassAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, glassDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR,glassSpec);
        glMaterialf(GL_FRONT, GL_SHININESS,glassCoef);
		glPushMatrix();
		glTranslated(-10, 10, 10);
		glTranslated((particula[i].x*cosf(particula[i].Angulo)),(particula[i].y),particula[i].z*sinf(particula[i].Angulo));
		glutSolidCube(particula[i].size);
		
		glPopMatrix();

		particula[i].Angulo +=0.003f;
	}
}

void showParticulas2(Particle *particula, int sistema) {
	int i;

	for (i = 0; i<MAX_PARTICULAS; i++)
	{
		glMaterialfv(GL_FRONT, GL_AMBIENT, glassAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, glassDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR,glassSpec);
        glMaterialf(GL_FRONT, GL_SHININESS,glassCoef);
		glPushMatrix();
		glTranslated(-15, 10, -10);
		glTranslated((particula[i].x*cosf(particula[i].Angulo)),(particula[i].y),particula[i].z*sinf(particula[i].Angulo));
		glutSolidCube(particula[i].size);
		
		glPopMatrix();

		particula[i].Angulo +=0.003f;
	}
}
void showParticulas3(Particle *particula, int sistema) {
	int i;

	for (i = 0; i<MAX_PARTICULAS; i++)
	{
		glMaterialfv(GL_FRONT, GL_AMBIENT, jadeAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, jadeDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR,jadeSpec);
        glMaterialf(GL_FRONT, GL_SHININESS,jadeCoef);
		glPushMatrix();
		glTranslated(-50, 10, 10);
		glTranslated((particula[i].x*cosf(particula[i].Angulo)),(particula[i].y),particula[i].z*sinf(particula[i].Angulo));
		glutSolidCube(particula[i].size);
		
		glPopMatrix();

		particula[i].Angulo +=0.003f;
	}
}
void showParticulas4(Particle *particula, int sistema) {
	int i;

	for (i = 0; i<MAX_PARTICULAS; i++)
	{
		glMaterialfv(GL_FRONT, GL_AMBIENT, goldAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, goldDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR,goldSpec);
        glMaterialf(GL_FRONT, GL_SHININESS,goldCoef);
		glPushMatrix();
		glTranslated(-50, 10, -15);
		glTranslated((particula[i].x*cosf(particula[i].Angulo)),(particula[i].y),particula[i].z*sinf(particula[i].Angulo));
		glutSolidCube(particula[i].size);
		
		glPopMatrix();

		particula[i].Angulo +=0.003f;
	}
}

void idle(void){

	glutPostRedisplay();
}

void Timer(int value){
	iniParticulas(particula1);

	glutPostRedisplay();
	glutTimerFunc(milisec, Timer, 1);   //.. Espera msecDelay milisegundos
}

void criaDefineTexturas(){

	//Chao
    glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &textures[0]);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	imag.LoadBmpFile("imag1.bmp"); 
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
		imag.GetNumCols(),
		imag.GetNumRows(),
		0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData() );

	glGenTextures(1, &textures[1]);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	imag.LoadBmpFile("imag2.bmp"); 
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
		imag.GetNumCols(),
		imag.GetNumRows(),
		0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData() );    
}

void criaDefineLuzes(){

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCor);
    glEnable(GL_LIGHTING);
    //Propriedades Luz Candeeiro
    glLightfv(GL_LIGHT0, GL_POSITION, lightOnePos);
	glLightfv(GL_LIGHT0, GL_AMBIENT,  matAmbienteR);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  matDifusaR);
	glLightfv(GL_LIGHT1, GL_SPECULAR,  matEspecularR);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION,  0.01);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION,  0.001);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION,  0.01);

	glLightfv(GL_LIGHT2, GL_POSITION, lightTwoPos);
	glLightfv(GL_LIGHT2, GL_AMBIENT,  matAmbienteB);
	glLightfv(GL_LIGHT2, GL_DIFFUSE,  matDifusaB);
	glLightfv(GL_LIGHT1, GL_SPECULAR,  matEspecularB);
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION,  0.01);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION,  0.001);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION,  0.01);

	glLightfv(GL_LIGHT3, GL_POSITION, lightThreePos);
	glLightfv(GL_LIGHT3, GL_AMBIENT,  matAmbienteY);
	glLightfv(GL_LIGHT3, GL_DIFFUSE,  matDifusaY);
	glLightfv(GL_LIGHT1, GL_SPECULAR,  matEspecularY);
	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION,  0.01);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION,  0.001);
	glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION,  0.01);

	glLightfv(GL_LIGHT4, GL_POSITION, lightFourPos);
	glLightfv(GL_LIGHT4, GL_AMBIENT,  matAmbienteG);
	glLightfv(GL_LIGHT4, GL_DIFFUSE,  matDifusaG);
	glLightfv(GL_LIGHT1, GL_SPECULAR,  matEspecularG);
	glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION,  0.01);
	glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION,  0.001);
	glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION,  0.01);
	//Propriedades Luz "Frontal"
	glLightfv(GL_LIGHT1, GL_POSITION, AmbLightPos);
	glLightfv(GL_LIGHT1, GL_AMBIENT,  matAmbiente);
	glLightfv(GL_LIGHT1, GL_DIFFUSE,  matDifusa);
	glLightfv(GL_LIGHT1, GL_SPECULAR,  matEspecular);
	glEnable(GL_LIGHT1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
 
void init(void){
    glClearColor(0,0,0,1);
    glShadeModel(GL_SMOOTH);
    //Texturas
    criaDefineTexturas();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_STENCIL_TEST);
}

void drawCube(float tamanho) {
 
    glPushMatrix();
 
    glBegin(GL_QUADS); //Topo
    glNormal3d(0, 1, 0);
    glVertex3f(-tamanho / 2, tamanho / 2, tamanho / 2);
    glVertex3f(tamanho / 2, tamanho / 2, tamanho / 2);
    glVertex3f(tamanho / 2, tamanho / 2, -tamanho / 2);
    glVertex3f(-tamanho / 2, tamanho / 2, -tamanho / 2);
 
    glEnd();
 
    glBegin(GL_QUADS);//Frente
    glNormal3d(1, 0, 0);
    glVertex3f(tamanho / 2, -tamanho / 2, tamanho / 2);
    glVertex3f(tamanho / 2, -tamanho / 2, -tamanho / 2);
    glVertex3f(tamanho / 2, tamanho / 2, -tamanho / 2);
    glVertex3f(tamanho / 2, tamanho / 2, tamanho / 2);
    glEnd();
 
    glBegin(GL_QUADS);//Tras
    glNormal3d(0, -1, 0);
    glVertex3f(-tamanho / 2, -tamanho / 2, tamanho / 2);
    glVertex3f(-tamanho / 2, -tamanho / 2, -tamanho / 2);
    glVertex3f(-tamanho / 2, tamanho / 2, -tamanho / 2);
    glVertex3f(-tamanho / 2, tamanho / 2, tamanho / 2);
    glEnd();
 
    glBegin(GL_QUADS);//Lados
    glNormal3d(0, 0, -1);
    glVertex3f(-tamanho / 2, -tamanho / 2, -tamanho / 2);
    glVertex3f(tamanho / 2, -tamanho / 2, -tamanho / 2);
    glVertex3f(tamanho / 2, tamanho / 2, -tamanho / 2);
    glVertex3f(-tamanho / 2, tamanho / 2, -tamanho / 2);
    glEnd();
 
    glBegin(GL_QUADS);//Lados
    glNormal3d(0, 0, 1);
    glVertex3f(-tamanho / 2, -tamanho / 2, tamanho / 2);
    glVertex3f(tamanho / 2, -tamanho / 2, tamanho / 2);
    glVertex3f(tamanho / 2, tamanho / 2, tamanho / 2);
    glVertex3f(-tamanho / 2, tamanho / 2, tamanho / 2);
    glEnd();
}

void drawtable(float tamanho,float altura) {
    glBegin(GL_QUADS); //Topo
    glNormal3d(0, 1, 0);
    glVertex3f(-tamanho, tamanho, tamanho);
    glVertex3f(tamanho, tamanho, tamanho);
    glVertex3f(tamanho, tamanho, -tamanho);
    glVertex3f(-tamanho, tamanho, -tamanho);
    glEnd();
   
    glBegin(GL_QUADS);//lateral esquerda
    glNormal3d(0, 0, 1);
    glVertex3f(-tamanho, tamanho, tamanho);
    glVertex3f(-tamanho, tamanho - 1, tamanho);
    glVertex3f(tamanho, tamanho - 1, tamanho);
    glVertex3f(tamanho, tamanho, tamanho);
    glEnd();
   
    glBegin(GL_QUADS);//lateral tras
    glNormal3d(-1, 0, 0);
    glVertex3f(-tamanho, tamanho, tamanho);
    glVertex3f(-tamanho, tamanho - 1, tamanho);
    glVertex3f(-tamanho, tamanho - 1, -tamanho);
    glVertex3f(-tamanho, tamanho, -tamanho);
    glEnd();
 
    glBegin(GL_QUADS);//Lateral direita
    glNormal3d(0, 0, -1);
    glVertex3f(-tamanho, tamanho, -tamanho);
    glVertex3f(-tamanho, tamanho - 1, -tamanho);
    glVertex3f(tamanho, tamanho-1, -tamanho);
    glVertex3f(tamanho, tamanho, -tamanho);
    glEnd();
 
    glBegin(GL_QUADS);//lateral frente
    glNormal3d(1, 0, 0);
    glVertex3f(tamanho, tamanho, tamanho);
    glVertex3f(tamanho, tamanho - 1, tamanho);
    glVertex3f(tamanho, tamanho - 1, -tamanho);
    glVertex3f(tamanho, tamanho, -tamanho);
    glEnd();
 
    //fazer as pernas da mesa com x = comprimento
    glBegin(GL_QUADS);//face da frente
    glNormal3d(0, 0, 1);
    glVertex3f(tamanho - 1, tamanho, tamanho - 1);
    glVertex3f(tamanho - 1, 0, tamanho - 1);
    glVertex3f(tamanho - 2, 0, tamanho - 1);
    glVertex3f(tamanho - 2, tamanho, tamanho - 1);
    glEnd();
 
    glBegin(GL_QUADS);//face esquerda
    glNormal3d(1, 0, 0);
    glVertex3f(tamanho - 1, tamanho, tamanho - 1);
    glVertex3f(tamanho - 1, 0, tamanho - 1);
    glVertex3f(tamanho - 1, 0, tamanho - 2);
    glVertex3f(tamanho - 1, tamanho, tamanho - 2);
    glEnd();
 
    glBegin(GL_QUADS);//face de tras
    glNormal3d(0, 0, -1);
    glVertex3f(tamanho - 2, tamanho, tamanho - 1);
    glVertex3f(tamanho - 2, 0, tamanho - 1);
    glVertex3f(tamanho - 2, 0, tamanho - 2);
    glVertex3f(tamanho - 2, tamanho, tamanho - 2);
    glEnd();
 
    glBegin(GL_QUADS);//face de direita
    glNormal3d(-1, 0, 0);
    glVertex3f(tamanho - 1, tamanho, tamanho - 2);
    glVertex3f(tamanho - 1, 0, tamanho - 2);
    glVertex3f(tamanho - 2, 0, tamanho - 2);
    glVertex3f(tamanho - 2, tamanho, tamanho - 2);
    glEnd();
    // Perna com x=- tamanho
    glBegin(GL_QUADS);//face da frente
    glNormal3d(0, 0, 1);
    glVertex3f(-tamanho + 1, tamanho, tamanho - 1);
    glVertex3f(-tamanho + 1, 0, tamanho - 1);
    glVertex3f(-tamanho + 2, 0, tamanho - 1);
    glVertex3f(-tamanho + 2, tamanho, tamanho - 1);
    glEnd();
 
    glBegin(GL_QUADS);//face esquerda
    glNormal3d(0, 0, -1);
    glVertex3f(-tamanho + 1, tamanho, tamanho - 1);
    glVertex3f(-tamanho + 1, 0, tamanho - 1);
    glVertex3f(-tamanho + 1, 0, tamanho - 2);
    glVertex3f(-tamanho + 1, tamanho, tamanho - 2);
    glEnd();
 
    glBegin(GL_QUADS);//face de tras
    glNormal3d(0, 0, -1);
    glVertex3f(-tamanho + 2, tamanho, tamanho - 1);
    glVertex3f(-tamanho + 2, 0, tamanho - 1);
    glVertex3f(-tamanho + 2, 0, tamanho - 2);
    glVertex3f(-tamanho + 2, tamanho, tamanho - 2);
    glEnd();
 
    glBegin(GL_QUADS);//face de direita
    glNormal3d(0, 0, -1);
    glVertex3f(-tamanho + 1, tamanho, tamanho - 2);
    glVertex3f(-tamanho + 1, 0, tamanho - 2);
    glVertex3f(-tamanho + 2, 0, tamanho - 2);
    glVertex3f(-tamanho + 2, tamanho, tamanho - 2);
    glEnd();
 
    //fazer as pernas da mesa com y = -comprimento
    glBegin(GL_QUADS);//face da frente
    glNormal3d(0, 0, 1);
    glVertex3f(tamanho - 2, 0, -tamanho + 1);
    glVertex3f(tamanho - 1, 0, -tamanho + 1);
    glVertex3f(tamanho - 1, tamanho, -tamanho + 1);
    glVertex3f(tamanho - 2, tamanho, -tamanho + 1);
    glEnd();
 
    glBegin(GL_QUADS);//face esquerda
    glNormal3d(1, 0, 0);
    glVertex3f(tamanho - 1, tamanho, -tamanho + 1);
    glVertex3f(tamanho - 1, 0, -tamanho + 1);
    glVertex3f(tamanho - 1, 0, -tamanho + 2);
    glVertex3f(tamanho - 1, tamanho, -tamanho + 2);
    glEnd();
 
    glBegin(GL_QUADS);//face de tras
    glNormal3d(0, 0, 0);
    glVertex3f(tamanho - 2, tamanho, -tamanho + 1);
    glVertex3f(tamanho - 2, 0, -tamanho + 1);
    glVertex3f(tamanho - 2, 0, -tamanho + 2);
    glVertex3f(tamanho - 2, tamanho, -tamanho + 2);
    glEnd();
 
    glBegin(GL_QUADS);//face de direita
    glNormal3d(0, 0, 0);
    glVertex3f(tamanho - 1, tamanho, -tamanho + 2);
    glVertex3f(tamanho - 1, 0, -tamanho + 2);
    glVertex3f(tamanho - 2, 0, -tamanho + 2);
    glVertex3f(tamanho - 2, tamanho, -tamanho + 2);
    glEnd();
 
    //fazer as pernas da mesa com y = -tamanho e x= -tamanho
    glBegin(GL_QUADS);//face da frente
    glNormal3d(0, 0, 0);
    glVertex3f(-tamanho + 1, tamanho, -tamanho + 1);
    glVertex3f(-tamanho + 1, 0, -tamanho + 1);
    glVertex3f(-tamanho + 2, 0, -tamanho + 1);
    glVertex3f(-tamanho + 2, tamanho, -tamanho + 1);
    glEnd();
 
    glBegin(GL_QUADS);//face esquerda
    glNormal3d(0, 0, 0);
    glVertex3f(-tamanho + 1, tamanho, -tamanho + 1);
    glVertex3f(-tamanho + 1, 0, -tamanho + 1);
    glVertex3f(-tamanho + 1, 0, -tamanho + 2);
    glVertex3f(-tamanho + 1, tamanho, -tamanho + 2);
    glEnd();
 
    glBegin(GL_QUADS);//face de tras
    glNormal3d(0, 0, 0);
    glVertex3f(-tamanho + 2, tamanho, -tamanho + 1);
    glVertex3f(-tamanho + 2, 0, -tamanho + 1);
    glVertex3f(-tamanho + 2, 0, -tamanho + 2);
    glVertex3f(-tamanho + 2, tamanho, -tamanho + 2);
    glEnd();
 
    glBegin(GL_QUADS);//face de direita
    glNormal3d(0, 0, 0);
    glVertex3f(-tamanho + 1, tamanho, -tamanho + 2);
    glVertex3f(-tamanho + 1, 0, -tamanho + 2);
    glVertex3f(-tamanho + 2, 0, -tamanho + 2);
    glVertex3f(-tamanho + 2, tamanho, -tamanho + 2);
    glEnd();
}

void DrawLamp() {
	glLineWidth(2);
	glTranslatef(-10,walls+2, -10);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(2,10,10,10);
	glTranslatef(0, 0, 2);
	glutSolidSphere(1, 10, 10);
	glTranslatef(0, 0, 6);
	glBegin(GL_QUADS);
	glNormal3d(0, 1, 0);
	glVertex3f(0,0,0);
	glVertex3f(0,0,100);
	glVertex3f(-0.2,0,100);
	glVertex3f(-0.1,0,0);
	glEnd();
}

void drawPole(){

	glMaterialfv(GL_FRONT, GL_AMBIENT, gold2Amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, gold2Dif);
    glMaterialfv(GL_FRONT, GL_SPECULAR, gold2Spec);
    glMaterialf(GL_FRONT, GL_SHININESS, gold2Coef);

 
    glBegin(GL_QUADS);   //Top
    glNormal3d(0, 1, 0);
	glVertex3f(-0.5, 5,0.5);
    glVertex3f(0.5, 5,0.5);
    glVertex3f(0.5, 5,-0.5 );
    glVertex3f(-0.5, 5, -0.5);
    glEnd();

    glBegin(GL_QUADS);  //Frente
    glNormal3d(0, 0, 1);
	glVertex3f(-0.5, 0,0);
    glVertex3f(0.5, 0,0);
    glVertex3f(0.5, 5,0 );
    glVertex3f(-0.5, 5, 0);
    glEnd();

    glBegin(GL_QUADS);  //Lado esq
    glNormal3d(0, 0, -1);
	glVertex3f(-0.5, 0,-0.5);
    glVertex3f(-0.5, 0,0.5);
    glVertex3f(-0.5, 5,0.5);
    glVertex3f(-0.5, 5,-0.5);
    glEnd();

    glBegin(GL_QUADS);  //Lado dir
    glNormal3d(0, 0, 1);
	glVertex3f(0.5, 0,-0.5);
    glVertex3f(0.5, 0,0.5);
    glVertex3f(0.5, 5,0.5);
    glVertex3f(0.5, 5,-0.5);
    glEnd();

    glBegin(GL_QUADS);  //Tras
    glNormal3d(0, 0, -1);
	glVertex3f(-0.5, 0,0);
    glVertex3f(0.5, 0,0);
    glVertex3f(0.5, 5,0 );
    glVertex3f(-0.5, 5, 0);
    glEnd();
}

void drawScene() {

	glTranslatef(0,0,40);

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Chao

    glPushMatrix();
    	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,textures[0]);
    	glMaterialfv(GL_FRONT, GL_AMBIENT, woodAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, woodDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, woodSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, woodCoef);
    	glTranslatef(-80-floor_size/2,0,-floor_size*8+floor_size/2);
	    for(int j=0;j<16;j++){
			for(int i=0;i<32;i++){
				glTranslatef(floor_size,0,0);
				glBegin(GL_QUADS);
				glNormal3d(0, 1, 0);
				    glTexCoord2f(0.0f, 0.0f);	glVertex3f(-floor_size / 2, 0, floor_size / 2);
				    glTexCoord2f(0.0f, 1.0f);	glVertex3f(floor_size/ 2, 0, floor_size / 2);
				    glTexCoord2f(1.0f, 1.0f);	glVertex3f(floor_size / 2, 0, -floor_size / 2);
				    glTexCoord2f(1.0f, 0.0f);	glVertex3f(-floor_size/ 2, 0, -floor_size / 2);
			    glEnd();
	    	}
	    	glTranslatef(-160,0,floor_size);
		}
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//------------------------------------------------Postes
	glPushMatrix();
    	glTranslatef(-30,0,20);
    	drawPole();

    	glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);

    	glBegin(GL_QUADS);
    		glNormal3d(0, 0, 1);
			glVertex3f(0.5, 4,0);
    		glVertex3f(19.5, 4,0);
    		glVertex3f(19.5, 4.5,0);
    		glVertex3f(0.5, 4.5,0);
    	glEnd();

    	glTranslatef(20,0,0);
    	drawPole();

    	glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);

    	glBegin(GL_QUADS);
    		glNormal3d(0, 0, 1);
			glVertex3f(0.5, 4,0);
    		glVertex3f(19.5, 4,0);
    		glVertex3f(19.5, 4.5,0);
    		glVertex3f(0.5, 4.5,0);
    	glEnd();


    	glTranslatef(20,0,0);
    	drawPole();

    	glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);

    	glBegin(GL_QUADS);
    		glNormal3d(0, 0, 1);
			glVertex3f(0.5, 4,0);
    		glVertex3f(19.5, 4,0);
    		glVertex3f(19.5, 4.5,0);
    		glVertex3f(0.5, 4.5,0);
    	glEnd();

    	glTranslatef(20,0,0);
    	drawPole();

    	glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);

    	glBegin(GL_QUADS);
    		glNormal3d(0, 0, 1);
			glVertex3f(0.5, 4,0);
    		glVertex3f(19.5, 4,0);
    		glVertex3f(19.5, 4.5,0);
    		glVertex3f(0.5, 4.5,0);
    	glEnd();

    	glTranslatef(20,0,0);
    	drawPole();

    	glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);

    	glBegin(GL_QUADS);
    		glNormal3d(0, 0, 1);
			glVertex3f(0.5, 4,0);
    		glVertex3f(19.5, 4,0);
    		glVertex3f(19.5, 4.5,0);
    		glVertex3f(0.5, 4.5,0);
    	glEnd();

    	glTranslatef(20,0,0);
    	drawPole();

    	glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);

    	glBegin(GL_QUADS);
    		glNormal3d(1, 0, 0);
			glVertex3f(0, 4,-0.5);
    		glVertex3f(0, 4,-19.5);
    		glVertex3f(0, 4.5,-19.5);
    		glVertex3f(0, 4.5,-0.5);
    	glEnd();

    	glTranslatef(0,0,0-20);
    	drawPole();

    	glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);

    	glBegin(GL_QUADS);
    		glNormal3d(1, 0, 0);
			glVertex3f(0, 4,-0.5);
    		glVertex3f(0, 4,-19.5);
    		glVertex3f(0, 4.5,-19.5);
    		glVertex3f(0, 4.5,-0.5);
    	glEnd();

    	glTranslatef(0,0,0-20);
    	drawPole();
    	glTranslatef(-20,0,-55);
    	drawPole();

    	glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);

    	glBegin(GL_QUADS);
    		glNormal3d(1, 0, 0);
			glVertex3f(0, 4,-0.5);
    		glVertex3f(0, 4,-19.5);
    		glVertex3f(0, 4.5,-19.5);
    		glVertex3f(0, 4.5,-0.5);
    	glEnd();

    	glTranslatef(-20,0,0);
    	drawPole();

    	glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);

    	glBegin(GL_QUADS);
    		glNormal3d(1, 0, 0);
			glVertex3f(0, 4,-0.5);
    		glVertex3f(0, 4,-19.5);
    		glVertex3f(0, 4.5,-19.5);
    		glVertex3f(0, 4.5,-0.5);
    	glEnd();


    	glTranslatef(-20,0,0);
    	drawPole();

    	glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);

    	glBegin(GL_QUADS);
    		glNormal3d(0, 0, -1);
			glVertex3f(10, 4,-1);
    		glVertex3f(-35.5, 4,-1);
    		glVertex3f(-35.5, 4.5,-1);
    		glVertex3f(10, 4.5,-1);
    	glEnd();



    	glTranslatef(-20,0,0);
    	drawPole();


    	glTranslatef(-15,0,0);
    	drawPole();


    	glTranslatef(-15,0,0);
    	glEnd();

    	glTranslatef(-15,0,0);
    	drawPole();

    	glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);

    	glBegin(GL_QUADS);
    		glNormal3d(0, 0, 1);
			glVertex3f(0.5, 4,0);
    		glVertex3f(19.5, 4,0);
    		glVertex3f(19.5, 4.5,0);
    		glVertex3f(0.5, 4.5,0);
    	glEnd();
    	

    	glTranslatef(-15,0,0);
    	drawPole();

    	glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);

    	glBegin(GL_QUADS);
    		glNormal3d(0, 0, 1);
			glVertex3f(0.5, 4,0);
    		glVertex3f(19.5, 4,0);
    		glVertex3f(19.5, 4.5,0);
    		glVertex3f(0.5, 4.5,0);
    	glEnd();

    	glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);

    	glBegin(GL_QUADS);
    		glNormal3d(1, 0, 0);
			glVertex3f(0, 4,0.5);
    		glVertex3f(0, 4,19.5);
    		glVertex3f(0, 4.5,19.5);
    		glVertex3f(0, 4.5,0.5);
    	glEnd();

	glPopMatrix();
 
    //------------------------------------------------Cubo
    glTranslatef(0,0,-20);
    glPushMatrix();
        glTranslatef(0, cubo / 2, 0);
        glMaterialfv(GL_FRONT, GL_AMBIENT, blackPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, blackPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, blackPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, blackPlasticCoef);
        drawCube(cubo);
    glPopMatrix();
 
    //----------------------------Cubos coloridos
    //---------------------Frente
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, cyanRubberAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, cyanRubberDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, cyanRubberSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, cyanRubberCoef);
 
        glTranslatef(cubo / 2 - miniCubo / 3, cubo - cubo / 6, cubo - cubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(0, 0, -cubo / 3);
                drawCube(miniCubo);
            }
            glTranslatef(0, -cubo / 3, cubo);
        }
    glPopMatrix();
    //---------------------Tras
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, goldAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, goldDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, goldSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, goldCoef);
        glTranslatef(-cubo / 2 + miniCubo / 3, cubo - cubo / 6, cubo - cubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(0, 0, -cubo / 3);
                drawCube(miniCubo);
            }
            glTranslatef(0, -cubo / 3, cubo);
        }
    glPopMatrix();
    //---------------------Top
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, jadeAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, jadeDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, jadeSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, jadeCoef);
        glTranslatef(-cubo / 3, cubo - miniCubo / 3, cubo - cubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(0, 0, -cubo / 3);
                drawCube(miniCubo);
            }
            glTranslatef(cubo / 3, 0, cubo);
        }
    glPopMatrix();
    //---------------------Sides
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);
        glTranslatef(-cubo + cubo / 3, cubo - cubo / 6, cubo / 2 - miniCubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(cubo / 3, 0, 0);
                drawCube(miniCubo);
            }
            glTranslatef(-cubo, -cubo / 3, 0);
        }
    glPopMatrix();
        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, silverAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, silverDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, silverSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, silverCoef);
        glTranslatef(-cubo + cubo / 3, cubo - cubo / 6, -cubo / 2 + miniCubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(cubo / 3, 0, 0);
                drawCube(miniCubo);
            }
            glTranslatef(-cubo, -cubo / 3, 0);
        }
    glPopMatrix();

     //----------------------------------------------Mesa
    glPushMatrix();
    GLfloat altura = cubo / 2;
         glTranslated(-10,0, -10);
        glMaterialfv(GL_FRONT, GL_AMBIENT, blackRubberAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, blackRubberDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, blackRubberSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, blackRubberCoef);
        drawtable(cubo,altura);
    glPopMatrix();


   //-------------------------------------------------------
   //-------------------------------------------------------
   //-------------------------------------------------------
   //-------------------------------------------------------
   //-------------------------------------------------------
   //-------------------------------------------------------
   //-------------------------------------------------------
    //-------------------------------------------------------	
    //-------------------------------------------------------
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Chao
	glTranslatef(0,0,20);

    glPushMatrix();
    	glTranslatef(-10,0,-40);
    	glRotatef(180,0,1,0);
    	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,textures[0]);
    	glMaterialfv(GL_FRONT, GL_AMBIENT, woodAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, woodDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, woodSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, woodCoef);
    	glTranslatef(-40-floor_size/2,0,-floor_size*8+floor_size/2);
	    for(int j=0;j<16;j++){
			for(int i=0;i<16;i++){
				glTranslatef(floor_size,0,0);
				glBegin(GL_QUADS);
				glNormal3d(0, 1, 0);
				    glTexCoord2f(0.0f, 0.0f);	glVertex3f(-floor_size / 2, 0, floor_size / 2);
				    glTexCoord2f(0.0f, 1.0f);	glVertex3f(floor_size/ 2, 0, floor_size / 2);
				    glTexCoord2f(1.0f, 1.0f);	glVertex3f(floor_size / 2, 0, -floor_size / 2);
				    glTexCoord2f(1.0f, 0.0f);	glVertex3f(-floor_size/ 2, 0, -floor_size / 2);
			    glEnd();
	    	}
	    	glTranslatef(-80,0,floor_size);
		}
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	glPushMatrix();
    	glTranslatef(0,0,-40);
        glTranslated(-10,0, -10);
        glMaterialfv(GL_FRONT, GL_AMBIENT, blackRubberAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, blackRubberDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, blackRubberSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, blackRubberCoef);
        drawtable(cubo,altura);
    glPopMatrix();


    //------------------------------------------------Cubo

    glTranslatef(0,0,-80);
    glRotatef(180,0,1,0);

    glTranslatef(0,0,-20);
    glPushMatrix();

        glTranslatef(0, cubo / 2, 0);
        glMaterialfv(GL_FRONT, GL_AMBIENT, blackPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, blackPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, blackPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, blackPlasticCoef);
        drawCube(cubo);
    glPopMatrix();
 
    //----------------------------Cubos coloridos
    //---------------------Frente
    glPushMatrix();
    	glMaterialfv(GL_FRONT, GL_AMBIENT, goldAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, goldDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, goldSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, goldCoef);
        
 
        glTranslatef(cubo / 2 - miniCubo / 3, cubo - cubo / 6, cubo - cubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(0, 0, -cubo / 3);
                drawCube(miniCubo);
            }
            glTranslatef(0, -cubo / 3, cubo);
        }
    glPopMatrix();
    //---------------------Tras
    glPushMatrix();

    	glMaterialfv(GL_FRONT, GL_AMBIENT, cyanRubberAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, cyanRubberDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, cyanRubberSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, cyanRubberCoef);
        
        glTranslatef(-cubo / 2 + miniCubo / 3, cubo - cubo / 6, cubo - cubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(0, 0, -cubo / 3);
                drawCube(miniCubo);
            }
            glTranslatef(0, -cubo / 3, cubo);
        }
    glPopMatrix();
    //---------------------Top
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, jadeAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, jadeDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, jadeSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, jadeCoef);
        glTranslatef(-cubo / 3, cubo - miniCubo / 3, cubo - cubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(0, 0, -cubo / 3);
                drawCube(miniCubo);
            }
            glTranslatef(cubo / 3, 0, cubo);
        }
    glPopMatrix();
    //---------------------Sides
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);
        glTranslatef(-cubo + cubo / 3, cubo - cubo / 6, cubo / 2 - miniCubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(cubo / 3, 0, 0);
                drawCube(miniCubo);
            }
            glTranslatef(-cubo, -cubo / 3, 0);
        }
    glPopMatrix();
        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, silverAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, silverDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, silverSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, silverCoef);
        glTranslatef(-cubo + cubo / 3, cubo - cubo / 6, -cubo / 2 + miniCubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(cubo / 3, 0, 0);
                drawCube(miniCubo);
            }
            glTranslatef(-cubo, -cubo / 3, 0);
        }
    glPopMatrix();

    glTranslatef(0,0,-20);
    glRotatef(180,0,1,0);

    //------------------------------------------------Cubo 3

    glTranslatef(-60,0,-20);

    glPushMatrix();

        glTranslatef(0, cubo / 2, 0);
        glMaterialfv(GL_FRONT, GL_AMBIENT, blackPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, blackPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, blackPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, blackPlasticCoef);
        drawCube(cubo);
    glPopMatrix();
 
    //----------------------------Cubos coloridos
    //---------------------Frente
    glPushMatrix();
    	glMaterialfv(GL_FRONT, GL_AMBIENT, goldAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, goldDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, goldSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, goldCoef);
        
 
        glTranslatef(cubo / 2 - miniCubo / 3, cubo - cubo / 6, cubo - cubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(0, 0, -cubo / 3);
                drawCube(miniCubo);
            }
            glTranslatef(0, -cubo / 3, cubo);
        }
    glPopMatrix();
    //---------------------Tras
    glPushMatrix();

    	glMaterialfv(GL_FRONT, GL_AMBIENT, cyanRubberAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, cyanRubberDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, cyanRubberSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, cyanRubberCoef);
        
        glTranslatef(-cubo / 2 + miniCubo / 3, cubo - cubo / 6, cubo - cubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(0, 0, -cubo / 3);
                drawCube(miniCubo);
            }
            glTranslatef(0, -cubo / 3, cubo);
        }
    glPopMatrix();
    //---------------------Top
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, jadeAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, jadeDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, jadeSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, jadeCoef);
        glTranslatef(-cubo / 3, cubo - miniCubo / 3, cubo - cubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(0, 0, -cubo / 3);
                drawCube(miniCubo);
            }
            glTranslatef(cubo / 3, 0, cubo);
        }
    glPopMatrix();
    //---------------------Sides
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, silverAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, silverDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, silverSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, silverCoef);
        glTranslatef(-cubo + cubo / 3, cubo - cubo / 6, cubo / 2 - miniCubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(cubo / 3, 0, 0);
                drawCube(miniCubo);
            }
            glTranslatef(-cubo, -cubo / 3, 0);
        }
    glPopMatrix();
        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);
        glTranslatef(-cubo + cubo / 3, cubo - cubo / 6, -cubo / 2 + miniCubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(cubo / 3, 0, 0);
                drawCube(miniCubo);
            }
            glTranslatef(-cubo, -cubo / 3, 0);
        }
    glPopMatrix();

    glTranslatef(60,0,20);

    glTranslatef(-80,0,20);
    glPushMatrix();

        glTranslatef(0, cubo / 2, 0);
        glMaterialfv(GL_FRONT, GL_AMBIENT, blackPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, blackPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, blackPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, blackPlasticCoef);
        drawCube(cubo);
    glPopMatrix();
 
    //----------------------------Cubos coloridos
    //---------------------Frente
    glPushMatrix();
    	glMaterialfv(GL_FRONT, GL_AMBIENT, goldAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, goldDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, goldSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, goldCoef);
        
 
        glTranslatef(cubo / 2 - miniCubo / 3, cubo - cubo / 6, cubo - cubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(0, 0, -cubo / 3);
                drawCube(miniCubo);
            }
            glTranslatef(0, -cubo / 3, cubo);
        }
    glPopMatrix();
    //---------------------Tras
    glPushMatrix();

    	glMaterialfv(GL_FRONT, GL_AMBIENT, cyanRubberAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, cyanRubberDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, cyanRubberSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, cyanRubberCoef);
        
        glTranslatef(-cubo / 2 + miniCubo / 3, cubo - cubo / 6, cubo - cubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(0, 0, -cubo / 3);
                drawCube(miniCubo);
            }
            glTranslatef(0, -cubo / 3, cubo);
        }
    glPopMatrix();
    //---------------------Top
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, jadeAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, jadeDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, jadeSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, jadeCoef);
        glTranslatef(-cubo / 3, cubo - miniCubo / 3, cubo - cubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(0, 0, -cubo / 3);
                drawCube(miniCubo);
            }
            glTranslatef(cubo / 3, 0, cubo);
        }
    glPopMatrix();
    //---------------------Sides
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, redPlasticAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, redPlasticDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, redPlasticSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, redPlasticCoef);
        glTranslatef(-cubo + cubo / 3, cubo - cubo / 6, cubo / 2 - miniCubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(cubo / 3, 0, 0);
                drawCube(miniCubo);
            }
            glTranslatef(-cubo, -cubo / 3, 0);
        }
    glPopMatrix();
        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT, silverAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, silverDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, silverSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, silverCoef);
        glTranslatef(-cubo + cubo / 3, cubo - cubo / 6, -cubo / 2 + miniCubo / 3);
        for (int j = 0; j<3; j++) {
            for (int i = 0; i<3; i++) {
                glTranslatef(cubo / 3, 0, 0);
                drawCube(miniCubo);
            }
            glTranslatef(-cubo, -cubo / 3, 0);
        }
    glPopMatrix();

	glPushMatrix();
		glTranslatef(20,0,-10);
        glMaterialfv(GL_FRONT, GL_AMBIENT, blackRubberAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, blackRubberDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, blackRubberSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, blackRubberCoef);
        drawtable(cubo,altura);
    glPopMatrix();

    glPushMatrix();
   		glTranslatef(30,2,0);
    	glMaterialfv(GL_FRONT, GL_AMBIENT, glassAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, glassDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, glassSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, glassCoef);
    	DrawLamp();
   	glPopMatrix();

	glTranslatef(80,0,-20);





	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Paredes
	glPushMatrix();

    	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,textures[1]);
 
        glMaterialfv(GL_FRONT, GL_AMBIENT, silverAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, silverDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, silverSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, silverCoef);

        glTranslatef(-30,0,0);
        glTranslatef(0,40-walls/2,-10-walls/2);
	    for(int j=0;j<8;j++){
			for(int i=0;i<4;i++){
				glTranslatef(0,0,walls);
				glBegin(GL_QUADS);
				glNormal3d(1, 0, 0);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(0, -walls/2, walls/ 2);
				glTexCoord2f(0.0f, 1.0f);	glVertex3f(0, -walls/2, -walls/2);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(0, walls/2, -walls/2);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(0, walls/2, walls/2);
			    glEnd();
	    	}
	    	glTranslatef(0, -walls,-20);
		}

    glPopMatrix();

    glPushMatrix();

    	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,textures[1]);
 
        glMaterialfv(GL_FRONT, GL_AMBIENT, silverAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, silverDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, silverSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, silverCoef);

        glTranslatef(-80-walls/2,40-walls/2,-40);
	    for(int j=0;j<8;j++){
			for(int i=0;i<32;i++){
				glTranslatef(walls,0,0);
				glBegin(GL_QUADS);
				glNormal3d(1, 0, 0);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(-walls/ 2, -walls/2, 0);
				glTexCoord2f(0.0f, 1.0f);	glVertex3f(walls/2, -walls/2, 0);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(walls/2, walls/2, 0);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(-walls/2, walls/2, 0);
			    glEnd();
	    	}
	    	glTranslatef(-160, -walls,0);
		}

    glPopMatrix();

    glPushMatrix();

    	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,textures[1]);
 
        glMaterialfv(GL_FRONT, GL_AMBIENT, silverAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, silverDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, silverSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, silverCoef);

        glTranslatef(-30,0,0);
        glTranslatef(0,40-walls/2,-40-walls/2);
	    for(int j=0;j<8;j++){
			for(int i=0;i<4;i++){
				glTranslatef(0,0,walls);
				glBegin(GL_QUADS);
				glNormal3d(1, 0, 0);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(0, -walls/2, walls/ 2);
				glTexCoord2f(0.0f, 1.0f);	glVertex3f(0, -walls/2, -walls/2);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(0, walls/2, -walls/2);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(0, walls/2, walls/2);
			    glEnd();
	    	}
	    	glTranslatef(0, -walls,-20);
		}

    glPopMatrix();

   glPushMatrix();

   		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,textures[1]);
 
        glMaterialfv(GL_FRONT, GL_AMBIENT, woodAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, woodDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, woodSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, woodCoef);

        glTranslatef(-20,0,0);
        glTranslatef(-10-walls/2,40-walls/2,0);
	    for(int j=0;j<8;j++){
			for(int i=0;i<4;i++){
				glTranslatef(walls,0,0);
				glBegin(GL_QUADS);
				glNormal3d(0, 0, 1);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(-walls/2, -walls/2, 0);
				glTexCoord2f(0.0f, 1.0f);	glVertex3f(-walls/ 2, walls/2, 0);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(walls/2, walls/2, 0);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(walls/ 2, -walls/2, 0);
			    glEnd();
	    	}
	    	glTranslatef(-20, -walls,0);
		}

    glPopMatrix();

    glPushMatrix();

    	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,textures[1]);
 
        glMaterialfv(GL_FRONT, GL_AMBIENT, silverAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, silverDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, silverSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, silverCoef);

        glTranslatef(20,0,0);
        glTranslatef(-10-walls/2,40-walls/2,0);
	    for(int j=0;j<8;j++){
			for(int i=0;i<4;i++){
				glTranslatef(walls,0,0);
				glBegin(GL_QUADS);
				glNormal3d(0, 0, 1);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(-walls/2, -walls/2, 0);
				glTexCoord2f(0.0f, 1.0f);	glVertex3f(walls/ 2, -walls/2, 0);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(walls/2, walls/2, 0);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(-walls/ 2, walls/2, 0);
			    glEnd();
	    	}
	    	glTranslatef(-20, -walls,0);
		}

    glPopMatrix();

    glTranslatef(-80,0,-40);

    glPushMatrix();
    	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,textures[0]);
    	glMaterialfv(GL_FRONT, GL_AMBIENT, woodAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, woodDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, woodSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, woodCoef);
    	glTranslatef(-40-floor_size/2,0,-floor_size*8+floor_size/2);
	    for(int j=0;j<16;j++){
			for(int i=0;i<16;i++){
				glTranslatef(floor_size,0,0);
				glBegin(GL_QUADS);
				glNormal3d(0, 1, 0);
				    glTexCoord2f(0.0f, 0.0f);	glVertex3f(-floor_size / 2, 0, floor_size / 2);
				    glTexCoord2f(0.0f, 1.0f);	glVertex3f(floor_size/ 2, 0, floor_size / 2);
				    glTexCoord2f(1.0f, 1.0f);	glVertex3f(floor_size / 2, 0, -floor_size / 2);
				    glTexCoord2f(1.0f, 0.0f);	glVertex3f(-floor_size/ 2, 0, -floor_size / 2);
			    glEnd();
	    	}
	    	glTranslatef(-80,0,floor_size);
		}
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	glPushMatrix();
		glTranslatef(40,0,30);
        glMaterialfv(GL_FRONT, GL_AMBIENT, blackRubberAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, blackRubberDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, blackRubberSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, blackRubberCoef);
        drawtable(cubo,altura);
    glPopMatrix();

    glTranslatef(80,0,40);

    glPushMatrix();

   		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,textures[1]);
 
        glMaterialfv(GL_FRONT, GL_AMBIENT, woodAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, woodDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, woodSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, woodCoef);

        glTranslatef(-80,40-walls/2,-80-walls/2);
	    for(int j=0;j<8;j++){
			for(int i=0;i<16;i++){
				glTranslatef(0,0,walls);
				glBegin(GL_QUADS);
				glNormal3d(0, 0, 1);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(0, -walls/2, walls/2);
				glTexCoord2f(0.0f, 1.0f);	glVertex3f(0, -walls/2, -walls/2);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(0, walls/2, -walls/2);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(0, walls/2, walls/2);
			    glEnd();
	    	}
	    	glTranslatef(0, -walls,-80);
		}

		glDisable(GL_TEXTURE_2D);

    glPopMatrix();




    glPushMatrix();
    	glTranslatef(0,0,20);
    	glMaterialfv(GL_FRONT, GL_AMBIENT, glassAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, glassDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, glassSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, glassCoef);
    	DrawLamp();
   	glPopMatrix();


   	glPushMatrix();
   		
    	glMaterialfv(GL_FRONT, GL_AMBIENT, glassAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, glassDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, glassSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, glassCoef);
    	DrawLamp();
   	glPopMatrix();


   	glPushMatrix();
   		glTranslatef(-35,0,0);
    	glMaterialfv(GL_FRONT, GL_AMBIENT, glassAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, glassDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, glassSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, glassCoef);
    	DrawLamp();
   	glPopMatrix();

    glPushMatrix();

        glMaterialfv(GL_FRONT, GL_AMBIENT, glassAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, glassDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, glassSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, glassCoef);
        glTranslatef(-10-walls/2,40-walls/2,0);
	    for(int j=0;j<8;j++){
			for(int i=0;i<4;i++){
				glTranslatef(walls,0,0);
				glBegin(GL_QUADS);
				glNormal3d(0, 0, 1);
				glVertex3f(-walls/2, -walls/2, 0);
				glVertex3f(-walls/ 2, walls/2, 0);
				glVertex3f(walls/2, walls/2, 0);
				glVertex3f(walls/ 2, -walls/2, 0);
			    glEnd();
	    	}
	    	glTranslatef(-20, -walls,0);
		}

    glPopMatrix();

    glPushMatrix();

        glMaterialfv(GL_FRONT, GL_AMBIENT, glassAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, glassDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, glassSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, glassCoef);
        glTranslatef(-30,40-walls/2,10-walls/2);
	    for(int j=0;j<8;j++){
			for(int i=0;i<8;i++){
				glTranslatef(0,0,walls);
				glBegin(GL_QUADS);
				glNormal3d(0, 0, 1);
				glVertex3f(0, -walls/2, walls/2);
				glVertex3f(0, -walls/2, -walls/2);
				glVertex3f(0, walls/2, -walls/2);
				glVertex3f(0, walls/2, walls/2);
			    glEnd();
	    	}
	    	glTranslatef(0, -walls,-40);
		}

    glPopMatrix();

    glPushMatrix();
 
        glMaterialfv(GL_FRONT, GL_AMBIENT, blackRubberAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, blackRubberDif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, blackRubberSpec);
        glMaterialf(GL_FRONT, GL_SHININESS, blackRubberCoef);

        glTranslatef(30,0,0);
        glTranslatef(0,40-walls/2,-80-walls/2);
	    for(int j=0;j<8;j++){
			for(int i=0;i<16;i++){
				glTranslatef(0,0,walls);
				glBegin(GL_QUADS);
				glNormal3d(1, 0, 0);
				glTexCoord2f(0.0f, 0.0f);	glVertex3f(0, -walls/2, walls/ 2);
				glTexCoord2f(0.0f, 1.0f);	glVertex3f(0, -walls/2, -walls/2);
				glTexCoord2f(1.0f, 0.0f);	glVertex3f(0, walls/2, -walls/2);
				glTexCoord2f(1.0f, 1.0f);	glVertex3f(0, walls/2, walls/2);
			    glEnd();
	    	}
	    	glTranslatef(0, -walls,-80);
		}

    glPopMatrix();
}
 
void display(void) {
 
 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    glViewport(0, 0, wScreen, hScreen);
 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Luzes
    criaDefineLuzes();
    glOrtho(-xC, xC, -yC, yC, -zC, zC);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(obsP[0], obsP[1], obsP[2], 0, 0, 0, 0, 1, 0);

    if (particleOn == 1){
		
		showParticulas(particula1, 1);
		showParticulas2(particula1, 1);
		showParticulas3(particula1, 1);
		showParticulas4	(particula1, 1);
	}

    drawScene();

    iniParticulas(particula1);

    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Actualizacao

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
 
    switch (key) {
   	case 'p':
   		if(luzGlobalCor[0]<1){
   			luzGlobalCor[0] = luzGlobalCor[0] + 0.05;
   		}
   		if(luzGlobalCor[1]<1){
   			luzGlobalCor[1] = luzGlobalCor[1] + 0.05;
   		}
   		if(luzGlobalCor[2]<1){
   			luzGlobalCor[2] = luzGlobalCor[2] + 0.05;
   		}
   		
   		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCor);
		glutPostRedisplay();
    	break;				
	
	case 'o':
   		if(luzGlobalCor[0]>0){
   			luzGlobalCor[0] = luzGlobalCor[0] - 0.05;
   		}
   		if(luzGlobalCor[1]>0){
   			luzGlobalCor[1] = luzGlobalCor[1] - 0.05;
   		}
   		if(luzGlobalCor[2]>0){
   			luzGlobalCor[2] = luzGlobalCor[2] - 0.05;
   		}
   		
   		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCor);
		glutPostRedisplay();
    	break;
    case 'l':
		if(nightMode==0){
    		nightMode = 1;
    		glEnable(GL_LIGHT0);
    		glEnable(GL_LIGHT2);
    		glEnable(GL_LIGHT3);
    		glEnable(GL_LIGHT4);

    	}
    	else{
    		nightMode =0;
    		glDisable(GL_LIGHT0);
    		glDisable(GL_LIGHT2);
    		glDisable(GL_LIGHT3);
    		glDisable(GL_LIGHT4);
    	}

   		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCor);
		glutPostRedisplay();
		break;	

	case 'k':

	if(particleOn==0){
		particleOn=1;
	}
	else{
		particleOn=0;
	}
	glutPostRedisplay();
	break;	

	case 'c':
		if(colorLight==0){
			colorLight=1;
			
			matAmbienteR[0]=1.0;
			matAmbienteR[1]=0.1;
			matAmbienteR[2]=0.1;
			matEspecularR[0]=1.0;
			matEspecularR[1]=0.1;
			matEspecularR[2]=0.1;
			matDifusaR[0]=1.0;
			matDifusaR[1]=0.1;
			matDifusaR[2]=0.1;

			matAmbienteG[0]=0.1;
			matAmbienteG[1]=1.0;
			matAmbienteG[2]=0.1;
			matDifusaG[0]=0.1;
			matDifusaG[1]=1.0;
			matDifusaG[2]=0.1;
			matEspecularG[0]=0.1;
			matEspecularG[1]=1.0;
			matEspecularG[2]=0.1;

			matAmbienteB[0]=0.1;
			matAmbienteB[1]=0.1;
			matAmbienteB[2]=1.0;
			matDifusaB[0]=0.1;
			matDifusaB[1]=0.1;
			matDifusaB[2]=1.0;
			matEspecularB[0]=0.1;
			matEspecularB[1]=0.1;
			matEspecularB[2]=1.0;

			matAmbienteY[0]=1.0;
			matAmbienteY[1]=1.0;
			matAmbienteY[2]=0.1;
			matDifusaY[0]=1.0;
			matDifusaY[1]=1.0;
			matDifusaY[2]=1.0;
			matEspecularY[0]=1.0;
			matEspecularY[1]=1.0;
			matEspecularY[2]=0.1;


		}
		else{
			colorLight =0;
			for(int i=0;i<3;i++){
				matAmbienteR[i]=1.0;
				matDifusaR[i]=1.0;
				matEspecularR[i]=1.0;
			}
			for(int i=0;i<3;i++){
				matAmbienteG[i]=1.0;
				matDifusaG[i]=1.0;
				matEspecularG[i]=1.0;
			}
			for(int i=0;i<3;i++){
				matAmbienteB[i]=1.0;
				matDifusaB[i]=1.0;
				matEspecularB[i]=1.0;
			}
			for(int i=0;i<3;i++){
				matAmbienteY[i]=1.0;
				matDifusaY[i]=1.0;
				matEspecularY[i]=1.0;
			}	
		}

		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzGlobalCor);
		glutPostRedisplay();
		break;			

    case 27:
        exit(0);
        break;
    }
}
 
void teclasNotAscii(int key, int x, int y) {
 
    if (key == GLUT_KEY_UP)         obsP[1] = (obsP[1] + 0.1);
    if (key == GLUT_KEY_DOWN)       obsP[1] = (obsP[1] - 0.1);
    if (key == GLUT_KEY_LEFT){
    	if(rVisao*cos(aVisao+0.01)>-2){
    		aVisao = (aVisao + 0.01);
    	}
	}
    if (key == GLUT_KEY_RIGHT){
    	if(rVisao*cos(aVisao-0.01)<=9.99999){
    		aVisao = (aVisao - 0.01);
    	}
    }
    if (obsP[1]>yC)     obsP[1] = yC;
    if (obsP[1]<0.5)    obsP[1] = 0.5;
    obsP[0] = rVisao*cos(aVisao);
    obsP[2] = rVisao*sin(aVisao);

 
    glutPostRedisplay();
}

int main(int argc, char** argv) {
 

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
    glutInitWindowSize(wScreen, hScreen);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(" ------------A Arte Do Cubo------------- ");
 
    init();
 
    glutSpecialFunc(teclasNotAscii);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
 
 	glutIdleFunc(idle);
 	glutTimerFunc(milisec,Timer,1);
    glutMainLoop();
 
    return 0;
}
