#include <iostream>
using namespace std;
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<cstring>
#include <sys/types.h>


int main(int argc, char **argv)
{

int ftt[2];
int at=pipe(ftt);
if(at == -1)
{
cout<<"Error Pipe"<<endl;
}
int ft2[2];
int bt=pipe(ft2);
if(bt == -1)
{
cout<<"Error Pipe2"<<endl;
}

int fd = open(argv[1],O_RDONLY, 0);

//if(fd == -1)
//{
//cout<<"Error File Opening"<<endl;
//}


char a;
int ss=1;
int sizea=0;
while(ss != 0)
{
int count = read(fd,&a,1);
++sizea;
ss=count;
}

int fd1 = open(argv[1],O_RDONLY, 0);
char *newara=new char[sizea];
int count=read(fd1,&*newara,sizea);
newara[count]='\0';

int gt=write(ftt[1],&*newara,sizea);
if(gt==-1)
{
cout<<"Error File Writing"<<endl;
}
int id=fork();

if(id == 0)
{

char *buffer1=new char[sizea];
char *tdata=new char[sizea];
int cot=read(ftt[0],&*buffer1,sizea);
int u=0;
buffer1[cot]='\0';

    for(int s=0; s < cot; ++s)
    {
    if ( (buffer1[s] >= 'a' && buffer1[s] <= 'z') || (buffer1[s] >= 'A' && buffer1[s] <= 'Z') )
    {
    if( (buffer1[s] >= 'a' && buffer1[s] <= 'z')  )
    {
       buffer1[s]=buffer1[s]-32;
    }
    else if( (buffer1[s] >= 'A' && buffer1[s] <= 'Z')  )
    {
       buffer1[s]=buffer1[s]+32;
    }    
    tdata[u] = buffer1[s];
    ++u;
    }
    if(buffer1[s] == ' ')
    {
    tdata[u]=' ';
    ++u;
    }
    }
    tdata[u]='\0';
    
write(ft2[1],&*tdata,u); 
}
if(id > 0)
{
wait(NULL);

char *tem2=new char[sizea];
int tt=read(ft2[0],&*tem2,sizea);
tem2[tt]='\0';
int sts=open(argv[2],O_WRONLY | O_CREAT, S_IRWXU);

int pp=write(sts,&*tem2,strlen(tem2));
close(sts);

if(pp==-1)
{
cout<<"File Wrting";
}
}


}
