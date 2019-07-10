#include <iostream>
#include <gl>
#include <string>
using namespace std;
float xDondur = 0, // x eksine ve y eksene gore dondurma 
yDondur = -15;

float xdiff = 0  // 
, ydiff = 0; // 
int mouseBasildiMi = 0; //OLU�AN �IKTIMIZI MOUSE �LE HAREKET ET��RMEM�Z ���N �LK BA�TA TANIMLIYORUZ
void printtext(float x, float y, string yazilacakText) //bu k�s�mda s�cakl�k g�stergelerinin yan�na yazd���m�z a��klamalar�n stringlerini tek tek yazd�rd�k. 
{
	
	glColor3f(1.0f, 1.0f, 1.0f); //Ge�erli rengin ayrlanmas�n� sa�lad�k.

	glRasterPos2f(x, y); //Piksel i�lemleri i�in tarama konumunu belirttik.
	for (int i = 0; i < yazilacakText.size(); i++) //bu for d�ng�s�nde stringleri tek tek yazd�rd�k.
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, yazilacakText[i]); //glutBitmapCharacter OpenGL kullanarak bir bitmap karakteri olu�turur
	}
}
void drawBox() // mavi ye�il ve k�rm�z� katmanlar� �izebilmemiz olu�turdu�umuz fonksiyon
{
	glBegin(GL_QUADS);
	// Mavi katman (su seviyesi)
	glColor3f(0.0f, 0.0f, 1.0f);
	// UST k�s�mda her bir 4 k��e i�in konumunu belirledik
	glVertex3f(-0.5f, 0.5f, 1.1f);
	glVertex3f(0.5f, 0.5f, 1.1f);
	glVertex3f(0.5f, 0.5f, -1.1f);
	glVertex3f(-0.5f, 0.5f, -1.1f);
	//sa� k�s�mda her bir 4 k��e i�in konumunu belirledik
	glVertex3f(0.5f, 0.3f, -1.1f);
	glVertex3f(0.5f, 0.5f, -1.1f);
	glVertex3f(0.5f, 0.5f, 1.1f);
	glVertex3f(0.5f, 0.3f, 1.1f);
	//�st k�s�mda her bir 4 k��e i�in konumunu belirledik
	glVertex3f(-0.5f, 0.5f, 1.1f);
	glVertex3f(0.5f, 0.5f, 1.1f);
	glVertex3f(0.5f, 0.3f, 1.1f);
	glVertex3f(-0.5f, 0.3f, 1.1f);
	//sol k�s�mda her bir 4 k��e i�in konumunu belirledik
	glVertex3f(-0.5f, 0.3f, 1.1f);
	glVertex3f(-0.5f, 0.5f, 1.1f);
	glVertex3f(-0.5f, 0.5f, -1.1f);
	glVertex3f(-0.5f, 0.3f, -1.1f);
	// ARKA k�s�mda her bir 4 k��e i�in konumunu belirledik
	glVertex3f(-0.5f, 0.3f, -1.1f);
	glVertex3f(-0.5f, 0.5f, -1.1f);
	glVertex3f(0.5f, 0.5f, -1.1f);
	glVertex3f(0.5f, 0.3f, -1.1f);

	//Ye�il katman (1000 metre derinli�inde) 
	glColor3f(0.0f, 1.0f, 0.0f);
	//ye�il katman i�in �st k�sm�nda her bir 4 k��e i�in konumunu belirledik
	glVertex3f(-0.5f, 0.3f, 1.1f);
	glVertex3f(0.5f, 0.3f, 1.1f);
	glVertex3f(0.5f, 0.3f, -1.1f);
	glVertex3f(-0.5f, 0.3f, -1.1f);
	//ye�il katman i�in sa� k�sm�nda her bir 4 k��e i�in konumunu belirledik
	glVertex3f(0.5f, 0.1f, -1.1f);
	glVertex3f(0.5f, 0.3f, -1.1f);
	glVertex3f(0.5f, 0.3f, 1.1f);
	glVertex3f(0.5f, 0.1f, 1.1f);
	//ye�il katman i�in alt k�sm�nda her bir 4 k��e i�in konumunu belirledik
	glVertex3f(-0.5f, 0.3f, 1.1f);
	glVertex3f(0.5f, 0.3f, 1.1f);
	glVertex3f(0.5f, 0.1f, 1.1f);
	glVertex3f(-0.5f, 0.1f, 1.1f);
	//ye�il katman i�in sol k�sm�nda her bir 4 k��e i�in konumunu belirledik
	glVertex3f(-0.5f, 0.1f, 1.1f);
	glVertex3f(-0.5f, 0.3f, 1.1f);
	glVertex3f(-0.5f, 0.3f, -1.1f);
	glVertex3f(-0.5f, 0.1f, -1.1f);
	//ye�il katman i�in arka k�sm�nda her bir 4 k��e i�in konumunu belirledik
	glVertex3f(-0.5f, 0.1f, -1.1f);
	glVertex3f(-0.5f, 0.3f, -1.1f);
	glVertex3f(0.5f, 0.3f, -1.1f);
	glVertex3f(0.5f, 0.1f, -1.1f);


	//K�rm�z� katman (2000 metre derinli�inde) 
	glColor3f(1.0f, 0.0f, 0.0f);
	//k�rm�z� katman i�in �st k�s�mda her bir 4 k��e i�in koordinatlar�n� belirledik
	glVertex3f(-0.5f, -0.1f, 1.1f);
	glVertex3f(-0.5f, -0.1f, -1.1f);
	glVertex3f(0.5f, -0.1f, -1.1f);
	glVertex3f(0.5f, -0.1f, 1.1f);
	//k�rm�z� katman i�in sa� k�s�mda her bir 4 k��e i�in koordinatlar�n� belirledik
	glVertex3f(0.5f, -0.1f, -1.1f);
	glVertex3f(0.5f, 0.1f, -1.1f);
	glVertex3f(0.5f, 0.1f, 1.1f);
	glVertex3f(0.5f, -0.1f, 1.1f);
	//k�rm�z� katman i�in alt k�s�mda her bir 4 k��e i�in koordinatlar�n� belirledik
	glVertex3f(-0.5f, -0.1f, 1.1f);
	glVertex3f(0.5f, -0.1f, 1.1f);
	glVertex3f(0.5f, 0.1f, 1.1f);
	glVertex3f(-0.5f, 0.1f, 1.1f);
	//k�rm�z� katman i�in sol k�s�mda her bir 4 k��e i�in koordinatlar�n� belirledik
	glVertex3f(-0.5f, 0.1f, 1.1f);
	glVertex3f(-0.5f, -0.1f, 1.1f);
	glVertex3f(-0.5f, -0.1f, -1.1f);
	glVertex3f(-0.5f, 0.1f, -1.1f);
	//k�rm�z� katman i�in arka k�s�mda her bir 4 k��e i�in koordinatlar�n� belirledik
	glVertex3f(-0.5f, 0.1f, -1.1f);
	glVertex3f(-0.5f, -0.1f, -1.1f);
	glVertex3f(0.5f, -0.1f, -1.1f);
	glVertex3f(0.5f, 0.1f, -1.1f);
	glEnd();
}

