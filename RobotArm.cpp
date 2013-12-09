#include <GL/glut.h>
#include <math.h>
#include <cstdlib>
#include <cstdio>
#include <stdlib.h>
#include <iostream>

using namespace std;

//starting positions of the objects, from 0 to 360 degrees.
static int shoulder = 0, elbow = 0, hand = 0, fumb = 0, point = 0, middle = 0, ring = 0, tiny = 0;

//fingertips?
static int fumbcap = 0, pointcap = 0, middlecap = 0, ringcap = 0, tinycap = 0;

//window size
static int sWidth = 1000, sHeight = 1000;

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
   glEnable(GL_DEPTH_TEST);
}

GLuint LoadTextureRAW( const char * filename, int wrap )
{
    GLuint texture;
    int width, height;
    GLubyte * data;
    FILE * file;

    // open texture data
    file = fopen( filename, "rb" );
    if ( file == NULL ){
	cout<<"Failed to open file";
	return 0;
	}

    // allocate buffer
    width = 256;
    height = 256;
    data = new GLubyte[width * height * 3];

    // read texture data
    fread( data, width * height * 3, 1, file );
    fclose( file );

    // allocate a texture name
    glGenTextures( 1, &texture );

    // select our current texture
    glBindTexture( GL_TEXTURE_2D, texture );

    // select modulate to mix texture with color for shading
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

    // when texture area is small, bilinear filter the closest mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                     GL_LINEAR );
    // when texture area is large, bilinear filter the first mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    // if wrap is true, the texture wraps over at the edges (repeat)
    //       ... false, the texture ends at the edges (clamp)
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                     wrap ? GL_REPEAT : GL_CLAMP );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
                     wrap ? GL_REPEAT : GL_CLAMP );

    // build our texture mipmaps
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,
                       GL_RGB, GL_UNSIGNED_BYTE, data );
	

    // free buffer
    free( data );

    return texture;
}

