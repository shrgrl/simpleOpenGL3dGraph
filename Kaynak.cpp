#include <iostream>
#include <gl>
#include <string>
using namespace std;
float xDondur = 0, // x eksine ve y eksene gore dondurma 
yDondur = -15;

float xdiff = 0  // 
, ydiff = 0; // 
int mouseBasildiMi = 0; //OLUÞAN ÇIKTIMIZI MOUSE ÝLE HAREKET ETÝÝRMEMÝZ ÝÇÝN ÝLK BAÞTA TANIMLIYORUZ
void printtext(float x, float y, string yazilacakText) //bu kýsýmda sýcaklýk göstergelerinin yanýna yazdýðýmýz açýklamalarýn stringlerini tek tek yazdýrdýk. 
{
	
	glColor3f(1.0f, 1.0f, 1.0f); //Geçerli rengin ayrlanmasýný saðladýk.

	glRasterPos2f(x, y); //Piksel iþlemleri için tarama konumunu belirttik.
	for (int i = 0; i < yazilacakText.size(); i++) //bu for döngüsünde stringleri tek tek yazdýrdýk.
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, yazilacakText[i]); //glutBitmapCharacter OpenGL kullanarak bir bitmap karakteri oluþturur
	}
}
void drawBox() // mavi yeþil ve kýrmýzý katmanlarý çizebilmemiz oluþturduðumuz fonksiyon
{
	glBegin(GL_QUADS);
	// Mavi katman (su seviyesi)
	glColor3f(0.0f, 0.0f, 1.0f);
	// UST kýsýmda her bir 4 köþe için konumunu belirledik
	glVertex3f(-0.5f, 0.5f, 1.1f);
	glVertex3f(0.5f, 0.5f, 1.1f);
	glVertex3f(0.5f, 0.5f, -1.1f);
	glVertex3f(-0.5f, 0.5f, -1.1f);
	//sað kýsýmda her bir 4 köþe için konumunu belirledik
	glVertex3f(0.5f, 0.3f, -1.1f);
	glVertex3f(0.5f, 0.5f, -1.1f);
	glVertex3f(0.5f, 0.5f, 1.1f);
	glVertex3f(0.5f, 0.3f, 1.1f);
	//üst kýsýmda her bir 4 köþe için konumunu belirledik
	glVertex3f(-0.5f, 0.5f, 1.1f);
	glVertex3f(0.5f, 0.5f, 1.1f);
	glVertex3f(0.5f, 0.3f, 1.1f);
	glVertex3f(-0.5f, 0.3f, 1.1f);
	//sol kýsýmda her bir 4 köþe için konumunu belirledik
	glVertex3f(-0.5f, 0.3f, 1.1f);
	glVertex3f(-0.5f, 0.5f, 1.1f);
	glVertex3f(-0.5f, 0.5f, -1.1f);
	glVertex3f(-0.5f, 0.3f, -1.1f);
	// ARKA kýsýmda her bir 4 köþe için konumunu belirledik
	glVertex3f(-0.5f, 0.3f, -1.1f);
	glVertex3f(-0.5f, 0.5f, -1.1f);
	glVertex3f(0.5f, 0.5f, -1.1f);
	glVertex3f(0.5f, 0.3f, -1.1f);

	//Yeþil katman (1000 metre derinliðinde) 
	glColor3f(0.0f, 1.0f, 0.0f);
	//yeþil katman için üst kýsmýnda her bir 4 köþe için konumunu belirledik
	glVertex3f(-0.5f, 0.3f, 1.1f);
	glVertex3f(0.5f, 0.3f, 1.1f);
	glVertex3f(0.5f, 0.3f, -1.1f);
	glVertex3f(-0.5f, 0.3f, -1.1f);
	//yeþil katman için sað kýsmýnda her bir 4 köþe için konumunu belirledik
	glVertex3f(0.5f, 0.1f, -1.1f);
	glVertex3f(0.5f, 0.3f, -1.1f);
	glVertex3f(0.5f, 0.3f, 1.1f);
	glVertex3f(0.5f, 0.1f, 1.1f);
	//yeþil katman için alt kýsmýnda her bir 4 köþe için konumunu belirledik
	glVertex3f(-0.5f, 0.3f, 1.1f);
	glVertex3f(0.5f, 0.3f, 1.1f);
	glVertex3f(0.5f, 0.1f, 1.1f);
	glVertex3f(-0.5f, 0.1f, 1.1f);
	//yeþil katman için sol kýsmýnda her bir 4 köþe için konumunu belirledik
	glVertex3f(-0.5f, 0.1f, 1.1f);
	glVertex3f(-0.5f, 0.3f, 1.1f);
	glVertex3f(-0.5f, 0.3f, -1.1f);
	glVertex3f(-0.5f, 0.1f, -1.1f);
	//yeþil katman için arka kýsmýnda her bir 4 köþe için konumunu belirledik
	glVertex3f(-0.5f, 0.1f, -1.1f);
	glVertex3f(-0.5f, 0.3f, -1.1f);
	glVertex3f(0.5f, 0.3f, -1.1f);
	glVertex3f(0.5f, 0.1f, -1.1f);


	//Kýrmýzý katman (2000 metre derinliðinde) 
	glColor3f(1.0f, 0.0f, 0.0f);
	//kýrmýzý katman için üst kýsýmda her bir 4 köþe için koordinatlarýný belirledik
	glVertex3f(-0.5f, -0.1f, 1.1f);
	glVertex3f(-0.5f, -0.1f, -1.1f);
	glVertex3f(0.5f, -0.1f, -1.1f);
	glVertex3f(0.5f, -0.1f, 1.1f);
	//kýrmýzý katman için sað kýsýmda her bir 4 köþe için koordinatlarýný belirledik
	glVertex3f(0.5f, -0.1f, -1.1f);
	glVertex3f(0.5f, 0.1f, -1.1f);
	glVertex3f(0.5f, 0.1f, 1.1f);
	glVertex3f(0.5f, -0.1f, 1.1f);
	//kýrmýzý katman için alt kýsýmda her bir 4 köþe için koordinatlarýný belirledik
	glVertex3f(-0.5f, -0.1f, 1.1f);
	glVertex3f(0.5f, -0.1f, 1.1f);
	glVertex3f(0.5f, 0.1f, 1.1f);
	glVertex3f(-0.5f, 0.1f, 1.1f);
	//kýrmýzý katman için sol kýsýmda her bir 4 köþe için koordinatlarýný belirledik
	glVertex3f(-0.5f, 0.1f, 1.1f);
	glVertex3f(-0.5f, -0.1f, 1.1f);
	glVertex3f(-0.5f, -0.1f, -1.1f);
	glVertex3f(-0.5f, 0.1f, -1.1f);
	//kýrmýzý katman için arka kýsýmda her bir 4 köþe için koordinatlarýný belirledik
	glVertex3f(-0.5f, 0.1f, -1.1f);
	glVertex3f(-0.5f, -0.1f, -1.1f);
	glVertex3f(0.5f, -0.1f, -1.1f);
	glVertex3f(0.5f, 0.1f, -1.1f);
	glEnd();
}

