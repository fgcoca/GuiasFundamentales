En este apartado vamos a realizar algunas consideraciones sobre los siguientes aspectos de las placas ESP32:

* Pines
* Entradas analógicas
* Entradas y salidas digitales
* Salidas PWM en ESP32

## <FONT COLOR=#007575>**Pines en ESP32**</font>
En general los pines en ESP32 son de tipo GPIO (<b>G</b>eneral <b>P</b>urpose <b>I</b>nput/<b>O</b>utput, Entrada/Salida de Propósito General).

Algunos pines GPIO pueden tener un comportamiento no esperado durante el arranque del sistema o en el reinicio del mismo. Esto se debe a que durante el arranque de la placa ESP32 se deben realizar procesos internos que ponen en alto ciertos pines o incluso hacen que emitan señales, y esto puede provocar esos efectos no deseados.

El pin **GPIO1** del microcontrolador es el pin **Tx** del puerto UART de depuración y cuando la placa arranca, se reinicia o cuando nosotros hacemos uso del puerto serie, este pin emite datos. Por este motivo es un pin que no conviene usar como entrada o salida.

El **GPIO3** tiene un problema similar al GPIO1 ya que se trata del pin **Rx** del micocontrolador.

Los pines **GPIO34**, **GPIO35**, **GPIO36** y **GPIO39** solamente pueden utilizarse como *entradas* porque no disponen de resistencia pull-up.

## <FONT COLOR=#007575>**Entradas analógicas**</font>
Las señales analógicas son las que pueden tomar diferentes valores de tensión en un determinado periodo de tiempo, siendo su forma mas característica la senoidal. Cuando hablamos de entradas analógicas estamos hablando de pines del microcontrolador que pueden leer esas señales. En el caso de ESP32 todo son pines GPIO y por lo tanto se requiere de un conversor analógico a digital que sea capaz de transformar esas señales analógicas en digitales. El chip ESP32 que monta la placa ESP32 STEAMakers dispone de 2 convertidores Digital-Analógico (DAC) de 8 bits y 16 convertidores Analógico-Digital (ADC) de 12 bits. Estos conversores se asocian a los pines IO1 hasta IO20.

La resolución de los conversores ADC es de 12 bits (2^12 = 4096) por lo que la transformación de los valores digitales va a ser de mucha precisión. Pero cuidado con el uso de estas entradas, porque en realidad su comportamiento es que están leyendo valores digitales y no valores analógicos por lo que lo cambios de valores analógicos muy pequeños pueden no ser detectados.

Los canales ADC se dividen en dos puertos denominados ADC1 y ADC2. Las entradas analógicas del puerto ADC2 solamente las podemos usar como tales si el controlador WiFi no ha sido iniciado, ya que este puerto es el que utiliza el controlador del WiFi que integra la placa.

!!! Warning "AVISO IMPORTANTE"
    Cuando vamos a trabajar con señales analógicas debemos tener muy presente que, aunque todos los pines IOxx son entradas y salidas digitales, algunas incluso con más funciones. <FONT COLOR=#FF00FF>**Cuando tenemos que utilizar la comunicación WiFi el convertidor ADC2 NO funciona.**</font>

## <FONT COLOR=#007575>**Entradas y salidas digitales**</font>
Una señal digital solamente puede tomar dos valores o estados lógicos, alto y bajo, High y Low, 0 y 1 siendo su representación característica una onda cuadrada. El estado bajo se asocia a cero voltios y el estado alto a 3.3V o 5V.

Las entradas permiten recibir señales con los valores digitales descritos, como por ejemplo leer el estado de un pulsador.

Debemos saber que ESP32 lleva unas resistencias de pull-up (1) o pull-down (0) que nos permiten establecer el estado que tiene la entrada cuando está en reposo. Estas resistencias están disponibles en todos los pines excepto el 34 y 39. Estas resistencias internas se pueden activar por código.

Las salidas digitales nos van a servir para realizar acciones sobre los elementos conectadas en ellas, como por ejemplo encender un LED o activar un relé.

En principio todos los pines que se pueden utilizar como salida en ESP32 pueden usarse con PWM excepto los pines que no disponen de resistencia de pull-up interna.

