## Control de relés via Web

Vamos a usar un formulario web para controlar remotamente un arduino


        <HTML>
        <head></head>
        <body>
        <center><form action='/'>
        <button name='dir' type='submit' value='1'>ON Rele 1</button>
        <button name='dir' type='submit' value='4'>ON Indicador 2</button><br>
        <button name='dir' type='submit' value='2'>OFF Rele 1</button>
        <button name='dir' type='submit' value='3'>OFF Indicador 2</button>
        </form></center>
        </body>
        </HTML>
        
        
Procesaremos la respuesta buscando el valor que se le ha asignado a la variable "dir" y en función de ese valor encenderemos o apagaremos los relés.


         int direction = server.arg("dir").toInt();
                // chose direction
                switch (direction)
                {
                    case 1:
                        enciendeRele(RELE_1);
                        break;
                    case 2:
                        apagaRele(RELE_1);
                        break;
                    case 3:
                        enciendeRele(RELE_2);
                        break;
                    case 4:
                        apagaRele(RELE_2);
                        break;
                }
                
                
[Codigo](./codigo/ControlRelesWeb.zip)                
