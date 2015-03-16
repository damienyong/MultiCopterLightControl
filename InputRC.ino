#if defined (INPUT_RC)

void setupInputRC(){
  pinMode(RC_PIN_1, INPUT);
}

void loopInputRC(){
  int rc1 = pulseIn(RC_PIN_1, HIGH, 25000);
  boolean lostConnection = rc1<1000;
  if (rc1<1000) rc1 = 1000;
  else if (rc1>2000) rc1 = 2000;

  if (lostConnection) mode = MODE_RC_7;
  else if ((rc1>500)&&(rc1<1000)) mode = MODE_RC_off;    
  else if ((rc1>1000)&&(rc1<1230)) mode = MODE_RC_2; //loiter
  else if ((rc1>1231)&&(rc1<1360)) mode = MODE_RC_1; //stabilize
  else if ((rc1>1361)&&(rc1<1470)) mode = MODE_RC_4; //drift
  else if ((rc1>1470)&&(rc1<1620)) mode = MODE_RC_3; //alt holf
  else if ((rc1>1621)&&(rc1<1665)) mode = MODE_RC_6; // acro   
  else mode = MODE_RC_5; //land
}

#endif

