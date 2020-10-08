//SpikeUP
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define PI 3.1416


//Player
float u= 0.0;
float f= 0.0;
//Monster
float my1 = 5.0;
float my2 = 5.0;
float my3 = 5.0;
float my4 = 5.0;

//Delay
int delay = 50;

// Score
int score = 5;
int kills = 0;

float m1=5.0,m2=10.0,m3=15.0,m4=20.0;

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glOrtho(0.0, 20.0, 0.0, 32.0, 0.0, 20.0); // H:W = 1.6
}

void circle(float x, float y, float radius_x, float radius_y)
{
    int i=0;
    float angle = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 100; i++)
    {
        angle = 2 * PI * i / 100;
        glVertex2f ((cos(angle) * radius_x) + x, (sin(angle) * radius_y) + y);
    }

    glEnd();
}

void monster_Spawan(float mx, float my)
{
    // Monsters
    glPushMatrix();
    glTranslatef(mx,0,0);

    // Monster body
    glColor3f(0.0, 1.0, 0.0);
    circle(2.5,28.0+my,1.5,1.5);

    // Monster left leg
    glColor3f(1.0, 1.0, 0.0);
    circle(1.58,26.3+my,0.7,0.3);

    // Monster right leg
    glColor3f(1.0, 1.0, 0.0);
    circle(3.42,26.3+my,0.7,0.3);


    glBegin(GL_TRIANGLES);
    // Top left Spikes
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(1.4f, 29.0f+my);
    glVertex2f(2.0f, 29.0f+my);
    glVertex2f(1.7f, 30.4f+my);
    // Top right Spikes
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(3.0f, 29.0f+my);
    glVertex2f(3.6f, 29.0f+my);
    glVertex2f(3.3f, 30.4f+my);

    // Left Teeth
    glColor3f(1.0f, 1.0f, 0.9f);
    glVertex2f(1.9f, 27.6f+my);
    glVertex2f(2.2f, 26.8f+my);
    glVertex2f(2.5f, 27.6f+my);

    // Right Teeth
    glColor3f(1.0f, 1.0f, 0.9f);
    glVertex2f(2.5f, 27.6f+my);
    glVertex2f(2.8f, 26.8f+my);
    glVertex2f(3.1f, 27.6f+my);
    glEnd();

    // EYE
    glColor3f(1.0, 1.0, 0.0);
    circle(2.5,28.5+my,0.5,0.5);

    // EYE Ball
    glColor3f(0.0, 0.0, 0.0);
    circle(2.5,28.5+my,0.15,0.15);

    glPopMatrix();
}

void update(int)
{
    int rand_seed = 25;
    int low_rand = 10;

    if(my1+m1 > -34.0)
    {
        my1 = my1-0.5;
    }
    else
    {
        my1 = 5.0;
        m1 = (low_rand + ( rand() %  rand_seed)) ;
    }

    if(my2+m2 > -34.0)
        my2 = my2-0.5;
    else
    {
        my2 = 5.0;
        m2 = (low_rand + ( rand() %  rand_seed)) ;
    }

    if(my3+m3 > -34.0)
        my3 = my3-0.5;
    else
    {
        my3 = 5.0;
        m3 = (low_rand + ( rand() %  rand_seed)) ;
    }

    if(my4+m4 > -34.0)
        my4 = my4-0.5;
    else
    {
        my4 = 5.0;
        m4 = (low_rand + ( rand() %  rand_seed)) ;
    }
    //cout<<0<<" "<<u<<" "<<my1<<" "<<my2<<" "<<my3<<" "<<my4<<" "<<m1<<" "<<m2<<" "<<m3<<" "<<m4<<endl;

    float threshold = -20.5;
    float th2 = -26.5;
    if (my1+m1 <= threshold && u == 0)
    {
        my1 = 5.0;
        m1 = (low_rand + ( rand() %  rand_seed)) ;
        kills += 1;
    }
    else if(my1+m1 == th2 && u != 0 && score != 0)
    {
        score -= 1;
        cout<<score<<endl;
    }

    if (my2+m2 <= threshold && u == 5)
    {
        my2 = 5.0;
        m2 = (low_rand + ( rand() %  rand_seed)) ;
        kills += 1;
    }
    else if(my2+m2 == th2 && u != 5 && score != 0)
    {
        score -= 1;
        cout<<score<<endl;
    }

    if (my3+m3 <= threshold && u == 10)
    {
        my3 = 5.0;
        m3 = (low_rand + ( rand() %  rand_seed)) ;
        kills += 1;
    }
    else if(my3+m3 == th2 && u != 10 && score != 0)
    {
        score -= 1;
        cout<<score<<endl;
    }

    if (my4+m4 <= threshold && u == 15)
    {
        my4 = 5.0;
        m4 = (low_rand + ( rand() %  rand_seed)) ;
        kills += 1;
    }
    else if(my4+m4 == th2 && u != 15 && score != 0)
    {
        score -= 1;
        cout<<score<<endl;
    }
    //cout<<score<<endl;
    glutTimerFunc(delay, update, 0);
}

