#define receiverpin 2
#define roleta3dol 23 
#define roleta3gora 25 
#define roleta4dol 27 
#define roleta4gora 29 
#define roleta2dol 31 
#define roleta2gora 33 
#define roleta1dol 35 
#define roleta1gora 37 
#define swiatlo1 39
#define swiatlo2 41
#include <IRremote.h>
#include <Timers.h>
#include <Wire.h>
#include <TimeLib.h>
IRrecv irrecv(receiverpin); 
decode_results results;

Timer tim1;
Timer rol1;
Timer rol2;
Timer rol3;
Timer rol4;
Timer trybnocny, trybwieczorny, trybwietrzenia;
bool roleta1= false, roleta2= false, roleta3= false,rolety= false , roleta4= false, tnocny = false, twieczorny = false, twietrzenia = false;
long int odbiorTV;
int odbiorBT;
 
void setup()
{
   pinMode(roleta1dol, OUTPUT);
   pinMode(roleta2dol, OUTPUT);
   pinMode(roleta3dol, OUTPUT);
   pinMode(roleta4dol, OUTPUT);
   pinMode(roleta1gora, OUTPUT);
   pinMode(roleta2gora, OUTPUT);
   pinMode(roleta3gora, OUTPUT);
   pinMode(roleta4gora, OUTPUT);
   pinMode(swiatlo1, OUTPUT);
   pinMode(swiatlo2, OUTPUT);
   //Serial.begin(9600); 
   //Serial1.begin(9600);
   irrecv.enableIRIn(); // uruchamia odbiornik podczerwieni
   tim1.begin(100);
   rol1.begin(100);
   rol2.begin(100);
   rol3.begin(100);
   rol4.begin(100);
   trybwieczorny.begin(100);
   trybnocny.begin(100); 
   trybwietrzenia.begin(100);
   delay(100);
}
 
