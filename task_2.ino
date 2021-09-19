//Motor driver 
#define IN1  7
#define IN2  5 
#define ENA   6  

#define IN3  4
#define IN4  2
#define ENB  3

//speed 
#define h 150
#define s 75
#define hh  90

//sensors
#define left_IR   A0
#define right_IR  A1
#define forward_IR   A2

////led 
//#define green   8
//
//#define outputA 6
// #define outputB 7
//
//int counter = 0; 
//int aState;
//int aLastState;  
//int angle = 0;

int r_read , l_read , f_read;
int white=0;

void setup()
{
//  pinMode (outputA,INPUT);
//  pinMode (outputB,INPUT); 
//  Serial.begin (9600);
//  aLastState = digitalRead(outputA);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(left_IR,INPUT);
  pinMode(right_IR,INPUT);
  pinMode(forward_IR,INPUT);
  pinMode(green,OUTPUT);
}

void loop()
{
  if(!Stop)
  {
    l_read = digitalRead(left_IR);
    r_read = digitalRead(right_IR);
    f_read = digitalRead(forward_IR);

    if (l_read == white && r_read==white &&f_read!=white)
    {
      forward();
    }
     if (l_read == white && r_read!=white &&f_read!=white)
    {
      right();
    }
     if (l_read != white && r_read!=white &&f_read!=white)
    {
      forward();
    }
     if (l_read == white && r_read!=white &&f_read!=white)
    {
      right();
    }
     if (l_read != white && r_read!=white &&f_read!=white)
    {
      left();
    }
     if (l_read == white && r_read!=white &&f_read!=white)
    {
      right();
    }
     if (l_read != white && r_read!=white &&f_read!=white)
    {
      right();
    }
     if (l_read != white && r_read==white &&f_read!=white)
    {
      left();
    }
     if (l_read != white && r_read==white &&f_read!=white)
    {
      left();
    }
     if (l_read == white && r_read!=white &&f_read!=white)
    {
      right();
    }
     if (l_read == white && r_read!=white &&f_read!=white)
    {
      right();
    }
     if (l_read == white && r_read==white &&f_read!=white)
    {
      forward();
    } 
     if (l_read != white && r_read!=white &&f_read!=white)
    {
      Stop();
    }       
  }

// aState = digitalRead(outputA); // Reads the "current" state of the outputA
//   // If the previous and the current state of the outputA are different, that means a Pulse has occured
//   if (aState != aLastState){     
//     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
//     if (digitalRead(outputB) != aState) { 
//       counter ++;
//     } else {
//       counter --;
//     }
//     Serial.print("Position: ");
//     Serial.println(counter);
//     Serial.print("Angle: ");
//     angle = (counter*9);
//     if (angle >= 360){
//      angle = 0;
//     }
//     Serial.println(angle);
//   } 
//   aLastState = aState; // Updates the previous state of the outputA with the current state 
//}

/*function*/
void forward()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,hh);
  //analogWrite(ENB,hh);
}

void backward()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,hh);
  analogWrite(ENB,hh);
}

void right()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA,s);
  analogWrite(ENB,h);
}

void left()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,h);
  analogWrite(ENB,s);
}

void Stop()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(ENA,0);
  analogWrite(ENB,0);
}
