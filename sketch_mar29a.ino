#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

#define bjp 2
#define inc 3 
#define aap 4
#define oth 5
#define rst 6

int b=0,i=0,a=0,o=0;
void setup(){
  
  lcd.begin(16,2);
  lcd.write("WELCOME VOTERS");
  lcd.setCursor(7,2);
  lcd.write("TO");
  delay(5000);
  lcd.clear();
  lcd.write("ELECTRONIC");
  lcd.setCursor(0,1);
  lcd.write("VOTING MACHINE");
  delay(5000);
  lcd.clear();
  lcd.write("MADE BY : Arati,");
  lcd.setCursor(0,1);
  lcd.write("Shreya,Nirmayee");
  delay(5000);
  lcd.clear();
  
  pinMode(bjp,INPUT);
  pinMode(inc,INPUT);
  pinMode(aap,INPUT);
  pinMode(oth,INPUT);
  pinMode(rst,INPUT);
 
  digitalWrite(bjp,HIGH); 
  digitalWrite(inc,HIGH);  
  digitalWrite(aap,HIGH);  
  digitalWrite(oth,HIGH);  
  digitalWrite(rst,HIGH);
lcd.write("Press Button");
lcd.setCursor(0,1);
lcd.write("To Vote");
delay(2000);
}

void loop() {
  
  lcd.clear();
  lcd.print("1-BJP 2-INC");
  lcd.setCursor(0,2);
  lcd.print("3-AAP 4-OTH");
  delay(2000);
  if(digitalRead(bjp)==LOW)
  {
    b=b++;
    while(digitalRead(bjp)==LOW);
  }
  else if(digitalRead(inc)==LOW)
  {
    i=i++;
    while(digitalRead(inc)==LOW);
  }
    else if(digitalRead(aap)==LOW)
  {
    a=a++;
    while(digitalRead(aap)==LOW);
  }
    else if(digitalRead(oth)==LOW)
  {
    o=o++;
    while(digitalRead(oth)==LOW);
  }
    else if(digitalRead(rst)==LOW)
  {{
    while(digitalRead(rst)==LOW);
  lcd.clear();
  lcd.write("CALCULATING");
  lcd.setCursor(0,2);
  lcd.write("RESULT");
  delay(2000);
  lcd.clear();
  lcd.write("BJP:");
  lcd.print(b);
  lcd.setCursor(8,0);
  lcd.write("INC:");
  lcd.print(i);
  lcd.setCursor(0,2);
  lcd.write("AAP:");
  lcd.print(a);
  lcd.setCursor(8,2);
  lcd.write("OTH:");
  lcd.print(o);
delay(5000);}
  {
   int vote=b+i+a+o;
     if(vote)
     {
      if((b > i && b > a && b > o))
      {
       lcd.clear();
       lcd.print("BJP Wins");
       delay(2000);
       lcd.clear();
      }
      else if((i > b && i > a && i > o))
      {
       lcd.clear();
       lcd.print("INC Wins");
       delay(2000);
       lcd.clear();
      }
      else if((a > b && a > i && a > o))
      {
       lcd.clear();
       lcd.print("AAP Wins");
       delay(2000);
       lcd.clear();
      }
      else if(o > b && o > i && o > a)
     {
       lcd.setCursor(0,0);
       lcd.clear();
       lcd.print("OTH Wins");
       delay(2000);
       lcd.clear();
     }
     
     else
     {
       lcd.clear();
       lcd.print("   Tie Up Or   ");
       lcd.setCursor(0,1);
       lcd.print("   No Result   ");
       delay(1000);
       lcd.clear();
     }
     
    }      
     else 
     {
       lcd.clear();
       lcd.print("No Voting....");
       delay(1000);
       lcd.clear();
     }
  b=0;
  i=0;
  a=0;
  o=0;
  
  delay(2000);
  }
  }}
    
