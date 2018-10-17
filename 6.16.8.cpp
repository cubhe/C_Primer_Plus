#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#define NULL 0
#define UP  18432
#define DOWN 20480
#define LEFT 19200
#define RIGHT 19712
#define ESC  283
#define ENTER 7181 
struct snake
{
	int centerx;
	int centery;
	int newx;
	int newy;
	struct snake *next;
};
struct snake *head;

int grade = 60;                     /*控制速度的*******/
int a, b;                        /* 背静遮的 位置*/
void *far1, *far2, *far3, *far4;             /* 蛇身指针 背静遮的指针 虫子*/
int size1, size2, size3, size4;              /* **全局变量**/
int ch = RIGHT;                     /**************存按键 开始蛇的方向为RIGHT***********/
int chy = RIGHT;
int flag = 0;                       /*********判断是否退出游戏**************/
int control = 4;                     /***********判断上次方向和下次方向不冲突***/
int nextshow = 1;                     /*******控制下次蛇身是否显示***************/
int scenterx;                      /***************随即矩形中心坐标***************/
int scentery;
int sx;                         /*******在a b 未改变前 得到他们的值 保证随机矩形也不在此出现*******/
int sy;

/************************蛇身初始化**************************/
void snakede()
{
	struct snake *p1, *p2;
	head = p1 = p2 = (struct snake *)malloc(sizeof(struct snake));
	p1->centerx = 80;
	p1->newx = 80;
	p1->centery = 58;
	p1->newy = 58;
	p1 = (struct snake *)malloc(sizeof(struct snake));
	p2->next = p1;
	p1->centerx = 58;
	p1->newx = 58;
	p1->centery = 58;
	p1->newy = 58;
	p1->next = NULL;
}
/*******************end*******************/
void welcome()            /*************游戏开始界面　，可以选择　速度**********/               
{
	int key;
	int size;
	int x = 240;
	int y = 300;
	int f;
	void *buf;
	setfillstyle(SOLID_FILL, BLUE);
	bar(98, 100, 112, 125);
	setfillstyle(SOLID_FILL, RED);
	bar(98, 112, 112, 114);
	setfillstyle(SOLID_FILL, GREEN);
	bar(100, 100, 110, 125);
	size = imagesize(98, 100, 112, 125);
	buf = malloc(size);
	getimage(98, 100, 112, 125, buf);
	cleardevice();

	setfillstyle(SOLID_FILL, BLUE);
	bar(240, 300, 390, 325);
	outtextxy(193, 310, "speed:");
	setfillstyle(SOLID_FILL, RED);
	bar(240, 312, 390, 314);
	setcolor(YELLOW);
	outtextxy(240, 330, "DOWN");
	outtextxy(390, 330, "UP");
	outtextxy(240, 360, "ENTER to start...");
	outtextxy(270, 200, "SNAKE");
	fei(220, 220);
	feiyang(280, 220);
	yang(340, 220);
	putimage(x, y, buf, COPY_PUT);
	setcolor(RED);
	rectangle(170, 190, 410, 410);
	while (1)
	{
		if (bioskey(1))                      /********8选择速度部分************/
			key = bioskey(0);
		switch (key)
		{
		case ENTER:
			f = 1;
			break;
		case DOWN:
			if (x >= 240)
			{
				putimage(x -= 2, y, buf, COPY_PUT);
				grade++;
				key = 0;
				break;
			}
		case UP:
			if (x <= 375)
			{
				putimage(x += 2, y, buf, COPY_PUT);
				grade--;
				key = 0;
				break;
			}
		}

		if (f == 1)
			break;
	}                           /********** end  ****************/


	free(buf);
}

/*************************随即矩形*****************/
/***********当nextshow 为1的时候才调用此函数**********/

void ran()
{
	int nx;
	int ny;
	int show;         /**********控制是否显示***********/
	int jump = 0;
	struct snake *p;
	p = head;
	if (nextshow == 1)      /***********是否开始随机产生***************/
		while (1)
		{
			show = 1;
			randomize();
			nx = random(14);
			ny = random(14);
			scenterx = nx * 22 + 58;
			scentery = ny * 22 + 58;
			while (p != NULL)
			{
				if (scenterx == p->centerx&&scentery == p->centery || scenterx == sx&&scentery == sy)
				{
					show = 0;
					jump = 1;
					break;
				}
				else
					p = p->next;
				if (jump == 1)
					break;
			}
			if (show == 1)
			{
				putimage(scenterx - 11, scentery - 11, far3, COPY_PUT);
				nextshow = 0;
				break;
			}

		}
}

