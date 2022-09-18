#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<graphics.h>
#include<mmgw.h>

char sold[5]="130";
int soldi=130;
int key1, win;
char roomc[40]="rooms/cz.jpg";
int x1,x2,x3,y1,y2,y3,xy1;

void meniu();
void muzica();
char* nm(char* pz);
char* timp(int t1, int t2, int t3);
char* timpjc(char* p);
void sort();
void L();
void bani();
void r1(char* r1);
void cz();
void r2(char* r2);
void r3(char* r3);
void r4();
void zb();
void canal();
void r5();
void txc(int a);
void r61();
void r62();
void r63();
void r7();
void r8();
void r9();


int main()
{
	initwindow(1080,720,"PANDEMIC");
	meniu();
	
	return 0;
}

void sort()
{
	int k=0, ok, k1=0, k2=0;
	char pls[50];
	struct bd
	{
		char n[30], t[25],stat[20], j[15];
	}e[1000], inv;
	ifstream f("jucatori.txt");
	do
	{
		f>>e[k].n>>pls>>pls>>e[k].t>>e[k].stat>>pls>>pls>>e[k].j;
		k++;
	}
	while(!f.eof());
	k--;
	do
	{
		ok=0;
		for(int i=0; i<k-1; i++)
		{
			if(strcmp(e[i].stat,e[i+1].stat)>0)
			{
				inv=e[i];
				e[i]=e[i+1];
				e[i+1]=inv;
				ok=1;
			}
			
		}
	}
	while(ok==1);
	for(int i=0; i<k-1; i++)
	{
		if(strcmp(e[i].stat,"CASTIGATOR!")==0)
				k1++;
			else
				k2++;
	}
	do
	{
		ok=0;
		for(int i=0; i<k1-1; i++)
			if(strcmp(e[i].n,e[i+1].n)<0)
			{
				inv=e[i];
				e[i]=e[i+1];
				e[i+1]=inv;
				ok=1;
			}
		for(int i=k2; i<k-1; i++)
			if(strcmp(e[i].n,e[i+1].n)>0)
			{
				inv=e[i];
				e[i]=e[i+1];
				e[i+1]=inv;
				ok=1;
			}
	}
	while(ok==1);
	
	
	ofstream fo("TOP.HTML");
	fo<<"<html>\n<head>\n<style>table {\nfont-family: arial, sans-serif;\nborder-collapse: collapse;\nwidth: 100%;\n}\ntd, th {\nborder: 1px solid #dddddd;\n";
	fo<<"  text-align: left;\n  padding: 8px;\n}\ntr:nth-child(even) {\n  background-color: #dddddd;\n}\n</style>\n</head>\n<body>\n<h2>BAZA DE DATE JUCATORI</h2>\n<table>\n  <tr>\n}\n";
	fo<<"<th>CRT</th>\j<th>NUME</th>\n<th>ORA</th>\n<th>STATUS</th>\n<th>TIMP</th>\n</tr>";
	for(int i=0; i<k; i++)
	{
		fo<<"\n<tr>\n<td>"<<i+1<<"</td>\n<td>"<<e[i].n<<"</td>\n<td>"<<e[i].t<<"</td>\n<td>"<<e[i].stat<<"</td>\n<td>"<<e[i].j<<"</td</tr>";
	}
	fo<<"\n</table>\n</body>\n</html>";
	fo.close();
}

char* timpjc(char* p)
{
	int tmh,tmm,tms;
	char ora[50], s[3], m[3];
	if(x3>y3)
	{
		x2--;
		x3+=60;
		tms=x3-y3;
	}
	else
		tms=y3-x3;
	if(x2>y2)
	{
		x1--;
		x2+=60;
		tmm=x2-y2;
	}
	else
		tmm=y2-x2;
	if(y1>x1)
		y1--;
	tmh=y1-x1;
	
	itoa(tmh,ora,10);
	itoa(tmm,m,10);
	itoa(tms,s,10);
	
	strcat(ora,p);
	strcat(ora,m);
	strcat(ora,p);
	strcat(ora,s);
	return ora;
}
char* timp(int t1, int t2, int t3)
{
	int x;
	char ora[50], oraa[15];
	time_t ttime = time(0);
	tm *local_time = localtime(&ttime);
	x=local_time->tm_year+1900;
	itoa(x,ora,10);
	
	x=local_time->tm_mon;
	itoa(x,oraa,10);
	strcat(ora,":");
	strcat(ora,oraa);
	
	x=local_time->tm_mday;
	itoa(x,oraa,10);
	strcat(ora,":");
	strcat(ora,oraa);
	
	t1=local_time->tm_hour;
	itoa(t1,oraa,10);
	strcat(ora,":");
	strcat(ora,oraa);
	
	t2=local_time->tm_min;
	itoa(t2,oraa,10);
	strcat(ora,":");
	strcat(ora,oraa);
	
    t3=local_time->tm_sec;
	itoa(t3,oraa,10);
	strcat(ora,":");
	strcat(ora,oraa);
	
	if(xy1==0)
	{
		x1=t1;x2=t2;x3=t3;
		xy1=1;
	}
	else
	{
		y1=t1;y2=t2;y3=t3;
		xy1=0;
	}
	return ora;
}