void init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);//glEnable GL özelliklerini etkinleþtirme veya devre dýþý býrakmayý saðlar.
							//Derinlik arabelleðini günceller
	glDepthFunc(GL_LEQUAL);//derinlik tamponu karþýlaþtýrmalarý için kullanýlan deðeri belirtir
	glClearDepth(1.0f); //derinlik arabelleði için net deðeri belirtir
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 1280, 720);
	gluPerspective(55, 1.1 * 1280 / 720, 1, 100 * 1.1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3d(1.0, 1.0, 1.0);
	glLoadIdentity();
	gluLookAt(
		0.0f, 0.0f, 3.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);
	glRotatef(xDondur, 1.0f, 0.0f, 0.0f);
	glRotatef(yDondur, 0.0f, 1.0f, 0.0f);

	drawBox();
	printtext(0.4, 0.60, "Su Seviyesi 22 derece");
	printtext(0.4, 0.30, "1000 metre  10 derece");
	printtext(0.4, 0.0, "2000 metre  5 derece");
	glFlush();
	glutSwapBuffers();
}



void specialKeys(int key, int x, int y) { //yön tuþlarý ile hareket ettirmemiz için bu fonksiyonu kullandýk

	//  sað yön tuþu ile 5 derece döndürdük
	if (key == GLUT_KEY_RIGHT)
		yDondur += 5;
	//  sol yön tuþu ile 5 derece döndürdük
	else if (key == GLUT_KEY_LEFT)
		yDondur -= 5;
	else if (key == GLUT_KEY_UP)
		xDondur += 5;
	else if (key == GLUT_KEY_DOWN)
		xDondur -= 5;
	// ekran güncellemelerini yaptýk
	glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)//mouse ile hareket ettirmeyi saðlayan fonksiyonu yazdýk
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseBasildiMi = 1;
		xdiff = x - yDondur;
		ydiff = -y + xDondur;
	}
	else
		mouseBasildiMi = 0;
}
void mouseMotion(int x, int y)//eðer bir týklanma olmuþsa gerçekleþen olayý yapan fonksiyonu yazdýk
{
	if (mouseBasildiMi)
	{
		yDondur = x - xdiff;
		xDondur = y + ydiff;
		glutPostRedisplay();
	}
}

int main(int argc, char *argv[])//main kýsmýnda yaptýðýmýz fonksiyonlara aksiyon verdik
{
	glutInit(&argc, argv);
	glutInitWindowPosition(350, 60);
	glutInitWindowSize(1280, 720);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("OKYANUSLAR'IN SICAKLIK ALANLARI");
	glutDisplayFunc(display);//ekranda gözükmezi için aksiyon verdik
	glutMouseFunc(mouse);//Mouse ile týklanmasý saðladýk aksiyon verdik
	glutMotionFunc(mouseMotion);
	glutSpecialFunc(specialKeys);//oklarla hareket ettirmemiz için aksiyon verdik
	glutMainLoop();
	return 0;
}