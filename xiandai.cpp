#include <iostream>
#include<math.h>
using namespace std;
class Matrix
{
private:
double data[10][20];
int size;
static int times;
public:
void qiuNi();
void setSize();
void show();
void chuShi();
};
int Matrix ::times=1;
void Matrix::setSize()
{
int n;
cout<<"请问你要输入几阶矩阵:";
cin>>n;
size=n;
}
void Matrix::show()
{
cout<<"("<<times<<")"<<endl;
times++;
int i,j;
for(i=0;i<size;i++)
{
for(j=0;j<2*size;j++)
{
cout.width(10);
cout.flags (ios::right);
cout<<data[i][j]<<" ";
}
cout<<endl;
}
cout<<"***********************************************"<<endl;
cout<<endl;
}
void Matrix::chuShi()
{
int i,j;
data[10][20]={0};
for(i=0;i<size;i++)
{ 
cout<<"请输入"<<i+1<<"行的元素:";
for(j=0;j<2*size;j++)
{
if(j<size)
{
cin>>data[i][j];
}
else if(j==i+size)
data[i][j]=1.0;
else
data[i][j]=0.0;
}
}
cout<<"开始求逆:"<<endl;
show();
}
void Matrix::qiuNi()
{
int i,j,k;
int maxI=0;
for(i=1;i<size;i++)
{
if(fabs(data[maxI][0])<fabs(data[i][0]))
maxI=i;
}
if(maxI!=0)
{
double temp;
for(j=0;j<2*size;j++)
{
temp=data[0][j];
data[0][j]=data[maxI][j];
data[maxI][j]=temp;
}
}
double temp2;
for(i=0;i<size;i++)
{
if(data[i][i]!=0)
temp2=1.0/data[i][i];
else
{
cout<<"此矩阵无逆!"<<endl;
return ;
}
for(j=0;j<2*size;j++)
    data[i][j]*=temp2;
for(j=0;j<size;j++)
{
if(j!=i)
{
double temp3=data[j][i];
for(k=0;k<2*size;k++)
data[j][k]-=temp3*data[i][k];
}
}
}
show();
}
int main()
{
Matrix a;
a.setSize();
a.chuShi();
a.qiuNi();
return 0;
}