void score_Board()
{
    glBegin(GL_QUADS);
    glColor3f(0.49f, 0.38f, 0.89f);
    glVertex2f(0.0f, 31.8f);
    glVertex2f(0.0f, 30.5f);
    glColor3f(0.59f, 0.48f, 0.89f);
    glVertex2f(5.0f, 30.5f);
    glColor3f(0.59f, 0.48f, 0.89f);
    glVertex2f(6.0f, 31.8f);
    glEnd();

    if(score >= 1)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.1f, 31.6f);
        glVertex2f(0.1f, 30.7f);
        glColor3f(0.62f, 0.0f, 0.77f);
        glVertex2f(1.0f, 30.7f);
        glColor3f(0.62f, 0.0f, 0.77f);
        glVertex2f(1.0f, 31.6f);
        glEnd();

    }

    if(score >= 2)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(1.1f, 31.6f);
        glVertex2f(1.1f, 30.7f);
        glColor3f(0.62f, 0.0f, 0.77f);
        glVertex2f(2.0f, 30.7f);
        glColor3f(0.62f, 0.0f, 0.77f);
        glVertex2f(2.0f, 31.6f);
        glEnd();

    }

    if(score >= 3)
    {
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(2.1f, 31.6f);
        glVertex2f(2.1f, 30.7f);
        glColor3f(0.62f, 0.0f, 0.77f);
        glVertex2f(3.0f, 30.7f);
        glColor3f(0.62f, 0.0f, 0.77f);
        glVertex2f(3.0f, 31.6f);
        glEnd();

    }

    if(score >= 4)
    {
        glBegin(GL_QUADS);
        glColor3f(0.88f, 0.62f, 0.0f);
        glVertex2f(3.1f, 31.6f);
        glColor3f(0.0f, 0.62f, 0.88f);
        glVertex2f(3.1f, 30.7f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(4.0f, 30.7f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(4.0f, 31.6f);
        glEnd();

    }

    if(score >= 5)
    {
        glBegin(GL_QUADS);
        glVertex2f(4.1f, 31.6f);
        glVertex2f(4.1f, 30.7f);
        glColor3f(0.0f, 1.0f, 0.2f);
        glVertex2f(5.0f, 30.7f);
        glColor3f(0.0f, 1.0f, 0.2f);
        glVertex2f(5.0f, 31.6f);
        glEnd();

    }
}

void RenderString(float x, float y, void *font, const char* string, float R, float G, float B)
{
    char *c;

    glColor3f(R, G, B);
    glRasterPos2f(x, y);

    //glutBitmapString(font, string);
    int len = strlen(string);
    for (int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
    }
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);


    if (score != 0)
    {
        // Background Quads
        glBegin(GL_QUADS);
        glColor3f(0.62f, 0.0f, 0.77f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(5.0f, 0.0f);
        glVertex2f(5.0f, 32.0f);
        glVertex2f(0.0f, 32.0f);

        glColor3f(0.70f, 0.0f, 0.85f);
        glVertex2f(5.0f, 0.0f);
        glVertex2f(10.0f, 0.0f);
        glVertex2f(10.0f, 32.0f);
        glVertex2f(5.0f, 32.0f);

        glColor3f(0.39f, 0.12f, 1.0f);
        glVertex2f(10.0f, 0.0f);
        glVertex2f(15.0f, 0.0f);
        glVertex2f(15.0f, 32.0f);
        glVertex2f(10.0f, 32.0f);

        glColor3f(0.49f, 0.18f, 1.0f);
        glVertex2f(15.0f, 0.0f);
        glVertex2f(20.0f, 0.0f);
        glVertex2f(20.0f, 32.0f);
        glVertex2f(15.0f, 32.0f);

        glEnd();


        // Player Spike
        glPushMatrix();
        glTranslatef(u,f,0);

        glBegin(GL_QUADS);
        //Face
        glColor3f(0.0f, 0.15f, 0.78f);
        glVertex2f(1.0f, 6.0f);
        glVertex2f(1.0f, 3.0f);
        glColor3f(0.4f, 0.25f, 0.98f);
        glVertex2f(4.0f, 3.0f);
        glVertex2f(4.0f, 6.0f);
        glEnd();

        glBegin(GL_QUADS);
        //Face Mask
        glColor3f(1.0f, 0.15f, 0.0f);
        glVertex2f(1.0f, 6.0f);
        glColor3f(1.2f, 0.15f, 0.6f);
        glVertex2f(1.0f, 4.5f);
        glVertex2f(4.0f, 5.7f);
        glVertex2f(4.0f, 6.0f);
        glEnd();

        glBegin(GL_QUADS);
        //Left eye
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(1.4f, 5.2f);
        glVertex2f(1.4f, 4.4f);
        glVertex2f(2.2f, 4.4f);
        glVertex2f(2.2f, 5.2f);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(1.4f, 4.9f);
        glVertex2f(1.4f, 4.4f);
        glVertex2f(1.9f, 4.4f);
        glVertex2f(1.9f, 4.9f);

        //Right Eye
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(2.8f, 5.2f);
        glVertex2f(2.8f, 4.4f);
        glVertex2f(3.6f, 4.4f);
        glVertex2f(3.6f, 5.2f);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(2.8f, 4.9f);
        glVertex2f(2.8f, 4.4f);
        glVertex2f(3.3f, 4.4f);
        glVertex2f(3.3f, 4.9f);

        //Mouth
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(1.8f, 3.9f);
        glVertex2f(1.8f, 3.6f);
        glVertex2f(3.2f, 3.6f);
        glVertex2f(3.2f, 3.9f);

        //Neck
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(1.0f, 3.0f);
        glVertex2f(1.0f, 2.7f);
        glVertex2f(4.0f, 2.7f);
        glVertex2f(4.0f, 3.0f);



        //Left Leg
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.7f, 1.7f);
        glVertex2f(0.7f, 1.3f);
        glVertex2f(1.9f, 1.3f);
        glVertex2f(1.9f, 1.7f);

        //Right Leg
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(4.3f, 1.7f);
        glVertex2f(4.3f, 1.3f);
        glVertex2f(3.1f, 1.3f);
        glVertex2f(3.1f, 1.7f);

        //Left Hand
        glColor3f(0.90f, 0.0f, 0.0f);
        glVertex2f(0.6f, 3.6f);
        glVertex2f(0.6f, 2.1f);
        glVertex2f(0.91f, 2.1f);
        glVertex2f(0.91f, 3.6f);

        //Right Hand
        glColor3f(0.90f, 0.0f, 0.0f);
        glVertex2f(4.09f, 3.6f);
        glVertex2f(4.09f, 2.1f);
        glVertex2f(4.4f, 2.1f);
        glVertex2f(4.4f, 3.6f);

        glEnd();

        glBegin(GL_QUADS);
        //Body
        glColor3f(0.88f, 0.0f, 0.0f);
        glVertex2f(1.05f, 2.7f);
        glColor3f(0.88f, 0.0f, 0.39f);
        glVertex2f(1.05f, 1.8f);
        glVertex2f(3.95f, 1.8f);
        glVertex2f(3.95f, 2.7f);
        glEnd();


        glBegin(GL_TRIANGLES);
        // Top Spikes
        glColor3f(1.0f, 1.0f, 0.86f);
        glVertex2f(1.0f, 6.09f);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(2.0f, 6.09f);
        glVertex2f(1.5f, 7.2f);

        glColor3f(1.0f, 1.0f, 0.86f);
        glVertex2f(2.0f, 6.09f);
        glVertex2f(3.0f, 6.09f);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(2.5f, 7.5f);

        glColor3f(1.0f, 1.0f, 0.86f);
        glVertex2f(3.0f, 6.09f);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(4.0f, 6.09f);
        glVertex2f(3.5f, 7.2f);

        //Tie
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(2.0f, 2.7f);
        glVertex2f(3.0f, 2.7f);
        glVertex2f(2.5f, 1.9f);

        glEnd();

        glPopMatrix();


        // Monsters
        monster_Spawan(0,my1+m1);

        monster_Spawan(5,my2+m2);

        monster_Spawan(10,my3+m3);

        monster_Spawan(15,my4+m4);

        score_Board();


        // KILLS
        int number = kills;
        stringstream strs;
        strs << number;
        string temp_str = strs.str();
        char* char_type = (char*) temp_str.c_str();
        RenderString(17.0f, 31.0f, GLUT_BITMAP_TIMES_ROMAN_24, char_type,1.0f,1.0f,1.0f);


    }



    // Game Over
    if(score == 0)
    {
        // Background Quads
        glBegin(GL_QUADS);
        glColor3f(0.39f, 0.12f, 1.0f);
        glVertex2f(0.0f, 32.0f);
        glVertex2f(0.0f, 0.0f);
        glColor3f(0.70f, 0.0f, 0.85f);
        glVertex2f(20.0f, 0.0f);
        glColor3f(0.70f, 0.0f, 0.85f);
        glVertex2f(20.0f, 32.0f);

        glEnd();

        //glColor3f(0.49f, 0.18f, 1.0f);
        glColor3f(0.80f, 0.0f, 0.85f);
        circle(10,16,6,6);

        glColor3f(0.39f, 0.12f, 1.0f);
        circle(10,16,3,3);

        // Game OVER
        RenderString(8.0f, 15.8f, GLUT_BITMAP_TIMES_ROMAN_24, "GAME OVER!",1.0f,1.0f,1.0f);

        // By
        RenderString(8.0f, 5.8f, GLUT_BITMAP_TIMES_ROMAN_24, "Project By-",1.0f,1.0f,1.0f);
        // Credit
        RenderString(8.0f, 4.8f, GLUT_BITMAP_TIMES_ROMAN_24, "Ayon Roy",1.0f,1.0f,1.0f);

        PlaySound(NULL, 0, 0);
    }


//    srand (time(NULL));
//    cout<<(1 + ( rand() % ( 10 - 1 + 1 ) ));


    glFlush();
    // Continues Portal
    if(u >= 20.0)
        u = 0.0;

    if(u < 0.0)
        u = 15.0;

    glutPostRedisplay();
}

