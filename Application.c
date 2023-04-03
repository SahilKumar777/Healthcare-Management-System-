#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<time.h>


void head();                                             //for heading
void EX();                                               //for exit
void def();                                              //for default
void wrongp();
void f_nopen();
void pas1(char pass[21],int *id);                           //    getting password
void patient();                                          //    patient module
void doctor();                                           //    doctor module
void rgcount();                                          //    register counter
void newp();                                             //    new patient record
void newd();                                             //    new doctor record
void denq();                                             //    doctors enquiry
void modp(int k);                                        //    modofying patient details
void modd(int k);                                        //    modofying doctor details
void viewp(int k,int i);                                 //    viewing patient details
void viewd(int k);                                       //    viewing doctor details
void makerpt(int k,int w);                               //    making report
void login(char f[21],char pass[21],int *id,char ps[21],int *ck);
void chpass(char f[21],char k);                          //    changing password
void fpass(char f[21]);                                  //    forgotton password

struct dob                                               //    date of birth structure
{
int dd;
int mm;
int yy;
};

struct addr                                              //    structure for address
{
int hno;
char area[51];
char city[21];
char state[21];
char pincode[7];
};

struct pat                                               //    structure for patient details
{
char name[21];
char fname[21];
char sex;
struct dob dobp;
char bg[4];
struct addr adress1;
char p_no[11];
char doc[21];
char test[41];
char disease[51];
char remark[200];
char status;
};

struct doct                                               //   structure for doctor details
{
 char name[21];
 char type[21];
 char sex;
 struct dob dobd;
 char bg[4];
 struct addr adress2;
 char p_no[11];
 double salary;
 char status;
};

char df[21]="dpass.dat",pf[21]="ppass.dat",cf[21]="cpass.dat";


void main()
{
 int ch;
clrscr();
do
{
 
printf("\t\t\tENTER YOUR CHOICE-(1 TO 4)"); 
printf("\n\n\t********* MAIN MENU ********** ");
printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ");
printf("\n\t  1. PATIENT");
printf("\n\t  2. DOCTOR");
printf("\n\t  3. REGISTER COUNTER");
printf("\n\t  4. EXIT\n\nCHOICE=");
fflush(stdin);

fflush(stdin);
switch(4)
{
case 1: patient();
        break;
case 2: doctor();
        break;
case 3: rgcount();
        break;
case 4: EX();             
          exit(1);
          break;
default :def();
         break;
         }

       }while(ch!=4);

getch();
}

void head()
{

printf("================================================================================");
printf("[\"]  [\"]                 _________________________                     [\"]  [\"]");
printf("\n[ ][][ ]   ************* HEALTH CARE CENTER SYSTEM  *************      [ ][][ ]");
printf("\n[_]  [_]                 ^^^^^^^^^^^^^^^^^^^^^^^^^                     [_]  [_]");
printf("\n================================================================================");
printf("\n");
}

void EX()
{int t=5;
while(t!=0)
        { head();
          printf("\n\n\n\n\n\n\n\n\n\n\t\t\t***** THANKYOU FOR VISITING US *****");
          printf("\n\t\t\t*****  WISH YOU A HEALTHY LIFE *****");
          printf("\n\n\t EXIT IN (%d) SECONDS",t--);
          delay(1000);
         }             
  }

void def()
{printf("\n\t\t\t !!!! YOU HAVE ENTERED WRONG CHOICE !!!!");
         printf("\n\t\t\t PLEASE ENTER CORRECT CHIOCE");
         delay(3000);
}

void wrongp()
{printf("\n\t\t\t!!! WRONG ID OR PASSWORD !!!\n\t\t\t      !!! TRY AGAIN !!!");  
            delay(3000);
 }

void f_nopen()
{printf("\n\t\t\t!!! FILE NOT OPENED !!!\n\t\t\t     !!! TRY AGAIN !!!");  
            delay(3000);
}

void patient()
{int ch,id,ck;
 char pass[21],ps[21];
do
{
 
printf("\t\t\tENTER YOUR CHOICE-(1 TO 8)"); 
printf("\n\n\t******** PATIENT MENU ******** ");
printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ");
printf("\n\t  1. VIEW PATIENT REPORT");
printf("\n\t  2. VIEW PATIENT DETAILS");
printf("\n\t  3. MODIFY PATIENT DETAILS");
printf("\n\t  4. DOCTORS ENQUIRY");
printf("\n\t  5. CHANGE PASSWORD");
printf("\n\t  6. FORGOT PASSWORD");
printf("\n\t  7. GO TO MAIN MENU");
printf("\n\t  8. EXIT\n\nCHOICE=");
fflush(stdin);

fflush(stdin);
switch(8)
{
case 1:login(pf,pass,&id,ps,&ck); 
       if(ck)
	{if(!strcmp(pass,ps))
           viewp(id,0);   
         else
	   wrongp();
         }
         else
	   f_nopen();	   
        break;
case 2: login(pf,pass,&id,ps,&ck); 
       if(ck)
	{if(!strcmp(pass,ps))
           viewp(id,1);   
         else
	   wrongp();
         }
         else
	   f_nopen();	   
        break;
case 3: login(pf,pass,&id,ps,&ck); 
       if(ck)
	{if(!strcmp(pass,ps))
           modp(id);   
         else
	   wrongp();
         }
         else
	   f_nopen();	           
        break;
case 4: denq();
        break;
case 5: login(pf,pass,&id,ps,&ck); 
       if(ck)
	{if(!strcmp(pass,ps))
           chpass(pf,id);   
         else
	   wrongp();
         }
         else
	   f_nopen();	   
        break;
case 6: fpass(pf);
        break;
case 7: break;
case 8: EX();
        exit(1);
         break;
default :def();
         break;
         }
       }while(ch!=7);
     }

