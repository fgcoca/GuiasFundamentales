## <FONT COLOR=#007575>**Actividad**</font>
En esta guía rápida encontrarás las instrucciones para conectar la placa a una red WiFi.

!!! danger "Por seguridad"
	Es muy conveniente tener la placa desprovista de cualquier tipo de alimentación mientras realizamos el conexionado de elementos. En caso contrario se pueden producir despefectos irreversibles en cualquiera de los elementos.

### <FONT COLOR=#AA0000>Material necesario</font>

* Placa ESP32 STEAMakers
* Ordenador. Antes de empezar a utilizar la placa STEAMakers, es necesario comprobar que nuestro dispositivo esté listo para trabajar. Encontrarás toda la información en [Antes de](https://fgcoca.github.io/GuiasFundamentales/UNO/contUNO/).

#### <FONT COLOR=#FF00FF>**Procedimiento**</font>

**1.** Ejecuta el programa AB-Connector. Recuerda que debe estar en ejecución todo el rato mientras trabajas con Arduinoblocks.

**2.** Ve a ArduinoBlocks, inicia sesión y comienza un nuevo proyecto del tipo “ESP32 STEAMakers”:

<center>

![Proyecto SM_wifi. Creación](../img/steamakers/actividades/SM_wifi.png)  
*Proyecto SM_wifi. Creación*

</center>

**3.** En la categoria de "Comunicaciones/WiFi/IoT" busca "Conectar a WiFi" y colocalo en "Inicializar".

<center>

![Proyecto SM_wifi. Iniciar WiFi](../img/steamakers/actividades/SM_wifi_ini.png)  
*Proyecto SM_wifi. Iniciar WiFi*

</center>

**4.** Escribe el SSID (Service Set Identifier) y la contraseña de la red WiFi.

<center>

![Proyecto SM_wifi. Iniciar WiFi](../img/steamakers/actividades/SM_wifi_ini1.png)  
*Proyecto SM_wifi. Iniciar WiFi*

</center>

**5.** Para comprobar que la placa se ha conectado correctamente a la red wifi se puede hacer desde la consola. Situa el bloque “Iniciar Baudios 115200" de la categoría “Comunicaciones / Puerto serie” en el bloque “Inicializar”. En el bloque “Bucle” pon un bloque condicional “Si…hacer” de la categoría “Lógica”. A continuación, de la categoría “Comunicaciones/WiFi/IoT” pon el bloque “¿Está conectado?” en la primera parte del condicional (si…) y en la segunda parte del condicional (hacer) pon el bloque “Enviar” que encontrarás en la categoría “Comunicaciones / Puerto serie”. En el espacio en blanco escribe “conectado”. Por último, coloca el bloque “Esperar para siempre (fin)” que encontrarás en la categoría “Tiempo”; con esto hará que el mensaje se muestre una sola vez en la consola.

<center>

![Proyecto SM_wifi. Programa](../img/steamakers/actividades/SM_wifiP1.png)  
*Proyecto SM_wifi. Programa*

</center>

**6.** Haz clic en “Subir”, asegurándote primero de que tienes el puerto correctamente seleccionado.

<center>

![Proyecto SM_wifi. Subir](../img/steamakers/actividades/SM_wifi_subir.png)  
*Proyecto SM_wifi. Subir*

</center>

**7.** Una vez le salga el mensaje que el programa se ha compilado correctamente, haz clic en “Consola” y después en “Conectar”. Ajusta la velocidad y si no se muestra el mensaje pulsa el botón de reset de la placa.

<center>

![Proyecto SM_wifi. Consola](../img/steamakers/actividades/SM_wifi_con.png)  
*Proyecto SM_wifi. Consola*

</center>

**8.** También se puede ver la IP de la conexión enviándola a la consola con el bloque “Dirección IP”, de la categoría “Comunicaciones/WiFi/IoT”

<center>

![Proyecto SM_wifi. Completo](../img/steamakers/actividades/SM_wifi_completo.png)  
*[Proyecto SM_wifi](../STEAMakers/programas/SM_wifi.abp)*

</center>

La consola se verá ahora de la siguiente forma:

<center>

![Proyecto SM_wifi. Consola](../img/steamakers/actividades/SM_wifi_completoCon.png)  
*Proyecto SM_wifi. Consola*

</center>
