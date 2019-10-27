<h1 align="center">
    <img src="http://utnfrae6.galeon.com/utn.jpg">
    <br/>
    Repositorio de práctica de trabajos prácticos (ABM) de Programación/Laboratorio 1.
    <br/>
</h1>

> El repositorio consta de trabajos prácticos realizados con el lenguaje ANSI C.
# Titulo:
Parcial orquesta.
# Enunciado:
Un teatro necesita gestionar las orquestas que realizan conciertos en el lugar, para ello es necesario
desarrollar un software que contará con el siguiente menú:

```md
1) Agregar Orquesta: Se da de alta una orquesta con nombre, lugar y tipo. Se generará un ID único
para esta orquesta que se imprimirá por pantalla si el alta es correcta.
2) Eliminar Orquesta: Se imprime la lista de orquestas. Luego se pide que se ingrese un ID y la
misma se eliminará, junto con los músicos que la componen.
3) Imprimir Orquestas: Se imprime la lista de orquestas.
4) Agregar Músico: Se da de alta un músico con nombre, apellido, edad, ID de la orquesta en la que
tocará, e ID del instrumento que toca.
5) Modificar Músico: Se imprime la lista de músicos con ID, Nombre y Apellido. Luego se pide que
se ingrese un ID y se podrán modificar los campos edad o ID de orquesta donde toca.
6) Eliminar Músico: Se imprime la lista de músicos con ID, Nombre y Apellido. Luego se pide que se
ingrese un ID y el músico se eliminará.
7) Imprimir Músicos: Se imprime la lista de músicos con ID, Nombre y Apellido, nombre y tipo de
instrumento.
8) Agregar Instrumento: Se da de alta un instrumento con nombre y tipo. Se generará un ID único
para este instrumento que se imprimirá por pantalla si el alta es correcta.
9) Imprimir instrumentos: Se imprime la lista de instrumentos indicando ID, nombre y tipo (Indicar el
tipo con un texto, no con números)
```

# Datos:

* Los tipos de orquesta que existirán son:
    - Sinfónica
    - Filarmónica
    - Cámara
* Los tipos de instrumento que existirán son:
    - Cuerdas
    - Viento-madera
    - Viento-metal
    - Percusión
* Existirán 50 orquestas como máximo.
* Existirán 20 instrumentos como máximo.
* Existirán 1000 músicos como máximo.
* Un músico solo pertenece a una orquesta.

# Recomendaciones:
* Agregar al campo “isEmpty” a cada entidad.
* Generar un ID auto incrementable para cada entidad.
* Tratar a los “tipos” de orquesta e instrumento, como valores numéricos.
* Antes de comenzar, realizar un diagrama con las entidades, todos sus campos y cómo se
relacionan.
* Antes de comenzar, realizar las funciones para imprimir cada uno de los arrays con todos sus
campos (sin relacionarlos con los otros arrays) para poder probar los ABM.
* Para poder probar los informes, realizar funciones que carguen con datos falsos los arrays de
las entidades, y ejecutarlas al comenzar el programa.

# Notas:
* Se deberán desarrollar bibliotecas por cada entidad las cuales contendrán las funciones (Alta, Baja, Modificar, etc.).
Los informes deberán estar en una biblioteca aparte. 
* El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas de estilo
de la cátedra.

