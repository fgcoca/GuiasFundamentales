## <FONT COLOR=#007575>**Objetivo**</font>
Utilizar la función de reconocimiento de bloques de color del sensor de visión artificial Sentry2 y posteriormente utilizar el CoCube para seguir el movimiento de un cilindro.

El video siguiente muestra la idea que se pretende programar.

<center>

<iframe width="560" height="315" src="https://www.youtube.com/embed/bXq0cMlPjwQ?si=4CgMK46Iow98Y7U5" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

</center>

## <FONT COLOR=#007575>**Materiales**</font>
Robot CoCube, conector soporte para Sentry2 y ordenador ejecutando el IDE de MicroBlocks en cualquiera de sus versiones, estable instalada localmente o versiones online tanto estable como pilot. En cualquier caso tenemos que añadir las bibliotecas **CoCube**, **CoCube module** y **Sentry2 AI camera**.

<center>

![Materiales](../img/CoCube/mat08.png)

</center>

Hay que realizar la conexión de de dispostivos colocando el soporte para la Sentry2, con la cámara colocada, en el conector de expansión del CoCube. El conector con 4 cables hay que colocarlo en el conector I2C de la cámara.

## <FONT COLOR=#007575>**Información de algoritmos de Sentry2**</font>
### <FONT COLOR=#AA0000>Introducción</font>

<center>

![Color](../img/sentry2/color.png)  

</center>

El usuario especifica uno o más colores para detectar si hay manchas de ese color en la imagen, devolviendo sus coordenadas y tamaño. Admite la detección multicolor y multibloque, y las etiquetas de clasificación de colores son las mismas que las del reconocimiento de colores.

### <FONT COLOR=#AA0000>Configurar parámetros</font>
Los usuarios deben especificar las etiquetas de color que se van a detectar, pudiendo detectarse hasta seis colores simultáneamente, aunque la velocidad disminuirá. Los usuarios también pueden filtrar las manchas más pequeñas que el ancho mínimo w y la altura mínima h especificados para reducir los falsos positivos.

Al configurar los registros a través del controlador principal, es necesario establecer los siguientes parámetros:

|==**Parámetro**==|==**Significado**==|
|:-:|---|
|1|Ninguno|
|2|Ninguno|
|3|Ancho mínimo 'w' de los puntos válidos|
|4|Alto mínimo 'h' de los puntos válidos|
|5|Etiquetas de clasificación de colores 1~6. Uso especial: al escribir un valor de color RGB565 superior a 6 en el parámetro 5, se pueden identificar colores específicos, por ejemplo, escribiendo 0xFB00 para el color naranja y 0xA11E para el color morado|

!!! Note "NOTA:"
    El RGB565 es un RGB de 16 bits que utiliza una paleta de colores de 32×64×32 = 65.536 colores en lugar de los 256x256x256 del RGB. Normalmente, se asignan 5 bits para los componentes rojo y azul (32 niveles cada uno) y 6 bits para el componente verde (64 niveles), debido a la mayor sensibilidad del ojo humano a este color.

En la interfaz de usuario, hay varios parámetros preestablecidos que se pueden usar:

* **Rendimiento del algoritmo.** De acuerdo con los diferentes requisitos de la aplicación, hay 3 opciones para elegir el rendimiento adecuado del algoritmo, que son "Sensible (Sensitive)", "Equilibrado (Balanced)" y "Preciso (Accurate)".

En el modo sensible, la velocidad de reconocimiento es rápida y la frecuencia de fotogramas es alta. En el modo preciso, se pueden detectar manchas distantes, pero la velocidad disminuirá. El valor predeterminado es un rendimiento equilibrado.

Especial: En el modo preciso, se obtiene un buen reconocimiento y seguimiento de las manchas, pero solo se puede reconocer una mancha.

* **Número máximo de pruebas simultáneas.** El número máximo de detecciones para un solo color admite 1 ~ 5 salidas.