char* nm(char* pz)
{
	char a, nume[30];
	int k=0;
	readimagefile(pz,0,0,1080,720);
	settextstyle(8,0,4);
	setcolor(WHITE);
	setbkcolor(BLACK);
	do
	{
		a=getch();
		if(a=='\r')
			break;
		nume[k]=a;
		k++;
		nume[k]=NULL;
		outtextxy(535,340,nume);
	}
	while(k!=30);
	return nume;
}

int w(char* pz)
{
	int x=1;
	readimagefile(pz,0,0,1080,720);
	delay(2000);
	return x;	
}

void meniu()
{
	char a, nume[30], ora[50], timpj[40];
	do
	{
		strcpy(sold,"130");
		soldi=130;
		strcpy(roomc,"rooms/cz.jpg");
		key1=0;
		readimagefile("rooms/meniu.jpg",0,0,1080,720);
		if(kbhit())
			a=getch();
		if(click(337,237,760,330))
		{
			ofstream fj("jucatori.txt", ios::app);
			strcpy(nume,nm("rooms/nume.jpg"));
			strcpy(ora,timp(x1,x2,x3));
			cout<<x1<<":"<<x2<<":"<<x3;
			cout<<nume<<" "<<ora<<endl;
			fj<<nume<<" Data inceperii: "<<ora;
			r1("rooms/r1.jpg");
			if(key1==1)
				fj<<" CASTIGATOR!";
			else
				fj<<" PIERZATOR!";
			
			strcpy(ora,timp(y1,y2,y3));
			cout<<endl<<y1<<":"<<y2<<":"<<y3;
			strcpy(timpj,timpjc(":"));
			fj<<" TIMP JUCAT: "<<timpj<<endl;
			fj.close();
			sort();
		}
		if(click(337,333,760,420))
		{
			readimagefile("rooms/desprejoc.jpg",0,0,1080,720);
			getch();
		}
		if(click(337,422,535,500))
		{
			readimagefile("rooms/controale.jpg",0,0,1080,720);
			getch();
		}
		if(click(560,422,760,500))
		{
			readimagefile("rooms/doneaza.jpg",0,0,1080,720);
			getch();
		}
	}
	while(a!=char(27));
}

void L()
{
	readimagefile("rooms/l.jpg",0,0,1080,720);
	win=0;
	getch();
}
void r1(char* r1)
{
	int l=0;
	int xx=200,xy=200,yy=500,yx=500;
	char a, pp[10];
	readimagefile(r1,1,1,1080,720);
	readimagefile("pp/p1.gif",xx,xy,yy,yx);
	bani();

	do
	{
		a=getch();
		ifstream f("pp.txt");
		if(a=='a')
		{
			if(xx>200)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile(r1,1,1,1080,720);
				readimagefile(pp,xx-10*i,xy,yy-10*i,yx);
				bani();
				delay(5);
			}
			xx-=50;yy-=50;
			}
		}
		if(a=='d')
		{
			if(yy<1000)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile(r1,1,1,1080,720);
				readimagefile(pp,xx+10*i,xy,yy+10*i,yx);
				bani();
				delay(5);
			}
			xx+=50;yy+=50;
			}
		}
		if(a=='s')
		{
			if(yx<700)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile(r1,1,1,1080,720);
				readimagefile(pp,xx,xy+10*i,yy,yx+10*i);	
				bani();
				delay(5);
			}
			xy+=50;yx+=50;
			}
		}
		if(a=='w')
		{
			if(xy>150)
			{
				for(int i=1; i<=5; i++)
				{
					f>>pp;
					readimagefile(r1,1,1,1080,720);
					readimagefile(pp,xx,xy-10*i,yy,yx-10*i);
					bani();
				}
				xy-=50;yx-=50;
			}
		}
		f.close();
		if(xx==400 && xy==150)
		{
			readimagefile("rooms/r1.1.jpg",1,1,1080,720);
			readimagefile("pp/p1.gif",xx,xy,yy,yx);
			readimagefile("key/e.jpg",600,225,625,250);
			bani();
			if(getch()=='e')
			{
				cz();
				readimagefile("rooms/r1.1.jpg",1,1,1080,720);
				readimagefile("pp/p1.gif",xx,xy,yy,yx);
				readimagefile("key/e.jpg",600,225,625,250);
				bani();
			}
		}
		if(xx==400 && xy==150 && key1==0 && soldi<130)
		{
			l=1;
			break;
		}
		
	}
	while(xx!=400 || yx!=700 || key1!=1);
	if(l==0)
		r2("rooms/r2.jpg");
	if(l==1)
		L();
}

