## LCD

1. Características: filas y columnas, iluminación, caracteres
1. Conectar LCD
1. Direcciones (I2C_scanner) TODO
1. Ejemplos:
  1. Hello LCD
  1. Contar/reloj TODO
  1. Estructurar la información en pantalla

![LCD](./images/2.ESP_LCD_bb.png)

TODO: cambiar los pines SCL = D1 SDA = D2

### Problemas con el LCD

* No se enciende la pantalla
  * Se ha caido el jumper de atrás
  * Están mal conectados los cables de Vcc y GND

* Se enciende la pantalla  pero no se ve nada: Se puede ajustar el contraste con el potenciómetro de atrás del LCD

* Sólo se ve una línea de cuadrados oscuros: cambiar la dirección de 0x27 a 0x30 o 0x3F

## Ejercicio

1. Scroll de texto


    for(int i = 0; i < 16 ; i += 1){
      lcd.clear(); // borramos la pantalla
      lcd.setCursor(i,0);
      lcd.print("Adios!!!");
      delay(500);
    }
