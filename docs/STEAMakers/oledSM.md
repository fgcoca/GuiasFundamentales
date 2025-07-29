Aquí encontrarás información e instrucciones para conectar y mostrar textos o imágenes en una pantalla de tipo OLED de 0.96" de 128x64 pixels.

Para saber mas sobre la OLED puedes consultar [Pantalla OLED](https://fgcoca.github.io/GuiasFundamentales/previos/#pantalla-oled).

!!! danger "Por seguridad"
	Es muy conveniente tener la placa desprovista de cualquier tipo de alimentación mientras realizamos el conexionado de elementos. En caso contrario se pueden producir despefectos irreversibles en cualquiera de los elementos.

## <FONT COLOR=#007575>**Material necesario**</font>

* Placa ESP32 STEAMakers
* Pantalla OLED 0.96"
* Cable I2C o 4 cables dupont hembra-hembra
* Ordenador. Antes de empezar a utilizar la placa ESP32 STEAMakers, es necesario comprobar que nuestro dispositivo esté listo para trabajar. Encontrarás toda la información en [Antes de](https://fgcoca.github.io/GuiasFundamentales/STEAMakers/contSM/).

## <FONT COLOR=#007575>**Procedimiento**</font>

**1.** Comenzamos conectando la pantalla OLED a la placa a través de los pines de comunicación I2C hembra dispuestos en el hub I2C que tiene la misma. Vemos la posición en la imagen siguiente:

<center>

![Conexionado](../img/steamakers/actividades/conex_oled.png)  
*Conexionado*

</center>

También puedes hacer las conexiones con un cable I2C o utilizando cuatro cables dupont hembra-hembra y situarlos en alguno de los pines macho del hub I2C.

!!! warning "CUIDADO"
    Si utilizas cables dupont, controla que cada cable conecte los terminales correspondientes de la placa y de la pantalla (GND con GND, VCC con VCC, SCL con SCL y SDA con SDA).

    Si utilizas un conector I2C ten cuidado de respetar el orden de los pines, es decir, que las conexiones son las mismas que con cables individuales.

**2.** Sigue con la programación con ArduinoBlocks: Ejecuta el programa AB-Connector. Recuerda que debe estar en ejecución todo el rato mientras trabajas con ArduinoBlocks.

**3.** Ve a ArduinoBlocks, inicia sesión y comienza un nuevo proyecto del tipo “ESP32 STEAMakers”:

<center>

![Proyecto SM_OLED. Creación](../img/steamakers/actividades/SM_OLED.png)  
*Proyecto SM_OLED. Creación*

</center>

**4.** Para utilizar la pantalla OLED, primero debes inicializarla. En el bloque “Inicializar”, sitúa un bloque “OLED Iniciar I2C”, que encontrarás en la categoría "Visualización/Pantalla OLED". Pon también el bloque “Limpiar” para asegurar que la pantalla no tenga nada escrito al inicio.

<center>

![Proyecto SM_OLED. Inicializar](../img/steamakers/actividades/SM_OLED_inicial.png)  
*Proyecto SM_OLED. Inicializar*

</center>

**5.** A continuación, en el bloque “Bucle”, sitúa alguno de los bloques de visualización de la pantalla OLED, en función de lo que desees mostrar. Comienza mostrando el texto “Hola”, con el bloque “OLED #1 Text…”:

<center>

![Proyecto SM_OLED. Explicación del bloque](../img/steamakers/actividades/SM_OLED_Bloque.png)  
![Proyecto SM_OLED. Hola](../img/steamakers/actividades/SM_OLED_Hola.png)  
*Proyecto SM_OLED. Hola*

</center>

Si quieres ver los datos que recoge algún sensor, también puede situar el bloque en el espacio destinado al texto (en la imagen se utiliza un bloque para ver los datos recogidos por un sensor que mide la intensidad lumínica):

<center>

![Ejemplo bloque "Text..."](../img/steamakers/actividades/ejemplo_text.png)  
*Ejemplo bloque "Text..."*

</center>

Haz clic en el botón “Subir” situado arriba a la derecha, verificando primero que el puerto seleccionado sea correcto:

<center>

![Proyecto SM_OLED. Subir](../img/steamakers/actividades/SM_OLED_Subir.png)  
*Proyecto SM_OLED. Subir*

</center>

**6.** Ahora, añade una espera de 2 segundos (2000 milisegundos), haz que se limpie la pantalla y que a continuación se muestre una imagen. Para añadir la espera de 2 segundos, ve a la categoría “Tiempo” y elige el bloque “Esperar 1000 milisegundos”. Cambia el valor a 2000. A continuación, de la categoría Visualización/Pantalla OLED, elige el bloque “OLED #1 Bitmap…” y cargalo con una imagen. Abre el editor Bitmap de la OLED:

<center>

![OLED - Bitmap Editor](../img/steamakers/actividades/OLED_Bitmap_Editor.png)  
*OLED - Bitmap Editor*

</center>

**7.** En OLED – Bitmap Editor tienes la pantalla OLED representada con todos sus píxeles. Puedes marcar directamente los píxeles que desees sobre el dibujo de la pantalla y estos serán los que se activarán en la pantalla OLED conectada a la placa.

<center>

![OLED - Bitmap Editor](../img/steamakers/actividades/OLED_Bitmap_Editor1.png)  
*OLED - Bitmap Editor*

</center>

O bien, puedes subir una imagen desde “Elegir archivos” (preferentemente con las dimensiones 128x64px, aunque cualquier imagen que subas se transformará a esta proporción):

<center>

![OLED - Bitmap Editor](../img/steamakers/actividades/OLED_Bitmap_Editor2.png)  
![OLED - Bitmap Editor](../img/steamakers/actividades/OLED_Bitmap_Editor3.png)  
*OLED - Bitmap Editor*

</center>

**8.** Poner otra espera de 2 segundos antes de reiniciar el bucle. El código completo de la programación debe quedar así:

<center>

![Proyecto SM_OLED](../img/steamakers/actividades/SM_OLED_completo.png)  
*[Proyecto SM_OLED](../STEAMakers/programas/SM_OLED.abp)*

</center>