void cz()
{
	int p=0;
	readimagefile(roomc,1,1,1080,720);
	setfillstyle(1,MAGENTA);
	setbkcolor(MAGENTA);
	setcolor(WHITE);
	settextstyle(0,0,0);
	bar(970,100,1080,125);
	outtextxy(975,105,"SOLD: $");
	outtextxy(1030,105,sold);
	if(soldi==130)
	{
		Sleep(1000);
		readimagefile("rooms/phishing.jpg",300,100,800,600);
		do
		{
			if(click(375,530,520,580))
			{
				soldi=0;
				itoa(soldi,sold,10);
				p=1;
			}
			if(click(590,530,730,590))
				p=1;
		}
		while(p!=1);
		readimagefile(roomc,1,1,1080,720);
		setfillstyle(1,MAGENTA);
		setbkcolor(MAGENTA);
		bar(970,100,1080,125);
		outtextxy(975,105,"SOLD: $");
		outtextxy(1030,105,sold);
		
	}
	p=0;
	do
	{
	if(click(812,250,938,300) && soldi>59)
	{
		soldi-=59;
		itoa(soldi,sold,10);
		readimagefile("rooms/cz.1.jpg",1,1,1080,720);
		strcpy(roomc,"rooms/cz.1.jpg");
		setfillstyle(1,MAGENTA);
		setbkcolor(MAGENTA);
		bar(970,100,1080,125);
		outtextxy(975,105,"SOLD: $");
		outtextxy(1030,105,sold);

	}
	else if(click(814,390,938,440) && soldi>119)
	{
		soldi-=119;
		itoa(soldi,sold,10);
		readimagefile("rooms/cz.2.jpg",1,1,1080,720);
		strcpy(roomc,"rooms/cz.2.jpg");
		setfillstyle(1,MAGENTA);
		setbkcolor(MAGENTA);
		bar(970,100,1080,125);
		outtextxy(975,105,"SOLD: $");
		outtextxy(1030,105,sold);
		key1=1;

	}
	else if(click(814,535,939,585) && soldi>89)
	{
		soldi-=89;
		itoa(soldi,sold,10);
		readimagefile("rooms/cz.3.jpg",1,1,1080,720);
		strcpy(roomc,"rooms/cz.3.jpg");
		setfillstyle(1,MAGENTA);
		setbkcolor(MAGENTA);
		bar(970,100,1080,125);
		outtextxy(975,105,"SOLD: $");
		outtextxy(1030,105,sold);
	}
	
	else if(click(1030,1,1079,40))
			break;
		
	}
	while(p!=1);
	
}

		
void r2(char* r2)
{
	int xx=25,xy=425,yy=275,yx=725;
	char a, pp[10];
	int key1=0;
	readimagefile(r2,0,0,1080,720);
	readimagefile("pp/p1.gif",xx,xy,yy,yx);
	readimagefile("ps/1ps.gif",xx+700,xy,yy+700,yx);
	readimagefile("key/inel.gif",75,655,125,705);
	bani();
	do
	{
		a=getch();
		ifstream f("pp.txt");
		if(a=='a')
		{
			if(xx>25)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/r2.jpg",1,1,1080,720);
				readimagefile(pp,xx-10*i,xy,yy-10*i,yx);
				readimagefile("ps/1ps.gif",725,425,975,725);
				if(key1==0)
					readimagefile("key/inel.gif",75,655,125,705);
				bani();
				delay(5);
			}
			xx-=50;yy-=50;
			}
		}
		if(a=='d')
		{
			if(yy<925)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/r2.jpg",1,1,1080,720);
				readimagefile(pp,xx+10*i,xy,yy+10*i,yx);
				readimagefile("ps/1ps.gif",725,425,975,725);
				if(key1==0)
					readimagefile("key/inel.gif",75,655,125,705);
				bani();
				delay(5);
			}
			xx+=50;yy+=50;
			}
		}
		
		if(a=='s')
		{
			if(yx<875)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/r2.jpg",1,1,1080,720);
				readimagefile(pp,xx,xy+10*i,yy,yx+10*i);
				readimagefile("ps/1ps.gif",725,425,975,725);
				if(key1==0)
					readimagefile("key/inel.gif",75,655,125,705);
				bani();
				delay(5);
			}
			xy+=50;yx+=50;
			}
		}
		if(a=='w')
		{
			if(xy>425)
			{
				for(int i=1; i<=5; i++)
				{
					f>>pp;
					readimagefile("rooms/r2.jpg",1,1,1080,720);
					readimagefile(pp,xx,xy-10*i,yy,yx-10*i);
					readimagefile("ps/1ps.gif",725,425,975,725);
					if(key1==0)
						readimagefile("key/inel.gif",75,655,125,705);
					bani();
					delay(5);
				}
				xy-=50;yx-=50;
			}
		}
		
		if(xx==25 && xy==475)
		{
			if(key1==0)
				readimagefile("key/e.jpg",40,630,70,660);
			if(getch()=='e')
			{
				key1=1;
				readimagefile("rooms/r2.jpg",1,1,1080,720);
				readimagefile(pp,xx,xy,yy,yx);
				readimagefile("ps/1ps.gif",725,425,975,725);
				bani();
			}
		}
		
		if(xx==675)
		{
			Sleep(200);
			
			readimagefile("rooms/r2.2.jpg",0,0,1080,720);
			bani();
			if(key1==0)
			{
			setcolor(BLACK);
			setbkcolor(WHITE);
			settextstyle(8,0,3);
			outtextxy(250,575,"Vericu', ma duci pana la aeroport?");
			bani();
			Sleep(3000);
			
			
			setcolor(BLACK);
			setbkcolor(WHITE);
			settextstyle(8,0,3);
			readimagefile("rooms/r2.3.jpg",0,0,1080,720);
			outtextxy(660,365,"13$ pana acolo.");
			bani();
			Sleep(3000);
			
			
			setcolor(BLACK);
			setbkcolor(WHITE);
			settextstyle(8,0,3);
			readimagefile("rooms/r2.2.jpg",0,0,1080,720);
			outtextxy(250,570,"Am doar 11$. Ce pot sa fac?");
			outtextxy(250,595,"Crede-ma, trebuie sa ajung urgent!");
			bani();
			Sleep(3000);
			
			
			setcolor(BLACK);
			setbkcolor(WHITE);
			settextstyle(8,0,3);
			readimagefile("rooms/r2.3.jpg",0,0,1080,720);
			outtextxy(660,335,"Fa rost de ceva ca");
			outtextxy(660,355,"nu vezi drum gratis.");
			bani();
			Sleep(3000);
			}
			
			if(key1==1)
			{
			setcolor(BLACK);
			setbkcolor(WHITE);
			settextstyle(8,0,3);
			readimagefile("key/inel.gif",340,445,420,525);
			outtextxy(250,575,"Hai cu inelu asta ma duci?");
			bani();
			Sleep(3000);
			
			setcolor(BLACK);
			setbkcolor(WHITE);
			settextstyle(8,0,3);
			readimagefile("rooms/r2.3.jpg",0,0,1080,720);
			readimagefile("key/inel.gif",340,445,420,525);
			outtextxy(660,365,"Hai urca sus.");
			bani();
			Sleep(3000);
			key1=2;
			}
		}
	}
	while(key1!=2);
	r3("rooms/r3.gif");
}

