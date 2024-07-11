# AyED-files

## fseek(art1,art2,art3)

```c/c++
int fseek(FILE *stream, long int desplazamiento, int origen);
```

La función *fseek* activa el indicador de posición de ficheros para el stream apuntado por **stream**. Para un stream binario, la nueva posición, medido en caracteres del principio del fichero, es obtenida mediante la suma de **desplazamiento** y la posición especificada por **origen**.

La posición especificada es el comienzo del fichero si **origen** es [SEEK_SET](https://conclase.net/c/librerias/stdio/SEEK_CUR), el valor actual del indicador de posición de fichero si es [SEEK_CUR](https://conclase.net/c/librerias/stdio/SEEK_CUR), o final de fichero si es [SEEK_END](https://conclase.net/c/librerias/stdio/SEEK_CUR).

```
fseek([nombre lógico del archivo], [cantidad de bytes a desplazarse], [ubicación desde donde comenzar a desplazarse])
```

Archivos binarios

```c
size_t fread(
   void *buffer,
   size_t size,
   size_t count,
   FILE *stream
);
```

***Los mismo para el fwrite***

```c
size_t fwrite(
   const void *buffer,
   size_t size,
   size_t count,
   FILE *stream
);
```

### Parametros

*`buffer`*  
Ubicación de almacenamiento de los datos.

*`size`*  
Tamaño del elemento en bytes.

*`count`*  
Número máximo de elementos que se va a leer.

*`stream`*  
Puntero a la estructura `FILE` .

### Valor devuelto

**`fread`** devuelve el número de elementos completos que lee la función, que puede ser menor que *`count`* si se produce un error o si encuentra el final del archivo antes de alcanzar *`count`*. Use la función **`feof`** o **`ferror`** para distinguir un error de lectura de una condición de final de archivo. Si *`size`* o *`count`* es 0, **`fread`** devuelve 0 y el contenido del búfer queda sin cambios. Si *`stream`* o *`buffer`* es un puntero nulo, **`fread`** invoca el controlador de parámetros no válidos, como se describe en [Validación](https://learn.microsoft.com/es-es/cpp/c-runtime-library/parameter-validation?view=msvc-170) de parámetros. Si la ejecución puede continuar, esta función establece `errno` en `EINVAL` y devuelve 0.