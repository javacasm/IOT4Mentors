## Uso IDE de Arduino

Usaremos el paquete instalado para Guadalinfo "Arduino IDE 1.8"

En [este enlace](./ConfiguracionIDE.md) podemos ver cómo se instalaría desde cero a partir del IDE de Arduino

## Diferencias con Arduino

1. Diferente capacidad
![](https://camo.githubusercontent.com/d33147f160317884c4376fafb64a39bedf37164e/68747470733a2f2f322e62702e626c6f6773706f742e636f6d2f2d4a733552315644336c39342f57515452735f5242456a492f41414141414141414242632f4e4641755043697643473062624d57386671486c343567365f3330637431365767434c63422f73313630302f436f6d70617261746976612532424553503332253242767325324241726475696e6f2e4a5047)
1. Programa más pequeño (diferencia microcontrolador/SOC: Sistem On Chip)

## Funcionamiento
1. Proceso de compilación
1. Las placas tienen un único programa

##  Uso del IDE

1. Cargamos un ejemplo Archivo -> Ejemplos
1. Seleccionamos (o comprobamos) que está seleccionada la placa NodeMCU 1.0 Herramientas -> Placa -> NodeMCU 1.0
![NodeMCU](./images/Placa-NodeMCU1.0.png)
1. Pulsamos Validar/Compilar
1. Si se produce un error  revisamos según el esquema…
![Error compilacion](./images/ErrorCodigo.png)
1. Seleccionamos el puerto al que está conectado Herramientas -> Puerto -> ttyUSB

  ![Puerto USB](./images/PuertoUSB.png)

1. Seleccionamos Herramientas -> Velocidad de transmisión -> 921600

    ![Velocidad Puerto](./images/UploadSpeed.png)

1. Subimos el programa a la placa   El led ázul de la placa parpadeará

Se puede producir un error si no hemos seleccionado bien el puerto USB en el paso anterior
    ![Error USB](./images/ErrorUSB.png)
