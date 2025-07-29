## <FONT COLOR=#007575>**Objetivo**</font>
Programe el robot CoCube para que ejecute los movimientos básicos.

## <FONT COLOR=#007575>**Materiales**</font>
Robot CoCube y ordenador ejecutando el IDE de MicroBlocks.

<center>

![Materiales](../img/CoCube/mat01.png)

</center>

## <FONT COLOR=#007575>**Programación**</font>
Para encender y conectar CoCube, sigue estos pasos:

1. **Conectar dispositivos:** conecta el IDE de MicroBlocks al robot CoCube a través de Bluetooth.
2. **Movimientos básicos:** se trata de controlar el robot para que se mueva hacia adelante, hacia la izquierda, hacia la derecha y hacia atrás. En la biblioteca de bloques "CoCube", arrastra los dos primeros bloques relacionados con el control del motor. Estos bloques controlan la dirección, la velocidad y la duración del movimiento del robot CoCube.

<center>

![Movimientos básicos](../img/CoCube/mov_base.gif)  
*[Descargar programa](../program/cocube/mov_base.ubp)*

</center>

**3. Frenar y detener:** ¡Escribe el siguiente código para comprobar la diferencia entre "freno de motor" y "parada de motor"! El "freno de motor" detendrá el robot un tiempo, mientras que la "parada del motor" simplemente elimina la alimentación del motor, por lo que el robot CoCube continuará deslizándose hacia adelante durante una corta distancia debido a la inercia. Puede haber ciertas tareas en las que necesite utilizar uno u otro de estos bloques de parada.

<center>

![Frenar y detener](../img/CoCube/freno_paro.gif)  
*[Descargar programa](../program/cocube/freno_paro.ubp)*

</center>

Observamos perfectamente como el robot se desvia un poco y los dos diferentes puntos de detención del mismo según se de una orden u otra.

## <FONT COLOR=#007575>**Movimiento circular**</font>
El chasis del robot CoCube tiene forma cúbica pensada para moverse en tableros tipo pista. Al controlar de manera diferente la velocidad de las ruedas izquierda y derecha, se pueden simularse una mayor variedad de trayectorias de movimiento, como hacer que el robot CoCube gire en círculos.

<center>

![Movimiento circular](../img/CoCube/Movimiento_circular.gif)  
*[Descargar programa](../program/cocube/Movimiento_circular.ubp)*

</center>

## <FONT COLOR=#007575>**Reto: Trayectoria cuadrada**</font>
Utiliza los bloques de control del motor para controlar el CoCube y completar una trayectoria cuadrada. Puedes medir el tiempo que tarda en girar el robot hacia la izquierda a una velocidad de 30 un ángulo determinado y girar 90 grados con mayor precisión.

<center>

![Trayectoria cuadrada](../img/CoCube/Trayectoria_cuadrada.gif)  
*[Descargar programa](../program/cocube/Trayectoria_cuadrada.ubp)*

</center>

Si dejas que el robot ejecute el programa durante un tiempo y eres observador, seguramente verás que el error acumulado por el CoCube girando a la izquierda aumenta, y que la trayectoria del cuadrado se distorsionará gradualmente. ¿Cómo podemos conseguir movimientos más precisos? La respuesta a la pregunta la veremos posteriormente utilizando una alfombrilla de posicionamiento.