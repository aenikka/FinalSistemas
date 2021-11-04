#define ALIVELED 13
#define PULSE 2

unsigned long last_time = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ALIVELED, OUTPUT);
  pinMode(PULSE, INPUT_PULLUP);
  Serial.begin(115200);

}

void loop() 
{
  // put your main code here, to run repeatedly:
  Task12();

}

void Task1()
{
  static bool ledState = false;
  if ( Serial.available() > 0) 
  {
    String dato = Serial.readStringUntil('\n');
    if ( dato == "r") 
    {
       Serial.print(digitalRead(PULSE));
       Serial.println(ledState);
       //Serial.println('\n');
    }
    else if (dato == "w")
    {

       if (ledState == false) 
       {
        ledState = true;
       } 
       else 
       {
        ledState = false;
       }
     digitalWrite(ALIVELED, ledState);
    }
  }

  
}

void Task12()
  {
     if (millis() > last_time + 2000)
    {
        Serial.println("Arduino is alive!!");
        last_time = millis();
    }

    // Send some message when I receive an 'A' or a 'Z'.
    switch (Serial.read())
    {
        case 'w':
            Serial.println("w");
            break;
        case 'r':
            Serial.println("r");
            break;
    }
  }
  