/***********过关动画**************/
void donghua()
{
	int i;
	cleardevice();
	setbkcolor(BLACK);
	randomize();
	while (1)
	{
		for (i = 0; i <= 5; i++)
		{
			putpixel(random(640), random(80), 13);
			putpixel(random(640), random(80) + 80, 2);
			putpixel(random(640), random(80) + 160, 3);
			putpixel(random(640), random(80) + 240, 4);
			putpixel(random(640), random(80) + 320, 1);
			putpixel(random(640), random(80) + 400, 14);
		}
		setcolor(YELLOW);
		settextstyle(0, 0, 4);
		outtextxy(130, 200, "Wonderful!!");
		setfillstyle(SOLID_FILL, 10);
		bar(240, 398, 375, 420);
		feiyang(300, 400);
		fei(250, 400);
		yang(350, 400);
		if (bioskey(1))
			if (bioskey(0) == ESC)
			{
				flag = 1;
				break;
			}
	}
}

/*************************end************************/

/***********************初始化图形系统*********************/
void init()
{
	int a = DETECT, b;
	int i, j;
	initgraph(&a, &b, "");
}
/***************************end****************************/

/***画立体边框效果函数******/
void tline(int x1, int y1, int x2, int y2, int white, int black)
{
	setcolor(white);
	line(x1, y1, x2, y1);
	line(x1, y1, x1, y2);
	setcolor(black);
	line(x2, y1, x2, y2);
	line(x1, y2, x2, y2);
}
/****end*********/

