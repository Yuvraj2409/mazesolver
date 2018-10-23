int mode = 0;
int motor_en_left=3; 
int motor_left_for=5;
int motor_left_back=7;
int motor_en_right=11;
int motor_right_for=A0;
int motor_right_back=A1;

int led=10;

# define STOPPED 0
# define FOLLOWING_LINE 1
# define NO_LINE 2
# define CONT_LINE 3
# define POS_LINE 4
# define RIGHT_LINE 5
# define LEFT_LINE 6
# define ERR_LEFT 7
# define ERR_RIGHT 8
# define THRE_LINE 9
# define ERR_R_LEFT 10
# define ERR_R_RIGHT 11

String pathI="";  //LLLURLRULLRULLLRULL  LSULULLUL  LRULLUL  LUS  R
String pathF;
int i;
int j;
int PathLen=0;
int OptpathLen=0;
int sensors[8]={0, 0, 0, 0, 0, 0, 0, 0};

int flag=0;

int inch=60;


//const int ledPin = ;

const int lineFollowSensor0 = 2; 
const int lineFollowSensor1 = 4; 
const int lineFollowSensor2 = 6; 
const int lineFollowSensor3 = 8;
const int lineFollowSensor4 = A5;
const int lineFollowSensor5 = A4; 
const int lineFollowSensor6 = A3;
const int lineFollowSensor7 = A2;
