Una alternativa que considero aconsejable para iniciarse en la programación con la placa Keyestudio UNO es acompañarla del escudo TdR STEAM. Es mas, es por donde aconsejaría comenzar.

En la web [Retos con TdR-STEAM y keyestudio UNO](https://fgcoca.github.io/TdR-STEAM-and_UNO/) tienes disponible toda una colección de retos y actividades realizadas con este conjunto de placas y algún hardware adicional.

La mayoría de retos y actividades se dan solucionadas para facilitar el aprendizaje,  pero se reta al lector a solucionar cada caso por si mismo y solamente recurrir a la solución cuando resulte imprescindible.

Reproduzco aquí la información básica del escudo.

## <FONT COLOR=#007575>**TdR STEAM**</font>
El escudo tiene el aspecto que vemos en la imagen siguiente:

<center>

![TdR STEAM](../img/uno/TdR-STEAM.png)  
*TdR STEAM*

</center>

Las partes que lo componen las vemos en la imagen siguiente y en los apartados subsiguientes se describen:

<center>

![Partes de la TdR STEAM](../img/uno/elementos-TdR-STEAM.png)  
*Partes de la TdR STEAM*

</center>

### <FONT COLOR=#FF00FF><FONT size=9><b>1. Interfaz I2C</b></font></font>
Interfaz I2C o IIC conectados a los pines VCC, GND, SDA (A4) y SCL (A5). El pin A4 corresponde con SDA (Serial DAta) y es por donde se transmiten los datos en la comunicación I2C. El pin A5 es SCL (Serial CLock) donde está la señal de sincronización o reloj de la comunicación I2C.

<center>

![Conector I2C en la TdR STEAM](../img/uno/I2C_steam.png)  
*Conector I2C en la TdR STEAM*

</center>

### <FONT COLOR=#FF00FF><FONT size=9><b>2. Pulsadores</b></font></font>
Los pulsadores SW1 y SW2 se conectan a D2 y D7 respectivamente y se configuran como entradas digitales con sus correspondientes resistencias de polarización que hacen que cuando están en reposo pongan su entrada digital correspondiente a "0" (cero lógico) y que se ponga a "1" (uno lógico) cuando los accionemos.

<center>

![Pulsadores SW1 y SW2](../img/uno/pulsadores_TdR.png)  
*Pulsadores SW1 y SW2*

</center>

### <FONT COLOR=#FF00FF><FONT size=9><b>3. Diodos LED</b></font></font>
Diodos LED Azul (LED3) y Rojo (LED4) conectados a D13 y D12 respectivamente. Configurados como salidas con su resistencia limitadora.

<center>

![Diodos LED](../img/uno/rojo_azul.png)  
*Diodos LED*

</center>

### <FONT COLOR=#FF00FF><FONT size=9><b>4. Led RGB</b></font></font>
El Led RGB o neopixel de la placa es del tipo 5050 conectado a los pines D6 (Red), D9 (Green) y D10(Blue). Estos tres pines son PWM y nos van a permitir regular su intensidad.

<center>

![Led RGB](../img/uno/RGB_TdR.png)  
*Led RGB*

</center>

### <FONT COLOR=#FF00FF><FONT size=9><b>5. Conectores E/S digital</b></font></font>
Son dos conectores para Entradas/Salidas digitales dotados de alimentación y conectados a los pines D3 y D5. A estos conectores podemos colocarles sensores externos.

<center>

![Led RGB](../img/uno/D3_D5_TdR.png)  
*Led RGB*

</center>

### <FONT COLOR=#FF00FF><FONT size=9><b>6. Comunicaciones serie</b></font></font>
Conector de comunicaciones Bluetooth y WiFi con conmutado (Swich On/Off) conectado a los pines D0 (Rx) y D1 (Tx).

El puerto de comunicaciones serie nos permite conectar módulos Bluetooth o WiFi. Este puerto va equipado con un conmutador para poder conectarlo o desconectarlo ya que utiliza los mismos pines Rx/Tx que se utilizan para comunicarse con el ordenador. Si vamos a subir firmware a la placa debe estar en posición OFF y si vamos a trabajar con Bluetooth o WiFi en posición ON.

<center>

![Comunicaciones serie](../img/uno/comm_TdR.png)  
*Comunicaciones serie*

</center>

### <FONT COLOR=#FF00FF><FONT size=9><b>7. DHT11</b></font></font>
Sensor digital de Temperatura y Humedad DHT11 conectado como entrada a D4.

<center>

![DHT11](../img/uno/DHT11_TdR.png)  
*DHT11*

</center>

### <FONT COLOR=#FF00FF><FONT size=9><b>8. Potenciómetro</b></font></font>
Potenciómetro giratorio de 270º conectado como entrada analógica al pin A0.

<center>

![Potenciómetro](../img/uno/pot_TdR.png)  
*Potenciómetro*

</center>

### <FONT COLOR=#FF00FF><FONT size=9><b>9. Buzzer</b></font></font>
El zumbador Piezoeléctrico o buzzer es un pequeño altavoz conectado a la salida digital D8.

<center>

![Buzzer](../img/uno/buzz_TdR.png)  
*Buzzer*

</center>

### <FONT COLOR=#FF00FF><FONT size=9><b>10. Receptor IR</b></font></font>
Diodo receptor de infrarrojos (IR) conectado a la entrada digital D11.

<center>

![Receptor IR](../img/uno/IR_TdR.png)  
*Receptor IR*

</center>

### <FONT COLOR=#FF00FF><FONT size=9><b>11. LDR</b></font></font>
Sensor de luminosidad o resistencia LDR conectada al pin analógico A1.

<center>

![LDR](../img/uno/LDR_TdR.png)  
*LDR*

</center>

### <FONT COLOR=#FF00FF><FONT size=9><b>12. Reset</b></font></font>
Botón de Reset conectado directamente a la entrada de reset de la placa Keyestudio UNO. Sirve para inicializar el funcionamiento del conjunto.

<center>

![Reset](../img/uno/reset.png)  
*Reset*

</center>

### <FONT COLOR=#FF00FF><FONT size=9><b>13. Entrada analógica</b></font></font>
Conector para entrada analógica desde sensor externo conectado al pin A3.

<center>

![Entrada analógica](../img/uno/a3.png)  
*Entrada analógica*

</center>

### <FONT COLOR=#FF00FF><FONT size=9><b>14. LM35</b></font></font>
Sensor de temperatura (LM35) conectado al pin analógico A2.

<center>

![LM35](../img/uno/LM35.png)  
*LM35*

</center>