void spe_key(int key, int x, int y)
{

    switch (key)
    {

    case GLUT_KEY_LEFT:
        u -=5; //to move the car left when left key pressed. To make movement faster or slower, try changing values of u
        glutPostRedisplay();
        break;

    case GLUT_KEY_RIGHT:
        u +=5;
        glutPostRedisplay();
        break;


    default:
        break;
    }
}

void my_keyboard(unsigned char key, int x, int y)
{

    switch (key)
    {
    case 'r':
        if(score == 0)
        {
            score = 5;
            my1=my2=my3=my4=5.0;
            kills = 0;
            glutPostRedisplay();
        }
        break;
    case 'p':
        PlaySound("Quickly and Without Fail.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
        break;
    case 'o':
        PlaySound("2 Pianos Cover Accel World.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
        break;
    case 'm':
        PlaySound(NULL, 0, 0);
        break;

    default:
        break;
    }
}

void my_mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        PlaySound("2 Pianos Cover Accel World.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
        break;
    case GLUT_RIGHT_BUTTON:
        PlaySound(NULL, 0, 0);
        break;
    default:
        break;
    }
}


int main()
{
    glutInitWindowSize(400,640);
    glutInitWindowPosition(300,20);
    glutCreateWindow("SpikeUP | Ayon");
    init();
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(my_keyboard);
    glutMouseFunc(my_mouse);
    srand (time(NULL));
    glutTimerFunc(delay, update, 0);
    glutMainLoop();
    return 0;
}