/*************飞洋标志**********/
int feiyang(int x, int y)
{
	int feiyang[18][18] = { { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
	{ 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0 },
	{ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0 },
	{ 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0 },
	{ 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0 },
	{ 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 } };
	int i, j;
	for (i = 0; i <= 17; i++)
		for (j = 0; j <= 17; j++)
		{
			if (feiyang[i][j] == 1)
				putpixel(j + x, i + y, RED);
		}
}

/********"飞"字*************/
int fei(int x, int y)
{
	int fei[18][18] = { { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 } };
	int i, j;
	for (i = 0; i <= 17; i++)
		for (j = 0; j <= 17; j++)
		{
			if (fei[i][j] == 1)
				putpixel(j + x, i + y, BLUE);
		}
}

/*********"洋"字**************/

int yang(int x, int y)
{
	int yang[18][18] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
	{ 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
	{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0 },
	{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 } };
	int i, j;
	for (i = 0; i <= 17; i++)
		for (j = 0; j <= 17; j++)
		{
			if (yang[i][j] == 1)
				putpixel(j + x, i + y, BLUE);
		}
}


/******************主场景**********************/
int bort()
{
	int a;
	setfillstyle(SOLID_FILL, 15);
	bar(49, 49, 71, 71);
	setfillstyle(SOLID_FILL, BLUE);
	bar(50, 50, 70, 70);
	size1 = imagesize(49, 49, 71, 71);
	far1 = (void *)malloc(size1);
	getimage(49, 49, 71, 71, far1);
	cleardevice();
	setfillstyle(SOLID_FILL, 12);
	bar(49, 49, 71, 71);
	size2 = imagesize(49, 49, 71, 71);
	far2 = (void *)malloc(size2);
	getimage(49, 49, 71, 71, far2);
	setfillstyle(SOLID_FILL, 12);
	bar(49, 49, 71, 71);
	setfillstyle(SOLID_FILL, GREEN);
	bar(50, 50, 70, 70);
	size3 = imagesize(49, 49, 71, 71);
	far3 = (void *)malloc(size3);
	getimage(49, 49, 71, 71, far3);
	cleardevice();                    /*取蛇身节点  背景节点 虫子节点end*/
	setbkcolor(8);
	setfillstyle(SOLID_FILL, GREEN);
	bar(21, 23, 600, 450);
	tline(21, 23, 600, 450, 15, 8);              /***开始游戏场景边框 立体效果*******/
	tline(23, 25, 598, 448, 15, 8);
	tline(45, 45, 379, 379, 8, 15);
	tline(43, 43, 381, 381, 8, 15);
	tline(390, 43, 580, 430, 8, 15);
	tline(392, 45, 578, 428, 8, 15);
	tline(412, 65, 462, 85, 15, 8);
	tline(410, 63, 464, 87, 15, 8);
	tline(410, 92, 555, 390, 15, 8);
	tline(412, 94, 553, 388, 15, 8);
	tline(431, 397, 540, 420, 15, 8);
	tline(429, 395, 542, 422, 15, 8);
	tline(46, 386, 377, 428, 8, 15);
	tline(44, 384, 379, 430, 8, 15);
	setcolor(8);
	outtextxy(429, 109, "press ENTER ");
	outtextxy(429, 129, "---to start");     /*键盘控制说明*/
	outtextxy(429, 169, "press ESC ");
	outtextxy(429, 189, "---to quiet");
	outtextxy(469, 249, "UP");
	outtextxy(429, 289, "LEFT");
	outtextxy(465, 329, "DOWN");
	outtextxy(509, 289, "RIGHT");
	setcolor(15);
	outtextxy(425, 105, "press ENTER ");
	outtextxy(425, 125, "---to start");
	outtextxy(425, 165, "press ESC ");
	outtextxy(425, 185, "---to quiet");
	outtextxy(465, 245, "UP");
	outtextxy(425, 285, "LEFT");
	outtextxy(461, 325, "DOWN");
	outtextxy(505, 285, "RIGHT");       /*******end*************/

	setcolor(8);
	outtextxy(411, 52, "score");
	outtextxy(514, 52, "left");
	setcolor(15);
	outtextxy(407, 48, "score");
	outtextxy(510, 48, "left");

	size4 = imagesize(409, 62, 465, 88);       /****分数框放到内存********/
	far4 = (void *)malloc(size4);
	getimage(409, 62, 465, 88, far4);
	putimage(500, 62, far4, COPY_PUT);      /*******输出生命框***********/
	setfillstyle(SOLID_FILL, 12);
	setcolor(RED);
	outtextxy(415, 70, "0");         /***************输入分数为零**********/
	outtextxy(512, 70, "20");          /*************显示还要吃 的虫子的数目*********/
	bar(46, 46, 378, 378);
	feiyang(475, 400);
	fei(450, 400);
	yang(500, 400);
	outtextxy(58, 390, "mailto:jiangzhiliang002@tom.com");
	outtextxy(58, 410, "snake game");
	outtextxy(200, 410, "made by yefeng");
	while (1)
	{
		if (bioskey(1))
			a = bioskey(0);
		if (a == ENTER)
			break;
	}

}
/******************gameover()******************/

void gameover()
{
	char *p = "GAME OVER";
	int cha;
	setcolor(YELLOW);
	settextstyle(0, 0, 6);
	outtextxy(100, 200, p);

	while (1)
	{
		if (bioskey(1))
			cha = bioskey(0);
		if (cha == ESC)
		{
			flag = 1;
			break;
		}
	}




}
/***********显示蛇身**********************/
void snakepaint()
{
	struct snake *p1;
	p1 = head;
	putimage(a - 11, b - 11, far2, COPY_PUT);
	while (p1 != NULL)
	{
		putimage(p1->newx - 11, p1->newy - 11, far1, COPY_PUT);
		p1 = p1->next;
	}
}
/****************end**********************/
/*********************蛇身刷新变化 游戏关键部分 *******************/
void snakechange()
{
	struct snake *p1, *p2, *p3, *p4, *p5;
	int i, j;
	static int n = 0;
	static int score;
	static int left = 20;
	char sscore[5];
	char sleft[1];
	p2 = p1 = head;
	while (p1 != NULL)
	{
		p1 = p1->next;
		if (p1->next == NULL)
		{
			a = p1->newx;
			b = p1->newy;           /************记录最后节点的坐标************/
			sx = a;
			sy = b;
		}
		p1->newx = p2->centerx;
		p1->newy = p2->centery;
		p2 = p1;
	}
	p1 = head;
	while (p1 != NULL)
	{
		p1->centerx = p1->newx;
		p1->centery = p1->newy;
		p1 = p1->next;
	}

	/********判断按键方向*******/
	if (bioskey(1))
	{
		ch = bioskey(0);
		if (ch != RIGHT&&ch != LEFT&&ch != UP&&ch != DOWN&&ch != ESC)   /********chy为上一次的方向*********/
			ch = chy;
	}
	switch (ch)
	{
	case LEFT: if (control != 4)
	{
		head->newx = head->newx - 22;
		head->centerx = head->newx;
		control = 2;
		if (head->newx<47)
			gameover();
	}
			   else
			   {
				   head->newx = head->newx + 22;
				   head->centerx = head->newx;
				   control = 4;
				   if (head->newx>377)
					   gameover();
			   }
			   chy = ch;
			   break;
	case DOWN:
		if (control != 1)
		{
			head->newy = head->newy + 22;
			head->centery = head->newy;
			control = 3;
			if (head->newy>377)
				gameover();
		}
		else
		{
			head->newy = head->newy - 22;
			head->centery = head->newy;
			control = 1;
			if (head->newy<47)
				gameover();
		}
		chy = ch;
		break;
	case RIGHT: if (control != 2)
	{
		head->newx = head->newx + 22;
		head->centerx = head->newx;
		control = 4;
		if (head->newx>377)
			gameover();
	}
				else
				{
					head->newx = head->newx - 22;
					head->centerx = head->newx;
					control = 2;
					if (head->newx<47)
						gameover();
				}
				chy = ch;
				break;
	case UP: if (control != 3)
	{
		head->newy = head->newy - 22;
		head->centery = head->newy;
		control = 1;
		if (head->newy<47)
			gameover();
	}
			 else
			 {
				 head->newy = head->newy + 22;
				 head->centery = head->newy;
				 control = 3;
				 if (head->newy>377)
					 gameover();
			 }
			 chy = ch;
			 break;


	case ESC:
		flag = 1;
		break;
	}


	/* if 判断是否吃蛇*/
	if (flag != 1)
	{
		if (head->newx == scenterx&&head->newy == scentery)
		{
			p3 = head;
			while (p3 != NULL)
			{
				p4 = p3;
				p3 = p3->next;
			}
			p3 = (struct snake *)malloc(sizeof(struct snake));
			p4->next = p3;
			p3->centerx = a;
			p3->newx = a;
			p3->centery = b;
			p3->newy = b;
			p3->next = NULL;
			a = 500;
			b = 500;
			putimage(409, 62, far4, COPY_PUT);  /********** 分数框挡住**************/
			putimage(500, 62, far4, COPY_PUT);  /*********把以前的剩下虫子的框挡住********/
			score = (++n) * 100;
			left--;
			itoa(score, sscore, 10);
			itoa(left, sleft, 10);
			setcolor(RED);
			outtextxy(415, 70, sscore);
			outtextxy(512, 70, sleft);
			nextshow = 1;
			if (left == 0)           /************判断是否过关**********/
				donghua();             /*******如果过关，播放过关动画*********************/
		}
		p5 = head;       /*********************判断是否自杀***************************/
		p5 = p5->next;
		p5 = p5->next;
		p5 = p5->next;
		p5 = p5->next;      /****从第五个节点判断是否自杀************/
		while (p5 != NULL)
		{
			if (head->newx == p5->centerx&&head->newy == p5->centery)
			{
				gameover();
				break;
			}
			else
				p5 = p5->next;
		}
	}
}
/************snakechange()函数结束*******************/




/*****************************主函数******************************************/
int main()
{
	int i;
	init();       /**********初始化图形系统**********/
	welcome();      /*********8欢迎界面**************/
	bort();       /*********主场景***************/
	snakede();      /**********连表初始化**********/
	while (1)
	{
		snakechange();
		if (flag == 1)
			break;
		snakepaint();
		ran();
		for (i = 0; i <= grade; i++)
			delay(3000);
	}
	free(far1);
	free(far2);
	free(far3);
	free(far4);
	closegraph();
	return 0;
}