void robotarm(void)
{
   glClear (GL_DEPTH_BUFFER_BIT);
   glEnable( GL_TEXTURE_2D );

   //GLuint text1 = LoadTextureRAW("metal2.bmp",true);
   
   //Shoulder
   glPushMatrix();
   //glBindTexture(GL_TEXTURE_2D,text1);
   glTranslatef (-1.0, 0.0, 0.0);         
   glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
   glRotatef ((GLfloat) shoulder, 0.5, 0.0, 0.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glColor3f(1.0,1.0,1.0);
   glScalef (2.0, 0.4, 1.0);
   glutSolidCube (1.0);
   glPopMatrix();
   
   
   //Elbow
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glColor3f(0.0,1.0,1.0);
   glScalef (2.0, 0.4, 1.0);
   glutSolidCube (1.0);
   glPopMatrix();
   
   //Hand
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) hand, 0.0, 0.0, 1.0);
   glTranslatef (0.25, 0.0, 0.0);
   glPushMatrix();
   glColor3f(0.0,0.0,1.0);
   glScalef (0.5, 0.5, 1.0);
   glutSolidCube (1.0);
   glPopMatrix();
   
   
   //Thumb1
   glPushMatrix();
   glTranslatef (0.0, 0.125, -0.2);
   glRotatef ((GLfloat) fumb, 0.0, 0.0, 1.0);
   glTranslatef (0.25, 0.0, 0.8);
   glPushMatrix();
   glColor3f(1.0,0.0,0.0);
   glScalef (0.5, 0.2, 0.2);
   glutSolidCube (0.8);
   glPopMatrix();
   
   glTranslatef (0.15, 0.0, -0.8);
   glRotatef ((GLfloat) fumb, 0.0, 0.0, 1.0);
   glTranslatef (0.25, 0.0, 0.8);
   glPushMatrix();
   glColor3f(1.0,0.0,0.0);
   glScalef (0.5, 0.2, 0.2);
   glutSolidCube (0.8);
   glPopMatrix();
   glPopMatrix();
   
   
   //Pointer Finger
   glPushMatrix();
   glTranslatef (0.5, 0.1, 0.0);
   glRotatef ((GLfloat) point, 0.0, 0.0, 1.0);
   glTranslatef (0.0, 0.0, 0.4);
   glPushMatrix();
   glColor3f(0.8,0.0,0.0);
   glScalef (0.6, 0.2, 0.2);
   glutSolidCube (0.8);
   glPopMatrix();
   
   glTranslatef (0.5, 0.0, 0.0);
   glRotatef ((GLfloat) point, 0.0, 0.0, 1.0);
   glTranslatef (0.0, 0.0, 0.0);
   glPushMatrix();
   glColor3f(0.8,0.0,0.0);
   glScalef (0.6, 0.2, 0.2);
   glutSolidCube (0.8);
   glPopMatrix();       
   glPopMatrix();
 
   
   //Middle Finger
   glPushMatrix();
   glTranslatef (0.5, 0.10, 0.0);
   glRotatef ((GLfloat) middle, 0.0, 0.0, 1.0);
   glTranslatef (0.0, 0.0, 0.0);
   glPushMatrix();
   glColor3f(0.65,0.0,0.0);
   glScalef (0.6, 0.2, 0.2);
   glutSolidCube (0.8);
   glPopMatrix();
   
   glTranslatef (0.5, 0.0, 0.0);
   glRotatef ((GLfloat) middle, 0.0, 0.0, 1.0);
   glTranslatef (0.0, 0.0, 0.0);
   glPushMatrix();
   glColor3f(0.65,0.0,0.0);
   glScalef (0.6, 0.2, 0.2);
   glutSolidCube (0.8);
   glPopMatrix();
   glPopMatrix();
   
   
   //Ring Finger
   glPushMatrix();
   glTranslatef (0.5, 0.1, 0.0);
   glRotatef ((GLfloat) ring, 0.0, 0.0, 1.0);
   glTranslatef (0.0, 0.0, -0.4);
   glPushMatrix();
   glColor3f(0.5,0.0,0.0);
   glScalef (0.6, 0.2, 0.2);
   glutSolidCube (0.8);
   glPopMatrix();
   
   glTranslatef (0.5, 0.1, 0.0);
   glRotatef ((GLfloat) ring, 0.0, 0.0, 1.0);
   glTranslatef (0.0, -0.1,  0.0);
   glPushMatrix();
   glColor3f(0.5,0.0,0.0);
   glScalef (0.6, 0.2, 0.2);
   glutSolidCube (0.8);
   glPopMatrix();
   glPopMatrix();
   
   
   //Pinky Finger
   glPushMatrix();
   glTranslatef (0.2, 0.1, 0.0);
   glRotatef ((GLfloat) tiny, 0.0, 0.0, 1.0);
   glTranslatef (0.0, 0.0, -0.6);
   glPushMatrix();
   glColor3f(0.35,0.0,0.0);
   glScalef (0.5, 0.2, 0.2);
   glutSolidCube (0.8);
   glPopMatrix();

   glTranslatef (0.4, 0.1, 0.0);
   glRotatef ((GLfloat) tiny, 0.0, 0.0, 1.0);
   glTranslatef (0.0, -0.1, 0.0);
   glPushMatrix();
   glColor3f(0.35,0.0,0.0);
   glScalef (0.6, 0.2, 0.2);
   glutSolidCube (0.8);
   glPopMatrix();
   glPopMatrix();

   
   //End
   glPopMatrix();
   glutSwapBuffers();
   //glDeleteTextures(1,&text1);
}

