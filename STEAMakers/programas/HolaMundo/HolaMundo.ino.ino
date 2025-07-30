unsigned long task_time_ms=0;

void setup()
{
  // Inicar puerto serie a 9600 buadios
	Serial.begin(9600);
  // Espera a que se complete la transmision de datos serie
	Serial.flush();
	while(Serial.available()>0)Serial.read();
}

void loop()
{
  // millis() retorna los milisegundos desde que se inicio el programa
 	if((millis()-task_time_ms)>=1000){
    task_time_ms=millis();
    // Envia mensaje por puerto serie
    Serial.println(String("Hola mundo"));
  }
}