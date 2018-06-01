## Clientes y servidores

Usamos los kits de 2 en 2.
1. Uno lee los datos de un sensor DHT y los publica de forma sencilla mediante un servidor web. Le llamaremos **Publicador**
1. El otro lee la página publicada, extrayendo la información y volviendo a publicarla. Lo llamaremos **Recolector**
1. Cada uno tendrá un montaje y una programación diferentes

### Montaje

1. Configuraremos  ips fijas para simplificar las conexiones entre las dos placas

#### Publicador
1. Leeremos los datos de un sensor DHT22
1. Para facilitar la puesta a punto usaremos una pantalla LCD
1. Los datos leídos se enviarán al monitor serie
1. Usaremos el ejemplo LCD_DHT_webData

![](./imagen/LCD_DHT_bb.png)

#### Recolector

1. El servidor se conectará al recolector y re-publicará la información
1. Solo necesitamos un placa NodeMCU
1. Usaremos el ejemplo Server_recolector


### Mejoras

1. Reprocesar el código HTML
1. Leer y republicar los datos de varios publicadores

### Saber más

1. Protocolo MQTT: facilita la interconexión entre equipos [Tutorial MQTT]() ENLACE