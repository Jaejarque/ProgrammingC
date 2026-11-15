# **Proyecto 2:** *Normalizador de fuentes y expansor de tabulaciones*

Basado en uno de los problemas mas clasicos del capitulo 1. Es el principio fundamental de cualquier formateador de codigo o linter.

- **Objetivo:** Leer texto por *stdin* y normalizar su indentacion y longitud de linea antes de emitirlo por *stout*
- **Que debe resolver:**
  - 1. **Expansion inteligente de tabulaciones:** reemplaza cada *\t* por el numero exacto de espacios necesarios hasta la siguiente columna de tabulacion fija (por ejemplo, cada 4 u 8 columnas), no un numero fijo de espacios ciegos.
  - 2. **Eliminacion de _trailing spaces_:** Quitar espacios y tabulaciones sobrantes al final de cada linea antes del '\n'
  - 3. **Plegado de lineas largas (_line folding_):** Si una linea supera una longitud maxima prefijada con _#define MAX_COL 80_, el programa debe partirla en el ultimo espacio disponible antes de ese limite, simulando el comportamiento de un procesador de texto de terminal
- **Por que es valioso:** Exige manipular arreglos de caracteres locales, rastrear la posicion de columna actual y manejar buffers circulares o esatticos sin desbordar memoria.

Set-Content -Path input_test.txt -Value @(
    "`tint x;        ",
    "1`t2`t3`tfin   ",
    "`t`tfor (i = 0; i < 10; i++) {      ",
    "El compilador debe plegar esta linea exactamente antes del limite sin romper palabras.",
    "http://servidor-planta-la-rioja.local/api/v1/telemetria/maquinaria/registro_crudo_sin_espacios",
    "   Linea con muchos espacios iniciales y finales    ",
    ""
) -Encoding Ascii

Get-Content input_test.txt -Raw | .\detab_fmt.exe

detab_fmt.exe < input_test.txt

Get-Content input_test.txt -Raw | .\detab_fmt.exe | ForEach-Object { ($_ -replace "`t", '<TAB>' -replace ' ', '.') + '|' }