void bani()
{
	setbkcolor(BLACK);
	setfillstyle(1, BLACK);
	settextstyle(0,0,3);
	bar(0,0,200,40);
	setcolor(YELLOW);
	outtextxy(2,10,"BANI: ");
	outtextxy(120,10,sold);
}

void r3(char* r3)
{	
	int x=0;
	do
	{
		readimagefile(r3,0,0,1080,720);
		readimagefile("rooms/taxi.gif",-300+x,400,0+x,700);
		x+=50;
		Sleep(50);
	}
	while(x!=1450);
	r4();
}

void r4()
{
	int xx=500,xy=500,yy=700,yx=700;
	char a, pp[10];
	int key1=0, key2=0, avion=0;
	readimagefile("rooms/r4.gif",0,0,1080,720);
	readimagefile("rooms/bani.gif",880,500,955,560);
	readimagefile("rooms/carte.gif",160,630,200,670);
	readimagefile("pp/p1.gif",xx,xy,yy,yx);
	bani();
	do
	{
		a=getch();
		ifstream f("pp.txt");
		if(a=='a')
		{
			if(xx>0)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/r4.gif",0,0,1080,720);
				readimagefile(pp,xx-10*i,xy,yy-10*i,yx);
				bani();
				if(key1==0)
					readimagefile("rooms/carte.gif",160,630,200,670);				
				if(key2==0)
					readimagefile("rooms/bani.gif",880,500,955,560);
				delay(5);
			}
			xx-=50;yy-=50;
			}
		}
		if(a=='d')
		{
			if(yy<1050)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/r4.gif",0,0,1080,720);
				readimagefile(pp,xx+10*i,xy,yy+10*i,yx);
				bani();
				if(key1==0)
					readimagefile("rooms/carte.gif",160,630,200,670);
				if(key2==0)
					readimagefile("rooms/bani.gif",880,500,955,560);
				delay(5);
			}
			xx+=50;yy+=50;
			}
		}
		if(a=='s')
		{
			if(yx<720)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/r4.gif",0,0,1080,720);
				readimagefile(pp,xx,xy+10*i,yy,yx+10*i);	
				bani();
				if(key1==0)
					readimagefile("rooms/carte.gif",160,630,200,670);
				if(key2==0)
					readimagefile("rooms/bani.gif",880,500,955,560);
				delay(5);
			}
			xy+=50;yx+=50;
			}
		}
		if(a=='w')
		{
			if(xy>350)
			{
				for(int i=1; i<=5; i++)
				{
					f>>pp;
					readimagefile("rooms/r4.gif",0,0,1080,720);
					readimagefile(pp,xx,xy-10*i,yy,yx-10*i);
					bani();
					if(key1==0)
						readimagefile("rooms/carte.gif",160,630,200,670);
					if(key2==0)
						readimagefile("rooms/bani.gif",880,500,955,560);
				delay(5);
				}
				xy-=50;yx-=50;
			}
		}
		f.close();
		
		if(xx==150 && xy==550 && key1==0)
		{
			readimagefile("key/e.jpg",150,600,175,625);
			a=getch();
			if(a=='e')
			{
				readimagefile("rooms/r4.gif",0,0,1080,720);
				readimagefile("pp/p1.gif",xx,xy,yy,yx);
				bani();
				key1=1;
				setcolor(BLACK);
				bar(0,670,500,720);
				setcolor(WHITE);
				settextstyle(1,0,1);
				outtextxy(5,680,"Oare ce scrie in cartea asta pierduta?????");
				getch();
				readimagefile("rooms/cartei.jpg",300,200,650,550);
				setcolor(BLACK);
				bar(0,670,500,720);
				setcolor(WHITE);
				outtextxy(5,680,"Oare ce inseamna asta?????");
				getch();
				readimagefile("rooms/r4.gif",0,0,1080,720);
				readimagefile("pp/p1.gif",xx,xy,yy,yx);
				bani();
				settextstyle(1,0,1);
				readimagefile("rooms/tlf.jpg",300,200,650,550);
				setcolor(BLACK);
				bar(0,670,500,720);
				setcolor(WHITE);
				outtextxy(5,680,"Guiziwan 2, numarul 37.");
				getch();
				if(key2==0)
					readimagefile("rooms/bani.gif",880,500,955,560);
			}
		}
		
		if(xx==800 && xy==450 && key2==0)
		{
			readimagefile("key/e.jpg",875,475,900,500);
			a=getch();
			if(a=='e')
			{
				readimagefile("rooms/r4.gif",0,0,1080,720);
				readimagefile("pp/p1.gif",xx,xy,yy,yx);
				key2=1;
				soldi+=450;
				itoa(soldi,sold,10);
				readimagefile("key/450.gif",300,200,700,600);
				bani();
				if(key1==0)
					readimagefile("rooms/carte.gif",160,630,200,670);
			}
		}
		
		if(xx==0 && xy==350)
		{
			readimagefile("key/e.jpg",25,350,50,375);
			a=getch();
			if(a=='e')
				avion=1;
		}
		
		if(xx==250 && xy==350)
		{
			readimagefile("key/e.jpg",275,350,300,375);
			a=getch();
			if(a=='e')
				avion=2;
		}
		
		if(xx==450 && xy==350)
		{
			readimagefile("key/e.jpg",475,350,500,375);
			a=getch();
			if(a=='e')
				avion=3;
		}
	}
	while(avion==0);
	
	if(avion!=3)
		L();
	else
		zb();
}

