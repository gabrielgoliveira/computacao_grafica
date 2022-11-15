#include<GL/glut.h>
#include<stdio.h>


typedef struct {
  float x;
  float y;
} Coordenada;

typedef struct {
  Coordenada lados[4];
} Quadrado;

Quadrado quadrado;

void desenhaQuadrado(Quadrado quad) {
  glBegin(GL_QUADS);//comeca a desenhar quadrilatros
    for(int i = 0; i < 4; i++) {
      glVertex2f(quad.lados[i].x, quad.lados[i].y);
    }
  glEnd();
}

void deformaQuadrado() {
  quadrado.lados[1].x += 0.001;
  quadrado.lados[2].x += 0.001;
}
void init() {
 glClearColor(0,0,0,0);
 gluOrtho2D(-20,20,-20,20);
}

void inicializaQuadrado() {
  quadrado.lados[0].x = 5;
  quadrado.lados[0].y = 5;

  quadrado.lados[1].x = -5;
  quadrado.lados[1].y = 5;

  quadrado.lados[2].x = -5;
  quadrado.lados[2].y = -5;

  quadrado.lados[3].x = 5;
  quadrado.lados[3].y = -5;
}

void display() {
  while(1) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.7f, 0.5f, 0.4f);
     
    desenhaQuadrado(quadrado);
    deformaQuadrado();
    glFlush();
  }
}

int main(int argc, char ** argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(0,0);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutCreateWindow("Animacao");
  init();
  inicializaQuadrado(); 
  glutDisplayFunc(display); 
  glutMainLoop();
}
