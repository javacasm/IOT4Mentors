## Wifi

### Conceptos Wifi
  1. Tipos
    * Station
    * AP (Access Point)
  2. Seguridad. Importancia
    * Open
    * Wep
    * WPA
  3. Configuración
    * Seguridad
    * IPs
    * Puerto
    



## Cuidado con las mayúsculas/minúsculas de los SSID y las contraseñas

## Ejemplos

### Servidor Web básico (Base_webserver)

1. Cambiamos las credenciales de la wifi en la línea
   
   
         Wifi.begin("SSID","password")
   
1. Probamos el acceso desde el navegador 
2. Veremos la ip con el Monitor Serie
3. Entramos a la web con http://IP (El ordenador debe de estar conectados a la misma red wifi)
4. Revisamos el código
5. Modificamos el HTML ([Tutoriales HTML](https://www.w3schools.com/)) 
    * Formato
    * Refresh

### Mostrando datos de sensores (LCD_DHT_web)

1. Cambiamos las credenciales de la wifi en la línea

      Wifi.begin("SSID","password")

2. Conectamos el LCD y el DHT como en el ejemplo LCD_DHT
3. Veremos la ip con el Monitor Serie
4. Entramos a la web con http://IP

### Prácticas más avanzadas

[Ejemplo Cliente/Servidor](./ClienteServidor.md)
[Control de relés](./codigo/ControlRelesWeb.tar.gz)

#### Para saber más ...
    * Configuración de routers
    * Redireccionamiento de Puertos (Acceso remoto)
    * Acceso desde el móvil
    * Configuración de seguridad de acceso
    * [Plataformas de datos](./Plataformas.md)
    * Dispositivos comerciales