void init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);//glEnable GL �zelliklerini etkinle�tirme veya devre d��� b�rakmay� sa�lar.
							//Derinlik arabelle�ini g�nceller
	glDepthFunc(GL_LEQUAL);//derinlik tamponu kar��la�t�rmalar� i�in kullan�lan de�eri belirtir
	glClearDepth(1.0f); //derinlik arabelle�i i�in net de�eri belirtir
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



void specialKeys(int key, int x, int y) { //y�n tu�lar� ile hareket ettirmemiz i�in bu fonksiyonu kulland�k

	//  sa� y�n tu�u ile 5 derece d�nd�rd�k
	if (key == GLUT_KEY_RIGHT)
		yDondur += 5;
	//  sol y�n tu�u ile 5 derece d�nd�rd�k
	else if (key == GLUT_KEY_LEFT)
		yDondur -= 5;
	else if (key == GLUT_KEY_UP)
		xDondur += 5;
	else if (key == GLUT_KEY_DOWN)
		xDondur -= 5;
	// ekran g�ncellemelerini yapt�k
	glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)//mouse ile hareket ettirmeyi sa�layan fonksiyonu yazd�k
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
void mouseMotion(int x, int y)//e�er bir t�klanma olmu�sa ger�ekle�en olay� yapan fonksiyonu yazd�k
{
	if (mouseBasildiMi)
	{
		yDondur = x - xdiff;
		xDondur = y + ydiff;
		glutPostRedisplay();
	}
}

int main(int argc, char *argv[])//main k�sm�nda yapt���m�z fonksiyonlara aksiyon verdik
{
	glutInit(&argc, argv);
	glutInitWindowPosition(350, 60);
	glutInitWindowSize(1280, 720);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("OKYANUSLAR'IN SICAKLIK ALANLARI");
	glutDisplayFunc(display);//ekranda g�z�kmezi i�in aksiyon verdik
	glutMouseFunc(mouse);//Mouse ile t�klanmas� sa�lad�k aksiyon verdik
	glutMotionFunc(mouseMotion);
	glutSpecialFunc(specialKeys);//oklarla hareket ettirmemiz i�in aksiyon verdik
	glutMainLoop();
	return 0;
}