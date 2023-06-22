#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
int i=0;
	void menu();        // function prototype

	class crim               //class for the new entries
	{
		public:
		int crno;
		int most;
		char name[26];
		char crime[80];
		void entry();
		void search();
	}crim,crim1;

	void welcome()			//for the welcome screen
	{
		clrscr();
		int gdriver=DETECT,gmode;
		initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
		setbkcolor(WHITE);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,8);
		setcolor(BLUE);
		delay(200);
		outtextxy(160,150,"W");
		delay(1000);
		outtextxy(220,150,"E");
		delay(1000);
		outtextxy(260,150,"L");
		delay(1000);
		outtextxy(285,150,"C");
		delay(1000);
		outtextxy(325,150,"O");
		delay(1000);
		outtextxy(370,150,"M");
		delay(1000);
		outtextxy(415,150,"E");
		delay(500);
		outtextxy(450,150,".");
		delay(500);
		outtextxy(460,150,".");
		delay(500);
		outtextxy(470,150,".");
		delay(1500);
		closegraph();
	}

	void intro()            //for the introductive page
	{
		int gdriver=DETECT,gmode;
		initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
		setbkcolor(WHITE);
		setcolor(MAGENTA);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
		outtextxy(150,150,"Computer Project");
		setcolor(BLUE);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
		delay(1000);
		outtextxy(300,300,"Made By:");
		delay(1000);
		outtextxy(320,325,"Name:Vrushank Anand");
		delay(1000);
		outtextxy(320,350,"Class:XI - A");
		delay(1000);
		outtextxy(320,375,"Roll no.: 22");
		delay(1000);
		outtextxy(320,400,"Session: 2017-18");
		delay(2000);
		closegraph();
	}

	void front()        //for the front page
	{
		clrscr();
		int gdriver=DETECT,gmode;
		initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
		setcolor(CYAN);
		int x=0;
		for(int i=0;i<180;i++)
		{
			delay(7);
			cleardevice();
			line(20+x,310,70+x,310);
			line(20+x,305,110+x,305);
			line(20+x,300,140+x,300);
			line(20+x,295,155+x,295);
			line(20+x,290,190+x,290);
			line(20+x,285,170+x,285);
			line(20+x,280,140+x,280);
			line(20+x,275,110+x,275);
			line(20+x,270,70+x,270);
			line(70+x,310,200+x,290);
			line(70+x,270,200+x,290);
			x+=2;
		}
		delay(1500);
		cleardevice();
		settextstyle(GOTHIC_FONT,HORIZ_DIR,7);
		setcolor(CYAN);
		delay(1000);
		outtextxy(170,150,"ODESSA");
		setcolor(CYAN);
		delay(5000);
		closegraph();
	}

	void most()                    //for the most wanted list
	{
		int gdriver=DETECT,gmode;
		initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
		setcolor(BROWN);
		outtextxy(200,5,"Most Wanted");
		line(200,40,400,40);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
		setcolor(GREEN);
		outtextxy(10,50,"1.Roman Pierce");
		outtextxy(10,75,"2.John Laplace");
		outtextxy(10,100,"3.Althea Trinity");
		outtextxy(10,125,"4.Jason Bourne");
		outtextxy(10,150,"5.Dorian Grey");
		outtextxy(10,175,"6.Lucia von Bardas");
		outtextxy(10,200,"7.Ra's Al Ghul");
		outtextxy(10,225,"8.Yelena Belova");
		outtextxy(10,250,"9.Remy Lebauw");
		outtextxy(7,275,"10.Lina Vonschaft");
		settextstyle(SMALL_FONT,HORIZ_DIR,7);
		setcolor(CYAN);
		outtextxy(150,400,"(Press enter to go back)");
		getch();
		menu();
		closegraph();
	}


	void crim::entry()                   //for the new entries list
	{
		clrscr();
		int gdriver=DETECT,gmode;
		initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
		setbkcolor(LIGHTBLUE);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
		outtextxy(200,5,"Description");
		line(190,40,370,40);
		setcolor(RED);
		char ab;
		do
		{
			ofstream fout("crim1.dat",ios::app);
			gotoxy(1,5);
			cout<<"Enter criminal number:"<<endl;
			cin>>crno;
			gotoxy(1,7);
			cout<<"Enter criminal name:"<<endl;
			gets(name);
			gotoxy(1,9);
			cout<<"Enter the given crime:"<<endl;
			gets(crime);
			gotoxy(1,11);
			cout<<"Enter the number in the most wanted list:"<<endl;
			cin>>most;
			fout.write((char*)&crim,sizeof(crim));
			fout.close();
			gotoxy(30,15);
			cout<<"Do you want to enter more?"<<endl;
			gotoxy(30,16);
			cin>>ab;
		}while(ab=='Y'||ab=='y');
		clrscr();
		closegraph();
		settextstyle(SMALL_FONT,HORIZ_DIR,7);
		setcolor(WHITE);
		outtextxy(150,400,"(Press enter to go back to the menu)");
		menu();

		closegraph();

	}

	void search()              //for the function to search the criminal
	{
		clrscr();
		int gdriver=DETECT,gmode;
		initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
		setbkcolor(CYAN);
		setcolor(GREEN);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
		outtextxy(230,5,"SEARCH");
		line(230,40,330,40);
		int cnumb,flag=0;
		gotoxy(15,15);
		cout<<"Enter the criminal number to be searched for:(1400 - 1440)"<<endl;
		gotoxy(15,16);
		cin>>cnumb;
		ifstream fin("crim1.dat");
		while(!fin.eof())
		{
			fin.read((char*)&crim,sizeof(crim));
			if(crim.crno==cnumb)
			{
				flag=1;
				gotoxy(15,18);
				cout<<"The criminal number is:"<<crim.crno<<endl;
				gotoxy(15,20);
				cout<<"The name of the criminal is :"<<crim.name<<endl;
				gotoxy(15,22);
				cout<<"The number in the list of most wanted is:"<<crim.most<<endl;
				gotoxy(15,24);
				cout<<"The crime committed by the criminal is:"<<crim.crime<<endl;
				getch();
				closegraph();
			}
			if(flag==0)
				setcolor(BLACK);
				settextstyle(SMALL_FONT,HORIZ_DIR,5);
				outtextxy(200,8,"The given criminal number is not found");
			fin.close();
		}
	}

	void thank()	            //for the last page
	{
		clrscr();
		int gdriver=DETECT,gmode;
		initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
		setbkcolor(WHITE);
		settextstyle(SANS_SERIF_FONT,HORIZ_DIR,8);
		setcolor(BLUE);
		delay(200);
		outtextxy(160,150,"T");
		delay(1000);
		outtextxy(200,150,"H");
		delay(1000);
		outtextxy(240,150,"A");
		delay(1000);
		outtextxy(285,150,"N");
		delay(1000);
		outtextxy(325,150,"K");
		delay(1000);
		outtextxy(380,150,"Y");
		delay(1000);
		outtextxy(415,150,"O");
		delay(1000);
		outtextxy(465,150,"U");
		delay(500);
		outtextxy(500,150,".");
		delay(500);
		outtextxy(510,150,".");
		delay(500);
		outtextxy(520,150,".");
		delay(1500);
		closegraph();
	}

	void menu()            //for the menu with the displaying options
	{
		int pass=6753;
		int num;
		clrscr();
		int gdriver=DETECT,gmode;
		initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
		setcolor(GREEN);
		settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
		outtextxy(250,0,"MENU");
		line(250,35,333,35);
		{
			setcolor(WHITE);
			settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
			outtextxy(215,45,"1.Most Wanted");
			outtextxy(215,65,"2.Search");
			outtextxy(215,85,"3.Input new Entries");
			outtextxy(215,105,"4.Exit");
			int choice;
			gotoxy(10, 13);
			cout<<"Input the choice to be viewed"<<endl;
			gotoxy(10,14);
			cin>>choice;
			closegraph();
			if(choice==1)
			{
				clrscr();
				most();             //call to the function for the most wanted list
				menu();             //call to the function to go back to the menu
				closegraph();
			}
			else if(choice==2)
			{
				clrscr();
				gotoxy(25,10);
				cout<<"Enter the password to search :"<<endl;
				gotoxy(25,11);
				cin>>num;
				if(num==pass)
				{
					search();           //call to the function for the searching page
					menu();            //call to the function to go back to the menu
					closegraph();
				}
				else
				{
					int gdriver=DETECT,gmode;
					initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
					setbkcolor(RED);
					setcolor(WHITE);
					settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
					outtextxy(125,200,"WRONG PASSWORD!!");
					getch();
					menu();             //call to the function for the menu
					closegraph();
				}
			}
			else if(choice==3)
			{
				crim.entry();          //call to the function for the new entries page
				menu();           //call to the function to go back to the menu
			}
			else if(choice==4)
			{
				thank();              //call to the function for the thank you page
			}
		closegraph();
		}
	}

	void enter()                  //function for viewing the project
		{
		clrscr();
		int n,given=782331;
		int gdriver=DETECT,gmode;
		initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
		settextstyle(SMALL_FONT,HORIZ_DIR,5);
		setcolor(WHITE);
		gotoxy(17,12);
		cout<<"Enter the password to view the project:"<<endl;
		gotoxy(17,13);
		cin>>n;
		if(n==given)
		{
			welcome();    //call to the function for the welcoming page
			intro();      //call to the function for the introductory page
			front();      //call to the function for the opening page
			menu();       //call to the function for the menu page
		}
		else
		{
			clrscr();
			int gdriver=DETECT,gmode;
			initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
			setbkcolor(RED);
			setcolor(WHITE);
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
			outtextxy(125,200,"WRONG PASSWORD!!");
			delay(2500);
		}
	}

	void main()
	{
		enter();      //call to the function for viewing the project
	}





