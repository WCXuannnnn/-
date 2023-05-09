#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <cmath>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    setFixedSize(358,326);
    setWindowTitle("计算器");
    ui->setupUi(this);
    str="";
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_5_clicked()
{
    str+="1";
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_6_clicked()
{
    str+="2";
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_7_clicked()
{
    str+="3";
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_8_clicked()
{
    str+="4";
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_9_clicked()
{
    str+="5";
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_10_clicked()
{
    str+="6";
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_11_clicked()
{
    str+="7";
    ui->textEdit->setText(QString::fromStdString(str));
}


void Widget::on_pushButton_12_clicked()
{
    str+="8";
    ui->textEdit->setText(QString::fromStdString(str));
}
void Widget::on_pushButton_13_clicked()
{
    str+="9";
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_14_clicked()
{
    str+="0";
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_18_clicked()
{
    str+="&";
    ui->textEdit->setText(QString::fromStdString(str));
}
void Widget::on_pushButton_19_clicked()
{
    str+="|";
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_17_clicked()
{
    str+="!";
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_20_clicked()
{
    str+="(";
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_21_clicked()
{
    str+=")";
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_23_clicked()
{
    str+="#";
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_4_clicked()
{
    str+="/";
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_3_clicked()
{
    str+="*";
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_clicked()
{
    str+="+";
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_2_clicked()
{
    str+="-";
    ui->textEdit->setText(QString::fromStdString(str));
}

double num(string str,int &j){
    double sum=0;
       double sum2=0;
       do{
           if(str[j]=='.'){
               j++;
               int i=1;
               do{
               sum2+=(str[j]-'0')*pow(10,-i);
                   i++;
               j++;
               }while(str[j]>='0'&&str[j]<='9');
               return sum+sum2;
           }
       sum*=10;
       sum+=(str[j]-'0');
       j++;
       }while((str[j]>='0'&&str[j]<='9')||str[j]=='.');
       return sum;
}
int cnt=0;
int cnt1=0;
void Widget::on_pushButton_15_clicked()
{
    int i=str.length();
       stack<double> S1;
       stack<char> S2;
       int j=0;
       S2.push(str[j++]);
       for(;j<i;){
           if((str[j]>='0'&&str[j]<='9')||str[j]=='.'){
               S1.push(num(str,j));
           }else{
               if(str[j]=='+'||str[j]=='-'){
                 while(1){
                 char x;
                 x=S2.top();
                 if(x=='#'||x=='('){
                   S2.push(str[j]);
                   break;
                 }else if(x=='!'){
                     double a;
                     a=S1.top();
                     S1.pop();
                     if(a!=0){
                         S1.push(0);
                         S2.pop();
                     }else{
                         S1.push(1);
                         S2.pop();
                     }
                 }else{
                     double a,b;
                     a=S1.top();
                     S1.pop();
                     b=S1.top();
                     S1.pop();
                     if(x=='+'){S1.push(a+b);S2.pop();}
                     if(x=='-'){S1.push(b-a);S2.pop();}
                     if(x=='*'){S1.push(a*b);S2.pop();}
                     if(x=='/'){S1.push(b/a);S2.pop();}
                     if(x=='&'){
                         if(a*b!=0)S1.push(1);
                         if(a*b==0)S1.push(0);
                         S2.pop();
                     }
                     if(x=='|'){
                         if(a==0&&b==0)S1.push(0);
                         else S1.push(1);
                         S2.pop();
                     }
                  }
              }
           }
               if(str[j]=='&'){
                   ++cnt;
                   if(cnt%2==0){
                       j++;
                       continue;
                   }
                   while(1){
                       char x;
                       x=S2.top();
                       if(x=='#'||x=='('||x=='+'||x=='-'){
                         S2.push(str[j]);
                         break;
                       }else if(x=='!'){
                           double a;
                           a=S1.top();
                           S1.pop();
                           if(a!=0){
                               S1.push(0);
                               S2.pop();
                           }else{
                               S1.push(1);
                               S2.pop();
                           }
                       }else{
                         double a,b;
                         a=S1.top();
                         S1.pop();
                         b=S1.top();
                         S1.pop();
                           if(x=='*'){S1.push(a*b);S2.pop();}
                           if(x=='/'){S1.push(b/a);S2.pop();}
                           if(x=='&'){
                               if(a*b!=0)S1.push(1);
                               if(a*b==0)S1.push(0);
                               S2.pop();
                           }
                           if(x=='|'){
                               if(a==0&&b==0)S1.push(0);
                               else S1.push(1);
                               S2.pop();
                           }
                        }
                    }
               }
               if(str[j]=='|'){
                   ++cnt1;
                   if(cnt1%2==0){
                       j++;
                       continue;
                   }
                   while(1){
                       char x;
                       x=S2.top();
                       if(x=='#'||x=='('||x=='+'||x=='-'){
                         S2.push(str[j]);
                         break;
                       }else if(x=='!'){
                           double a;
                           a=S1.top();
                           S1.pop();
                           if(a!=0){
                               S1.push(0);
                               S2.pop();
                           }else{
                               S1.push(1);
                               S2.pop();
                           }
                       }else{
                         double a,b;
                         a=S1.top();
                         S1.pop();
                         b=S1.top();
                         S1.pop();
                           if(x=='*'){S1.push(a*b);S2.pop();}
                           if(x=='/'){S1.push(b/a);S2.pop();}
                           if(x=='&'){
                               if(a*b!=0)S1.push(1);
                               if(a*b==0)S1.push(0);
                               S2.pop();
                           }
                           if(x=='|'){
                               if(a==0&&b==0)S1.push(0);
                               else S1.push(1);
                               S2.pop();
                           }
                        }
                    }
               }
           if(str[j]=='*'||str[j]=='/'||str[j]=='!'){
             while(1){
                 char x;
                 x=S2.top();
                 if(x=='#'||x=='('||x=='+'||x=='-'){
                   S2.push(str[j]);
                   break;
                 }else if(x=='!'){
                     double a;
                     a=S1.top();
                     S1.pop();
                     if(a!=0){
                         S1.push(0);
                         S2.pop();
                     }else{
                         S1.push(1);
                         S2.pop();
                     }
                 }else{
                   double a,b;
                   a=S1.top();
                   S1.pop();
                   b=S1.top();
                   S1.pop();
                     if(x=='*'){S1.push(a*b);S2.pop();}
                     if(x=='/'){S1.push(b/a);S2.pop();}
                     if(x=='&'){
                         if(a*b!=0)S1.push(1);
                                             if(a*b==0)S1.push(0);
                                             S2.pop();
                     }
                     if(x=='|'){
                         if(a*b!=0)S1.push(1);
                                             if(a*b==0)S1.push(0);
                                             S2.pop();
                     }
                  }
              }
           }
           if(str[j]=='#'){
               while(1){
                   char x;
                   x=S2.top();
                 if(x=='#'){
                     double result;
                     result=S1.top();
                     S1.pop();
                     QString temp=QString::number(result);
                     ui->textEdit_2->setText(temp);
                     break;
                 }else if(x=='!'){
                     double a;
                     a=S1.top();
                     if(a!=0){
                         a=0;
                         S1.push(a);
                         S2.pop();
                     }else{
                         a=1;
                         S1.push(a);
                         S2.pop();
                     }
                 }else{
                   double a,b;
                   a=S1.top();
                   S1.pop();
                   b=S1.top();
                   S1.pop();
                   if(x=='+'){S1.push(a+b);S2.pop();}
                   if(x=='-'){S1.push(b-a);S2.pop();}
                   if(x=='*'){S1.push(a*b);S2.pop();}
                   if(x=='/'){S1.push(b/a);S2.pop();}
                   if(x=='&'){
                         if(a*b!=0)S1.push(1);
                         if(a*b==0)S1.push(0);
                         S2.pop();
                     }
                   if(x=='|'){
                         if(a==0&&b==0)S1.push(0);
                         else S1.push(1);
                         S2.pop();
                     }
               }
           }
       }
       if(str[j]=='('){
           S2.push(str[j]);
       }
       if(str[j]==')'){
         while(1){
             char x;
             x=S2.top();
             if(x=='('){
               S2.pop();
               break;
             }else if(x=='!'){
                 int a;
                 a=S1.top();
                 if(a!=0){
                     a=0;
                     S1.push(a);
                     S2.pop();
                 }else{
                     a=1;
                     S1.push(a);
                     S2.pop();
                 }
             }else{
               double a,b;
               a=S1.top();
               S1.pop();
               b=S1.top( );
               S1.pop();
                 if(x=='+'){S1.push(a+b);S2.pop();}
                 if(x=='-'){S1.push(b-a);S2.pop();}
                 if(x=='*'){S1.push(a*b);S2.pop();}
                 if(x=='/'){S1.push(b/a);S2.pop();}
                 if(x=='&'){
                     if(a*b!=0)S1.push(1);
                     if(a*b==0)S1.push(0);
                     S2.pop();
                 }
                 if(x=='|'){
                     if(a==0&&b==0)S1.push(0);
                     else S1.push(1);
                     S2.pop();
                 }
              }
          }
       }
       j++;
   }
   }
}


void Widget::on_pushButton_22_clicked()
{
    str.clear();
    ui->textEdit_2->clear();
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_16_clicked()
{
    str+=".";
    ui->textEdit->setText(QString::fromStdString(str));
}

void Widget::on_pushButton_24_clicked()
{
    str.erase(str.length()-1);
    ui->textEdit->setText(QString::fromStdString(str));
}