void doctor()
{
int ch,id,ck,w;
 char pass[21],ps[21];
do
{
 
printf("\t\t\tENTER YOUR CHOICE-(1 TO 8)"); 
printf("\n\n\t******** DOCTOR MENU ********");
printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ");
printf("\n\t  1. PATIENT ENQUIRY");
printf("\n\t  2. MAKE PATIENT REPORT");
printf("\n\t  3. VIEW DOCTOR DETAILS");
printf("\n\t  4. MODIFY DOCTOR DETAILS");
printf("\n\t  5. CHANGE PASSWORD");
printf("\n\t  6. FORGOT PASSWORD");
printf("\n\t  7. GO TO MAIN MENU");
printf("\n\t  8. EXIT\n\nCHOICE=");
fflush(stdin);
scanf("%d",&ch);
fflush(stdin);
switch(ch)
{
case 1:login(df,pass,&id,ps,&ck); 
       if(ck)
	{if(!strcmp(pass,ps))
           { printf("\nENTER PATIENT ID");
            fflush(stdin);            
            scanf("%d",&w);
            fflush(stdin);
            viewp(w,0);}   
         else
	   wrongp();
         }
         else
	   f_nopen();	   
        break;
case 2:login(df,pass,&id,ps,&ck); 
       if(ck)
	{if(!strcmp(pass,ps))
           {printf("\nENTER PATIENT ID");
            fflush(stdin);            
            scanf("%d",&w);
            fflush(stdin);
            makerpt(w,id);}   
         else
	   wrongp();
         }
         else
	   f_nopen();	   
        break;
case 3:login(df,pass,&id,ps,&ck); 
       if(ck)
	{if(!strcmp(pass,ps))
         viewd(id);
        else
	   wrongp();
         }
         else
	   f_nopen();	   
        break;
case 4: login(df,pass,&id,ps,&ck); 
       if(ck)
	{if(!strcmp(pass,ps))
         modd(id);
        else
	   wrongp();
         }
         else
	   f_nopen();	  
        break;
case 5: login(df,pass,&id,ps,&ck); 
       if(ck)
	{if(!strcmp(pass,ps))
           chpass(df,id);   
         else
	   wrongp();
         }
         else
	   f_nopen();	   
        break;
case 6: fpass(df);
        break;
case 7: break;
case 8: EX();
        exit(1);
        break;
default :def();
         break;
         }
       }while(ch!=7);
     }


void rgcount()
{
int ch,id,ck,w;
 char pass[21],ps[21],cp[21],name[21]="sahil kumar";
do
{
 
printf("\t\t\tENTER YOUR CHOICE-(1 TO 8)"); 
printf("\n\n\t****** REGISTER COUNTER MENU ******");
printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ");
printf("\n\t  1. ADD NEW PATIENT RECORD");
printf("\n\t  2. ADD NEW DOCTOR RECORD");
printf("\n\t  3. MODIFY PATIENT DETAILS");
printf("\n\t  4. MODIFY DOCTOR DETAILS");
printf("\n\t  5. CHANGE PASSWORD");
printf("\n\t  6. FORGOT PASSWORD");
printf("\n\t  7. GO TO MAIN MENU");
printf("\n\t  8. EXIT\n\n\tCHOICE=");
fflush(stdin);
scanf("%d",&ch);
fflush(stdin);
switch(ch)
{
case 1: login(cf,pass,&id,ps,&ck); 
       if(ck)
	{if(!strcmp(pass,ps))
         newp();
        else
	 wrongp();
         }
         else
	   f_nopen();
        break;
case 2: login(cf,pass,&id,ps,&ck); 
       if(ck)
	{if(!strcmp(pass,ps))
         newd();
        else
	   wrongp();
         }
         else
	   f_nopen();	   
        break;
case 3:login(cf,pass,&id,ps,&ck); 
       if(ck)
	{if(!strcmp(pass,ps))
           {printf("\nENTER PATIENT ID");
            fflush(stdin);            
            scanf("%d",&w);
            fflush(stdin);
            modp(w);}   
         else
	   wrongp();
         }
         else
	   f_nopen();	   
                 break;
case 4: login(cf,pass,&id,ps,&ck); 
       if(ck)
	{if(!strcmp(pass,ps))
           {printf("\nENTER DOCTOR ID");
            fflush(stdin);            
            scanf("%d",&w);
            fflush(stdin);
            modd(w);}   
         else
	   wrongp();
         }
         else
	   f_nopen();	   
        break;
case 5: login(cf,pass,&id,ps,&ck); 
       if(ck)
	{if(!strcmp(pass,ps))
           chpass(cf,id);   
         else
	   wrongp();
         }
         else
	   f_nopen();
        break;
case 6: printf("\nENTER YOUR NAME : ");
        gets(name);
        if(!strcmp(name,cp))
       { printf("\nYOUR ID IS : 1");
        printf("\nYOUR PASSWORD IS");
        }
       else
	   {printf("\n\t\t\t!!! WRONG NAME !!!\n\t\t\t      !!! TRY AGAIN !!!");  
            delay(2500);}
break;
case 7: break;
case 8: EX();
        exit(1);
        break;
default :def();
         break;
         }
       }while(ch!=7);
     }