Cuando se establece en 1, solo se devuelve el mejor resultado. Si hay varias manchas en la imagen, se devuelve la más grande. Si los tamaños son similares, se da prioridad a la que se encuentra en la esquina superior izquierda.

Cuando se establece en un valor superior a 1, el número de manchas devueltas no superará este valor.

* **Tamaño del bloque de color mínimo.** Si hay pequeños parches del mismo color en el fondo, puedes filtrarlos estableciendo un valor mínimo razonable.

Los valores predeterminados en el sistema de coordenadas absolutas son: 2x2, 4x4, 8x8, 16x16, 32x32, 64x64, 128x128 píxeles.

Los valores predeterminados en el sistema de coordenadas porcentuales son: 1x1, 2x3, 3x4, 6x8, 9x12, 21x28, 42x56 %.

* **Colores a inspeccionar.** Se proporciona en forma de botón para que el usuario lo seleccione. Cuando se habilita un color, se muestra un pequeño icono con forma de ojo; si no está habilitado, se muestra un icono con forma de ojo tachado. Se pueden habilitar uno o más colores simultáneamente.

<center>

![Colores a inspeccionar](../img/sentry2/id2_result.png)  

</center>

Una vez que se reconoce el bloque de color especificado, se marcará en la interfaz de usuario y mostrará su ubicación, tamaño, etiqueta de clasificación, nombre y otra información.

Cuando se leen los registros a través del maestro, se devuelven los siguientes datos:

|==**Parámetro**==|==**Significado**==|
|:-:|---|
|1|Coordenada X del centro del bloque de color|
|2|Coordenada Y del centro del bloque de color|
|3|Ancho del bloque 'w'|
|4|Alto del bloque 'h'|
|5|Etiquetas de clasificación de colores|

Nos aseguramos de tener blob configurado como en la imagen siguiente:

<center>

![Colores a inspeccionar](../img/sentry2/conf_blob_color.png)  

</center>

### <FONT COLOR=#AA0000>Consejos de uso</font>
1. Cuando se determina que es necesario rastrear un único objeto, como detectar una carretera blanca o seguir una pelota, se puede establecer el número de bloques de color en 1 para mejorar la velocidad y reducir los falsos positivos.
2. El uso de un área de reconocimiento más pequeña y un modo de rendimiento preciso permite ver objetos más lejanos.
3. Al reconocer grandes áreas de manchas de color, la velocidad de fotogramas disminuirá significativamente. En este caso, se debe utilizar el modo sensible.
4. Cuando hay una mancha de color en la imagen, es necesario bloquear la función de balance de blancos.

### <FONT COLOR=#AA0000>Explicación de los bloques necesarios</font>
- **Inicialización de Sentry2**
Es un parámetro opcional que determina la dirección I2C del dispositivo. El valor por defecto es 96 (0x60) de entre el rango válido que va desde 96 (0x60) hasta 99 (0x63).

Antes de poder usar Sentry2, debes inicializarla mediante el bloque de la imagen, que por lo general, se coloca debajo de un bloque tipo sombrero "al empezar".

<center>

![Bloque para inicializar Sentry2](../img/CoCube/B_inic_sentry2.png)  

</center>

- **Modo configuración de Sentry2**

<center>

![Bloque modo configuración de Sentry2](../img/CoCube/B_mod_config_sentry2.png)  

</center>

Para este caso hay que establecer el modo en 'blob', es decir, el modo de detección de bloques de color.

- **Resultados de las pruebas de Sentry2**

<center>

![Bloque resultados de las pruebas de Sentry2](../img/CoCube/B_res_pruebas_sentry2.png)  

</center>

Este bloque debe utilizarse para activar la detección antes de obtener resultados.

El resultado devuelto es el número de resultados identificados por el algoritmo 'blob' actual.

El número de resultados se verá afectado por la configuración de parámetros del algoritmo correspondiente.

- **Sentry2 detección de los atributos del objeto**

<center>

![Bloque detección de los atributos del objeto](../img/CoCube/B_detec_atrib_sentry2.png)  

</center>

