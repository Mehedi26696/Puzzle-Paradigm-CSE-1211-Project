#include "iGraphics.h"
#include <GL/glut.h>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>

void drawHomePage();
void drawStartPage();
void drawnamepage();
void StartButtonClickHandler();
void drawInstPage();
void InstButtonClickHandler();
void BackButtonClickHandler();
void coordinates();
void location_change();
void drawwinpage();
void drawgamepage();
void check_pic();
void drawscorepage();
void drawsettingspage();
void drawaboutuspage();
void drawlosepage();
void musicplay(int n);
void drawleaderboard();
void drawpicpage();

bool homepage=1;
bool startpage=0;
bool gamepage=0;
bool instpage=0;
bool winpage=0;
bool losepage=0;
bool namepage=0;
bool settings=0;
bool about_us=0;
bool leaderboard=0;
bool picpage=0;

bool musicon=1;

int mode =1; //easy mode 
int picc=1;
int moves =0;
int TIME=31000;
char arr[100], str[10];
int index = 0, run = 1;
clock_t start;

struct pic{
	int x;
	int y;
};

struct correct_pic{
	int x;
	int y;
};

struct pic pic[25];
struct correct_pic correct_pic[25];

int openx = 0, openy = 480;
int x = 300, y = 300, r = 20;
bool correct = true;


char picture[2][25][20] = {
   {"image\\52.bmp", "image\\51.bmp", "image\\50.bmp", "image\\49.bmp", "image\\48.bmp",
    "image\\47.bmp", "image\\46.bmp", "image\\45.bmp", "image\\44.bmp", "image\\43.bmp",
    "image\\42.bmp", "image\\41.bmp", "image\\40.bmp", "image\\39.bmp", "image\\38.bmp",
    "image\\37.bmp", "image\\36.bmp", "image\\35.bmp", "image\\34.bmp", "image\\33.bmp",
    "image\\32.bmp", "image\\31.bmp", "image\\30.bmp", "image\\29.bmp", "image\\28.bmp"},
    
   {"image\\25.bmp", "image\\24.bmp", "image\\23.bmp", "image\\22.bmp", "image\\21.bmp",
    "image\\20.bmp", "image\\19.bmp", "image\\18.bmp", "image\\17.bmp", "image\\16.bmp",
    "image\\15.bmp", "image\\14.bmp", "image\\13.bmp", "image\\12.bmp", "image\\11.bmp",
    "image\\10.bmp", "image\\09.bmp", "image\\08.bmp", "image\\07.bmp", "image\\06.bmp",
    "image\\05.bmp", "image\\04.bmp", "image\\03.bmp", "image\\02.bmp", "image\\01.bmp"}
};





char alt[25][20];



void iDraw() {
	iClear();
	if(homepage){
		drawHomePage();
	}
	else if(startpage){
		drawStartPage();
	}
	else if(gamepage)
	{

		iShowBMP2(600,0,"image\\gamepage.png",0);
		//iSetColor(144, 238, 144);
		clock_t end = clock();
		double time_diff = (start - end) / CLOCKS_PER_SEC;
		char str2[10];
		sprintf(str2, "%.2lf", time_diff);
		if (time_diff < 1)
		{
			homepage = 0;
			startpage = 0;
			instpage = 0;
			winpage = 0;
			gamepage = 0;
			namepage = 0;
			settings = 0;
			about_us = 0;
			losepage = 1;
			leaderboard=0;
			picpage=0;
		}
		//iText(730, 450, "TIME :", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(770, 420, str2, GLUT_BITMAP_TIMES_ROMAN_24);

		//iSetColor(149, 33, 246);
		//iFilledRectangle(0, 0, 700, 700);
		//iSetColor(255, 255, 255);
		//iText(740, 330, "MOVES ->", GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(str, "%i", moves);
		//iSetColor(255, 0, 0);
		iText(800,236, str, GLUT_BITMAP_TIMES_ROMAN_24);
		int count = 1;
		for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (i == 0 && j == 0)
						continue;
					else
					{
						iShowBMP(pic[count].x, pic[count].y, picture[picc][count]);
						count++;
					}
				}
			}

		check_pic();
		if (correct == true)
		{
			printf("CONGOOOOO\n");
			homepage = 0;
			startpage = 0;
			instpage = 0;
			winpage = 1;
			gamepage = 0;
			namepage = 0;
			settings = 0;
			about_us = 0;
			losepage = 0;
			leaderboard =0;
			picpage=0;
		}
		
	}else if(namepage){
		drawnamepage();
	}else if(instpage){
		drawInstPage();
	}else if(winpage){
		drawwinpage();
	}else if(settings){
		drawsettingspage();
	}else if(about_us){
		drawaboutuspage();
	}else if(losepage){
		drawlosepage();
	}else if(leaderboard){
		drawleaderboard();
	}else if(picpage){
		drawpicpage();
	}
}

