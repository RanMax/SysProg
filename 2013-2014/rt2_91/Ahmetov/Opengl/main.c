#include <stdlib.h>

/* подключаем библиотеку GLUT */
#include <GL/glut.h>

/* начальная ширина и высота окна */
GLint Width = 512, Height = 512;

/* эта функция управляет всем выводом на экран */
void Display(void)
{

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3ub(255,255,0);

    glBegin(GL_POINTS);
      glVertex2f(30, 448);
      glVertex2f(37,470);
      glVertex2f(47,390);
      glVertex2f(67,470);
      glVertex2f(90,390);
    glEnd();

    glBegin(GL_LINES);
      glVertex2f(130, 390);
      glVertex2f(200,470);
      glVertex2f(130,470);
      glVertex2f(190,390);
      glVertex2f(195,390);
      glVertex2f(230,480);
    glEnd();

    glBegin(GL_LINE_STRIP);
      glVertex2f(260,390);
      glVertex2f(270,470);
      glVertex2f(280,400);
      glVertex2f(500,480);
      glVertex2f(384,400);
      glVertex2f(290,475);
    glEnd();

    glBegin(GL_LINE_LOOP);
      glVertex2f(30, 320);
      glVertex2f(60,380);
      glVertex2f(100,370);
      glVertex2f(80,260);
      glVertex2f(70,290);
    glEnd();

    glBegin(GL_POLYGON);
      glVertex2f(150, 270);
      glVertex2f(130,330);
      glVertex2f(190,380);
      glVertex2f(250,370);
      glVertex2f(250,250);
          glColor3ub(0,255,0); // для видимости впуклости
      glVertex2f(200,320);
    glEnd();

    glBegin(GL_QUADS);
      glVertex2f(350, 300);
      glVertex2f(260,340);
      glVertex2f(370,380);
      glVertex2f(380, 320);

      glVertex2f(400, 340);
      glVertex2f(500,380);
      glVertex2f(500,250);
      glVertex2f(400, 300);
    glEnd();

    glBegin(GL_QUAD_STRIP);
      glVertex2f( 32,140);
      glVertex2f( 32,150);
      glVertex2f( 70,130);
      glVertex2f( 60,160);

      glVertex2f( 90, 135);
      glVertex2f( 80,160);
      glVertex2f(100,145);
      glVertex2f(110, 165);
    glEnd();

    glBegin(GL_TRIANGLES);
      glVertex2f(257,192);
      glVertex2f(265,240);
      glVertex2f(340,185);

      glVertex2f(300,130);
      glVertex2f(384,200);
      glVertex2f(390,130);

      glVertex2f(390,200);
      glVertex2f(500,250);
      glVertex2f(450,185);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
      glVertex2f( 70, 10);
      glVertex2f( 50, 60);
      glVertex2f( 60,120);
      glVertex2f(130, 80);
      glVertex2f(190, 60);
      glColor3ub(0,0,255);
      glVertex2f(200, 20);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
      glVertex2f(260, 10);
      glVertex2f(320,110);
        glColor3ub(255,0,0);
      glVertex2f(360, 30);
      glVertex2f(384,100);
      glVertex2f(400, 10);
        glColor3ub(255,255,255);
      glVertex2f(450,120);
    glEnd();

    glFinish();
}

/* Функция вызывается при изменении размеров окна */
void Reshape(GLint w, GLint h)
{
    Width = w;
    Height = h;

    /* устанавливаем размеры области отображения */
    glViewport(0, 0, w, h);

    /* ортографическая проекция */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/* Функция обрабатывает сообщения от клавиатуры */
void
Keyboard( unsigned char key, int x, int y )
{
#define ESCAPE '\033'

    if( key == ESCAPE )
        exit(0);
}

/* Главный цикл приложения */
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("Red square example");

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);

    glutMainLoop();
}

