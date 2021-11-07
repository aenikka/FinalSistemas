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



void Task12()
  {
    static bool ledState = false;
    
    // Send some message when I receive an 'A' or a 'Z'.
    switch (Serial.read())
    {
        case 'w':
        
            //Serial.println("w");
            if (ledState == false) 
             {
              ledState = true;
             } 
             else 
             {
              ledState = false;
             }
            digitalWrite(ALIVELED, ledState);
            break;
            
        case 'r':
        
            Serial.print(digitalRead(PULSE));
            Serial.println(ledState);
            break;
    }
  }
  