## <FONT COLOR=#007575>**Compatibilidad y descripción de pines ESP32 STEAMakers**</font>
Importante: Todos los pines IOxx son entradas y salidas digitales, algunas con más funciones. Utilizando la comunicación WiFi no funciona el ADC2.

En las tablas siguientes tenemos relacionados todos los pines entre los tipos de placas UNO y ESP32 STEAMakers.

<table width="100%"  border="1" cellspacing="0" cellpadding="0" style="font-size:10px">
  <tr>
    <th>UNO</th>
    <th>Función</th>
    <th>ESP32</th>
    <th>Ampliación</th>
    <th>UNO</th>
    <th>Función</th>
    <th>ESP32</th>
    <th>Ampliación</th>
  </tr>
  <tr>
    <td>D0</td>
    <td>Rx</td>
    <td>IO03</td>
    <td>UART 0 RX</td>
    <td>D1</td>
    <td>Rx</td>
    <td>IO01</td>
    <td>UART 0 TX</td>
  </tr>
  <tr>
    <td>D2</td>
    <td>ADC2 CH9</td>
    <td>IO26</td>
    <td>DAC2</td>
    <td>D3</td>
    <td>ADC2 CH8</td>
    <td>IO25</td>
    <td>DAC1</td>
  </tr>
  <tr>
    <td>D4</td>
    <td></td>
    <td>IO17</td>
    <td>UART 2 TX</td>
    <td>D5</td>
    <td></td>
    <td>IO16</td>
    <td>UART 2 RX</td>
  </tr>
  <tr>
    <td>D6</td>
    <td>ADC2 CH7</td>
    <td>IO27</td>
    <td>TOUCH7 / HSPI CS</td>
    <td>D7</td>
    <td>ADC2 CH6</td>
    <td>IO14</td>
    <td>TOUCH6 / HSPI SCK</td>
  </tr>
  <tr>
    <td>D8</td>
    <td>ADC2 CH5</td>
    <td>IO12</td>
    <td>TOUCH5 / HSPI MISO</td>
    <td>D9</td>
    <td>ADC2 CH4</td>
    <td>IO13</td>
    <td>TOUCH4 / HSPI MOSI</td>
  </tr>
  <tr>
    <td>D10</td>
    <td></td>
    <td>IO05</td>
    <td>VSPI CSO</td>
    <td>D11</td>
    <td></td>
    <td>IO23</td>
    <td>VSPI MOSI</td>
  </tr>
  <tr>
    <td>D12</td>
    <td></td>
    <td>IO19</td>
    <td>VSPI MISO</td>
    <td>D13</td>
    <td></td>
    <td>IO18</td>
    <td>VSPI CLK</td>
  </tr>
  <tr>
    <td>GND</td>
    <td></td>
    <td>GND</td>
    <td></td>
    <td>5V</td>
    <td></td>
    <td>+5V</td>
    <td></td>
  </tr>
  <tr>
    <td>SDA</td>
    <td>I2C</td>
    <td>IO21</td>
    <td>SDA / VSPI HD</td>
    <td>SCL</td>
    <td>I2C</td>
    <td>IO22</td>
    <td>SCL / VSPI WP</td>
  </tr>
  <tr>
    <td>A0</td>
    <td>ADC2 CH2</td>
    <td>IO02</td>
    <td>TOUCH 2 / HSPI WP / E/S de RTC 12 procesador ultra baja potencia</td>
    <td>A1</td>
    <td>ADC2 CH0</td>
    <td>IO04</td>
    <td>TOUCH 0 / HSPI CD / E/S de RTC 10 procesador ultra baja potencia</td>
  </tr>
  <tr>
    <td>A2</td>
    <td>ADC1 CH7</td>
    <td>IO35</td>
    <td>E/S de RTC 5 procesador ultra baja potencia</td>
    <td>A3</td>
    <td>ADC1 CH6</td>
    <td>IO34</td>
    <td>E/S de RTC 4 procesador ultra baja potencia</td>
  </tr>
  <tr>
    <td>A4</td>
    <td>SDA</td>
    <td>IO21</td>
    <td></td>
    <td>A5</td>
    <td>SCL</td>
    <td>IO22</td>
    <td></td>
  </tr>