void pas1(char pass[21],int *id)
{
int i=0,j,l;
 char p[21];char ch;

 while(ch!=13)
 {
   start1:
  
   printf("\n\n\t\t\t--------------------------");
   printf("\n\t\t\t|@@@@@@ LOGIN PAGE @@@@@@|");
   printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^");   
   printf("\nEnter id=");
   if(i)
    {printf("%d\n",l);}
   else
   {
fflush(stdin);
scanf("%d",&l);}
   printf("Enter PASS=");
   for(j=1;j<i;j++)
     {printf("*");}
if(ch==13)
   break;
if(i)
  printf("%c",p[i-1]);
fflush(stdin);  
ch=getch();
  if(ch!=13)
   p[i++]=ch ;
if(ch==13){i++;
  goto start1;}
 }
 p[i-1]='\0';

*id=l;
}


void login(char f[21],char pass[21],int *id,char ps[21],int *ck)
{

char fpd;
int set,no;

 if(!pt)
 {
  pt=fopen(f,"wb+");
  if(!pt)
  {
   printf("\n---- UNABLE TO OPEN FILE ---");
   delay(3000);
   *ck=0;
   goto end1;}
 }
*ck=1;
pas1(pass,id);
no=*id;
set=(no-1)*21;
fseek(pt,set,SEEK_SET);
fread(ps,21,1,pt);
fclose(pt);

end1:
}



void chpass(char f[21],char k)
{
FILE *pt;
char p1[21],p2[21],ch,cha;
int i=0,x,j,set;
pt=fopen(f,"rb+");
 if(!pt)
 {
  pt=fopen(f,"wb+");
  if(!pt)
  {
   printf("\n---- UNABLE TO OPEN FILE ---");
   delay(3000);
   goto end2;
        }
     }

while(ch!=13)
 {start2 :
head();
printf("\n\n\t\t\t---------------------------------");
   printf("\n\t\t\t|####### CHANGE PASSWORD #######|");
   printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");  
   printf("\n\n\tENTER NEW PASSWORD:");
for(j=1;j<i;j++)
     {printf("*");}
if(ch==13)
   break;
if(i)
  printf("%c",p1[i-1]);
  ch=getch();
fflush(stdin);  
if(ch!=13)
   p1[i++]=ch ;
if(ch==13){i++;
  goto start2;}
 }
 p1[i-1]='\0';
x=i-1;
i=0;

while(cha!=13)
 {start3:
head();
  printf("\n\n\t\t\t####### CHANGE PASSWORD #######");
  printf("\n\n\tENTER NEW PASSWORD:");
for(j=0;j<x;j++)
    {printf("*");}
printf("\n\tCONFIRM NEW PASSWORD:");
for(j=1;j<i;j++)
     {printf("*");}
if(cha==13)
   break;
if(i)
  printf("%c",p2[i-1]);
fflush(stdin);  
cha=getch();
  if(cha!=13)
   p2[i++]=cha ;
if(cha==13){i++;
  goto start3;}
 }
 p2[i-1]='\0';

if(!strcmp(p1,p2))
 {
set=(k-1)*21;
fseek(pt,set,SEEK_SET);
fread(p1,21,1,pt);
fclose(pt);
}
else
{printf("\n\n\t\t\t#######  PASSWORD DON'T MATCH  #######");
 printf("\n\n\t\t\t      ####### TRY AGAIN #######");delay(3000);
}
end2:
}


