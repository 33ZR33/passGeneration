 # Password Generator

 Este es un generador de contraseñas simple que puede generar contraseñas de cualquier longitud entre 5 y 25 caracteres. Las contraseñas se generan utilizando una combinación de letras mayúsculas y minúsculas, números y caracteres especiales.

 ## Como usar

 Para utilizar el generador de contraseñas, simplemente ejecute el archivo `passGenerator.c`. Se le pedirá que ingrese la longitud de la contraseña que desea generar. Una vez que ingrese la longitud, el programa generará una contraseña y la mostrará en la pantalla.

 ## Explicación

El código para el generador de contraseñas es relativamente simple. La función principal primero genera el generador de números aleatorios utilizando la hora actual. Esto asegura que las contraseñas se generen aleatoriamente.

Luego, la función solicita al usuario que ingrese la longitud de la contraseña que desea generar. Si el usuario ingresa una longitud menor que 5 o mayor que 25, el programa mostrará un mensaje de error y saldrá.

Si el usuario ingresa una longitud válida, el programa generará una contraseña usando la función `generate_password()`. Esta función toma la longitud de la contraseña como argumento y devuelve un puntero a una matriz de caracteres que contiene la contraseña.

La función `generate_password()` primero crea una matriz de todos los caracteres posibles que se pueden usar en la contraseña. Esta matriz incluye letras mayúsculas y minúsculas, números y caracteres especiales.

Luego, la función genera una contraseña aleatoria seleccionando caracteres de la matriz de caracteres posibles. Se garantiza que los primeros cuatro caracteres de la contraseña serán una letra mayúscula, una letra minúscula, un número y un carácter especial. Los caracteres restantes de la contraseña se seleccionan aleatoriamente de la variedad de caracteres posibles.

Una vez que se ha generado la contraseña, la función devuelve un puntero a la matriz de caracteres que contiene la contraseña.

La función principal luego imprime la contraseña generada en la pantalla.

## Seguridad

El generador de contraseñas utiliza una combinación de letras mayúsculas y minúsculas, números y caracteres especiales para generar contraseñas. Esto hace que las contraseñas sean más seguras que si solo se generaran con un tipo de carácter. Sin embargo, es importante tener en cuenta que ninguna contraseña es completamente segura. Siempre es posible que un hacker descifre una contraseña, incluso si es larga y compleja.

## Conclusion
Este es un generador de contraseñas simple pero efectivo. Puede utilizarse para generar contraseñas seguras que sean difíciles de adivinar.