void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("x = %d, y= %d\n", mx, my);
		if (homepage && (mx >= 385 && mx <= 615) && (my >= 363 && my <= 423))
		{
			homepage = 0;
			startpage = 1;
			instpage = 0;
			winpage = 0;
			gamepage = 0;
			namepage = 0;
			settings = 0;
			about_us = 0;
			losepage = 0;
			leaderboard = 0;
			picpage=0;
		}
		else if (homepage && (mx >= 385 && mx <= 615) && (my >= 264 && my <= 324))
		{
			homepage = 0;
			startpage = 0;
			instpage = 1;
			winpage = 0;
			gamepage = 0;
			namepage = 0;
			settings = 0;
			about_us = 0;
			losepage = 0;
			leaderboard = 0;
			picpage=0;
		}
		else if (homepage && (mx >= 385 && mx <= 615) && (my >= 180 && my <= 240))
		{
			homepage = 0;
			startpage = 0;
			instpage = 0;
			winpage = 0;
			gamepage = 0;
			namepage = 0;
			settings = 1;
			about_us = 0;
			losepage = 0;
			leaderboard = 0;
			picpage=0;
		}
		else if (homepage && (mx >= 385 && mx <= 615) && (my >= 80 && my <= 140))
		{
			homepage = 0;
			startpage = 0;
			instpage = 0;
			winpage = 0;
			gamepage = 0;
			namepage = 0;
			settings = 0;
			about_us = 1;
			losepage = 0;
			leaderboard = 0;
			picpage=0;
		}
		else if (startpage && (mx >= 311 && mx <= 692) && (my >= 344 && my <= 430))
		{
			homepage = 0;
			startpage = 0;
			instpage = 0;
			winpage = 0;
			gamepage = 0;
			namepage = 1;
			settings = 0;
			about_us = 0;
			losepage = 0;
			leaderboard = 0;
			picpage=0;
			mode = 1;
		}
		else if (startpage && (mx >= 311 && mx <= 692) && (my >= 174 && my <= 260))
		{
			homepage = 0;
			startpage = 0;
			instpage = 0;
			winpage = 0;
			gamepage = 0;
			namepage = 1;
			settings = 0;
			about_us = 0;
			losepage = 0;
			leaderboard = 0;
			picpage=0;
			mode = 2;
		}
		else if (namepage && (mx >= 312 && mx <= 692) && (my >= 173 && my <= 250))
		{
			homepage = 0;
			startpage = 0;
			instpage = 0;
			winpage = 0;
			gamepage = 0;
			namepage = 0;
			losepage = 0;
			leaderboard = 0;
			picpage=1;
			coordinates();
			location_change();
			run = 1;
			openx = 0, openy = 480;
			moves = 0;
			// PlaySound(0, 0, 0);
			start = clock() + TIME;
		}
		else if ((about_us || startpage || settings || instpage) && 
		(mx >= 0 && mx <= 70) && (my >= 560 && my <= 600))
		{
			homepage = 1;
			startpage = 0;
			instpage = 0;
			winpage = 0;
			gamepage = 0;
			namepage = 0;
			settings = 0;
			about_us = 0;
			losepage = 0;
			leaderboard = 0;
			picpage=0;
		}else if (picpage && (mx >= 0 && mx <= 70) && (my >= 560 && my <= 600))
		{
			homepage = 0;
			startpage = 0;
			instpage = 0;
			winpage = 0;
			gamepage = 0;
			namepage = 1;
			settings = 0;
			about_us = 0;
			losepage = 0;
			leaderboard = 0;
			picpage=0;
		}
		else if (namepage && (mx >= 0 && mx <= 70) && (my >= 560 && my <= 600))
		{
			homepage = 0;
			startpage = 1;
			instpage = 0;
			winpage = 0;
			gamepage = 0;
			namepage = 0;
			settings = 0;
			about_us = 0;
			losepage = 0;
			leaderboard = 0;
			picpage=0;
		}
		else if ((winpage) && (mx >= 252 && mx <=570) && (my >= 67 && my <= 132))
		{
			homepage = 0;
			startpage = 0;
			instpage = 0;
			winpage = 0;
			gamepage = 0;
			namepage = 0;
			settings = 0;
			about_us = 0;
			losepage = 0;
			leaderboard = 1;
			picpage=0;
		}
		else if ((winpage) && (mx >=666 && mx <= 725) && (my >= 72 && my <= 133))
		{
			homepage = 1;
			startpage = 0;
			instpage = 0;
			winpage = 0;
			gamepage = 0;
			namepage = 0;
			settings = 0;
			about_us = 0;
			losepage = 0;
			leaderboard = 0;
			picpage=0;
		}
		else if ((losepage) && (mx >= 385 && mx <= 615) && (my >= 80 && my <= 140))
		{
			homepage = 0;
			startpage = 0;
			instpage = 0;
			winpage = 0;
			gamepage = 0;
			namepage = 0;
			settings = 0;
			about_us = 0;
			losepage = 0;
			leaderboard = 1;
			picpage=0;
		}
		else if ((losepage) && (mx >=470 && mx <= 530) && (my >= 170 && my <= 230))
		{
			homepage = 1;
			startpage = 0;
			instpage = 0;
			winpage = 0;
			gamepage = 0;
			namepage = 0;
			settings = 0;
			about_us = 0;
			losepage = 0;
			leaderboard = 0;
			picpage=0;
		}
		else if (leaderboard &&(mx>=470 && mx<=530) && (my>=47 && my<=105))
		{
			homepage = 1;
			startpage = 0;
			instpage = 0;
			winpage = 0;
			gamepage = 0;
			namepage = 0;
			settings = 0;
			about_us = 0;
			losepage = 0;
			leaderboard = 0;
		}
		else if (picpage)
		{
			if ((mx >= 200 && mx <= 400) && (my >= 200 && my <= 400))
			{
				picc = 0;
				homepage = 0;
				startpage = 0;
				instpage = 0;
				winpage = 0;
				gamepage = 1;
				namepage = 0;
				settings = 0;
				about_us = 0;
				losepage = 0;
				leaderboard = 0;
				picpage = 0;
			}
			else if ((mx >= 600 && mx <= 800) && (my >= 200 && my <= 400))
			{
				picc = 1;
				homepage = 0;
				startpage = 0;
				instpage = 0;
				winpage = 0;
				gamepage = 1;
				namepage = 0;
				settings = 0;
				about_us = 0;
				losepage = 0;
				leaderboard = 0;
				picpage = 0;
			}
		}
		else if (gamepage && mode == 1)
		{
			PlaySoundA("click.wav", NULL,SND_ASYNC);
			//PlaySound("click.wav", NULL, SND_ASYNC);
               moves++;
			int tempx = (mx / 120) * 120;
			int tempy = (my / 120) * 120;
			for (int i = 1; i < 25; i++)
			{
				if (pic[i].x == tempx && pic[i].y == tempy)
				{
					pic[i].x = openx;
					pic[i].y = openy;
					openx = tempx;
					openy = tempy;
					break;
				}
			}
		}
		else if (settings && (mx >= 500 && mx <= 620) && (my >= 300 && my <= 360))
		{
			printf("OHO\n");
			if (musicon)
			{
				musicon = false;
				musicplay(musicon);
			}
			else
			{
				musicon = true;
				musicplay(musicon);
			};
		}
		else if (settings && (mx >= 500 && mx <= 620) && (my >= 200 && my <= 260))
		{
			if(TIME==31000){
				TIME=180000;
			}else{
				TIME=31000;
			}
		}
		else if(gamepage && mode==2){
			int tempx = (mx / 120) * 120;
			int tempy = (my / 120) * 120;
			if((tempx==openx && abs(tempy-openy)==120) 
			|| (tempy==openy && abs(tempx-openx)==120)){
				moves++;
				for (int i = 1; i < 25; i++)
				{
					if (pic[i].x == tempx && pic[i].y == tempy)
					{
						pic[i].x = openx;
						pic[i].y = openy;
						openx = tempx;
						openy = tempy;
						break;
					}
				}
			}
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		
	}
}