void newp()
{
FILE *ptr,*fptr;
struct pat p;
int fsize,count,ofset,loc;
char dp[21]="1111";
ptr=fopen("patient.dat","rb+");
 if(!ptr)
 {
  ptr=fopen("patient.dat","wb+");
  if(!ptr)
  {
   printf("\n---- UNABLE TO OPEN FILE ---");
   delay(3000);
   goto end3;}
 }

fseek(ptr,0,SEEK_END);
fsize=ftell(ptr);
count=fsize/sizeof(struct pat);
ofset=count*sizeof(struct pat);
loc=count*sizeof(dp);



fptr=fopen("ppass.dat","rb+");
if(!fptr)
{
fptr=fopen("ppass.dat","wb+");
if(!fptr)
{printf("\n---- UNABLE TO OPEN FILE ---");
delay(3000);
goto end3;}
}

fseek(fptr,loc,SEEK_SET);
fwrite(dp,sizeof(dp),1,fptr);
fclose(fptr);

head();
printf("\n******** ADD NEW PATIENT RECORD *********");
printf("\nPATIENT NAME  :");
fflush(stdin);
gets(p.name);
printf("\nRELATIVE NAME :");
fflush(stdin);
gets(p.fname);
printf("\nGENDER(M or F):");
fflush(stdin);
p.sex=getche();
printf("\nDATE OF BIRTH :");
fflush(stdin);
printf("\n\tDAY   :");
scanf("%d",&(p.dobp.dd));
printf("\n\tMONTH :");
fflush(stdin);
scanf("%d",&(p.dobp.mm));
printf("\n\tYEAR  :");
fflush(stdin);
scanf("%d",&(p.dobp.yy));
printf("\nBLOOD GROUP   :");
fflush(stdin);
gets(p.bg);
printf("\nADDRESS:");
printf("H_no  :");
fflush(stdin);
scanf("%d",&(p.adress1.hno));
printf("\n\tAREA  :");
fflush(stdin);
gets(p.adress1.area);
printf("\n\tCITY  :");
fflush(stdin);
gets(p.adress1.city);
printf("\n\tSTATE :");
fflush(stdin);
gets(p.adress1.state);
printf("\n\tPINCODE:");fflush(stdin);
gets(p.adress1.pincode);
printf("\nCONTACT NO.   :");
fflush(stdin);
gets(p.p_no);
p.status='*';

fseek(ptr,ofset,SEEK_SET);
fwrite(&p,sizeof(struct pat),1,ptr);
fclose(ptr);


head();
printf("\n\n\n\t\t\t>>>>>>>>> RECORD CREATED SUCESSFULY <<<<<<<<<<");
printf("\n\n PLEASE NOTE YOUR PATIENT-ID IS=%d",count+1);
printf("\n DEFAULT PASSWORD IS \"1111\"  ");
printf("\n\n  ");
getch();

end3:
}




void newd()                                                                 
{
FILE *ptr,*fptr;
struct doct d;
int fsize,count,ofset,loc;
char dp[21]="1111";
ptr=fopen("doctor.dat","rb+");
 if(!ptr)
 {
  ptr=fopen("doctor.dat","wb+");
  if(!ptr)
  {
   printf("\n---- UNABLE TO OPEN FILE ---");
   delay(3000);
   goto end4;}
 }

fseek(ptr,0,SEEK_END);
fsize=ftell(ptr);
count=fsize/sizeof(struct pat);
ofset=count*sizeof(struct pat);
loc=count*sizeof(dp);


fptr=fopen("dpass.dat","rb+");
if(!fptr)
{
fptr=fopen("dpass.dat","wb+");
if(!fptr)
{printf("\n---- UNABLE TO OPEN FILE ---");
delay(3000);
goto end4;}
}

fseek(fptr,loc,SEEK_SET);
fwrite(dp,sizeof(dp),1,fptr);
fclose(fptr);

head();
printf("\n******** ADD NEW DOCTOR RECORD *********");
printf("\nDOCTOR NAME      :");
fflush(stdin);
gets(d.name);
printf("\nSPECIALISATION IN:");
fflush(stdin);
gets(d.type);
printf("\nGENDER (M or F)  :");
fflush(stdin);
d.sex=getche();
printf("\nDATE OF BIRTH     ");
printf("\n\t  DAY    :");
fflush(stdin);
scanf("%d",&(d.dobd.dd));
printf("\n\t  MONTH  :");
fflush(stdin);
scanf("%d",&(d.dobd.mm));
printf("\n\t  YEAR   :");
fflush(stdin);
scanf("%d",&(d.dobd.yy));
printf("\nBLOOD GROUP      :");
fflush(stdin);
gets(d.bg);
printf("\nADDRESS          ");
printf("\n\t H_no    :");
fflush(stdin);
scanf("%d",&(d.adress2.hno));
printf("\n\t AREA    :");
fflush(stdin);
gets(d.adress2.area);
printf("\n\t CITY    :");
fflush(stdin);
gets(d.adress2.city);
printf("\n\t STATE   :");
fflush(stdin);
gets(d.adress2.state);
printf("\n\tPIN CODE       :");
fflush(stdin);
gets(d.adress2.pincode);
printf("\nCONTACT NO.      :");
fflush(stdin);
gets(d.p_no);
d.status='*';

fseek(ptr,ofset,SEEK_SET);
fwrite(&d,sizeof(struct doct),1,ptr);
fclose(ptr);


head();
printf("\n\n\n\t\t\t>>>>>>>>> RECORD CREATED SUCESSFULY <<<<<<<<<<");
printf("\n\n PLEASE NOTE  DOCTOR-ID IS=%d",count+1);
printf("\n DEFAULT PASSWORD IS \"1111\"  ");
printf("\n\n  ");
getch();

end4:
}


