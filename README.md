# cub3D

**cub3D** es un motor de renderizado en primera persona implementado en C, basado en la técnica de **raycasting**. Este proyecto fue desarrollado como parte de una formación intensiva en programación de bajo nivel y tiene como objetivo comprender e implementar los fundamentos de un motor gráfico 3D clásico, similar a los usados en juegos como *Wolfenstein 3D*, sin utilizar librerías externas de gráficos avanzados.

## 🧱 Objetivos del proyecto

- Implementar un sistema de renderizado en 3D utilizando raycasting.
- Procesar mapas desde archivos de configuración.
- Dibujar el entorno en una ventana mediante píxeles manipulados con **MiniLibX**.
- Gestionar la entrada del usuario para navegación y rotación del punto de vista.
- Control de colisiones y validación de mapas.

## 🛠️ Tecnologías utilizadas

- Lenguaje: **C**
- Librería gráfica: [**MiniLibX**](https://harm-smits.github.io/42docs/libs/minilibx)
- Sistema operativo: Linux / macOS
- Compilación: `Makefile`

## 📂 Estructura del proyecto

```
cub3D/
├── inc/ # Archivos de cabecera
├── src/ # Código fuente principal
├── maps/ # Archivos de mapa .cub
├── assets/ # Archivos de textura
├── Makefile
└── README.md
```

## 🚀 Cómo compilar y ejecutar

```bash
make           			 # Compila el proyecto
./cub3D maps/map.cub	 # Ejecuta cub3D
```

## 🔍 Funcionalidades implementadas

- Raycasting para muros (cálculo de intersecciones por columna).
- Renderizado de techo, suelo y texturas.
- Movimiento libre del jugador y rotación con teclas.
- Carga de archivos `.cub` con mapa, texturas y configuración.
- Validaciones: mapa cerrado, jugador único, extensiones correctas.
- Gestión de memoria y recursos.

## 🧠 Qué aprendí

Este proyecto me permitió profundizar en:

- Manipulación de memoria y estructuras de datos en C.
- Principios de motores gráficos simples.
- Lógica matemática aplicada a gráficos: vectores, distancias, ángulos.
- Parsing de archivos de configuración personalizados.
- Organización modular del código en proyectos medianos.

## 📸 Captura de pantalla

![cub3D Screenshot](https://github.com/Fefeco/cub3d/blob/main/cub3D.png)

## ℹ️ Notas

Este proyecto fue realizado como parte del programa de formación de [42](https://42.fr/), siguiendo sus restricciones.


