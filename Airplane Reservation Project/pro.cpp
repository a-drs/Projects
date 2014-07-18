//DSL MINI PROJECT

#include<iostream>//including header files
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<fstream>
#include<time.h>
#include<stack>
#include<list>
using namespace std;
class tree
{//class declaration

public:
char name[5];
char time[10];
char dest[15];
char gate[5];
char n[20];
char fl[5];//variable declaration
int seat[60][6];//60 rows 6 A-F
int rw;//for seat number
char col;
tree *left;
tree *rt;
int flag;
 //list<tree>l;

tree()
{

}
tree(char b[],char a[] ,char c[],char d[])
{
    strcpy(name,a);
    strcpy(time,b);
    strcpy(dest,c);
    strcpy(gate,d);
}

void create(char [],char [],char [],char [],char[],tree *,tree *);//method declaration
void delayed(int,char*[],tree *);
void search(char [],char[],tree *r);
void board(char [],char [],tree *r);
void select();
void passdata();
void dep(char *[]);
int inter(char []);
void inorder(tree *);
void preorder(tree *);
void create_list(tree *);
void update(char*[],tree *);
void print();
int passval(char []);
int flvalid(char *);

    friend bool operator<(const tree &o1,const tree &o2);
  friend bool operator>(const tree &o1,const tree &o2);
  friend bool operator==(const tree &o1,const tree &o2);
  friend bool operator!=(const tree &o1,const tree &o2);
};




bool operator<(const tree &o1,const tree &o2)
{
 return o1.time < o2.time;
}

bool operator>(const tree &o1,const tree &o2)
{
 return o1.time > o2.time;
}

bool operator==(const tree &o1,const tree &o2)
{
 return o1.time == o2.time;
}

bool operator!=(const tree &o1,const tree &o2)
{
 return o1.time !=  o2.time;
}







void ptime(char [],char[]);

int main(int argc, char *argv[])
{//main method

//clrscr();
tree *r,*q,p;
char i[5],x[70];
int c,h,d,f,ch,chk;
f=0;


	char input[70];
	ofstream fout;
	fout.open(argv[1]);
fout<<"KL07\n11:00:00\nLONDON\n01\n";
fout<<"EA11\n12:45:00\nDUBAI\n02\n";
fout<<"QA78\n14:00:00\nSYDNEY\n5A\n";
fout<<"AA05\n15:00:00\nNY\n03\n";
fout<<"ML16\n16:30:00\nSING\n04\n";
fout<<"IA46\n17:00:00\nFRANK\n4A\n";
//cout<<"Enter a flight name ";
//cin>>i;//taking data for root node

fout.close();
fout.open("interpol.txt");
fout<<"Kartik\n";
fout<<"Julien\n";
fout<<"Torres\n";
fout<<"Asif\n";
fout<<"Dawood\n";
fout<<"Javed\n";
fout.close();
char line[5];
char line1[10];
char line2[15];
char line3[5];
ifstream fin;

fin.open(argv[1]);
fin.getline(line,5);
fin.getline(line1,10);
fin.getline(line2,15);
fin.getline(line3,5);
strcpy(i,line);

r=new tree;
strcpy(r->name,i);
strcpy(r->time,line1);
strcpy(r->dest,line2);
strcpy(r->gate,line3);
r->left=NULL;
r->rt=NULL;
r->flag=1;
q=r;
//cout<<"\nEnter data value, 0 to stop ";
//cin>>i;
while(fin)
{
fin.getline(line,5);
fin.getline(line1,10);
fin.getline(line2,15);
fin.getline(line3,5);
p.create(line,line1,line2,line3,r->name,r,q);//creating further nodes
}
fin.close();
cout<<"\n\t\t\t\tOLD TRAFFORD AIRPORT\n\n";
cout<<"\nThe flight data is : \nNAME\tTIME\t\tDEST\tGATE\n";
p.inorder(r);
//cout<<"\nthe preorder traversal is : \nNAME\t\tTIME\t\tDEST\t\tGATE\n";
//p.preorder(r);
do
{
cout<<"\nEnter your user type : \n 1. Administrator \n 2. Passenger\n 3. Exit";
cin>>h;
switch(h)
{

case 1:
cout<<"\nDo you want to edit flight timings? 1.Yes 2.No\n";
cin>>d;
if(d)
{
cout<<"\nChange in flight schedule : \n";
p.delayed(argc,argv,r);
cout<<"\nThe update flight data is : \nNAME\tTIME\t\tDEST\tGATE\n";
p.inorder(r);
}
break;


case 2:

p.dep(argv);
cout<<"\n\t\t\tAIRPORT CONFIRMATION SYSTEM\n";
cout<<"\t\tWelcome To Old Trafford Airport\n";
p.passdata();
p.search(p.n,p.fl,r);
if(!p.flag)
{
cout<<"\nFlight not found. Please Enter details again.\n";
}
break;

default:
exit(0);

}
}
while(1);
//ptime(input,x);
//cout<<"\nMain time ="<<input<<endl;
getch();
return 0;
}


