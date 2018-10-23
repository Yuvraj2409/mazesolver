void mazeEnd(void)
{
  digitalWrite(led,HIGH);
  pathF=Optimize(pathI);
  delay(6000);
  digitalWrite(led,LOW);
  actualRUN();
}


String MergeU(String path)
{
  String temp;
  int i=0;
  PathLen=path.length();
  while(i < PathLen)
  {
    if(path.charAt(i)=='U' && path.charAt(i-1)=='U')
      continue;
    else
      temp+=path.charAt(i);
    i++;
  }
  return temp;
}

String Optimize(String path)
{
  path=MergeU(path);
  int OptpathIndex;
  int pathIndex;
  
  PathLen=path.length();
  String Optpath="";
  for(pathIndex=0,OptpathIndex=0;pathIndex<PathLen;pathIndex++)         //Traversal
  {
   Serial.println(Optpath);
     if(pathIndex!=0 || pathIndex!=PathLen-1){
     if(path.charAt(pathIndex-1)=='U' && path.charAt(pathIndex+1)=='U')      //For alternating U occurences
    {
      for(i=pathIndex+1;i<PathLen;i++)
        {
          Optpath += path.charAt(i);
        }
      break;
    }

    
    if(((path.charAt(pathIndex+1)!='U') && (path.charAt(pathIndex-1)!='U')) && (path.charAt(pathIndex)!='U'))       //Normal cases
    {
      Optpath+=path.charAt(pathIndex);
      OptpathIndex++;
    }
    else if(path.charAt(pathIndex) == 'U')
    {
       if(path.charAt(pathIndex-1)=='L' && path.charAt(pathIndex+1)=='L')
       {
        Optpath+='S';
        OptpathIndex++;
       }
       else if(path.charAt(pathIndex-1)=='L' && path.charAt(pathIndex+1)=='S')
       {
        Optpath+='R';
        OptpathIndex++;
       }
       else if(path.charAt(pathIndex-1)=='S' && path.charAt(pathIndex+1)=='L')
       {
        Optpath+='R';
        OptpathIndex++;
       }
       else
       {
        Optpath+='U';
        OptpathIndex++;
       }
    }
  }
  }
  OptpathLen=Optpath.length();
  for(i=0;i<OptpathLen;i++)                             //Recall function if Dead ends exist
  {
    if(Optpath.charAt(i)=='U')
    {
      Optpath=Optimize(Optpath);
      break;
    }
  }
  return Optpath;
}