Devuelve las propiedades del identificador del objeto detectado, incluida la coordenada x central del bloque de color, la coordenada y del centro del bloque de color, el ancho del bloque de color w, la altura del bloque de color h y la etiqueta de clasificación de color.

Las etiquetas de clasificación por colores van del 1 al 6, y representan el negro (1), el blanco (2), el rojo (3), el verde (4), el azul (5) y el amarillo (6), respectivamente.

- **set blob check color red ... green ... blue ...** (**establecer color de detección de bloque**)

<center>

![Bloque set blob check color red ... green ... blue ...](../img/CoCube/B_set_blob_check_color.png)  

</center>

El bloque permite ajustar el color de detección del bloque (blob) de entre los posibles que son: **negro, blanco, rojo, verde, azul y amarillo**.

Tiene el mismo efecto que si lo hacemos desde la configuración de blob con el joystick:

<center>

![Configuración color detección blob en Sentry2](../img/CoCube/conf_blob_color.png)  

</center>

## <FONT COLOR=#007575>**Programación de ejemplo base**</font>

<font color=#FF0000>**&#x2460**</font> Conecta el IDE de MicroBlocks al robot CoCube a través de cable USB o por medios inalámbricos.

<font color=#FF0000>**&#x2461**</font> Debes agregar las bibliotecas **Sentry2 AI camera**, **CoCube** y **CoCube module**.

<font color=#FF0000>**&#x2462**</font> Debajo de un bloque sombrero "al empezar" coloca el bloque "activa la alimentación del módulo" para que la Sentry2 se alimente a través del conector I2C. A continuación inicializa la interfaz I2C y coloca una espera de 4 segundos para dar tiempo a que el módulo de la cámara se inicie correctamente y, a continuación, establece el modo de algoritmo de la cámara en modo blob para el reconocimiento de bloques de color. Finalmente establece como color de detección por ejemplo rojo.

<center>

![Programa "al comenzar"](../img/CoCube/P_detec_color_ini.png)  

</center>

<font color=#FF0000>**&#x2463**</font> Bajo un bloque sombrero "cuando" se comprueba continuamente si se detectan manchas de color Blob de color rojo. Cuando el número de objetos detectados sea 1, se muestran los cinco atributos de esa mancha u objeto. Puedes observar la posición, el tamaño y la etiqueta de color de la mancha en tiempo real.

<center>

![Programa detectar bloque de color](../img/CoCube/P_detec_color.png)  
**[Descargar el programa](../program/cocube/Reconocimiento_color_Sentry2.ubp)**

</center>

## <FONT COLOR=#007575>**Programación seguir objeto de color azul**</font>
Ten en cuenta que debes configurar los parámetros de reconocimiento de bloques de color de la cámara Sentry2 para cambiar el color rojo por defecto que trae de fábrica al color azul.

<font color=#FF0000>**&#x2460**</font> Conecta el IDE de MicroBlocks al robot CoCube a través de cable USB o por medios inalámbricos.

<font color=#FF0000>**&#x2461**</font> Debes agregar las bibliotecas **Sentry2 AI camera**, **CoCube** y **CoCube module**.

<font color=#FF0000>**&#x2462**</font> Debajo de un bloque sombrero "al empezar" coloca el bloque "activa la alimentación del módulo" para que la Sentry2 se alimente a través del conector I2C. A continuación inicializa la interfaz I2C y coloca una espera de 4 segundos para dar tiempo a que el módulo de la cámara se inicie correctamente y, a continuación, establece el modo de algoritmo de la cámara en modo blob para el reconocimiento de bloques de color. Finalmente establece como color de detección el azul.

<font color=#FF0000>**&#x2463**</font> Bajo un bloque sombrero "cuando" se comprueba continuamente si se detectan manchas de color Blob azules. Si es cierto el robot avanza y si el color desaparece el robot se detiene.

<center>

![Programa seguir color azul](../img/CoCube/P_seguir_azul.png)  
**[Descargar el programa](../program/cocube/CoCube_sigue_azul.ubp)**

</center>
