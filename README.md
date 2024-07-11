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