void tree :: passdata()
{
  int chk;
do
{
cout<<"Please enter your name\n";
cin>>n;
if(inter(n))
{
    cout<<"\nYou are on Interpol's blacklist. You will not be permitted to board your flight.\n";
    return;
}
chk=passval(n);
}
while(!chk);

do
{
cout<<"\nPlease enter your flight name, for which you want to confirm your booking : \n";
 cin>>fl;
 chk=flvalid(fl);
}
while(!chk);
}


void tree :: create(char x[],char x1[],char x2[],char x3[],char root[],tree *r,tree *roo)
{
if(strcmp(x,root)<0)//deciding layout
{
	if(r->left==NULL)
	{

	r->left=new tree;//creating new nodes
	(r->left)->flag=(r->flag)+1;
	r=r->left;
	r->left=r->rt=NULL;
	strcpy(r->name,x);
	strcpy(r->time,x1);
	strcpy(r->dest,x2);
	strcpy(r->gate,x3);

	}
	else
	{
	  create(x,x1,x2,x3,(r->left)->name,r->left,roo);
	}
}
else if(strcmp(x,root)>0)
{
	if(r->rt==NULL)
	{

	r->rt=new tree;
	(r->rt)->flag=(r->flag)+1;
	r=r->rt;
	r->left=NULL;
	r->rt=NULL;
	strcpy(r->name,x);
	strcpy(r->time,x1);
	strcpy(r->dest,x2);
    strcpy(r->gate,x3);
	}
	else
	{
	  create(x,x1,x2,x3,(r->rt)->name,r->rt,roo);//recursive call
	}
}

}


void tree :: dep(char* argv[])
{
 list<tree> l;
 list<tree>::iterator P;

char line0[5];
char line1[10];
char line2[15];
char line3[5];
ifstream fin;
char i[5];
fin.open(argv[2]);
while(fin)
{
fin.getline(line0,5);
fin.getline(line1,10);
fin.getline(line2,15);
fin.getline(line3,5);
l.push_back(tree(line1,line0,line2,line3));
}
fin.close();
l.sort();
cout<<"\n\n\n\t DEPARTURE LIST";
cout<<"\n\nTIME\tFLIGHT\tDEST\tGATE\n";
P=l.begin();
while(P!=l.end())
{
 P->print();
 P++;
}
}

void tree :: print()
{
 cout<<"\n"<<time;
 cout<<" "<<name;
 cout<<"\t"<<dest;
 cout<<"\t"<<gate;
}

