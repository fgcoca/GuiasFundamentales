(Fuente: Wikipedia)

En redes informáticas, el Protocolo de Datagramas de Usuario (UDP) es uno de los protocolos de comunicación centrales del conjunto de protocolos de Internet utilizado para enviar mensajes (transportados como datagramas en paquetes) a otros hosts en una red de Protocolo de Internet (IP). Dentro de una red IP, UDP no requiere comunicación previa para establecer canales de comunicación o rutas de datos.

UDP utiliza un modelo sencillo de comunicación sin conexión con un mínimo de mecanismos de protocolo. UDP proporciona números de puerto para direccionar diferentes funciones en el origen y el destino del datagrama. No tiene diálogos de toma de contacto y, por tanto, no hay garantía de entrega, orden o protección contra duplicados.

UDP es adecuado para fines en los que la comprobación y corrección de errores no son necesarias o se realizan en la aplicación. Las aplicaciones sensibles al tiempo suelen utilizar UDP porque es preferible soltar paquetes que esperar a que se retrasen debido a la retransmisión, que puede no ser una opción en un sistema en tiempo real.

Las características principales de este protocolo son:

1. Trabaja sin conexión, es decir, que no emplea ninguna sincronización entre el origen y el destino.
2. Trabaja con paquetes o datagramas enteros, no con bytes individuales como TCP. Una aplicación que emplea el protocolo UDP intercambia información en forma de bloques de bytes, de forma que por cada bloque de bytes enviado de la capa de aplicación a la capa de transporte, se envía un paquete UDP.
3. No es fiable. No emplea control del flujo ni ordena los paquetes.
4. Su gran ventaja es que provoca poca carga adicional en la red, ya que es sencillo y emplea cabeceras muy simples.

## <FONT COLOR=#007575>Los puertos UDP</font>
Las aplicaciones pueden utilizar sockets (conectores) de datagramas para establecer comunicaciones de host (equipo) a host (equipo). Una aplicación vincula un socket a su punto final de transmisión de datos, que es una combinación de una dirección IP y un puerto. De esta forma, UDP proporciona multiplexación de aplicaciones. Un puerto es una estructura de software que se identifica por el número de puerto, un valor entero de 16 bits, que permite números de puerto entre 0 y 65535.

* El puerto 0 está reservado, pero es un valor de puerto de origen admisible si el proceso de envío no espera mensajes como respuesta.
* Los puertos 1 a 1023 se llaman puertos "bien conocidos (well-known)" y en sistemas operativos tipo Unix enlazar con uno de estos puertos requiere acceso como superusuario.
* Los puertos 1024 a 49.151 son puertos registrados usados por [IANA-registered services](https://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.txt). IANA son las siglas de Internet Assigned Numbers Authority que es el Registro de nombres de servicio y números de puerto de protocolo de transporte.
* Los puertos 49.152 a 65.535 son puertos dinámicos y son utilizados como puertos temporales, sobre todo por los clientes al comunicarse con los servidores.

En [Anexo:Puertos de red](https://es.wikipedia.org/wiki/Anexo:Puertos_de_red) de Wikipedia hay un amplio listado de puertos y su descripción.

## <FONT COLOR=#007575>UDP en MicroBlocks</font>
La implementación de MicroBlocks del protocolo UDP se manifiesta en la libreria UDP. No hay ningún requisito especial antes de usar el protocolo, aparte de que los dispositivos implicados tienen que estar presentes en una red IP compartida, en nuestro caso nuestro WiFi local.

Veamos una descripción de los bloques que componen esta libreria:

* **inicia UDP en el puerto...**

<center>

![Bloque inicia UDP en el puerto...](../img/CoCube/B_ini_UDP.png)  

</center>

Este bloque configura el script para que **escuche los mensajes UDP en el puerto designado**. La dirección IP propia del dispositivo y el número de puerto especificado forman un socket e identifican de forma única el dispositivo y cualquier servicio de software que proporcione. Según lo anterior:

* si se envía un mensaje de difusión UDP dirigido al puerto 5000,
* o se envía un mensaje UDP dirigido a la IP del dispositivo y al puerto 5000...

nuestro script lo verá y lo recibirá.

* **envia paquete UDP...a la IP...y puerto...**

<center>

![Bloque envia paquete UDP...a la IP...y puerto...](../img/CoCube/B_envia_paq_UDP.png)  

</center>

Este bloque se utiliza para **enviar mensajes UDP a la dirección IP y puerto designados**. La **dirección IP 255.255.255.255** es una dirección de **difusión especial**, y se utilizará para acceder a todos los dispositivos IP en la subred local. Esto facilita el envío de mensajes sin molestarse con la dirección IP específica de cada dispositivo.

Ten en cuenta que **en MicroBlocks, los mensajes de difusión no son vistos por el dispositivo emisor**. Sin embargo, **en la MIT AI2 APP, las difusiones son vistas por el teléfono emisor**.

Los mensajes también pueden ser enviados utilizando la dirección IP específica y el número de puerto UDP del dispositivo de destino, incluso a la propia dirección IP.

!!! Abstract "Direcciones IPv4 reservadas para usos específicos"
    127.0.0.0 -> Dirección de loopback o bucle de retorno (la propia interfaz del host)

    224.0.0.0 -> IP multicast o entrega de datos simultanea a un grupo de nodos receptores.

    255.255.255.255 -> Difusión (broadcast); se envía a todas las interfaces en la red

* **recibe paquete UDP**

<center>

![Bloque recibe paquete UDP](../img/CoCube/B_recib_paq_UDP.png)  

</center>

**Siempre que se reciba un mensaje UDP, este bloque contendrá su contenido**. Comprobando si su longitud es mayor que cero, podemos consultar el resultado de las transacciones UDP.

Este bloque también proporciona una opción booleana de **datos binarios** que permite recibir cualquier tipo de dato.

Hay otros bloques en la biblioteca que no se utilizan en este proyecto aunque se explican por sí mismos.

* **detén UDP**. Detiene el procesado de UDP

<center>

![Bloque detén UDP](../img/CoCube/B_deten_UDP.png)  

</center>

* **dirección IP remota de UDP**. El mensaje UDP envía la dirección IP remota.

<center>

![Bloque dirección IP remota de UDP](../img/CoCube/B_dir_rem_UDP.png)  

</center>

* **puerto remoto de UDP**. El mensaje UDP envía el puerto remoto.

<center>

![Bloque puerto remoto de UDP](../img/CoCube/B_puerto_rem_UDP.png)  

</center>
