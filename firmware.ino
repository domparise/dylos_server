char line[80];
int small = 0;
int large = 0;
int i = 0;

char someChar; // for incoming serial data

void setup() {
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    someChar = Serial.read();

    Serial.print(someChar);
    if (someChar == '\n')
    {
      line[i++]=0;
      sscanf(line,"%d,%d",&small,&large);
      Serial.print(small);
      Serial.print(' ');
      Serial.println(large);
      Spark.publish("dust_count", "{\"small\":"+String(small)+",\"large\":"+String(large)+"}" );
      i=0;
    }
    else
      line[i++] = someChar;

  }
}