void tree ::  delayed(int argc,char* argv[],tree *r)
{
int x;
char f[5];
char t[10];
do
{
cout<<"\nEnter the name of the flight for which you want to change time: ";
cin>>f;
x=flvalid(f);
}
while(!x);

ofstream fout;
char line[10];
fstream fin1,fin2;
fin1.open(argv[1],ios::in);
fin2.open(argv[2],ios::out);
while(fin1)
{

fin1.getline(line,10);
//if(!strcmp(line,"EA11"))
if(!strcmp(line,f))
{
   cout<<"\nEnter the new time(HH:MM:SS): ";
   cin>>t;
    //fin2<<"EA11\n";
    fin2<<f<<"\n";
    //fin2<<"02:00:00\n";
    fin2<<t<<"\n";
    fin1.getline(line,10);
    fin1.getline(line,10);
   // fin2<<"DUBAI\n";
    fin2<<line<<"\n";
    fin1.getline(line,10);
    fin2<<line<<"\n";
   // fin2<<"06\n";
 /* fin1.getline(line,10);
  fin1.getline(line,10);
  fin1.getline(line,10); */
}
else{
  fin2<<line<<"\n";
}
}
fin1.close();
fin2.close();
update(argv,r);
}

void tree :: update(char * argv[],tree *r)
{

char line0[5];
char line1[10];
char line2[15];
char line3[5];
ifstream fin;
char i[5];
fin.open(argv[2]);
fin.getline(line0,5);
fin.getline(line1,10);
fin.getline(line2,15);
fin.getline(line3,5);
strcpy(i,line0);

strcpy(r->name,i);
strcpy(r->time,line1);
strcpy(r->dest,line2);
strcpy(r->gate,line3);
r->left=NULL;
r->rt=NULL;
r->flag=1;
tree *q=r;
//cout<<"\nEnter data value, 0 to stop ";
//cin>>i;
while(fin)
{
fin.getline(line0,5);
fin.getline(line1,10);
fin.getline(line2,15);
fin.getline(line3,5);
create(line0,line1,line2,line3,r->name,r,q);//creating further nodes
}
fin.close();
}


void tree :: search(char n[],char f[],tree *r)
{

    if(r)
    {

    if(!strcmp(f,(r->name)))
    {
        select();
        board(n,f,r);
        flag=1;
    }
    search(n,f,r->left);
    search(n,f,r->rt);
    }

}

void tree :: board(char n[],char f[],tree *r)
{

char x[70],t[70];
ptime(x,t);
char food[10];
int fd;
cout<<"\nEnter your food choice : 1. VEG 2. NON-VEG\n";
cin>>fd;
if(fd==1)
strcpy(food,"VEG");
else
strcpy(food,"NON-VEG");


ofstream fout;
fout.open("boarding.txt");
fout<<"\t\t\t\tOLD TRAFFORD AIRPORT\nLocation: Manchester\t\t\tBOARDING PASS\t\t\t"<<t<<"\n";
fout<<"Passenger Name  : "<<n<<"\n";
fout<<"Flight Number : "<<r->name<<"\t\t\t\t\t\t\tSeat Number : "<<rw<<col<<"\n";
fout<<"Departure Time : "<<r->time<<"\t\t\t\t\t\tFood Choice : "<<food<<"\n";
fout<<"Gate No. : "<<r->gate<<"\n";
fout<<"Destination : "<<r->dest<<"\n";

fout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
fout<<"Important Information : \n";
fout<<"\n1. No sharp objects such as knives, scissors,, etc. are permitted on board.\n";
fout<<"2. Guns and other weapons not permitted on board. Individuals found in possession of such objects shall face prosecution.\n";
fout<<"3. Food and beverages must necessarily be procured in-flight\n";
fout<<"4. Maximum baggage limit 20 kg per person. \n";
fout<<"5. Once confirmed, a ticket cannot be cancelled.\n";
fout<<"\n\n\n\nWe hope you enjoy your flight and use our services again.\n";
fout.close();

cout<<"\nPlease collect your boarding pass now. Thank you.\n";
}



