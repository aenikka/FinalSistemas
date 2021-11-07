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
    static uint8_t dataCounter = 0;
    static uint8_t state = 1;
    static uint8_t bufferRx[1] = {0};
    static uint8_t arrayResultado[2] = {0};
    
    switch (state)
    {
        case 1:
            while(Serial.available())
            {
                uint8_t dataRx = Serial.read();
       
                if (dataCounter >= 1) {
                    bufferRx[dataCounter] = dataRx;
                    dataCounter = 0;
                    Serial.write(bufferRx[0]);
                           
                    if(bufferRx[1]=='w')
                    {
                      state = 2;
                      Serial.write("estamos en estado 2");            
                    }
                    if(bufferRx[1]== 'r')
                    {
                      state = 3;
                      Serial.write("estamos en estado 3");            
                    }
                   
                }
                else
                {
                    bufferRx[dataCounter] = dataRx;
                    dataCounter++;              
                }  
              }

   
            
        case 2:
             //Serial.write(2);
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
        case 3:
            Serial.write(2);
            arrayResultado[0] = digitalRead(PULSE);
            arrayResultado[1] = ledState;
            Serial.write(arrayResultado,2);
            
        

            break;
        default:
 
             break;
        
            
    }
  }
  
