#include <iostream>
#include <Windows.h>
#include <glut.h>
#include <math.h>


using namespace std;

//Objek Bergerak

float xr = 0, yr = 0; //untuk mengatur objek bergerak
const double phi = 3.14;

void lingkaran(int r, int n, int xt, int yt) {
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 306; i++) {
        float sudut = i * (2 * phi / n);
        float x = xt + r * cos(sudut);
        float y = yt + r * sin(sudut);
        glVertex2f(x, y);
    }
    glEnd;
}

void unit(void)
{
    glPointSize(4.0); // ukuran titik 4 x 4 pixel
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLineWidth(4.0f);
    gluOrtho2D(0.0, 500.0, 0.0, 400.0);
}

void fungsicallback(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.1f, 0.6f, 0.9f);
    glBegin(GL_POLYGON);
    glVertex2i(0, 100); //langit
    glColor3ub(255, 255, 255);
    glVertex2i(0, 600);
    glVertex2i(1000, 600);
    glColor3f(0.1f, 0.6f, 0.9f);
    glVertex2i(1000, 100);
    glEnd();

    glColor3f(0.1f, 0.7f, 0.2f);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0); //halaman
    glVertex2i(0, 100);
    glVertex2i(1000, 100);
    glVertex2i(1000, 0);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(210, 100); //tembok
    glVertex2i(210, 180);
    glVertex2i(310, 180);
    glVertex2i(310, 100);
    glEnd();


    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(210, 220); //atap
    glVertex2i(310, 220);
    glColor3ub(255, 255, 255);
    glVertex2i(330, 180);
    glVertex2i(190, 180);
    glEnd();


    glColor3f(0.9f, 0.3f, 0.2f);
    glBegin(GL_POLYGON);
    glVertex2i(220, 100);
    glVertex2i(220, 155); //pintu
    glVertex2i(255, 155);
    glVertex2i(255, 100);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS); //gagang pintu
    glVertex2i(250, 125);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2i(210, 100); // Garis tembok
    glVertex2i(210, 180);
    glVertex2i(310, 180);
    glVertex2i(310, 100);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(220, 100); // garis pintu
    glVertex2i(220, 155);
    glVertex2i(255, 155);
    glVertex2i(255, 100);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(210, 220); // garis atap
    glVertex2i(310, 220);
    glVertex2i(330, 180);
    glVertex2i(190, 180);
    glEnd();


    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(265, 135);
    glVertex2i(265, 155); //jendela1
    glVertex2i(285, 155);
    glVertex2i(285, 135);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(285, 135);
    glVertex2i(285, 155); //jendela2
    glVertex2i(305, 155);
    glVertex2i(305, 135);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(265, 115);
    glVertex2i(265, 135); //jendela3
    glVertex2i(285, 135);
    glVertex2i(285, 115);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(285, 115);
    glVertex2i(285, 135); //jendela4
    glVertex2i(305, 135);
    glVertex2i(305, 115);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2i(265, 135);
    glVertex2i(265, 155); // garis jendela1
    glVertex2i(285, 155);
    glVertex2i(285, 135);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(285, 135);
    glVertex2i(285, 155); //garis jendela2
    glVertex2i(305, 155);
    glVertex2i(305, 135);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(265, 115);
    glVertex2i(265, 135); //garis jendela3
    glVertex2i(285, 135);
    glVertex2i(285, 115);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(285, 115);
    glVertex2i(285, 135); //garis jendela4
    glVertex2i(305, 135);
    glVertex2i(305, 115);
    glEnd();

    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(220, 100);
    glVertex2i(270, 100); //jalan1
    glVertex2i(280, 30);
    glVertex2i(210, 30);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(149, 80);
    glVertex2i(160, 120); //rumput kanan1
    glVertex2i(161, 120);
    glVertex2i(153, 80);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(149, 80);
    glVertex2i(150, 120); //rumput tengah1
    glVertex2i(151, 120);
    glVertex2i(152, 80);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(151, 80);
    glVertex2i(140, 120); //rumput kiri1
    glVertex2i(141, 120);
    glVertex2i(147, 80);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(349, 80);
    glVertex2i(360, 120); //rumput kanan2
    glVertex2i(361, 120);
    glVertex2i(353, 80);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(349, 80);
    glVertex2i(350, 120); //rumput tengah2
    glVertex2i(351, 120);
    glVertex2i(352, 80);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(351, 80);
    glVertex2i(340, 120); //rumput kiri2
    glVertex2i(341, 120);
    glVertex2i(347, 80);
    glEnd();

    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(0, 30); //jalan2
    glVertex2i(500, 30);
    glVertex2i(500, 0);
    glEnd();

    glColor3f(0.8f, 0.3f, .2f);
    glBegin(GL_POLYGON);
    glVertex2i(40, 60);
    glVertex2i(30, 80); //vas bunga
    glVertex2i(70, 80);
    glVertex2i(60, 60);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(49, 80);
    glVertex2i(49, 120); //batang
    glVertex2i(51, 120);
    glVertex2i(51, 80);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(49, 80);
    glVertex2i(60, 120); //daun kanan
    glVertex2i(61, 120);
    glVertex2i(53, 80);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(51, 80);
    glVertex2i(30, 120); //daun kiri
    glVertex2i(31, 120);
    glVertex2i(47, 80);
    glEnd();

    glColor3f(1.0f, 0.5f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(45, 110);
    glVertex2i(45, 120); //bunga
    glVertex2i(55, 120);
    glVertex2i(55, 110);
    glEnd();

    glColor3f(0.8f, 0.3f, .2f);
    glBegin(GL_POLYGON);
    glVertex2i(60, 60);
    glVertex2i(50, 80); //vas bunga2
    glVertex2i(90, 80);
    glVertex2i(80, 60);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(69, 80);
    glVertex2i(69, 120); //batang2
    glVertex2i(71, 120);
    glVertex2i(71, 80);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(69, 80);
    glVertex2i(80, 120); //daun kanan2
    glVertex2i(81, 120);
    glVertex2i(73, 80);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(71, 80);
    glVertex2i(60, 110); //daun kiri2
    glVertex2i(61, 110);
    glVertex2i(67, 80);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.7f);
    glBegin(GL_POLYGON);
    glVertex2i(65, 110);
    glVertex2i(65, 120); //bunga2
    glVertex2i(75, 120);
    glVertex2i(75, 110);
    glEnd();

    glColor3f(0.8f, 0.3f, .2f);
    glBegin(GL_POLYGON);
    glVertex2i(80, 60);
    glVertex2i(70, 80); //vas bunga3
    glVertex2i(110, 80);
    glVertex2i(100, 60);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(89, 80);
    glVertex2i(89, 120); //batang3
    glVertex2i(91, 120);
    glVertex2i(91, 80);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(89, 80);
    glVertex2i(100, 120); //daun kanan3
    glVertex2i(101, 120);
    glVertex2i(93, 80);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(90, 80);
    glVertex2i(80, 110); //daun kiri3
    glVertex2i(81, 110);
    glVertex2i(87, 80);
    glEnd();

    glColor3f(0.53f, 0.12f, 0.47f);
    glBegin(GL_POLYGON);
    glVertex2i(85, 110);
    glVertex2i(85, 120); //bunga3
    glVertex2i(95, 120);
    glVertex2i(95, 110);
    glEnd();

    glColor3f(0.8f, 0.3f, .2f);
    glBegin(GL_POLYGON);
    glVertex2i(390, 60);
    glVertex2i(380, 80); //vas bunga4
    glVertex2i(420, 80);
    glVertex2i(410, 60);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(399, 80);
    glVertex2i(399, 120); //batang4
    glVertex2i(401, 120);
    glVertex2i(401, 80);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(399, 80);
    glVertex2i(410, 120); //daun kanan4
    glVertex2i(411, 120);
    glVertex2i(403, 80);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(401, 80);
    glVertex2i(380, 120); //daun kiri4
    glVertex2i(381, 120);
    glVertex2i(397, 80);
    glEnd();

    glColor3f(1.0f, 0.5f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(395, 110);
    glVertex2i(395, 120); //bunga4
    glVertex2i(405, 120);
    glVertex2i(405, 110);
    glEnd();

    glColor3f(0.8f, 0.3f, .2f);
    glBegin(GL_POLYGON);
    glVertex2i(410, 60);
    glVertex2i(400, 80); //vas bunga5
    glVertex2i(440, 80);
    glVertex2i(430, 60);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(419, 80);
    glVertex2i(419, 120); //batang5
    glVertex2i(421, 120);
    glVertex2i(421, 80);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(419, 80);
    glVertex2i(430, 120); //daun kanan5
    glVertex2i(431, 120);
    glVertex2i(423, 80);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(421, 80);
    glVertex2i(410, 110); //daun kiri5
    glVertex2i(411, 110);
    glVertex2i(417, 80);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.7f);
    glBegin(GL_POLYGON);
    glVertex2i(415, 110);
    glVertex2i(415, 120); //bunga5
    glVertex2i(425, 120);
    glVertex2i(425, 110);
    glEnd();

    glColor3f(0.8f, 0.3f, .2f);
    glBegin(GL_POLYGON);
    glVertex2i(430, 60);
    glVertex2i(420, 80); //vas bunga6
    glVertex2i(460, 80);
    glVertex2i(450, 60);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(439, 80);
    glVertex2i(439, 120); //batang6
    glVertex2i(441, 120);
    glVertex2i(441, 80);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(439, 80);
    glVertex2i(450, 120); //daun kanan6
    glVertex2i(451, 120);
    glVertex2i(443, 80);
    glEnd();

    glColor3f(0.5f, 1.0f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(440, 80);
    glVertex2i(430, 110); //daun kiri6
    glVertex2i(431, 110);
    glVertex2i(437, 80);
    glEnd();

    glColor3f(0.53f, 0.12f, 0.47f);
    glBegin(GL_POLYGON);
    glVertex2i(435, 110);
    glVertex2i(435, 120); //bunga6
    glVertex2i(445, 120);
    glVertex2i(445, 110);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    lingkaran(20, 45, 460, 375); //matahari
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(10 + xr, 320 + yr);
    glVertex2f(30 + xr, 320 + yr); //sayap atas pesawat
    glVertex2f(40 + xr, 300 + yr);
    glVertex2f(20 + xr, 300 + yr);
    glEnd();
    
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_QUADS);
    glVertex2f(20 + xr, 300 + yr);
    glVertex2f(100 + xr, 300 + yr); //badan pesawat
    glVertex2f(100 + xr, 285 + yr);
    glVertex2f(40 + xr, 285 + yr);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(45 + xr, 270 + yr);
    glVertex2f(60 + xr, 270 + yr); //sayap pesawat
    glVertex2f(85 + xr, 285 + yr);
    glVertex2f(55 + xr, 285 + yr);
    glEnd();

    glColor3f(0.6f, 0.6f, 0.6f);
    lingkaran(5 , 20 , 100 + xr, 290 + yr); //kepala pesawat
    glEnd();

    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
}


//Mengatur fungsi callback 
void specialkey(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:   // ketikan panah atas ditekan
        yr = yr + 1;
        cout << y << endl;
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN: // ketika panah bawah ditekan
        yr--;
        cout << y << endl;
        glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT: // ketika panah kiri ditekan
        xr--;
        cout << x << endl;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:    // ketika panah kanan ditekan
        xr++;
        cout << x << endl;
        glutPostRedisplay();
        break;
    }
}

INT main(int argc, char** argv)
{
    printf("Use array key");
    glutInit(&argc, argv); // inisialisasi toolkit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // display
    glutInitWindowSize(1000, 600); // ukuran window
    glutInitWindowPosition(100, 150); // posisi window di layar
    glutCreateWindow("Pesawat Terbang"); // buka screen window
    glutDisplayFunc(fungsicallback); // registrasi fungsi menggambar
    unit();
    glutSpecialFunc(specialkey);
    glutMainLoop(); // berulang terus-menerus
}