</table>

En la tabla siguiente tenemos relacionados el resto de los pines entre los tipos de placas UNO y ESP32 STEAMakers.

<table width="100%"  border="1" cellspacing="0" cellpadding="0" style="font-size:10px">
  <tr>
    <th>UNO</th>
    <th>Función</th>
    <th>ESP32</th>
    <th>Ampliación</th>
    <th>UNO</th>
    <th>Función</th>
    <th>ESP32</th>
    <th>Ampliación</th>
  </tr>
  <tr>
    <td>VIN</td>
    <td></td>
    <td>VIN</td>
    <td></td>
    <td>GND</td>
    <td></td>
    <td>GND</td>
    <td></td>
  </tr>
  <tr>
    <td>GND</td>
    <td></td>
    <td>GND</td>
    <td></td>
    <td>5V</td>
    <td></td>
    <td>+5V</td>
    <td></td>
  </tr>
  <tr>
    <td>3.3V</td>
    <td></td>
    <td>+3.3V</td>
    <td></td>
    <td>RST</td>
    <td></td>
    <td>Reset</td>
    <td></td>
  </tr>
  <tr>
    <td>5V</td>
    <td></td>
    <td>5V</td>
    <td></td>
    <td></td>
    <td>ADC2 CH1</td>
    <td>IO00</td>
    <td>TOUCH 1 / E/S de RTC 11 procesador ultra baja potencia</td>
  </tr>
  <tr>
    <td></td>
    <td>D0 - uSD</td>
    <td>IO32</td>
    <td></td>
    <td></td>
    <td>CLK - uSD</td>
    <td>IO15</td>
    <td></td>
  </tr>
  <tr>
    <td></td>
    <td>CMD - uSD</td>
    <td>IO33</td>
    <td></td>
    <td></td>
    <td>IOUT</td>
    <td>IO35</td>
    <td>Medidor de corriente</td>
  </tr>
 <tr>
    <td></td>
    <td>VOUT</td>
    <td>IO37</td>
    <td>Medidor de tensión</td>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
</table>

En la figura siguiente podemos ver y descargar un gráfico con el pinout de la ESP32 STEAMakers en formato original svg.

<center>

![Comparativa de la placa ESP32 STEAMakers](../img/steamakers/ESP32_STEAMakers_pinout.svg)  
*Comparativa de la placa ESP32 STEAMakers*

</center>

## <FONT COLOR=#007575>**Verificación de la alimentación de la STEAMakers**</font>
La ESP32 STEAMakers, como cualquier otra placa basada en ESP32, debe tener unos valores de alimentación mínimos. Gracias a que la STEAMakers lleva incorporado un medidor de tensión e intensidad, podemos saber la tensión de alimentación en todo momento.

Si la tensión de alimentación cae por debajo de 4,8 V (aproximadamente), la placa no funcionará correctamente, sobre todo en la comunicación WiFi.

Es recomendable realizar una verificación de la tensión que está entregando el puerto USB del ordenador. Si la tensión no está cerca de 5 V deberemos cambiar el cable USB, alimentar el puerto USB de forma externa o alimentar la placa con una fuente de alimentación.

Podemos realizar un pequeño programa para verificar la alimentación de la placa como el que vemos en la imagen siguiente:

<center>

![Valor de tensión en la placa](../img/steamakers/Valor_V_placa.png)  
*Valor de tensión en la placa*

</center>

Debería ser un buen hábito colocar estos bloques al inicio de cualquier programa para asegurarnos de una buena alimentación, sobre todo si trabajamos directamente con la placa conectada al puerto USB del ordenador y empezamos a conectar elementos externos en la placa (pantallas, LED, servos, etc.).

También hay que tener en cuenta que, cuando utilicemos la comunicación mediante WiFi, deja de funcionar el ADC2, por lo que no podremos leer los valores de sensores conectados a los pines A0 y A1. En este caso, la alternativa es conectarlos a los pinos A2 y/o A3.