void modp(int k)
{
FILE *ptr;
struct pat p1,p2;
int fsize,count,ofset;
char g[2];
ptr=fopen("patient.dat","rb+");
 if(!ptr)
 {
  ptr=fopen("patient.dat","wb+");
  if(!ptr)
  {
   printf("\n---- UNABLE TO OPEN FILE ---");
   delay(3000);
   goto end5;}
 }

fseek(ptr,0,SEEK_END);
fsize=ftell(ptr);
count=fsize/sizeof(struct pat);



if((!count)&&(k>count))
{
   printf("\n---- NO RECORD AVAILABLE ---");
   delay(3000);
   goto end5;
}
else
{
ofset=(k-1)*sizeof(struct pat);
fseek(ptr,ofset,SEEK_SET);
fread(&p2,sizeof(struct pat),1,ptr);
head();
printf("\n\t\t\t ----- MODIFY DETAILS OF PATIENT ----- ");
printf("\n IF WANT TO RETAIN PARTICULAR DETAIL");
printf("\n PRESS ENTER KEY (0 for hno. & DOB)");
printf("\nPATIENT NAME   :");
fflush(stdin);
gets(p1.name);
printf("\nRELATIVE NAME  :");
fflush(stdin);
gets(p1.fname);
printf("\nGENDER (M or F):");
fflush(stdin);
gets(g);
printf("\nDATE OF BIRTH");
printf("\n\tDAY    :");
fflush(stdin);
scanf("%d",&(p2.dobp.dd));
printf("\n\tMONTH  :");
fflush(stdin);
scanf("%d",&(p2.dobp.mm));
fflush(stdin);
printf("\n\tYEAR   :");
fflush(stdin);
scanf("%d",&(p2.dobp.yy));
printf("\nBLOOD GROUP    :");
fflush(stdin);
gets(p1.bg);
printf("\nADDRESS         ");
printf("\n\tH_no   :");
fflush(stdin);
scanf("%d",&(p1.adress1.hno));
printf("\n\tAREA   :");
fflush(stdin);
gets(p1.adress1.area);
printf("\n\tCITY   :");
fflush(stdin);
gets(p1.adress1.city);
printf("\n\tSTATE  :");
fflush(stdin);
gets(p1.adress1.state);
printf("\n\tPINCODE:");
fflush(stdin);
gets(p1.adress1.pincode);
printf("\nCONTACT NO.    :");
fflush(stdin);
gets(p1.p_no);


if(strlen(p1.name)!=0)
strcpy(p2.name,p1.name);
if(strlen(p1.fname)!=0)
strcpy(p2.fname,p1.fname);
if(strlen(g)!=0)
p2.sex=g[0];
if((p1.dobp.dd)!=0)
p2.dobp.dd=p1.dobp.dd;
if((p1.dobp.mm)!=0)
p2.dobp.mm=p1.dobp.mm;
if((p1.dobp.yy)!=0)
p2.dobp.yy=p1.dobp.yy;
if(strlen(p1.bg)!=0)
strcpy(p2.bg,p1.bg);
if((p1.adress1.hno)!=0)
p2.adress1.hno=p1.adress1.hno;
if(strlen(p1.adress1.area)!=0)
strcpy(p2.adress1.area,p1.adress1.area);
if(strlen(p1.adress1.city)!=0)
strcpy(p2.adress1.city,p1.adress1.city);
if(strlen(p1.adress1.state)!=0)
strcpy(p2.adress1.state,p1.adress1.state);
if(strlen(p1.adress1.pincode)!=0)
strcpy(p2.adress1.pincode,p1.adress1.pincode);
if(strlen(p1.p_no)!=0)
strcpy(p2.p_no,p1.p_no);

fseek(ptr,ofset,SEEK_SET);
fwrite(&p2,sizeof(struct pat),1,ptr);
fclose(ptr);


head();
printf("\n\n\n\t\t\t>>>>>>>>> RECORD MODIFIED SUCESSFULY <<<<<<<<<<");
printf("\n\n  ");
}
getch();

end5:
}


