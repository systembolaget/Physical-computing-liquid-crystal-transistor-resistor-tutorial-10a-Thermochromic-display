// Tutorial 10a. Thermochromic display

// Main parts: Adafruit Metro Mini, ON Semiconductor TIP120,
// 200Ohm 0.6V resistors, Alps 10k linear potentiometer,
// SFXC thermochromic liquid crystal sheet

// Variables that remain constant
const byte pinPotentiometer = A0; // Analog input pin from potentiometer
const byte pinTransistor = 3; // Digital output pin to transistor base

// Variables that can change
int vPotentiometer = 0; // Stores the potentiometer's voltage

void setup()
{
  // Initialise output pin to the transistor's base
  pinMode(pinTransistor, OUTPUT);
}

void loop()
{
  //Read the voltage from the potentiometer pin
  vPotentiometer = analogRead(pinPotentiometer);

  // And scale it into a 0 - 255 value range (= 0 to ~37°C resistor
  // temperature with the 7 200Ohm 0.6W resistors used here)
  int rTemperature = map(vPotentiometer, 0, 1023, 0, 255);

  // Set transistor base to change the resistor's temperature
  analogWrite(pinTransistor, rTemperature);
}