void reshape (int w, int h)
{
   sWidth=w;
   sHeight=h;
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  for(int i = 0; i <= 4; i++) {
    if(i == 0) {
	glViewport(0, sHeight/2, sWidth/2, sHeight/2);
        glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(65.0, (GLfloat) sWidth/(GLfloat) sHeight, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef (0.0, 0.0, -5.0);
        robotarm();
    } else if(i == 1) {
        glViewport (sWidth/2, sHeight/2, sWidth/2, sHeight/2);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(65.0, (GLfloat) sWidth/(GLfloat) sHeight, 1.0, 20.0);
	gluLookAt(6,0,-5.0, 0,0,-5.0, 0,1,0);  //First three: Eye position, Second three: Center of screen, Last three: Where is up?
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef (0.0, 0.0, -5.0);
        robotarm();
    } else if(i == 2) {
        glViewport (sWidth/2, 0, sWidth/2, sHeight/2);
        glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(65.0, (GLfloat) sWidth/(GLfloat) sHeight, 1.0, 20.0);
	gluLookAt(6,6,-0.0, 0,0,-5.0, 0,1,0);  //First three: Eye position, Second three: Center of screen, Last three: Where is up?
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef (0.0, 0.0, -5.0);
        robotarm();
    } else if(i == 3) {
        glViewport (0, 0, sWidth/2, sHeight/2);
        glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(65.0, (GLfloat) sWidth/(GLfloat) sHeight, 1.0, 20.0);
	gluLookAt(6,0,-5.0, 0,0,-5.0, 0,-1,0);  //First three: Eye position, Second three: Center of screen, Last three: Where is up?
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef (0.0, 0.0, -5.0);
        robotarm();
    }
  }
  glFlush();
  glutSwapBuffers();
}


void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      //Shoulder
      case 's':
         shoulder = (shoulder + 5) % 360;
         glutPostRedisplay();
         break;
      case 'S':
         shoulder = (shoulder - 5) % 360;
         glutPostRedisplay();
         break;
      //Elbow
      case 'e':
	 if (elbow < 180)
         elbow = (elbow + 5) % 360;
         glutPostRedisplay();
         break;
      case 'E':
	 if (elbow > 0)
         elbow = (elbow - 5) % 360;
         glutPostRedisplay();
         break;
      //Hand
      case 'h':
	 if (hand < 90)
	 hand = (hand + 5) % 360;
         glutPostRedisplay();
         break;
      case 'H':
	 if (hand > 0)
	 hand = (hand - 5) % 360;
         glutPostRedisplay();
         break;
	 
      //Thumb 
      case 'f':
	 if (fumb < 90)
         fumb = (fumb + 5) % 360;
         glutPostRedisplay();
         break;
      case 'F':
	 if (fumb > 0)
         fumb = (fumb - 5) % 360;
         glutPostRedisplay();
         break;
	 
      //Pointer Finger
      case 'p':
	 if (point < 90)
         point = (point + 5) % 360;
         glutPostRedisplay();
         break;
      case 'P':
	 if (point > 0)
         point = (point - 5) % 360;
         glutPostRedisplay();
         break;
	 
      //Middle Finger
      case 'm':
	 if (middle < 90)
         middle = (middle + 5) % 360;
         glutPostRedisplay();
         break;
      case 'M':
	 if (middle > 0)
         middle = (middle - 5) % 360;
         glutPostRedisplay();
         break;
	 
      //Ring Finger
      case 'r':
	 if (ring < 90)
         ring = (ring + 5) % 360;
         glutPostRedisplay();
         break;
      case 'R':
	 if (ring > 0)
         ring = (ring - 5) % 360;
         glutPostRedisplay();
         break;
	 
      //Pinky Finger
      case 't':
	 if (tiny < 90)
         tiny = (tiny + 5) % 360;
         glutPostRedisplay();
         break;
      case 'T':
	 if (tiny > 0)
         tiny = (tiny - 5) % 360;
         glutPostRedisplay();
	 break;

      //Entire Hand!(For Creep-Out Effect)
      case 'c':
         if (fumb < 90)
         fumb = (fumb + 5) % 360;
         if (point < 90)
         point = (point + 5) % 360;
         if (middle < 90)
         middle = (middle + 5) % 360;
         if (ring < 90)
         ring = (ring + 5) % 360;
         if (tiny < 90)
         tiny = (tiny + 5) % 360;
         glutPostRedisplay();
         break;
      case 'C':
         if (fumb > 0)
         fumb = (fumb - 5) % 360;
         if (point > 0)
         point = (point - 5) % 360;
         if (middle > 0)
         middle = (middle - 5) % 360;
         if (ring > 0)
         ring = (ring - 5) % 360;
	 if (tiny > 0)
         tiny = (tiny - 5) % 360;
         glutPostRedisplay();
	 break;

      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (sWidth, sHeight); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("T-900\'s got nothing on this.");
   init();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