void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
	if(namepage) // ENTRY
	{
		if (key != '\b')
		{
			arr[index] = key;
			index++;
			arr[index] = '\0';
		}
		else
		{
			if (index > 0)
			{
				index--;
				arr[index] = '\0';
			}
			else
			{
				index = 0;
			}
		}
	}

	/* if(key == 'k'){
		if(musicon){
			musicon=false;
			PlaySound(0,0,0);
		}else{
			musicon=true;
			PlaySound("bg_music.wav", NULL, SND_ASYNC);
		}
	} */
}

void iSpecialKeyboard(unsigned char key) {
	if (key == GLUT_KEY_END) {
		exit(0);
	}
}

void drawnamepage(){

	//iSetColor(200,200,200);
	//iFilledRectangle(0,560,70,40);
	//iSetColor(0, 0, 0);
	//iText(0, 560, "BACK",GLUT_BITMAP_TIMES_ROMAN_24);

	iShowBMP2(0,0,"image\\namepage.png",0);
	//iSetColor(20, 200, 200);
	//iFilledRectangle(400,150,200,80);

	//iSetColor(0, 0, 0);

	//iText(420, 190, "START GAME",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(255, 255, 255);
    //iFilledRectangle(300, 500, 300, 60);

    iSetColor(0, 255, 0);

    //iText(375, 450, "YOUR NAME", GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(0, 0, 0);
     iText(450, 322, arr, GLUT_BITMAP_HELVETICA_18);
     iText(450 + 11 * index, 322, "_", GLUT_BITMAP_HELVETICA_18);
}

