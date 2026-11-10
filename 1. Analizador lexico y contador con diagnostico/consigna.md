## **Proyecto 1:** *uniwc* (Analizador lexico y contador con diagnostico)

K&R enseña a contar caracteres, lineas y palabras manejando estados (IN vs OUT). Este proyecto lleva esa idea al nivel de una herramienta de analisis de codigo o texto con metricas detalladas

- **Objetivo:** Procesar un flujo de entrada estandar (stdin) o archivos redirigidos caracter por caracter usando una pequeña maquina de estados sin cargar todo el archivo en memoria
- **Que debe calcular:**
    - Total de bytes/caracteres.
    - Total de lineas (detectando saltos \n)
    - Total de palabras (delimitadas por espacios, tabulaciones \t o saltos de linea)
    - Longitud de la linea mas larga encontrada (concepto directop del ejercicio de arreglos de caracteres de K&R)
    - Conteo discriminado de caracteres visibles vs espacios en blanco vs caracteres de control

- **Por que es valioso:** Te enseña a procesar flujos de datos potencialmente infinitos (gigabytes de logs) consumiendo una cantidad de memoria virtual constante (O(1)) mediante $getchar()$
- **Prueba de fuego en terminal:** Codigo: ./uniwc < /etc/passwd (LINUX) - Get-Content C:\Windows\System32\drivers\etc\hosts -Raw | .\uniwc.exe (Windows)