void tree :: select()
{
 int col1;

int i,j,n;

for( i=0;i<60;i++)
     for( j=0;j<6;j++)
     if(j!=2 && i%4!=0)
       seat[i][j]=0;        //initializing the matrix
     else
       seat[i][j]=1;
 i=1;


cout<<"\t\t\t\tSEAT SELECTION\t\t\t\t\n";
cout<<"\nPlease select your ticket class : \n1. Business Class\n2. First Class\n3. Economy Class\n";
cin>>n;

cout<<"\nThe seats available to you are : \n"<<endl;
cout<<"     \tA B C\t\tD E F\n\n";
 for(i=(n*20)-20;i<(n*20);i++)
 {
     cout<<"ROW "<<i<<"\t";
     for(j=0;j<6;j++)
    {
        if(j==3)
        cout<<"\t\t"<<seat[i][j]<<" ";

        else
        cout<<seat[i][j]<<" ";
    }

    cout<<endl;
 }

 cout<<endl;
  while(1)
  {
  up:
  cout<<"enter your seat preference";
  cout<<"\nrow followed by column:eg 32A::";//format
  cin>>rw>>col;
  col1=(int)(col-65);

 // cout<<col1;
  if(seat[rw][col1]==0)
  {
    seat[rw][col1]=1;        //setting seat to 1
      if(col1==0 || col1==5)
	cout<<"window seat::";
  cout<<"reserved\n";
break;
  }
  else
  {
  cout<<"already reserved try again\n";
    }


   }

}


int tree :: inter(char s[])
{
    char crime[15];
    int x=0,y;
    ifstream fin;

    fin.open("interpol.txt");
    while(fin)
    {
        fin.getline(crime,15);
        if(!strcmp(s,crime))
        {
        x=1;
        return 1;
        }
    }
return 0;
}




void tree :: inorder(tree *r)
{
    if(r)
    {
        inorder(r->left);
        cout<<r->name<<"\t"<<r->time<<"\t"<<r->dest<<"\t"<<r->gate<<endl;
        inorder(r->rt);
    }
}


void tree :: preorder(tree *r)
{
    if(r)
    {
        cout<<r->name<<"\t"<<r->time<<"\t"<<r->dest<<"\t"<<r->gate<<endl;
        preorder(r->left);
        preorder(r->rt);
    }
}


void ptime(char a[],char str[]) //system time c++
//we'll have to use this func in proj
{

   time_t t;

   struct tm *tstruct;
   time(&t);

  tstruct=localtime(&t);

 // printf("current time::%s",asctime(tstruct));
   //cout<<asctime(tstruct);
     strcpy(str,asctime(tstruct));
     //outtextxy(380,435,str);
     //cout<<"\nusing tstruct:"<<str;
      char b[6];
    int j;
     strcpy(a,str);
      for(j=0;j<15;j++)
   {                             //reducing string to a usable format
     a[j]=a[j+11];


   }

   a[j-7]='\0';
   //cout<<"reduced string::"<<a;
}

int tree :: passval(char str[])
{

int i,c;
 i=0;
while(i<strlen(str))
{
    //c=(int)str[i];
    //if ( ! (  (c>=65 && c<=90) || (c>=97 && c<=132) ) )
        if(!isalpha(str[i]))
        return 0;
    i++;
}

return 1;
}

int tree :: flvalid(char *str)
{
   int cnt1=0,cnt2=0;
   //len=strlen(str);
int i;
   for( i=0;i<2;i++)
   {
	if(isupper(*str)) //checking 1st two chars (upper case alphabets)
	{
	 cnt1++;
	}
	str++;
   }
   if(cnt1==2)
   {

       for(i=0;i<2;i++)
      {
	if(isdigit(*str))   //checking next two digits
	{
	 cnt2++;
	}
	str++;

      }
      if(cnt2==2)
      {
	 return 1;  //valid flight no.
      }
      else
      {
	return 0; //invalid flight no.
      }

   }
   else
   {
     return 0;  //flight number not valid
   }



}

/*  OUTPUT -


C:\TurboC++\Disk\TurboC3\project>som hey.txt

the inorder traversal is :
N       T       D

AA05    t4      NY
EA11    t2      DUBAI
IA46    t6      FRANKFURT
KL07    t1      LONDON
ML16    t5      SINGAPORE
QA78    t3      SYDNEY

the preorder traversal is :
N       T       D
KL07    t1      LONDON
EA11    t2      DUBAI
AA05    t4      NY

IA46    t6      FRANKFURT
QA78    t3      SYDNEY
ML16    t5      SINGAPORE

*/
