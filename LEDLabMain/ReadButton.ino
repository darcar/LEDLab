int read_buttons()
{
  int upval = digitalRead(upbutt);
  int downval = digitalRead(downbutt);
  
  if (upval == HIGH) {
     output = 1;
  }
  else if (downval == HIGH) {
     output = -1;
  }
  else if (downval == HIGH && upval == HIGH) {
     output = 0;
  }
  else {
     output = 0;
  }  
 
  return output;
}