void zb()
{
	readimagefile("rooms/z1.gif",0,0,1080,720);
	Sleep(2000);
	readimagefile("rooms/z2.gif",0,0,1080,720);
	Sleep(2000);
	readimagefile("rooms/z3.gif",0,0,1080,720);
	Sleep(2000);
	r5();
}

void r5()
{
	readimagefile("rooms/r5.jpg",0,0,1080,720);
	int xx=750,xy=250,yy=950,yx=450, t=0;
	char a,b, pp[10];
	readimagefile("rooms/r5.jpg",0,0,1080,720);
	readimagefile("pp/p1.gif",xx,xy,yy,yx);
	bani();
	do
	{
		a=getch();
		ifstream f("pp.txt");
		if(a=='a')
		{
			if(xx>0)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/r5.jpg",0,0,1080,720);
				readimagefile(pp,xx-10*i,xy,yy-10*i,yx);
				bani();
				delay(5);
			}
			xx-=50;yy-=50;
			}
		}
		if(a=='d')
		{
			if(yy<1050)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/r5.jpg",0,0,1080,720);
				readimagefile(pp,xx+10*i,xy,yy+10*i,yx);
				bani();
				delay(5);
			}
			xx+=50;yy+=50;
			}
		}
		if(a=='s')
		{
			if(yx<650)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/r5.jpg",0,0,1080,720);
				readimagefile(pp,xx,xy+10*i,yy,yx+10*i);	
				bani();
				delay(5);
			}
			xy+=50;yx+=50;
			}
		}
		if(a=='w')
		{
			if(xy>250)
			{
				for(int i=1; i<=5; i++)
				{
					f>>pp;
					readimagefile("rooms/r5.jpg",0,0,1080,720);
					readimagefile(pp,xx,xy-10*i,yy,yx-10*i);
					bani();
				delay(5);
				}
				xy-=50;yx-=50;
			}
		}
		f.close();
		
		if(xy==450 && xx==800)
		{
			readimagefile("key/e.jpg",900,475,925,500);
			a=getch();
			if(a=='e')
			{
				readimagefile("rooms/r5.1p.jpg",0,0,1080,720);
				setbkcolor(WHITE);
				setcolor(BLACK);
				settextstyle(1,0,2);
				outtextxy(90,170,"Am nevoie sa ajung la adresa: ");
				bar(100,500,985,665);
				setbkcolor(BLACK);
				setcolor(WHITE);
				settextstyle(1,0,1);
				outtextxy(150,550,"a. Guiziwan, Numarul 17");
				outtextxy(150,600,"b. Guiziwan 2, Numarul 37");
				outtextxy(600,550,"c. Guiziwan 2, Numarul 41");
				outtextxy(600,600,"d. Guiziwan 3, Numarul 37");
				b=getch();
				readimagefile("rooms/r5.1t.jpg",0,0,1080,720);
				setbkcolor(WHITE);
				setcolor(BLACK);
				settextstyle(1,0,2);
				outtextxy(330,100,"Urca in masina.");
				getch();
				if(b=='b')
					t=1;
				else
					t=2;
			}
		}
		if((xy==450 && xx==550) || (xy==450 && xx==400))
		{
			readimagefile("key/e.jpg",550,475,575,500);
			a=getch();
			if(a=='e')
			{
				readimagefile("rooms/r5.2p.jpg",0,0,1080,720);
				setbkcolor(WHITE);
				setcolor(BLACK);
				settextstyle(1,0,2);
				outtextxy(555,105,"Am nevoie sa ajung la adresa: ");
				bar(100,500,985,665);
				setbkcolor(BLACK);
				setcolor(WHITE);
				settextstyle(1,0,1);
				outtextxy(150,550,"a. Guiziwan, Numarul 17");
				outtextxy(150,600,"b. Guiziwan 2, Numarul 41");
				outtextxy(600,550,"c. Guiziwan 2, Numarul 37");
				outtextxy(600,600,"d. Guiziwan 3, Numarul 37");
				b=getch();
				readimagefile("rooms/r5.2.jpg",0,0,1080,720);
				setbkcolor(WHITE);
				setcolor(BLACK);
				settextstyle(1,0,2);
				outtextxy(165,600,"Urca in masina.");
				getch();
				t=3;
			}
		}
		
	}
	while(t!=3&&t!=2&&t!=1);
	txc(t);
}

