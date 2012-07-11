/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor 
 
 This example code is in the public domain.
 */
int count = 10;
int low=0;
int empty=0;

void setup() {
  Serial.begin(19200);
  pinMode(2, INPUT);
}

void loop() {
  int sensorValue = digitalRead(2);
  if (sensorValue==1)
    {
      count --;
      Serial.print("\r");
      delay(1000);                    //Wait for a second while the modem sends an "OK"
      Serial.print("AT+CMGF=1\r");    //Because we want to send the SMS in text mode
      delay(1000);
 
      Serial.print("AT+CSCA=\"+13123149810\"\r");  //Setting for the SMS Message center number,  
      delay(1000);                                  //uncomment only if required and replace with
                                                  //the message center number obtained from
                                                  //your GSM service provider.
                                                  //Note that when specifying a tring of characters
                                                  // " is entered as \"
 
      Serial.print("AT+CMGS=\"+16038017161\"\r");    //Start accepting the text for the message
                                                      //to be sent to the number specified.
                                                      //Replace this number with the target mobile number.
      delay(1000);
      Serial.print("SIM900 and Arduino say Hi!\r");   //The text for the message
      delay(1000);
      Serial.write(26);
      while(sensorValue == 1)
      {int sensorValue = digitalRead(2);}
    }
    if(count==3&&low==0)
    {
      low++;
            Serial.print("\r");
      delay(1000);                    //Wait for a second while the modem sends an "OK"
      Serial.print("AT+CMGF=1\r");    //Because we want to send the SMS in text mode
      delay(1000);
 
      Serial.print("AT+CSCA=\"+13123149810\"\r");  //Setting for the SMS Message center number,  
      delay(1000);                                  //uncomment only if required and replace with
                                                  //the message center number obtained from
                                                  //your GSM service provider.
                                                  //Note that when specifying a tring of characters
                                                  // " is entered as \"
 
      Serial.print("AT+CMGS=\"+16038017161\"\r");    //Start accepting the text for the message
                                                      //to be sent to the number specified.
                                                      //Replace this number with the target mobile number.
      delay(1000);
      Serial.print("LOW!\r");   //The text for the message
      delay(1000);
      Serial.write(26);
    }
      
 
}