void loop()
{
   //odbiornikTV
   if (irrecv.decode(&results)&&tim1.available()) // sprawdza, czy otrzymano sygnał IR
   {
      odbiorTV = results.value;
      switch (odbiorTV)
      {
        case 16753245:
          if(roleta1==false)
          {
            digitalWrite(roleta1gora, HIGH);
            rol1.begin(28000);
            roleta1= true;
          }
          else
          {
            digitalWrite(roleta1gora, LOW);
            digitalWrite(roleta1dol, LOW);
            roleta1= false;
          }
          break;
        case 16720605:
          if(roleta1==false)
          {
            digitalWrite(roleta1dol, HIGH);
            rol1.begin(28000);
            roleta1= true;
          }
          else
          {
            digitalWrite(roleta1gora, LOW);
            digitalWrite(roleta1dol, LOW);
            roleta1= false;
          }
          break;
        case 16736925:
          if(roleta2==false)
          {
            digitalWrite(roleta2gora, HIGH);
            rol2.begin(28000);
            roleta2= true;
          }
          else
          {
            digitalWrite(roleta2gora, LOW);
            digitalWrite(roleta2dol, LOW);
            roleta2= false;
          }
          break;
        case 16712445:
          if(roleta2==false)
          {
            digitalWrite(roleta2dol, HIGH);
            rol2.begin(28000);
            roleta2= true;
          }
          else
          {
            digitalWrite(roleta2gora, LOW);
            digitalWrite(roleta2dol, LOW);
            roleta2= false;
          }
          break;
        case 16769565:
          if(roleta3==false)
          {
            digitalWrite(roleta3gora, HIGH);
            rol3.begin(28000);
            roleta3= true;
          }
          else
          {
            digitalWrite(roleta3gora, LOW);
            digitalWrite(roleta3dol, LOW);
            roleta3= false;
          }
          break;
        case 16761405:
          if(roleta3==false)
          {
            digitalWrite(roleta3dol, HIGH);
            rol3.begin(28000);
            roleta3= true;
          }
          else
          {
            digitalWrite(roleta3gora, LOW);
            digitalWrite(roleta3dol, LOW);
            roleta3= false;
          }
          break;
        case 16769055:
          if(roleta4==false)
          {
            digitalWrite(roleta4gora, HIGH);
            rol4.begin(28000);
            roleta4= true;
          }
          else
          {
            digitalWrite(roleta4gora, LOW);
            digitalWrite(roleta4dol, LOW);
            roleta4= false;
          }
          break;
        case 16738455:
          if(roleta4==false)
          {
            digitalWrite(roleta4dol, HIGH);
            rol4.begin(28000);
            roleta4= true;
          }
          else
          {
            digitalWrite(roleta4gora, LOW);
            digitalWrite(roleta4dol, LOW);
            roleta4= false;
          }
          break;
        case 16754775:
          digitalWrite(swiatlo1, HIGH);
          break;
        case 16750695:
          digitalWrite(swiatlo1, LOW);
          break;
        case 16748655:
          digitalWrite(swiatlo2, HIGH);
          break;
        case 16756815:
          digitalWrite(swiatlo2, LOW);
          break;
        case 16730805:
          if(rolety==false)
          {
            digitalWrite(roleta1dol, HIGH);
            digitalWrite(roleta2dol, HIGH);
            digitalWrite(roleta3dol, HIGH);
            digitalWrite(roleta4dol, HIGH);
            rol1.begin(28000);
            rol2.begin(28000);
            rol3.begin(28000);
            rol4.begin(28000);
            rolety= true;
          }
          else
          {
            digitalWrite(roleta1dol, LOW);
            digitalWrite(roleta2dol, LOW);
            digitalWrite(roleta3dol, LOW);
            digitalWrite(roleta4dol, LOW);
            digitalWrite(roleta1gora, LOW);
            digitalWrite(roleta2gora, LOW);
            digitalWrite(roleta3gora, LOW);
            digitalWrite(roleta4gora, LOW);
            rolety= false;
          }
          break;
        case 16718055:
          if(rolety==false)
          {
            digitalWrite(roleta1gora, HIGH);
            digitalWrite(roleta2gora, HIGH);
            digitalWrite(roleta3gora, HIGH);
            digitalWrite(roleta4gora, HIGH);
            rol1.begin(28000);
            rol2.begin(28000);
            rol3.begin(28000);
            rol4.begin(28000);
            rolety= true;
          }
          else
          {
            digitalWrite(roleta1dol, LOW);
            digitalWrite(roleta2dol, LOW);
            digitalWrite(roleta3dol, LOW);
            digitalWrite(roleta4dol, LOW);
            digitalWrite(roleta1gora, LOW);
            digitalWrite(roleta2gora, LOW);
            digitalWrite(roleta3gora, LOW);
            digitalWrite(roleta4gora, LOW);
            rolety= false;
          }
          break;
        
        case 16726215:
            if((tnocny == false)&&(twieczorny == false)&&(twietrzenia==false))
            {
              tnocny= true;
              digitalWrite(roleta1dol, HIGH);
              digitalWrite(roleta2dol, HIGH);
              digitalWrite(roleta3dol, HIGH);
              digitalWrite(roleta4dol, HIGH);
              trybnocny.begin(28000);
            }
            else
            {
              digitalWrite(roleta1dol, LOW);
              digitalWrite(roleta2dol, LOW);
              digitalWrite(roleta3dol, LOW);
              digitalWrite(roleta4dol, LOW);
              digitalWrite(roleta1gora, LOW);
              digitalWrite(roleta2gora, LOW);
              digitalWrite(roleta3gora, LOW);
              digitalWrite(roleta4gora, LOW);
              twieczorny = false;
              twietrzenia = false;
              tnocny = false;
            }
            break;

          case 16716015:
            if((tnocny == false)&&(twieczorny == false)&&(twietrzenia==false))
            {
              twieczorny= true;
              digitalWrite(roleta1gora, HIGH);
              digitalWrite(roleta2gora, HIGH);
              digitalWrite(roleta3gora, HIGH);
              digitalWrite(roleta4gora, HIGH);
              trybwieczorny.begin(28000);
            }
            else
            {
              digitalWrite(roleta1dol, LOW);
              digitalWrite(roleta2dol, LOW);
              digitalWrite(roleta3dol, LOW);
              digitalWrite(roleta4dol, LOW);
              digitalWrite(roleta1gora, LOW);
              digitalWrite(roleta2gora, LOW);
              digitalWrite(roleta3gora, LOW);
              digitalWrite(roleta4gora, LOW);
              twieczorny = false;
              twietrzenia = false;
              tnocny = false;
            }
            break;
          case 16734885:
            if((tnocny == false)&&(twieczorny == false)&&(twietrzenia==false))
            {
              twietrzenia= true;
              digitalWrite(roleta1gora, HIGH);
              digitalWrite(roleta2gora, HIGH);
              digitalWrite(roleta3gora, HIGH);
              digitalWrite(roleta4gora, HIGH);
              trybwietrzenia.begin(28000);
            }
            else
            {
              digitalWrite(roleta1dol, LOW);
              digitalWrite(roleta2dol, LOW);
              digitalWrite(roleta3dol, LOW);
              digitalWrite(roleta4dol, LOW);
              digitalWrite(roleta1gora, LOW);
              digitalWrite(roleta2gora, LOW);
              digitalWrite(roleta3gora, LOW);
              digitalWrite(roleta4gora, LOW);
              twieczorny = false;
              twietrzenia = false;
              tnocny = false;
            }
            break;
        default:
          break;
          
      }
      irrecv.resume(); // odbiera następną wartość
      tim1.begin(100);
   }
    //odbiornikBT
   odbiorBT = Serial1.read();
      switch (odbiorBT)
      {
        case 1:
          if(roleta1==false)
          {
            digitalWrite(roleta1gora, HIGH);
            rol1.begin(28000);
            roleta1= true;
          }
          else
          {
            digitalWrite(roleta1gora, LOW);
            digitalWrite(roleta1dol, LOW);
            roleta1= false;
          }
          break;
        case 5:
          if(roleta1==false)
          {
            digitalWrite(roleta1dol, HIGH);
            rol1.begin(28000);
            roleta1= true;
          }
          else
          {
            digitalWrite(roleta1gora, LOW);
            digitalWrite(roleta1dol, LOW);
            roleta1= false;
          }
          break;
        case 2:
          if(roleta2==false)
          {
            digitalWrite(roleta2gora, HIGH);
            rol2.begin(28000);
            roleta2= true;
          }
          else
          {
            digitalWrite(roleta2gora, LOW);
            digitalWrite(roleta2dol, LOW);
            roleta2= false;
          }
          break;
        case 6:
          if(roleta2==false)
          {
            digitalWrite(roleta2dol, HIGH);
            rol2.begin(28000);
            roleta2= true;
          }
          else
          {
            digitalWrite(roleta2gora, LOW);
            digitalWrite(roleta2dol, LOW);
            roleta2= false;
          }
          break;
        case 3:
          if(roleta3==false)
          {
            digitalWrite(roleta3gora, HIGH);
            rol3.begin(28000);
            roleta3= true;
          }
          else
          {
            digitalWrite(roleta3gora, LOW);
            digitalWrite(roleta3dol, LOW);
            roleta3= false;
          }
          break;
        case 7:
          if(roleta3==false)
          {
            digitalWrite(roleta3dol, HIGH);
            rol3.begin(28000);
            roleta3= true;
          }
          else
          {
            digitalWrite(roleta3gora, LOW);
            digitalWrite(roleta3dol, LOW);
            roleta3= false;
          }
          break;
        case 4:
          if(roleta4==false)
          {
            digitalWrite(roleta4gora, HIGH);
            rol4.begin(28000);
            roleta4= true;
          }
          else
          {
            digitalWrite(roleta4gora, LOW);
            digitalWrite(roleta4dol, LOW);
            roleta4= false;
          }
          break;
        case 8:
          if(roleta4==false)
          {
            digitalWrite(roleta4dol, HIGH);
            rol4.begin(28000);
            roleta4= true;
          }
          else
          {
            digitalWrite(roleta4gora, LOW);
            digitalWrite(roleta4dol, LOW);
            roleta4= false;
          }
          break;
        case 9:
          digitalWrite(swiatlo1, HIGH);
          break;
        case 10:
          digitalWrite(swiatlo1, LOW);
          break;
        case 11:
          digitalWrite(swiatlo2, HIGH);
          break;
        case 12:
          digitalWrite(swiatlo2, LOW);
          break;
        case 13:
          if(rolety==false)
          {
            digitalWrite(roleta1gora, HIGH);
            digitalWrite(roleta2gora, HIGH);
            digitalWrite(roleta3gora, HIGH);
            digitalWrite(roleta4gora, HIGH);
            rol1.begin(28000);
            rol2.begin(28000);
            rol3.begin(28000);
            rol4.begin(28000);
            rolety= true;
          }
          else
          {
            digitalWrite(roleta1dol, LOW);
            digitalWrite(roleta2dol, LOW);
            digitalWrite(roleta3dol, LOW);
            digitalWrite(roleta4dol, LOW);
            digitalWrite(roleta1gora, LOW);
            digitalWrite(roleta2gora, LOW);
            digitalWrite(roleta3gora, LOW);
            digitalWrite(roleta4gora, LOW);
            rolety= false;
          }
          break;
        case 14:
          if(rolety==false)
          {
            digitalWrite(roleta1dol, HIGH);
            digitalWrite(roleta2dol, HIGH);
            digitalWrite(roleta3dol, HIGH);
            digitalWrite(roleta4dol, HIGH);
            rol1.begin(28000);
            rol2.begin(28000);
            rol3.begin(28000);
            rol4.begin(28000);
            rolety= true;
          }
          else
          {
            digitalWrite(roleta1dol, LOW);
            digitalWrite(roleta2dol, LOW);
            digitalWrite(roleta3dol, LOW);
            digitalWrite(roleta4dol, LOW);
            digitalWrite(roleta1gora, LOW);
            digitalWrite(roleta2gora, LOW);
            digitalWrite(roleta3gora, LOW);
            digitalWrite(roleta4gora, LOW);
            rolety= false;
          }
          break;
        case 15:
             if((tnocny == false)&&(twieczorny == false)&&(twietrzenia==false))
            {
              tnocny= true;
              digitalWrite(roleta1dol, HIGH);
              digitalWrite(roleta2dol, HIGH);
              digitalWrite(roleta3dol, HIGH);
              digitalWrite(roleta4dol, HIGH);
              trybnocny.begin(28000);
            }
            else
            {
              digitalWrite(roleta1dol, LOW);
              digitalWrite(roleta2dol, LOW);
              digitalWrite(roleta3dol, LOW);
              digitalWrite(roleta4dol, LOW);
              digitalWrite(roleta1gora, LOW);
              digitalWrite(roleta2gora, LOW);
              digitalWrite(roleta3gora, LOW);
              digitalWrite(roleta4gora, LOW);
              twieczorny = twietrzenia = tnocny = false;
            }
            break;

          case 16:
            if((tnocny == false)&&(twieczorny == false)&&(twietrzenia==false))
            {
              twieczorny= true;
              digitalWrite(roleta1gora, HIGH);
              digitalWrite(roleta2gora, HIGH);
              digitalWrite(roleta3gora, HIGH);
              digitalWrite(roleta4gora, HIGH);
              trybwieczorny.begin(28000);
            }
            else
            {
              digitalWrite(roleta1dol, LOW);
              digitalWrite(roleta2dol, LOW);
              digitalWrite(roleta3dol, LOW);
              digitalWrite(roleta4dol, LOW);
              digitalWrite(roleta1gora, LOW);
              digitalWrite(roleta2gora, LOW);
              digitalWrite(roleta3gora, LOW);
              digitalWrite(roleta4gora, LOW);
              twieczorny = twietrzenia = tnocny = false;
            }
            break;
          case 17:
            if((tnocny == false)&&(twieczorny == false)&&(twietrzenia==false))
            {
              twietrzenia= true;
              digitalWrite(roleta1gora, HIGH);
              digitalWrite(roleta2gora, HIGH);
              digitalWrite(roleta3gora, HIGH);
              digitalWrite(roleta4gora, HIGH);
              trybwietrzenia.begin(28000);
            }
            else
            {
              digitalWrite(roleta1dol, LOW);
              digitalWrite(roleta2dol, LOW);
              digitalWrite(roleta3dol, LOW);
              digitalWrite(roleta4dol, LOW);
              digitalWrite(roleta1gora, LOW);
              digitalWrite(roleta2gora, LOW);
              digitalWrite(roleta3gora, LOW);
              digitalWrite(roleta4gora, LOW);
              twieczorny = twietrzenia = tnocny = false;
            }
            break;
        default:
          break;
          
      }
      
   //reset
   if((tnocny == false)&&(twieczorny == false)&&(twietrzenia == false))
   {
     if(rol1.available())
     {
       digitalWrite(roleta1gora, LOW);
       digitalWrite(roleta1dol, LOW);
     }
     if(rol2.available())
     {
       digitalWrite(roleta2gora, LOW);
       digitalWrite(roleta2dol, LOW);
     }
     if(rol3.available())
     {
       digitalWrite(roleta3gora, LOW);
       digitalWrite(roleta3dol, LOW);
     }
     if(rol4.available())
     {
       digitalWrite(roleta4gora, LOW);
       digitalWrite(roleta4dol, LOW);
     }
   }
   if(tnocny == true)
   {
    if(trybnocny.available())
    {
      digitalWrite(roleta1dol, LOW);
      digitalWrite(roleta2dol, LOW);
      digitalWrite(roleta3dol, LOW);
      digitalWrite(roleta4dol, LOW);
      digitalWrite(roleta1gora, HIGH);
      digitalWrite(roleta2gora, HIGH);
      digitalWrite(roleta3gora, HIGH);
      digitalWrite(roleta4gora, HIGH);

      rol4.begin(1000);
      rol3.begin(1000);
      rol2.begin(1000);
      rol1.begin(1000);
      
     
      tnocny = false;
    }
   }
   if(twieczorny == true)
   {
    if(trybwieczorny.available())
    {
      digitalWrite(roleta1gora, LOW);
      digitalWrite(roleta2gora, LOW);
      digitalWrite(roleta3gora, LOW);
      digitalWrite(roleta4gora, LOW);
      digitalWrite(roleta1dol, HIGH);
      digitalWrite(roleta2dol, HIGH);
      digitalWrite(roleta3dol, HIGH);
      digitalWrite(roleta4dol, HIGH);
      /*rol3.begin(17000);
      rol2.begin(18000);
      rol1.begin(9000);
      rol4.begin(18000);*/

      rol4.begin(9000);
      rol3.begin(18000);
      rol2.begin(18000);
      rol1.begin(18000);     
      
      twieczorny = false;
    }
   }
  if(twietrzenia == true)
   {
    if(trybwietrzenia.available())
    {
      digitalWrite(roleta1gora, LOW);
      digitalWrite(roleta2gora, LOW);
      digitalWrite(roleta3gora, LOW);
      digitalWrite(roleta4gora, LOW);
      digitalWrite(roleta1dol, HIGH);
      digitalWrite(roleta2dol, HIGH);
      digitalWrite(roleta3dol, HIGH);
      digitalWrite(roleta4dol, HIGH);
      /*rol3.begin(17000);
      rol2.begin(4000);
      rol4.begin(4000);
      rol1.begin(4000);*/

      rol4.begin(4000);
      rol3.begin(4000);
      rol2.begin(17000);
      rol1.begin(4000);

      twietrzenia = false;
    }
   }
}
