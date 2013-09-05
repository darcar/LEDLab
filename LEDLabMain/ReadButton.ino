int read_buttons(float brightness)
{
  int upval = digitalRead(upbutt);            // read up button value (HIGH/LOW)
  int downval = digitalRead(downbutt);        // read down button value (HIGH/LOW)
  
  if (downval == HIGH && upval == HIGH) {     //case where both buttons pushed
     output = 0;
  }
  else if (upval == HIGH) {                   // case where up button is pushed
     output = 1;
  }
  else if (downval == HIGH && brightness > 0) { // case where down button is pushed
     output = -1;                               // and brightness is non-zero/negative
  }
  else {                                      // case where no button was pressed
     output = 0;
  }  
 
  return output;
}