void drawpicpage(){
	/* iSetColor(200,200,200);
	iFilledRectangle(0,560,70,40);
	iSetColor(0, 0, 0);
	iText(0, 560, "BACK",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(200,200,200);
	iFilledRectangle(200,200,200,200);

	iSetColor(0,200,100);
	iFilledRectangle(600,200,200,200); */
	iSetColor(0, 0, 0);
	iShowBMP2(0,0,"image\\chooose_image.png",0);



}

void drawStartPage(){

	iSetColor(200,200,200);
	iFilledRectangle(0,0,70,40);
	//iSetColor(0, 0, 0);
	//iText(0, 560, "BACK",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(20, 200, 0);
	iFilledRectangle(400,450,200,80);

	iSetColor(20, 200, 200);
	iFilledRectangle(400,150,200,80);
	iShowBMP2(0,0,"image\\start-page.jpg",0);
	/*iSetColor(0, 0, 0);

	iText(420, 190, "Hard mode",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(0, 0, 0);

	iText(420, 490, "Easy MOde",GLUT_BITMAP_TIMES_ROMAN_24);*/
}

void drawInstPage(){
	iSetColor(200,200,200);
	//iFilledRectangle(0,560,70,40);
	iSetColor(0, 0, 0);
	//iText(0, 560, "BACK",GLUT_BITMAP_TIMES_ROMAN_24);
	/* iSetColor(200, 200, 200);
	iText(320, 490, "***EKHANE GAME ER INSTRUCTIONS THAKBE***",GLUT_BITMAP_TIMES_ROMAN_24); */
	iSetColor(128,128,128);
	//iFilledRectangle(0,0,1000,600);
	iShowBMP2(0,0,"image\\rules.png",0);
	//iShowBMP2(5,500,"image\\back.bmp",0);
}

