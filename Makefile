
all: manual

MANUAL="Talleres Tecnologia IOT.pdf"


manual:
	pandoc --latex-engine=xelatex   \
					-V papersize:a4paper    \
					--template=./LaTeX_ES.latex    \
					-o  $(MANUAL)   \
					Cabecera.md     \
					Introduccion.md \
					IOT.md \
					NodeMCU.md \
					ConfiguracionIDE.md \
					ProgramacionNodeMCU.md \
					Leds.md \
					Librerias.md \
					LCD.md \
					Reles.md \
					Sensores_atmosfericos.md \
					Reloj_RTC.md \
					Wifi.md \
					Plataformas.md \
					Proyectos.md \
					Apendices.md \
					Electronica.md \
					ProgramacionBloques.md \
					scratch.md \
					appInventor.md \
					kit.md \
					Componentes.md \
					Componentes/NodeMCU_componente.md \
					Componentes/DHT22.md \
					Componentes/BME280.md \
					Componentes/LDR.md \
					Componentes/Sensor_Humedad_Suelo.md \
					Componentes/Sensor_lluvia.md \
					Componentes/Sensores_Gases.md \
					Componentes/SensorPresencia.md \
					Componentes/Servo.md \
					Componentes/Rele.md \
					Componentes/LCD.md \
					Componentes/Protoboard.md \
					Componentes/MotorShield.md \
					Componentes/RTC_DS3231.md \
					KitRecomendables.md \
					Simuladores.md \
					Recursos.md


clean:
	rm $(MANUAL)

push:
	git commit -m "update manual" $(MANUAL);
	git push;
