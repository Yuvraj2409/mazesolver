void readSensors()
{
 
  sensors[0] = digitalRead(lineFollowSensor0);
  sensors[1] = digitalRead(lineFollowSensor1);
  sensors[2] = digitalRead(lineFollowSensor2);
  sensors[3] = digitalRead(lineFollowSensor3);
  sensors[4] = digitalRead(lineFollowSensor4);
  sensors[5] = digitalRead(lineFollowSensor5); if(sensors[5]>2) {flag=1;}
  sensors[6] = digitalRead(lineFollowSensor6); if(sensors[6]>2) {flag=1;}
  sensors[7] = digitalRead(lineFollowSensor7); if(sensors[7]>2) {flag=1;}


 if(flag==0){

  if     ((sensors[0]== 0 )&&(sensors[1]== 0 )&&(sensors[2]== 0 )&&(sensors[3]== 1 )&&(sensors[4]== 1 )&&(sensors[5]== 0 )&&(sensors[6]== 0 )&&(sensors[7]== 0 ))  {mode = FOLLOWING_LINE;}
  else if((sensors[0]== 0 )&&(sensors[1]== 0 )&&(sensors[2]== 1 )&&(sensors[3]== 1 )&&(sensors[4]== 1 )&&(sensors[5]== 0 )&&(sensors[6]== 0 )&&(sensors[7]== 0 ))  {mode = FOLLOWING_LINE;}
  else if((sensors[0]== 0 )&&(sensors[1]== 0 )&&(sensors[2]== 0 )&&(sensors[3]== 1 )&&(sensors[4]== 1 )&&(sensors[5]== 1 )&&(sensors[6]== 0 )&&(sensors[7]== 0 ))  {mode = FOLLOWING_LINE; }

  else if((sensors[0]== 1 )&&(sensors[1]== 1 )&&(sensors[2]== 1 )&&(sensors[3]== 1 )&&(sensors[4]== 1 )&&(sensors[5]== 1 )&&(sensors[6]== 1 )&&(sensors[7]== 1 ))  {mode = THRE_LINE; }
  else if((sensors[0]== 0 )&&(sensors[1]== 1 )&&(sensors[2]== 1 )&&(sensors[3]== 1 )&&(sensors[4]== 1 )&&(sensors[5]== 1 )&&(sensors[6]== 1 )&&(sensors[7]== 1 ))  {mode = THRE_LINE; }
  else if((sensors[0]== 1 )&&(sensors[1]== 1 )&&(sensors[2]== 1 )&&(sensors[3]== 1 )&&(sensors[4]== 1 )&&(sensors[5]== 1 )&&(sensors[6]== 1 )&&(sensors[7]== 0 ))  {mode = THRE_LINE; }

  else if((sensors[0]== 0 )&&(sensors[1]== 0 )&&(sensors[2]== 1 )&&(sensors[3]== 1 )&&(sensors[4]== 1 )&&(sensors[5]== 1 )&&(sensors[6]== 1 )&&(sensors[7]== 1 ))  {mode = RIGHT_LINE; }
  
  else if((sensors[0]== 0 )&&(sensors[1]== 0 )&&(sensors[2]== 0 )&&(sensors[3]== 1 )&&(sensors[4]== 1 )&&(sensors[5]== 1 )&&(sensors[6]== 1 )&&(sensors[7]== 1 ))  {mode = RIGHT_LINE; }
  else if((sensors[0]== 0 )&&(sensors[1]== 0 )&&(sensors[2]== 0 )&&(sensors[3]== 0 )&&(sensors[4]== 1 )&&(sensors[5]== 1 )&&(sensors[6]== 1 )&&(sensors[7]== 1 ))  {mode = RIGHT_LINE; }

  else if((sensors[0]== 1 )&&(sensors[1]== 1 )&&(sensors[2]== 1 )&&(sensors[3]== 1 )&&(sensors[4]== 1 )&&(sensors[5]== 1 )&&(sensors[6]== 0 )&&(sensors[7]== 0 ))  {mode = LEFT_LINE; }
  
  else if((sensors[0]== 1 )&&(sensors[1]== 1 )&&(sensors[2]== 1 )&&(sensors[3]== 1 )&&(sensors[4]== 1 )&&(sensors[5]== 0 )&&(sensors[6]== 0 )&&(sensors[7]== 0 ))  {mode = LEFT_LINE; }
  else if((sensors[0]== 1 )&&(sensors[1]== 1 )&&(sensors[2]== 1 )&&(sensors[3]== 1 )&&(sensors[4]== 0 )&&(sensors[5]== 0 )&&(sensors[6]== 0 )&&(sensors[7]== 0 ))  {mode = LEFT_LINE; }
 
  else if((sensors[0]== 0 )&&(sensors[1]== 0 )&&(sensors[2]== 0 )&&(sensors[3]== 0 )&&(sensors[4]== 0 )&&(sensors[5]== 0 )&&(sensors[6]== 0 )&&(sensors[7]== 0 ))  {mode = NO_LINE; }

  else if((sensors[0]== 0 )&&(sensors[1]== 1 )&&(sensors[2]== 1 )&&(sensors[3]== 1 )&&(sensors[4]== 0 )&&(sensors[5]== 0 )&&(sensors[6]== 0 )&&(sensors[7]== 0 ))  {mode = ERR_RIGHT;}
  else if((sensors[0]== 0 )&&(sensors[1]== 0 )&&(sensors[2]== 1 )&&(sensors[3]== 1 )&&(sensors[4]== 0 )&&(sensors[5]== 0 )&&(sensors[6]== 0 )&&(sensors[7]== 0 ))  {mode = ERR_RIGHT;}  
  
  else if((sensors[0]== 0 )&&(sensors[1]== 1 )&&(sensors[2]== 1 )&&(sensors[3]== 0 )&&(sensors[4]== 0 )&&(sensors[5]== 0 )&&(sensors[6]== 0 )&&(sensors[7]== 0 ))  {mode = ERR_R_RIGHT;}
  else if((sensors[0]== 1 )&&(sensors[1]== 1 )&&(sensors[2]== 1 )&&(sensors[3]== 0 )&&(sensors[4]== 0 )&&(sensors[5]== 0 )&&(sensors[6]== 0 )&&(sensors[7]== 0 ))  {mode = ERR_R_RIGHT;}
  else if((sensors[0]== 1 )&&(sensors[1]== 1 )&&(sensors[2]== 0 )&&(sensors[3]== 0 )&&(sensors[4]== 0 )&&(sensors[5]== 0 )&&(sensors[6]== 0 )&&(sensors[7]== 0 ))  {mode = ERR_R_RIGHT;} 
  else if((sensors[0]== 1 )&&(sensors[1]== 0 )&&(sensors[2]== 0 )&&(sensors[3]== 0 )&&(sensors[4]== 0 )&&(sensors[5]== 0 )&&(sensors[6]== 0 )&&(sensors[7]== 0 ))  {mode = ERR_R_RIGHT;}

  else if((sensors[0]== 0 )&&(sensors[1]== 0 )&&(sensors[2]== 0 )&&(sensors[3]== 0 )&&(sensors[4]== 1 )&&(sensors[5]== 1 )&&(sensors[6]== 1 )&&(sensors[7]== 0 ))  {mode = ERR_LEFT;}
  else if((sensors[0]== 0 )&&(sensors[1]== 0 )&&(sensors[2]== 0 )&&(sensors[3]== 0 )&&(sensors[4]== 1 )&&(sensors[5]== 1 )&&(sensors[6]== 0 )&&(sensors[7]== 0 ))  {mode = ERR_LEFT;}
 
  else if((sensors[0]== 0 )&&(sensors[1]== 0 )&&(sensors[2]== 0 )&&(sensors[3]== 0 )&&(sensors[4]== 0 )&&(sensors[5]== 1 )&&(sensors[6]== 1 )&&(sensors[7]== 0 ))  {mode = ERR_R_LEFT;}
  else if((sensors[0]== 0 )&&(sensors[1]== 0 )&&(sensors[2]== 0 )&&(sensors[3]== 0 )&&(sensors[4]== 0 )&&(sensors[5]== 1 )&&(sensors[6]== 1 )&&(sensors[7]== 1 ))  {mode = ERR_R_LEFT;}
  else if((sensors[0]== 0 )&&(sensors[1]== 0 )&&(sensors[2]== 0 )&&(sensors[3]== 0 )&&(sensors[4]== 0 )&&(sensors[5]== 0 )&&(sensors[6]== 1 )&&(sensors[7]== 1 ))  {mode = ERR_R_LEFT;}
  else if((sensors[0]== 0 )&&(sensors[1]== 0 )&&(sensors[2]== 0 )&&(sensors[3]== 0 )&&(sensors[4]== 0 )&&(sensors[5]== 0 )&&(sensors[6]== 0 )&&(sensors[7]== 1 ))  {mode = ERR_R_LEFT;}


 
 }

 else{
  flag=0;
  readSensors();
 }

}