void drawlosepage()
{
	iSetColor(200, 200, 200);
	//iText(320, 490, "***YOU LOST!!!***", GLUT_BITMAP_TIMES_ROMAN_24);
	// move dekhanno jaite pare idk
	//iFilledRectangle(385,80,230,60);
	//iSetColor(0,0,0);
	iShowBMP2(0,0,"image\\lose_page.png",0);
	//iText(385,80,"LEADERBOARD", GLUT_BITMAP_TIMES_ROMAN_24);
}

void drawleaderboard()
{

	iShowBMP2(0,0,"image\\leaderboard.png",0);
	// iSetColor(200, 200, 200);
	// iFilledRectangle(0, 560, 70, 40);
	// iSetColor(0, 0, 0);
	// iText(0, 560, "HOME", GLUT_BITMAP_TIMES_ROMAN_24);
	// iSetColor(200, 200, 200);

	//int y_co = 240;
	//iText(350, 250, "NAME", GLUT_BITMAP_TIMES_ROMAN_24);
	//iLine(350, y_co, 420, y_co);
	//iText(500, 250, "MOVES", GLUT_BITMAP_TIMES_ROMAN_24);
	//iLine(500, y_co, 590, y_co);
	//iSetColor(255, 192, 203);

	FILE *ifp = fopen("score.txt", "r");
	if (ifp == NULL)
		printf("Cant open ifp");
	else
	{
		for (int i = 0; i < 3; i++)
		{
			char name[150];
			char point[10];
			//int v;
			fgets(name, 200, ifp);
			fgets(point, 8, ifp);

			iText(354, 322 - i * 70, name, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(660, 322 - i * 70, point, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		fclose(ifp);
	}
}

void drawwinpage()
{
	iSetColor(200, 200, 200);
	iShowBMP2(0,0,"image\\winnerpage.png",0);
	char m[10];
	sprintf(m,"%i",moves);
	iText(562,220,m,GLUT_BITMAP_TIMES_ROMAN_24);
	//iText(320, 490, "***YOU WON***", GLUT_BITMAP_TIMES_ROMAN_24);
	//iFilledRectangle(385,80,230,60);
	//iSetColor(0,0,0);
	//iText(385,80,"LEADERBOARD", GLUT_BITMAP_TIMES_ROMAN_24);
	// ekhane koto move+koto time lagse sheta lagbe
	if (run == 1) // ei if shudhu file e kaj kore kisu output kore na
	{
		FILE *score_read_ptr = fopen("score.txt", "r");
		FILE *out_write_ptr = fopen("out.txt", "w");
		int mind = 0;
		// comparing
		char id[150];
		while (fgets(id, 100, score_read_ptr)){
			
			char point[10];
			fgets(point, 8, score_read_ptr);
			int v = atoi(point);
			if (moves < v && mind == 0)
			{
				fputs(arr, out_write_ptr);
				fprintf(out_write_ptr, "\n");

				fputs(str, out_write_ptr);
				fprintf(out_write_ptr, "\n");

				fputs(id, out_write_ptr);
				fputs(point, out_write_ptr);
				mind++;
			}
			else
			{
				fputs(id, out_write_ptr);
				fputs(point, out_write_ptr);
			}
		}
		fclose(score_read_ptr);
		fclose(out_write_ptr);
		FILE *score_write_ptr = fopen("score.txt", "w");
		FILE *out_read_ptr = fopen("out.txt", "r");

		char temp[200];
		while (fgets(temp, 150, out_read_ptr))
		{
			fputs(temp, score_write_ptr);
		}
		fclose(out_read_ptr);
		fclose(score_write_ptr);
		run++;
	}
}

void drawsettingspage(){

	iSetColor(200,200,200);
	//iFilledRectangle(0,560,70,40);
	//iSetColor(0, 0, 0);
	//iText(0, 560, "BACK",GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(0,0,"image\\settings.png",0);

	iSetColor(200, 200, 200);
	//iText(300, 300, "MUSIC",GLUT_BITMAP_TIMES_ROMAN_24); 
	//iText(300, 200, "TIME",GLUT_BITMAP_TIMES_ROMAN_24); 

	//iFilledRectangle(100, 400, 200, 50);
	//iFilledRectangle(100, 300, 200, 50);
	
	iSetColor(255, 0, 0);
	if(musicon){
		// iSetColor(200, 220, 220);
		// iFilledRectangle(500, 300, 60, 60);
		// iSetColor(0, 0, 0);
        // iText(520, 320, "ON", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(500,315,"image\\on.png",0);
		
	}else{
		// iSetColor(255, 0, 0);
		// iFilledRectangle(500, 300, 60, 60);
		// iSetColor(200, 255, 0);
        // iText(520, 320, "OFF", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(500,315,"image\\off.png",0);
	}

	if(TIME==31000){
		// iSetColor(200, 220, 220);
		// iFilledRectangle(500, 200, 60, 60);
		// iSetColor(0, 0, 0);
        // iText(520, 220, "30s", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(500,213,"image\\30s.png",0);
		
	}else{
		// iSetColor(255, 0, 0);
		// iFilledRectangle(500, 200, 60, 60);
		// iSetColor(200, 255, 0);
        // iText(520, 220, "180s", GLUT_BITMAP_TIMES_ROMAN_24);
		iShowBMP2(500,213,"image\\180s.png",0);
	}

}


void drawaboutuspage(){


	iSetColor(200,200,200);
	//iFilledRectangle(0,560,70,40);
	iSetColor(0, 0, 0);
	//iText(0, 560, "BACK",GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(0,0,"image\\about_us.png",0);

	iSetColor(200, 200, 200);
	//iText(400, 400, "ABOUT US",GLUT_BITMAP_TIMES_ROMAN_24);
}

void drawHomePage(){
	iSetColor(128,128,128);
	iFilledRectangle(0,0,1000,600);
	iShowBMP2(0,0,"image\\main.png",0);

	iSetColor(20, 200, 0);
	//iFilledRectangle(400,400,200,60);
	iSetColor(0, 0, 0);
	//iText(400, 400, "START GAME",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(20, 200, 200);
	//iFilledRectangle(400,300,200,60);
	iSetColor(0, 0, 0);
	//iText(400, 300, "INSTRUCTIONS",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(20, 200, 200);
	//iFilledRectangle(400,200,200,60);
	iSetColor(0, 0, 0);
	//iText(400, 200, "SETTINGS",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(20, 200, 200);
	//iFilledRectangle(400,100,200,60);
	iSetColor(0, 0, 0);
	//iText(400, 100, "ABOUT US",GLUT_BITMAP_TIMES_ROMAN_24);
}

void location_change()
{
	int a = 2, b = 25;
	int box[6];
	srand(time(NULL));

	for (int i = 0; i < 6; i++)
	{
		box[i] = rand() % (b - a) + a;
	label:
		for (int j = 0; j < i; j++)
		{
			if (box[i] == box[j])
			{
				box[i] = rand() % (b - a) + a;
				goto label;
			}
		}
		printf("%d\n", box[i]);
	}
	for (int i = 0; i < 6; i = i + 2)
	{
		pic[box[i]].x = correct_pic[box[i + 1]].x;
		pic[box[i]].y = correct_pic[box[i + 1]].y;
		printf("%d got %d's coordinates\n",box[i],box[i+1]);
		pic[box[i + 1]].x = correct_pic[box[i]].x;
		pic[box[i + 1]].y = correct_pic[box[i]].y;
	}
}

void coordinates()
{
	int n = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			pic[n].x = 0 + j * 120; // storing real addresses
			pic[n].y = 480 - i * 120;
			correct_pic[n].x = pic[n].x; // storing real addresses
			correct_pic[n].y = pic[n].y;
			n++;
		}
	}
}

void check_pic()
{
	int n = 1;
	correct = true;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == 0 && j == 0)
				continue;
			else
			{
				if (pic[n].x != correct_pic[n].x)
				{
					correct = false;
					break;
				}
				if (pic[n].y != correct_pic[n].y)
				{
					correct = false;
					break;
				}
				n++;
			}
		}
	}
}

void musicplay(int music){
	if(music){
		PlaySoundA("The_Painful_Way.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}else{
		PlaySoundA( NULL,NULL,NULL);
	}
}

int main() {
	musicplay(musicon);
	//coordinates();
	//location_change();
	iInitialize(1000, 600, "Puzzle Paradigm");
	return 0;
}