
// 0 is BLACK
// 1 is White



#include "define.h"



void setup() {
  pinMode(lineFollowSensor0, INPUT);
  pinMode(lineFollowSensor1, INPUT);
  pinMode(lineFollowSensor2, INPUT);
  pinMode(lineFollowSensor3, INPUT);
  pinMode(lineFollowSensor4, INPUT);
  pinMode(lineFollowSensor5, INPUT);
  pinMode(lineFollowSensor6, INPUT);
  pinMode(lineFollowSensor7, INPUT);
  pinMode(motor_en_left,OUTPUT);
  pinMode(motor_left_for,OUTPUT);
  pinMode(motor_left_back,OUTPUT);
  pinMode(motor_en_right,OUTPUT);
  pinMode(motor_right_for,OUTPUT);
  pinMode(motor_right_back,OUTPUT);

  pinMode(led,OUTPUT);
  
  analogWrite(motor_en_left,255);
  analogWrite(motor_en_right,255);


  Serial.begin(9600);

 
}

void loop() {
 
  readSensors();
  switch(mode)
  {
    case FOLLOWING_LINE:
            run_an_Inch();
            break;
      
    case LEFT_LINE:
            analogWrite(motor_en_left,255);
            analogWrite(motor_en_right,255);
            right_forward();
            left_forward();
            delay(25);
            right_stop();
            left_stop();
            readSensors();
            if(mode==LEFT_LINE){
             
            left_turn();
            pathI+='L';

            }
            break;


     case THRE_LINE:
            run_an_Inch();
            run_an_Inch();
            delay(80);
            readSensors();
            
            if(mode == THRE_LINE/*(sensors[0]== 1 )&&(sensors[1]== 1 )&&(sensors[2]== 1 )&&(sensors[3]== 1 )&&(sensors[4]== 1 )&&(sensors[5]== 1 )&&(sensors[6]== 1 )&&(sensors[7]== 1 )*/){
              mazeEnd();
              
            }
            else{
              analogWrite(motor_en_left,255);
              analogWrite(motor_en_right,255);
              right_backward();
              left_backward();
              delay(200);
              right_stop();
              left_stop();
              left_turn();
              pathI+='L';
            }

            break;


        
    case RIGHT_LINE:
            run_an_Inch();
            run_an_Inch();
            run_an_Inch();
            
            readSensors();
      
            if(mode==NO_LINE){
               analogWrite(motor_en_left,255);
               analogWrite(motor_en_right,255);
               right_backward();
               left_backward();
               delay(400);
               right_stop();
               left_stop();
               right_turn();
               pathI+='R';
            }
            else {
              run_an_Inch();
              run_an_Inch();
              pathI+='S';
            }
            
            break;
     
      
    case NO_LINE:
            U_turn();
            pathI+='U';
            break;
  
            
    case ERR_RIGHT:
            analogWrite(motor_en_left,180);
            analogWrite(motor_en_right,255);
            right_forward();
            left_forward();
            delay(10);
            analogWrite(motor_en_left,255);
            analogWrite(motor_en_right,255);
            right_stop();
            left_stop();
            break;
            
    case ERR_LEFT:
            analogWrite(motor_en_left,255);
            analogWrite(motor_en_right,180);
            right_forward();
            left_forward();
            delay(10);
            analogWrite(motor_en_left,255);
            analogWrite(motor_en_right,255);
            right_stop();
            left_stop();
            break;


    case ERR_R_RIGHT:
            analogWrite(motor_en_left,255);
            right_stop();
            left_backward();
            delay(200);
            left_stop();
            run_an_Inch();
            run_an_Inch();
            break;
            
    case ERR_R_LEFT:
            analogWrite(motor_en_right,255);
            left_stop();
            right_backward();
            delay(200);
            right_stop();
            run_an_Inch();
            run_an_Inch();
            break;

            
     default:
            run_an_Inch();
            break;
           
  }

}


/*

           analogWrite(motor_en_left,160);
           analogWrite(motor_en_right,255);
           right_backward();
           left_backward();
           delay(500);
           right_forward();
           left_stop();
           delay(300);
           right_forward();
           left_forward();
           delay(400);
           right_stop();
           left_stop();


*/