void txc(int a)
{
	int x=0;
	do
	{
		readimagefile("rooms/txc.jpg",0,0,1080,720);
		readimagefile("rooms/mchn.gif",-300+x,400,0+x,700);
		x+=50;
		Sleep(50);
	}
	while(x!=1450);
	if(a==1)
	{
		r61();
	}
	if(a==2)
	{
		r62();
	}
	if(a==3)
		r63();
}

void r63()
{
	readimagefile("rooms/rded.jpg",0,0,1080,720);
	delay(2000);
	L();
}

void r61()
{
	int xx=25,xy=425,yy=275,yx=725;
	char a, pp[10];
	readimagefile("rooms/cna.jpg",0,0,1080,720);
	readimagefile("pp/p1.gif",xx,xy,yy,yx);
	bani();
	do
	{
		a=getch();
		ifstream f("pp.txt");
		if(a=='a')
		{
			if(xx>25)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/cna.jpg",1,1,1080,720);
				readimagefile(pp,xx-10*i,xy,yy-10*i,yx);
				bani();
				delay(5);
			}
			xx-=50;yy-=50;
			}
		}
		if(a=='d')
		{
			if(yy<925)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/cna.jpg",1,1,1080,720);
				readimagefile(pp,xx+10*i,xy,yy+10*i,yx);
				bani();
				delay(5);
			}
			xx+=50;yy+=50;
			}
		}
		
		if(a=='s')
		{
			if(yx<825)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/cna.jpg",1,1,1080,720);
				readimagefile(pp,xx,xy+10*i,yy,yx+10*i);
				bani();
				delay(5);
			}
			xy+=50;yx+=50;
			}
		}
		if(a=='w')
		{
			if(xy>375)
			{
				for(int i=1; i<=5; i++)
				{
					f>>pp;
					readimagefile("rooms/cna.jpg",1,1,1080,720);
					readimagefile(pp,xx,xy-10*i,yy,yx-10*i);
					
					bani();
					delay(5);
				}
				xy-=50;yx-=50;
			}
		}
		if(xx==475 && xy==375)
		{
			readimagefile("key/e.jpg",600,425,625,450);
			a=getch();
			if(a=='e');
			{
				readimagefile("rooms/r61.1.jpg",0,0,1080,720);
				settextstyle(0,0,0);
				setcolor(BLACK);
				setbkcolor(WHITE);
				outtextxy(225,100,"Cu ce va pot ajuta domnule?");
				getch();
				
				readimagefile("rooms/r61.2.jpg",0,0,1080,720);
				outtextxy(325,110,"Trebuie sa gasesc un om");
				outtextxy(325,135,"care mananca lilieci.");
				getch();
				
				readimagefile("rooms/r61.1.jpg",0,0,1080,720);
				outtextxy(225,100,"Eu te pot ajuta cu orice,");
				outtextxy(225,125,"dar o sa fie scump. 400$");
				getch();
				
				if(soldi>400)
				{
					readimagefile("rooms/r61.2.jpg",0,0,1080,720);
					outtextxy(325,110,"Fac orice, o fac pentru salvarea planetei.");
					getch();
					
					readimagefile("rooms/r61.1.jpg",0,0,1080,720);
					outtextxy(225,100,"Haide  cu mine.");
					soldi-=400;
					itoa(soldi,sold,10);
					a='p';
				}
				else
				{
					readimagefile("rooms/r61.2.jpg",0,0,1080,720);
					outtextxy(325,110,"Dar nu am atatia bani.");
					getch();
					
					readimagefile("rooms/r61.1.jpg",0,0,1080,720);
					outtextxy(225,100,"Atunci iti voi lua viata.");
					a='o';
				}
				getch();
			}
		}
		
	}
	while(a!='p' && a!='o');
	if(a=='p')
		r7();
	else
		L();
}