void modd(int k)
{
FILE *ptr;
struct doct p1,p2;
int fsize,count,ofset;
char g[2];
ptr=fopen("doctor.dat","rb+");
 if(!ptr)
 {
  ptr=fopen("doctor.dat","wb+");
  if(!ptr)
  {
   printf("\n---- UNABLE TO OPEN FILE ---");
   delay(3000);
   goto end6;
  }
 }

fseek(ptr,0,SEEK_END);
fsize=ftell(ptr);
count=fsize/sizeof(struct doct);



if((!count)&&(k>count))
{ 
   printf("\n---- NO RECORD AVAILABLE ---");
    delay(3000);
   goto end6;
}
 else
{
ofset=(k-1)*sizeof(struct doct);
fseek(ptr,ofset,SEEK_SET);
fread(&p2,sizeof(struct doct),1,ptr);
head();
printf("\n\n\n\n ---- MODIFY DETAILS OF DOCTOR ---- ");

printf("\n IF WANT TO RETAIN PARTICULAR DETAIL");
printf("\n PRESS ENTER KEY (0 for hno. & DOB)");
printf("\nDOCTOR NAME    :");
fflush(stdin);
gets(p1.name);
printf("\nSPECIALISATION :");
fflush(stdin);
gets(p1.type);
printf("\nGENDER (M or F):");
fflush(stdin);
gets(g);
printf("\nDATE OF BIRTH   ");
printf("\n\tDAY    :");
fflush(stdin);
scanf("%d",&(p1.dobd.dd));
printf("\n\tMONTH  :");
fflush(stdin);
scanf("%d",&(p1.dobd.mm));
printf("\n\tYEAR   :");
fflush(stdin);
scanf("%d",&(p1.dobd.yy));
printf("\nBLOOD GROUP    :");
fflush(stdin);
gets(p1.bg);
printf("\nADDRESS         ");
printf("\n\tH_no   :");
fflush(stdin);
scanf("%d",&(p1.adress2.hno));
printf("\n\tAREA   :");
fflush(stdin);
gets(p1.adress2.area);
printf("\n\tCITY   :");
fflush(stdin);
gets(p1.adress2.city);
printf("\n\tSTATE  :");
fflush(stdin);
gets(p1.adress2.state);
printf("\n\tPINCODE:");
fflush(stdin);
gets(p1.adress2.pincode);
printf("\nCONTACT NO.    :");
fflush(stdin);
gets(p1.p_no);
printf("\nSALARY         :");
fflush(stdin);
scanf("%lf",&(p1.salary));

if(strlen(p1.name)!=0)
strcpy(p2.name,p1.name);
if(strlen(p1.type)!=0)
strcpy(p2.type,p1.type);
if(strlen(g)!=0)
p2.sex=g[0];
if((p1.dobd.dd)!=0)
p2.dobd.dd=p1.dobd.dd;
if((p1.dobd.mm)!=0)
p2.dobd.mm=p1.dobd.mm;
if((p1.dobd.yy)!=0)
p2.dobd.yy=p1.dobd.yy;
if(strlen(p1.bg)!=0)
strcpy(p2.bg,p1.bg);
if((p1.adress2.hno)!=0)
p2.adress2.hno=p1.adress2.hno;
if(strlen(p1.adress2.area)!=0)
strcpy(p2.adress2.area,p1.adress2.area);
if(strlen(p1.adress2.city)!=0)
strcpy(p2.adress2.city,p1.adress2.city);
if(strlen(p1.adress2.state)!=0)
strcpy(p2.adress2.state,p1.adress2.state);
if(strlen(p1.adress2.pincode)!=0)
strcpy(p2.adress2.pincode,p1.adress2.pincode);
if(strlen(p1.p_no)!=0)
strcpy(p2.p_no,p1.p_no);
if(p1.salary!=0)
p2.salary=p1.salary;

fseek(ptr,ofset,SEEK_SET);
fwrite(&p2,sizeof(struct doct),1,ptr);
fclose(ptr);


head();
printf("\n\n\n\t\t\t>>>>>>>>> RECORD MODIFIED SUCESSFULY <<<<<<<<<<");
printf("\n\n  ");
}
getch();

end6:
}



void viewp(int k,int i)
{

FILE *ptr;
struct pat p;
int fsize,count,ofset;

ptr=fopen("patient.dat","rb+");
 if(!ptr)
 {
  ptr=fopen("patient.dat","wb+");
  if(!ptr)
  {
   printf("\n---- UNABLE TO OPEN FILE ---");
   delay(3000);
   goto end7;}
 }

fseek(ptr,0,SEEK_END);
fsize=ftell(ptr);
count=fsize/sizeof(struct pat);



if((!count)&&(k>count))
{
   printf("\n---- NO RECORD AVAILABLE ---");
   delay(3000);
   goto end7;}
 else
{
ofset=(k-1)*sizeof(struct pat);
fseek(ptr,ofset,SEEK_SET);
fread(&p,sizeof(struct pat),1,ptr);
fclose(ptr);

head();
if(i)
printf("\n\n\t\t\t********  PATIENT DETAILS *********");
else
printf("\n\n\t\t\t********  PATIENT REPORT *********");
printf("\n-------------------------------------------------------------------------------");
printf("\nPATIENT NAME :");
printf("%-20s",p.name);
printf("\tPATIENT ID    :");
printf("%04d",k);
printf("\nRELATIVE NAME:");
printf("%-20s",p.fname);
printf("\tGENDER(M or F):");
putchar(p.sex);
printf("\nDATE OF BIRTH:");
printf("%02d/%02d/%4d\t  ",p.dobp.dd,p.dobp.mm,p.dobp.yy);
printf("\tBLOOD GROUP   :");
puts(p.bg);
if(i)
{
printf("\nADDRESS      :");
printf("H_no:%-04d\t   ",p.adress1.hno);
printf("\tCONTACT NO.   :");
puts(p.p_no);
printf("\n\t      %s\n\t      %s %s\npin=%s ",p.adress1.area,p.adress1.city,p.adress1.state,p.adress1.pincode);
printf("\n-------------------------------------------------------------------------------");
}
else
{
 printf("\n-------------------------------------------------------------------------------");
 printf("\n\nCONSULTING DOCTOR:");
 puts(p.doc);
 printf("\n\tTEST NAME  :");
 puts(p.test);
 printf("\n\tREMARKS    :");
 puts(p.remark);
 printf("\n\n\t\t\t********  END OF REPORT *********");
}
}
getch();


end7:
}



