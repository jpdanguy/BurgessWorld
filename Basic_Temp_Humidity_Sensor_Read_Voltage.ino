/*--------------------------------------------------------------
  Program:      Measure_Voltage

  Description:  Reads VIN volage value on analog input A0 and calculates
                the voltage assuming that a voltage divider
                network on the pin divides VIN voltage to 1.1v
                It uses the INTERNAL 1.1 voltage reference of the Atmega328

  Hardware:     BurgessWorld Basic or Advanced sensor board with voltage divider on A0.

  Software:     Developed using Arduino 1.8.3.0 software
                Should be compatible with Arduino 1.0 +

  Date:         17 May 2017
  --------------------------------------------------------------*/

// number of analog samples to take per reading
#define NUM_SAMPLES 10

int sum = 0;                    // sum of samples taken
unsigned char sample_count = 0; // current sample number
float voltage = 0.0;            // calculated voltage

void setup()
{
  Serial.begin(57600);
  analogReference(INTERNAL);

}

void loop()
{
  // take a number of analog samples and add them up
  while (sample_count < NUM_SAMPLES) {
    sum += analogRead(A0);
    sample_count++;
    delay(10);
  }
  // calculate the voltage
  // use 5.0 for a 5.0V ADC reference voltage
  // 5.015V is the calibrated reference voltage
  Serial.println(sum / 10);
  voltage = ((((((float)sum / (float)NUM_SAMPLES)) / 1024.0) * 1.1) / .245);
  // send voltage for display on Serial Monitor
  // voltage multiplied by 11 when using voltage divider that
  // divides by 11. 11.132 is the calibrated voltage divide
  // value
  Serial.print(voltage);
  Serial.println (" V");
  sample_count = 0;
  sum = 0;
}