void r62()
{
	int xx=25,xy=425,yy=275,yx=725;
	char a, pp[10], k=0;
	readimagefile("rooms/stg.jpg",0,0,1080,720);
	readimagefile("pp/p1.gif",xx,xy,yy,yx);
	bani();
	do
	{
		a=getch();
		ifstream f("pp.txt");
		if(a=='a')
		{
			if(xx>25)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/stg.jpg",1,1,1080,720);
				readimagefile(pp,xx-10*i,xy,yy-10*i,yx);
				bani();
				delay(5);
			}
			xx-=50;yy-=50;
			}
		}
		if(a=='d')
		{
			if(yy<925)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/stg.jpg",1,1,1080,720);
				readimagefile(pp,xx+10*i,xy,yy+10*i,yx);
				bani();
				delay(5);
			}
			xx+=50;yy+=50;
			}
		}
		
		if(a=='s')
		{
			if(yx<825)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/stg.jpg",1,1,1080,720);
				readimagefile(pp,xx,xy+10*i,yy,yx+10*i);
				bani();
				delay(5);
			}
			xy+=50;yx+=50;
			}
		}
		if(a=='w')
		{
			if(xy>375)
			{
				for(int i=1; i<=5; i++)
				{
					f>>pp;
					readimagefile("rooms/stg.jpg",1,1,1080,720);
					readimagefile(pp,xx,xy-10*i,yy,yx-10*i);
					
					bani();
					delay(5);
				}
				xy-=50;yx-=50;
			}
		}
		if(xx==375 && xy==475)
		{
			readimagefile("key/e.jpg",550,550,575,575);
			a=getch();
			if(a=='e')
			{
				readimagefile("rooms/r62.1.jpg",0,0,1080,720);
				settextstyle(0,0,0);
				setcolor(BLACK);
				setbkcolor(WHITE);
				outtextxy(225,100,"Ce te aduce in cartier, tinere?");
				getch();
				
				readimagefile("rooms/r62.2.jpg",0,0,1080,720);
				outtextxy(270,110,"Trebuie sa gasesc un om ");
				outtextxy(270,135,"care mananca lilieci.");
				getch();
				
				readimagefile("rooms/r62.1.jpg",0,0,1080,720);
				outtextxy(225,100,"Este cam periculos sa");
				outtextxy(225,125," te aventurezi in acest cartier.");
				outtextxy(225,150,"Nu ne plac strainii.");
				outtextxy(225,175,"Ti-ai gasit sfarsitul.");
				delay(2000);
				k=1;
			}
		}
		
		if(xx==375 && xy==375)
		{
			readimagefile("key/e.jpg",550,550,575,575);
			a=getch();
			if(a=='e')
				k=2;
		}
	}
	while(k==0);
	if(k==1)
		L();
	if(k==2)
		canal();
}
void canal()
{
	int xx=25,xy=275,yy=275,yx=575;
	char a, pp[10];
	readimagefile("rooms/canal.jpg",0,0,1080,720);
	readimagefile("pp/p1.gif",xx,xy,yy,yx);
	bani();
	do
	{
		a=getch();
		ifstream f("pp.txt");
		if(a=='a')
		{
			if(xx>25)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/canal.jpg",0,0,1080,720);
				readimagefile(pp,xx-10*i,xy,yy-10*i,yx);
				bani();
				delay(5);
			}
			xx-=50;yy-=50;
			}
		}
		if(a=='d')
		{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/canal.jpg",0,0,1080,720);
				readimagefile(pp,xx+10*i,xy,yy+10*i,yx);
				bani();
				delay(5);
			}
			xx+=50;yy+=50;
		}
	}
	while(xx!=1025);
	r7();
}