void viewd(int k)
{

FILE *ptr;
struct doct p;
int fsize,count,ofset;

ptr=fopen("doctor.dat","rb+");
 if(!ptr)
 {
  ptr=fopen("doctor.dat","wb+");
  if(!ptr)
  {
   printf("\n---- UNABLE TO OPEN FILE ---");
   delay(2000);
   goto end8;}
 }

fseek(ptr,0,SEEK_END);
fsize=ftell(ptr);
count=fsize/sizeof(struct pat);



if((!count)&&(k>count))
{
   printf("\n---- NO RECORD AVAILABLE ---");
   delay(3000);
   goto end8;}
 else
{
ofset=(k-1)*sizeof(struct doct);
fseek(ptr,ofset,SEEK_SET);
fread(&p,sizeof(struct doct),1,ptr);
fclose(ptr);

head();
printf("\n\n\t\t\t********  DOCTOR DETAILS *********");
printf("\n-------------------------------------------------------------------------------");
printf("\nDOCTOR NAME  :");
printf("%-20s",p.name);
printf("\tDOCTOR ID     :");
printf("%04d",k);
printf("\nSPECILISATION:");
printf("%-20s",p.type);
printf("\tGENDER(M or F):");
putchar(p.sex);
printf("\nDATE OF BIRTH:");
printf("%02d/%02d/%4d\t  ",p.dobd.dd,p.dobd.mm,p.dobd.yy);
printf("\tBLOOD GROUP   :");
puts(p.bg);
printf("\nSALARY       :%-9lf\t   ",p.salary);
printf("\tCONTACT NO.   :");
puts(p.p_no);
printf("\nADDRESS      :");
printf("H_no:%d %s ",p.adress2.hno,p.adress2.area);
printf("\n\t %s %s",p.adress2.city,p.adress2.state);
printf(" pin=%s",p.adress2.pincode);
printf("\n-------------------------------------------------------------------------------");
getch();
}
end8:
}


void denq()
{
FILE *ptr;
struct doct p;
int fsize,count,h=0;

ptr=fopen("doctor.dat","rb+");
 if(!ptr)
 {
  ptr=fopen("doctor.dat","wb+");
  if(!ptr)
  {
   printf("\n---- UNABLE TO OPEN FILE ---");
   delay(3000);
   goto end9;}
 }

fseek(ptr,0,SEEK_END);
fsize=ftell(ptr);
count=fsize/sizeof(struct doct);



if(!count)
{
   printf("\n---- NO RECORD AVAILABLE ---");
   delay(3000);
   goto end9;}
 else
{
  
head();
printf("\n\t\t\t****DOCTORS ENQUIRY****");
printf("\n----------------------------------------------------------------------------");
printf("\n|  NAME OF DOCTOR     |    SPECIALIST   |    TIMINGS    |   PHONE NO.      |");
printf("\n|---------------------|-----------------|---------------|------------------|");
rewind(ptr); 
 while(h<count)
{
 fread(&p,sizeof(struct doct),1,ptr);
 printf("\n|%02d.%-17s| %-16s| 9:00am-1:30pm | %-17s|",++h,p.name,p.type,p.p_no);
 }
printf("\n----------------------------------------------------------------------------");
}
 
getch();
end9:
}

void makerpt(int k,int w)
{
FILE *ptr,*fptr;
struct pat p1;
struct doct p2;
int fsize,count,ofsetp,ofsetd;
int pid,did;
pid=k;
did=w;

ptr=fopen("patient.dat","rb+");
 if(!ptr)
 {
  ptr=fopen("patient.dat","wb+");
  if(!ptr)
  {
   printf("\n---- UNABLE TO OPEN FILE ---");
   delay(3000);
   goto end0;}
 }
fptr=fopen("doctor.dat","rb+");
 if(!fptr)
 {
  fptr=fopen("doctor.dat","wb+");
  if(!fptr)
  {
   printf("\n---- UNABLE TO OPEN FILE ---");
   delay(3000);
   goto end0;}
 }

fseek(ptr,0,SEEK_END);
fsize=ftell(ptr);
count=fsize/sizeof(struct pat);



if((!count)&&(pid>count))
{
   printf("\n---- NO RECORD AVAILABLE ---");
   delay(3000);
   goto end0;}
 else
{
ofsetp=(pid-1)*sizeof(struct pat);
fseek(ptr,ofsetp,SEEK_SET);
fread(&p1,sizeof(struct pat),1,ptr);
ofsetd=(did-1)*sizeof(struct doct);
fseek(fptr,ofsetd,SEEK_SET);
fread(&p2,sizeof(struct doct),1,fptr);
fclose(fptr);
head();
printf("\n\n\t\t\t********  PATIENT REPORT GENERATION *********");
printf("\n-------------------------------------------------------------------------------");
printf("\nPATIENT NAME :");
printf("%-20s",p1.name);
printf("\tPATIENT ID    :");
printf("%04d",pid);
printf("\nRELATIVE NAME:");
printf("%-20s",p1.fname);
printf("\tGENDER(M or F):");
putchar(p1.sex);
printf("\nDATE OF BIRTH:");
printf("%02d/%02d/%4d\t  ",p1.dobp.dd,p1.dobp.mm,p1.dobp.yy);
printf("\tBLOOD GROUP   :");
puts(p1.bg);
printf("\n-------------------------------------------------------------------------------");
strcpy(p1.doc,p2.name);
printf("\n\nENTER TEST NAME    :");
fflush(stdin);
gets(p1.test);
printf("\nENTER DISEASE NAME :");
fflush(stdin);
gets(p1.disease);
printf("\nENTER REMARKS      :");
fflush(stdin);
gets(p1.remark);

fseek(ptr,ofsetp,SEEK_SET);
fwrite(&p1,sizeof(struct pat),1,ptr);
fclose(ptr);
printf("\n\n\t\t\t*** REPORT MAKING COMPLETED ***");

getch();}
end0:
}


