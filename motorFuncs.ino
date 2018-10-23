void run_an_Inch()
{
  analogWrite(motor_en_left,255);
  analogWrite(motor_en_right,255);
  right_forward();
  left_forward();
  delay(inch);
  right_stop();
  left_stop();
}

void left_turn()
{
   right_forward();
   left_stop();
   delay(500);
   while(mode!=FOLLOWING_LINE)
   {
   right_forward();
   left_stop();
   delay(10);
  
   readSensors();
   }
}

void right_turn()
{
   left_forward();
   right_stop();
   delay(500);
   while(mode!=FOLLOWING_LINE)
   {
   left_forward();
   right_stop();
   delay(10);
   
   readSensors();
   }
}

void U_turn()
{
   left_forward();
   right_forward();
   delay(200);
   left_backward();
   delay(180);
   while(mode!=FOLLOWING_LINE && mode!=ERR_RIGHT && mode!=ERR_LEFT)
   {
     right_forward();
     left_backward();
     delay(10);
     readSensors();
   }
   right_stop();
   left_stop();
}

void right_forward()
{
  digitalWrite(motor_right_for,HIGH);
  digitalWrite(motor_right_back,LOW);
  
}

void left_forward()
{
  digitalWrite(motor_left_for,HIGH);
  digitalWrite(motor_left_back,LOW);
  
}

void right_backward()
{
  digitalWrite(motor_right_for,LOW);
  digitalWrite(motor_right_back,HIGH);
  
}


void left_backward()
{
  digitalWrite(motor_left_for,LOW);
  digitalWrite(motor_left_back,HIGH);
  
}

void right_stop()
{
  digitalWrite(motor_right_for,LOW);
  digitalWrite(motor_right_back,LOW);
  
}

void left_stop()
{
  digitalWrite(motor_left_for,LOW);
  digitalWrite(motor_left_back,LOW);
  
}