void r7()
{
	int xx=25,xy=425,yy=275,yx=725, ok=0;;
	char a, pp[10];
	readimagefile("rooms/r7.gif",0,0,1080,720);
	readimagefile("pp/p1.gif",xx,xy,yy,yx);
	bani();
	do
	{
		a=getch();
		ifstream f("pp.txt");
		if(a=='a')
		{
			if(xx>25)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/r7.gif",0,0,1080,720);
				readimagefile(pp,xx-10*i,xy,yy-10*i,yx);
				bani();
				delay(5);
			}
			xx-=50;yy-=50;
			}
		}
		if(a=='d')
		{
			if(yy<925)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/r7.gif",0,0,1080,720);
				readimagefile(pp,xx+10*i,xy,yy+10*i,yx);
				bani();
				delay(5);
			}
			xx+=50;yy+=50;
			}
		}
		
		if(a=='s')
		{
			if(yx<825)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/r7.gif",0,0,1080,720);
				readimagefile(pp,xx,xy+10*i,yy,yx+10*i);
				bani();
				delay(5);
			}
			xy+=50;yx+=50;
			}
		}
		if(a=='w')
		{
			if(xy>325)
			{
				for(int i=1; i<=5; i++)
				{
					f>>pp;
					readimagefile("rooms/r7.gif",0,0,1080,720);
					readimagefile(pp,xx,xy-10*i,yy,yx-10*i);
					bani();
					delay(5);
				}
				xy-=50;yx-=50;
			}
		}
		if(xx==375 && xy==325)
		{
			readimagefile("key/e.jpg",450,400,475,425);
			a=getch();
			if(a=='e')
				ok=1;
		}
	}
	while(ok==0);
	r8();
}

void r8()
{
	int xx=25,xy=425,yy=275,yx=725, key=0, key1=0;
	char a, pp[10];
	readimagefile("rooms/r8.jpg",0,0,1080,720);
	readimagefile("rooms/pistol.gif",500,425,550,475);
	readimagefile("pp/p1.gif",xx,xy,yy,yx);
	bani();
	do
	{
		a=getch();
		ifstream f("pp.txt");
		if(a=='a')
		{
			if(xx>25)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/r8.jpg",0,0,1080,720);
				readimagefile(pp,xx-10*i,xy,yy-10*i,yx);
				if(key==0)
					readimagefile("rooms/pistol.gif",500,425,550,475);
				bani();
				delay(5);
			}
			xx-=50;yy-=50;
			}
		}
		if(a=='d')
		{
			if(yy<1025)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/r8.jpg",0,0,1080,720);
				readimagefile(pp,xx+10*i,xy,yy+10*i,yx);
				if(key==0)
					readimagefile("rooms/pistol.gif",500,425,550,475);
				bani();
				delay(5);
			}
			xx+=50;yy+=50;
			}
		}
		
		if(a=='s')
		{
			if(yx<825)
			{
			for(int i=1; i<=5; i++)
			{
				f>>pp;
				readimagefile("rooms/r8.jpg",0,0,1080,720);
				readimagefile(pp,xx,xy+10*i,yy,yx+10*i);
				if(key==0)
					readimagefile("rooms/pistol.gif",500,425,550,475);
				bani();
				delay(5);
			}
			xy+=50;yx+=50;
			}
		}
		if(a=='w')
		{
			if(xy>325)
			{
				for(int i=1; i<=5; i++)
				{
					f>>pp;
					readimagefile("rooms/r8.jpg",0,0,1080,720);
					readimagefile(pp,xx,xy-10*i,yy,yx-10*i);
					if(key==0)
						readimagefile("rooms/pistol.gif",500,425,550,475);
					bani();
					delay(5);
				}
				xy-=50;yx-=50;
			}
		}
		if(xx==375 && xy==375 && key==0)
		{
			readimagefile("key/e.jpg",450,400,475,425);
			a=getch();
			if(a=='e')
			{
				key=1;
				readimagefile("rooms/r8.jpg",0,0,1080,720);
				readimagefile(pp,xx,xy,yy,yx);
			}
		}
		if(xx==725 && xy==475)
		{
			readimagefile("key/e.jpg",850,500,875,525);
			a=getch();
			if(a=='e')
				key1=1;
		}
	}
	while(key1==0);
	r9();
}

void r9()
{
	int life=4;
	do
	{
		readimagefile("rooms/r9.jpg",0,0,1080,720);
		readimagefile("pp/p5.gif",100,350,500,850);
		readimagefile("bad.gif",600,400,750,550);
		if(click(1,1,1080,720))
			readimagefile("pp/p6.gif",100,350,500,850);
		if(click(580,430,700,560))
		{
			readimagefile("pp/p6.gif",100,350,500,850);
			life-=1;
		}
		delay(100);
	}
	while(life!=0);
	readimagefile("rooms/r9.jpg",0,0,1080,720);
	readimagefile("pp/p5.gif",100,350,500,850);
	readimagefile("dead.gif",600,400,750,550);
	delay(2000);
	win=w("rooms/win.jpg");
}