void fpass(char f[21])
{
FILE *fp,*fd;
struct pat p1,p2;
struct doct d1,d2;
int fsizep,fsized,countp,countd,ofset,z,n=0;
char pass1[21];
if(!strcmp(f,pf))
{
fd=fopen(pf,"rb+");
 if(!fd)
 {
  fd=fopen(pf,"wb+");
  if(!fd)
  {
   printf("\n---- UNABLE TO OPEN FILE ---");
   delay(3000);
   goto end10;}
 }

fp=fopen("ppass.dat","rb+");
if(!fp)
{
fp=fopen("ppass.dat","wb+");
if(!fp)
{printf("\n---- UNABLE TO OPEN FILE ---");
delay(3000);
goto end10;}
}
}

if(!strcmp(f,df))
{
fd=fopen(df,"rb+");
 if(!fd)
 {
  fd=fopen(df,"wb+");
  if(!fd)
  {
   printf("\n---- UNABLE TO OPEN FILE ---");
   delay(3000);
   goto end10;}
 }

fp=fopen("dpass.dat","rb+");
if(!fp)
{
fp=fopen("dpass.dat","wb+");
if(!fp)
{printf("\n---- UNABLE TO OPEN FILE ---");
delay(3000);
goto end10;}
}
}

fseek(fd,0,SEEK_END);
fsized=ftell(fd);
fseek(fp,0,SEEK_END);
fsizep=ftell(fp);
if(!strcmp(f,df))
{countd=fsized/sizeof(struct doct);
countp=fsizep/21;}
if(!strcmp(f,pf))
{countd=fsizep/sizeof(struct pat);
countp=fsized/21;}
if(!strcmp(f,pf))
{
head();
printf("\n\n\t\t\t----------------------------");
printf("\n\t\t\t|!!! FORGOTTON PASSWORD !!!|");
printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^");   
printf("\n\nENTER PATIENT NAME :");
fflush(stdin);
gets(p1.name);
printf("\nDATE OF BIRTH      :");
printf("\n\tDAY        :");
fflush(stdin);
scanf("%d",&(p1.dobp.dd));
printf("\n\tMONTH      :");
fflush(stdin);
scanf("%d",&(p1.dobp.mm));
printf("\n\tYEAR       :");
fflush(stdin);
scanf("%d",&(p1.dobp.yy));
rewind(fd);
while(n<countp)
{fread(&p2,sizeof(struct pat),1,fd);
if(!strcmp(p1.name,p2.name)&&(p1.dobp.dd==p2.dobp.dd)&&(p1.dobp.mm==p2.dobp.mm)&&(p1.dobp.yy==p2.dobp.yy))
 {z=ftell(fd)/sizeof(struct pat);
break;}
n++;
}
if(z)
{ofset=(z-1)*21;
 fseek(fp,ofset,SEEK_SET);
 fread(pass1,21,1,fp);
 printf("\nYOUR ID IS = %d",z);
 printf("\nYOUR PASSWORD IS =%s",pass1);
  }
else
{ printf("\n---- NO RECORD MATCHED ---");
   delay(3000);
   goto end10;
   }
}

if(!strcmp(f,df))
{
head();
printf("\n\n\t\t\t----------------------------");
printf("\n\t\t\t|!!! FORGOTTON PASSWORD !!!|");
printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^");   
printf("\n\nENTER DOCTOR  NAME :");
fflush(stdin);
gets(d1.name);
printf("\nDATE OF BIRTH      :");
printf("\n\tDAY        :");
fflush(stdin);
scanf("%d",&(d1.dobd.dd));
printf("\n\tMONTH      :");
fflush(stdin);
scanf("%d",&(d1.dobd.mm));
printf("\n\tYEAR       :");
fflush(stdin);
scanf("%d",&(d1.dobd.yy));
rewind(fd);
while(n<countd)
{fread(&d2,sizeof(struct doct),1,fd);
if(!strcmp(d1.name,d2.name)&&(d1.dobd.dd==d2.dobd.dd)&&(d1.dobd.mm==d2.dobd.mm)&&(d1.dobd.yy==d2.dobd.yy))
 {z=ftell(fd)/sizeof(struct doct);
break;}

n++;
}
if(z)
{ofset=(z-1)*21;
 fseek(fp,ofset,SEEK_SET);
 fread(pass1,21,1,fp);
printf("\nYOUR ID IS :%d",z);
 printf("\nYOUR PASSWORD IS :%s",pass1);
 }
else
{ printf("\n---- NO RECORD MATCHED ---");
   delay(3000);
   goto end10;}
 }

getch();

end10:
}

 




