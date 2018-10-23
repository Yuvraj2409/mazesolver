
void actualRUN()
{
  readSensors();
  while(mode!=FOLLOWING_LINE)
  {
    delay(500);
    readSensors();
  }
  j=0;
  while(1)
  {
  readSensors();
  switch(mode)
  {
    case FOLLOWING_LINE:
      run_an_Inch();
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
            delay(150);
            run_an_Inch();
            analogWrite(motor_en_left,255);
            analogWrite(motor_en_right,255);
            break;
            
    case ERR_R_LEFT:
            analogWrite(motor_en_right,255);
            left_stop();
            right_backward();
            delay(150);
            run_an_Inch();
            analogWrite(motor_en_left,255);
            analogWrite(motor_en_right,255);
            break;
    
    
    case THRE_LINE:
            run_an_Inch();
            run_an_Inch();
            readSensors();
            
            if((sensors[0]== 1 )&&(sensors[1]== 1 )&&(sensors[2]== 1 )&&(sensors[3]== 1 )&&(sensors[4]== 1 )&&(sensors[5]== 1 )&&(sensors[6]== 1 )&&(sensors[7]== 1 )){
              finish();
            }
            
            else{
              what_to_do();
            }

            break;        
    
     
     default:
            what_to_do();
   
            

   }
  }
}


void what_to_do(void)
{
    if(pathF.charAt(j)=='L')
      {
        left_turn();
        j++;
      }
     
    else if(pathF.charAt(j)=='R')
      {
        right_turn();
        j++;
      }

    else if(pathF.charAt(j)=='S')
      {
        run_an_Inch();
        run_an_Inch();
        j++;
      }

}
