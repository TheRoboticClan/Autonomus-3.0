Control software
====

We use arduino IDE to program our robot. The autonomuscar file contains the code used.

Definición de pines y variables:
Definir TRIG como pin A1
Definir ECHO como pin A0
Definir wheels_Ctrl como pin 12
Definir wheels_PWM como pin 3
Definir steer_Ctrl como pin 13
Definir steer_PWM como pin 11
Definir velocidad como 100
Función verificar_distancia():
Escribir LOW en el pin TRIG
Esperar 2 microsegundos
Escribir HIGH en el pin TRIG
Esperar 10 microsegundos
Escribir LOW en el pin TRIG
Medir duración del pulso HIGH en el pin ECHO
Dividir duración por 58.00 para obtener la distancia en cm
Esperar 10 milisegundos
Retornar la distancia
Función setup():
Iniciar comunicación serial a 9600 baudios
Configurar TRIG como salida
Configurar ECHO como entrada
Configurar wheels_Ctrl como salida
Configurar wheels_PWM como salida
Configurar steer_Ctrl como salida
Configurar steer_PWM como salida
Función loop():
Escribir HIGH en steer_Ctrl
Escribir valor PWM 255 en steer_PWM
Función avanzar():
Escribir HIGH en wheels_Ctrl
Escribir valor PWM 100 en wheels_PWM
Escribir HIGH en steer_Ctrl
Escribir valor PWM (velocidad) en steer_PWM
Función retroceder():
Escribir LOW en wheels_Ctrl
Escribir valor PWM (velocidad) en wheels_PWM
Escribir HIGH en steer_Ctrl
Escribir valor PWM 255 en steer_Ctrl
Función girar_derecha():
Escribir LOW en wheels_Ctrl
Escribir valor PWM 75 en wheels_PWM
Escribir HIGH en steer_Ctrl
Escribir valor PWM 255 en steer_PWM
Función girar_izquierda():
Escribir HIGH en wheels_Ctrl
Escribir valor PWM (velocidad) en wheels_PWM
Escribir LOW en steer_Ctrl
Escribir valor PWM 255 en steer_PWM
Función detenerse():
Escribir LOW en wheels_Ctrl
Escribir valor PWM 0 en wheels_PWM
Escribir LOW en steer_Ctrl
Escribir valor PWM 0 en steer_PWM
Esperar indefinidamente
